//------------------------------------------------------------------------------
/// @file  sc_buf_type.h
/// @ingroup  include
///
/// @brief  Defines of structures related with data buffer
/// @internal
/// @author  Rakie Kim<rakie.kim@samsung.com>
///
/// @section changelog Change Log
/// 2016/04/12 Rakie Kim created
///
/// @section copyright_section Copyright
/// &copy; 2016, Samsung Electronics Co., Ltd.
///
/// @section license_section License
///
//------------------------------------------------------------------------------

#ifndef SCORE_COMMON_INCLUDE_SC_BUF_TYPE_H_
#define SCORE_COMMON_INCLUDE_SC_BUF_TYPE_H_

#include "sc_global.h"
#include "sc_printf.h"

#define SCV_BASE_PIXEL_SIZE 8

#define SUM_OF_PLANE(TYPE) (TYPE.plane0 + TYPE.plane1 + TYPE.plane2 + \
  TYPE.plane3)

#define TYPE_SZ(TYPE) ((SUM_OF_PLANE(TYPE) >> 3) + \
  ((SUM_OF_PLANE(TYPE) & 7) ? 1 : 0))

#define INIT_BUF_TYPE(T) {T.sc_type, T.plane0, T.plane1, T.plane2, T.plane3}

#define CUBE_TILE_W 1
#define CUBE_TILE_H 2
#define CUBE_TILE_D 4

/// @brief  Bits per color component
/// @param  [in] C0 Bytes of the first color component. 8 bits (0~32)
/// @param  [in] C1 Bytes of the second color component. 8 bits (0~32)
/// @param  [in] C2 Bytes of the third color component. 8 bits (0~32)
/// @param  [in] C3 Bytes of the fourth color component. 8 bits (0~32)
/// @return         Encoded 32 bit information MSB[C3:C2:C1:C0]LSB
///
/// @note
///   BPP Example)
///   RGBA 8888 BPCC(8,8,8,8)
///   R 8bit    BPCC(8,0,0,0)
///   R 32bit   BPCC(32,0,0,0)
///   Bayer 565 BPCC(5,6,5,0)
#define BPCC(C0,C1,C2,C3) \
  ((((C0)&0x3F))|(((C1)&0x3F)<<8)|(((C2)&0x3F)<<16)|(((C3)&0x3F)<<24))

/// @brief  Get the bits of a color component
/// @param  [in] X bpcc value
/// @param  [in] N n-th color component. 0 is the first component.
/// @return Number of bits of a color component
#define CCBITS(X, N) (((X)>>((N)<<3))&0x3F)

/// @brief  Get the size of a pixel in byte
/// @param  [in] X bpcc value
/// @return Size of a pixel in byte
#define PIXEL_SIZE(X) (((CCBITS(X,0)+0x7)>>3)+((CCBITS(X,1)+0x7)>>3) \
                      +((CCBITS(X,2)+0x7)>>3)+((CCBITS(X,3)+0x7)>>3))

/// @brief  Get the maximal bits among color components
/// @param  [in] X bpcc value
/// @return Maximal bits among color components
#define MAXCCBITS(X) \
  ((CCBITS(X,0) > CCBITS(X,1)) ? \
   (CCBITS(X,2) > CCBITS(X,3) ? \
    (CCBITS(X,0) > CCBITS(X,2) ? CCBITS(X,0) : CCBITS(X,2)) \
    : (CCBITS(X,0) > CCBITS(X,3) ? CCBITS(X,0) : CCBITS(X,3))) \
   : (CCBITS(X,2) > CCBITS(X,3) ? \
     (CCBITS(X,1) > CCBITS(X,2) ? CCBITS(X,1) : CCBITS(X,2)) \
     : (CCBITS(X,1) > CCBITS(X,3) ? CCBITS(X,1) : CCBITS(X,3))))

