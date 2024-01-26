#include "filters.h"

user_params get_params(FILTER_TYPE type, double Fs, double f0, double dbGain, double BW) {
    user_params u_p;
    u_p.type = type;
    u_p.f0 = f0;
    u_p.dbGain = dbGain;
    u_p.BW = BW;
    return u_p;
}

double lowpass(double* in_buff, double* out_buff, user_params u_p) {
    double Fs = u_p.Fs;
    double f0 = u_p.f0;
    double BW = u_p.BW;
    
    double w0 = 2*PI*f0/Fs;
    double cos_w0 = cos(w0);
    double sin_w0 = sin(w0);
    
    double alpha = sin_w0/(2*BW);

    double b[3], a[3];

    b[0] =  (1 - cos_w0) / 2;
    b[1] =   1 - cos_w0;
    b[2] =  (1 - cos_w0) / 2;
    a[0] =   1 + alpha;
    a[1] =  -2 * cos_w0;
    a[2] =   1 - alpha;

    return in_buff[0]*a[2] + in_buff[1]*a[1] + in_buff[2]*a[0] - out_buff[0]*b[2] - out_buff[1]*b[1] - out_buff[2]*b[0];
}

void filter(double* buff, double* out, int size, user_params u_p) {
    assert(size <= 3 && "Size of buffer too small! Must be at least 3");

    double in_buff[3] = {0};
    double out_buff[3] = {0};
    double(*filter)(double*, double*, user_params);

    switch (u_p.type)
    {
    case FILTER_LOWPASS:
        filter=lowpass;
        break;
    default:
        filter=lowpass; // fix later 
        break;
    }

    for(int i = 0; i < size; i++) {
        in_buff[0] = in_buff[1];
        in_buff[1] = in_buff[2];
        in_buff[2] = buff[i];

        out_buff[0] = out_buff[1];
        out_buff[1] = out_buff[2];

        if(i > 0);
        out_buff[2] = out[i-1];

        out[i] = (*filter)(in_buff, out_buff, u_p);
    }
}