//------------------------------------------------------------------------------
/// @file  sc_global.h
/// @ingroup  include
///
/// @brief   Global definitions and declarations for host part of SCore SDK
/// @author  Aleksiej Chrabrow<a.chrabrow@partner.samsung.com>
///
/// @section changelog Change Log
/// 2017/09/27  Aleksiej Chrabrow  created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
///
/// This file must be included by every SCore public header.
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_GLOBAL_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_GLOBAL_H_

#include "sc_global.h"

//
// Compatibility with pre-C++11 compilers
//
// Please use SC_OVERRIDE instead of 'override' keyword and
// and SC_NULLPTR from sc_global.h for 'nullptr' inside
// SCore public headers.
//
#if __cplusplus >= 201103L
#define SC_OVERRIDE override
#else
#define SC_OVERRIDE
#endif

#endif
