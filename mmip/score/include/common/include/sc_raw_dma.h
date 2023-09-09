//------------------------------------------------------------------------------
/// @file  sc_raw_dma.h
/// @ingroup  include
///
/// @brief  Declaration of a class representing module managing interrupts
///
/// The main task for this class is to manage interrupts passing between actors
/// (instances of classes derived from AbstractCore).
///
/// @internal
/// @author  generated
///
/// @section changelog Change Log
/// 2017/03/02 generated
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_RAW_DMA_H_
#define SCORE_COMMON_INCLUDE_SC_RAW_DMA_H_

#include "sc_global.h"

// Read DMA0
struct DFC_CONFIG_0
{
 #if SCORE_AP_VERSION == 2
    uint32_t BPP      :3,
    // 1 Pixel == [2:0](3'b000):1 Byte,(3'b001):2 Bytes,
    //            (3'b011):4 Bytes,(3'b100):2bit,
    //            (3'b101):12bit
    FROM_DRAM         :1,
    SAT_ENABLE        :1,
    DEI_ENABLE        :1, //De-interleaved
    SKIP_ENABLE       :1,
    PP_ENABLE         :1,
    SG_ENABLE         :1,
    EXT_ENABLE        :1,
    ROT_ENABLE        :1,
    TENBIT_ENABLE     :7;
#else
    uint32_t BPP      :3,
    FROM_DRAM         :1,
    SKIP_ENABLE       :1,
    SAT_ENABLE        :1,
    DEI_ENABLE        :1,
    EXT_ENABLE        :1,
    ROT_ENABLE        :1,
    PP_ENABLE         :1,
    SG_ENABLE         :1,
    TENBIT_ENABLE     :7;
#endif
};

// Write DMA1
struct DFC_CONFIG_1
{
    uint32_t BPP        :2,
    // 1 Pixel == [1:0](2'b00):1 Byte,(2'b01):2 Bytes,
    //            (2'b10):3Bytes,(2'b11):4 Bytes
    TO_DRAM             :1,
    SAT_ENABLE          :1,
    INT_ENABLE          :1, //Interleaved
    SKIP_ENABLE         :1,
    EXT_ENABLE          :1,
    ROT_ENABLE          :1,
    TENBIT_ENABLE   :7;
};

#if SCORE_AP_VERSION == 3
typedef struct _dma0_tile_info {
    uint8_t    tile_bpp;
    uint32_t   tile_width;
    uint32_t   tile_height;
    uint8_t    *src_addr0;
    uint32_t   src_basewidth;
    uint32_t   src_stridewidth;
    uint8_t    src_3d_trans;
    uint8_t    *dst_addr0;
    uint8_t    *dst_addr1;
    uint8_t    *dst_addr2;
    uint8_t    *dst_addr3;
    uint32_t   dst_basewidth;
} dma0_tile_info;

typedef struct _dma1_tile_info {
    uint8_t    tile_bpp;
    uint32_t   tile_width;
    uint32_t   tile_height;
    uint8_t    *src_addr0;
    uint32_t   src_addr1;
    uint32_t   src_addr2;
    uint32_t   src_addr3;
    uint32_t   src_basewidth;
    uint8_t    *dst_addr0;
    uint32_t   dst_basewidth;
} dma1_tile_info;

typedef struct _dma2_tile_info {
    uint8_t     tile_bpp;
    uint32_t    tile_width;
    uint32_t    tile_height;
    uint32_t    src_addr0;
    uint32_t    src_basewidth;
    uint32_t    dst_addr0;
    uint32_t    dst_basewidth;
} dma2_tile_info;

typedef struct _dma0_dfc_info {
    uint32_t  dfc_enable; // [13:7] : tenbit mode, [6] : 3-d transfer, [5] : padding, [4] : rotate, [3] : extend, [2] : deintlv, [1] : saturate, [0] : skip alpha

    uint8_t   rot_mode;
    uint8_t   padding_mode;
    uint8_t   padding_left;
    uint8_t   padding_right;
    uint8_t   padding_top;
    uint8_t   padding_bottom;
    uint32_t  padding_data;
    uint8_t   skip_mode;
    uint8_t   sat_mode;
    uint8_t   deintlv_mode;
    uint8_t   ext_mode;
} dma0_dfc_info;

