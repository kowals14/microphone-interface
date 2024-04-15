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

extern uint8_t update_flags;
extern uint16_t timer_count[3];

/**
 * Switch the current FX to be controlled
 */
void AUDIOFX_SwitchFX(uint8_t dir) {
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

void AUDIOFX_SetParams(AUDIOFX_Type fx) {
	float params[3];

	// convert timer counter to percentage

	params[0] = (1.0f - (timer_count[0] / AUDIOFX_CNTR_SIZE));
	params[1] = (timer_count[1] / AUDIOFX_CNTR_SIZE);
	params[2] = (1.0f - (timer_count[2] / AUDIOFX_CNTR_SIZE));

	// set the new parameters as temporary and set the update flag for the corresponding effect

	switch (fx)
	{
		case AUDIOFX_DELAY:
		{
			dl_p.temp[0] = params[0] * 1.0;		// mix
			dl_p.temp[1] = params[1] * 1.0;		// feedback
			dl_p.temp[2] = params[3] * 1000.0;	// delay time

			update_flags |= UPDATE_DELAY;

			break;
		}
		case AUDIOFX_DISTORTION:
		{
			ds_p.temp[0] = params[0] * 10000000.0f;		// threshold gap
			ds_p.temp[1] = params[1] + 1.0;				// l_gain
			ds_p.temp[2] = params[2] * 0.9f + 0.01f;	// h_gain

			update_flags |= UPDATE_DISTORT;

			break;
		}
		case AUDIOFX_PKNG0:
		{

			f_p0.temp[0] = params[0] * 12000.0f + 20.0f;	// center frequency
			f_p0.temp[1] = params[1] * 500.0f + 1.0f;		// bandwidth
			f_p0.temp[2] = params[2] * 10.0;				// boost/cut

			update_flags |= UPDATE_FILTER0;

			break;
		}
		case AUDIOFX_PKNG1:
		{

			f_p1.temp[0] = params[0] * 12000.0f + 20.0f;	// center frequency
			f_p1.temp[1] = params[1] * 500.0f + 1.0f;		// bandwidth
			f_p1.temp[2] = params[2] * 10.0;				// boost/cut

			update_flags |= UPDATE_FILTER1;

			break;
		}
		case AUDIOFX_PKNG2:
		{

			f_p2.temp[0] = params[0] * 12000.0f + 20.0f;	// center frequency
			f_p2.temp[1] = params[1] * 500.0f + 1.0f;		// bandwidth
			f_p2.temp[2] = params[2] * 10.0;				// boost/cut

			update_flags |= UPDATE_FILTER2;

			break;
		}
		case AUDIOFX_PKNG3:
		{

			f_p3.temp[0] = params[0] * 12000.0f + 20.0f;	// center frequency
			f_p3.temp[1] = params[1] * 500.0f + 1.0f;		// bandwidth
			f_p3.temp[2] = params[2] * 10.0;				// boost/cut

			update_flags |= UPDATE_FILTER3;

			break;
		}
		case AUDIOFX_PKNG4:
		{

			f_p4.temp[0] = params[0] * 12000.0f + 20.0f;	// center frequency
			f_p4.temp[1] = params[1] * 500.0f + 1.0f;		// bandwidth
			f_p4.temp[2] = params[2] * 10.0;				// boost/cut

			update_flags |= UPDATE_FILTER4;

			break;
		}
	}
}

void AUDIOFX_Apply_FX_Chain(void) {
	float left_in;
	float right_in;

	int16_t left_out;
	int16_t right_out;

	if(update_flags) {
		// check the update flags
		if(update_flags & UPDATE_DELAY) {
			DELAY_SetParams(&dl_p, dl_p.temp[0], dl_p.temp[1], dl_p.temp[2]);
		}
		if(update_flags & UPDATE_DISTORT) {
			DISTORT_SetParams(&ds_p, ds_p.temp[0], ds_p.temp[1], ds_p.temp[2]);
		}
		if(update_flags & UPDATE_FILTER0) {
			FILTERS_SetParams(&f_p0, f_p0.temp[0], f_p0.temp[1], f_p0.temp[2]);
		}
		if(update_flags & UPDATE_FILTER1) {
			FILTERS_SetParams(&f_p1, f_p1.temp[0], f_p1.temp[1], f_p1.temp[2]);
		}
		if(update_flags & UPDATE_FILTER2) {
			FILTERS_SetParams(&f_p2, f_p2.temp[0], f_p2.temp[1], f_p2.temp[2]);
		}
		if(update_flags & UPDATE_FILTER3) {
			FILTERS_SetParams(&f_p3, f_p3.temp[0], f_p3.temp[1], f_p3.temp[2]);
		}
		if(update_flags & UPDATE_FILTER4) {
			FILTERS_SetParams(&f_p4, f_p4.temp[0], f_p4.temp[1], f_p4.temp[2]);
		}

		// clear the flags
		update_flags = 0;
	}

	for(uint8_t n = 0; n < (AUDIOFX_BUFF_SIZE/2) - 1; n += 2) {
		left_in		= INT16_TO_FLOAT * ((float) p_in_buff[n]);
		right_in	= INT16_TO_FLOAT * ((float) p_in_buff[n + 1]);

		left_in		= FILTERS_Apply(left_in, &f_p0);
		right_in 	= FILTERS_Apply(right_in, &f_p0);

		left_in		= FILTERS_Apply(left_in, &f_p1);
		right_in 	= FILTERS_Apply(right_in, &f_p1);

		left_in		= FILTERS_Apply(left_in, &f_p2);
		right_in 	= FILTERS_Apply(right_in, &f_p2);

		left_in		= FILTERS_Apply(left_in, &f_p3);
		right_in 	= FILTERS_Apply(right_in, &f_p3);

		left_in		= FILTERS_Apply(left_in, &f_p4);
		right_in 	= FILTERS_Apply(right_in, &f_p4);

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


