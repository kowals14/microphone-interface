/*
 * delay.c
 *
 *  Created on: Apr 10, 2024
 *      Author: Jakub Kowalski
 *      Derivded from: https://wiki.analog.com/resources/tools-software/sharc-audio-module/baremetal/delay-effect-tutorial
 */


#include "delay.h"

void DELAY_SetParams(DELAY_Params* d_p, float mix, float feedback, float time_ms) {
	d_p->mix	 		= mix;
	d_p->feedback		= feedback;
	d_p->sample_len 	= (uint32_t) (time_ms / 1000.0) * AUDIOFX_SAMPLING_RATE;

}

void DELAY_Init(DELAY_Params* d_p) {
	d_p->delay_line_index	= 0;

	DELAY_SetParams(d_p, 0.0f, 0.0f, 0.0f);

	for(int i = 0; i < DELAY_LINE_SIZE; i++) {
		d_p->delay_line[i] = 0;
	}
}

float DELAY_Apply(float in_sample, DELAY_Params* d_p) {
	float delayed_sample = d_p->delay_line[d_p->delay_line_index];

	d_p->delay_line[d_p->delay_line_index] = d_p->feedback * (delayed_sample + in_sample);

	if (d_p->delay_line_index++ >= d_p->sample_len) {
		d_p->delay_line_index = 0;
	}

	return (in_sample * (1.0 - d_p->mix)) + (delayed_sample * d_p->mix);;
}
