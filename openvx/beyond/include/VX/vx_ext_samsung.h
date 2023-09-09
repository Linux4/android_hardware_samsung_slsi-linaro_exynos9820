/**
 * Copyright 2016-17 Samsung R&D Institute India - Bangalore (SRIB)
 * Samsung Electronics All Rights Reserved.
 * Samsung Confidential Proprietary.
 *
 */

/*!
 * \file    vx_ext_samsung.h
 * \author  S Sampath Kumar <k.sampath@samsung.com>
 * \date    7-Jan-2016
 *
 * \brief   API interface for custom kernels extended by vendor Samsung
 *
 */

#ifndef _VX_EXT_SAMSUNG_H_
#define _VX_EXT_SAMSUNG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define IVA_RoundUp(value, bytes)       ( ((value) + (bytes-1)) & ~(bytes-1) )

/*! \brief The list of extended libraries by Samsung */
enum vx_library_samsung_e {
	VX_LIBRARY_SS_BASE	= 0x0,	/* generic for ss */
	VX_LIBRARY_IVA		= 0x1,
	VX_LIBRARY_NEON		= 0x2,
	VX_LIBRARY_SCORE	= 0x3,
	VX_LIBRARY_C_MODEL	= 0x4,
	VX_LIBRARY_VDIS 	= 0x5,
};

/*!
 * \brief The list of extension kernels for IVA target.
 *
 * Each kernel listed here can be used with the <tt>\ref vxGetKernelByEnum</tt> call.
 * When programming the parameters, use
 * \arg <tt>\ref VX_INPUT</tt> for [in]
 * \arg <tt>\ref VX_OUTPUT</tt> for [out]
 * \arg <tt>\ref VX_BIDIRECTIONAL</tt> for [in,out]
 *
 * When programming the parameters, use
 * \arg <tt>\ref VX_TYPE_IMAGE</tt> for a <tt>\ref vx_image</tt> in the size field of <tt>\ref vxGetParameterByIndex</tt> or <tt>\ref vxSetParameterByIndex</tt>  * \arg <tt>\ref VX_TYPE_ARRAY</tt> for a <tt>\ref vx_array</tt> in the size field of <tt>\ref vxGetParameterByIndex</tt> or <tt>\ref vxSetParameterByIndex</tt>  * \arg or other appropriate types in \ref vx_type_e.
 * \ingroup group_kernel
 */
enum vx_kernel_iva_ext_e {

	VX_KERNEL_SAMSUNG_IVA_BASE = VX_KERNEL_BASE(VX_ID_SAMSUNG, VX_LIBRARY_IVA),

	/********************** IVA ENTRY ********************/
	/* IVA external kernel must be defined in this range */

	/*! \brief The IVA Local Min Max Kernel
	 *
	 */
	VX_KERNEL_IVA_LOCAL_MIN_MAX = VX_KERNEL_SAMSUNG_IVA_BASE + 0x0,

	/*! \brief The IVA Corner Score Kernel
	 *
	 */
	VX_KERNEL_IVA_CORNER_SCORE = VX_KERNEL_SAMSUNG_IVA_BASE + 0x1,

	/*! \brief The IVA ENF Kernel
	 *
	 */
	VX_KERNEL_IVA_ENF = VX_KERNEL_SAMSUNG_IVA_BASE + 0x2,

	/*! \brief The IVA WIG Kernel
	 *
	 */
	VX_KERNEL_IVA_WIG = VX_KERNEL_SAMSUNG_IVA_BASE + 0x3,

	/*! \brief The IVA LK Tracker Kernel
	 *
	 */
	VX_KERNEL_IVA_LKTRACKER = VX_KERNEL_SAMSUNG_IVA_BASE + 0x4,

	/*! \brief The IVA ORB Kernel
	 *
	 */
	VX_KERNEL_IVA_ORB = VX_KERNEL_SAMSUNG_IVA_BASE + 0x5,

	/*! \brief The IVA SCL Kernel
	 *
	 */
	VX_KERNEL_IVA_SCALER = VX_KERNEL_SAMSUNG_IVA_BASE + 0x6,

	/*! \brief The IVA ENFP Kernel
	 *
	 */
	VX_KERNEL_IVA_ENFP = VX_KERNEL_SAMSUNG_IVA_BASE + 0x7,

	/*! \brief The IVA MCH Kernel
	 *
	 */
	VX_KERNEL_IVA_MCH = VX_KERNEL_SAMSUNG_IVA_BASE + 0x8,

	/*! \brief The IVA Gaussian 5x5 Kernel
	 *
	 */
	VX_KERNEL_IVA_GAUSSIAN_5x5 = VX_KERNEL_SAMSUNG_IVA_BASE + 0x9,

	/*! \brief The IVA Optical flow pyramid lk kernel
	 *
	 */
	VX_KERNEL_IVA_OPTFLOW_PYR_LK = VX_KERNEL_SAMSUNG_IVA_BASE + 0xA,

	/*! \brief The IVA Remap PreProcess Kernel
	 *
	 */
	VX_KERNEL_IVA_REMAP_PRE_PROCESS = VX_KERNEL_SAMSUNG_IVA_BASE + 0xB,

	/*! \brief The IVA WIG PreProcess Kernel
	 *
	 */
	VX_KERNEL_IVA_WIG_PRE_PROCESS = VX_KERNEL_SAMSUNG_IVA_BASE + 0xC,

	/*! \brief The Iva UV SCALER Kernal.
	 *
	 */
	VX_KERNEL_IVA_UV_SCALER = VX_KERNEL_SAMSUNG_IVA_BASE + 0xD,

	/*! \brief The Iva UV ENF Kernal.
	 *
	 */
	VX_KERNEL_IVA_UV_ENF = VX_KERNEL_SAMSUNG_IVA_BASE + 0xE,

	/*! \brief The Iva FAST ORB Kernal.
	 *
	 */
	VX_KERNEL_IVA_FAST_ORB = VX_KERNEL_SAMSUNG_IVA_BASE + 0xF,

	/* insert new kernels here */
	/*! \brief The IVA Remap PreProcess Kernel
	 *
	 */
	VX_KERNEL_IVA_REMAP_POST_PROCESS = VX_KERNEL_SAMSUNG_IVA_BASE + 0x10,

	/*! \brief The Iva Optical Flow Pre processing Kernel.
	 *
	 */
	VX_KERNEL_IVA_HELPERS_OPTFLOWPYRLK_PRE_PROCESS = VX_KERNEL_SAMSUNG_IVA_BASE + 0x11,

	/*! \brief The Iva Optical Flow Inter level Kernel.
	 *
	 */
	VX_KERNEL_IVA_HELPERS_OPTFLOWPYRLK_INTER_LEVEL = VX_KERNEL_SAMSUNG_IVA_BASE + 0x12,

	/*! \brief The Iva Optical Flow Post processing Kernel.
	 *
	 */
	VX_KERNEL_IVA_HELPERS_OPTFLOWPYRLK_POST_PROCESS = VX_KERNEL_SAMSUNG_IVA_BASE + 0x13,

	/*! \brief The Iva WSB Computation Kernel.
	*
	*/
	VX_KERNEL_IVA_HELPERS_WSB_COMPUTATION = VX_KERNEL_SAMSUNG_IVA_BASE + 0x14,

	/*! \brief The Iva WARP STREAM Kernal.
	*
	*/
	VX_KERNEL_IVA_WARP_STREAM_BLEND = VX_KERNEL_SAMSUNG_IVA_BASE + 0x15,

	/*! \brief The Iva WIG MESH Compute kernel.
	*
	*/
	VX_KERNEL_IVA_HELPERS_WIG_MESH_COMPUTE = VX_KERNEL_SAMSUNG_IVA_BASE + 0x16,

	/*! \brief The Iva WIG MESH Kernel.
	*
	*/
	VX_KERNEL_IVA_WIG_MESH = VX_KERNEL_SAMSUNG_IVA_BASE + 0x17,

	/*! \brief The Iva MFB Kernel.
	*
	*/
	VX_KERNEL_IVA_MFB = VX_KERNEL_SAMSUNG_IVA_BASE + 0x18,

	/*! \brief The Iva BAX Kernel.
	*
	*/
	VX_KERNEL_IVA_BAX = VX_KERNEL_SAMSUNG_IVA_BASE + 0x19,

	/*! \brief The Iva SCL Interleaving Kernel.
	*
	*/
	VX_KERNEL_IVA_SCALER_INTER = VX_KERNEL_SAMSUNG_IVA_BASE + 0x1A,

	/*! \brief The IVA WME Kernel.
	*
	*/
	VX_KERNEL_IVA_WME = VX_KERNEL_SAMSUNG_IVA_BASE + 0x1B,

	/*! \brief The IVA WME compute Kernel.
	*
	*/
	VX_KERNEL_IVA_HELPERS_WME_COMPUTATION = VX_KERNEL_SAMSUNG_IVA_BASE + 0x1C,

	/*! \brief The IVA copy image kernel.
	*
	*/
	VX_KERNEL_IVA_COPY_IMAGE = VX_KERNEL_SAMSUNG_IVA_BASE + 0x1D,

	/*! \brief The IVA 4-frame MCH Kernel
	 *
	 */
	VX_KERNEL_IVA_MCH4 = VX_KERNEL_SAMSUNG_IVA_BASE + 0x1E,

	/* add here for iva */

	/* do not exceed here for iva itself, iva pre/post*/
	VX_KERNEL_IVA_EXT_KERNEL_MAX,
};

#define VX_SS_IVA_KERNEL_NUM	(VX_KERNEL_IVA_EXT_KERNEL_MAX - \
						VX_KERNEL_SAMSUNG_IVA_BASE)

enum vx_kernel_neon_ext_e {
	VX_KERNEL_SAMSUNG_NEON_BASE = VX_KERNEL_BASE(VX_ID_SAMSUNG, VX_LIBRARY_NEON),

	/*! \brief The IVA Local Min Max Kernel
	*
	*/
	VX_KERNEL_NEON_GAUSSIAN_5x5 = VX_KERNEL_SAMSUNG_NEON_BASE,

	/* do not exceed here for iva itself, iva pre/post*/
	VX_KERNEL_NEON_EXT_KERNEL_MAX,
};

#define VX_SS_NEON_KERNEL_NUM	(VX_KERNEL_NEON_EXT_KERNEL_MAX - \
						VX_KERNEL_SAMSUNG_NEON_BASE)

enum vx_kernel_score_ext_e {
	VX_KERNEL_SAMSUNG_SCORE_BASE =
			VX_KERNEL_BASE(VX_ID_SAMSUNG, VX_LIBRARY_SCORE),

	/*! \brief S-Core kernels to support channel extract
	 *
	 */
	VX_KERNEL_SCORE_CHANNELS_EXTRACT = VX_KERNEL_SAMSUNG_SCORE_BASE,

	/*! \brief S-Core kernels to support histogram
	 *
	 */
	VX_KERNEL_SCORE_HISTOGRAM,

	/*! \brief C-base Convert kernel for socre Histogram.
	 */
	VX_KERNEL_SCORE_CONV_HIST,

	/*! \brief S-Core kernels to support fast corners
	 *
	 */
	VX_KERNEL_SCORE_FAST_CORNERS,
	/*! \brief C-base Convert kernels for score fast corners
	 *
	 */
	VX_KERNEL_SCORE_CONV_FAST,

	/*! \brief S-Core kernels to support LUT
	 *
	 */
	VX_KERNEL_SCORE_LOOK_UP_TABLE,

	/*! \brief C-base Convert kernel for socre LUT.
	 */
	VX_KERNEL_SCORE_CONV_LOOK_UP_TABLE,
	/*! \brief S-Core kernels to support EqualizeHist
	 *
	 */
	VX_KERNEL_SCORE_EQUALIZE_HIST,
	/*! \brief S-Core kernels to support MeanStdDev
	 *
	 */
	VX_KERNEL_SCORE_MEANSTDDEV,

	/*! \brief C-base Convert kernel for socre MeanStdDev.
	 */
	VX_KERNEL_SCORE_CONV_MEANSTDDEV,

	VX_KERNEL_SCORE_ALPHA_BLENDER,
	VX_KERNEL_SCORE_LSC,

	/*! \brief C-base Convert kernels for score stream blend
	*
	*/
	VX_KERNEL_SCORE_STREAM_BLEND,
	/* do not exceed here for iva itself, score pre/post*/
	VX_KERNEL_SCORE_EXT_KERNEL_MAX,
};

#define VX_SS_SCORE_KERNEL_NUM	(VX_KERNEL_SCORE_EXT_KERNEL_MAX - \
						VX_KERNEL_SAMSUNG_SCORE_BASE)

enum vx_kernel_c_model_ext_e {
	VX_KERNEL_SAMSUNG_C_MODEL_BASE = VX_KERNEL_BASE(VX_ID_SAMSUNG, VX_LIBRARY_C_MODEL),
	/*! \brief The ORB MCH GetAffine Kernel
	*
	*/
	VX_KERNEL_ORBMCHGETAFFINE = VX_KERNEL_SAMSUNG_C_MODEL_BASE + 0x0,

