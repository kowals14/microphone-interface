
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

void DISTORT_SetParams(DISTORT_Params* d_p, float pre_amp, float mix, float gain){
	d_p->pre_amp 	= pre_amp;
	d_p->mix		= mix;
	d_p->gain		= gain;

}

void DISTORT_Init(DISTORT_Params* d_p){

	d_p->thrshld_noise	= 0.1f;
	d_p->thrshld_lower 	= 0.2f;
	d_p->thrshld_higher = 0.5f;

	d_p->gain 			= 2.0f;
	d_p->l_gain 		= 2.0f;
	d_p->h_gain			= 0.5f;

	DISTORT_SetParams(d_p, 1.0f, 1.0f, 1.0f);
}

float DISTORT_Apply(float in_sample, DISTORT_Params* d_p){
	float distorted_sample;

	in_sample = in_sample * d_p->pre_amp;

	if (fabs(in_sample) < d_p->thrshld_lower && fabs(in_sample) > d_p->thrshld_noise ){
		distorted_sample = d_p->gain * in_sample * d_p->l_gain;
	}
	else if (fabs(in_sample) > d_p->thrshld_higher){
		distorted_sample = d_p->gain * in_sample * d_p->h_gain;
	}
	else{
		distorted_sample = d_p->gain * in_sample;
	}

	return (distorted_sample * d_p->mix) + (in_sample * (1 - d_p->mix));
}
