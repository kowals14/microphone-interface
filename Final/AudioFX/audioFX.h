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

#define AUDIOFX_PKNG0		(AUDIOFX_Type) 0
#define AUDIOFX_PKNG1		(AUDIOFX_Type) 1
#define AUDIOFX_PKNG2		(AUDIOFX_Type) 2
#define AUDIOFX_PKNG3		(AUDIOFX_Type) 3
#define AUDIOFX_PKNG4		(AUDIOFX_Type) 4
#define AUDIOFX_DELAY		(AUDIOFX_Type) 5
#define AUDIOFX_DISTORTION	(AUDIOFX_Type) 6

#define AUDIOFX_MAX_CHAIN 	 7

#define AUDIOFX_CNTR_SIZE			400

void AUDIOFX_Chain_SwitchFX(uint8_t);
void AUDIOFX_Apply_FX_Chain(void);
void AUDIOFX_UserParams_SetParams(AUDIOFX_Type type, float p0, float p1, float p2);

#endif /* INC_AUDIOFX_H_ */
