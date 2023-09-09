/*
 * Copyright (c) 2016 Samsung Electronics Co.Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 */

#ifndef _SAMSUNG_OPENVX_API_H_
#define _SAMSUNG_OPENVX_API_H_

/*!
 * \file
 * \brief The API definition for Samsung OpenVX.
 */

#ifdef  __cplusplus
extern "C" {
#endif

/*==============================================================================
 CONTEXT
 =============================================================================*/
 /*!
 * \brief synchronize memory with cpu cache
 *
 * User must should get to know the direction for memory synchronizing.
 *	do not use exept special exceptional case
 *		because it is generally unnecessary.
 *
 * \param [in] param	reference to vx data object
 * \param [in] dir	direction for sync
 *			VX_SYNC_CPU_TO_DEV, VX_SYNC_DEV_TO_CPU
 * \param [in] capacity     The maximal number of items that the array can hold.
 *
 * \returns	error code on error or 0 on success *
 * \ingroup group_context
 */
VX_API_ENTRY vx_int32 svxSyncVxObject(vx_reference param, vx_int32 dir);

 /*!
 * \brief synchronize shared memory pool with cpu cache
 *
 * User must should get to know the direction for memory synchronizing.
 *
 * \param [in] p 	memory of shared memory pool
 * \param [in] dir	direction for sync
 *			VX_SYNC_CPU_TO_DEV, VX_SYNC_DEV_TO_CPU
 *
 * \returns	void
 * \ingroup 	group_context
 */
VX_API_ENTRY void svxSyncShmemPool(void *p, vx_enum dir);

/*==============================================================================
 TARGET
 =============================================================================*/
/*! \brief Used to put the corresponding hw suspended/resumed.
 * \note This assignment overrides implementation chosen behavior.
 * \param [in] context The reference to the overall context.
 * \param [in] name The target string name.
 * \ingroup group_target
 * \retval VX_SUCCESS on success, VX_FAILURE on failure.
 */
VX_API_ENTRY vx_status VX_API_CALL svxResumeTarget(vx_context context,
		const vx_char *name);

VX_API_ENTRY vx_status VX_API_CALL svxSuspendTarget(vx_context context,
		const vx_char *name);

/*==============================================================================
 IMAGE
 =============================================================================*/
/*! \brief Creates an image from another image.
 * Create Y or UV format image from YUV format image. Updates to this image
 * updates the parent image.
 * \param [in] img The reference to the parent image.
 * \param [in] img_type The image type to create. VX_DF_IMAGE_Y or VX_DF_IMAGE_UV.
 * \returns An image reference <tt>\ref vx_image</tt> to the sub-image.
 * 	Any possible errors preventing a
 * successful creation should be checked using <tt>\ref vxGetStatus</tt>.
 * \ingroup group_image
 */
VX_API_ENTRY vx_image VX_API_CALL svxCreateImageFromImage(vx_image img,
		vx_df_image img_type);

/*! \brief Creates a reference to an image object that was externally
 *		allocated with shared fd.
 * \param [in] context The reference to the implementation context.
 * \param [in] color See the <tt>\ref vx_df_image_e</tt> codes.
 * \param [in] share_fd fd of externally allocated memory.
 * \param [in] dim_x width of the image.
 * \param [in] dim_y height of the image.
 * \returns An image reference <tt>\ref vx_image</tt>.
 *		Any possible errors preventing a successful creation
 *		should be checked using <tt>\ref vxGetStatus</tt>.
 * \note The user must call vxAccessImagePatch prior to accessing the pixels
 *		of an image, even if the
 * image was created via <tt>\ref vxCreateImageFromSharedFd</tt>.
 * \ingroup group_image
 */
VX_API_ENTRY vx_image VX_API_CALL svxCreateImageFromSharedFd(vx_context context,
		vx_df_image color, vx_int32 share_fd,
		vx_int32 dim_x, vx_int32 dim_y);

/*! \brief Creates a reference to an image object that was externally
 *		allocated with shared fd (w/ offset).
 * \param [in] context The reference to the implementation context.
 * \param [in] color See the <tt>\ref vx_df_image_e</tt> codes.
 * \param [in] share_fd fd of externally allocated memory.
 * \param [in] dim_x width of the image.
 * \param [in] dim_y height of the image.
 * \param [in] offset offset added to the starting addr of mapped VA.
 * \param [in] virt_addr for future use.
 * \returns An image reference <tt>\ref vx_image</tt>.
 *		Any possible errors preventing a successful creation
 *		should be checked using <tt>\ref vxGetStatus</tt>.
 * \note The user must call vxAccessImagePatch prior to accessing the pixels
 *		of an image, even if the
 * image was created via <tt>\ref vxCreateImageFromSharedFd</tt>.
 * \ingroup group_image
 */
VX_API_ENTRY vx_image VX_API_CALL svxCreateImageFromSharedFd2(vx_context context,
                vx_df_image color, vx_int32 share_fd, vx_int32 dim_x, vx_int32 dim_y,
                vx_size offset, void *virt_addr);


/*==============================================================================
 ARRAY
 =============================================================================*/
 /*!
 * \brief Grants access to a sub-range of an Array.
 *		The number of elements in the sub-range is given by (end - start).
 		end should not be bigger than capacity of the array.
 *
 * \param [in] arr          The reference to the Array.
 * \param [in] start        The start index.
 * \param [in] end          The end index. (end - start) elements are accessed from start.
 * \param [in, out] stride  A pointer to 'number of bytes' between the beginning of two consequent
 * elements.
 * \arg Input case: ptr is a pointer to a non-NULL pointer. The stride parameter must be the address
 * of a vx_size scalar that describes how the user will access the requested array data at address
 * (*ptr).
 * \arg Output Case: ptr is a pointer to a NULL pointer. The function fills the vx_size scalar
 * pointed by stride with the element stride information that the user must consult to access the
 * array elements at address (*ptr).
 * \param [out] ptr        A pointer to a pointer to a location to store the requested data.
 * \arg Input Case: ptr is a pointer to a non-NULL pointer to a valid buffer. This buffer will be
 * used in one of two ways, depending on the value of the usage parameter. If usage is
 * VX_WRITE_ONLY, then the buffer must contain element data that the user wants to replace the
 * array's element data with. Otherwise (i.e., usage is not VX_WRITE_ONLY), the array's current
 * element data will be written to the memory starting at address (*ptr) as storage memory for the
 * access request. The caller must ensure enough memory has been allocated for the requested array
 * range with the requested stride.
 * \arg Output Case: ptr is a pointer to a NULL pointer.  This NULL pointer will be overwritten with
 * a pointer to the address where the requested data can be accessed. (*ptr) must eventually be provided
 * as the ptr parameter of a call to vxCommitArrayRange.
 * \param [in] usage        This declares the intended usage of the pointer using the <tt>\ref vx_accessor_e</tt> enumeration.
 *
 * \note The stride and ptr parameters must both be input, or both be output, otherwise the behavior
 * is undefined.
 *
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS                   No errors.
 * \retval VX_ERROR_OPTIMIZED_AWAY      If the reference is a virtual array and cannot be accessed or committed.
 * \retval VX_ERROR_INVALID_REFERENCE   If the \a arr is not a <tt>\ref vx_array</tt>.
 * \retval VX_ERROR_INVALID_PARAMETERS  If any of the other parameters are incorrect.
 * \post <tt>\ref vxCommitArrayRange</tt>
 * \ingroup group_array
 */
VX_API_ENTRY vx_status VX_API_CALL svxAccessArrayWithCapacity(vx_array arr,
		vx_size start, vx_size end, vx_size *stride, void **ptr, vx_enum usage);

VX_API_ENTRY vx_array VX_API_CALL svxCreateArrayWithPool(vx_context context,
		vx_enum item_type, vx_size capacity, void *pool);


/*!
 * \brief Commits data back to the Array object.
 *
 * \details This allows a user to commit data to a sub-range of an Array.
 *		The number of elements in the sub-range is given by (end - start).
 		end should not be bigger than capacity of the array.
 * \param [in] arr          The reference to the Array.
 * \param [in] start        The start index.
 * \param [in] end          The end index. (end - start) elements are accessed from start.
 * \param [in] ptr          The user supplied pointer.
 *
 * \return A <tt>\ref vx_status_e</tt> enumeration.
 * \retval VX_SUCCESS                   No errors.
 * \retval VX_ERROR_OPTIMIZED_AWAY      If the reference is a virtual array and cannot be accessed or committed.
 * \retval VX_ERROR_INVALID_REFERENCE   If the \a arr is not a <tt>\ref vx_array</tt>.
 * \retval VX_ERROR_INVALID_PARAMETERS  If any of the other parameters are incorrect.
 *
 * \ingroup group_array
 */
VX_API_ENTRY vx_status VX_API_CALL svxCommitArrayWithCapacity(vx_array arr,
		vx_size start, vx_size end, const void *ptr);


/*==============================================================================
 NODE
 =============================================================================*/
/*! \brief Change the current node target.
 * \param [in] node
 * \param [in] target name to change
 * \retval VX_SUCCESS Success to change node's target
 * \retval VX_ERROR_INVAIDE_NODE Fail to change node's target
 */
VX_API_ENTRY vx_status VX_API_CALL svxSetNodeTarget(vx_node node,
		const vx_char* targetName);


/*! \brief Make a forced dependency between two nodes. (source)-->(target)
 * \param [in] graph
 * \param [in] source node
 * \param [in] target node
 */
VX_API_ENTRY vx_bool VX_API_CALL svxMakeDependencyForced(vx_graph graph,
		vx_node trig_node, vx_node dep_node);


/*==============================================================================
 CUSTOM
 =============================================================================*/
VX_API_ENTRY vx_status VX_API_CALL svxEnableXMLCustomPath(vx_graph graph,
		const vx_char *target_name, const vx_char *xml_file_name);

VX_API_ENTRY vx_status VX_API_CALL svxUpdateAllVcmNodeParameters(vx_graph graph);

/*! \brief Create shared memory pool from user
 * \param [in] size size to allocate shared memory.
 * \param [in] maximum size of slot.
 * \returns return memory address that contains memory_pool_info
 *          If failed, returns NULL
 * \note This pool can be used at <tt>\ref vxCreateArrayFromShmemPool()</tt>.
 * \ingroup group_memory
 */
VX_API_ENTRY void* svxCreateShmemPool(vx_size size, int32_t max_slot);


/*! \brief Destroy shared memory pool from user
 * \param [in] pool_info
 * \returns returns vx_success or vx_failure
 * \ingroup group_memory
 */

VX_API_ENTRY vx_status svxDestroyShmemPool(void *pool);



#ifdef  __cplusplus
}
#endif

#endif