	/* Added this to find number of kernels */
	VX_KERNEL_C_MODEL_EXT_KERNEL_MAX,

};
#define VX_SS_C_MODEL_KERNEL_NUM	(VX_KERNEL_C_MODEL_EXT_KERNEL_MAX - \
						VX_KERNEL_SAMSUNG_C_MODEL_BASE)

/* ORB */
#define DEFAULT_NMS_SIZE	(3)	/* 3: 3x3, 5: 5x5 */
#define DEFAULT_INT_FAST_TH	(20)	/* 0 ~ 128 */

/*! \brief [Graph] Creates a getAffine Node.
 * \param [in] graph The reference to the graph.
 * \param [in] orbKpt The keypoint of the reference image in <tt>\ref VX_TYPE_DELAY</tt> format.
 * \param [in] orbKptDesc The keypoint descriptors of the reference image in <tt>\ref VX_TYPE_DELAY</tt> format.
 * \param [in] mchMatchFrame0 The keypoint descriptors of the first image frame in <tt>\ref VX_TYPE_DELAY</tt> format.
 * \param [in] mchMatchFrame1 The keypoint descriptors of the second image frame in <tt>\ref VX_TYPE_DELAY</tt> format.
 * \param [in] mchMatchFrame2 The keypoint descriptors of the third image frame in <tt>\ref VX_TYPE_DELAY</tt> format.
 * \param [in] mchMatchFrame3 The keypoint descriptors of the fourth image frame in <tt>\ref VX_TYPE_DELAY</tt> format.
 * \param [out] affine The output affine matrices for the frames in <tt>\ref VX_TYPE_ARRAY</tt> format.
 * \param [in] zoom, A <tt>\ref VX_TYPE_FLOAT32</tt> This describes ratio of input dim to output dim of images
 *                   on which affine matrix is applied.
 * \param [out] flag The output flag values for the frames in <tt>\ref VX_TYPE_ARRAY</tt> format.
 * \param [out] error The output error values for the frames in <tt>\ref VX_TYPE_ARRAY</tt> format.
 * \param [in] blendSize, A <tt>\ref VX_TYPE_UINT32</tt> value describing the number of frames to be blended.
 * \param [in] rotThr, A <tt>\ref VX_TYPE_FLOAT32</tt> value describing the rotation treshhold.
 * \param [in] scaleSymmThr, A <tt>\ref VX_TYPE_FLOAT32</tt> value describing the scaling treshhold.
 * \param [in] transThr, A <tt>\ref VX_TYPE_FLOAT32</tt> value describing the translation treshhold.
 * \param [in] fitThr, A <tt>\ref VX_TYPE_FLOAT32</tt> value describing the treshhold.
 * \param [in] offsetX, A <tt>\ref VX_TYPE_ARRAY</tt> ORB offset in X.
 * \param [in] offsetY, A <tt>\ref VX_TYPE_ARRAY</tt> ORB offset in Y.
 * \param [in] fastTh, A <tt>\ref VX_TYPE_DELAY</tt> Feedback delay.
 * \param [in] width_tile, A <tt>\ref VX_TYPE_UINT32</tt> value describing width of tile for which ORB feature points are calculated.
 *                          It is used for Threshold feedback mechanism.
 * \param [in] height_tile, A <tt>\ref VX_TYPE_UINT32</tt> value describing height of tile for which ORB feature points are calculated.
 *                          It is used for Threshold feedback mechanism.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxOrbMchGetAffineNode(vx_graph graph, vx_delay orbKpt, vx_delay orbKptDesc,
          vx_delay mchMatchFrame0, vx_delay mchMatchFrame1, vx_delay mchMatchFrame2,
          vx_delay mchMatchFrame3, vx_matrix wig_matrix0, vx_matrix wig_matrix1, vx_matrix wig_matrix2,
          vx_matrix wig_matrix3, vx_matrix wig_matrix4, vx_array zoom, vx_array flag, vx_array error,
          vx_scalar blendSize, vx_scalar rotThr, vx_scalar scaleSymmThr,
          vx_scalar transThr, vx_scalar fitThr, vx_array offsetX, vx_array offsetY,
          vx_delay fastTh, vx_scalar width_tile, vx_scalar height_tile, vx_array translation,
          vx_scalar vdisScale, vx_array orbScale);

/*! \brief [Graph] Creates a Gaussian Filter Node.
 * \param [in] graph The reference to the graph.
 * \param [in] input The input image in <tt>\ref VX_DF_IMAGE_U8</tt> format.
 * \param [out] output The output image in <tt>\ref VX_DF_IMAGE_U8</tt> format.
 * \ingroup group_vision_function_gaussian_image
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxNeonGaussian5x5Node(vx_graph graph, vx_image input, vx_image output);


/** @brief  [Graph] Computes Corner Score for each pixel in the image.
 * Supports only two modes namely Harris  Score or Minimum Eigen Value Score
 *
 * \param [in] graph The reference to the graph.
 * \param [in] img The input <tt>\ref VX_DF_IMAGE_U8</tt> image.
 * \param [in] use_harris A <tt>\ref VX_TYPE_INT32</tt> value describing the method for score computation.
 * Supports two modes. Harris and Eigen scores. 0 - Min Eigen Value, 1 - Harris.
 * \param [in] harris_k A <tt>\ref VX_TYPE_INT32</tt> value describing the harris_k for score computation. Value should be calculated as shown below.
 *  harris_k = floor(harris_k_float * 2 ^ 15), where 0.01 < k < 0.1
 * \param [in] window_size Block size to be considered for Score computation. Use a <tt>\ref VX_TYPE_INT32</tt> value to describe the window size.
 * Supported window_sizes are 3, 5, 7, 9, 11, 13, 15.
 * \param [in] output_mode Harris Score is represented in a 16-bit proprietary float or 32-bit IEEE754 float format. Output Use a <tt>\ref VX_TYPE_INT32</tt> value
 * to describe the output mode. Supports two output modes. 1 - 32bit, 0 - 16bit.
 * 16-bit proprietary float is of the following format. Sign - 1, Exponent - 6, Significand - 9.
 * \param [out] output A <tt>\ref vx_image</tt> with each pixel describing the scores of corresponding pixel of the image. Data type of the image depends
 * output_mode.
 * \return <tt>\ref vx_node</tt>.
 * \retval  vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \note For more information on debug mode and output format in debug mode, please refer to the LMD HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVACornerScoreNode(vx_graph graph,
        vx_image img,
        vx_scalar use_harris,
        vx_scalar harris_k,
        vx_scalar window_size,
        vx_scalar output_mode,
        vx_image out);

/** @brief [Graph]  Performs a Local Maxima and Minima detection on given input image.
 * \param[in] graph The reference to the graph.
 * \param[in] img A <tt>\ref vx_image</tt> image with either of the following data types.
 * <tt>\ref VX_DF_IMAGE_U8</tt> or <tt>\ref VX_DF_IMAGE_U16</tt> or <tt>\ref VX_DF_IMAGE_S16</tt> or <tt>\ref VX_DF_IMAGE_S32</tt>.
 * \param[in] window_size Window size used for comparing the target pixel to detect if it is  maxima/minima. Supported window sizes are 3
 * and 5. Use a <tt>\ref VX_TYPE_INT32</tt> scalar to describe the window size.
 * \param[in] max_cmd Enable or Disable Maxima Comparison. 1 - Enable, 0 - Disable. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] min_cmd Enable or Disable Minima Comparison. 1 - Enable, 0 - Disable. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] strict_mode Comparsion method. 1 - Enable strict mode. Pixel must not be equal to any neighboring pixel in window 0 - Inclusive. Pixel may be equal to neighboring pixel. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] max_thresh Maxima threshold. Any pixel less than this will not be considered for maxima comparison. Use a
 * <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] min_thresh Minima threshold. Any pixel greater than this will not be considered for minima comparison.
 * Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] sign mode. Input img pixel is regarded as 0 - Unsigned, 1 - Signed, 2- Signed Magnitude.
 * Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[out] out Output array with each element describing about the detected maxima or minima pixels. Each output pixel is 64-bit in the following format.
 * Bit 63 - denotes if it is maxima or minima, Bits 48 - 62 - denote the X coordinate of pixel, Bit 47 - Don't Care, Bits 32 - 46 - denote the Y Coordinate of pixel & Bits 0 to 31 - denote the pixel value at (X, Y)
 * \return <tt>\ref vx_node</tt>.
 * \retval  vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \note For more information on debug mode and output format in debug mode, please refer to the LMD HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVALocalMinMaxNode(vx_graph graph,
        vx_image img,
        vx_scalar window_size,
        vx_scalar max_cmd,
        vx_scalar min_cmd,
        vx_scalar strict_mode,
        vx_scalar max_thresh,
        vx_scalar min_thresh,
        vx_scalar sign_mode,
        vx_array  out);

/**
 * @ brief Computes the delta configuration for the WSB nodes
 * \param[in] graph The reference to the graph.
 * \param[in] y_imgs array of luma slice images
 * \param[in] uv_imgs array of chrome images
 * \param[in] dst_width width of the destination image
 * \param[in] dst_height height of the destination image
 * \param[in] dst_stride stride of the destination image
 * \param[in] tile_width width of the tile
 * \param[in] tile_height height of the tile
 * \param[in] Array of affine matrices
 * \param[in] VCF address of the delta congif
 * \param[out] the size of the delta config array
 * \param[out] the delta config array
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIvaWSBComputationNode(vx_graph  graph,
                                                         vx_array  y_imgs,
                                                         vx_array  uv_imgs,
                                                         vx_scalar dst_width,
                                                         vx_scalar dst_height,
                                                         vx_scalar dst_stride,
                                                         vx_scalar tile_width,
                                                         vx_scalar tile_height,
                                                         vx_array matrices,
                                                         vx_array delta_config,
                                                         vx_scalar ga_roi_left,
                                                         vx_scalar ga_roi_top,
                                                         vx_scalar in_roi_left,
                                                         vx_scalar in_roi_top,
                                                         vx_scalar warp_zoom_r,
                                                         vx_scalar num_blend_frames);

/**
 * @brief Performs warping of input images and blend the warped images.
 * \param [in] graph The reference to the graph.
 * \param [in] in_y_img0 Reference to Input Luma image 0.
 * \param [in] in_y_img1 Reference to Input Luma image 1.
 * \param [in] in_y_img2 Reference to Input Luma image 2.
 * \param [in] in_y_img3 Reference to Input Luma image 3.
 * \param [in] in_y_img4 Reference to Input Luma image 4.
 * \param [in] in_uv_img0 Reference to Input Luma image 0.
 * \param [in] in_uv_img1 Reference to Input Luma image 1.
 * \param [in] in_uv_img2 Reference to Input Luma image 2.
 * \param [in] in_uv_img3 Reference to Input Luma image 3.
 * \param [in] in_uv_img4 Reference to Input Luma image 4.
 * \param [in] affine matrices A matrix containing 40 elements, each group of 8 elements representing a
 *             affine matrix for a input image.
 * \param [in] delta_config Used for only the IVA target. Contains the config information for VCM.
 * \param [in] interpolation_type Interpolation Type for Warping.
 * \param [in] iso ISO value of the reference image.
 * \param [in] blend_size Number of frames to blend.
 * \param [out] output_y Blended Output Luma image.
 * \param [out] output_uv Blended Output UV image.
 * \param [out] output_mmap Motion map of the blended image.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 *
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAWarpStreamBlendNode(vx_graph  graph,
                                                          vx_image  in_y_img0,
                                                          vx_image  in_y_img1,
                                                          vx_image  in_y_img2,
                                                          vx_image  in_y_img3,
                                                          vx_image  in_y_img4,
                                                          vx_image  in_uv_img0,
                                                          vx_image  in_uv_img1,
                                                          vx_image  in_uv_img2,
                                                          vx_image  in_uv_img3,
                                                          vx_image  in_uv_img4,
                                                          vx_array  affine_matrices,
                                                          vx_array  delta_config,
                                                          vx_scalar interpolation_type,
                                                          vx_scalar iso,
                                                          vx_scalar blend_size,
                                                          vx_image  output_y,
                                                          vx_image  output_uv,
                                                          vx_image  output_mmap,
                                                          vx_scalar ref_unity
                                                         );

/**
 * @brief Blends a series of registered y, u and v images into a single image.
 *   Works only on SCORE target when working with WarpStreamBlendNode.
 * \param[in] graph The reference to the graph.
 * \param[in] iso ISO of the reference frame.
 * \param[in] blend_size No of Frames to blend.
 * \param[in] output_stride No of Frames.
 * \param[in out] output_y Blended luma image.
 * \param[in out] output_u Blended u image.
 * \param[in out] output_v Blended v image.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference.
 * Any possible errors preventing a successful creation should be checked
 * using <tt>\ref vxGetStatus</tt>
 *
 */
VX_API_ENTRY vx_node VX_API_CALL vxStreamBlendNode( vx_graph graph,
                                                    vx_scalar cache_offset,
                                                    vx_scalar cache_size,
                                                    vx_scalar iso,
                                                    vx_scalar uv_mult,
                                                    vx_scalar ref_frame_id,
                                                    vx_scalar frame_weight0,
                                                    vx_scalar frame_weight1,
                                                    vx_scalar frame_weight2,
                                                    vx_scalar frame_weight3,
                                                    vx_scalar frame_weight4,
                                                    vx_scalar c_mot_count,
                                                    vx_scalar blend_size,
                                                    vx_scalar output_stride,
                                                    vx_image  output_y,
                                                    vx_image  output_uv,
                                                    vx_image  output_mmap,
                                                    vx_scalar actual_width,
                                                    vx_scalar actual_height,
                                                    vx_scalar ref_unity);