typedef struct _dma1_dfc_info {
    uint32_t  dfc_enable; //[11:5] : tenbit mode, [4] : rotate, [3] : extend, [2] : skip alpha, [1] : intlv , [0] : saturate,

    uint8_t   skip_mode;
    uint8_t   sat_mode;
    uint8_t   intlv_mode;
    uint8_t   ext_mode;
    uint8_t   rot_mode;
} dma1_dfc_info;

typedef struct _dma3_dfc_info {
    uint32_t  dfc_enable; // [2] : rotate, [1] : intlv, [0] : padding
    uint8_t   padding_mode;
    uint8_t   padding_left;
    uint8_t   padding_right;
    uint8_t   padding_top;
    uint8_t   padding_bottom;
    uint32_t  padding_data;
    uint8_t   rot_mode;
    uint8_t   intlv_mode;
} dma3_dfc_info;

#endif

// Mode
struct DFC_MODE
{
    uint32_t pp_mode;
    uint32_t pp_data;
    uint32_t skip_mode;
    uint32_t sat_mode;
    uint32_t int_mode;
    uint32_t dei_mode;
    uint32_t ext_mode;
    uint32_t rot_mode;
    uint32_t sg_mode;
};

#if SCORE_AP_VERSION == 3
  #define DMA0_SAMSUNG10_2_UV     8192
  #define DMA0_SAMSUNG10_8_UV     4096
  #define DMA0_SAMSUNG10_2_Y      2048
  #define DMA0_SAMSUNG10_8_Y      1024
  #define DMA0_P010_UV            512
  #define DMA0_P010_Y             256
  #define DMA0_PACKED12           128
  #define DMA0_3DTRANS_ENABLE     64
  #define DMA0_PADDING_ENABLE     32
  #define DMA0_ROT_ENABLE         16
  #define DMA0_EXT_ENABLE         8
  #define DMA0_DEINTLV_ENABLE     4
  #define DMA0_SAT_ENABLE         2
  #define DMA0_SKIP_ENABLE        1

  #define DMA1_SAMSUNG10_2_UV     2048
  #define DMA1_SAMSUNG10_8_UV     1024
  #define DMA1_SAMSUNG10_2_Y      512
  #define DMA1_SAMSUNG10_8_Y      256
  #define DMA1_P010_UV            128
  #define DMA1_P010_Y             64
  #define DMA1_PACKED12           32
  #define DMA1_ROT_ENABLE         16
  #define DMA1_EXT_ENABLE         8
  #define DMA1_SKIP_ENABLE        4
  #define DMA1_INTLV_ENABLE       2
  #define DMA1_SAT_ENABLE         1

  #define DMA3_ROT_ENABLE         4
  #define DMA3_INTLV_ENABLE       2
  #define DMA3_PADDING_ENABLE     1
#endif

//Pixel padding mode (pp_mode) 2bit
//[3:0]    leftEdge width
//[7:4]    rightEdge width
//[11:8]   top height
//[15:12]  bottom height
//[17:16] pixel padding mode bit

#define PP_replicate    0  //0b00
#define PP_set          1  //0b01
#define PP_mirror       2  //0b10
#define PP_mirror_101   3  //0b11

//AP2
//Convolution mode (conv_mode) 7bit
//[1:0] window size 0 -> size:3 , 1 -> size:5, 2 -> size:7
//[2]   sign bit 0 -> unsinged, 1 -> signed
//[4:3] 0 -> full result data, 1 -> low result data, 2 -> high result data

//AP3
//Convolution mode (conv_mode) 7bit
//[1:0] pixel byte = BPP
//[3:2] window size 0 -> size:3 , 1 -> size:5, 2 -> size:7
//[4]   sign bit 0 -> unsinged, 1 -> signed
//[6:5] 0 -> full result data, 1 -> low result data, 2 -> high result data
//[7] header enable ( DMA simulation c code doesn't consider about this value )

//Skip-Alpha mode (skip_mode) 1bit
#define TRF_SKIP_ALPHA0 0
#define TRF_SKIP_ALPHA3 1

//Saturate mode (sat_mode) 5bit
#define SAT_U16U8       1   //0b00001
#define SAT_U32U16      2   //0b00010
#define SAT_U32U8       3   //0b00011    //ap2
#define DUMMY_4         4
#define SAT_U16S8       5   //0b00101    //ap2
#define SAT_U32S16      6   //0b00110    //ap2
#define SAT_U32S8       7   //0b00111    //ap2
#define DUMMY_8         8
#define SAT_S16U8       9   //0b01001
#define SAT_S32U16      10  //0b01010
#define SAT_S32U8       11  //0b01011    //ap2
#define DUMMY_12        12
#define SAT_S16S8       13  //0b01101    //ap2
#define SAT_S32S16      14  //0b01110
#define SAT_S32S8       15  //0b01111    //ap2
#define DUMMY_16        16
#define TRUNC_16_8      17  //0b10001
#define TRUNC_32_16     18  //0b10010
#define TRUNC_32_8      19  //0b10011    //ap2
#define DUMMY_20        20
#define AVG_16_8        21  //0b10101
#define AVG_32_16       22  //0b10110
#define AVG_32_8        23  //0b10111    //ap2

