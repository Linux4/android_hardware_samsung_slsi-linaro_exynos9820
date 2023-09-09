//------------------------------------------------------------------------------
/// @file  sc_buffer.h
/// @ingroup  include
///
/// @brief  Declarations of ScBuffer class
///
/// ScBuffer class includes functions making image buffer for SCore kernel
/// @internal
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

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_BUFFER_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_BUFFER_H_

#include "sc_platform_global.h"

#include "sc_buf_type.h"
#include "sc_dma.h"
#include "sc_pimpl_base.h"
#include "sc_control.h"

namespace score {

class ScBufferPrivate;

/// @brief  Class for Buffer to execute SCore kernel
/// @ingroup SCore_Host_Public_API
class SC_PUBLIC_API ScBuffer : public ScPimplBase {
 public:
  /// @brief  This constructor should be used only for temporary placeholder
  explicit ScBuffer();

#if __cplusplus > 199711L
  /// @brief  Move constructor
  ScBuffer(ScBuffer &&src) = default;
  /// @brief  Move assignment
  ScBuffer& operator=(ScBuffer &&src) = default;
#endif

  /// @brief  Constructor of ScBuffer class
  ///
  /// This allocates memory for buffer.
  /// @brief  Create ScBuffer
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] src0~3  Pointer to sc_buffer to be processed depending on type
  ///
  /// @note This function allocates memory for ScBuffer and memory for addr parameter
  /// included in ScBuffer. Size of addr parameter depends on type. When creating
  /// ScBuffer as input data, you must put data to src0~3 depending on type.
  /// Value put to src0~3 is pointer to sc_buffer processed in SCore. When creating
  /// ScBuffer as output data, you don't have to put anything. Information about
  /// type is referred to in sc_buf_type.h. This function creates cache-memory.
  /// For non-cache memory, use the other constructor.\n
  /// Example,\n
  /// \b Case \b 1: input data that type is RGB\n
  /// ScBuffer *in = new score::ScBuffer(10, 10, SC_RGB, data);\n
  /// \b Case \b 2: input data that type is YUYV\n
  /// ScBuffer *in = new score::ScBuffer(20, 20, SC_YUYV, data1, data2, data3);\n
  /// \b Case \b 3: output data that type is HSV\n
  /// ScBuffer *out = new score:ScBuffer(30, 30, SC_HSV);\n
  explicit ScBuffer(uint32_t width,
                    uint32_t height,
                    sc_image_format type,
                    void *src0 = SC_NULLPTR,
                    void *src1 = SC_NULLPTR,
                    void *src2 = SC_NULLPTR,
                    void *src3 = SC_NULLPTR);

