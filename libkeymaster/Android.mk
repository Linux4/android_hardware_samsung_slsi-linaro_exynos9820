# Copyright (C) 2012 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

MOBICORE_PATH := hardware/samsung_slsi-linaro-linaro/$(TARGET_SOC_BASE)/mobicore

LOCAL_MODULE := keystore.$(TARGET_SOC)
LOCAL_MODULE_RELATIVE_PATH := hw

USE_VENDOR_PARTITION ?= YES

ifeq ($(BOARD_USES_KEYMASTER_VER1), true)
LOCAL_CPPFLAGS := -Wall
LOCAL_CPPFLAGS += -Wextra
LOCAL_CPPFLAGS += -Werror
LOCAL_CPPFLAGS += -std=c++11 -std=c++17

ALL_SRC_FILES := $(wildcard ${LOCAL_PATH}/ver1/src/*.cpp \
                            ${LOCAL_PATH}/ver1/src/*.c)
LOCAL_SRC_FILES := $(ALL_SRC_FILES:$(LOCAL_PATH)/ver1/%=ver1/%)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/ver1/include
else
LOCAL_SRC_FILES := \
	ver0/keymaster_mobicore.cpp \
	ver0/tlcTeeKeymaster_if.c
LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/ver0 \
	$(MOBICORE_PATH)/daemon/ClientLib/public \
	$(MOBICORE_PATH)/common/MobiCore/inc/
LOCAL_C_FLAGS = -fvisibility=hidden -Wall -Werror

ifeq ($(BOARD_USES_KEYMASTER_VER0_3), true)
	LOCAL_CFLAGS += -DKEYMASTER_VER0_3
endif
endif

# ExySp
LOCAL_C_INCLUDES += external/libcxx/include
LOCAL_C_INCLUDES += hardware/libhardware/include/
LOCAL_C_INCLUDES += system/core/libsystem/include/
LOCAL_C_INCLUDES += system/keymaster/include/keymaster/

# ExySp: add define for LOG
LOCAL_CFLAGS += -DLOG_ANDROID

# ExySp: add libcutils for property
LOCAL_SHARED_LIBRARIES := libcrypto liblog libMcClient libcutils
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES

ifeq ($(USE_VENDOR_PARTITION), YES)
LOCAL_PROPRIETARY_MODULE := true
endif

include $(BUILD_SHARED_LIBRARY)
