//------------------------------------------------------------------------------
/// @file  sc_assert.h
/// @ingroup  include
///
/// @brief  Declarations related to assert control
/// @internal
/// @author  Yongjun Kim<kyj0713.kim@samsung.com>
///
/// @section changelog Change Log
/// 2016/06/15 Yongjun Kim created
///
/// @section copyright_section Copyright
/// &copy; 2015, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_ASSERT_H_
#define SCORE_COMMON_INCLUDE_SC_ASSERT_H_

#include "sc_global.h"

#ifdef SCORE_TARGET
#include "chess.h"
#else
#ifndef chess_frequent_else
#define chess_frequent_else
#endif
#endif

#include "sc_printf.h"

#if defined(SCORE_TARGET) && !defined(EMULATOR)

#ifdef assert
#undef assert
#endif

#ifdef DEBUG
#define assert(expr)                   \
  do {                                 \
    if (!(expr)) chess_frequent_else { \
      sc_log_error("assert failed\n"); \
    }                                  \
  } while(0)
#else // DEBUG
#define assert(expr)  ((void)0)
#endif // DEBUG

#endif // SCORE_TARGET

#ifdef DEBUG

#include <assert.h>

#define SC_ASSERT(COND, MSG)          \
  do {                                \
    if(!(COND)) chess_frequent_else { \
      assert(!#COND ": " MSG);        \
    }                                 \
  } while(0)

#define SC_ASSERTCHECK(COND, RETVAL, MSG)               \
  do {                                                  \
    if (!(COND)) chess_frequent_else {                  \
      sc_log_error("ASSERTCHECK: "#COND ": " MSG "\n"); \
      return (RETVAL);                                  \
    }                                                   \
  } while(0)

#else // not DEBUG

/// @brief  Check the assert condition.
/// @param [in] COND  Condition to be checked
/// @param [in] MSG   Message to be printed if COND is false
///
/// @note This is only used in debug mode
#define SC_ASSERT(COND, MSG) \
  do { } while(0)

/// @brief  Check the assert condition or the return condition.
/// @param [in] COND    Condition to be checked
/// @param [in] RETVAL  Value to be returned if COND is false
/// @param [in] MSG     Message to be printed if COND is false
///
/// @note This is the same as SC_ASSERT in debug mode but in release mode returns
/// RETVAL.
#define SC_ASSERTCHECK(COND, RETVAL, MSG) \
  do {                                    \
    if (!(COND)) chess_frequent_else {    \
      return (RETVAL);                    \
    }                                     \
  } while(0)

#endif // DEBUG

#endif
