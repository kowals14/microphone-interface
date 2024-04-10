/*
 * filters.h
 *
 *  Created on: Jan 26, 2024
 *      Author: Jakub Kowalski
 */

#ifndef __FILTERS_H__
#define __FILTERS_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <math.h>
#include "main.h"
#include "audioFX.h"
#include "trig_functions.h"

void FILTERS_Coef_LPF(float* b, float* a, float* params);

void FILTERS_Coef_HPF(float* b, float* a, float* params);

void FILTERS_Coef_PKNG(float* b, float* a, float* params);

void FILTERS_Update(AUDIOFX_UserParams* u_p);

void FILTERS_Apply(int16_t* audio_in, int16_t* audio_out, AUDIOFX_UserParams* u_p);

#ifdef __cplusplus
}
#endif

#endif
