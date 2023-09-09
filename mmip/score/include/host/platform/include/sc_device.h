//------------------------------------------------------------------------------
/// @file  sc_device.h
/// @ingroup  core
///
/// @brief Declaration of ScDeviceManager class
///
/// It is a class that porvides the user with all the control
/// related to the device.
/// This class starts and ends the device and sends each request.
///
/// @internal
/// @author  Rakie Kim<rakie.kim@samsung.com>
///
/// @section changelog Change Log
/// 2017/07/18 Rakie Kim created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_DEVICE_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_DEVICE_H_

#include "sc_platform_global.h"

#include "sc_pimpl_base.h"

#include "profile_tags.h"

namespace score {

typedef enum {
  DEVELOP1,
  DEVELOP2,
  DEVELOP3,
  CAMERA1,
  CAMERA2,
  CAMERA3,
  CAMERA4,
  CAMERA5,
  CAMERA6,
  CAMERA7,
  CAMERA8,
  CAMERA9,
  FIRMWARE_END
} ScoreFirmwareId;

/*
 * DVFS level
 * Supported DVFS levels vary depending on the chipset.
 * AP2 supports from L0 to L4.
 * AP3 supports from L0 to L5.
 */
typedef enum {
  L0,
  L1,
  L2,
  L3,
  L4,
  L5
} ScorePmLevel;

class ScContext;
class ScContextPrivate;
class ScDeviceBenchmark;

class ScDevicePrivate;

/// @brief Public class which handles device control related requests
/// @ingroup SCore_Host_Public_API
class SC_PUBLIC_API ScDevice : public ScPimplBase {
 public:
  /// @brief Destructor
  virtual ~ScDevice();

  /// @brief Returns ScDevice instance
  static ScDevice& instance();

  /// @brief Create and boot device
  /// @param [in] firmware_id Id to select firmware
  /// @return Zero if successful, negative if fail
  int32_t createDevice(int32_t firmware_id);

  /// @brief Create and boot device
  /// @param [in] firmware_id Id to select firmware
  /// @param [in] pm_level Requesting frequency level
  /// @return Zero if successful, negative if fail
  int32_t createDevice(int32_t firmware_id, int32_t pm_level);

  /// @brief Create and boot device
  /// @param [in] firmware_id Id to select firmware
  /// @param [in] pm_level Requesting frequency level
  /// @param [in] flag Additional boot setting
  /// @return Zero if successful, negative if fail
  int32_t createDevice(int32_t firmware_id, int32_t pm_level, int32_t flag);

  /// @brief Release device related information. it is similar to close
  void releaseDevice();

  /// @brief Set frequency level
  /// @param [in] level Requesting frequency level
  /// @return Zero, Positive if successful, negative if fail
  int32_t setFrequencyLevel(int32_t level);

  /// @brief Start collecting profiling information with masking
  /// @param [in] file_name File name to dump profliing data
  /// @param [in] mask mask for selecting traces (by default all traces are enabled)
  /// @return Zero, Positive if successful, negative if fail
  int32_t startProfilerDumping(const char *file_name, uint32_t mask = PROF_TAG_ANY);

  /// @brief Finish collecting profling data
  void endProfilerDumping();

 protected:
  /// @brief  Internal constructor
  ScDevice(ScDevicePrivate &d);

 private:
  /// @brief  Private constructor
  ScDevice();

  SC_DECLARE_PRIVATE(ScDevice)

  friend class ScContext;
  friend class ScContextPrivate;
  friend class ScDeviceBenchmark;
};

} // namespace score

#endif
