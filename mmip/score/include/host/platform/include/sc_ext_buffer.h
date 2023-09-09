//------------------------------------------------------------------------------
/// @file  sc_ext_buffer.h
/// @ingroup  include
///
/// @brief  Declarations of ScExtBuffer class
///
/// ScExtBuffer class includes functions setting DMA & tile info for SCore kernel
///
/// @author  Kyungmok Kum<km.kum@samsung.com>
///
/// @section changelog Change Log
/// 2017/04/20 Kyungmok Kum created
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_EXT_BUFFER_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_EXT_BUFFER_H_

#include "sc_platform_global.h"

#include "sc_param.h"
#include "sc_buffer.h"
#include "sc_buf_type.h"
#include "sc_dma.h"
#include "sc_control.h"

namespace score {

class ScExtBufferPrivate;

/// @brief  Class for ExtBuffer to set DMA & tile info of the SCore kernel
/// @ingroup SCore_Host_Public_API
class SC_PUBLIC_API ScExtBuffer : public ScParam {
 public:
  /// @brief  This Constructor should be used only for temporary placeholder
  explicit ScExtBuffer();

  /// @brief  Constructor of ScExtBuffer class for onetime tile
  /// @param [in] index Index of DMA info. It should be unique positive number
  explicit ScExtBuffer(uint32_t index);

  /// @brief  Constructor of ScExtBuffer class for once tile
  /// @param [in] index Index of DMA info. It should be unique positive number
  /// @param [in] buf input or output of buffer
  /// @param [in] dir input(DRAM_TO_TCM), output(TCM_TO_DRAM)
  explicit ScExtBuffer(uint32_t index,
                       ScBuffer *buf,
                       enum DIRECTION_OF_DMA dir);

  /// @brief  Constructor of ScExtBuffer class for normal tile
  /// @param [in] index Index of DMA info. It should be unique positive number
  /// @param [in] buf input or output of buffer
  /// @param [in] dir input(DRAM_TO_TCM), output(TCM_TO_DRAM)
  /// @param [in] tile_width tile width in pixels
  /// @param [in] tile_height tile height in pixels
  explicit ScExtBuffer(uint32_t index,
                       ScBuffer *buf,
                       enum DIRECTION_OF_DMA dir,
                       uint32_t tile_width,
                       uint32_t tile_height);

  /// @brief  Constructor of ScExtBuffer class for normal tile
  /// @param [in] index Index of DMA info. It should be unique positive number
  /// @param [in] buf input or output of buffer
  /// @param [in] dir input(DRAM_TO_TCM), output(TCM_TO_DRAM)
  /// @param [in] tile_width tile width in pixels
  /// @param [in] tile_height tile height in pixels
  /// @param [in] tile_depth tile depth in pixels
  explicit ScExtBuffer(uint32_t index,
                       ScBuffer *buf,
                       enum DIRECTION_OF_DMA dir,
                       uint32_t tile_width,
                       uint32_t tile_height,
                       uint32_t tile_depth);

  /// @brief  Destructor of ScBuffer class
  ///
  /// This deallocates memory for buffer.
  virtual ~ScExtBuffer();

  /// @brief    Set data format conversion mode of DMA
  ///
  ///           Default : DFC_NORMAL
  ///
  /// @note     If you want to know about DFC modes,
  ///           please refer to sc_dma.h and AP2 SDK User guide about DFC Mode
  ///
  /// @param [in] mode Data format Conversion mode
  /// @return   STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setDfcMode(uint32_t mode);

  /// @brief  Set neighboring information for processing image border
  ///         and tile neighboring
  /// @note   SCore-AP2 provides four modes :
  ///         DFC_PP_REPLICATE, DFC_PP_SET, DFC_PP_MIRROR, DFC_MIRROR_101
  ///
  /// @param [in] left Left neighboring length in pixel (0 ~ 7)
  /// @param [in] right Right neighboring length  in pixel (0 ~ 7)
  /// @param [in] top Top neighboring length in pixel (0 ~ 7)
  /// @param [in] bottom Bottom neighboring length in pixel (0 ~ 7)
  /// @param [in] nei_value Image border value when use DFC_PP_SET mode
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setNeighbor(uint32_t left,
                          uint32_t right,
                          uint32_t top,
                          uint32_t bottom,
                          uint32_t nei_value = 0);

