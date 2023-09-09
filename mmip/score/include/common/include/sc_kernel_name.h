//------------------------------------------------------------------------------
/// @file  sc_kernel_name.h
/// @ingroup  include
///
/// @brief  Name of the kernels implemented in SCore
/// @internal
/// @author  Minwook Ahn<minwook.ahn@samsung.com>
///
/// @section changelog Change Log
/// 2015/04/14 Minwook Ahn created
/// 2016/06/13 Sanghwan Park modified
/// 2016/06/20 Nahyun Kim modified
///
/// @section copyright_section Copyright
/// &copy; 2015, Samsung Electronics Co., Ltd.
///
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_KERNEL_NAME_H_
#define SCORE_COMMON_INCLUDE_SC_KERNEL_NAME_H_

#include "sc_global.h"

/// @brief  Name of kernels
/// @ingroup common
#define DEFINE_CTI(cti_id, cti_name, cti_fn)
#define DEFINE_KERNEL(kernel_id, kernel_name, k_fn) \
  kernel_name = kernel_id,
enum sc_kernel_name_e {
#include "kernels.incl"
};
#undef DEFINE_KERNEL
#undef DEFINE_CTI

/// @brief  Name of CTIs
/// @ingroup common
#define DEFINE_KERNEL(kernel_id, kernel_name, k_fn)
#define DEFINE_CTI(cti_id, cti_name, cti_fn) \
  cti_name = cti_id,
enum sc_cti_name_e {
#include "kernels.incl"
};
#undef DEFINE_KERNEL
#undef DEFINE_CTI


/// @brief  SCore kernel name registered
///
/// This is used for debugging and doesn't have an effect on the execution.
/// The content of this array must be the same with sc_kernel_name_e
extern char sc_kernel_name[][50];

#endif
