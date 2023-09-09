//------------------------------------------------------------------------------
/// @file  sc_control.h
/// @ingroup  include
///
/// @brief  Declarations related to processing control
/// @internal
/// @author  Minwook Ahn<minwook.ahn@samsung.com>
///
/// @section changelog Change Log
/// 2015/04/10 Minwook Ahn created
/// 2015/12/21 Jongkwon Park added
/// 2015/12/21 Sanghwan Park commented
///
/// @section copyright_section Copyright
/// &copy; 2015, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_CONTROL_H_
#define SCORE_COMMON_INCLUDE_SC_CONTROL_H_

#include "sc_global.h"
#include "sc_errno.h"

/// @brief  Exit status of an execution
/// @ingroup include
enum sc_status_t {
  STS_SUCCESS           = 0,                ///< success
  STS_CONTINUE          = 1,                ///< continue
  STS_CTI_TERMINATED    = 2,                ///< CTI is terminated
  STS_FAILURE           = -EFAILURE,        ///< failure
  STS_FATAL             = -EFATAL,          ///< fatal error
                                            ///< flushing current task, and reset framework
  STS_WRONG_TYPE        = -EWRONGTYPE,      ///< not supported type
  STS_INVALID_VALUE     = -EINVALVALUE,     ///< values specified in flag are invalid
  STS_NULL_PTR          = -ENULLPTR,        ///< input or output image is NULL.
  STS_OUT_OF_RANGE      = -EOUTRANGE,       ///< out of range
  STS_TCM_MALLOC_FAILED = -ETCMMALLOCFAIL,  ///< TCM malloc failed
  STS_MALLOC_FAILED     = -EMALLOCFAIL,     ///< malloc failed
  STS_FOPEN_FAILED      = -EFOPENFAIL,      ///< fopen failed
  STS_NOT_FOUND_KERNEL  = -ENOTFOUNDKERNEL, ///< not found kernel information
  STS_NOT_CONNECTED     = -ENOTCONNECTED,   ///< not connectd kernel
  STS_OVERFLOW_PACKET   = -EOVERFLOWPACKET, ///< not enough packet space
  STS_NOT_FOUND_CMODE   = -ENOTFOUNDCMODE,  ///< not found convert mode
  STS_DUP_CTX_IDX       = -EDUPCTXIDX,      ///< CTX idx already occupied
  STS_TILE_POOL_DRIED   = -ETILEPOOLDRIED,  ///< Free Tile POOL empty
  STS_NOT_FOUND_DECODER = -ENOTFOUNDDECODER,///< not found decoder function
  STS_CRACK_QUEUE       = -ECRACKQUEUE,     ///< The data in the queue is crack
  STS_WRONG_REQUEST     = -EWRONGREQUEST,   ///< User-defined request is wrong
  STS_KERNEL_FAIL       = -EKERNELFAIL,     ///< User-kernel is failed
  STS_OVERFULL_IPC      = -EOVERFULLIPC,    ///< The transmission data larger than system limit
  STS_NOT_EQUAL_ITER    = -ENOTEUQALITER,   ///< Not equal interation count between buffers
  STS_NOT_FOUND_OUTBUF  = -ENOTFOUNDOUTBUF, ///< Not found output buffer
  STS_LEAK_OF_MEMORY    = -ELEAKOFMEMORY,   ///< occur memory leak
  STS_INVALID_SID       = -EINVALSECID,     ///< Invalid section ID
  STS_OCCUPIED_SECTION  = -EOCCUPIEDSID,    ///< Section already occupied
  STS_FREE_SECTION      = -EFREESID,        ///< Section is not being used
  STS_INVALID_PKT_VER   = -EINVALPKTVER,    ///< Invalid packet version
  STS_WRONG_BOX_SIZE    = -EWRONGBOXSZ,     ///< Not supported size of box
  STS_WRONG_PP_POLICY   = -EWRONGPPP,       ///< Not supported Pixel Padding Policy
  STS_PRIVATE_DUMMY                         ///< dummy private kernel is used
};

/// @brief  Check the exit code of X after X is done.
/// @param  [in] X A function or status flag
/// @return Exit a function and return the sc_status_t from X
#define CHECK_STATUS(X) \
  do { \
    sc_status_t status = (sc_status_t)(X); \
    if (status != STS_SUCCESS) { \
      return status; \
    } \
  } while(0)

/// @brief  Performs continue by checking the exit status.
/// @param  [in] X A function or status flag
#define CHECK_CONTINUE(X) \
  if ((sc_status_t)(X) != STS_SUCCESS) { \
    continue; \
  }

/// @brief  Check the return condition.
/// @param  [in] COND   Condition to be checked
/// @param  [in] RETVAL Value to be returned if COND is true
#define CHECK_COND(COND, RETVAL) \
  do { \
    if ((COND)) { \
      return (RETVAL); \
    } \
  } while(0)

// This definition can enable AST TEST
//#define ASB_TEST

#endif
