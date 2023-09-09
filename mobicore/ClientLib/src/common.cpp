/*
 * Copyright (c) 2013-2017 TRUSTONIC LIMITED
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the TRUSTONIC LIMITED nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <mutex>
#include <vector>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

#include "dynamic_log.h"
#include "driver.h"
#include "common.h"

#ifdef LOG_FPRINTF
// Set default log destination (needs to be somewhere)
FILE* mc_log_file_ = stdout;
#endif

using namespace trustonic;

struct Common::Impl {
    Driver driver;
    IClient* client = &driver;
    std::mutex init_mutex;
    int init_count = 0;
    pid_t init_pid = 0;
    OpenMode open_mode = OpenMode::AUTO;

    // Must be called under init_mutex
    bool openNeeded() {
        // Re-open on fork
        if ((init_pid == getpid()) && (init_count != 0)) {
            return false;
        }
        init_count = 0;
        init_pid = getpid();
        return true;
    }
};

Common::Common(): pimpl_(new Impl) {
}

// Destructor needs the size of Impl
Common::~Common() {}

// Proprietary
void Common::TEEC_TT_RegisterPlatformContext(
    void*                   /*globalContext*/,
    void*                   /*localContext*/) {
}

TEEC_Result Common::TEEC_TT_TestEntry(
    void*                   buff,
    size_t                  len,
    uint32_t*               tag) {
    return pimpl_->client->TEEC_TT_TestEntry(buff, len, tag);
}

// Global Platform
TEEC_Result Common::TEEC_InitializeContext(
    const char*             name,
    TEEC_Context*           context) {
    std::lock_guard<std::mutex> lock(pimpl_->init_mutex);
    TEEC_Result teec_result = TEEC_SUCCESS;
    if (pimpl_->openNeeded()) {
        switch (pimpl_->open_mode) {
            case OpenMode::AUTO:
            case OpenMode::DRIVER:
                teec_result = pimpl_->driver.TEEC_InitializeContext(name, context);
                if (teec_result == TEEC_SUCCESS) {
                    pimpl_->client = &pimpl_->driver;
                    LOG_I("Kinibi access granted by the driver");
                }
                break;
            default:
                teec_result = TEEC_ERROR_ACCESS_DENIED;
        }
    }

    if (teec_result == TEEC_SUCCESS) {
        pimpl_->init_count++;
    } else {
        LOG_E("Cannot access Kinibi");
    }
    return teec_result;
}

void Common::TEEC_FinalizeContext(
    TEEC_Context*           context) {
    std::lock_guard<std::mutex> lock(pimpl_->init_mutex);
    if (pimpl_->init_count == 0) {
        LOG_E("instance counter cannot go negative");
        return;
    }
    if (--pimpl_->init_count == 0) {
        pimpl_->client->TEEC_FinalizeContext(context);
    }
}

TEEC_Result Common::TEEC_RegisterSharedMemory(
    TEEC_Context*           context,
    TEEC_SharedMemory*      sharedMem,
    int                     /*proxyClientFd*/) {
    return pimpl_->client->TEEC_RegisterSharedMemory(context, sharedMem);
}

void Common::TEEC_ReleaseSharedMemory(
    TEEC_SharedMemory*      sharedMem) {
    pimpl_->client->TEEC_ReleaseSharedMemory(sharedMem);
}

void Common::prepareOperation(
    TEEC_Operation*         operation) {
    pimpl_->client->prepareOperation(operation);
}

TEEC_Result Common::TEEC_OpenSession(
    TEEC_Context*           context,
    TEEC_Session*           session,
    const TEEC_UUID*        destination,
    uint32_t                connectionMethod,
    const void*             connectionData,
    TEEC_Operation*         operation,
    uint32_t*               returnOrigin,
    int                     /*proxyClientFd*/) {
    return pimpl_->client->TEEC_OpenSession(context, session, destination,
                                            connectionMethod, connectionData,
                                            operation, returnOrigin);
}

void Common::TEEC_CloseSession(
    TEEC_Session*           session) {
    pimpl_->client->TEEC_CloseSession(session);
}

TEEC_Result Common::TEEC_InvokeCommand(
    TEEC_Session*           session,
    uint32_t                commandID,
    TEEC_Operation*         operation,
    uint32_t*               returnOrigin,
    int                     /*proxyClientFd*/) {
    return pimpl_->client->TEEC_InvokeCommand(session, commandID, operation,
            returnOrigin);
}

