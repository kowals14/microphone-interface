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

	float pre_amp;
	float mix;
	float gain;

	float temp[3];

	float thrshld_noise;
	float gain;

} typedef DISTORT_Params;

void DISTORT_SetParams(DISTORT_Params* d_p, float, float, float);

void DISTORT_Init(DISTORT_Params* d_p);

float DISTORT_Apply(float audio_in, DISTORT_Params* d_p);

#ifdef __cplusplus
}
#endif

#endif