//Interleaved mode (int_mode) 2bit
#define INT_2ch         1   //'b0001
#define INT_3ch         2   //'b0010
#define INT_4ch         4   //'b0100
#if SCORE_AP_VERSION == 3 //AP3
  #define INT_2ch_2byte   9   //'b1001
  #define INT_3ch_2byte   10  //'b1010
  #define INT_4ch_2byte   12  //'b1100
#endif

//De-interleaved mode (dei_mode) 5bit
#define DEI_3ch_sel0    1  //0b00001
#define DEI_3ch_sel1    2  //0b00010
#define DEI_3ch_skip2   3  //0b00011
#define DEI_3ch_sel2    4  //0b00100
#define DEI_3ch_skip1   5  //0b00101
#define DEI_3ch_skip0   6  //0b00110
#define DEI_3ch         7  //0b00111
#define DUMMY_8         8
#define DEI_YUYV        9  //0b01001
#define DEI_UYVY        10 //0b01010
#define DUMMY_11        11
#define DEI_2ch         12 //0b01100
#define DUMMY_13        13
#define DUMMY_14        14
#define DUMMY_15        15
#define DEI_4ch         16 //0b10000

//Extend mode (ext_mode) 6bit
#define EXT_U8U16      1  //0b00_0001
#define EXT_U16U32     2  //0b00_0010
#define EXT_U8U32      3  //0b00_0011
#define EXT_S8S16      5  //0b00_0101
#define EXT_S16S32     6  //0b00_0110
#define EXT_S8S32      7  //0b00_0111
#define EXT_S8U16      9  //0b00_1001  //ap2
#define EXT_S16U32     10 //0b00_1010  //ap2
#define EXT_S8U32      11 //0b00_1011  //ap2
#define DUP_8          13 //0b00_1101
#define DUP_16         14 //0b00_1110
#if SCORE_AP_VERSION == 2 //AP2
  #define DUP_2D_8       45 //0b10_1101
  #define DUP_2D_16      46 //0b10_1110
#endif

//Rotate
#define ROT_NO          0
#define ROT_FLIP_V      1
#define ROT_FLIP_H      2
#define ROT_180         3
///XXX Before reordering these value, must check TILE swap conditions.
#define ROT_TRANSPOSE0  4
#if SCORE_AP_VERSION == 2 //AP2
  #define ROT_270         5
  #define ROT_90          6
#else //AP3
  #define ROT_90          5
  #define ROT_270         6
#endif
#define ROT_TRANSPOSE1  7

// 10bit format
#define SM_RAW10_UNPACKED16   0
#define SM_RAW10_PACKED12     1
#define SM_P010_Y             2
#define SM_P010_UV            3
#define SM_SAMSUNG10_8_Y      4
#define SM_SAMSUNG10_2_Y      5
#define SM_SAMSUNG10_8_UV     6
#define SM_SAMSUNG10_2_UV     7

#define GET_TENBIT_MODE(X)    (0x80000000ul >> (32 - (X)))
#define RAW10_UNPACKED16      (0x80000000ul >> (32-SM_RAW10_UNPACKED16))  // 0
#define RAW10_PACKED12        (0x80000000ul >> (32-SM_RAW10_PACKED12))    // 1
#define P010_Y                (0x80000000ul >> (32-SM_P010_Y))            // 2
#define P010_UV               (0x80000000ul >> (32-SM_P010_UV))           // 4
#define SAMSUNG10_8_Y         (0x80000000ul >> (32-SM_SAMSUNG10_8_Y))     // 8
#define SAMSUNG10_2_Y         (0x80000000ul >> (32-SM_SAMSUNG10_2_Y))     // 16
#define SAMSUNG10_8_UV        (0x80000000ul >> (32-SM_SAMSUNG10_8_UV))    // 32
#define SAMSUNG10_2_UV        (0x80000000ul >> (32-SM_SAMSUNG10_2_UV))    // 64

#endif