void Common::TEEC_RequestCancellation(
    TEEC_Operation*         operation) {
    pimpl_->client->TEEC_RequestCancellation(operation);
}

// MobiCore
mcResult_t Common::mcOpenDevice(
    uint32_t                deviceId) {
    std::lock_guard<std::mutex> lock(pimpl_->init_mutex);
    mcResult_t mc_result = MC_DRV_OK;
    if (pimpl_->openNeeded()) {
        switch (pimpl_->open_mode) {
            case OpenMode::AUTO:
            case OpenMode::DRIVER:
                mc_result = pimpl_->driver.mcOpenDevice(deviceId);
                if (mc_result == MC_DRV_OK) {
                    pimpl_->client = &pimpl_->driver;
                    LOG_I("Kinibi access granted by the driver");
                }
                break;
            default:
                mc_result = MC_DRV_ERR_INVALID_OPERATION;
        }
    }

    if (mc_result == MC_DRV_OK) {
        pimpl_->init_count++;
    }
    return mc_result;
}

mcResult_t Common::mcCloseDevice(
    uint32_t                deviceId) {
    std::lock_guard<std::mutex> lock(pimpl_->init_mutex);
    if (pimpl_->init_count == 0) {
        LOG_E("instance counter cannot go negative");
        return MC_DRV_ERR_DAEMON_DEVICE_NOT_OPEN;
    }
    mcResult_t mc_result = MC_DRV_OK;
    if (pimpl_->init_count == 1) {
        mc_result = pimpl_->client->mcCloseDevice(deviceId);
        if (mc_result == MC_DRV_OK) {
            pimpl_->init_count--;
        }
    }
    return mc_result;
}

mcResult_t Common::mcOpenSession(
    mcSessionHandle_t*      session,
    const mcUuid_t*         uuid,
    uint8_t*                tci,
    uint32_t                tciLen,
    int                     /*proxyClientFd*/) {
    return pimpl_->client->mcOpenSession(session, uuid, tci, tciLen);
}

mcResult_t Common::mcOpenTrustlet(
    mcSessionHandle_t*      session,
    mcSpid_t                spid,
    uint8_t*                trustedapp,
    uint32_t                tLen,
    uint8_t*                tci,
    uint32_t                tciLen,
    int                     /*proxyClientFd*/) {
    return pimpl_->client->mcOpenTrustlet(session, spid, trustedapp, tLen, tci,
                                          tciLen);
}

mcResult_t Common::mcCloseSession(
    mcSessionHandle_t*      session) {
    return pimpl_->client->mcCloseSession(session);
}

mcResult_t Common::mcNotify(
    mcSessionHandle_t*      session) {
    return pimpl_->client->mcNotify(session);
}

mcResult_t Common::mcWaitNotification(
    mcSessionHandle_t*      session,
    int32_t                 timeout) {
    return pimpl_->client->mcWaitNotification(session, timeout);
}

mcResult_t Common::mcMallocWsm(
    uint32_t                deviceId,
    uint32_t                len,
    uint8_t**               wsm) {
    return pimpl_->client->mcMallocWsm(deviceId, len, wsm);
}

mcResult_t Common::mcFreeWsm(
    uint32_t                deviceId,
    uint8_t*                wsm,
    uint32_t                len) {
    return pimpl_->client->mcFreeWsm(deviceId, wsm, len);
}

mcResult_t Common::mcMap(
    mcSessionHandle_t*      session,
    void*                   buf,
    uint32_t                len,
    mcBulkMap_t*            mapInfo,
    int                     /*proxyClientFd*/) {
    return pimpl_->client->mcMap(session, buf, len, mapInfo);
}

mcResult_t Common::mcUnmap(
    mcSessionHandle_t*      session,
    void*                   buf,
    mcBulkMap_t*            mapInfo) {
    return pimpl_->client->mcUnmap(session, buf, mapInfo);
}

mcResult_t Common::mcGetSessionErrorCode(
    mcSessionHandle_t*      session,
    int32_t*                lastErr) {
    return pimpl_->client->mcGetSessionErrorCode(session, lastErr);
}

mcResult_t Common::mcGetMobiCoreVersion(
    uint32_t                deviceId,
    mcVersionInfo_t*        versionInfo) {
    return pimpl_->client->mcGetMobiCoreVersion(deviceId, versionInfo);
}

void Common::setOpenMode(OpenMode open_mode) {
    pimpl_->open_mode = open_mode;
    LOG_I("open mode set to: %x", static_cast<int>(pimpl_->open_mode));
}