  /// @brief  Create ScBuffer
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] set_cache determine to set a buffer to cache or non-cache
  /// @param [in] src0~3  Pointer to sc_buffer to be processed depending on type
  ///
  /// @note You can create a cache memory buffer and a non-cache memory buffer.\n
  /// Example,\n
  /// \b Case \b 1: input data that type is RGB\n
  /// ScBuffer *in = new score::ScBuffer(10, 10, SC_RGB, true, data);\n
  /// \b Case \b 2: input data that type is YUYV\n
  /// ScBuffer *in = new score::ScBuffer(20, 20, SC_YUYV, false, data1, data2, data3);\n
  /// \b Case \b 3: output data that type is HSV\n
  /// ScBuffer *out = new score:ScBuffer(30, 30, SC_HSV, false);\n
  explicit ScBuffer(uint32_t width,
                    uint32_t height,
                    sc_image_format type,
                    bool set_cache,
                    void *src0 = SC_NULLPTR,
                    void *src1 = SC_NULLPTR,
                    void *src2 = SC_NULLPTR,
                    void *src3 = SC_NULLPTR);

  /// @brief  Create ScBuffer
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] depth   Depth of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] src0    Pointer to sc_buffer to be processed depending on type
  ///
  /// @note image format type is not supported if depth is greater than 2.
  /// Example,
  /// \b Case \b 1: input data that type is unsigned int
  /// ScBuffer *in = new score::ScBuffer(10, 10, 2, SC_TYPE_U32, data);
  explicit ScBuffer(uint32_t width,
                    uint32_t height,
                    uint32_t depth,
                    sc_image_format type,
                    void *src = SC_NULLPTR);

  /// @brief  Create ScBuffer
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] depth   Depth of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] set_cache determine to set a buffer to cache or non-cache
  /// @param [in] src0    Pointer to sc_buffer to be processed depending on type
  ///
  /// @note image format type is not supported if depth is greater than 2.
  /// @note You can create a cache memory buffer and a non-cache memory buffer.
  /// Example,
  /// \b Case \b 1: input data that type is unsigned int
  /// ScBuffer *in = new score::ScBuffer(10, 10, 2, SC_TYPE_U32, true, data);
  /// \b Case \b 2: output data that type is signed short
  /// ScBuffer *out = new score:ScBuffer(30, 30, 3, SC_TYPE_S16, false, data);
  /// @note You can create a cache memory buffer and a non-cache memory buffer.
  explicit ScBuffer(uint32_t width,
                    uint32_t height,
                    uint32_t depth,
                    sc_image_format type,
                    bool set_cache,
                    void *src = SC_NULLPTR);

  /// @brief  Destructor of ScBuffer class
  ///
  /// This deallocates memory for buffer.
  virtual ~ScBuffer();

  /// @brief  Get witdh of ScBuffer manages area
  /// @return Width of which ScBuffer manages area
  uint32_t getWidth() const;

  /// @brief  Get height of ScBuffer manages area
  /// @return Height of which ScBuffer manages area
  uint32_t getHeight() const;

  /// @brief  Get depth of ScBuffer manages area
  /// @return Depth of which ScBuffer manages area
  uint32_t getDepth() const;

  /// @brief  Get type of ScBuffer manages area
  /// @return Type of which ScBuffer manages area
  sc_image_format getFormat() const;

  /// @brief  Get address of which ScBuffer manages area
  /// @return Address of which ScBuffer manages area
  virtual unsigned long getBufferAddr() const;

  /// @brief  Get address of sc_host_info struct
  /// @return Pointer to addr of host_info
  void *getHostInfo();

  /// @brief Get Memory type of Buffer
  /// @return Memory type among enum of sc_memory_type
  int32_t getHostInfoMemtype() const;

  /// @brief  Get file descriptor of which ScBuffer manages area
  /// @return File descriptor of which ScBuffer manages area
  int32_t getHostInfoHostFd() const;

  /// @brief Get required buffer size
  /// @return Size to be allocated depending on type
  size_t getBufferSize() const;

  /// @brief  Set RoI(Region of interests) of ScBuffer
  /// @param [in] policy policy of RoI
  /// @param [in] start_x horizontal start address of RoI
  /// @param [in] start_y vertical start address of RoI
  /// @param [in] roi_width width of RoI
  /// @param [in] roi_height height of RoI
  void setRoI(enum ROI_BORDER_POLICY policy, uint32_t start_x,
              uint32_t start_y, uint32_t roi_width, uint32_t roi_height);

  /// @brief Get RoI information
  /// @return Struct of RoI information
  sc_roi getRoI() const;

  /// @brief  Get the information whether RoI was set or not
  /// @return true if RoI was set
  bool isSetRoI() const;

  /// @brief  Get the information whether this buffer was initialized or not
  /// @return value to indicate whether class instance was initialized
  ///         or not
  bool isInitialized() const;

  /// @brief Make stream data for packet
  /// @param [in] pkt address of memory where the stream data be stored
  /// @return The number of byte being stored
  uint32_t makeParam(uint8_t *pkt);

  /// @brief Get size of stream data for packet
  /// @return Size of stream data
  uint32_t getParamSize() const ;

  /// @brief  Copy data to addr parameter of ScBuffer when there is input data
  /// @param [in] type       Type of sc_data
  /// @param [in] dest       Pointer to addr of ScBuffer
  /// @param [in] base_size  Width * height of image data
  /// @param [in] src0~3     Pointer to image data to be processed depending on type
  static void copyToBuffer(sc_image_format type, int8_t *dest, size_t base_size,
                           void *src0 = SC_NULLPTR, void *src1 = SC_NULLPTR,
                           void *src2 = SC_NULLPTR, void *src3 = SC_NULLPTR);

  /// @brief Calculate pixel size depending on type
  /// @param [in] type  Type of sc_buffer
  /// @return Size to be allocated depending on type
  static float calcPixelSize(sc_image_format type);

  /// @brief Calculate pixel size in bits depending on type
  /// @param [in] type  Type of sc_buffer
  /// @return Size to be allocated depending on type
  static size_t calcPixelSizeInBits(sc_image_format type);

  /// @brief Calculate buffer size depending on width, height and type
  /// @param [in] w Width of sc_buffer
  /// @param [in] h Height of sc_buffer
  /// @param [in] t Type of sc_buffer
  /// @return Size of sc_buffer
  static size_t calcBufferSize(uint32_t w, uint32_t h, sc_image_format t);

  /// @brief Calculate buffer size depending on width, height and type
  /// @param [in] w Width of sc_buffer
  /// @param [in] h Height of sc_buffer
  /// @param [in] d Depth of sc_buffer
  /// @param [in] t Type of sc_buffer
  /// @return Size of sc_buffer
  static size_t calcBufferSize(uint32_t w, uint32_t h, uint32_t d, sc_image_format t);

 protected:
  ScBuffer(ScBufferPrivate &d);

 private:
  SC_DECLARE_PRIVATE(ScBuffer)
};