/**
 * @brief  Performs Edge Enhanced Noise Filter
 * \param[in] graph The reference to the graph.
 * \param[in] img The input image is 8-bit unsigned
 * \param[in] mmap The input motion map is a 8-bit unsigned
 * \param[in] config_params Threshold Configuration Parameters. A total of 55 Parameters.
 * \param[in] 00_THR_SB0_PARAM_0 Threshold parameter 0 for sub-band 0. Q12.0 (0 to 4095)
 * \param[in] 01_THR_SB0_PARAM_1 Threshold parameter 1 for sub-band 0. Q12.0 (0 to 4095)
 * \param[in] 02_THR_SB1_PARAM_0 Threshold parameter 0 for sub-band 1. Q12.0 (0 to 4095)
 * \param[in] 03_THR_SB1_PARAM_1 Threshold parameter 1 for sub-band 1. Q12.0 (0 to 4095)
 * \param[in] 04_THR_SB2_PARAM_0 Threshold parameter 0 for sub-band 2. Q12.0 (0 to 4095)
 * \param[in] 05_THR_SB2_PARAM_1 Threshold parameter 1 for sub-band 2. Q12.0 (0 to 4095)
 * \param[in] 06_THR_SB3_PARAM_0 Threshold parameter 0 for sub-band 3. Q12.0 (0 to 4095)
 * \param[in] 07_THR_SB3_PARAM_1 Threshold parameter 1 for sub-band 3. Q12.0 (0 to 4095)
 * \param[in] 08_THR_SB4_PARAM_0 Threshold parameter 0 for sub-band 4. Q12.0 (0 to 4095)
 * \param[in] 09_THR_SB4_PARAM_1 Threshold parameter 1 for sub-band 4. Q12.0 (0 to 4095)
 * \param[in] 10_THR_SB5_PARAM_0 Threshold parameter 0 for sub-band 5. Q12.0 (0 to 4095)
 * \param[in] 11_THR_SB5_PARAM_1 Threshold parameter 1 for sub-band 5. Q12.0 (0 to 4095)
 * \param[in] 12_SLP_SB0_PARAM_0 Positive slope parameter 0 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 13_SLP_SB0_PARAM_1 Positive slope parameter 1 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 14_SLP_SB1_PARAM_0 Positive slope parameter 0 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 15_SLP_SB1_PARAM_1 Positive slope parameter 1 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 16_SLP_SB2_PARAM_0 Positive slope parameter 0 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 17_SLP_SB2_PARAM_1 Positive slope parameter 1 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 18_SLP_SB3_PARAM_0 Positive slope parameter 0 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 19_SLP_SB3_PARAM_1 Positive slope parameter 1 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 20_SLP_SB4_PARAM_0 Positive slope parameter 0 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 21_SLP_SB4_PARAM_1 Positive slope parameter 1 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 22_SLP_SB5_PARAM_0 Positive slope parameter 0 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 23_SLP_SB5_PARAM_1 Positive slope parameter 1 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 24_SLN_SB0_PARAM_0 Negative slope parameter 0 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 25_SLN_SB0_PARAM_1 Negative slope parameter 1 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 26_SLN_SB1_PARAM_0 Negative slope parameter 0 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 27_SLN_SB1_PARAM_1 Negative slope parameter 1 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 28_SLN_SB2_PARAM_0 Negative slope parameter 0 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 29_SLN_SB2_PARAM_1 Negative slope parameter 1 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 30_SLN_SB3_PARAM_0 Negative slope parameter 0 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 31_SLN_SB3_PARAM_1 Negative slope parameter 1 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 32_SLN_SB4_PARAM_0 Negative slope parameter 0 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 33_SLN_SB4_PARAM_1 Negative slope parameter 1 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 34_SLN_SB5_PARAM_0 Negative slope parameter 0 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 35_SLN_SB5_PARAM_1 Negative slope parameter 1 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 36_CORING_THR_EDGE_M Coring threshold for edge M. Q12.0 (0 to 255)
 * \param[in] 37_CORING_THR_EDGE_S Coring threshold for edge S. Q12.0 (0 to 255)
 * \param[in] 38_CORING_SLP_EDGE_M Coring slope for edge M. Q12.0 (0 to 1024)
 * \param[in] 39_CORING_SLP_EDGE_S Coring slope for edge S. Q12.0 (0 to 1024)
 * \param[in] 40_HALO_THR_EDGE_M Halo threshold for edge M. Q12.0 (0 to 1023)
 * \param[in] 41_HALO_THR_EDGE_S Halo threshold for edge S. Q12.0 (0 to 1023)
 * \param[in] 42_HALO_SLP_EDGE_M Halo slope for edge M. Q12.0 (0 to 1023)
 * \param[in] 43_HALO_SLP_EDGE_S Halo slope for edge S. Q12.0 (0 to 1023)
 * \param[in] 44_HALO_GNP_EDGE_M Halo positive gain for edge M. Q12.0 (0 to 1023)
 * \param[in] 45_HALO_GNP_EDGE_S Halo positive gain for edge S. Q12.0 (0 to 1023)
 * \param[in] 46_HALO_GNN_EDGE_M Halo negative gain for edge M. Q12.0 (0 to 1023)
 * \param[in] 47_HALO_GNN_EDGE_S Halo negative gain for edge S. Q12.0 (0 to 1023)
 * \param[in] 48_BRT_ADPT0_THRESHOLD Brightness adaptive threshold. Q12.0 (0 to 255)
 * \param[in] 49_BRT_ADPT1_SLOPE Brightness adaptive slope.  Q12.0 (0 to 255)
 * \param[in] 50_BRT_ADPT2_GAIN Brightness adaptive gain.  Q12.0 (0 to 255)
 * \param[in] 51_TOT_GAIN_M_PARAM_0 Total gain parameter 0 for edge M. Q12.0 (0 to 4095)
 * \param[in] 52_TOT_GAIN_M_PARAM_1 Total gain parameter 1 for edge M. Q12.0 (0 to 4095)
 * \param[in] 53_TOT_GAIN_S_PARAM_0 Total gain parameter 0 for edge S. Q12.0 (0 to 4095)
 * \param[in] 54_TOT_GAIN_S_PARAM_1 Total gain parameter 1 for edge S. Q12.0 (0 to 4095)
 * \param[out] out Output image 8 bit unsigned
 * \param[in] flag whether motion map is enabled (1: enable, 0: disable)
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAENFNode(vx_graph  graph,
        vx_image  img,
        vx_image  mmap,
        vx_matrix config_params,
        vx_scalar out_roi_offset_x,
        vx_scalar out_roi_offset_y,
        vx_image  out,
        vx_scalar mot_en);

/**
 * @brief  Performs Edge Enhanced Noise Filter
 * \param[in] graph The reference to the graph.
 * \param[in] img The input image is 8-bit unsigned
 * \param[in] mmap The input motion map is a 8-bit unsigned
 * \param[in] config_params Threshold Configuration Parameters. A total of 55 Parameters.
 * \param[in] 00_THR_SB0_PARAM_0 Threshold parameter 0 for sub-band 0. Q12.0 (0 to 4095)
 * \param[in] 01_THR_SB0_PARAM_1 Threshold parameter 1 for sub-band 0. Q12.0 (0 to 4095)
 * \param[in] 02_THR_SB1_PARAM_0 Threshold parameter 0 for sub-band 1. Q12.0 (0 to 4095)
 * \param[in] 03_THR_SB1_PARAM_1 Threshold parameter 1 for sub-band 1. Q12.0 (0 to 4095)
 * \param[in] 04_THR_SB2_PARAM_0 Threshold parameter 0 for sub-band 2. Q12.0 (0 to 4095)
 * \param[in] 05_THR_SB2_PARAM_1 Threshold parameter 1 for sub-band 2. Q12.0 (0 to 4095)
 * \param[in] 06_THR_SB3_PARAM_0 Threshold parameter 0 for sub-band 3. Q12.0 (0 to 4095)
 * \param[in] 07_THR_SB3_PARAM_1 Threshold parameter 1 for sub-band 3. Q12.0 (0 to 4095)
 * \param[in] 08_THR_SB4_PARAM_0 Threshold parameter 0 for sub-band 4. Q12.0 (0 to 4095)
 * \param[in] 09_THR_SB4_PARAM_1 Threshold parameter 1 for sub-band 4. Q12.0 (0 to 4095)
 * \param[in] 10_THR_SB5_PARAM_0 Threshold parameter 0 for sub-band 5. Q12.0 (0 to 4095)
 * \param[in] 11_THR_SB5_PARAM_1 Threshold parameter 1 for sub-band 5. Q12.0 (0 to 4095)
 * \param[in] 12_SLP_SB0_PARAM_0 Positive slope parameter 0 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 13_SLP_SB0_PARAM_1 Positive slope parameter 1 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 14_SLP_SB1_PARAM_0 Positive slope parameter 0 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 15_SLP_SB1_PARAM_1 Positive slope parameter 1 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 16_SLP_SB2_PARAM_0 Positive slope parameter 0 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 17_SLP_SB2_PARAM_1 Positive slope parameter 1 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 18_SLP_SB3_PARAM_0 Positive slope parameter 0 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 19_SLP_SB3_PARAM_1 Positive slope parameter 1 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 20_SLP_SB4_PARAM_0 Positive slope parameter 0 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 21_SLP_SB4_PARAM_1 Positive slope parameter 1 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 22_SLP_SB5_PARAM_0 Positive slope parameter 0 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 23_SLP_SB5_PARAM_1 Positive slope parameter 1 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 24_SLN_SB0_PARAM_0 Negative slope parameter 0 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 25_SLN_SB0_PARAM_1 Negative slope parameter 1 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 26_SLN_SB1_PARAM_0 Negative slope parameter 0 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 27_SLN_SB1_PARAM_1 Negative slope parameter 1 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 28_SLN_SB2_PARAM_0 Negative slope parameter 0 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 29_SLN_SB2_PARAM_1 Negative slope parameter 1 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 30_SLN_SB3_PARAM_0 Negative slope parameter 0 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 31_SLN_SB3_PARAM_1 Negative slope parameter 1 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 32_SLN_SB4_PARAM_0 Negative slope parameter 0 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 33_SLN_SB4_PARAM_1 Negative slope parameter 1 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 34_SLN_SB5_PARAM_0 Negative slope parameter 0 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 35_SLN_SB5_PARAM_1 Negative slope parameter 1 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 36_CORING_THR_EDGE_M Coring threshold for edge M. Q12.0 (0 to 255)
 * \param[in] 37_CORING_THR_EDGE_S Coring threshold for edge S. Q12.0 (0 to 255)
 * \param[in] 38_CORING_SLP_EDGE_M Coring slope for edge M. Q12.0 (0 to 1024)
 * \param[in] 39_CORING_SLP_EDGE_S Coring slope for edge S. Q12.0 (0 to 1024)
 * \param[in] 40_HALO_THR_EDGE_M Halo threshold for edge M. Q12.0 (0 to 1023)
 * \param[in] 41_HALO_THR_EDGE_S Halo threshold for edge S. Q12.0 (0 to 1023)
 * \param[in] 42_HALO_SLP_EDGE_M Halo slope for edge M. Q12.0 (0 to 1023)
 * \param[in] 43_HALO_SLP_EDGE_S Halo slope for edge S. Q12.0 (0 to 1023)
 * \param[in] 44_HALO_GNP_EDGE_M Halo positive gain for edge M. Q12.0 (0 to 1023)
 * \param[in] 45_HALO_GNP_EDGE_S Halo positive gain for edge S. Q12.0 (0 to 1023)
 * \param[in] 46_HALO_GNN_EDGE_M Halo negative gain for edge M. Q12.0 (0 to 1023)
 * \param[in] 47_HALO_GNN_EDGE_S Halo negative gain for edge S. Q12.0 (0 to 1023)
 * \param[in] 48_BRT_ADPT0_THRESHOLD Brightness adaptive threshold. Q12.0 (0 to 255)
 * \param[in] 49_BRT_ADPT1_SLOPE Brightness adaptive slope.  Q12.0 (0 to 255)
 * \param[in] 50_BRT_ADPT2_GAIN Brightness adaptive gain.  Q12.0 (0 to 255)
 * \param[in] 51_TOT_GAIN_M_PARAM_0 Total gain parameter 0 for edge M. Q12.0 (0 to 4095)
 * \param[in] 52_TOT_GAIN_M_PARAM_1 Total gain parameter 1 for edge M. Q12.0 (0 to 4095)
 * \param[in] 53_TOT_GAIN_S_PARAM_0 Total gain parameter 0 for edge S. Q12.0 (0 to 4095)
 * \param[in] 54_TOT_GAIN_S_PARAM_1 Total gain parameter 1 for edge S. Q12.0 (0 to 4095)
 * \param[out] Output UV image (if format is VX_DF_IMAGE_UV) or U image (if format is VX_DF_IMAGE_U8)
 * \param[out] Output V image if previous one is VX_DF_IMAGE_U8 else it's ignore
 * \param[in] flag whether motion map is enabled (1: enable, 0: disable)
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAUVENFNode(vx_graph  graph,
        vx_image  img,
        vx_image  mmap,
        vx_matrix config_params,
        vx_scalar out_roi_offset_x,
        vx_scalar out_roi_offset_y,
        vx_image  out_1,
        vx_image  out_2,
        vx_scalar mot_en);


/** @brief  Performs conversion of remap table to mesh as expected by IVA WIG HWA.
 * \param[in] graph The reference to the graph.
 * \param[in] table Remap Table.
 * \param[in] mesh Mesh as expected by IVA WIG HWA.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVARemapPreProcessNode(vx_graph graph,
        vx_remap table,
        vx_array mesh);

/** @brief  Performs masking out-of-bound area of out image.
 * \param[in] table Remap Table.
 * \param[in] Remapped image before post-processing.
 * \param[out] Post-processed image.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVARemapPostProcessNode(vx_graph graph,
        vx_remap table,
        vx_image in,
        vx_image out);

/** @brief  Converts affine matrix from float to Q Point format as expected by IVA WIG HWA.
 * \param[in] graph The reference to the graph.
 * \param[in] matrix Affine Matrix in Float.
 * \param[in] matrix Affine Matrix in Q format as expected by IVA WIG HWA.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAWIGPreProcessNode(vx_graph graph,
        vx_matrix affine_flt,
        vx_scalar conv_sclr,
        vx_image in_img,
        vx_matrix affine_int);


/** @brief  Performs warping on the given input image using transform matrix.
 * \param[in] graph The reference to the graph.
 * \param[in] img The input is 8-bit image.
 * \param[in] wmode Warp Mode can take values 0 or 1. 0 indicates MATRIX MODE whereas 1 indicates MESH MODE.
 * In MATRIX MODE affine_mat needs to be provided and mesh can be NULL.
 * In MESH MODE mesh needs to be provided and affine_mat can be passed as NULL.
 * \param[in] affine_mat Coefficients of the 8 element transformation matrix, using which affine or perspective transform is performed on the input image
 * Transformation matrix is an 8 element array {a, b, c, d, e, f, g, h}; a,b,d,e,g,h are in Q11.20 format and c, e are in Q15.16
 * (x,y) is the input pixel
 * (u,v) is the output pixel
 * Mapping of output to input pixels is as follows:
 * u = (ax+by+c)/(gx+hy+1)  ;  v = (dx+ey+f)/(gx+hy+1)
 * \param[in] mesh It consists of output to input mapping for the pixels seperated by mspace distance.
 * The coordinate (x, y) of source pixel should be packed as (y << 16) + x .
 * Size of mesh is 4 * ((out_width/mspace) + 1) * ((out_height/mspace) + 1) where out_width & out_height represent width and height of output.
 * \param[in] log_mspace Log value of the mspace to base 2. Used only in Mesh Mode.
 * \param[in] inter_mode Interpolation mode.
 * Supports following modes: VX_INTERPOLATION_TYPE_NEAREST_NEIGHBOR, VX_INTERPOLATION_TYPE_BILINEAR, VX_INTERPOLATION_TYPE_BICUBIC
 * \param[out] out Output image after applying affine transformation on input image.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAWIGNode(vx_graph graph,
        vx_image img,
        vx_scalar wmode,
        vx_matrix  affine_mat,
        vx_array  mesh,
        vx_scalar log_mspace,
        vx_scalar inter_mode,
        vx_scalar frame_mesh_en,
        vx_image out);
/**
 * @brief [Graph] Performs a Lucas Kanade Tracking from one image to another image on a specified level.
 * \param[in] graph The reference to the graph.
 * \param[in] ref_img The reference <tt>\ref VX_DF_IMAGE_U8 </tt> image.
 * \param[in] trk_img The tracking <tt>\ref VX_DF_IMAGE_U8 </tt> image on which the points are to the tracked.
 * \param[in] ref_points A <tt>\ref VX_TYPE_UINT64</tt> type array containing the points of the reference image to be tracked.
 * Each point is described in a 64-bit format. A 64-bit element contains reference x and y coordinates in upper 32-bits and initial track point estimate in
 * the lower 32-bits. All the coordinates should be in Q12.4 format.
 * \image html lkt.jpg
 * \param[in] window_size A <tt>\ref VX_TYPE_INT32</tt> scalar. Width the size of the tracking window at each iteration.
 * Supported window sizes are 5, 7, 9, 15, and 21.
 * \param[in] num_iters  A <tt>\ref VX_TYPE_INT32</tt> scalar. Maximum iterations before termination. Supported range is 1-255.
 * \param[in] min_step Minimum displacement for termination. Displacement vector (hhx, hhy) is computed in Q3.4 format.
 * Iteration terminate when (hhx*hhx + hhy*hhy < min_step). Supported minimum step size is  0 - 255. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * If minimum step size is < 0, then the min_step is not taken into criteria for LKT termination.
 * \param[in] gradient_type Two types of gradients are supported. Sobel and Scharr. 0 - Sobel and 1 - Scharr. Use a <tt>\ref VX_TYPE_INT32</tt> scalar/
 * \param[in] output_mode Supports two output modes. 0 - default mode. 1 - debug mode.
 * \param[in] border_mode A <tt>\ref VX_TYPE_INT32</tt> scalar supporting two border handling modes. 1 - Replicate Mode and 0 - Constant Mode.
 * \param[in] border_constant A <tt>\ref VX_TYPE_INT32</tt> scalar describing the value of the padded border. Used only when the border_mode is 0. Range is 0-255.
 * \param[in] lkt_level A <tt>\ref VX_TYPE_INT32</tt> scalar describing the level of the reference and tracking images in the pyramidal LKT.
 * 0 - Full resolution image, 1 - Half resolution in both width and height and so on. Input reference and tracking are expected to be scaled to this level,
 * while input ref_points are described with respect to level 0 i.e. full resolution image. Using the lkt_level, ref_points are scaled down accordingly and used for
 * tracking. Output track points are again scaled up to the full resolution.
 * \param[out] trk_points A <tt>\ref VX_TYPE_UINT64</tt> type array with the tracked points.
 * In default output mode, if the lkt_level is 0, only the tracked points are dumped, otherwise for the points which cannot be tracked, output will be equal to
 * input. The format of the tracked points will be same as ref_points (Refer ref_points for format description).
 * If the output_mode is set to debug, debug info will be dumped for all the points along with the tracked locations. In debug mode, the bits 60-63 will describe a
 * flag about the error, coordinates of tracked point will be of Q12.4 format and will be located at 32, 0 bit respectively. If the flag value is 4, then the point
 * is tracked, else otherwise.
 * \return <tt>\ref vx_node</tt>.
 * \retval  vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \note For more information on debug mode and output format in debug mode, please refer to the LKT HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVALKTrackerNode(vx_graph graph,
        vx_image ref_img,
        vx_image trk_img,
        vx_array ref_points,
        vx_scalar window_size,
        vx_scalar max_iters,
        vx_scalar min_step,
        vx_scalar gradient_type,
        vx_scalar output_mode,
        vx_scalar lkt_level,
        vx_array trk_points);

/**
 * @brief  [Graph] Performs a ORB keypoint detection and their descriptors on an image.
 * Computes FAST keypoints, orientation and their rBRIEF descriptors in an image. Orientation computed in a given diameter. Maximum value of
 * diameter is 35. IVA ORB leaves a border of 21 on every side. So the image provided should be of dimensions atleast 43x43.
 * \param[in] graph The reference to the graph.
 * \param[in] image A <tt>\ref VX_DF_IMAGE_U8 </tt> image.
 * \param[in] diameter Diameter for Keypoints Orientation Computation. Use a <tt>\ref VX_TYPE_INT32</tt> value. Supported range is 1 - 35.
 * \param[in] fast_th Keypoint threshold for FAST response. Use a <tt>\ref VX_TYPE_INT32</tt> value. Value should be of 0-255.
 * \param[in] harris_en decides to compute Fast response or Harris response and use corresponding threshold. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] harris_th Keypoints threshold for Harris response. Use a <tt>\ref VX_TYPE_FLOAT32</tt> value.
 * \param[in] scale_x Scale factor for X-coordinate of Keypoint and should be in Q7.18 format. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] scale_y Scale factor for Y-coordinate of Keypoint and should be in Q7.18 format. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] metadata Metadata to be filled in the Keypoint structure as shown below. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[out] keypoints A <tt>\ref vx_array</tt> containing keypoints. Each keypoint is a <tt>\ref VX_TYPE_UINT128</tt> value as described below.
 * \image html orb_keypoint.jpg
 * \param[out] descriptors A <tt>\ref vx_array</tt> containing descriptors. Each descriptor is 256-bit binary descriptor. Data type of <tt>\ref vx_array</tt>
 * holding the descriptors is of type <tt>\ref VX_TYPE_UINT256</tt> type.
 * \return <tt>\ref vx_node</tt>.
 * \retval  vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \ingroup group_vision_function_remap
 * \note For more information on ORB algorithm implementation, please refer to the ORB HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAOrbNode (vx_graph graph,
        vx_image image,
        vx_scalar diameter,
        vx_scalar fast_th,
        vx_scalar harris_en,
        vx_scalar harris_th,
        vx_scalar scale_x,
        vx_scalar scale_y,
        vx_scalar metadata,
        vx_array keypoints,
        vx_array descriptors,
        vx_scalar nms_size,
        vx_scalar int_fast_th);

/**
 * @brief  [Graph] Performs a ORB keypoint detection and their descriptors on an image.
 * Computes FAST keypoints, orientation and their rBRIEF descriptors in an image. Orientation computed in a given diameter. Maximum value of
 * diameter is 35. IVA ORB leaves a border of 21 on every side. So the image provided should be of dimensions atleast 43x43.
 * \param[in] graph The reference to the graph.
 * \param[in] image A <tt>\ref VX_DF_IMAGE_U8 </tt> image.
 * \param[in] diameter Diameter for Keypoints Orientation Computation. Use a <tt>\ref VX_TYPE_INT32</tt> value. Supported range is 1 - 35.
 * \param[in] fast_th Keypoint threshold for FAST response. Use a <tt>\ref VX_TYPE_INT32</tt> value. Value should be of 0-255.
 * \param[in] harris_en decides to compute Fast response or Harris response and use corresponding threshold. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] harris_th Keypoints threshold for Harris response. Use a <tt>\ref VX_TYPE_FLOAT32</tt> value.
 * \param[in] scale_x Scale factor for X-coordinate of Keypoint and should be in Q7.18 format. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] scale_y Scale factor for Y-coordinate of Keypoint and should be in Q7.18 format. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] metadata Metadata to be filled in the Keypoint structure as shown below. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[out] keypoints A <tt>\ref vx_array</tt> containing keypoints. Each keypoint is a <tt>\ref VX_TYPE_UINT128</tt> value as described below.
 * \image html orb_keypoint.jpg
 * \param[out] descriptors A <tt>\ref vx_array</tt> containing descriptors. Each descriptor is 256-bit binary descriptor. Data type of <tt>\ref vx_array</tt>
 * holding the descriptors is of type <tt>\ref VX_TYPE_UINT256</tt> type.
 * \return <tt>\ref vx_node</tt>.
 * \retval  vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \ingroup group_vision_function_remap
 * \note For more information on ORB algorithm implementation, please refer to the ORB HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAFastOrbNode (vx_graph graph,
        vx_image image,
        vx_scalar diameter,
        vx_scalar fast_th,
        vx_scalar harris_en,
        vx_scalar harris_th,
        vx_scalar scale_x,
        vx_scalar scale_y,
        vx_scalar metadata,
        vx_array keypoints,
        vx_array descriptors,
        vx_scalar offset_x,
        vx_scalar offset_y,
        vx_scalar nms_size,
        vx_scalar int_fast_th);

/** @brief  Performs Either Upscaling or Downscaling on the given input image with user specified scaler coefficients
* \param[in]    graph                                            The reference to the graph.
* \param[in]    in                <tt>\ref VX_DF_IMAGE_U8 </tt>    The input is 8/16-bit image.
* \param[in]    scale            <tt>\ref VX_TYPE_FLOAT32</tt>    Scale factor by which input image is scaled. Specify either dst_width/height or scale. Not both.
* \param[in]    scl_mode        <tt>\ref VX_TYPE_INT32</tt>        Scaler operation mode: 0 - scaling or 1 - general 2D filtering
* \param[in]    interpolation    <tt>\ref VX_TYPE_INT32</tt>        Type of interpolation to be done (=5, 4, 3, or 2)
                                                                    Supports 4 different kernel size: Gaussian 5x5, Bicubic 4x4, Gaussian 3x3, Bilinear 2x2
                                                                    Scaling mode: 2x2, 3x3, 4x4, 5x5
                                                                    General 2D filtering: 3x3, 5x5
* \param[in]    scl_coeff        <tt>\ref VX_TYPE_ARRAY</tt>        Coefficients for 32 Phases. Size = (interpolation x 32)
* \param[in]    v_offset        <tt>\ref VX_TYPE_INT32</tt>        vertical offset
* \param[in]    h_offset        <tt>\ref VX_TYPE_INT32</tt>        horizontal offset
* \param[out]    out                <tt>\ref VX_DF_IMAGE_U8 </tt>    Output image in 8/16-bit format after applying scaling on input image.
* \return <tt>\ref vx_node</tt>.
* \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
* \note For more information on debug mode and output format in debug mode, please refer to the SCL HWA documentation.
*/
VX_API_ENTRY vx_node VX_API_CALL vxIVAScalerNode(vx_graph graph,
        vx_image  in,
        vx_scalar scale,
        vx_scalar scl_mode,
        vx_scalar interpolation,
        vx_matrix scl_coeff,
        vx_scalar v_offset,
        vx_scalar h_offset,
        vx_image  out);

