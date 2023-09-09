//------------------------------------------------------------------------------
/// @file  sc_param.h
/// @ingroup  include
///
/// @brief  Declarations of ScParam class
///
/// ScBuffer class includes functions making parameter for SCore kernel
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

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_PARAM_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_PARAM_H_

#include "sc_platform_global.h"

#include "sc_host_info.h"
#include "sc_pimpl_base.h"

namespace score {

class ScParamPrivate;

/// @brief  Abstract base class for Param to execute SCore kernel
class SC_PUBLIC_API ScParam : public ScPimplBase {
 public:
  explicit ScParam();
  virtual ~ScParam();

  /// @brief  Make stream data for packet
  /// @param [in] pkt memory address to be stored
  /// @return Size of stream data
  virtual int32_t makeParam(uint8_t *pkt) const =0;

  /// @brief  Get size of stream data for packet
  /// @return Size of stream data
  virtual int32_t getParamSize() const =0;

  /// @brief  Identify whether this class is buffer or not
  /// @return true for Buffer, false for not
  virtual bool isBuffer() const =0;

  /// @brief Copy Host_info in this class to packet memory
  /// @param [in] pkt host_info memory address to be stored
  virtual void copyHostInfo(sc_host_info *pkt) const =0;

 protected:
  ScParam(ScParamPrivate &d);

 private:
  SC_DECLARE_PRIVATE(ScParam)
};

} //namespace score
#endif
