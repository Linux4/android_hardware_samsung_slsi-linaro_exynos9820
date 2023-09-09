/**
 * \copyright Copyright 2015-16 Samsung Research America (SRA), MPI Lab.
 * All Rights Reserved.
 * Samsung Confidential and Proprietary.
 *
 */

#ifndef VX_MPI_EXT_H
#define VX_MPI_EXT_H

#include <VX/vx.h>

#ifdef __cplusplus
extern "C" {
#endif

#if (VX_VERSION < (VX_VERSION_MAJOR(1) | VX_VERSION_MINOR(1)))
/*
 * vx_object_array is used to help mark where we will use delays as non-aging containers for objects
 * This will be replaced by the official vx_object_array in OpenVX 1.1, for now, it is nothing more
 * than just an alias for vx_delay.
 */
typedef vx_delay vx_object_array;

static vx_object_array vxCreateObjectArray(vx_context context, vx_reference exemplar, vx_size count)
{
    return vxCreateDelay(context, exemplar, count);
}
static vx_status vxReleaseObjectArray(vx_object_array *arr)
{
    return vxReleaseDelay(arr);
}
static vx_reference vxGetObjectArrayItem(vx_object_array arr, vx_size index)
{
    return vxGetReferenceFromDelay(arr, index);
}
static vx_status vxQueryObjectArray(vx_object_array arr, vx_enum attribute, void *ptr, vx_size size)
{
    return vxQueryDelay(arr, attribute, ptr, size);
}

#define VX_TYPE_OBJECT_ARRAY VX_TYPE_DELAY
#define VX_OBJECT_ARRAY_ATTRIBUTE_ITEMTYPE VX_DELAY_ATTRIBUTE_TYPE
#define VX_OBJECT_ARRAY_ATTRIBUTE_NUMITEMS VX_DELAY_ATTRIBUTE_SLOTS

#endif

/*
 * We should move this definition to vx_ext_samsung.h (each lab will need to be unique to avoid
 * collision)
 */
#define VX_LIBRARY_MPI (0x3)

/*!
 * \brief The list of MPI user mode kernels.
 */
/*
enum vx_kernel_mpi_ext_e {
    VX_KERNEL_MPI_KERNEL_START = VX_KERNEL_BASE(VX_ID_SAMSUNG, VX_LIBRARY_MPI) + 0x0,
    VX_KERNEL_MPI_ACCUMULATEWEIGHTMAPPED,
    VX_KERNEL_MPI_ADDNOISEMAP,
    VX_KERNEL_MPI_BLENDFRAMES,
    VX_KERNEL_MPI_BLURMAP,
    VX_KERNEL_MPI_CONCATARRAY,
    VX_KERNEL_MPI_FRAMEFUSION,
    VX_KERNEL_MPI_GETAFFINE,
    VX_KERNEL_MPI_GETAFFINEMULTI,
    VX_KERNEL_MPI_INITACCUMULATEWEIGHTMAPPED,
    VX_KERNEL_MPI_LKTMULTI,
    VX_KERNEL_MPI_MOTIONDENOM,
    VX_KERNEL_MPI_MOTIONMAP,
    VX_KERNEL_MPI_NOISEMAP,
    VX_KERNEL_MPI_REFSELECT,
    VX_KERNEL_MPI_SELECTFEATURES,
    VX_KERNEL_MPI_SUBPIX,
    VX_KERNEL_MPI_UVAFFINE,
    VX_KERNEL_MPI_ORBMCHGETAFFINE,
    // up to 0xFFF kernel enums can be created.
};
*/
/** @brief Calculate a noisemap from an original and filtered image
 *
 * Noisemap is a difference image between an original and noise filtered image that is scaled and
 * thresholded
 *
 * @param[in] graph The reference to the graph.
 * @param[in] orig An unfiltered input image in <tt>\ref VX_DF_IMAGE_U8</tt> format
 * @param[in] filtered Filtered version of \ref orig in <tt>\ref VX_DF_IMAGE_U8</tt> format
 * @param[in] gain A UQ4.12 multiplier represented in <tt>\ref VX_TYPE_UINT16 </tt> format
 * @param[in] max A <tt>\ref VX_TYPE_UINT8 </tt> value between [0,127] used to threshold output
 * between [-max,max]
 * @param[out] noisemap Difference image with gain and max applied and then offset by 128 to output
 * as <tt>\ref VX_DF_IMAGE_U8</tt> format
 */
vx_node vxmpiNoiseMapNode(vx_graph graph, vx_image orig, vx_image filtered, vx_scalar gain,
        vx_scalar max, vx_image noisemap);
vx_status vxumpiNoiseMap(vx_context context, vx_image orig, vx_image filtered, vx_scalar gain,
        vx_scalar max, vx_image noisemap);

/** @brief Refines corners locations
 *
 * Finds a sub-pixel accurate location of given corner. Input corners can be offset by a rectangle
 * and then scaled before finding sub-pixel location in the input image.
 *      ptX' = (ptX + rect.start_x) * scale
 *      ptY' = (ptY + rect.start_y) * scale
 *
 * @param[in] graph The reference to the graph.
 * @param[in] orig An input image in <tt>\ref VX_DF_IMAGE_U8</tt> format to find sub-pixel location
 * @param[in] offset Rectangle in which to offset corners
 * @param[in] scale Scale value to apply after offset of corners
 * @param[in] corners Input array of VX_TYPE_KEYPOINT or VX_TYPE_SAMSUNG_KEYPOINTF objects
 * @param[out] output Output array of VX_TYPE_SAMSUNG_KEYPOINTF objects with size equal or greater than input
 * corners
 */
vx_node vxmpiCornerSubPixNode(vx_graph graph, vx_image orig, vx_rectangle_t offset,
        vx_float32 scale, vx_array corners, vx_array output);
vx_status vxumpiCornerSubPix(vx_context context, vx_image orig, vx_rectangle_t offset,
        vx_float32 scale, vx_array corners, vx_array output);

/** @brief Run LKT on multiple frames in a delay
 *
 * @param[in] graph The reference to the graph.
 * @param[in] pyramids Delay of pyramids for the frames that need to be tracked along with the reference
 * @param[in] refcorners Delay of array with element type VX_TYPE_SAMSUNG_KEYPOINTF. One will be used as the reference.
 * @param[in] index The index into pyramids and refcorners that will be used as the reference for tracking Type: vx_int32
 * @param[in] epsilon The vx_float32 scalar error for terminating the algorithm.
 * @param[in] iterations The number of iterations. Use a VX_TYPE_UINT32 scalar
 * @param[in] use_intial VX_TYPE_BOOL scalar. Only false supported at the moment.
 * @param[in] window The size of the window on which to perform the algorithm. See VX_CONTEXT_ATTRIBUTE_OPTICAL_FLOW_WINDOW_MAXIMUM_DIMENSION.
 * @param[out] trackedcorners Delay of array with element type VX_TYPE_SAMSUNG_KEYPOINTF
 */
vx_node vxmpiLKTMultiNode(vx_graph graph, vx_delay pyramids, vx_delay refcorners, vx_scalar index,
        vx_scalar epsilon, vx_scalar iterations, vx_scalar use_initial, vx_scalar window,
        vx_delay trackedcorners);
vx_status vxumpiLKTMulti(vx_context context, vx_delay pyramids, vx_delay refcorners, vx_scalar index,
        vx_scalar epsilon, vx_scalar iterations, vx_scalar use_initial, vx_scalar window,
        vx_delay trackedcorners);

/** @brief Concatenate elements in a delay of arrays into one array
 *
 * @param[in] graph The reference to the graph.
 * @param[in] input Delay of arrays containing data that will be concatenated into the output
 * @param[out] output Array of the same type as the arrays in input
 */
vx_node vxmpiConcatArrayNode(vx_graph graph, vx_delay input, vx_array output);
vx_status vxumpiConcatArray(vx_context context, vx_delay input, vx_array output);

/** @brief Filter feature points to remove outliers
 *
 * Given a delay of feature points for N number frames, filter each list removing the ones with
 * error beyond given thresholds
 *
 * @param[in] graph The reference to the graph.
 * @param[in] corners A delay of vx_array that contain VX_TYPE_KEYPOINT information
 * @param[in] index Frame number (starting from 0) to use as reference in the delay. Type: vx_int32
 * @param[in] width Width of the images the feature points were tracked. Type: vx_int32
 * @param[in] height Height of the images the feature points were tracked. Type: vx_int32
 * @param[in] crop_l Represents the left position of the tracking window used in the tracked images. Type: vx_int32
 * @param[in] crop_t Represents the top position of the tracking window used in the tracked images. Type: vx_int32
 * @param[in] crop_w Represents the width of the tracking window used in the tracked images. Type: vx_int32
 * @param[in] crop_h Represents the height of the tracking window used in the tracked images. Type: vx_int32
 * @param[in] num_x Number of regions the tracked image was split vertically. Type: vx_int32
 * @param[in] num_y Number of regions the tracked image was split horizontally. Type: vx_int32
 * @param[in] thr_pts Minimum number of points in a region needed to keep it. Type: vx_int32
 * @param[in] thr_rgn Maximum error in a region in order to keep the points. Type: vx_float32
 * @param[out] rgn_error Return the error from each region. Type: vx_object_array
 * @param[out] output Output vx_object_array of vx_array that will contain VX_TYPE_KEYPOINT information
 * corners for each frame
 */
vx_node vxmpiSelectFeaturesNode(vx_graph graph, vx_delay corners, vx_scalar index,
        vx_scalar width, vx_scalar height, vx_scalar crop_l, vx_scalar crop_t, vx_scalar crop_w,
        vx_scalar crop_h, vx_scalar num_x, vx_scalar num_y, vx_scalar thr_pts, vx_scalar thr_rgn,
        vx_object_array rgn_error, vx_object_array output);
vx_status vxumpiSelectFeatures(vx_context context, vx_delay corners, vx_scalar index,
        vx_scalar width, vx_scalar height, vx_scalar crop_l, vx_scalar crop_t, vx_scalar crop_w,
        vx_scalar crop_h, vx_scalar num_x, vx_scalar num_y, vx_scalar thr_pts, vx_scalar thr_rgn,
        vx_object_array rgn_error, vx_object_array output);


/** @brief Calculate an affine matrix from given set of key points
 *
 * Given a reference set of key points and a corresponding set of tracked key points,
 * calculate an affine matrix
 *
 * @param[in] graph The reference to the graph.
 * @param[in] ref_corners Reference set of vx_array of VX_TYPE_KEYPOINTS
 * @param[in] corners The new set of vx_array of VX_TYPE_KEYPOINTS to calculate affine matrix
 * @param[in] threshold Frame should not be used if affine error is above given threshold.
 * Type: vx_float32
 * @param[in] scale_factor VX_TYPE_FLOAT32 value giving additional scale factor to apply to affine
 * after finding frame correspondence
 * @param[out] error Affine error for this frame. Type: vx_float32
 * @param[out] affine Calcualted affine matrix to correspond the new set of points to the reference.
 * Type vx_matrix->vx_float32
 */
vx_node vxmpiGetAffineNode(vx_graph graph, vx_array ref_corners, vx_array corners,
        vx_scalar threshold, vx_scalar scale_factor, vx_scalar error, vx_matrix affine);
vx_status vxumpiGetAffine(vx_context context, vx_array ref_corners, vx_array corners,
        vx_scalar threshold, vx_scalar scale_factor, vx_scalar error, vx_matrix affine);

/** @brief Calculate an affine matrix for multiple sets of corners given set of key points
 *
 * Given a reference set of key points and some corresponding set of tracked key points,
 * calculate an affine matrix for each set
 *
 * @param[in] graph The reference to the graph.
 * @param[in] corners The vx_object_array of new set of vx_array of VX_TYPE_KEYPOINTS to calculate affine matrix
 * @param[in] index Frame number (starting from 0) to use as reference in the delay. Type: vx_int32
 * @param[in] threshold Frame should not be used if affine error is above given threshold.
 * Type: vx_float32
 * @param[in] scale_factor VX_TYPE_FLOAT32 value giving additional scale factor to apply to affine
 * after finding frame correspondence
 * @param[out] error Affine error for each frame. Type: vx_object_array of vx_float32
 * @param[out] mode Blending mode for each frame (specific for HiFi). Type: vx_object_array of vx_int32
 * @param[out] affine Calculated affine matrix to correspond the new set of points to the reference.
 * Type vx_object_array->vx_matrix->vx_float32
 */
vx_node vxmpiGetAffineMultiNode(vx_graph graph, vx_object_array corners, vx_scalar index,
        vx_scalar threshold, vx_scalar scale_factor, vx_object_array error, vx_object_array mode,
        vx_object_array affine);
vx_status vxumpiGetAffineMulti(vx_context context, vx_object_array corners, vx_scalar index,
        vx_scalar threshold, vx_scalar scale_factor, vx_object_array error, vx_object_array mode,
        vx_object_array affine);


/** @brief Calculate the motion denominator used in FrameFusion kernel
 *
 * @param[in] graph The reference to the graph.
 * @param[in] ref Image of type VX_DF_IMAGE_U8 used as reference frame
 * @param[in] nonref Image of type VX_DF_IMAGE_U8 used to estimate motion compared to the reference
 * @param[in] peak Tunes the motion estimation value for this scene Type: vx_uint16
 * @param[in] iszoom VX_TYPE_BOOL indiciting whether or not we are running a zoom usecase
 * @param[out] denom Image of type VX_DF_IMAGE_U16 whose value is used as motion denominator for
 * FrameFusion
 */
vx_node vxmpiMotionDenominatorNode(vx_graph graph, vx_image ref, vx_image nonref,
        vx_scalar peak, vx_scalar iszoom, vx_image denom);
vx_status vxumpiMotionDenominator(vx_context context, vx_image ref, vx_image nonref,
        vx_scalar peak, vx_scalar iszoom, vx_image denom);

/** @brief Calculate a motion weight map between two frames
 *
 * @param[in] graph The reference to the graph.
 * @param[in] refY VX_DF_IMAGE_U8 representing luma channel for the reference image
 * @param[in] refU VX_DF_IMAGE_U8 representing Cb channel for the reference image
 * @param[in] refV VX_DF_IMAGE_U8 representing Cr channel for the reference image
 * @param[in] nonrefY VX_DF_IMAGE_U8 representing luma channel for the new image
 * @param[in] nonrefU VX_DF_IMAGE_U8 representing Cb channel for the new image
 * @param[in] nonrefV VX_DF_IMAGE_U8 representing Cr channel for the new image
 * @param[in] denom VX_DF_IMAGE_U16 motion denominator calculated with vxmpiMotionDenominatorNode
 * @param[in] refweight Value representing no motion in the motion weight map Type: vx_uint8
 * @param[in] wmult Weight multiplier used in FrameFusion. Get value with FrameFusionCalcWMult. Type: vx_int32
 * @param[in] iszoom VX_TYPE_BOOL indiciting whether or not we are running a zoom usecase
 * @param[out] weights VX_DF_IMAGE_U8 motion weight map
 */
vx_node vxmpiFrameFusionNode(vx_graph graph, vx_image refY, vx_image refU, vx_image refV,
        vx_image nonrefY, vx_image nonrefU, vx_image nonrefV, vx_image denom, vx_scalar refweight,
        vx_scalar wmult, vx_scalar iszoom, vx_image weights);
vx_status vxumpiFrameFusion(vx_context context, vx_image refY, vx_image refU, vx_image refV,
        vx_image nonrefY, vx_image nonrefU, vx_image nonrefV, vx_image denom, vx_scalar refweight,
        vx_scalar wmult, vx_scalar iszoom, vx_image weights);

/** @brief Accumulate input image based on the supplied weight map
 *
 * @param[in] graph The reference to the graph.
 * @param[in] imgY VX_DF_IMAGE_U8 representing luma channel for the image
 * @param[in] imgU VX_DF_IMAGE_U8 representing Cb channel for the image
 * @param[in] imgV VX_DF_IMAGE_U8 representing Cr channel for the image
 * @param[in] weightMap VX_DF_IMAGE_U8 representing weight map to use to accumulate this image
 * @param[out] accumY VX_DF_IMAGE_U32 representing luma channel for the accumulator
 * @param[out] accumU VX_DF_IMAGE_U32 representing Cb channel for the accumulator
 * @param[out] accumV VX_DF_IMAGE_U32 representing Cr channel for the accumulator
 * @param[out] accumWeight VX_DF_IMAGE_U16 representing accumulated weight map interpolated to
 * accumulator dimensions
 * @param[in] mode Specifies the mode to use this accumulator Type: vx_int32
 *                  0: Initialize the accumulator based on the weight map and input image
 *                  1: Accumulate the input image based on the weight map
 *                  2: Accumulate the input image based on the weight map and return the normalized
 *                     output
 * @param[out] outY VX_DF_IMAGE_U8 representing luma channel for the normalized output image (mode 2 only)
 * @param[out] outU VX_DF_IMAGE_U8 representing Cb channel for the normalized output image (mode 2 only)
 * @param[out] outV VX_DF_IMAGE_U8 representing Cr channel for the normalized output image (mode 2 only)
 */
vx_node vxmpiAccumulateWeightMappedNode(vx_graph graph, vx_image imgY, vx_image imgU,
        vx_image imgV, vx_image weightMap, vx_image accumY, vx_image accumU, vx_image accumV,
        vx_image accumWeight, vx_scalar mode, vx_image outY, vx_image outU, vx_image outV);
vx_status vxumpiAccumulateWeightMapped(vx_context context, vx_image imgY, vx_image imgU,
        vx_image imgV, vx_image weightMap, vx_image accumY, vx_image accumU, vx_image accumV,
        vx_image accumWeight, vx_scalar mode, vx_image outY, vx_image outU, vx_image outV);

/** @brief Initialize accumulators for vxmpiAccumulateWeightMappedNode
 *
 * This is just the special implementation of vxmpiAccumulateWeightMappedNode where mode = 0
 *
 * @param[in] graph The reference to the graph.
 * @param[in] imgY VX_DF_IMAGE_U8 representing luma channel for the image
 * @param[in] imgU VX_DF_IMAGE_U8 representing Cb channel for the image
 * @param[in] imgV VX_DF_IMAGE_U8 representing Cr channel for the image
 * @param[in] weightMap VX_DF_IMAGE_U8 representing weight map to use to accumulate this image
 * @param[out] accumY VX_DF_IMAGE_U32 representing luma channel for the accumulator
 * @param[out] accumU VX_DF_IMAGE_U32 representing Cb channel for the accumulator
 * @param[out] accumV VX_DF_IMAGE_U32 representing Cr channel for the accumulator
 */
vx_node vxmpiInitAccumulateWeightMappedNode(vx_graph graph, vx_image imgY, vx_image imgU,
        vx_image imgV, vx_image weightMap, vx_image accumY, vx_image accumU, vx_image accumV);
vx_status vxumpiInitAccumulateWeightMapped(vx_context context, vx_image imgY, vx_image imgU,
        vx_image imgV, vx_image weightMap, vx_image accumY, vx_image accumU, vx_image accumV);

/** @brief Calculate a motion weight map between two frames
 *
 * @param[in] graph The reference to the graph.
 * @param[in] accum_map VX_DF_IMAGE_U16 containing the accumulated weight map from blending
 * @param[in] chroma_lut VX_DF_IMAGE_U8 64x64 table determines influence of hue on motion map
 * @param[in] ref_weight The reference weight used in FrameFusion and AccumulateWeightMapped Type: vx_uint8
 * @param[in] num_frames The number of frames sent to AccumulateWeightMapped and used to normalize Type: vx_int32
 * @param[in] u VX_DF_IMAGE_U8 representing Cb channel for the blended normalized image
 * @param[in] v VX_DF_IMAGE_U8 representing Cr channel for the blended normalized image
 * @param[in] useradial Determines wheter or not to calculate motion map with a radial Type: vx_bool
 * @param[out] motionmap VX_DF_IMAGE_U8 motion map sent to ENF
 */
vx_node vxmpiMotionMapNode(vx_graph graph, vx_image accum_map, vx_array chroma_lut,
        vx_scalar ref_weight, vx_scalar num_frames, vx_image u, vx_image v, vx_scalar useradial,
        vx_image motionmap);
vx_status vxumpiMotionMap(vx_context context, vx_image accum_map, vx_array chroma_lut,
        vx_scalar ref_weight, vx_scalar num_frames, vx_image u, vx_image v, vx_scalar useradial,
        vx_image motionmap);

/** @brief Add noise to a corresponding frame
 *
 * @param[in] graph The reference to the graph.
 * @param[in] input VX_DF_IMAGE_U8 image which correlates to noise map
 * @param[in] noisemap VX_DF_IMAGE_U8 image that will be added to input image
 * @param[out] output VX_DF_IMAGE_U8 output image with noise added
 */
vx_node vxmpiAddNoiseMapNode(vx_graph graph, vx_image input, vx_image noisemap, vx_image output);
vx_status vxumpiAddNoiseMap(vx_context context, vx_image input, vx_image noisemap, vx_image output);

/** @brief Given channels Y, U, and V of a set of frames blend them together
 *
 * BlendFrames will internally call FrameFusion and AccumulateWeightMap
 *
 * @param[in] graph The reference to the graph.
 * @param[in] imgY Array of VX_DF_IMAGE_U8 images representing luma channel for each image
 * @param[in] imgU Array of VX_DF_IMAGE_U8 images representing Cb channel for each image
 * @param[in] imgV Array of VX_DF_IMAGE_U8 images representing Cr channel for each image
 * @param[in] mode Array of VX_TYPE_INT32 scalars specifying blending mode for each frame.
 * @param[in] index VX_TYPE_UINT32 index into the delays specifying location of reference frame.
 * @param[in] peak VX_TYPE_UINT16 tunes the motion estimation value for this scene.
 * @param[in] refweight VX_TYPE_UINT8 representing 0-motion in the motion weight map
 * @param[in] iszoom VX_TYPE_BOOL indiciting whether or not we are running a zoom usecase
 * @param[out] weightMap VX_DF_IMAGE_U16 representing accumulated weight map interpolated to
 * accumulator dimensions
 * @param[out] blendY VX_DF_IMAGE_U8 representing luma channel for the normalized output image
 * @param[out] blendU VX_DF_IMAGE_U8 representing Cb channel for the normalized output image
 * @param[out] blendV VX_DF_IMAGE_U8 representing Cr channel for the normalized output image
 */
vx_node vxmpiBlendFramesNode(vx_graph graph, vx_object_array imgY, vx_object_array imgU,
        vx_object_array imgV, vx_object_array modes, vx_scalar index, vx_scalar peak,
        vx_scalar refweight, vx_scalar iszoom, vx_image weightMap, vx_image blendY,
        vx_image blendU, vx_image blendV);
vx_status vxumpiBlendFrames(vx_context context, vx_object_array imgY, vx_object_array imgU,
        vx_object_array imgV, vx_object_array modes, vx_scalar index, vx_scalar peak,
        vx_scalar refweight, vx_scalar iszoom, vx_image weightMap, vx_image blendY,
        vx_image blendU, vx_image blendV);

/** @brief Given channels Y, U, and V of a set of frames blend them together
 *
 * @param[in] graph The reference to the graph.
 * @param[in] input Matrix corresponding to luma channel
 * @param[out] output Matrix corresponding to UV channels
 */
vx_node vxmpiUVAffineNode(vx_graph graph, vx_matrix input, vx_matrix output);
vx_status vxumpiUVAffine(vx_context context, vx_matrix input, vx_matrix output);

/** @brief Given an array of KPT from ORB and a array-of-array of match
 *         results from MCH, computes alignment matrices for each set of
 *         MCH results.
 *
 *
 *
 * @param[in] graph The reference to the graph.
 * @param[in] orbKpt Array holding Kpt (vx_uint128)
 * @param[in] orbKptDesc Array holding Kpt descriptors (vx_uint256)
 * @param[in] mchMatchF0 Array holding Match results (vx_uint8)
 * @param[in] mchMatchF1 Array holding Match results (vx_uint8)
 * @param[in] mchMatchF2 Array holding Match results (vx_uint8)
 * @param[in] mchMatchF3 Array holding Match results (vx_uint8)
 * @param[out] affine Array holding results from the get affine node (vx_matrix)
 * @param[out] flag Array holding flag status from the get affine node (vx_int32)
 * @param[out] error Array holding residual error from the get affine node (vx_float32)
 * @param[in] blendSize Number of frames in the blending window (vx_uint32)
 * @param[in] rotThr Parameter setting threshold for allowable rotation by the matrix (vx_float32)
 * @param[in] scaleSymmThr Parameter setting threshold for allowable scale difference in x/y (vx_float32)
 * @param[in] transThr Parameter setting threshold for allowable translation amount (vx_float32)
 * @param[in] fitThr Parameter setting threshold for maximum residual error (vx_float32)
 */
vx_node vxmpiOrbMchGetAffineNode(vx_graph graph, vx_object_array orbKpt, vx_object_array orbKptDesc,
          vx_object_array mchMatchFrame0, vx_object_array mchMatchFrame1, vx_object_array mchMatchFrame2,
          vx_object_array mchMatchFrame3, vx_array affine, vx_array flag, vx_array error,
          vx_scalar blendSize, vx_scalar rotThr, vx_scalar scaleSymmThr,
          vx_scalar transThr, vx_scalar fitThr);
vx_status vxumpiOrbMchGetAffine(vx_context context, vx_object_array orbKpt, vx_object_array orbKptDesc,
          vx_object_array mchMatchFrame0, vx_object_array mchMatchFrame1, vx_object_array mchMatchFrame2,
          vx_object_array mchMatchFrame3, vx_array affine, vx_array flag, vx_array error,
          vx_scalar blendSize, vx_scalar rotThr, vx_scalar scaleSymmThr,
          vx_scalar transThr, vx_scalar fitThr);


/** @brief Calculate a blurmap from an image
 *
 * @param[in] graph The reference to the graph.
 * @param[in] input An input image in <tt>\ref VX_DF_IMAGE_U8</tt> format
 * @param[out] output Output blurmap in <tt>\ref VX_DF_IMAGE_U16</tt> format
 */
vx_node vxmpiBlurMapNode(vx_graph graph, vx_image input, vx_image output);
vx_status vxumpiBlurMap(vx_context context, vx_image input, vx_image output);


/** @brief Select a reference frame based on a set of blur maps
 *
 * @param[in] graph The reference to the graph.
 * @param[in] maps An object array of blur maps with <tt>\ref VX_DF_IMAGE_U16</tt> format
 * @param[out] index Reference index chosen from set of blur maps (VX_TYPE_INT32)
 * @param[out] modes An object array of scalar (VX_TYPE_INT32) specifying whether or not to use this
 * frame
 */
vx_node vxmpiRefSelectNode(vx_graph graph, vx_object_array maps, vx_scalar index,
        vx_object_array modes);
vx_status vxumpiRefSelect(vx_context context, vx_object_array maps, vx_scalar index,
        vx_object_array modes);

#ifdef __cplusplus
}
#endif

#endif