/** @brief  Performs Either Upscaling or Downscaling on the given input image with user specified scaler coefficients
* \param[in]    graph                                            The reference to the graph.
* \param[in]    in                <tt>\ref VX_DF_IMAGE_U8 </tt>    The input is 8/16-bit image.
* \param[in]    scl_mode        <tt>\ref VX_TYPE_INT32</tt>        Scaler operation mode: 0 - scaling or 1 - general 2D filtering
* \param[in]    interpolation    <tt>\ref VX_TYPE_INT32</tt>        Type of interpolation to be done (=5, 4, 3, or 2)
                                                                    Supports 4 different kernel size: Gaussian 5x5, Bicubic 4x4, Gaussian 3x3, Bilinear 2x2
                                                                    Scaling mode: 2x2, 3x3, 4x4, 5x5
                                                                    General 2D filtering: 3x3, 5x5
* \param[in]    scl_coeff        <tt>\ref VX_TYPE_ARRAY</tt>        Coefficients for 32 Phases. Size = (interpolation x 32)
* \param[in]    v_offset        <tt>\ref VX_TYPE_INT32</tt>        vertical offset
* \param[in]    h_offset        <tt>\ref VX_TYPE_INT32</tt>        horizontal offset
* \param[out]   out             <tt>\ref VX_DF_IMAGE_U8 </tt>      Output image in 8/16-bit format after applying scaling on input image.
* \param[in]    v_scale        <tt>\ref VX_TYPE_INT32</tt>         vertical scale
* \param[in]    h_scale        <tt>\ref VX_TYPE_INT32</tt>         horizontal scale
* \param[in]    src_width      <tt>\ref VX_TYPE_UINT32</tt>        src Width used for ROI scaling
* \param[in]    src_height     <tt>\ref VX_TYPE_UINT32</tt>        src Height used for ROI scaling
* \param[in]    dst_width      <tt>\ref VX_TYPE_UINT32</tt>        dst Width used for ROI scaling
* \param[in]    dst_height     <tt>\ref VX_TYPE_UINT32</tt>        dst Height used for ROI scaling
* \return <tt>\ref vx_node</tt>.
* \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
* \note For more information on debug mode and output format in debug mode, please refer to the SCL HWA documentation.
*/
VX_API_ENTRY vx_node VX_API_CALL vxIVAScalerROINode(vx_graph graph,
        vx_image  in,
        vx_scalar scale,
        vx_scalar scl_mode,
        vx_scalar interpolation,
        vx_matrix scl_coeff,
        vx_scalar v_offset,
        vx_scalar h_offset,
        vx_image  out,
        vx_scalar h_scale,
        vx_scalar v_scale,
        vx_scalar src_width,
        vx_scalar src_height,
        vx_scalar dst_width,
        vx_scalar dst_height);


