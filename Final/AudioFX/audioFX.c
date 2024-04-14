/*
 * audioFX.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Jakub Kowalski
 */
#include "audioFX.h"
#include "filters.h"
#include "delay.h"
#include "distort.h"

extern int16_t* p_in_buff;
extern int16_t* p_out_buff;

extern FILTERS_Params f_p0;
extern FILTERS_Params f_p1;
extern FILTERS_Params f_p2;
extern FILTERS_Params f_p3;
extern FILTERS_Params f_p4;

extern DELAY_Params 	dl_p;
extern DISTORT_Params 	ds_p;

extern AUDIOFX_Type curr_fx;

/**
 * Switch the current FX to be controlled
 */
void AUDIOFX_Chain_SwitchFX(uint8_t dir) {
	if(dir) {
		curr_fx++;
	}
	else {
		curr_fx--;
	}

	if(curr_fx == AUDIOFX_MAX_CHAIN) {
		curr_fx = 0;
	}
	else if(curr_fx == -1) {
		curr_fx = AUDIOFX_MAX_CHAIN - 1;
	}

	// convert the current fx parameters to corresponding timer values
	switch(curr_fx) {
		case AUDIOFX_PKNG0:
				{
					TIM1->CNT = (uint32_t) ((((f_p0.f0 - 20.0f) / 20000.0f) + 1.0f)	* AUDIOFX_CNTR_SIZE);
					TIM3->CNT = (uint32_t) ((f_p0.BW - 1.0f)  / 500.0f 				* AUDIOFX_CNTR_SIZE);
					TIM4->CNT = (uint32_t) ((((f_p0.G  - 0.01f) / 10.0f) + 1.0f) 	* AUDIOFX_CNTR_SIZE);
				}
		case AUDIOFX_PKNG1:
				{
					TIM1->CNT = (uint32_t) ((((f_p1.f0 - 20.0f) / 20000.0f) + 1.0f)	* AUDIOFX_CNTR_SIZE);
					TIM3->CNT = (uint32_t) ((f_p1.BW - 1.0f)  / 500.0f 				* AUDIOFX_CNTR_SIZE);
					TIM4->CNT = (uint32_t) ((((f_p1.G  - 0.01f) / 10.0f) + 1.0f) 	* AUDIOFX_CNTR_SIZE);
				}
		case AUDIOFX_PKNG2:
				{
					TIM1->CNT = (uint32_t) ((((f_p2.f0 - 20.0f) / 20000.0f) + 1.0f)	* AUDIOFX_CNTR_SIZE);
					TIM3->CNT = (uint32_t) ((f_p2.BW - 1.0f)  / 500.0f 				* AUDIOFX_CNTR_SIZE);
					TIM4->CNT = (uint32_t) ((((f_p2.G  - 0.01f) / 10.0f) + 1.0f) 	* AUDIOFX_CNTR_SIZE);
				}
		case AUDIOFX_PKNG3:
				{
					TIM1->CNT = (uint32_t) ((((f_p3.f0 - 20.0f) / 20000.0f) + 1.0f)	* AUDIOFX_CNTR_SIZE);
					TIM3->CNT = (uint32_t) ((f_p3.BW - 1.0f)  / 500.0f 				* AUDIOFX_CNTR_SIZE);
					TIM4->CNT = (uint32_t) ((((f_p3.G  - 0.01f) / 10.0f) + 1.0f) 	* AUDIOFX_CNTR_SIZE);
				}
		case AUDIOFX_PKNG4:
				{
					TIM1->CNT = (uint32_t) ((((f_p4.f0 - 20.0f) / 20000.0f) + 1.0f)	* AUDIOFX_CNTR_SIZE);
					TIM3->CNT = (uint32_t) ((f_p4.BW - 1.0f)  / 500.0f 				* AUDIOFX_CNTR_SIZE);
					TIM4->CNT = (uint32_t) ((((f_p4.G  - 0.01f) / 10.0f) + 1.0f) 	* AUDIOFX_CNTR_SIZE);
				}
		case AUDIOFX_DELAY:
				{
					TIM1->CNT = (uint32_t) ((dl_p.mix + 1.0f) 							 * AUDIOFX_CNTR_SIZE);
					TIM3->CNT = (uint32_t) (dl_p.feedback 								 * AUDIOFX_CNTR_SIZE);
					TIM4->CNT = (uint32_t) (((dl_p.sample_len / DELAY_LINE_SIZE) + 1.0f) * AUDIOFX_CNTR_SIZE);
				}
		case AUDIOFX_DISTORTION:
				{
					TIM1->CNT = (uint32_t) (((ds_p.thrshld_gap / 10000000.0f) + 1.0f)	* AUDIOFX_CNTR_SIZE);
					TIM3->CNT = (uint32_t) ((ds_p.l_gain - 1.0f) 						* AUDIOFX_CNTR_SIZE);
					TIM4->CNT = (uint32_t) ((((ds_p.h_gain  - 0.01f) / 0.9f) + 1.0f)	* AUDIOFX_CNTR_SIZE);
				}
	}
}

