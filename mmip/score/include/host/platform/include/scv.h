//------------------------------------------------------------------------------
/// @file  scv.h
/// @ingroup  include
///
/// @brief  Declarations of SCore kernel from host
/// @internal
/// @author  Rakie Kim<rakie.kim@samsung.com>
///
/// @section changelog Change Log
/// 2016/03/02 Snaghwan Park created
/// 2017/08/16 Rakie Kim modified
///
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SCV_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SCV_H_

#include "sc_platform_global.h"

#include "sc_kernel_name.h"
#include "sc_buffer.h"
#include "sc_context.h"
#include "sc_scalar.h"

namespace score {

/// @ingroup SCV_kernels
/// @brief Computes the per-element bit-wise 'NOT' operation
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in input buffer(SC_TYPE_U8)
/// @param [out] out output buffer(SC_TYPE_U8)
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t Not(ScContext *ctx,
                ScBuffer *in,
                ScBuffer *out);

/// @ingroup SCV_kernels
/// @brief  Splits a four-channel array into four independent single-channel arrays.
///
/// <pre>
/// out1(i,j) = in(4*i,j)
/// out2(i,j) = in(4*i+1,j)
/// out3(i,j) = in(4*i+2,j)
/// out4(i,j) = in(4*i+3,j)
/// </pre>
///
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in input buffer(RGBA, SC_TYPE_U8)
/// @param [out] out1 output buffer(SC_TYPE_U8)
/// @param [out] out2 output buffer(SC_TYPE_U8)
/// @param [out] out3 output buffer(SC_TYPE_U8)
/// @param [out] out4 output buffer(SC_TYPE_U8)
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t ChannelExtract_4CH(ScContext *ctx,
                               ScBuffer *in,
                               ScBuffer *out1,
                               ScBuffer *out2,
                               ScBuffer *out3,
                               ScBuffer *out4);

/// @ingroup  SCV_kernels
/// @brief  Merges four independent single-channel arrays into a four-channel array
///
/// <pre>
/// out(4*i,j)   = in1(i,j)
/// out(4*i+1,j) = in2(i,j)
/// out(4*i+2,j) = in3(i,j)
/// out(4*i+3,j) = in4(i,j)
/// </pre>
///
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in1 input buffer(SC_TYPE_U8)
/// @param [in] in2 input buffer(SC_TYPE_U8)
/// @param [in] in3 input buffer(SC_TYPE_U8)
/// @param [in] in4 input buffer(SC_TYPE_U8)
/// @param [out] out output buffer(RGBA, SC_TYPE_U8)
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t ChannelCombine_4CH(ScContext *ctx,
                               ScBuffer *in1,
                               ScBuffer *in2,
                               ScBuffer *in3,
                               ScBuffer *in4,
                               ScBuffer *out);

/// @ingroup  SCV_kernels
/// @brief  Calculates an average value of entire pixels of an image
///
/// \f$out = \frac{\sum_{}^{}in(i,j)}{width*height}\f$
/// out buffer size in only 1x1.
///
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in input buffer(SC_TYPE_U8)
/// @param [out] out output buffer(SC_TYPE_F32)
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t Average(ScContext *ctx,
                    ScBuffer *in,
                    ScBuffer *out);

/// @ingroup SCV_kernels
/// @brief Blurs an image using the box filter
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in input buffer(SC_TYPE_U8)
/// @param [out] out output buffer(SC_TYPE_U8)
/// @param [in] kernel_size Box filter size(3 or 5)
/// @param [in] policy padding mode (DFC_PP_REPLICATE, DFC_PP_SET, DFC_PP_MIRROR, DFC_PP_MIRROR_101)
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t Box(ScContext *ctx,
                ScBuffer *in,
                ScBuffer *out,
                int32_t kernel_size,
                uint32_t policy);

/// @ingroup SCV_kernels
/// @brief Blurs an image using the gaussian filter
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in input buffer(SC_TYPE_U8)
/// @param [out] out output buffer(SC_TYPE_U8)
/// @param [in] kernel_size Gaussiang filter size(3 or 5)
/// @param [in] policy padding mode (DFC_PP_REPLICATE, DFC_PP_SET, DFC_PP_MIRROR, DFC_PP_MIRROR_101)
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t Gaussian(ScContext *ctx,
                     ScBuffer *in,
                     ScBuffer *out,
                     uint32_t kernel_size,
                     uint32_t policy);

/// @brief Computes the per-element addition between weighted in and out images
///         \f$inout[i] = (1-scale)*inout[i] + scale*in[i]\f$
/// @ingroup SCV_kernels
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in input buffer(SC_TYPE_U8)
/// @param [inout] out input and output buffer(SC_TYPE_U8)
/// @param [in] scale scale value
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t AccumulateWeightedImage(ScContext *ctx,
                                    ScBuffer *in,
                                    ScBuffer *out,
                                    float scale);

/// @ingroup  SCV_kernels
/// @brief  Generates a histogram from the image which counts the number of
/// each pixel value
/// @param  [in] ctx context info to execute SCore kernel
/// @param  [in] in Input image (SC_TYPE_U8)
/// @param  [out] out Output histogram data (width:256 / height:1 / type:SC_TYPE_U32)
/// @return STS_SUCCESS If function succeeds, otherwise error.
SC_PUBLIC_API
sc_status_t Histogram(ScContext *ctx,
                      ScBuffer *in,
                      ScBuffer *out);

/// @ingroup  SCV_kernels
/// @brief  Computes the per-element bit-wise 'NOT' operation
///  using CTI which sets irregular tile iteration pattern
/// @param [in,out] ctx           context information
/// @param [in]     in            input buffer(SC_TYPE_U8)
/// @param [out]    out           output buffer(SC_TYPE_U8)
/// @param [in]     is_ko         flag for knight only
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t BasicCTI(ScContext *ctx,
                     ScBuffer *in,
                     ScBuffer *out,
                     uint8_t is_ko);

/// @ingroup SCV_kernels
/// @brief  Calculates matrix multiplication using two input buffers
///  tile size and pivot mode are set by user
/// @param [in] ctx       context info to execute SCore kernel
/// @param [in] in1       input buffer(SC_TYPE_U8)
/// @param [in] in2       input buffer(SC_TYPE_U8)
/// @param [out] out      output buffer(SC_TYPE_U8)
/// @param [in] tile_cols number of cols selected to process in a tile
/// @param [in] tile_rows number of rows selected to process in a tile
/// @param [in] mode      select modes, 1 = ROW, 2 = COL
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t MatMul(ScContext *ctx,
                   ScBuffer *in1,
                   ScBuffer *in2,
                   ScBuffer *out,
                   uint32_t tile_cols,
                   uint32_t tile_rows,
                   uint32_t mode);

/// @ingroup SCV_kernels
/// @brief Performs bilinear interpolation image scale
/// @param [in] ctx context info to execute SCore kernel
/// @param [in] in input buffer(SC_TYPE_U8)
/// @param [out] out output buffer(SC_TYPE_U8)
/// @return STS_SUCCESS if function succeeds, otherwise error
SC_PUBLIC_API
sc_status_t Bilinear(ScContext *ctx,
                     ScBuffer *in,
                     ScBuffer *out);


sc_status_t Test_VIF(ScContext *ctx, ScBuffer* in1, ScBuffer* in2, ScBuffer* out);

} /// namespace score
#endif
