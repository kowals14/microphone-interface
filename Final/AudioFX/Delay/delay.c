/*
 * delay.c
 *
 *  Created on: Apr 10, 2024
 *      Author: Jakub Kowalski
 *      Derivded from: https://wiki.analog.com/resources/tools-software/sharc-audio-module/baremetal/delay-effect-tutorial
 */

#include "delay.h"

void DELAY_SetParams(DELAY_Params* d_p, float* params) {

	d_p->temp_delay_mix[0] 		= params[1];
	d_p->temp_delay_mix[1] 		= 1.0f - params[1];
	d_p->temp_delay_sample_len 	= (uint32_t) params[2] * AUDIOFX_SAMPLING_RATE;
	d_p->temp_delay_feedback 	= params[0];

}

void DELAY_Update(DELAY_Params* d_p) {

	d_p->delay_mix[0] 		= d_p->temp_delay_mix[0];
	d_p->delay_mix[1] 		= d_p->temp_delay_mix[1];
	d_p->delay_sample_len 	= d_p->temp_delay_sample_len;
	d_p->delay_feedback		= d_p->temp_delay_feedback;

}

void DELAY_Apply(int16_t* audio_in, int16_t* audio_out, DELAY_Params* d_p) {
	float delayed_sample = d_p->delay_line[d_p->delay_line_index];
	float in_sample = INT16_TO_FLOAT * (*audio_in);

	*audio_out = (int16_t) FLOAT_TO_INT16 * ((in_sample * d_p->delay_mix[1]) + (delayed_sample * d_p->delay_mix[0]));

	d_p->delay_line[d_p->delay_line_index] = d_p->delay_feedback * (delayed_sample + in_sample);

	// Finally, update the delay line index
	if (d_p->delay_line_index++ >= d_p->delay_sample_len) {
		d_p->delay_line_index = 0;
	}
}
