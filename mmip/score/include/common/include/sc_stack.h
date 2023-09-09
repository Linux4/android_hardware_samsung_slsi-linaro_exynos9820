//------------------------------------------------------------------------------
/// @file  sc_stack.h
/// @ingroup  include
///
/// @brief  Declaration of Vector stack
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

#ifndef SCORE_COMMON_INCLUDE_SC_STACK_H_
#define SCORE_COMMON_INCLUDE_SC_STACK_H_

#include "sc_global.h"

/// @enum Enumeration of Vector Stack size
typedef enum {
  VSSIZE_16KB = 0, //0x3fff
  VSSIZE_8KB  = 1, //0x1fff
  VSSIZE_4KB  = 2, //0xfff
} TypeVSSize;

#define DEFAULT_VECTOR_STACK_SIZE VSSIZE_16KB
#define SIZE_480K (480*KiB)
#define SIZE_512K (512*KiB)

inline uint32_t get_vector_stack_size(TypeVSSize type)
{
  uint32_t stack_size = DEFAULT_VECTOR_STACK_SIZE;
  switch(type) {
  case VSSIZE_16KB:
    stack_size = 0x4000;
    break;
  case VSSIZE_8KB:
    stack_size = 0x2000;
    break;
  case VSSIZE_4KB:
    stack_size = 0x1000;
    break;
  }

  return stack_size;
}
#endif
