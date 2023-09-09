#
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
#

ifeq ($(TARGET_SOC_BASE), exynos9820)
exynos9820_dirs := \
	libkeymaster

ifneq ($(BOARD_USES_SW_GATEKEEPER),true)
exynos9820_dirs += libgatekeeper
endif

exynos9820_dirs += mmip

ifeq ($(BOARD_USES_OPENVX), true)
exynos9820_dirs += openvx
endif

include $(call all-named-subdir-makefiles,$(exynos9820_dirs))

endif
