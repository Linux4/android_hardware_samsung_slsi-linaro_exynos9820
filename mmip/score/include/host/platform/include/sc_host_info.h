//------------------------------------------------------------------------------
/// @file  sc_host_info.h
/// @ingroup  include
///
/// @brief  Declarations of buffer handler
/// @internal
/// @author  Sanghwan Park<senius.park@samsung.com>
///
/// @section changelog Change Log
/// 2016/06/16 Sanghwan Park created
///
/// @section copyright_section Copyright
/// &copy; 2016, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_DATA_TYPE_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_DATA_TYPE_H_

#include "sc_platform_global.h"

namespace score {

enum host_info_type {
  MEMORY_TYPE = 1,
  TASK_ID_TYPE
};

/// @brief  Memory information of image buffer handler
///
/// This data structure handles memory info of any image buffer in Host.
typedef struct _sc_host_info {
  unsigned int memory_type: 3;  ///< memory type like USERPTR or DMABUF
  unsigned int offset:      29; ///< offset about base address of memory of TASK_ID
  unsigned int memory_size;     ///< byte size of memory
  union {
    int           fd;       ///< fd of ION
    unsigned long userptr;  ///< address of userptr
    uint64_t      dummy;    ///< dummy for fixed size
  } m;
  unsigned int addr_offset: 29; ///< offset about address of ScBuffer
  unsigned int type:        3;  ///< MEMORY_TYPE or TASK_ID_TYPE
  unsigned int reserved;
} sc_host_info;

} // namespace score
#endif