/** @brief  Performs Either Upscaling or Downscaling on the given input UV
** image(Interleaved format) with user specified scaler coefficients
* \param[in]    graph                                            The reference to the graph.
* \param[in]    in                <tt>\ref VX_DF_IMAGE_U8 </tt>    The input is 8-bit image.
* \param[in]    scale            <tt>\ref VX_TYPE_FLOAT32</tt>    Scale factor by which input image is scaled. Specify either dst_width/height or scale. Not both.
* \param[in]    scl_mode        <tt>\ref VX_TYPE_INT32</tt>        Scaler operation mode: 0 - scaling or 1 - general 2D filtering
* \param[in]    interpolation    <tt>\ref VX_TYPE_INT32</tt>        Type of interpolation to be done (=5, 4, 3, or 2)
                                                                    Supports 4 different kernel size: Gaussian 5x5, Bicubic 4x4, Gaussian 3x3, Bilinear 2x2
                                                                    Scaling mode: 2x2, 3x3, 4x4, 5x5
                                                                    General 2D filtering: 3x3, 5x5
* \param[in]    scl_coeff        <tt>\ref VX_TYPE_ARRAY</tt>        Coefficients for 32 Phases. Size = (interpolation x 32)
* \param[in]    v_offset        <tt>\ref VX_TYPE_INT32</tt>        vertical offset
* \param[in]    h_offset        <tt>\ref VX_TYPE_INT32</tt>        horizontal offset
* \param[out]    out                <tt>\ref VX_DF_IMAGE_U8 </tt>    Output image in 8/16-bit format after applying scaling on input image.
* \param[in]    v_ratio        <tt>\ref VX_TYPE_INT32</tt>        vertical ratio
* \param[in]    h_ratio        <tt>\ref VX_TYPE_INT32</tt>        horizontal ratio
* \param[in]    ctrl_type        <tt>\ref VX_TYPE_INT32</tt>        control type (0 - scale and offset are derived internally, 1 - given from App)
* \return <tt>\ref vx_node</tt>.
* \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
* \note For more information on debug mode and output format in debug mode, please refer to the SCL HWA documentation.
*/
VX_API_ENTRY vx_node VX_API_CALL vxIVAUVScalerNode(vx_graph graph,
        vx_image  in,
        vx_scalar scale,
        vx_scalar scl_mode,
        vx_scalar interpolation,
        vx_matrix  scl_coeff,
        vx_scalar v_offset,
        vx_scalar h_offset,
        vx_image  out,
        vx_scalar v_ratio,
        vx_scalar h_ratio,
        vx_scalar ctrl_type);

/** @brief  Performs Either Upscaling or Downscaling on the given separate U and V on input
** image(Interleaved format) with user specified scaler coefficients
* \param[in]    graph                                            The reference to the graph.
* \param[in]    inU              <tt>\ref VX_DF_IMAGE_U8 </tt>   The input is 8-bit U.
* \param[in]    inV              <tt>\ref VX_DF_IMAGE_U8 </tt>   The input is 8-bit V.
* \param[in]    scale            <tt>\ref VX_TYPE_FLOAT32</tt>   Scale factor by which input image is scaled. Specify either dst_width/height or scale. Not both.
* \param[in]    scl_mode         <tt>\ref VX_TYPE_INT32</tt>     Scaler operation mode: 0 - scaling or 1 - general 2D filtering
* \param[in]    interpolation    <tt>\ref VX_TYPE_INT32</tt>     Type of interpolation to be done (=5, 4, 3, or 2)
                                                                 Supports 4 different kernel size: Gaussian 5x5, Bicubic 4x4, Gaussian 3x3, Bilinear 2x2
                                                                 Scaling mode: 2x2, 3x3, 4x4, 5x5
                                                                 General 2D filtering: 3x3, 5x5
* \param[in]    scl_coeff        <tt>\ref VX_TYPE_ARRAY</tt>     Coefficients for 32 Phases. Size = (interpolation x 32)
* \param[in]    v_offset         <tt>\ref VX_TYPE_INT32</tt>     vertical offset
* \param[in]    h_offset         <tt>\ref VX_TYPE_INT32</tt>     horizontal offset
* \param[out]   out              <tt>\ref VX_DF_IMAGE_UV </tt>   Interleaved UV
* \param[in]    v_ratio          <tt>\ref VX_TYPE_INT32</tt>     vertical ratio
* \param[in]    h_ratio          <tt>\ref VX_TYPE_INT32</tt>     horizontal ratio
* \param[in]    ctrl_type        <tt>\ref VX_TYPE_INT32</tt>     control type (0 - scale and offset are derived internally, 1 - given from App)
* \return <tt>\ref vx_node</tt>.
* \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
* \note For more information on debug mode and output format in debug mode, please refer to the SCL HWA documentation.
*/
VX_API_ENTRY vx_node VX_API_CALL vxIVAScalerInterNode(vx_graph graph,
    vx_image  inU,
    vx_image  inV,
    vx_scalar scale,
    vx_scalar scl_mode,
    vx_scalar interpolation,
    vx_matrix  scl_coeff,
    vx_scalar v_offset,
    vx_scalar h_offset,
    vx_image  out,
    vx_scalar v_ratio,
    vx_scalar h_ratio,
    vx_scalar ctrl_type);

/** @brief  Performs Spatial Noise Reduction via Bilateral Filtering (used as Pre Processing block for ENF)
 * \param[in] graph The reference to the graph.
 * \param[in] img The input image is <tt>\ref VX_DF_IMAGE_YUV4 </tt> (YUV 444 Planar Image)
 * \param[out] out The Output image <tt>\ref VX_DF_IMAGE_U8 </tt>
 * \param[in] width Width of the input image
 * \param[in] height Height of the input image
 * \param[in] pthres_params A <tt>\ref VX_TYPE_UINT8</tt> type array containing threshold Parameters for luma, cb, cr.
 * Pass NULL to use default Values.
 * \param[in] border_mode A <tt>\ref VX_TYPE_INT32</tt> scalar supporting two border handling modes. 1 - Replicate Mode and 0 - Constant Mode.
 * \param[in] border_constant A <tt>\ref VX_TYPE_INT32</tt> scalar describing the value of the padded border. Used only when the border_mode is 0. Range is 0-255.
 * \paral[in] sweights_params A <tt>\ref VX_TYPE_UINT8</tt> type array containing weights for spatial filtering.
 * Pass NULL to use default Values.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 * \note For more information on debug mode and output format in debug mode, please refer to the ENF HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAENFPNode(vx_graph  graph,
        vx_image  img,
        vx_scalar width,
        vx_scalar height,
        vx_array  pthres_params,
        vx_array  sweights_params,
        vx_image  out);

/**
 * TODO:
 */
VX_API_ENTRY vx_node VX_API_CALL vxIvaOptFlowPyrLkPreProcessNode(vx_graph        graph,
                                                                 vx_array        old_points,
                                                                 vx_array        new_points_estimate,
                                                                 vx_scalar       max_level,
                                                                 vx_scalar       scale,
                                                                 vx_array        old_points_iva
                                                                );
/**
 * TODO:
 */
VX_API_ENTRY vx_node VX_API_CALL vxIvaOptFlowPyrLKInterLevelNode(vx_graph        graph,
                                                                 vx_array        prev_old_points,
                                                                 vx_array        prev_new_points,
                                                                 vx_scalar       scale,
                                                                 vx_array        cur_old_points
                                                                );
/**
 * TODO:
 */
VX_API_ENTRY vx_node VX_API_CALL vxIvaOptFlowPyrLKPostProcessNode(vx_graph       graph,
                                                                  vx_array       old_points_iva,
                                                                  vx_array       new_points_iva,
                                                                  vx_array       new_points
                                                                 );
