/*
 * trig_functions.h
 *
 *  Created on: Mar 23, 2024
 *      Author: Jakub Kowalski
 */

#ifndef LUTS_TRIG_FUNCTIONS_H_
#define LUTS_TRIG_FUNCTIONS_H_

#include <math.h>
#include "main.h"

#define LUT_SIZE	2048
#define LUT_STEP  	((M_TWOPI) / (LUT_SIZE - 1))

float LUT_Lin_Extrpltn(float*, float, int, int);
float LUT_Lin_Intrpltn(float*, float, int, int);

void  LUT_Table_Init(float*, double(*)(double));
float LUT_Table_Get(float, float*);

#endif /* LUTS_TRIG_FUNCTIONS_H_ */
