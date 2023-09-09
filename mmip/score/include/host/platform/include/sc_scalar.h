//------------------------------------------------------------------------------
/// @file  sc_scalar.h
/// @ingroup  include
///
/// @brief  Declarations of ScScalar class
///
/// ScScalar class includes functions to transfer scalar value to SCore kernel
///
/// @internal
/// @author  Kyungmok Kum<km.kum@samsung.com>
///
/// @section changelog Change Log
/// 2017/06/20 Kyungmok Kum created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_SCALAR_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_SCALAR_H_

#include "sc_platform_global.h"
#include "sc_param.h"

namespace score {

class ScScalarPrivate;

/// @brief  Class for scalar value to execute SCore kernel
/// @ingroup SCore_Host_Public_API
class SC_PUBLIC_API ScScalar : public ScParam {
 public:
  explicit ScScalar();
  explicit ScScalar(uint32_t index, int32_t value);
  virtual ~ScScalar();

  /// @brief  Make stream data for packet
  /// @param [in] pkt memory address to be stored
  /// @return Size of stream data
  int32_t makeParam(uint8_t *pkt) const;

  /// @brief  Get size of stream data for packet
  /// @return Size of stream data
  int32_t getParamSize() const;

  /// @brief  Identify whether this class is buffer or not
  /// @return false cause this is not buffer
  bool isBuffer() const;

  /// @brief Nothing in ScScalar
  /// @param [in] pkt Nothing in ScScalar
  void copyHostInfo(sc_host_info *pkt) const;

 protected:
  ScScalar(ScScalarPrivate &d);

 private:
  SC_DECLARE_PRIVATE(ScScalar)
};

} //namespace score
#endif
