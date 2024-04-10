/*
 * trig_functions.c
 *
 *  Created on: Mar 23, 2024
 *      Author: Jakub Kowalski
 */

#include "trig_functions.h"

float LUT_Lin_Extrpltn(float* table, float x, int xk_1, int xk) {
	float yk_1 	= table[xk_1];
	float yk 	= table[xk];

	return yk_1 + (((float)(x - xk_1) * (yk - yk_1)) / (float)(xk - xk_1));
}

float LUT_Lin_Intrpltn(float* table, float x, int x0, int x1) {
	if(x1 >= LUT_SIZE) {
		return LUT_Lin_Extrpltn(table, x, --x0, --x1);
	}

	float y0 = table[x0];
	float y1 = table[x1];

	return (y0 * (float) (x1 - x) + y1 * (float) (x - x0)) / (float) (x1 - x0);
}

void LUT_Table_Init(float* table, double(*trig_func)(double)) {
	for(uint32_t i = 0; i < LUT_SIZE; i++) {
		table[i] = (float) trig_func(i * LUT_STEP);
	}
}

float LUT_Table_Get(float input, float* table) {
	// for values greater than supported by the table
	while(input > M_TWOPI) {
		input -= M_TWOPI;
	}

	float indx = ((input) / LUT_STEP);

	if(indx > (int) indx){
		return LUT_Lin_Intrpltn(table, indx, (int)indx, ((int)indx)+1);
	}

	return table[(int) indx];
}
