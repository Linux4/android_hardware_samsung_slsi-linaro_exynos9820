//------------------------------------------------------------------------------
/// @file  sc_context.h
/// @ingroup  include
///
/// @brief  Declarations of ScContext class
///
/// ScContext class includes functions for executing SCore kernel
///
/// @internal
/// @author  Kyoungsoo Cho<ks9.cho@samsung.com>
///
/// @section changelog Change Log
/// 2017/07/12 KyoungSoo Cho created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_CONTEXT_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_CONTEXT_H_

#include "sc_platform_global.h"

#include "sc_control.h"
#include "sc_param.h"
#include "sc_kernel_name.h"
#include "sc_priority.h"
#include "sc_buffer.h"
#include "sc_ipc_packet.h"

#include "sc_pimpl_base.h"
#include "sc_bound.h"
#include "sc_stack.h"

namespace score {

typedef enum {
  SYNC,
  ASYNC,
} TypeExecute;

typedef enum {
  WAIT,
  NOWAIT
} OptionExecute;

class ScContextPrivate;

/// @brief  Class for executing the SCore kernel
/// @ingroup SCore_Host_Public_API
class SC_PUBLIC_API ScContext : public ScPimplBase {
 public:
  /// @brief  Constructor of ScContext class
  ScContext();

  /// @brief  Destructor of ScContext class
  ~ScContext();

  /// @brief  Add paramter of kernel in context
  /// @param [in] param A paramter to be added to context
  /// @return STS_SUCCESS if function succeeds, otherwise proper error
  ///
  /// @warning Objects passed to addParam *must* live long enough, that is until
  ///          buildParam is called. They can be safely deleted after buildParam
  ///          was called. That means you *must* use addParam and buildParam in
  ///          the same scope if you are using stack allocated objects or be
  ///          even more cautious when using heap allocated objects.
  sc_status_t addParam(ScParam *param);

  /// @brief  Add a buffer to delete after excuting kernel
  /// @param [in] pre_buf An parameter to be deleted
  /// @return STS_SUCCESS if function succeeds, otherwise proper error
  sc_status_t addPostDeletingBuffer(ScBuffer *pre_buf);

  /// @brief  Set post proccessing function
  /// @param [in] func Function pointer
  /// @param [in] pre_data An parameter to pass to func
  /// @return STS_SUCCESS if function succeeds, otherwise proper error
  sc_status_t setPostProccessingFunc(void (*func)(sc_status_t, void *), void * pre_data);

  /// @briedf Set Kernel_id to context
  /// @param [in] kernel_id A enum number indicate kernel id
  /// @return STS_SUCCESS if function succeeds, otherwise proper error
  sc_status_t setKernelID(sc_kernel_name_e kernel_id);

  /// @brief  Execute kernel using SCore synchronously or asynchronously
  /// @param [in] type Execute a kernel synchronously if type is SYNC or
  ///         asynchronously if type is ASYNC. default value is SYNC
  /// @param [in] option Execute whether to use wait API if type is ASYNC.
  ///         If option is WAIT, wait API should be called. default value is WAIT
  /// @return Rerutn SC_SUCCESS if function succeeds, otherwise proper error
  ///         when synchronous mode or always return SC_SUCCESS when asynchronous mode
  sc_status_t execute(TypeExecute type = SYNC, OptionExecute option = WAIT);

  /// @brief  Wait response of calling execute and get return value
  ///         when kernel was executed asynchronously
  /// @return STS_SUCCESS if execute function succeeds, otherwise proper error
  sc_status_t wait();

  /// @brief  Build parameters to execute the kernel
  /// @return STS_SUCCESS if function succeeds, otherwise proper error
  ///
  /// @warning All objects passed to addParam *must* still exist when this
  ///          function is called. See addParam for more information.
  sc_status_t buildParam(const ScPacketVersion version = IHM_PKT_VER);

  /// @brief  Set priority level to context
  /// @param [in] priority_level Priority level is set to SC_PRIORITY_NORMAL by default,
  ///         and SC_PRIORITY_HIGH is supported.
  void setPriority(enum priority_level);

  /// @brief  set CPU / IO Bound for optimized operation
  void setBound(TypeBound bound);

  /// @brief  Sets the size of the vector stack to use inside the kernel.
  ///         The default setting is 16kb. caller can increase the size
  ///         of the tile by decreasing vector stack.
  /// @param [in] size size of vector stack
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  void setVectorStack(TypeVSSize vs_size);

  /// @brief  Enable blocking SC_PRIORITY_NORMAL job
  void enableBlockPriority();

  /// @brief  Disable blocking SC_PRIORITY_NORMAL job
  void disableBlockPriority();

  /// @brief  enable sync mode setting for VDIS
  void enableVDISSync();

  /// @brief  enable task split mode
  void enableTaskSplit();

  /// @brief  enable Single Computing Core mode
  void enableSingleKnight();

 protected:
  ScContext(ScContextPrivate &d);

 private:
  SC_DECLARE_PRIVATE(ScContext)

  friend class ScDevicePrivate;
};

} //namespace score
#endif