void AUDIOFX_UserParams_SetParams(AUDIOFX_Type type, float t0, float t1, float t2) {
	float params[3];

	params[0] = (1.0f - (t0 / (1.0f * AUDIOFX_CNTR_SIZE)));
	params[1] = (t1 / (1.0f * AUDIOFX_CNTR_SIZE));
	params[2] = (1.0f - (t0 / (1.0f * AUDIOFX_CNTR_SIZE)));

	switch (type)
	{
		case AUDIOFX_DELAY:
		{
			float mix			= params[0] * 1.0;
			float feedback		= params[1] * 1.0;
			uint32_t sample_len	= (uint32_t) (params[3] * DELAY_LINE_SIZE);

			DELAY_SetParams(&dl_p, mix, feedback, sample_len);
			break;
		}
		case AUDIOFX_DISTORTION:
		{
			float gap 		= params[0] * 10000000.0f;
			float l_gain 	= params[1] + 1.0;
			float h_gain 	= params[2] * 0.9f + 0.01f;

			DISTORT_SetParams(&ds_p, gap, l_gain, h_gain);
			break;
		}
		case AUDIOFX_PKNG0:
		{

			float f0 = params[0] * 12000.0f + 20.0f;
			float BW = params[1] * 500.0f + 1.0f;
			float G  = params[2] * 10.0;

			FILTERS_SetParams(&f_p0, f0, BW, G);
			break;
		}
		case AUDIOFX_PKNG1:
		{

			float f0 = params[0] * 12000.0f + 20.0f;
			float BW = params[1] * 500.0f + 1.0f;
			float G  = params[2] * 10.0;

			FILTERS_SetParams(&f_p1, f0, BW, G);
			break;
		}
		case AUDIOFX_PKNG2:
		{

			float f0 = params[0] * 12000.0f + 20.0f;
			float BW = params[1] * 500.0f + 1.0f;
			float G  = params[2] * 10.0;

			FILTERS_SetParams(&f_p2, f0, BW, G);
			break;
		}
		case AUDIOFX_PKNG3:
		{

			float f0 = params[0] * 12000.0f + 20.0f;
			float BW = params[1] * 500.0f + 1.0f;
			float G  = params[2] * 10.0;

			FILTERS_SetParams(&f_p3, f0, BW, G);
			break;
		}
		case AUDIOFX_PKNG4:
		{

			float f0 = params[0] * 12000.0f + 20.0f;
			float BW = params[1] * 500.0f + 1.0f;
			float G  = params[2] * 10.0;

			FILTERS_SetParams(&f_p4, f0, BW, G);
			break;
		}
	}
}

void AUDIOFX_Apply_FX_Chain(void) {
	float left_in;
	float right_in;

	int16_t left_out;
	int16_t right_out;

	for(uint8_t n = 0; n < (AUDIOFX_BUFF_SIZE/2) - 1; n += 2) {
		left_in		= INT16_TO_FLOAT * ((float) p_in_buff[n]);
		right_in	= INT16_TO_FLOAT * ((float) p_in_buff[n + 1]);

//		left_in		= FILTERS_Apply(left_in, &f_p0);
//		right_in 	= FILTERS_Apply(right_in, &f_p0);

//		left_in		= FILTERS_Apply(left_in, &f_p1);
//		right_in 	= FILTERS_Apply(right_in, &f_p1);

//		left_in		= FILTERS_Apply(left_in, &f_p2);
//		right_in 	= FILTERS_Apply(right_in, &f_p2);

//		left_in		= FILTERS_Apply(left_in, &f_p3);
//		right_in 	= FILTERS_Apply(right_in, &f_p3);

//		left_in		= FILTERS_Apply(left_in, &f_p4);
//		right_in 	= FILTERS_Apply(right_in, &f_p4);

//		left_in		= DISTORT_Apply(left_in, &ds_p);
//		right_in 	= DISTORT_Apply(right_in, &ds_p);

//		left_in		= DELAY_Apply(left_in, &dl_p);
//		right_in 	= DELAY_Apply(right_in, &dl_p);

		left_out	= (int16_t) (FLOAT_TO_INT16 * left_in);
		right_out 	= (int16_t) (FLOAT_TO_INT16 * right_in);

		p_out_buff[n] 		= left_out;
		p_out_buff[n + 1] 	= right_out;
	}
}


