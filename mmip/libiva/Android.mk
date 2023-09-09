LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libiva_android_hal
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_SHARED_LIBRARIES := libc++ libc libdl liblog libm

TARGET_MODEL := $(findstring beyond, $(TARGET_PRODUCT))
ifeq ($(strip $(TARGET_MODEL)),)
TARGET_MODEL := beyond
endif

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := $(TARGET_MODEL)/lib64/libiva_android_hal.so
LOCAL_SRC_FILES_32 := $(TARGET_MODEL)/lib32/libiva_android_hal.so
LOCAL_MULTILIB := both
else
LOCAL_SRC_FILES := $(TARGET_MODEL)/lib32/libiva_android_hal.so
LOCAL_MULTILIB := 32
endif

include $(BUILD_PREBUILT)
