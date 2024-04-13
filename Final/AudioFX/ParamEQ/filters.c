/*
 * filters.c
 *
 *  Created on: Jan 26, 2024
 *      Author: Jakub Kowalski
 */

#include "filters.h"

void FILTERS_SetParams(FILTERS_Params* f_p, float* params) {

	f_p->f0 = params[0] * 20000;	// center frequency in Hz
	f_p->G 	= params[1] * 2.0;		// boost/cut
	f_p->BW = params[2] * 1000.0;	// bandwidth in Hz

	float f0 		= f_p->f0;
	float G			= f_p->G;
	float BW_Q 		= f_p->BW;

	float w0 		= 2 * M_PI * f0 / AUDIOFX_SAMPLING_RATE;
	float A 	 	= pow(10, (G / 40));
	float cos_w0 	= cos(w0);
	float sin_w0 	= sin(w0);
	float alpha;

	alpha = sin_w0 * sinh(log(2)/2 * BW_Q * w0 / sin_w0);

	f_p->temp_b[0] =   1 + alpha * A;
	f_p->temp_b[1] =  -2 * cos_w0;
	f_p->temp_b[2] =   1 - alpha * A;

	f_p->temp_a[0] =   1 + alpha / A;
	f_p->temp_a[1] =  -2 * cos_w0;
	f_p->temp_a[2] =   1 - alpha / A;

}

void FILTERS_Update(FILTERS_Params* f_p) {

		f_p->b[0] = f_p->temp_b[0];
		f_p->b[1] = f_p->temp_b[1];
		f_p->b[2] = f_p->temp_b[2];

		f_p->a[0] = f_p->temp_a[0];
		f_p->a[1] = f_p->temp_a[1];
		f_p->a[2] = f_p->temp_a[2];

}

void FILTERS_Apply(int16_t* audio_in, int16_t* audio_out, FILTERS_Params* f_p) {
	float in_sample;
	float out_sample;


	in_sample = (INT16_TO_FLOAT * (*audio_in));

	out_sample = (int16_t) (((-f_p->out_buff[0] 	* f_p->a[1]
								- f_p->out_buff[1] 	* f_p->a[2]
								+ f_p->in_buff[0] 	* f_p->b[0]
								+ f_p->in_buff[1] 	* f_p->b[1]
								+ f_p->in_buff[2] 	* f_p->b[2]) / f_p->a[0]) * FLOAT_TO_INT16);

	// Update the previous input/output buffers

	f_p->in_buff[2] = f_p->in_buff[1];
	f_p->in_buff[1] = f_p->in_buff[0];
	f_p->in_buff[0] = in_sample;

	f_p->out_buff[1] = f_p->out_buff[0];
	f_p->out_buff[0] = out_sample;

	// store the output in the output address

	*audio_out = out_sample;
}
