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

#define FILTERS_MAX_FREQ	19980.0
#define FILTERS_MAX_G		50.0
#define FILTERS_MAX_BW		500.0

#define FILTERS_MIN_FREQ	20.0
#define FILTERS_MIN_G		0.0
#define FILTERS_MIN_BW		1.0

typedef uint8_t	FILTERS_Type;

#define FILTERS_PKF			(FILTERS_Type) 0
#define FILTERS_HPF			(FILTERS_Type) 1
#define FILTERS_LPF			(FILTERS_Type) 2
#define FILTERS_BPF			(FILTERS_Type) 3

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

void FILTERS_SetParams_PKNG(FILTERS_Params* f_p, float f0, float BW, float G);
void FILTERS_SetParams_LPF(FILTERS_Params* f_p, float f0, float BW, float G);
void FILTERS_SetParams_HPF(FILTERS_Params* f_p, float f0, float BW, float G);

void FILTERS_Init(FILTERS_Params* f_p);

float FILTERS_Apply(float in_sample, FILTERS_Params* f_p);

#ifdef __cplusplus
}
#endif

#endif
