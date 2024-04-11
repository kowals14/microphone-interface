/*
 * filters.c
 *
 *  Created on: Jan 26, 2024
 *      Author: Jakub Kowalski
 */

#include "filters.h"

void FILTERS_Coef_LPF(float* b, float* a, float* params) {
	float f0 		= params[0];
	float BW_Q 		= params[2];

	float w0 		= 2 * M_PI * f0 / AUDIOFX_SAMPLING_RATE;
	float cos_w0 	= cos(w0);
	float sin_w0 	= sin(w0);
	float alpha;

	alpha = sin_w0/(2*BW_Q);

	b[0] =  (1 - cos_w0) / 2;
	b[1] =   1 - cos_w0;
	b[2] =  (1 - cos_w0) / 2;

	a[0] =   1 + alpha;
	a[1] =  -2 * cos_w0;
	a[2] =   1 - alpha;
}

void FILTERS_Coef_HPF(float* b, float* a, float* params) {
	float f0 		= params[0];
	float BW_Q 		= params[2];

	float w0 		= 2 * M_PI * f0 / AUDIOFX_SAMPLING_RATE;
	float cos_w0 	= cos(w0);
	float sin_w0 	= sin(w0);
	float alpha;

	alpha = sin_w0/(2*BW_Q);

	b[0] =  (1 + cos_w0) / 2;
	b[1] = -(1 + cos_w0);
	b[2] =  (1 + cos_w0) / 2;

	a[0] =   1 + alpha;
	a[1] =  -2 * cos_w0;
	a[2] =   1 - alpha;
}

void FILTERS_Coef_PKNG(float* b, float* a, float* params) {
	float f0 		= params[0];
	float dbGain 	= params[1];
	float BW_Q 		= params[2];

	float w0 		= 2 * M_PI * f0 / AUDIOFX_SAMPLING_RATE;
	float A 	 	= pow(10, (dbGain / 40));
	float cos_w0 	= cos(w0);
	float sin_w0 	= sin(w0);
	float alpha;

	alpha = sin_w0 * sinh(log(2)/2 * BW_Q * w0 / sin_w0);

	b[0] =   1 + alpha * A;
	b[1] =  -2 * cos_w0;
	b[2] =   1 - alpha * A;

	a[0] =   1 + alpha / A;
	a[1] =  -2 * cos_w0;
	a[2] =   1 - alpha / A;
}

void FILTERS_Update(AUDIOFX_UserParams* u_p) {
	// set all the coefficient variables to the new values
	if(u_p->param_change_flag) {

		u_p->b[0] = u_p->temp_b[0];
		u_p->b[1] = u_p->temp_b[1];
		u_p->b[2] = u_p->temp_b[2];

		u_p->a[0] = u_p->temp_a[0];
		u_p->a[1] = u_p->temp_a[1];
		u_p->a[2] = u_p->temp_a[2];

		u_p->param_change_flag = 0;
	}
}

void FILTERS_Apply(int16_t* audio_in, int16_t* audio_out, AUDIOFX_UserParams* u_p) {
	float  in_sample;

	for(int i = 0; i < (AUDIOFX_BUFF_SIZE/2); i++) {
    	in_sample = (INT16_TO_FLOAT * audio_in[i]);

        u_p->in_buff[2] = u_p->in_buff[1];
        u_p->in_buff[1] = u_p->in_buff[0];
        u_p->in_buff[0] = in_sample;

        if(i > 0) {
        	u_p->out_buff[1] = u_p->out_buff[0];
        	u_p->out_buff[0] = (INT16_TO_FLOAT * audio_out[i-1]);
        }

        audio_out[i] = (int16_t) (((-u_p->out_buff[0] * u_p->a[1] 
									- u_p->out_buff[1] * u_p->a[2]
									+ u_p->in_buff[0] * u_p->b[0] 
									+ u_p->in_buff[1] * u_p->b[1] 
									+ u_p->in_buff[2] * u_p->b[2]) / u_p->a[0]) * FLOAT_TO_INT16);
    }
}
