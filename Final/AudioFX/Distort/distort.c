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

void DISTORT_SetParams(DISTORT_Params* d_p, float gap, float l_gain, float h_gain){
	d_p->thrshld_gap 	= gap;
	d_p->l_gain 		= l_gain;
	d_p->h_gain 		= h_gain;

}

void DISTORT_Init(DISTORT_Params* d_p){
	d_p->thrshld_noise	= 2000000.0f;
	d_p->gain 			= 2.0f;

	DISTORT_SetParams(d_p, 0.0f, 0.0f, 0.0f);
}

float DISTORT_Apply(float in_sample, DISTORT_Params* d_p){
	float threshold_lower 	= in_sample - (d_p->thrshld_gap / 2);
	float threshold_higher	= in_sample + (d_p->thrshld_gap / 2);

	if(d_p->thrshld_gap == 0 && d_p->l_gain == 0 && d_p->h_gain == 0) {	// no distortion being applied
		return in_sample;
	}
	else if (fabs(in_sample) < threshold_lower && fabs(in_sample) > d_p->thrshld_noise ){
		return d_p->gain * in_sample * d_p->l_gain;
	}
	else if (fabs(in_sample) > threshold_higher){
		return d_p->gain * in_sample * d_p->h_gain;
	}
	else{
		return d_p->gain * in_sample;
	}
}
