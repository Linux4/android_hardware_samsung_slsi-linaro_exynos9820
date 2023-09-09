//------------------------------------------------------------------------------
/// @file  sc_dma.h
/// @ingroup  include
///
/// @brief  Declaration of the DMA mode
/// @internal
/// @author  Jongkwon Park<jong_k.park@samsung.com>
//
/// @section changelog Change Log
/// 2017/06/28 Jongkwon Park created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
///
//------------------------------------------------------------------------------
#ifndef SCORE_COMMON_INCLUDE_SC_DMA_H_
#define SCORE_COMMON_INCLUDE_SC_DMA_H_

#include "sc_global.h"

#define CHECK_DFC_USER_MODE(A, B) (uint8_t)(B >> (8*A))
#define CHECK_DFC_GROUP(A, B) (uint8_t)(CHECK_DFC_USER_MODE(A, B) >> 4)
#define CHECK_DFC_MODE(A, B) (uint8_t)(CHECK_DFC_USER_MODE(A, B) & 0xf)

/// @brief  Masking value distinguishing the specific DFC mode
#define EXT_2D_MASK         0X20
#define TRNC_AVG_MASK       0X10
#define DEI_4CH_MASK        0X10

/// @enum  Defined direction of DMA
enum DIRECTION_OF_DMA {
  DRAM_TO_TCM = 0,
  TCM_TO_DRAM
};

// @brief  Defined DFC mode (Default : DFC_NORMAL)
#define DFC_NORMAL          0

/// @enum  Enumeration of SKIP mode
enum SKIP_GROUP {
  DFC_SKIP_ALPHA0 = 16,
  DFC_SKIP_ALPHA3
};

/// @enum  Enumeration of SATURATION mode
enum SAT_GROUP {
  DFC_SAT_U16U8 = 33,
  DFC_SAT_U32U16,
  DFC_SAT_U32U8,
  DFC_SAT_U16S8 = 37,
  DFC_SAT_U32S16,
  DFC_SAT_U32S8,
  DFC_SAT_S16U8 = 41,
  DFC_SAT_S32U16,
  DFC_SAT_S32U8,
  DFC_SAT_S16S8 = 45,
  DFC_SAT_S32S16,
  DFC_SAT_S32S8,
  DFC_TRNC_16_8 = 49,
  DFC_TRNC_32_16,
  DFC_TRNC_32_8,
  DFC_AVG_16_8 = 53,
  DFC_AVG_32_16,
  DFC_AVG_32_8
};

/// @enum  Enumeration of INTERLEAVE mode
enum INT_GROUP {
  DFC_INTLV_2CH = 65,
  DFC_INTLV_3CH,
  DFC_INTLV_4CH = 68
};

/// @enum  Enumeration of DEINTERLEAVE mode
enum DEI_GROUP {
  DFC_DEINTLV_4CH = 80,
  DFC_DEINTLV_3CH_SEL0,
  DFC_DEINTLV_3CH_SEL1,
  DFC_DEINTLV_3CH_SKIP2,
  DFC_DEINTLV_3CH_SEL2,
  DFC_DEINTLV_3CH_SKIP1,
  DFC_DEINTLV_3CH_SKIP0,
  DFC_DEINTLV_3CH,
  DFC_DEINTLV_YUYV = 89,
  DFC_DEINTLV_UYVY,
  DFC_DEINTLV_2CH = 92
};

/// @enum  Enumeration of EXTENSION mode
enum EXT_GROUP {
  DFC_EXT_U8U16 = 97,
  DFC_EXT_U16U32,
  DFC_EXT_U8U32,
  DFC_EXT_S8S16 = 101,
  DFC_EXT_S16S32,
  DFC_EXT_S8S32,
  DFC_EXT_S8U16 = 105,
  DFC_EXT_S16U32,
  DFC_EXT_S8U32,
  DFC_DUP_8 = 109,
  DFC_DUP_16,
#if SCORE_AP_VERSION == 2 //AP2
  DFC_DUP_2D_8 = 125,
  DFC_DUP_2D_16
#endif
};