class ScBindBufferPrivate;

/// @brief  Class to bind ion memory allocated by the other process
/// @ingroup SCore_Host_Public_API
/// @note ScBindBuffer does not allocate memory, but adds only buffer information
/// to the memory it receives from the outside.
class SC_PUBLIC_API ScBindBuffer : public ScBuffer {
 public:
  /// @brief  This constructor should be used only for temporary placeholder
  explicit ScBindBuffer();

  /// @brief Constructor of ScBindBuffer class
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] fd      Allocated ion fd
  /// @param [in] map     Command to decide whether to map
  explicit ScBindBuffer(uint32_t width,
                        uint32_t height,
                        sc_image_format type,
                        int32_t fd,
                        bool map = false);

  /// @brief Constructor of ScBindBuffer class
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] depth   Depth of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] fd      Allocated ion fd
  /// @param [in] map     Command to decide whether to map
  explicit ScBindBuffer(uint32_t width,
                        uint32_t height,
                        uint32_t depth,
                        sc_image_format type,
                        int32_t fd,
                        bool map = false);

  /// @brief Constructor of ScBindBuffer class
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] fd      Allocated ion fd
  /// @param [in] offset  Offset to change memory base address
  /// @param [in] map     Command to decide whether to map
  explicit ScBindBuffer(uint32_t width,
                        uint32_t height,
                        sc_image_format type,
                        int32_t fd,
                        unsigned long offset,
                        bool map = false);

  /// @brief Constructor of ScBindBuffer class
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] depth   Depth of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] fd      Allocated ion fd
  /// @param [in] offset  Offset to change memory base address
  /// @param [in] map     Command to decide whether to map
  explicit ScBindBuffer(uint32_t width,
                        uint32_t height,
                        uint32_t depth,
                        sc_image_format type,
                        int32_t fd,
                        unsigned long offset,
                        bool map = false);

  /// @brief Constructor of ScBindBuffer class
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] addr    Allocated memory address
  ///
  /// @note Only the memory allocated through ion can be used
  explicit ScBindBuffer(uint32_t width,
                        uint32_t height,
                        sc_image_format type,
                        unsigned long addr);

  /// @brief Constructor of ScBindBuffer class
  /// @param [in] width   Width of sc_buffer
  /// @param [in] height  Height of sc_buffer
  /// @param [in] depth   Depth of sc_buffer
  /// @param [in] type    Type of sc_buffer
  /// @param [in] addr    Allocated memory address
  ///
  /// @note Only the memory allocated through ion can be used
  explicit ScBindBuffer(uint32_t width,
                        uint32_t height,
                        uint32_t depth,
                        sc_image_format type,
                        unsigned long addr);

#if __cplusplus > 199711L
  /// @brief  Move constructor
  ScBindBuffer(ScBindBuffer &&src) = default;
  /// @brief  Move assignment
  ScBindBuffer& operator=(ScBindBuffer &&src) = default;
#endif

  /// @brief  Destructor of ScBindBuffer class
  ///
  /// This unmaps memory for buffer.
  virtual ~ScBindBuffer();

  /// @brief  Map user virtual address by ion memory file descriptor(fd)
  /// @return 0 if mapped, otherwise nagative number
  int32_t MapBuffer();

  /// @brief  Get the mapped information whether fd of ion was mapped or not
  /// @return Value to indicate whether fd of ion memory was mapped to memory address
  bool isMapped() const;

  /// @brief  Get base memory address
  /// @return Memory address
  /// @note If class was created via Fd, it will return the mapped address if it
  /// was mapped, otherwise 0. If class was created via address, it will return
  /// the address.
  unsigned long getBaseBufferAddr(void) const;

  /// @brief  Get memory offset
  /// @return offset Offset to change base address of buffer accessed by target
  /// @note offset can be only used when class is created via Fd
  unsigned long getOffset(void) const;

  /// @brief  Get address of which ScBindBuffer manages area
  /// @return Memory address
  /// @note It returns the address taking account of base addres and offset.
  /// Return value of getBufferAddr is same with return value of getBaseBufferAddr
  /// if class was created via address.
  virtual unsigned long getBufferAddr() const;

 protected:
  ScBindBuffer(ScBindBufferPrivate &d);

 private:
  SC_DECLARE_PRIVATE(ScBindBuffer)
};

} //namespace score

#endif
