/*
**
** Copyright 2017, Samsung Electronics Co. LTD
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef EXYNOS_CAMERA_SENSOR_INFO_H
#define EXYNOS_CAMERA_SENSOR_INFO_H

#include "ExynosCameraSensorInfoBase.h"

namespace android {

struct ExynosCameraSensor2L7 : public ExynosCameraSensor2L7Base {
public:
    ExynosCameraSensor2L7();
};

struct ExynosCameraSensor2P8 : public ExynosCameraSensor2P8Base {
public:
    ExynosCameraSensor2P8();
};

struct ExynosCameraSensorIMX333_2L2 : public ExynosCameraSensorIMX333_2L2Base {
public:
    ExynosCameraSensorIMX333_2L2(int sensorId);
};

struct ExynosCameraSensor2L3 : public ExynosCameraSensor2L3Base {
public:
    ExynosCameraSensor2L3(int sensorId);
};

struct ExynosCameraSensorIMX320_3H1 : public ExynosCameraSensorIMX320_3H1Base {
public:
    ExynosCameraSensorIMX320_3H1(int sensorId);
};

struct ExynosCameraSensor3M3 : public ExynosCameraSensor3M3Base {
public:
    ExynosCameraSensor3M3(int sensorId);
};

struct ExynosCameraSensorS5K5F1 : public ExynosCameraSensorS5K5F1Base {
public:
    ExynosCameraSensorS5K5F1(int sensorId);
};

/* Helpper functions */
struct ExynosCameraSensorInfoBase *createExynosCameraSensorInfo(int sensorName);
struct HAL_CameraInfo_t *getExynosCameraVendorDeviceInfoByServiceCamId(int serviceCameraId);
struct HAL_CameraInfo_t *getExynosCameraVendorDeviceInfoByCamIndex(int camIndex);
int getExynosCameraVendorDeviceInfoSize();

}; /* namespace android */
#endif
