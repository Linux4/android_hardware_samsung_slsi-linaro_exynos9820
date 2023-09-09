//------------------------------------------------------------------------------
/// @file  sc_global.h
/// @ingroup  include
///
/// @brief   Global definitions and declarations for SCore SDK
/// @author  Aleksiej Chrabrow<a.chrabrow@partner.samsung.com>
///
/// @section changelog Change Log
/// 2017/09/27  Aleksiej Chrabrow  created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_GLOBAL_H_
#define SCORE_COMMON_INCLUDE_SC_GLOBAL_H_

//
// This file unifies data types required by SCore SDK
// between C and C++ compilers. It facilitates writing
// code that can be compiled by both C and C++ compilers.
//
// After 'sc_global.h' is included following types are defined
// in global scope:
//
//  * [u]int(8|16|32|64)_t sized integers
//
//  * size_t, uintptr_t, intptr_t types
//
//  * bool data type with true, false constants
//    (in C mode, in C++ bool is native)
//
// This header defines SC_NULLPTR macro that provides
// additional pointer safety when compiled by C++11
// compilers.
//

#if (defined __cplusplus) && (__cplusplus >= 201103L)
// using C++11 or newer compiler
#include <cstddef>
#include <cstdint>
#define SC_NULLPTR nullptr
using std::int8_t;
using std::uint8_t;
using std::int16_t;
using std::uint16_t;
using std::int32_t;
using std::uint32_t;
using std::int64_t;
using std::uint64_t;
using std::size_t;
using std::uintptr_t;
using std::intptr_t;
#else
// when using C++ compiler older than C++11 or plain C compiler
// fallback to using C headers
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#define SC_NULLPTR NULL
#endif

//
// SCore version defines
//

#if !defined(SCORE_VERSION)
#define SCORE_VERSION 31
#else
#if SCORE_VERSION < 10
#error "SCORE_VERSION must be >= 10."
#endif
#endif

#if !defined(SCORE_AP_VERSION)
#define SCORE_AP_VERSION (SCORE_VERSION / 10)
#endif

#if !defined(SCORE_EVT_VERSION)
#define SCORE_EVT_VERSION (SCORE_VERSION % 10)
#endif

//
// SCore log level defines
//
#if !defined(SC_LOG_LEVEL_VERBOSE) || !defined(SC_LOG_LEVEL_INFO) || !defined(SC_LOG_LEVEL_SILENT)
#define SC_LOG_LEVEL_INFO 1
#endif

//
// Printf format checker attribute
//

#if defined __GNUC__ || defined __clang__
#define SC_PRINTF_FORMAT_CHECK_ATTR(format_index, first_to_check_index) \
    __attribute__((format(printf, format_index, first_to_check_index)))
#else
#define SC_PRINTF_FORMAT_CHECK_ATTR(format_index, first_to_check_index)
#endif

//
// Exported functions and classes belong to one of three categories:
//
// * SC_PUBLIC_API - stable, public API with stable ABI, always exported
//
// * SC_INTERNAL_SERVICE_API - required by SCore Daemon, not-stable,
//                             always exported
//
// * SC_INTERNAL_EXPORTED_API - required for running tests, not-stable,
//                              unavailable in final release build
//

#if (defined(SC_BUILDING_SHARED_LIBSCORE)                              \
     && ((defined(__GNUC__) && (__GNUC__ >= 4))                        \
         || (defined(__clang__)                                        \
             && (__clang_major__ >= 4                                  \
                 || (__clang_major__ == 3 && __clang_minor__ >= 8)))))
// visibility support requires compiler to be GCC/G++ >= 4 or clang >= 3.8
#  define SC_PUBLIC_API  __attribute__((visibility("default")))
#  define SC_INTERNAL_SERVICE_API  __attribute__((visibility("default")))
#  ifdef SC_EXPORT_ONLY_PUBLIC_API
#    define SC_INTERNAL_EXPORTED_API
#  else
#    define SC_INTERNAL_EXPORTED_API  __attribute__((visibility("default")))
#  endif
#else
#  define SC_PUBLIC_API
#  define SC_INTERNAL_SERVICE_API
#  define SC_INTERNAL_EXPORTED_API
#endif

#define UNUSED(x) (void)(x)

/// Defines the various type used in kernels
/// Number of vector slots when the bit of data types is 8/16/32
#define VWORD         (512)
#define NOOFSLOT(N)   (VWORD/N)

#define UNROLL_02     (2)
#define UNROLL_04     (4)
#define UNROLL_08     (8)
#define UNROLL_16     (16)

#define KiB           (1024)

#endif
