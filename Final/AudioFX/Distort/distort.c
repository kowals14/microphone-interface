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

void DISTORT_SetParams(DISTORT_Params* d_p, float* params){

	d_p->thrshld_gap 	= params[0] * 10000000.0f;
	d_p->l_gain 		= 1.0f + params[1] * 1.0f;
	d_p->h_gain 		= params[2] * 1.0f - 0.1f;

}

void DISTORT_Update(DISTORT_Params* d_p){

	d_p->thrshld_gap = d_p->temp_thrshld_gap;
	d_p->h_gain = d_p->temp_h_gain;
	d_p->l_gain = d_p->temp_l_gain;

}

float DISTORT_Apply(int16_t audio_in, DISTORT_Params* d_p){
	float in_sample 		= INT16_TO_FLOAT * audio_in;
	float threshold_lower 	= in_sample - (d_p->thrshld_gap/2);
	float threshold_higher	= in_sample + (d_p->thrshld_gap/2);
	float threshold_noise	= 2000000.0f;
	float gain 				= 2.0f;

	if(d_p->thrshld_gap == 0 && d_p->l_gain == 0 && d_p->h_gain == 0) {	// no distortion being applied
		return in_sample;
	}
	else if (fabs(in_sample) < threshold_lower && fabs(in_sample) > threshold_noise ){
		return gain * in_sample * d_p->l_gain;
	}
	else if (fabs(in_sample) > threshold_higher){
		return gain * in_sample * d_p->h_gain;
	}
	else{
		return gain * in_sample;
	}
}