/**
 * @brief For a given Database and Querybase, MCH module finds the maximum of 3 Nearest neighbors and
 * returns the matchNum, index and disatnce for each Query.
 * \param[in] graph The reference to the graph.
 * \param[in] query_array Querybase array
 * \param[in] db_array Database array.
 * \param[in] output_array A <tt>\ref VX_TYPE_CHAR</tt> type Output array to write MatchNum, Index and Distance for each query.
 * \param[in] dist_mode A <tt>\ref VX_TYPE_INT32</tt> scalar holds Distance calculation mode. Supports BINARY(0) and REAL(1) modes.
 * \param[in] vector_size A <tt>\ref VX_TYPE_INT32</tt> scalar holds Database, Querybase input dimension. Supports 128, 256 and 512 (in bits) in BINARY mode, 16n (1<=n<=8) bytes in REAL mode.
 * \param[in] num_nearest A <tt>\ref VX_TYPE_INT32</tt> scalar. MCH module returns maximum of 3 nearest neighbors and match_num(1 to 3) is used to configure how many nearest neighbors required.
 * \param[in] output_mode A <tt>\ref VX_TYPE_INT32</tt> scalar holds Output mode. In '0' mode, MCH module returns MatchNum(1 byte) and Index(1 byte) for each query.
 * whereas in output mode '1', MCH returns MatchNum(1 byte), Index(1 byte) and Distance(2 byte) for each query.
 * \param[in] thresh_on A <tt>\ref VX_TYPE_INT32</tt> scalar to set/reset Threshold On. describing the level of the reference and tracking images in the pyramidal LKT.
 * \param[in] thresh_val A <tt>\ref VX_TYPE_INT32</tt> scalar. When Threshold On is set, for a given query, MCH returns that match, if distance is more than the threshold.
 * \return <tt>\ref vx_node</tt>.
 * \retval  vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \note For more information on debug mode and output format in debug mode, please refer to the MCH HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAMCHNode(vx_graph graph,
        vx_array query_array,
        vx_array db_array,
        vx_array output_array,
        vx_scalar dist_mode,
        vx_scalar vector_size,
        vx_scalar num_nearest,
        vx_scalar output_mode,
        vx_scalar thresh_on,
        vx_scalar thresh_val);

/**
 * @brief For a given Database and up to 4 sets of Query, MCH module finds the maximum of 3 Nearest neighbors and
 * returns the matchNum, index and disatnce for each Query.
 * \param[in] graph The reference to the graph.
 * \param[in] query_array0 Querybase array #0
 * \param[in] query_array1 Querybase array #1
 * \param[in] query_array2 Querybase array #2
 * \param[in] query_array3 Querybase array #3
 * \param[in] db_array Database array.
 * \param[in] output_array0 A <tt>\ref VX_TYPE_CHAR</tt> type Output array to write MatchNum, Index and Distance for query set 0.
 * \param[in] output_array1 A <tt>\ref VX_TYPE_CHAR</tt> type Output array to write MatchNum, Index and Distance for query set 1.
 * \param[in] output_array2 A <tt>\ref VX_TYPE_CHAR</tt> type Output array to write MatchNum, Index and Distance for query set 2.
 * \param[in] output_array3 A <tt>\ref VX_TYPE_CHAR</tt> type Output array to write MatchNum, Index and Distance for query set 3.
 * \param[in] dist_mode A <tt>\ref VX_TYPE_INT32</tt> scalar holds Distance calculation mode. Supports BINARY(0) and REAL(1) modes.
 * \param[in] vector_size A <tt>\ref VX_TYPE_INT32</tt> scalar holds Database, Querybase input dimension. Supports 128, 256 and 512 (in bits) in BINARY mode, 16n (1<=n<=8) bytes in REAL mode.
 * \param[in] num_nearest A <tt>\ref VX_TYPE_INT32</tt> scalar. MCH module returns maximum of 3 nearest neighbors and match_num(1 to 3) is used to configure how many nearest neighbors required.
 * \param[in] output_mode A <tt>\ref VX_TYPE_INT32</tt> scalar holds Output mode. In '0' mode, MCH module returns MatchNum(1 byte) and Index(1 byte) for each query.
 * whereas in output mode '1', MCH returns MatchNum(1 byte), Index(1 byte) and Distance(2 byte) for each query.
 * \param[in] thresh_on A <tt>\ref VX_TYPE_INT32</tt> scalar to set/reset Threshold On. describing the level of the reference and tracking images in the pyramidal LKT.
 * \param[in] thresh_val A <tt>\ref VX_TYPE_INT32</tt> scalar. When Threshold On is set, for a given query, MCH returns that match, if distance is more than the threshold.
 * \return <tt>\ref vx_node</tt>.
 * \retval  vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \note For more information on debug mode and output format in debug mode, please refer to the MCH HWA documentation.
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAMCH4Node(vx_graph graph,
        vx_array query_array0,
        vx_array query_array1,
        vx_array query_array2,
        vx_array query_array3,
        vx_array db_array,
        vx_array output_array0,
        vx_array output_array1,
        vx_array output_array2,
        vx_array output_array3,
        vx_scalar dist_mode,
        vx_scalar vector_size,
        vx_scalar num_nearest,
        vx_scalar output_mode,
        vx_scalar thresh_on,
        vx_scalar thresh_val);

/*! \brief [Graph] Creates a Gaussian Filter Node.
 * \param [in] graph The reference to the graph.
 * \param [in] input The input image in <tt>\ref VX_DF_IMAGE_U8</tt> format.
 * \param [out] output The output image in <tt>\ref VX_DF_IMAGE_U8</tt> format.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAGaussian5x5Node(vx_graph graph, vx_image input, vx_image output);

/**
 * TODO:
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAWIGMeshComputationNode(vx_graph  graph,
				vx_image  src_img_y,
				vx_image  src_img_uv,
				vx_image  src_img_v,
				vx_array  mesh_input,
				vx_scalar tile_width,
				vx_scalar tile_height,
				vx_scalar log_mspace,
				vx_scalar interpolation,
				vx_scalar interpolation_uv,
				vx_scalar mesh_analysis,
				vx_scalar is_new_mesh_map,
				vx_array  delta_config,
				vx_array  mesh_out_uv,
				vx_array  mesh_luma_modified,
				vx_image  dst_img_y,
				vx_image  dst_img_uv);

/**
 * TODO:
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAWIGMeshNode(vx_graph graph,
				vx_image  src_img_y,
				vx_image  src_img_uv,
				vx_image  src_img_v,
				vx_array  mesh,
				vx_array  mesh_uv,
				vx_array  delta_config,
				vx_scalar tile_width,
				vx_scalar tile_height,
				vx_scalar log_mspace,
				vx_scalar interpolation,
				vx_scalar interpolation_uv,
				vx_image  dst_img_y,
				vx_image  dst_img_uv);

/** @brief  Performs Multi-Frame Blending
 * \param[in] graph The reference to the graph.
 * \param[in] y0, u0, v0, ..., v4 Input images in <tt>\ref VX_DF_IMAGE_U8</tt> format.
 * Image dimensions as per NV12.
 * \param[in] num_frames_sclr number of frames given in input.
 * \param[in] reference_frame_index_sclr index of reference frame.
 * \param[in] motmod Motmod image in <tt>\ref VX_DF_IMAGE_U8</tt> format. Can be NULL.
 * Width and height are 1/4th of Y width and height (rounded up).
 * \param[in] sigest Sigma estimate indicating the noise level in the frame sequence.
 * \param[in] wmult Array of 4 wmult parameters (<tt>\ref VX_TYPE_INT16</tt>). Multiplication factors for computing blend weights.
 * \param[in] refweight Array of 4 refweight parameters (<tt>\ref VX_TYPE_INT16</tt>).
 * \param[in] uvmult U/V channel multiplication factor for computing blend weights.
 * Determines the contribution of UV channel towards computing frame difference.
 * \param[in] pgain Array of 36 integers -- four 3x3 matrices stored in column-major order (<tt>\ref VX_TYPE_INT16</tt>).
 * \param[in] pgain Array of 12 integer -- four 3-element vectors (<tt>\ref VX_TYPE_INT16</tt>).
 * \param[in] mot_slope Motion blend slope in computing motion map.
 * \param[in] count_thr
 * \param[in] log_bwidth
 * \param[in] out_roi_offset_x Output ROI offset X (<tt>\ref VX_TYPE_UINT16</tt>).
 * \param[in] out_roi_offset_y Output ROI offset Y (<tt>\ref VX_TYPE_UINT16</tt>).
 * \param[out] out_y Y plane of output in <tt>\ref VX_DF_IMAGE_U8</tt> format
 * \param[out] out_u U plane of output in <tt>\ref VX_DF_IMAGE_U8</tt> format
 * \param[out] out_v V plane of output in <tt>\ref VX_DF_IMAGE_U8</tt> format
 * \param[out] out_mmap Motion Map output in <tt>\ref VX_DF_IMAGE_U8</tt> format
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVAMFBNode(vx_graph graph,
	vx_image y0,
	vx_image u0,
	vx_image v0,
	vx_image y1,
	vx_image u1,
	vx_image v1,
	vx_image y2,
	vx_image u2,
	vx_image v2,
	vx_image y3,
	vx_image u3,
	vx_image v3,
	vx_image y4,
	vx_image u4,
	vx_image v4,
	vx_scalar num_frames_sclr,
	vx_scalar reference_frame_index_sclr,
	vx_image motmod,
	vx_scalar mot_mult,
	vx_scalar sigest,
	vx_array wmult,
	vx_array refweight,
	vx_scalar uvmult,
	vx_array pgain,
	vx_array poffset,
	vx_scalar mot_slope,
	vx_scalar count_thr,
	vx_scalar log_bwidth,
	vx_scalar out_roi_offset_x,
	vx_scalar out_roi_offset_y,
	vx_image out_y,
	vx_image out_u,
	vx_image out_v,
	vx_image mmap);

/*! \brief [Graph] Creates a Bundle Adjustment Node.
 * \param [in] graph The reference to the graph.
 * \param [in] obs_graph The struct that holds the data of the BAX.
 * \param [in] ba_parameter The struct with parameters for the BAX.
 * \param [in] lm_loop_config The struct with loop configuration.
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIVABAXNode(vx_graph graph,
				vx_array obs_graph,
				vx_array ba_parameter,
				vx_array lm_loop_config);

/**
* TODO:
*/
VX_API_ENTRY vx_node VX_API_CALL vxIVAWMENode(vx_graph graph,
    /* INPUTS */
    vx_image    input0_y,
    vx_image    input0_u,
    vx_image    input0_v,
    vx_image    input1_y,
    vx_image    input1_u,
    vx_image    input1_v,
    vx_image    input2_y,
    vx_image    input2_u,
    vx_image    input2_v,
    vx_image    input3_y,
    vx_image    input3_u,
    vx_image    input3_v,
    vx_image    input4_y,
    vx_image    input4_u,
    vx_image    input4_v,

    /* WME params */
    vx_scalar   wme_frames_number,
    vx_scalar   wme_reference_frame_index,
    vx_array    wme_delta_config,
    vx_scalar   wme_slice_width,
    vx_scalar   wme_slice_offset_x,
    vx_array    wme_affine_image_left_offset,
    vx_array    wme_affine_image_top_offset,
    vx_array    wme_input_image_left_offset,
    vx_array    wme_input_image_top_offset,
    vx_array    wme_scaling_ratio,

    /* WIG params */
    vx_matrix   wig_matrix0,
    vx_matrix   wig_matrix1,
    vx_matrix   wig_matrix2,
    vx_matrix   wig_matrix3,
    vx_matrix   wig_matrix4,
    vx_scalar   wig_interpolation_y,
    vx_scalar   wig_interpolation_uv,

    /* MFB params */
    vx_scalar   mfb_mot_mult,
    vx_image    mfb_motion_image,
    vx_scalar   mfb_sigma_estimate,             // SIGEST
    vx_array    mfb_blend_weights,
    vx_array    mfb_reference_weights,          // REF_WEIGHT
    vx_scalar   mfb_uv_multiplication_factor,   // UVMULT
    vx_array    mfb_photometric_gains,
    vx_array    mfb_photometric_offsets,
    vx_scalar   mfb_motion_blend_slope,         // SLOPE
    vx_scalar   mfb_histogram_threshold,        // COUNT_THR
    vx_scalar   mfb_histogram_bin_width_log,    // LOG_BINWIDTH

    /* ENF params */
    vx_matrix   enf_config_params,
    vx_scalar   mot_en,

    /* OUTPUTS */
    vx_image    out_y,
    vx_image    out_u,
    vx_image    out_v);

VX_API_ENTRY vx_node VX_API_CALL vxIVACopyImageNode(vx_graph graph,
    vx_image    input,
    vx_image    output);

