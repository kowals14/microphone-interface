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

//#define AUDIOFX_CNTR_RANGE	700

#define AUDIOFX_CNTR_SIZE	500
#define AUDIOFX_CNTR_MIN	50
#define AUDIOFX_CNTR_MAX	550

//#define INVERT_CNTR(CNTR)	(AUDIOFX_CNTR_RANGE-CNTR)

#define CNTR_TO_PRCNT(CNTR) 	( (CNTR-AUDIOFX_CNTR_MIN) / (AUDIOFX_CNTR_SIZE * 1.0f))
#define PRCNT_TO_CNTR(PRCNT) 	( (PRCNT * AUDIOFX_CNTR_SIZE) + AUDIOFX_CNTR_MIN)

#define CNTR_TO_PARAM(MAX,MIN,CNTR) 	(float)		((CNTR_TO_PRCNT(CNTR)*MAX)+MIN)
#define PARAM_TO_CNTR(MAX,MIN,PARAM) 	(uint32_t) 	(PRCNT_TO_CNTR((PARAM - MIN) / MAX))

void AUDIOFX_UpdateCounters(void);
void AUDIOFX_SwitchFX(uint8_t);
void AUDIOFX_Apply_FX_Chain(void);
void AUDIOFX_SetParams(AUDIOFX_Type);

#endif /* INC_AUDIOFX_H_ */
