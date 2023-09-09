//------------------------------------------------------------------------------
/// @file  sc_log.h
/// @ingroup  include
///
/// @brief  Declaration SCore logging
/// @author  Aleksiej Chrabrow<a.chrabrow@partner.samsung.com>
//
/// @section changelog Change Log
/// 2017/10/27  Aleksiej Chrabrow  created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
///
/// NOTE: On target all C99 specifiers are supported, excluding floating point
///
//------------------------------------------------------------------------------
#ifndef SCORE_COMMON_INCLUDE_LOG_H_
#define SCORE_COMMON_INCLUDE_LOG_H_

#include "sc_global.h"

#ifdef SC_LOG_LEVEL_VERBOSE
#define __sc_log_verbose(fmt, arg...) sc_log(LogLevelVerbose, fmt, ##arg)
#define __sc_log_info(fmt, arg...)    sc_log(LogLevelInfo, fmt, ##arg)
#define __sc_log_error(fmt, arg...)   sc_log(LogLevelError, fmt, ##arg)
#endif

#ifdef SC_LOG_LEVEL_INFO
#define __sc_log_verbose(fmt, arg...)
#define __sc_log_info(fmt, arg...)    sc_log(LogLevelInfo, fmt, ##arg)
#define __sc_log_error(fmt, arg...)   sc_log(LogLevelError, fmt, ##arg)
#endif

#ifdef SC_LOG_LEVEL_SILENT
#define __sc_log_verbose(fmt, arg...)
#define __sc_log_info(fmt, arg...)
#define __sc_log_error(fmt, arg...)   sc_log(LogLevelError, fmt, ##arg)
#endif

#ifndef __sc_log_verbose
#define __sc_log_verbose(fmt, arg...)
#endif

#ifndef __sc_log_info
#define __sc_log_info(fmt, arg...)
#endif

#ifndef __sc_log_error
#define __sc_log_error(fmt, arg...)   sc_log(LogLevelError, fmt, ##arg)
#endif

/// @brief  Log level enum
typedef enum LogLevel {
  LogLevelVerbose,
  LogLevelInfo,
  LogLevelError,
} LogLevel;


static const char *const log_core_names[] = {
#if SCORE_AP_VERSION == 2
  "---",
  "MC0",
  "KC1",
  "KC2"
#elif SCORE_AP_VERSION == 3
/*
 * CORE_ID
 * 00000(0)  : APCPU
 * 00001(1)  : Baron DSP core1
 * 00010(2)  : Baron DSP core2
 * 00011(3)  : IVA
 * 00100(4)  : Thread0 core of TS-II
 * 01000(8)  : Thread1 core of TS-II
 * 01100(12) : Thread2 core of TS-II
 * 10000(16) : Thread3 core of TS-II
 * 10100(20) : Thread4 core of TS-II
 * 11000(24) : Thread5 core of TS-II
 */
  "CPU",
  "BR1",
  "BR2",
  "IVA",
  "TS0", "---", "---", "---",
  "TS1", "---", "---", "---",
  "TS2", "---", "---", "---",
  "TS3", "---", "---", "---",
  "TS4", "---", "---", "---",
  "TS5"
#else
#error "Logger doesn't support this AP version!"
#endif
};

static inline const char *log_level_to_name(LogLevel level)
{
  switch (level) {
  case LogLevelVerbose:
    return "LOG";
  case LogLevelInfo:
    return "DBG";
  case LogLevelError:
    return "ERR";
  default:
    return "???";
  }
}

static inline const char *log_get_core_name(uint32_t core_id)
{
  const size_t core_names_number = sizeof(log_core_names) / sizeof(log_core_names[0]);
  if (core_id < core_names_number) {
    return log_core_names[core_id];
  } else {
    return "???";
  }
}

/// @brief  Write log message with specified log level
/// @param  level   Log level for this message
/// @param  format  Format string
/// @param  ...     Printf arguments list
SC_PUBLIC_API
void sc_log(LogLevel level, const char *format, ...)
SC_PRINTF_FORMAT_CHECK_ATTR(2, 3);

#endif
