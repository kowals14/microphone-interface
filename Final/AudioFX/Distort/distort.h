/*
 * filters.h
 *
 *  Created on: Apr 10, 2024
 *      Author: Joshua Hom
 *      Derived From: https://www.youtube.com/watch?v=azLQf4aLv9w
 */

#ifndef __DISTORT_H__
#define __DISTORT_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <math.h>
#include "main.h"
#include "trig_functions.h"

 /**
 * Distortion specific variables
 */
struct __DISTORT_Params_ {

	float thrshld_gap;
	float h_gain;
	float l_gain;

	float temp_thrshld_gap;
	float temp_h_gain;
	float temp_l_gain;

} typedef DISTORT_Params;

void DISTORT_SetParams(DISTORT_Params* d_p, float* params);

void DISTORT_Update(DISTORT_Params* d_p);

float DISTORT_Apply(int16_t audio_in, DISTORT_Params* d_p);

#ifdef __cplusplus
}
#endif

#endif
