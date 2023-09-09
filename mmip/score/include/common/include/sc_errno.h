//------------------------------------------------------------------------------
/// @file  sc_errno.h
/// @ingroup  include
///
/// @brief  Declarations the error number for SCore
/// @internal
/// @author  Sanghwan Park<senius.park@samsung.com>
///
/// @section changelog Change Log
/// 2016/06/28 Sanghwan Park created
///
/// @section copyright_section Copyright
/// &copy; 2016, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_ERRNO_H_
#define SCORE_COMMON_INCLUDE_SC_ERRNO_H_

#include "sc_global.h"
#include <errno.h>

/// @brief Define of error for SCore
///
/// Error number is temporary value. This can be changed.
/// {
#define EFAILURE          300  /* Execution failure */
#define EWRONGTYPE        301  /* Not supported type */
#define EINVALVALUE       302  /* Invalid value specified in flag */
#define ENULLPTR          303  /* Unwished NULL pointer */
#define EOUTRANGE         304  /* Out of valid range */
#define ETCMMALLOCFAIL    305  /* TCM malloc failed */
#define EFOPENFAIL        306  /* File open failed */
#define ENOTFOUNDKERNEL   307  /* Not found kernel information*/
#define ENOTCONNECTED     308  /* Not connected kernel */
#define EOVERFLOWPACKET   309  /* Not euought IPC packet space */
#define ENOTFOUNDCMODE    310  /* Not found convert mode */
#define EFATAL            311  /* Fatal error which mean cannot handle */
#define EMALLOCFAIL       312  /* DM malloc failed */
#define EDUPCTXIDX        313  /* CTX idx already occupied */
#define ETILEPOOLDRIED    314  /* Free Tile POOL empty */
#define ENOTFOUNDDECODER  315  /* Not found decoder function */
#define ECRACKQUEUE       316  /* The data in the queue is crack. */
#define EWRONGREQUEST     317  /* User-defined request is wrong. */
#define EKERNELFAIL       318  /* User-kernel is failed */
#define EOVERFULLIPC      319  /* The transmission data larger than system limit */
#define ENOTEUQALITER     320  /* Not equal interation count between buffers */
#define ENOTFOUNDOUTBUF   321  /* Not found output buffer */
#define ELEAKOFMEMORY     322  /* Occur memory leak */
#define EINVALSECID       323  /* Invalid section ID */
#define EOCCUPIEDSID      324  /* Section already occupied */
#define EFREESID          325  /* Section is not being used */
#define EINVALPKTVER      326  /* Invalid packet version */
#define EWRONGBOXSZ       327  /* Not supported size of box */
#define EWRONGPPP         328  /* Not supported pixel padding policy */
/// }

#endif
