//------------------------------------------------------------------------------
/// @file  sc_priority.h
/// @ingroup  include
///
/// @brief  Declaration of Priority mode
/// @author  Jongkwon Park<jong_k.park@samsung.com>
///
/// @section changelog Change Log
/// 2017/09/11 Jongkwon Park created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
///
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_PRIORITY_H_
#define SCORE_COMMON_INCLUDE_SC_PRIORITY_H_

#include "sc_global.h"

/// @enum Enumeration of priority level
/// For Priority level, only HIGH, NORMAL(Default) are available.
enum priority_level {
  SC_PRIORITY_NORMAL   = 0,
  SC_PRIORITY_HIGH     = 1,
  SC_PRIORITY_NUM
};

#define SC_PRIORITY_DEFAULT    SC_PRIORITY_NORMAL

/// @enum Enumeration of Block State
typedef enum {
  BLK_ENABLE  = 0x1,
  BLK_DISABLE = 0x2
} BlockState, block_state;

#endif
