/*
 * filters.h
 *
 *  Created on: Apr 10, 2024
 *      Author: Joshua Hom
 *      Derived From: https://www.youtube.com/watch?v=azLQf4aLv9w
 */

#ifndef __DISTORT_H__
#define __DISTORT_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <math.h>
#include "main.h"
#include "audioFX.h"
#include "trig_functions.h"

void DISTORT_Coef(float* params);

void DISTORT_Update(AUDIOFX_UserParams* u_p);

void DISTORT_Apply(int16_t* audio_in, int16_t* audio_out, AUDIOFX_UserParams* u_p);

#ifdef __cplusplus
}
#endif

#endif
