/*
 * filters.c
 *
 *  Created on: Jan 26, 2024
 *      Author: Jakub Kowalski
 *      Derived from Phil's Lab "Audio EQ Software Implementation": https://www.youtube.com/watch?v=4o-_gUht_Xc
 */

#include "filters.h"

void FILTERS_SetParams_PKNG(FILTERS_Params* f_p, float f0, float BW, float G) {
	f_p->f0 = f0;
	f_p->BW = BW;
	f_p->G  = G;

	float wcT = 2.0f * tanf(M_PI * (f0/2.0) * f_p->sampleTime_s);
	float Q = f0/BW;

	f_p->b[0] = 4.0f + 2.0f * (G  / Q) * wcT + wcT * wcT;
	f_p->b[1] = 2.0f * wcT * wcT - 8.0f;
	f_p->b[2] = 4.0f - 2.0f * (G  / Q) * wcT + wcT * wcT;

	f_p->a[0] = 1.0f / (4.0f + 2.0f / Q * wcT + wcT * wcT);
	f_p->a[1] = -(2.0f * wcT * wcT - 8.0f);
	f_p->a[2] = -(4.0f - 2.0f / Q * wcT + wcT * wcT);
}

void FILTERS_Init(FILTERS_Params* f_p) {
	f_p->sampleTime_s = 1.0f / AUDIOFX_SAMPLING_RATE;

	for (uint8_t n = 0; n < 3; n++) {
		f_p->x[n] = 0.0f;
		f_p->y[n] = 0.0f;
	}

	FILTERS_SetParams_PKNG(f_p, 20.0f, 1.0f, 1.0f);
}



float FILTERS_Apply(float in_sample, FILTERS_Params* f_p) {
	// Update the previous input buffer
	f_p->x[2] = f_p->x[1];
	f_p->x[1] = f_p->x[0];
	f_p->x[0] = in_sample;

	// Update the previous output buffer
	f_p->y[2] = f_p->y[1];
	f_p->y[1] = f_p->y[0];
	f_p->y[0] = (f_p->b[0] * f_p->x[0] + f_p->b[1] * f_p->x[1] + f_p->b[2] * f_p->x[2]
									  + (f_p->a[1] * f_p->y[1] + f_p->a[2] * f_p->y[2])) * f_p->a[0];

	return (f_p->y[0]);
}
