TARGET_MODEL := $(findstring beyond, $(TARGET_PRODUCT))
ifeq ($(strip $(TARGET_MODEL)),)
TARGET_MODEL := beyond
endif

LOCAL_PATH := $(call my-dir)/$(TARGET_MODEL)

include $(CLEAR_VARS)

LOCAL_MODULE := libopenvx
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_C_INCLUDES)
LOCAL_SHARED_LIBRARIES := android.frameworks.schedulerservice@1.0 libc++ libc libcutils libdl libhidlbase libiva_android_hal liblog libm libutils libutilscallstack libxml2 libz

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := core/lib64/libopenvx.so
LOCAL_SRC_FILES_32 := core/lib32/libopenvx.so
LOCAL_MULTILIB := both
else
LOCAL_SRC_FILES := core/lib32/libopenvx.so
LOCAL_MULTILIB := 32
endif

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)

LOCAL_MODULE := libvxu
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_C_INCLUDES)
LOCAL_SHARED_LIBRARIES := libc++ libc libdl libm libopenvx

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := core/lib64/libvxu.so
LOCAL_SRC_FILES_32 := core/lib32/libvxu.so
LOCAL_MULTILIB := both
else
LOCAL_SRC_FILES := core/lib32/libvxu.so
LOCAL_MULTILIB := 32
endif

include $(BUILD_PREBUILT)


include $(CLEAR_VARS)

LOCAL_MODULE := libhifistill
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/
LOCAL_SHARED_LIBRARIES := libc++ libc libcutils libdl libiva_android_hal liblog libm libopenvx libvxu
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := engines/hifi_still/lib64/libhifistill.so
LOCAL_SRC_FILES_32 := engines/hifi_still/lib32/libhifistill.so
LOCAL_MULTILIB := both
else
LOCAL_SRC_FILES := engines/hifi_still/lib32/libhifistill.so
LOCAL_MULTILIB := 32
endif

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)

LOCAL_MODULE := libhifistill_tuning
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/
LOCAL_SHARED_LIBRARIES := libc++ libc libm libdl

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := engines/hifi_still/lib64/libhifistill_tuning.so
LOCAL_SRC_FILES_32 := engines/hifi_still/lib32/libhifistill_tuning.so
LOCAL_MULTILIB := both
else
LOCAL_SRC_FILES := engines/hifi_still/lib32/libhifistill_tuning.so
LOCAL_MULTILIB := 32
endif

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)

LOCAL_MODULE := libhifivdislib
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/
LOCAL_SHARED_LIBRARIES := libc++ libc libcutils libdl libiva_android_hal liblog libm libopenvx

ifeq ($(TARGET_ARCH),arm64)
LOCAL_SRC_FILES_64 := engines/hifi_video/lib64/libhifivdislib.so
LOCAL_SRC_FILES_32 := engines/hifi_video/lib32/libhifivdislib.so
LOCAL_MULTILIB := both
else
LOCAL_SRC_FILES := engines/hifi_video/lib32/libhifivdislib.so
LOCAL_MULTILIB := 32
endif

include $(BUILD_PREBUILT)
