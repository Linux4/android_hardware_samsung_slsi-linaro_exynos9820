//------------------------------------------------------------------------------
/// @file  sc_bound.h
/// @ingroup  include
///
/// @brief  Declaration of Priority mode
/// @author  Kyungmok Kum<km.kum@samsung.com>
///
/// @section changelog Change Log
/// 2017/12/04 Kyungmok Kum created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
///
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_BOUND_H_
#define SCORE_COMMON_INCLUDE_SC_BOUND_H_

/// @enum Enumeration of Bound Type
typedef enum {
  CPU_BOUND = 0,
  IO_BOUND = 1,
  IO_BOUND_EXCL_TCM = 2
} TypeBound;

#endif
