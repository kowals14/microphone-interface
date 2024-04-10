/*
 * filters.c
 *
 *  Created on: Apr 10, 2024
 *      Author: Joshua Hom
 *      Derived From: https://www.youtube.com/watch?v=azLQf4aLv9w
 */

#include "distort.h"

//void Do_Distortion (float insample) {
//
//	float threshold_noise = 2000000.0f;
//
//
//	float threshold_lower = 10000000.0f;
//	float gain_lower = 2.0f;
//
//	float threshold_higher = 60000000.0f;
//	float gain_higher = 0.5f;
//
//	float outgain = 2.0f;
//
//
//	if (fabs(insample) < threshold_lower && fabs(insample) > threshold_noise ) return outgain*(insample*gain_lower);
//	if (fabs(insample) > threshold_higher) return outgain*(insample*gain_higher);
//	return outgain*insample;
//}

void DISTORT_Coef(float* params){
	thrshld_gap = params[0] * 10000000.0f;
	l_gain = params[1] * 2.0f;
	h_gain = params[2] * 0.5f;
}

void DISTORT_Update(AUDIOFX_UserParams* u_p){
	// set all the coefficient variables to the new values
		if(u_p->param_change_flag) {//?

			u_p->thrshld_gap = u_p->temp_thrshld_gap;
			u_p->h_gain = u_p->temp_h_gain;
			u_p->l_gain = u_p->temp_l_gain;

			u_p->param_change_flag = 0;
		}
}

void DISTORT_Apply(int16_t* audio_in, int16_t* audio_out, AUDIOFX_UserParams* u_p){
	float  in_sample = (INT16_TO_FLOAT * audio_in[i]);

	float threshold_lower = in_sample - (thrshld_gap/2);
	float threshold_higher = in_sample + (thrshld_gap/2);
	float threshold_noise = 2000000.0f;
	float outgain = 2.0f;

	if (fabs(insample) < threshold_lower && fabs(insample) > threshold_noise ){
		audio_out[i] = (int16_t) (outgain*(insample*l_gain) * FLOAT_TO_INT16);
	}
	else if (fabs(insample) > threshold_higher){
		audio_out[i] = (int16_t) (outgain* (insample*h_gain) * FLOAT_TO_INT16);
	}
	else{
		audio_out[i] = (int16_t) (outgain*insample * FLOAT_TO_INT16);
	}

}
