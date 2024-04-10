/*
 * audioFX.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Jakub Kowalski
 */
#include "audioFX.h"
#include "filters.h"

/**
 * Initialize the FX chain as empty
 */
void AUDIOFX_Chain_Init(AUDIOFX_Chain_HandleTypeDef* hfxchn) {
	hfxchn->fx_count = 0;
	hfxchn->curr_fx = NULL;
	for(uint8_t i = 0; i < AUDIOFX_MAX_CHAIN; i++) {
		// initialize each function pointer as a NULL to indicate empty FX slot
		hfxchn->fx_chain[i] = NULL;						
	}
}

/**
 * Switch the current FX to be controlled
 */
void AUDIOFX_Chain_SwitchFX(AUDIOFX_Chain_HandleTypeDef* hfxchn, uint8_t dir) {
	int8_t idx = hfxchn->curr_fx->type;

	if(dir) {
		idx++;
	}
	else {
		idx--;
	}

	if(idx == AUDIOFX_MAX_CHAIN) {
		idx = 0;
	}
	else if(idx == -1) {
		idx = AUDIOFX_MAX_CHAIN - 1;
	}

	hfxchn->curr_fx = hfxchn->fx_chain[idx];

	TIM1->CNT = (uint32_t) (hfxchn->curr_fx->params[0] * AUDIOFX_CNTR_SIZE / (hfxchn->curr_fx->max_param[0]));
	TIM3->CNT = (uint32_t) (hfxchn->curr_fx->params[1] * AUDIOFX_CNTR_SIZE / (hfxchn->curr_fx->max_param[1]));
	TIM4->CNT = (uint32_t) (hfxchn->curr_fx->params[2] * AUDIOFX_CNTR_SIZE / (hfxchn->curr_fx->max_param[2]));

	hfxchn->fx_change_flag = 1;
}

/**
 * Add and effect to the FX chain
 */
void AUDIOFX_Chain_Add(AUDIOFX_Chain_HandleTypeDef* hfxchn, AUDIOFX_UserParams* hfx) {

	for(uint8_t i = 0; i < AUDIOFX_MAX_CHAIN; i++) {
		// find first available slot in the chain
		if(!(hfxchn->fx_chain[i])) {
			(hfxchn->fx_chain)[i] = hfx;
			hfxchn->fx_count++;
			hfxchn->curr_fx = hfx;
			return;
		}
	}
}

void AUDIOFX_UserParams_Init(AUDIOFX_UserParams* u_p, AUDIOFX_Type type) {
	u_p->type = type;

	u_p->in_buff[2] = 0;
	u_p->in_buff[1] = 0;
	u_p->in_buff[0] = 0;

	u_p->out_buff[1] = 0;
	u_p->out_buff[0] = 0;

	u_p->param_change_flag = 0;

    switch (type)
    {
		case AUDIOFX_HPF:
		{
			u_p->params[0] = 1000.0;
			u_p->params[1] = 0;
			u_p->params[2] = 0.5;

			FILTERS_Coef_HPF(u_p->b, u_p->a, u_p->params);

			break;
		}
		case AUDIOFX_PKNG1:
		{
			u_p->params[0] = 5000.0;
			u_p->params[1] = 0;
			u_p->params[2] = 0.5;

			FILTERS_Coef_PKNG(u_p->b, u_p->a, u_p->params);

			break;
		}
		case AUDIOFX_PKNG2:
		{
			u_p->params[0] = 10000.0;
			u_p->params[1] = 0;
			u_p->params[2] = 0.5;

			FILTERS_Coef_PKNG(u_p->b, u_p->a, u_p->params);

			break;
		}
		case AUDIOFX_PKNG3:
		{
			u_p->params[0] = 15000.0;
			u_p->params[1] = 0;
			u_p->params[2] = 0.5;

			FILTERS_Coef_PKNG(u_p->b, u_p->a, u_p->params);

			break;
		}
		case AUDIOFX_LPF:
		{
			u_p->params[0] = 20000.0;
			u_p->params[1] = 0;
			u_p->params[2] = 0.5;

			FILTERS_Coef_LPF(u_p->b, u_p->a, u_p->params);

		    break;
		}
		default:
		{
			u_p->b[0] =   1;
			u_p->b[1] =   0;
			u_p->b[2] =   0;

			u_p->a[0] =   1;
			u_p->a[1] =   0;
			u_p->a[2] =   0;

			break;
		}
    }
}

