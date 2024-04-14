/*
 * delay.h
 *
 *  Created on: Apr 10, 2024
 *      Author: Jakub Kowalski
 */

#ifndef DELAY_DELAY_H_
#define DELAY_DELAY_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"

#define  DELAY_MAX	(1.0f)
//#define  DELAY_LINE_SIZE	(int) (AUDIOFX_SAMPLING_RATE * DELAY_MAX)
#define  DELAY_LINE_SIZE	(int) (48000.0f)

/**
 * Delay specific variables
 */
struct __DELAY_Params_ {

	// delay_mix[0] = wet, delay_mix[1] = dry
	float delay_mix[2];
	float delay_feedback;
	uint32_t delay_sample_len;

	float temp_delay_mix[2];
	float temp_delay_feedback;
	uint32_t temp_delay_sample_len;

	// delay line
	float delay_line[DELAY_LINE_SIZE];
	uint32_t delay_line_index;

} typedef DELAY_Params;

void DELAY_SetParams(DELAY_Params* d_p, float* params);

void DELAY_Update(DELAY_Params* d_p);

float DELAY_Apply(int16_t audio_in, DELAY_Params* d_p);

#ifdef __cplusplus
}
#endif

#endif /* DELAY_DELAY_H_ */
