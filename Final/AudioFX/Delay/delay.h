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
#define  DELAY_LINE_SIZE (int) (AUDIOFX_SAMPLING_RATE * DELAY_MAX)

/**
 * Delay specific variables
 */
struct __DELAY_Params_ {

	float mix;		// wet mix
	float feedback;
	float time_ms;

	float temp[3];

	uint32_t sample_len;
	uint32_t delay_line_index;

	float delay_line[DELAY_LINE_SIZE];

} typedef DELAY_Params;

void DELAY_SetParams(DELAY_Params* d_p, float, float, float);

void DELAY_Init(DELAY_Params* d_p);

float DELAY_Apply(float audio_in, DELAY_Params* d_p);

#ifdef __cplusplus
}
#endif

#endif /* DELAY_DELAY_H_ */
