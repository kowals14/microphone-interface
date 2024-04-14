/*
 * delay.c
 *
 *  Created on: Apr 10, 2024
 *      Author: Jakub Kowalski
 *      Derivded from: https://wiki.analog.com/resources/tools-software/sharc-audio-module/baremetal/delay-effect-tutorial
 */


#include "delay.h"

void DELAY_SetParams(DELAY_Params* d_p, float mix, float feedback, uint32_t sample_len) {
	d_p->mix	 		= mix;
	d_p->sample_len 	= sample_len;
	d_p->feedback		= feedback;

}

void DELAY_Init(DELAY_Params* d_p) {
	d_p->mix	 			= 0;
	d_p->sample_len 		= 0;
	d_p->feedback			= 0;
	d_p->delay_line_index	= 0;

	for(int i = 0; i < DELAY_LINE_SIZE; i++) {
		d_p->delay_line[i] = 0;
	}
}

float DELAY_Apply(float in_sample, DELAY_Params* d_p) {
	float delayed_sample = d_p->delay_line[d_p->delay_line_index];
	float out_sample 	 = 0;

	d_p->delay_line[d_p->delay_line_index] = d_p->feedback * (delayed_sample + in_sample);

	if (d_p->delay_line_index++ >= d_p->sample_len) {
		d_p->delay_line_index = 0;
	}

	out_sample = (in_sample * (1.0 - d_p->mix)) + (delayed_sample * d_p->mix);

	return out_sample;
}
