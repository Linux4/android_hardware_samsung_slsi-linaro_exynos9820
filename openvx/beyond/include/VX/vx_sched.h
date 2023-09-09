/*
 *
 * \copyright
 *
 * @brief   types for samsung scheduler
 *
 * \file    vx_sched.h
 * \author  Ilkwan Kim
 * \date    23-Mar-2016
 * TO DO: this file is used temporarily. After refactoring the source structure,
 *          will be removed.
 */

#ifndef _OPENVX_SCHED_H_
#define _OPENVX_SCHED_H_


typedef enum vx_processor_id
{
	PROC_NONE = -1,
	PROC_CPU = 0,
	PROC_IVA,
	PROC_SCORE,
	PROC_MAX,
} PROC_ID;

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef  __cplusplus
}
#endif

#endif

