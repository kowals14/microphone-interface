/*
 * audioFX.h
 *
 *  Created on: Mar 20, 2024
 *      Author: Jakub Kowalski
 */

#ifndef INC_AUDIOFX_H_
#define INC_AUDIOFX_H_

#include "main.h"

typedef int8_t AUDIOFX_Type;

#define AUDIOFX_HPF			(AUDIOFX_Type) 0
#define AUDIOFX_PKNG1		(AUDIOFX_Type) 1
#define AUDIOFX_PKNG2		(AUDIOFX_Type) 2
#define AUDIOFX_PKNG3		(AUDIOFX_Type) 3
#define AUDIOFX_LPF			(AUDIOFX_Type) 4
#define AUDIOFX_DELAY		(AUDIOFX_Type) 5
#define AUDIOFX_DISTORTION	(AUDIOFX_Type) 6

#define  AUDIOFX_MAX_DELAY	(1)
#define  AUDIOFX_DELAY_LINE_SIZE	(int) (AUDIOFX_SAMPLING_RATE * AUDIOFX_MAX_DELAY)

typedef struct __AUDIOFX_UserParams
{
	/**
	 * Global FX Variables
	 */

	AUDIOFX_Type type;

	float params[3];
	float max_param[3];	// max values for each parmeter
	float min_param[3];	// min values for each parmeter

	uint8_t param_change_flag;

	/**
	 * Filter specific variables
	 */

	// Previous outputs/inputs
	float in_buff[3];
	float out_buff[2];

	// IIR Coefficients
	float b[3];
	float a[3];
	float temp_b[3];
	float temp_a[3];

	/**
	 * Delay specific variables
	 */

	float delay_mix[2];
	float delay_feedback;
	uint32_t delay_sample_len;

	float temp_delay_mix[2];
	float temp_delay_feedback;
	uint32_t temp_delay_sample_len;

} AUDIOFX_UserParams;

typedef struct __AUDIOFX_Chain_HandleTypeDef {
	uint8_t fx_count;		// number of fx in the chain

	int16_t* p_in_buff;		// pointer to the address of the beginning of the input buffer
	int16_t* p_out_buff;	// pointer to the address of the beginning of the output buffer

	AUDIOFX_UserParams* fx_chain[AUDIOFX_MAX_CHAIN];
	AUDIOFX_UserParams*	curr_fx;	// pointer to the current effect being edited

	uint8_t	fx_change_flag;
} AUDIOFX_Chain_HandleTypeDef;

void AUDIOFX_Chain_Init(AUDIOFX_Chain_HandleTypeDef*);
void AUDIOFX_Chain_SwitchFX(AUDIOFX_Chain_HandleTypeDef*, uint8_t);
void AUDIOFX_Chain_Add(AUDIOFX_Chain_HandleTypeDef*, AUDIOFX_UserParams*);
void AUDIOFX_Apply_FX_Chain(AUDIOFX_Chain_HandleTypeDef*);
void AUDIOFX_UserParams_Init(AUDIOFX_UserParams* u_p, AUDIOFX_Type type);
void AUDIOFX_UserParams_Calculate(AUDIOFX_UserParams* u_p, float p0, float p1, float p2);
#endif /* INC_AUDIOFX_H_ */
