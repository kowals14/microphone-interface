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
 * Add and effect to the FX chain
 */
void AUDIOFX_Chain_Add(AUDIOFX_Chain_HandleTypeDef* hfxchn, AUDIOFX_UserParams* u_p) {

	for(uint8_t i = 0; i < AUDIOFX_MAX_CHAIN; i++) {
		// find first available slot in the chain
		if(!(hfxchn->fx_chain[i])) {
			hfxchn->fx_chain[i] = u_p;
			hfxchn->fx_count++;
			hfxchn->curr_fx = u_p;
			return;
		}
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

	TIM1->CNT = (uint32_t) (hfxchn->curr_fx->params[0] * AUDIOFX_CNTR_SIZE);
	TIM3->CNT = (uint32_t) (hfxchn->curr_fx->params[1] * AUDIOFX_CNTR_SIZE);
	TIM4->CNT = (uint32_t) (hfxchn->curr_fx->params[2] * AUDIOFX_CNTR_SIZE);

	hfxchn->fx_change_flag = 1;
}

static void FILTERS_Init(AUDIOFX_UserParams* u_p) {
	FILTERS_Params* f_p = (FILTERS_Params*) u_p->fx_params;

	f_p->in_buff[2] = 0;
	f_p->in_buff[1] = 0;
	f_p->in_buff[0] = 0;

	f_p->out_buff[1] = 0;
	f_p->out_buff[0] = 0;
}

static void DELAY_Init(AUDIOFX_UserParams* u_p) {
	DELAY_Params* d_p = (DELAY_Params*) u_p->fx_params;

	for(int i = 0; i < DELAY_LINE_SIZE; i++) {
		d_p->delay_line[i] = 0;
	}

	d_p->delay_line_index = 0;
}

void AUDIOFX_UserParams_Init(AUDIOFX_UserParams* u_p, AUDIOFX_Type type, void* fx_params) {
	u_p->type 				= type;
	u_p->param_change_flag 	= 0;
	u_p->fx_params 			= fx_params;

    switch (type)
    {
		case AUDIOFX_DELAY:
		{
			u_p->params[0] = 0.0f / 1.0f; // feedback
			u_p->params[1] = 0.0f / 1.0f; // mix
			u_p->params[2] = 0.0f / 1.0f; // delay time (s)

			DELAY_Init(u_p);
			DELAY_SetParams((DELAY_Params*) u_p->fx_params, u_p->params);

			break;
		}
		case AUDIOFX_DISTORTION:
		{
			u_p->params[0] = 0.0f / 1.0f;
			u_p->params[1] = 0.0f / 1.0f;
			u_p->params[2] = 0.0f / 1.0f;

			DISTORT_SetParams((DISTORT_Params*) u_p->fx_params, u_p->params);
			break;
		}
		case AUDIOFX_PKNG0:
		{
			u_p->params[0] = 6000.0f / 20000.0f;
			u_p->params[1] = 0.0f / 2.0f;
			u_p->params[2] = 25.0f / 1000.0f;
		}
		case AUDIOFX_PKNG1:
		{
			u_p->params[0] = 8000.0f / 20000.0f;
			u_p->params[1] = 0.0f / 2.0f;
			u_p->params[2] = 25.0f / 1000.0f;
		}
		case AUDIOFX_PKNG2:
		{
			u_p->params[0] = 10000.0f / 20000.0f;
			u_p->params[1] = 0.0f / 2.0f;
			u_p->params[2] = 25.0f / 1000.0f;
		}
		case AUDIOFX_PKNG3:
		{
			u_p->params[0] = 12000.0f / 20000.0f;
			u_p->params[1] = 0.0f / 2.0f;
			u_p->params[2] = 25.0f / 1000.0f;
		}
		case AUDIOFX_PKNG4:
		{
			u_p->params[0] = 14000.0f / 20000.0f;
			u_p->params[1] = 0.0f / 2.0f;
			u_p->params[2] = 25.0f / 1000.0f;
		}
		default: // EQ Bands
		{
			FILTERS_Init(u_p);
			FILTERS_SetParams((FILTERS_Params*) u_p->fx_params, u_p->params);
			break;
		}
    }
}

void AUDIOFX_UserParams_SetParams(AUDIOFX_UserParams* u_p, float t0, float t1, float t2) {
	u_p->params[0] = (1.0f - (t0 / (1.0f * AUDIOFX_CNTR_SIZE)));
	u_p->params[1] = (t1 / (1.0f * AUDIOFX_CNTR_SIZE));
	u_p->params[2] = (1.0f - (t0 / (1.0f * AUDIOFX_CNTR_SIZE)));

	switch (u_p->type)
	{
		case AUDIOFX_DELAY:
		{
			DELAY_SetParams((DELAY_Params*) u_p->fx_params, u_p->params);
			break;
		}
		case AUDIOFX_DISTORTION:
		{
			DISTORT_SetParams((DISTORT_Params*) u_p->fx_params, u_p->params);
			break;
		}
		default:	// EQ bands
		{
			FILTERS_SetParams((FILTERS_Params*) u_p->fx_params, u_p->params);
			break;
		}
	}

    u_p->param_change_flag = 1;
}


static int16_t AUDIOFX_Apply(int16_t audio_in, AUDIOFX_UserParams* u_p) {
	switch(u_p->type) {
		case AUDIOFX_DELAY:
			return DELAY_Apply(audio_in,(DELAY_Params*) u_p->fx_params);
		case AUDIOFX_DISTORTION:
			return DISTORT_Apply(audio_in,(DISTORT_Params*) u_p->fx_params);
		default:	// EQ
			return FILTERS_Apply(audio_in,(FILTERS_Params*) u_p->fx_params);
	}
}

static void AUDIOFX_Update(AUDIOFX_Chain_HandleTypeDef* hfxchn) {
	AUDIOFX_UserParams* u_p;

	for(size_t i = 0; i < hfxchn->fx_count; i++) {				// Go through each effect in the chain
		if((u_p = hfxchn->fx_chain[i])) {						// Check if valid
			// update the coefficients for current fx before processing
			if(u_p->param_change_flag) {
				switch(u_p->type) {
						case AUDIOFX_DELAY:
							DELAY_Update((DELAY_Params*) u_p->fx_params);
							break;
						case AUDIOFX_DISTORTION:
							DISTORT_Update((DISTORT_Params*) u_p->fx_params);
							break;
						default:	// EQ
							FILTERS_Update((FILTERS_Params*) u_p->fx_params);
							break;
					}
				u_p->param_change_flag = 0;
			}
		}
	}
}

/**
 * Apply each effect in the chain to the input signal
 */
void AUDIOFX_Apply_FX_Chain(AUDIOFX_Chain_HandleTypeDef* hfxchn) {
	AUDIOFX_UserParams* u_p;

	int16_t in_sample;

	AUDIOFX_Update(hfxchn); // Update all the effect's parameters

	for(int i = 0; i < AUDIOFX_BUFF_SIZE/2; i++) {
		in_sample = hfxchn->p_in_buff[i];							// Initialize the input as the sample from the input DMA buffer

		for(int j = 0; j < hfxchn->fx_count; j++) {					// Go through each effect in the chain
			if((u_p = hfxchn->fx_chain[j])) {						// Check if valid
				in_sample = AUDIOFX_Apply(in_sample, u_p);			// Apply effect to data in and store it back in the same variable for the next effect to use
			}
		}

		hfxchn->p_out_buff[i] = in_sample;							// Store the processed sample into the output DMA buffer
	}

}



