//------------------------------------------------------------------------------
/// @file  sc_perf.h
/// @ingroup  include
///
/// @brief  Declarations of functions and macros related perfomance measure
/// @author  Jeongwan Woo<jw0314.woo@samsung.com>
///
/// @section changelog Change Log
/// 2017/09/07 Jeongwan Woo created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_PERF_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_PERF_H_

#include "sc_platform_global.h"

#include <unistd.h>
#include <time.h>

namespace score {

#define EXECUTION_TIME(prefix, func)                   \
  do {                                                 \
    struct timespec start, end;                        \
    start = ::score::ScoreGetTime();                   \
    (func);                                            \
    end = ::score::ScoreGetTime();                     \
    ::score::ScorePrintDiffTime((prefix), start, end); \
  } while (0)

/// @brief  Measure time in the form of struct timespec
SC_PUBLIC_API struct timespec ScoreGetTime(void);

/// @brief  Calculate difference of time
/// @param  start start time
/// @param  end end time
SC_PUBLIC_API struct timespec ScoreDiffTime(struct timespec start, struct timespec end);

/// @brief  Print difference of time
/// @param  prefix_str prefix log
/// @param  start start time
/// @param  end end time
SC_PUBLIC_API void ScorePrintDiffTime(const char *prefix_str,
                                      struct timespec start, struct timespec end);

/// @brief  Print difference of time
/// @param  prefix_str prefix log
/// @param  kernel_id Id of DSP kernel
/// @param  start start time
/// @param  end end time
SC_PUBLIC_API void ScorePrintDiffTime(const char *prefix_str, uint32_t kernel_id,
                                      struct timespec start, struct timespec end);

} // namespace score

#endif