/** @brief  [Immediate] Invokes an immediate Corner Score Computation for each pixel in the image.
 * Supports only two modes namely Harris  Score or Minimum Eigen Value Score
 *
 * \param [in] context The reference to the overall context.
 * \param [in] img The input <tt>\ref VX_DF_IMAGE_U8</tt> image.
 * \param [in] use_harris A <tt>\ref VX_TYPE_INT32</tt> value describing the method for score computation.
 * Supports two modes. Harris and Eigen scores. 0 - Min Eigen Value, 1 - Harris.
 * \param [in] harris_k A <tt>\ref VX_TYPE_INT32</tt> value describing the harris_k for score computation. Value should be calculated as shown below.
 *  harris_k = floor(harris_k_float * 2 ^ 15), where 0.01 < k < 0.1
 * \param [in] window_size Block size to be considered for Score computation. Use a <tt>\ref VX_TYPE_INT32</tt> value to describe the window size.
 * Supported window_sizes are 3, 5, 7, 9, 11, 13, 15.
 * \param [in] output_mode Harris Score is represented in a 16-bit proprietary float or 32-bit IEEE754 float format. Output Use a <tt>\ref VX_TYPE_INT32</tt> value
 * to describe the output mode. Supports two output modes. 1 - 32bit, 0 - 16bit.
 * 16-bit proprietary float is of the following format. Sign - 1, Exponent - 6, Significand - 9.
 * \param [out] output A <tt>\ref vx_image</tt> with each pixel describing the scores of corresponding pixel of the image. Data type of the image depends
 * output_mode.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVACornerScore(vx_context context,
        vx_image img,
        vx_scalar use_harris,
        vx_scalar harris_k,
        vx_scalar window_size,
        vx_scalar output_mode,
        vx_image out);

/** @brief [Immediate] Invokes an immediate Local Maxima and Minima detection on given input image.
 * \param [in] context The reference to the overall context.
 * \param[in] img A <tt>\ref vx_image</tt> image with either of the following data types.
 * <tt>\ref VX_DF_IMAGE_U8</tt> or <tt>\ref VX_DF_IMAGE_U16</tt> or <tt>\ref VX_DF_IMAGE_S16</tt> or <tt>\ref VX_DF_IMAGE_S32</tt>.
 * \param[in] window_size Window size used for comparing the target pixel to detect if it is  maxima/minima. Supported window sizes are 3
 * and 5. Use a <tt>\ref VX_TYPE_INT32</tt> scalar to describe the window size.
 * \param[in] max_cmd Enable or Disable Maxima Comparison. 1 - Enable, 0 - Disable. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] min_cmd Enable or Disable Minima Comparison. 1 - Enable, 0 - Disable. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] strict_mode Comparsion method. 1 - Enable strict mode. Pixel must not be equal to any neighboring pixel in window 0 - Inclusive. Pixel may be equal to neighboring pixel. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] max_thresh Maxima threshold. Any pixel less than this will not be considered for maxima comparison. Use a
 * <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] min_thresh Minima threshold. Any pixel greater than this will not be considered for minima comparison.
 * Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[in] sign mode. Input img pixel is regarded as 0 - Unsigned, 1 - Signed, 2- Signed Magnitude.
 * Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * \param[out] out Output array with each element describing about the detected maxima or minima pixels. Each output pixel is 64-bit in the following format.
 * Bit 63 - denotes if it is maxima or minima, Bits 48 - 62 - denote the X coordinate of pixel, Bit 47 - Don't Care, Bits 32 - 46 - denote the Y Coordinate of pixel & Bits 0 to 31 - denote the pixel value at (X, Y)
 * \param[out] num_out Number of detected maxima or minima pixels.
 * Use a <tt>\ref VX_TYPE_SIZE</tt> scalar.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVALocalMinMax(vx_context context,
        vx_image img,
        vx_scalar window_size,
        vx_scalar max_cmd,
        vx_scalar min_cmd,
        vx_scalar strict_mode,
        vx_scalar max_thresh,
        vx_scalar min_thresh,
        vx_scalar sign_mode,
        vx_array  out);

/**
 * @brief [Immediate] Invokes an immediate Edge Enhanced Noise Filter
 * \param [in] context The reference to the overall context.
 * \param[in] img The input image is 8-bit unsigned
 * \param[in] mmap The input motion map is a 8-bit unsigned
 * \param[in] config_params Threshold Configuration Parameters. A total of 55 Parameters.
 * \param[in] 00_THR_SB0_PARAM_0 Threshold parameter 0 for sub-band 0. Q12.0 (0 to 4095)
 * \param[in] 01_THR_SB0_PARAM_1 Threshold parameter 1 for sub-band 0. Q12.0 (0 to 4095)
 * \param[in] 02_THR_SB1_PARAM_0 Threshold parameter 0 for sub-band 1. Q12.0 (0 to 4095)
 * \param[in] 03_THR_SB1_PARAM_1 Threshold parameter 1 for sub-band 1. Q12.0 (0 to 4095)
 * \param[in] 04_THR_SB2_PARAM_0 Threshold parameter 0 for sub-band 2. Q12.0 (0 to 4095)
 * \param[in] 05_THR_SB2_PARAM_1 Threshold parameter 1 for sub-band 2. Q12.0 (0 to 4095)
 * \param[in] 06_THR_SB3_PARAM_0 Threshold parameter 0 for sub-band 3. Q12.0 (0 to 4095)
 * \param[in] 07_THR_SB3_PARAM_1 Threshold parameter 1 for sub-band 3. Q12.0 (0 to 4095)
 * \param[in] 08_THR_SB4_PARAM_0 Threshold parameter 0 for sub-band 4. Q12.0 (0 to 4095)
 * \param[in] 09_THR_SB4_PARAM_1 Threshold parameter 1 for sub-band 4. Q12.0 (0 to 4095)
 * \param[in] 10_THR_SB5_PARAM_0 Threshold parameter 0 for sub-band 5. Q12.0 (0 to 4095)
 * \param[in] 11_THR_SB5_PARAM_1 Threshold parameter 1 for sub-band 5. Q12.0 (0 to 4095)
 * \param[in] 12_SLP_SB0_PARAM_0 Positive slope parameter 0 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 13_SLP_SB0_PARAM_1 Positive slope parameter 1 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 14_SLP_SB1_PARAM_0 Positive slope parameter 0 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 15_SLP_SB1_PARAM_1 Positive slope parameter 1 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 16_SLP_SB2_PARAM_0 Positive slope parameter 0 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 17_SLP_SB2_PARAM_1 Positive slope parameter 1 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 18_SLP_SB3_PARAM_0 Positive slope parameter 0 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 19_SLP_SB3_PARAM_1 Positive slope parameter 1 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 20_SLP_SB4_PARAM_0 Positive slope parameter 0 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 21_SLP_SB4_PARAM_1 Positive slope parameter 1 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 22_SLP_SB5_PARAM_0 Positive slope parameter 0 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 23_SLP_SB5_PARAM_1 Positive slope parameter 1 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 24_SLN_SB0_PARAM_0 Negative slope parameter 0 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 25_SLN_SB0_PARAM_1 Negative slope parameter 1 for sub-band 0. Q12.0 (0 to 256)
 * \param[in] 26_SLN_SB1_PARAM_0 Negative slope parameter 0 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 27_SLN_SB1_PARAM_1 Negative slope parameter 1 for sub-band 1. Q12.0 (0 to 256)
 * \param[in] 28_SLN_SB2_PARAM_0 Negative slope parameter 0 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 29_SLN_SB2_PARAM_1 Negative slope parameter 1 for sub-band 2. Q12.0 (0 to 256)
 * \param[in] 30_SLN_SB3_PARAM_0 Negative slope parameter 0 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 31_SLN_SB3_PARAM_1 Negative slope parameter 1 for sub-band 3. Q12.0 (0 to 256)
 * \param[in] 32_SLN_SB4_PARAM_0 Negative slope parameter 0 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 33_SLN_SB4_PARAM_1 Negative slope parameter 1 for sub-band 4. Q12.0 (0 to 256)
 * \param[in] 34_SLN_SB5_PARAM_0 Negative slope parameter 0 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 35_SLN_SB5_PARAM_1 Negative slope parameter 1 for sub-band 5. Q12.0 (0 to 256)
 * \param[in] 36_CORING_THR_EDGE_M Coring threshold for edge M. Q12.0 (0 to 255)
 * \param[in] 37_CORING_THR_EDGE_S Coring threshold for edge S. Q12.0 (0 to 255)
 * \param[in] 38_CORING_SLP_EDGE_M Coring slope for edge M. Q12.0 (0 to 1024)
 * \param[in] 39_CORING_SLP_EDGE_S Coring slope for edge S. Q12.0 (0 to 1024)
 * \param[in] 40_HALO_THR_EDGE_M Halo threshold for edge M. Q12.0 (0 to 1023)
 * \param[in] 41_HALO_THR_EDGE_S Halo threshold for edge S. Q12.0 (0 to 1023)
 * \param[in] 42_HALO_SLP_EDGE_M Halo slope for edge M. Q12.0 (0 to 1023)
 * \param[in] 43_HALO_SLP_EDGE_S Halo slope for edge S. Q12.0 (0 to 1023)
 * \param[in] 44_HALO_GNP_EDGE_M Halo positive gain for edge M. Q12.0 (0 to 1023)
 * \param[in] 45_HALO_GNP_EDGE_S Halo positive gain for edge S. Q12.0 (0 to 1023)
 * \param[in] 46_HALO_GNN_EDGE_M Halo negative gain for edge M. Q12.0 (0 to 1023)
 * \param[in] 47_HALO_GNN_EDGE_S Halo negative gain for edge S. Q12.0 (0 to 1023)
 * \param[in] 48_BRT_ADPT0_THRESHOLD Brightness adaptive threshold. Q12.0 (0 to 255)
 * \param[in] 49_BRT_ADPT1_SLOPE Brightness adaptive slope.  Q12.0 (0 to 255)
 * \param[in] 50_BRT_ADPT2_GAIN Brightness adaptive gain.  Q12.0 (0 to 255)
 * \param[in] 51_TOT_GAIN_M_PARAM_0 Total gain parameter 0 for edge M. Q12.0 (0 to 4095)
 * \param[in] 52_TOT_GAIN_M_PARAM_1 Total gain parameter 1 for edge M. Q12.0 (0 to 4095)
 * \param[in] 53_TOT_GAIN_S_PARAM_0 Total gain parameter 0 for edge S. Q12.0 (0 to 4095)
 * \param[in] 54_TOT_GAIN_S_PARAM_1 Total gain parameter 1 for edge S. Q12.0 (0 to 4095)
 * \param[out] out Output image 8 bit unsigned.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVAENF(vx_context context,
        vx_image  img,
        vx_image  mmap,
        vx_matrix config_params,
        vx_scalar out_roi_offset_x,
        vx_scalar out_roi_offset_y,
        vx_image  out,
        vx_bool mot_en);

/** @brief [Immediate] Invokes an immediate warping on the given input image using transform matrix.
 * \param [in] context The reference to the overall context.
 * \param[in] img The input is 8-bit image.
 * \param[in] affine_mat Coefficients of the 8 element transformation matrix, using which affine or perspective transform is performed on the input image
 * Transformation matrix is an 8 element array {a, b, c, d, e, f, g, h}; a,b,d,e,g,h are in Q11.20 format and c, e are in Q15.16
 * (x,y) is the input pixel
 * (u,v) is the output pixel
 * Mapping of output to input pixels is as follows:
 * u = (ax+by+c)/(gx+hy+1)  ;  v = (dx+ey+f)/(gx+hy+1)
 * \param[in] inter_mode Interpolation mode. Supports following modes: 0- Nearest Neighbor, 1 - Bilinear, 2 -Bicubic 3 - Bayer (Expects input and output image in 8-bit bayer format)
 * \param[out] out Output image after applying affine transformation on input image.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVAWIG(vx_context context,
        vx_image img,
        vx_scalar wmode,
        vx_matrix  affine_mat,
        vx_array  mesh,
        vx_scalar log_mspace,
        vx_scalar inter_mode,
	vx_scalar frame_mesh_en,
        vx_image out);

/**
 * @brief [Immediate] Invokes an immediate Lucas Kanade Tracking from one image to another image on a specified level.
 * \param [in] context The reference to the overall context.
 * \param[in] ref_img The reference <tt>\ref VX_DF_IMAGE_U8 </tt> image.
 * \param[in] trk_img The tracking <tt>\ref VX_DF_IMAGE_U8 </tt> image on which the points are to the tracked.
 * \param[in] ref_points A <tt>\ref VX_TYPE_UINT64</tt> type array containing the points of the reference image to be tracked.
 * Each point is described in a 64-bit format. A 64-bit element contains reference x and y coordinates in upper 32-bits and initial track point estimate in
 * the lower 32-bits. All the coordinates should be in Q12.4 format.
 * \image html lkt.jpg
 * \param[in] window_size A <tt>\ref VX_TYPE_INT32</tt> scalar. Width the size of the tracking window at each iteration.
 * Supported window sizes are 5, 7, 9, 15, and 21.
 * \param[in] num_iters  A <tt>\ref VX_TYPE_INT32</tt> scalar. Maximum iterations before termination. Supported range is 1-255.
 * \param[in] min_step Minimum displacement for termination. Displacement vector (hhx, hhy) is computed in Q3.4 format.
 * Iteration terminate when (hhx*hhx + hhy*hhy < min_step). Supported minimum step size is  0 - 255. Use a <tt>\ref VX_TYPE_INT32</tt> scalar.
 * If minimum step size is < 0, then the min_step is not taken into criteria for LKT termination.
 * \param[in] gradient_type Two types of gradients are supported. Sobel and Scharr. 0 - Sobel and 1 - Scharr. Use a <tt>\ref VX_TYPE_INT32</tt> scalar/
 * \param[in] output_mode Supports two output modes. 0 - default mode. 1 - debug mode.
 * \param[in] lkt_level A <tt>\ref VX_TYPE_INT32</tt> scalar describing the level of the reference and tracking images in the pyramidal LKT.
 * 0 - Full resolution image, 1 - Half resolution in both width and height and so on. Input reference and tracking are expected to be scaled to this level,
 * while input ref_points are described with respect to level 0 i.e. full resolution image. Using the lkt_level, ref_points are scaled down accordingly and used for
 * tracking. Output track points are again scaled up to the full resolution.
 * \param[out] trk_points A <tt>\ref VX_TYPE_UINT64</tt> type array with the tracked points.
 * In default output mode, if the lkt_level is 0, only the tracked points are dumped, otherwise for the points which cannot be tracked, output will be equal to
 * input. The format of the tracked points will be same as ref_points (Refer ref_points for format description).
 * If the output_mode is set to debug, debug info will be dumped for all the points along with the tracked locations. In debug mode, the bits 60-63 will describe a
 * flag about the error, coordinates of tracked point will be of Q12.4 format and will be located at 32, 0 bit respectively. If the flag value is 4, then the point
 * is tracked, else otherwise.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVALKTracker(vx_context context,
        vx_image ref_img,
        vx_image trk_img,
        vx_array ref_points,
        vx_scalar window_size,
        vx_scalar max_iters,
        vx_scalar min_step,
        vx_scalar gradient_type,
        vx_scalar output_mode,
        vx_scalar lkt_level,
        vx_array trk_points);

/**
 * @brief [Immediate] Invokes an immediate ORB keypoint detection and their descriptors on an image.
 * Computes FAST keypoints, orientation and their rBRIEF descriptors in an image. Orientation computed in a given diameter. Maximum value of
 * diameter is 35. IVA ORB leaves a border of 21 on every side. So the image provided should be of dimensions atleast 43x43.
 * \param [in] context The reference to the overall context.
 * \param[in] image A <tt>\ref VX_DF_IMAGE_U8 </tt> image.
 * \param[in] diameter Diameter for Keypoints Orientation Computation. Use a <tt>\ref VX_TYPE_INT32</tt> value. Supported range is 1 - 35.
 * \param[in] fast_th Keypoint threshold for FAST response. Use a <tt>\ref VX_TYPE_INT32</tt> value. Value should be of 0-255.
 * \param[in] harris_th Keypoints threshold for Harris response. Use a <tt>\ref VX_TYPE_FLOAT32</tt> value.
 * \param[in] scale_x Scale factor for X-coordinate of Keypoint and should be in Q7.18 format. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] scale_y Scale factor for Y-coordinate of Keypoint and should be in Q7.18 format. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[in] metadata Metadata to be filled in the Keypoint structure as shown below. Use a <tt>\ref VX_TYPE_INT32</tt> value.
 * \param[out] keypoints A <tt>\ref vx_array</tt> containing keypoints. Each keypoint is a <tt>\ref VX_TYPE_UINT128</tt> value as described below.
 * \image html orb_keypoint.jpg
 * \param[out] descriptors A <tt>\ref vx_array</tt> containing descriptors. Each descriptor is 256-bit binary descriptor. Data type of <tt>\ref vx_array</tt>
 * holding the descriptors is of type <tt>\ref VX_TYPE_UINT256</tt> type.
 * \return <tt>\ref vx_node</tt>.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVAOrb(vx_context context,
		vx_image	image,
		vx_scalar	diameter,
		vx_scalar	fast_th,
		vx_scalar	harris_en,
		vx_scalar	harris_th,
		vx_scalar	scale_x,
		vx_scalar	scale_y,
		vx_scalar	metadata,
		vx_array	keypoints,
		vx_array	descriptors,
		vx_scalar	nms_size,
		vx_scalar	int_fast_th);

/** @brief [Immediate] Invokes an immediate Upscaling/Downscaling on the given input image with user specified scaler coefficients
 * \param [in] context The reference to the overall context.
* \param[in] in <tt>\ref VX_DF_IMAGE_U8 </tt> The input is 8/16-bit image.
* \param[in] scale <tt>\ref VX_TYPE_FLOAT32</tt> Scale factor by which input image is scaled. Specify either dst_width/height or scale. Not both.
* \param[in] scl_mode <tt>\ref VX_TYPE_INT32</tt> Scaler operation mode: 0 - scaling or 1 - general 2D filtering
* \param[in] interpolation <tt>\ref VX_TYPE_INT32</tt> Type of interpolation to be done (=5, 4, 3, or 2)
*                        Supports 4 different kernel size: Gaussian 5x5, Bicubic 4x4, Gaussian 3x3, Bilinear 2x2
*                        Scaling mode: 2x2, 3x3, 4x4, 5x5
*                        General 2D filtering: 3x3, 5x5
* \param[in] scl_coeff <tt>\ref VX_TYPE_ARRAY</tt> Coefficients for 32 Phases. Size = (interpolation x 32)
* \param[in] v_offset <tt>\ref VX_TYPE_INT32</tt> vertical offset
* \param[in] h_offset <tt>\ref VX_TYPE_INT32</tt> horizontal offset
* \param[out]   out <tt>\ref VX_DF_IMAGE_U8 </tt>   Output image in 8/16-bit format after applying scaling on input image.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVAScaler(vx_context context,
        vx_image  in,
        vx_scalar scale,
        vx_scalar scl_mode,
        vx_scalar interpolation,
        vx_matrix  scl_coeff,
        vx_scalar v_offset,
        vx_scalar h_offset,
        vx_image  out);

/** @brief [Immediate] Invokes an immediate Spatial Noise Reduction via Bilateral Filtering (used as Pre Processing block for ENF)
 * \param [in] context The reference to the overall context.
 * \param[in] img The input image is <tt>\ref VX_DF_IMAGE_YUV4 </tt> (YUV 444 Planar Image)
 * \param[out] out The Output image <tt>\ref VX_DF_IMAGE_U8 </tt>
 * \param[in] width Width of the input image
 * \param[in] height Height of the input image
 * \param[in] pthres_params A <tt>\ref VX_TYPE_UINT8</tt> type array containing threshold Parameters for luma, cb, cr.
 * Pass NULL to use default Values.
 * \paral[in] sweights_params A <tt>\ref VX_TYPE_UINT8</tt> type array containing weights for spatial filtering.
 * Pass NULL to use default Values.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVAENFP(vx_context context,
        vx_image  img,
        vx_scalar width,
        vx_scalar height,
        vx_array  pthres_params,
        vx_array  sweights_params,
        vx_image  out);

/**
 * @brief [Immediate] Invokes an immediate Query search. For a given Database and Querybase, MCH module finds the maximum of 3 Nearest neighbors and
 * returns the matchNum, index and disatnce for each Query.
 * \param [in] context The reference to the overall context.
 * \param[in] query_array Querybase Array.
 * \param[in] db_array Database Array.
 * \param[in] output_array A <tt>\ref VX_TYPE_CHAR</tt> type Output array to write MatchNum, Index and Distance for each query.
 * \param[in] dist_mode A <tt>\ref VX_TYPE_INT32</tt> scalar holds Distance calculation mode. Supports BINARY(0) and REAL(1) modes.
 * \param[in] vector_size A <tt>\ref VX_TYPE_INT32</tt> scalar holds Database, Querybase input dimension. Supports 128, 256 and 512 (in bits) in BINARY mode, 16n (1<=n<=8) bytes in REAL mode.
 * \param[in] num_nearest A <tt>\ref VX_TYPE_INT32</tt> scalar. MCH module returns maximum of 3 nearest neighbors and match_num(1 to 3) is used to configure how many nearest neighbors required.
 * \param[in] output_mode A <tt>\ref VX_TYPE_INT32</tt> scalar holds Output mode. In '0' mode, MCH module returns MatchNum(1 byte) and Index(1 byte) for each query.
 * whereas in output mode '1', MCH returns MatchNum(1 byte), Index(1 byte) and Distance(2 byte) for each query.
 * \param[in] thresh_on A <tt>\ref VX_TYPE_INT32</tt> scalar to set/reset Threshold On. describing the level of the reference and tracking images in the pyramidal LKT.
 * \param[in] thresh_val A <tt>\ref VX_TYPE_INT32</tt> scalar. When Threshold On is set, for a given query, MCH returns that match, if distance is more than the threshold.
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 * \retval * An error occurred. See <tt>\ref vx_status_e</tt>.
 */