/// @brief  structure of plane-type for buffer
typedef struct _sc_image_format {
  uint32_t sc_type     : 8; ///< index of type
  uint32_t plane0      : 6; ///< pixel bit of plain0
  uint32_t plane1      : 6; ///< pixel bit of plain1
  uint32_t plane2      : 6; ///< pixel bit of plain2
  uint32_t plane3      : 6; ///< pixel bit of plain3

#ifdef __cplusplus
  bool operator==(const _sc_image_format &cmp) const {
    return sc_type == cmp.sc_type;
  }
  bool operator!=(const _sc_image_format &cmp) const {
    return sc_type != cmp.sc_type;
  }
#endif
} sc_image_format;

/// @brief  Type of memory
typedef enum _sc_memory_type {
  WRONG_MEMORY_TYPE = 0,
  USERPTR_MEMORY = 1,
  DMABUF_MEMORY,
} sc_memory_type;

/// @brief  Image buffer handler
///
/// This data structure handles any image buffer in SCore.
typedef struct _sc_buffer {
  uint32_t width;        ///< Width of image (in pixel)
  uint32_t height;       ///< Height of image (in pixel)
  sc_image_format type;  ///< Memory and data type
  uint32_t addr;         ///< Address of the start of image data
} sc_buffer;

/// @brief  Information of Region of Interest(ROI) for Image Buffer
typedef struct _sc_roi {
  uint32_t policy;        ///< Policy of ROI border
  uint32_t start_x;       ///< Start x-offset of ROI
  uint32_t start_y;       ///< Start y-offset of ROI
  uint32_t roi_width;     ///< Width of ROI
  uint32_t roi_height;    ///< Height of ROI
} sc_roi;

/// @brief  Calculate BPCC (bits per color component)
/// @param  data  data information used in SCore
/// @retval BPCC value
inline uint32_t calculate_bpcc_from_buffer(const sc_buffer *info)
{
  sc_image_format type = info->type;
  return BPCC(type.plane0, type.plane1, type.plane2, type.plane3);
}

/// @brief  Calculate pixel size in byte from sc_buffer structure
/// @param  info  data information object
/// @retval Pixel size in byte
inline uint32_t calculate_pixel_from_buffer(const sc_buffer *info)
{
  uint32_t bpcc = calculate_bpcc_from_buffer(info);
  return PIXEL_SIZE(bpcc);
}

inline bool check_dimensions_of_buffer(const sc_buffer *buf){
  size_t size = buf->height * buf->width;
  if(buf->height == 0 || buf->width == 0 ||
     size < buf->height ||
     size < buf->width) {
    sc_log_error("buf size zero or caused int overflow\n");
    return true;
  }
  uint32_t pixel_size = calculate_pixel_from_buffer(buf);
  if (pixel_size != 0 && size * pixel_size >= size &&
     size * pixel_size >= pixel_size){
    return false;
  } else {
    sc_log_error("pixel size zero or caused int overflow %u : %u\n",
          pixel_size,(unsigned int)size);
    return true;
  }
}

inline bool check_dimensions_of_roi(const sc_buffer *buf,
                                       uint32_t roi_width,
                                       uint32_t roi_height,
                                       uint32_t start_x,
                                       uint32_t start_y){


  if (roi_width == 0 || roi_height == 0 ||
      buf->width < start_x ||
      buf->width - start_x < roi_width ||
      buf->height < start_y ||
      buf->height - start_y < roi_height) {
    sc_log_error("dimensions of roi are wrong\n");
    return true;
  }
  return false;
}

/// @brief  macro expands to a table which allows to get buffer structs by index
/// @ingroup common
#define DECLARE_IMAGE_FORMAT(IDX, IMG_FORMAT_NAME, PLANE0, PLANE1, PLANE2, PLANE3)\
IMG_FORMAT_NAME ## _TYPE,

enum formatsEnums {
  #include "buf_types.incl"
};

#undef DECLARE_IMAGE_FORMAT

/// @brief macro expands to structs holding info about buffer_types. Structs can be accesed by IMG_FORMAT_NAME
/// @ingroup common
#define DECLARE_IMAGE_FORMAT(IDX, IMG_FORMAT_NAME, PLANE0, PLANE1, PLANE2, PLANE3) \
static const sc_image_format IMG_FORMAT_NAME = {IDX, PLANE0, PLANE1, PLANE2, PLANE3};

#include "buf_types.incl"
#undef DECLARE_IMAGE_FORMAT

#endif