  /// @brief  Set buffer to be transferred whole data only once
  ///         If the direction of the buffer is DRAM to TCM,
  ///         whole input buffer is transferred from DRAM to the TCM buffer
  ///         before tile iteration begins
  ///         If the direction of the buffer is TCM to DRAM,
  ///         whole output buffer is transferred from TCM to the DRAM buffer
  ///         after tile iteration ends
  ///         This is useful when data should be shared between tiles
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setOnceTile();

  /// @brief  Set TCM stride of the DMA
  /// @param [in] stride TCM stride in pixel
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setTcmStride(uint32_t stride);

  /// @brief  Set DRAM stride of the DMA
  /// @param [in] stride DRAM stride in pixel
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setDramStride(uint32_t stride);

  /// @brief  Set CTI used for internal tile calculation instead of BTI
  /// @param [in] id ID of custom tile address calculation function.
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setCustomTileIteratorID(uint32_t cti_id);

  /// @brief  Change default built-in tile iterator to the setting BTI
  ///         Default build-in tile iterator is automatically selected
  ///         by DFC mode if this is not called
  /// @param [in] mode Data transfer mode set to the DMA
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setTileIterator(uint32_t mode);

  /// @brief  Set one time information to the Buffer
  ///         This has similar funcitionality with setOnceTile except DMA transfer
  ///         This only makes to create shared buffer in TCM
  /// @param [in] size size of one time information
  /// @param [in] is_preserved option for memory to be preserved for the entire tile iteration or not
  /// @param [in] zero_init option for initializing memory to zero
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setOneTime(uint32_t size, bool is_preserved, bool zero_init = true);

  /// @brief  Set a Matrix Multiplication Pivot to the Buffer
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setMatMulPivot();

  /// @brief  Set a difference from current and previous tile in DRAM(pixel)
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  /// @note Tile Location Difference(TileLocDiff) is used for locating the position
  /// of the next tile in the tile iteration. As the location of a tile is
  /// represented by its top-left pixel coordinate, tile_loc_diff is the difference
  /// between two top-left pixel coordinates of a tile and its next tile.
  /// This is useful when a tile is separated from its previous tile with space
  sc_status_t setTileLocDiff(uint32_t x, uint32_t y);

  /// @brief  Set ScatterGather information for transferring several tiles
  ///         which are located at regular intervals.
  /// @note   If you want to skip tiles between interval,
  ///         you should set with setTileLocDiff(image_width, 0)
  /// @param [in] num_of_tiles number of tiles to transferring at once
  /// @param [in] interval regular interval from the previous tile start addr
  ///                      to the next tile start addr
  /// @return STS_SUCCESS if successfully set, otherwise STS_FAILURE
  sc_status_t setScatterGather(uint8_t num_of_tiles, uint32_t interval);

  /// @brief Implementation of pure virtual function ScParam::makeParam
  virtual int32_t makeParam(uint8_t *pkt) const SC_OVERRIDE;

  /// @brief Implementation of pure virtual function ScParam::getParamSize
  virtual int32_t getParamSize() const SC_OVERRIDE;

  /// @brief Implementation of pure virtual function ScParam::isBuffer
  virtual bool isBuffer() const SC_OVERRIDE;

  /// @brief Implementation of pure virtual function ScParam::copyHostInfo
  virtual void copyHostInfo(sc_host_info *host_info) const SC_OVERRIDE;

 protected:
  ScExtBuffer(ScExtBufferPrivate &d);

 private:
  SC_DECLARE_PRIVATE(ScExtBuffer)
};

} //namespace score
#endif
