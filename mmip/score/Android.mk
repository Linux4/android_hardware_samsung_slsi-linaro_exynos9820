LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libscore
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_SHARED_LIBRARIES := libc++ libc libdl libion_exynos liblog libm
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/include/host/platform/include\
                               $(LOCAL_PATH)/include/common/include

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := lib64/libscore.so
LOCAL_SRC_FILES_32 := lib/libscore.so
LOCAL_MULTILIB := both
else #arm64
LOCAL_SRC_FILES := lib/libscore.so
LOCAL_MULTILIB := 32
endif #arm64

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)

LOCAL_MODULE := libscore_device
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_SHARED_LIBRARIES := libc++ libc libdl libion_exynos liblog libm libscore

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := lib64/libscore_device.so
LOCAL_SRC_FILES_32 := lib/libscore_device.so
LOCAL_MULTILIB := both
else #arm64
LOCAL_SRC_FILES := lib/libscore_device.so
LOCAL_MULTILIB := 32
endif #arm64

include $(BUILD_PREBUILT)
