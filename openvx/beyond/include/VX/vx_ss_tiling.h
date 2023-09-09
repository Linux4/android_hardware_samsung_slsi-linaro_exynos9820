/*
 *
 * \copyright
 *
 * @brief   types for samsung tiling
 *
 * \file    vx_ss_tiling.h
 * \author  samsung.com
 * \date    .
 *	this file borrows some part of vx_khr_tiling.h.
 *	samsung ovx does not support khronous tiling officilly.
 */


#ifndef _VX_SS_TILING_H_
#define _VX_SS_TILING_H_

/*! \brief The User Tiling Function tile block size declaration.
 * \details The author of a User Tiling Kernel will use this structure to define
 * the dimensionality of the tile block.
 * \ingroup group_tiling
 */
typedef struct _vx_tile_block_size_t {
	vx_int32 width;		/*!< \brief Tile block width in pixels. */
	vx_int32 height;	/*!< \brief Tile block height in pixels. */
} vx_tile_block_size_t;

/*! \brief The User Node Tiling Attributes.
 * \note These are largely unusable by the tiling function, as it doesn't give you the node reference!
 * \ingroup group_tiling
 */
enum vx_node_attribute_tiling_e {
	/*! \brief This allows a tiling mode node to get its output tile block size. */
	VX_NODE_ATTRIBUTE_OUTPUT_TILE_BLOCK_SIZE  =
			VX_ATTRIBUTE_BASE(VX_ID_KHRONOS, VX_TYPE_NODE) + 0x8,

	/*! \brief This allows a tiling mode node to get its input tile block size. */
	VX_NODE_ATTRIBUTE_INPUT_TILE_BLOCK_SIZE   =
			VX_ATTRIBUTE_BASE(VX_ID_KHRONOS, VX_TYPE_NODE) + 0xB,
};

#endif
