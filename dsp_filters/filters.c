#include "filters.h"
#include <math.h>
#include <assert.h>

# define PI 3.14159265358979323846

double lowpass(double* in_buff, double* out_buff, double* user_params) {

    double Fs = user_params[0];
    double f0 = user_params[1];
    double Q = user_params[2];

    double w0 = 2*PI*f0/Fs;

    double cos_w0 = cos(w0);
    double sin_w0 = sin(w0);
    
    double alpha = sin_w0/(2*Q);

    double b0 =  (1 - cos_w0) / 2;
    double b1 =   1 - cos_w0;
    double b2 =  (1 - cos_w0) / 2;
    double a0 =   1 + alpha;
    double a1 =  -2 * cos_w0;
    double a2 =   1 - alpha;

    return in_buff[0]*a2 + in_buff[1]*a1 + in_buff[2]*a0 + out_buff[0]*b2 + out_buff[1]*b1 + out_buff[2]*b0;
}


double* filter(double* buff, int size, double* user_params, double (*filter)(double*, double*, double*)) {
    assert(size <= 3 && "Size of buffer too small! Must be at least 3");

    double out[size];
    memset(out, 0, size*sizeof(double));

    double in_buff[3] = {0};
    double out_buff[3] = {0};

    for(int i = 0; i < size; i++) {
        in_buff[0] = in_buff[1];
        in_buff[1] = in_buff[2];
        in_buff[2] = buff[i];

        out_buff[0] = out_buff[1];
        out_buff[1] = out_buff[2];

        if(i > 0);
        out_buff[2] = out[i-1];

        out[i] = (*filter)(in_buff, out_buff, user_params);
    }

    return out;
}