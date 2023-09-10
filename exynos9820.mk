#
# Copyright (C) 2013 The Android Open Source Project
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
#

# video codecs
PRODUCT_PACKAGES := \
	libOMX.Exynos.MPEG4.Decoder \
	libOMX.Exynos.AVC.Decoder \
	libOMX.Exynos.WMV.Decoder \
	libOMX.Exynos.VP8.Decoder \
	libOMX.Exynos.HEVC.Decoder \
	libOMX.Exynos.VP9.Decoder \
	libOMX.Exynos.MPEG4.Encoder \
	libOMX.Exynos.AVC.Encoder \
	libOMX.Exynos.VP8.Encoder \
	libOMX.Exynos.HEVC.Encoder \
	libOMX.Exynos.VP9.Encoder \
	libOMX.Exynos.AVC.WFD.Encoder \
	libOMX.Exynos.HEVC.WFD.Encoder

# stagefright and device specific modules
PRODUCT_PACKAGES += \
	libstagefrighthw \
	libExynosOMX_Core \
	libExynosOMX_Resourcemanager

# mmip Libraries
PRODUCT_PACKAGES += \
	libscore \
	libscore_device\
	libiva_android_hal

# OpeVX Libraries
ifeq ($(BOARD_USES_OPENVX),true)
PRODUCT_PACKAGES += \
	libopenvx \
	libvxu

PRODUCT_PACKAGES += \
	libhifistill \
	libhifistill_tuning \
	libhifivdislib

TARGET_MODEL := $(findstring beyond, $(TARGET_PRODUCT))
ifeq ($(strip $(TARGET_MODEL)),)
TARGET_MODEL := beyond
endif

SOVX_TOP_SRC_DIR := hardware/samsung_slsi-linaro-linaro/exynos9820/openvx/$(TARGET_MODEL)
SOVX_TOP_DST_DIR := $(TARGET_COPY_OUT_VENDOR)/openvx

SOVX_COST_SRC_DIR := $(SOVX_TOP_SRC_DIR)/raw/cost
SOVX_COST_DST_DIR := $(SOVX_TOP_DST_DIR)/cost

SOVX_XML_SRC_DIR := $(SOVX_TOP_SRC_DIR)/raw/xml
SOVX_XML_DST_DIR := $(SOVX_TOP_DST_DIR)/xml

PRODUCT_COPY_FILES += \
	$(SOVX_COST_SRC_DIR)/cost_c_iva.dat:$(SOVX_COST_DST_DIR)/cost_c_iva.dat \
	$(SOVX_COST_SRC_DIR)/cost_c_neon.dat:$(SOVX_COST_DST_DIR)/cost_c_neon.dat \
	$(SOVX_COST_SRC_DIR)/cost_c_score.dat:$(SOVX_COST_DST_DIR)/cost_c_score.dat \
	$(SOVX_COST_SRC_DIR)/cost_c_std.dat:$(SOVX_COST_DST_DIR)/cost_c_std.dat \
	$(SOVX_COST_SRC_DIR)/cost_iva.dat:$(SOVX_COST_DST_DIR)/cost_iva.dat \
	$(SOVX_COST_SRC_DIR)/cost_score.dat:$(SOVX_COST_DST_DIR)/cost_score.dat

PRODUCT_COPY_FILES += \
	$(SOVX_XML_SRC_DIR)/_hifi_still_schedule.xml:$(SOVX_XML_DST_DIR)/_hifi_still_schedule.xml \
	$(SOVX_XML_SRC_DIR)/hifi_allstages_no_file_writes.xml:$(SOVX_XML_DST_DIR)/hifi_allstages_no_file_writes.xml
endif
