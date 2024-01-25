#ifdef __FOURIER_H__
#define __FOURIER_H__

float* dft(float*, int);

/**
 * @brief
 * Implementation of the discrete Fourier transform (DFT).
 * @param buff buffer for the signal to be tranformed.
*/
float* dft(float* buff, int len);

#endif