void AUDIOFX_UserParams_Calculate(AUDIOFX_UserParams* u_p, float p0, float p1, float p2) {

	// calculate all the coefficients and store them in temporary variables
	switch (u_p->type)
	{
		case AUDIOFX_HPF:
		{
			if(!p0)
				p0 = 0.001;
			if(!p2)
				p2 = 0.001;

			// save the parameter values for returning to effect later
			u_p->params[0] = 20000.0 - (p0 / (1.0f * AUDIOFX_CNTR_SIZE)) * 20000.0;
			u_p->params[1] = (p1 / (1.0f * AUDIOFX_CNTR_SIZE)) * 40.0;
			u_p->params[2] = 2.0 - (p2 / (1.0f * AUDIOFX_CNTR_SIZE)) * 2.0;

			FILTERS_Coef_HPF(u_p->temp_b, u_p->temp_a, u_p->params);
			break;
		}
		case AUDIOFX_PKNG1:
		case AUDIOFX_PKNG2:
		case AUDIOFX_PKNG3:
		{
			if(!p0)
				p0 = 0.001;
			if(!p2)
				p2 = 0.001;

			// save the parameter values for returning to effect later
			u_p->params[0] = 20000.0 - (p0 / (1.0f * AUDIOFX_CNTR_SIZE)) * 20000.0;
			u_p->params[1] = (p1 / (1.0f * AUDIOFX_CNTR_SIZE)) * 40.0;
			u_p->params[2] = 2.0 - (p2 / (1.0f * AUDIOFX_CNTR_SIZE)) * 2.0;

			FILTERS_Coef_PKNG(u_p->temp_b, u_p->temp_a, u_p->params);
			break;
		}
		case AUDIOFX_LPF:
		{
			if(!p0)
				p0 = 0.001;
			if(!p2)
				p2 = 0.001;

			// save the parameter values for returning to effect later
			u_p->params[0] = 20000.0 - (p0 / (1.0f * AUDIOFX_CNTR_SIZE)) * 20000.0;
			u_p->params[1] = (p1 / (1.0f * AUDIOFX_CNTR_SIZE)) * 40.0;
			u_p->params[2] = 2.0 - (p2 / (1.0f * AUDIOFX_CNTR_SIZE)) * 2.0;

			FILTERS_Coef_LPF(u_p->temp_b, u_p->temp_a, u_p->params);
			break;
		}
		default:
		{
			// save the parameter values for returning to effect later
			u_p->params[0] = (p0 / (1.0f * AUDIOFX_CNTR_SIZE)) * 20000.0;
			u_p->params[1] = (p1 / (1.0f * AUDIOFX_CNTR_SIZE)) * 40.0;
			u_p->params[2] = (p2 / (1.0f * AUDIOFX_CNTR_SIZE)) * 2.0;

			u_p->temp_b[0] =   1;
			u_p->temp_b[1] =   0;
			u_p->temp_b[2] =   0;

			u_p->temp_a[0] =   1;
			u_p->temp_a[1] =   0;
			u_p->temp_a[2] =   0;

			break;
		}
	}

    u_p->param_change_flag = 1;
}

/**
 * Apply each effect in the chain to the input signal
 */
void AUDIOFX_Apply_FX_Chain(AUDIOFX_Chain_HandleTypeDef* hfxchn) {
	AUDIOFX_UserParams* hfx = hfxchn->curr_fx;

	void(*dsp_fx)(int16_t*, int16_t*, AUDIOFX_UserParams*);
	void(*update)(AUDIOFX_UserParams*);

	switch(hfx->type) {
	case AUDIOFX_HPF:
	case AUDIOFX_LPF:
	case AUDIOFX_PKNG1:
	case AUDIOFX_PKNG2:
	case AUDIOFX_PKNG3:
		dsp_fx = FILTERS_Apply;
		update = FILTERS_Update;
		break;
	default:
		dsp_fx = FILTERS_Apply;
		update = FILTERS_Update;
		break;
	}

	int16_t buff[AUDIOFX_BUFF_SIZE/2] = {0};

	int16_t* audio_in = (hfxchn->p_in_buff);
	int16_t* audio_out = buff;
	int16_t* temp;

	for(size_t i = 0; i < hfxchn->fx_count; i++) {				// Go through each effect in the chain
		if((hfx = hfxchn->fx_chain[i])) {						// Check if valid function pointer

			// update the coefficients for current fx before processing
			update(hfx);

			// for the last effect, we want the output to go into our DMA output buffer
			if(i == hfxchn->fx_count - 1) {
				audio_out = (hfxchn->p_out_buff);
			}

			dsp_fx(audio_in, audio_out, hfx);	// Apply effect to data in and store in audio_out

			// swap the buffers so that the last output becomes the new input and vice versa
			temp 		= audio_out;
			audio_out 	= audio_in;
			audio_in 	= temp;
		}
	}
}



