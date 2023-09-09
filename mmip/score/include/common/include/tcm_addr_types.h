//------------------------------------------------------------------------------
/// @file  tcm_addr_types.h
/// @ingroup  include
///
/// @brief  Defines types for tcm in appropriate adress space
///
/// Definition of types should prevent comparing and assigning
/// pointers from different adress spaces
///
/// @internal
/// @author  Filip Chudzynski<f.chudzynski@samsung.com>
///
/// @section changelog Change Log
/// 2018/03/12 Filip Chudzynski created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_TCM_ADDR_TYPES_H_
#define SCORE_COMMON_INCLUDE_TCM_ADDR_TYPES_H_

#include <stdint.h>
#if defined(EMULATOR)
#include "score_native.h"
#elif defined(SIMULATOR)
#ifndef __chess__
#define chess_storage(x)
#endif
#endif

typedef void    chess_storage(TCMb) *tcm_ptr_t;
typedef uint8_t chess_storage(TCMb) tcm_uint8_t;

// unsigned integer type that can hold tcm_ptr_t
typedef uintptr_t tcm_uintptr_t;

#define TCM_NULL ((tcm_ptr_t)-1)

#endif
