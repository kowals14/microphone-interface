#ifndef __FOURIER_H__
#define __FOURIER_H__

double* dft(double*, int);

/**
 * @brief
 * Implementation of the discrete Fourier transform (DFT).
 * @param buff 
 * buffer for the signal to be tranformed.
 * @param size
 * size of the buffer
*/
double* dft(double* buff, int size);

#endif