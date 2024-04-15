/*
 * filters.h
 *
 *  Created on: Jan 26, 2024
 *      Author: Jakub Kowalski
 */

#ifndef __FILTERS_H__
#define __FILTERS_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
#include <math.h>


/**
 * Filter Specific Variables
 */
struct __FILTERS_Params_ {

	float f0;	// center frequency in Hz
	float G;	// boost/cut
	float BW;	// bandwidth in Hz

	float temp[3];

	float sampleTime_s;

	// Previous outputs/inputs
	float x[3];
	float y[3];

	// IIR Coefficients
	float b[3];
	float a[3];

} typedef FILTERS_Params;

void FILTERS_SetParams(FILTERS_Params* f_p, float f0, float BW, float G);

void FILTERS_Init(FILTERS_Params* f_p);

float FILTERS_Apply(float in_sample, FILTERS_Params* f_p);

#ifdef __cplusplus
}
#endif

#endif
