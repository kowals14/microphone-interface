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

#define DISTORT_MAX_GAIN	2.0
#define DISTORT_MAX_MIX		1.0
#define DISTORT_MAX_PREAMP	10.0

#define DISTORT_MIN_GAIN	0.0
#define DISTORT_MIN_MIX		0.0
#define DISTORT_MIN_PREAMP	1.0

 /**
 * Distortion specific variables
 */
struct __DISTORT_Params_ {

	float thrshld_lower;
	float thrshld_higher;
	float thrshld_noise;

	float h_gain;
	float l_gain;

	float pre_amp;
	float mix;
	float gain;

	float temp[3];


} typedef DISTORT_Params;

void DISTORT_SetParams(DISTORT_Params* d_p, float, float, float);

void DISTORT_Init(DISTORT_Params* d_p);

float DISTORT_Apply(float audio_in, DISTORT_Params* d_p);

#ifdef __cplusplus
}
#endif

#endif
