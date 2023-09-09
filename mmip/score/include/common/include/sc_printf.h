//------------------------------------------------------------------------------
/// @file  sc_printf.h
/// @ingroup  include
///
/// @brief  Declarations of functions and macros about debugging log
/// @internal
/// @author  Rakie Kim<rakie.kim@samsung.com>
///
/// @section changelog Change Log
/// 2015/11/16 Rakie Kim created
/// 2015/12/09 Sanghwan Park commented
/// 2017/07/28 Kyungmok Kum Modified
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
///
/// NOTE: On target all C99 specifiers are supported, excluding floating point
///
//------------------------------------------------------------------------------
#ifndef SCORE_COMMON_INCLUDE_SC_PRINTF_H_
#define SCORE_COMMON_INCLUDE_SC_PRINTF_H_

#include <stdarg.h>
#include <stdio.h>

#include "sc_global.h"
#include "sc_log.h"

// public API
#if !defined(RTL)
#define sc_log_verbose(fmt, arg...) __sc_log_verbose(fmt, ##arg)
#define sc_log_info(fmt, arg...)    __sc_log_info(fmt, ##arg)
#define sc_log_error(fmt, arg...)   __sc_log_error(fmt, ##arg)

// legacy names
#define sc_printf(fmt, arg...)  sc_log_info(fmt, ##arg)
#define sc_error(fmt, arg...)   sc_log_error(fmt, ##arg)
#else
#define sc_log_verbose(fmt, arg...)
#define sc_log_info(fmt, arg...)
#define sc_log_error(fmt, arg...)

// legacy names
#define sc_printf(fmt, arg...)
#define sc_error(fmt, arg...)
#endif
#endif