/// @enum  Enumeration of ROTATE mode
enum ROT_GROUP {
  DFC_FLIP_V = 129,
  DFC_FLIP_H,
  DFC_ROT_180,
  DFC_ROT_TRANSPOSE0,
#if SCORE_AP_VERSION == 2 //AP2
  DFC_ROT_270,
  DFC_ROT_90,
#else //AP3
  DFC_ROT_90,
  DFC_ROT_270,
#endif
  DFC_ROT_TRANSPOSE1
};

/// @enum  Enumeration of TENBIT mode
enum TENBIT_GROUP {
  DFC_RAW10_UPACK16 = 144,
  DFC_RAW10_PACK12,
  DFC_P010_Y,
  DFC_P010_UV,
  DFC_SAMSUNG10_8_Y,
  DFC_SAMSUNG10_2_Y,
  DFC_SAMSUNG10_8_UV,
  DFC_SAMSUNG10_2_UV
};

/// @enum  Enumeration of PIXEL PADDING mode
enum PP_GROUP {
  DFC_PP_REPLICATE = 160,
  DFC_PP_SET,
  DFC_PP_MIRROR,
  DFC_PP_MIRROR_101
};

/// @enum  Enumeration of SCATTER GATHER mode
enum SG_GROUP {
  DFC_SCATTER_GATHER = 176
};

/// @enum  Enumeration of ROI border policy
enum ROI_BORDER_POLICY {
  ROI_NOT_SET = 0,      ///< not used ROI (default)
  ROI_VALID_BORDER = 1, ///< if neighbor processing is required, use the valid values
  ///< of the image at the ROI boundary.
  ROI_HW_BORDER = 2     ///< if neirhbor processing is required, all ROI boundary
                  ///< are treated as H/W padding policy.
};

#define   ITER_COL          (0x00000001)
#define   ITER_ROW          (0x00000100)
#define   ITER_CONTI        (0x00010000)
#define   ITER_LEFT         (0x01000000)
#define   ITER_RIGHT        (0x02000000)
#define   ITER_TOP          (0x04000000)
#define   ITER_BOT          (0x08000000)

/// @enum  Enumeration of ITER policy (mode used in setTileIterator)
enum ITER_POLICY {
  ITER_COL_LEFT_TOP         = ITER_COL | ITER_LEFT | ITER_TOP,
  ITER_COL_LEFT_BOT         = ITER_COL | ITER_LEFT | ITER_BOT,
  ITER_COL_RIGHT_TOP        = ITER_COL | ITER_RIGHT | ITER_TOP,
  ITER_COL_RIGHT_BOT        = ITER_COL | ITER_RIGHT | ITER_BOT,
  ITER_ROW_LEFT_TOP         = ITER_ROW | ITER_LEFT | ITER_TOP,
  ITER_ROW_LEFT_BOT         = ITER_ROW | ITER_LEFT | ITER_BOT,
  ITER_ROW_RIGHT_TOP        = ITER_ROW | ITER_RIGHT | ITER_TOP,
  ITER_ROW_RIGHT_BOT        = ITER_ROW | ITER_RIGHT | ITER_BOT,
  ITER_COL_LEFT_TOP_CONTI   = ITER_CONTI | ITER_COL_LEFT_TOP,
  ITER_COL_LEFT_BOT_CONTI   = ITER_CONTI | ITER_COL_LEFT_BOT,
  ITER_ROW_LEFT_TOP_CONTI   = ITER_CONTI | ITER_ROW_LEFT_TOP,
  ITER_ROW_RIGHT_BOT_CONTI  = ITER_CONTI | ITER_ROW_RIGHT_TOP,
};

/// @enum  Enumeration of DFC group
enum DFC_GROUP {
  NORMAL,
  SKIP,
  SATURATION,
  TRNC_AVG,
  INTLV,
  DEINTLV,
  EXTENSION_1D,
  EXTENSION_2D,
  ROTATION,
  TENBIT,
  PIXEL_PADDING,
  SCATTER_GATHER
};

#endif
