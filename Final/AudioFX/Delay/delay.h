/*
 * delay.h
 *
 *  Created on: Apr 10, 2024
 *      Author: Jakub Kowalski
 */

#ifndef DELAY_DELAY_H_
#define DELAY_DELAY_H_

#include "audiofx.h"

void DELAY_Update(AUDIOFX_UserParams* u_p);

void DELAY_Apply(int16_t* audio_in, int16_t* audio_out, AUDIOFX_UserParams* u_p);

#endif /* DELAY_DELAY_H_ */
