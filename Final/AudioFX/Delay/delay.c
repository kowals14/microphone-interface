/*
 * delay.c
 *
 *  Created on: Apr 10, 2024
 *      Author: Jakub Kowalski
 */

#include "delay.h"

extern float* delay_line;
extern uint32_t delay_line_index;

void DELAY_Update(AUDIOFX_UserParams* u_p) {
	u_p->delay_mix[0] 		= u_p->temp_delay_mix[0];
	u_p->delay_mix[1] 		= u_p->temp_delay_mix[1];;
	u_p->delay_sample_len 	= u_p->temp_delay_sample_len;
}

void DELAY_Apply(int16_t* audio_in, int16_t* audio_out, AUDIOFX_UserParams* u_p) {
	for (int i = 0; i < AUDIOFX_BUFF_SIZE; i++) {
		float delayed_sample  = delay_line[delay_line_index];

//		audio_out[i] = (audio_in[i] * u_p->delay_mix[1]) + (delayed_sample * u_p->delay_mix[0]);
		audio_out[i] = audio_in[i];

		delay_line[delay_line_index]  = u_p->params[0] * (delayed_sample + audio_in[i]);

		// Finally, update the delay line index
//		if (delay_line_index++ >= u_p->delay_sample_len) {
//			delay_line_index = 0;
//		}
	}
}
