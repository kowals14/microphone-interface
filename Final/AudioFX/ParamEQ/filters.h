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

#include <math.h>
#include "main.h"
#include "trig_functions.h"


/**
 * Filter Specific Variables
 */
struct __FILTERS_Params_ {

	float f0;	// center frequency in Hz
	float G;	// boost/cut
	float BW;	// bandwidth in Hz

	// Previous outputs/inputs
	float in_buff[3];
	float out_buff[2];

	// IIR Coefficients
	float b[3];
	float a[3];
	float temp_b[3];
	float temp_a[3];

} typedef FILTERS_Params;

void FILTERS_SetParams(FILTERS_Params* f_p, float* params);

void FILTERS_Update(FILTERS_Params* f_p);

float FILTERS_Apply(int16_t audio_in, FILTERS_Params* u_p);

#ifdef __cplusplus
}
#endif

#endif