VX_API_ENTRY vx_status VX_API_CALL vxuIVAMCH(vx_context context,
        vx_array query_array,
        vx_array db_array,
        vx_array output_array,
        vx_scalar dist_mode,
        vx_scalar vector_size,
        vx_scalar num_nearest,
        vx_scalar output_mode,
        vx_scalar thresh_on,
        vx_scalar thresh_val);

/*! \brief extra kernels to support SCore's mismatched parameters
 * \param [in] context The reference to the context.
 * \param [in] input input image
 * \param [out] outbuf0 The output image
 * \param [out] outbuf1 The output image
 * \param [out] outbuf2 The output image
 * \param [out] outbuf3 The output image
 */
VX_API_ENTRY vx_node VX_API_CALL vxsChannelsExtractNode(vx_graph graph,
                             vx_image input,
                             vx_image outbuf0,
                             vx_image outbuf1,
                             vx_image outbuf2,
                             vx_image outbuf3);

/*! \brief extra kernels to support SCore's mismatched parameters
 * \param [in] context The reference to the context.
 * \param [in] input input image
 * \param [out] outbuf The output image for score
 */
VX_API_ENTRY vx_node VX_API_CALL vxsHistogramNode(vx_graph graph,
                             vx_image input,
                             vx_image outbuf);

VX_API_ENTRY vx_node VX_API_CALL vxConvertToHistogramNode(vx_graph graph,
                             vx_image input,
                             vx_distribution distribution);
/*
 * \param [in] tmp tem image
 * \param [out] output The output image
 * \param [in] strength_thresh
 * \param [in] nonmax_suppression
 */
VX_API_ENTRY vx_node VX_API_CALL vxsFastCornersNode(vx_graph graph,
                vx_image input,
                vx_image tmp,
                vx_image output,
                vx_scalar strength_thresh,
                vx_scalar nonmax_suppression);

VX_API_ENTRY vx_node VX_API_CALL vxConvertToFastCornNode(vx_graph graph,
                vx_image input,
                vx_array corners,
                vx_scalar num_corners);

/*! \brief extra kernels to support SCore's mismatched parameters
 * \param [in] context The reference to the context.
 * \param [in] input input image
 * \param [in] input input image for score
 * \param [out] outbuf The output image for score
 */
VX_API_ENTRY vx_node VX_API_CALL vxsTableLookupNode(vx_graph graph,
        vx_image input,
        vx_image lut,
        vx_image output);

VX_API_ENTRY vx_node VX_API_CALL vxConvertToLookUpTableNode(vx_graph graph,
        vx_lut lut,
        vx_image output);

/*! \brief extra kernels to support SCore's mismatched parameters
 * \param [in] context The reference to the context.
 * \param [in] input input image
 * \param [in] input input image for score
 * \param [out] outbuf The output image for score
 */
VX_API_ENTRY vx_node VX_API_CALL vxsScoreEqualizeHistNode(vx_graph graph,
        vx_image input,
        vx_image hist,
        vx_image integralline,
        vx_image output);

/*! \brief extra kernels to support SCore's mismatched parameters
 * \param [in] context The reference to the context.
 * \param [in] input input image
 * \param [out] outbuf The output image for score
 * \param [out] outbuf The output image for score
 */
VX_API_ENTRY vx_node VX_API_CALL vxsScoreMeanStdDevNode(vx_graph graph,
        vx_image input,
        vx_image mean,
        vx_image stddev);

VX_API_ENTRY vx_node VX_API_CALL vxConvertToMeanStdDevNode(vx_graph graph,
	vx_image input,
        vx_image sc_mean,
        vx_image sc_stddev,
        vx_scalar mean,
        vx_scalar stddev);

VX_API_ENTRY vx_node VX_API_CALL vxsAlphaBlenderNode(vx_graph graph,
		vx_image input1,
		vx_image input2,
		vx_image input3,
		vx_image output);

VX_API_ENTRY vx_node VX_API_CALL vxsLscNode(vx_graph graph,
		vx_image input0,
		vx_image input1,
		vx_image gain,
		vx_image output0,
		vx_image output1);

/*! \brief [Immediate] Invokes a immediate Gaussian 5x5 Filter.
 * \param [in] context The reference to the context.
 * \param [in] input The input image in <tt>\ref VX_DF_IMAGE_U8</tt> format.
 * \param [out] output The output image in <tt>\ref VX_DF_IMAGE_U8</tt> format.
 * \ingroup group_vision_function_gaussian_image
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS Success
 */
VX_API_ENTRY vx_status VX_API_CALL vxuNeonGaussian5x5(vx_context context,
		vx_image input,
		vx_image output);


/**
 * @ brief Computes the delta configuration for the WME nodes
 * \param[in] graph The reference to the graph.
 * \param[in] src_width width of source image.
 * \param[in] src_height height of source image.
 * \param[in] dst_width width of the destination image
 * \param[in] dst_height height of the destination image
 * \param[in] affine matrice of frame 0
 * \param[in] affine matrice of frame 1
 * \param[in] affine matrice of frame 2
 * \param[in] affine matrice of frame 3
 * \param[in] affine matrice of frame 4
 * \param[out] Array of the delta config array
 * \param[in] Get affine image left offset (no use, as of now)
 * \param[in] Get affine image top offset (no use, as of now)
 * \param[in] Input image left offset (no use, as of now)
 * \param[in] Input image top offset (no use, as of now)
 * \param[in] zoom factor
 * \param[in] number of blend frames
 * \param[in] Array of WIG output Y sizes
 * \param[in] Array of WIG output C sizes
 * \param[in] Array of slice width
 * \param[in] Array of slice offset x
 * \param[in] ref frame index for Blend
 * \param[in] number of slices in a frame
 * \return <tt>\ref vx_node</tt>.
 * \retval vx_node A node reference. Any possible errors preventing a successful creation should be checked using <tt>\ref vxGetStatus</tt>
 */
VX_API_ENTRY vx_node VX_API_CALL vxIvaWMEComputationNode(vx_graph  graph,
                                                         vx_array  src_width,
                                                         vx_array  src_height,
                                                         vx_scalar dst_width,
                                                         vx_scalar dst_height,
                                                         vx_matrix matrix0,
                                                         vx_matrix matrix1,
                                                         vx_matrix matrix2,
                                                         vx_matrix matrix3,
                                                         vx_matrix matrix4,
                                                         vx_delay delta_configs,
                                                         vx_array ga_roi_left,
                                                         vx_array ga_roi_top,
                                                         vx_array in_roi_left,
                                                         vx_array in_roi_top,
                                                         vx_array warp_zoom_r,
                                                         vx_scalar num_blend_frames,
                                                         vx_array wig_out_buf_size_Y,
                                                         vx_array wig_out_buf_size_C,
                                                         vx_array slice_width,
                                                         vx_array slice_offset_x,
                                                         vx_scalar ref_frame_idx,
                                                         vx_scalar num_slices);

#ifdef __cplusplus
}
#endif

#endif
