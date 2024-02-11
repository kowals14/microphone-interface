#include "filters.h"

user_params get_params(FILTER_TYPE type, int f0, int dbGain, float BW) {
    user_params u_p;
    u_p.type = type;
    u_p.f0 = f0;
    u_p.dbGain = dbGain;
    u_p.BW = BW;
    return u_p;
}

const float* lut_cos[32];

float lowpass(float* in_buff, float* out_buff, user_params u_p) {
    int f0 = u_p.f0;
    float BW = u_p.BW;
    
    float w0 = 2 * M_PI * f0 / CFG_SAMPLE_RATE;
    float cos_w0 = cos(w0);
    float sin_w0 = sin(w0);
    
    float alpha = sin_w0/(2*BW);

    float b[3], a[3];

    b[0] =  (1 - cos_w0) / 2;
    b[1] =   1 - cos_w0;
    b[2] =  (1 - cos_w0) / 2;

    a[0] =   1 + alpha;
    a[1] =  -2 * cos_w0;
    a[2] =   1 - alpha;

    return (-out_buff[0]*a[1] - out_buff[1]*a[2] + in_buff[0]*b[0] + in_buff[1]*b[1] + in_buff[2]*b[2])/a[0];
}

float highpass(float* in_buff, float* out_buff, user_params u_p) {
    float f0 = u_p.f0;
    float BW = u_p.BW;
    
    float w0 = 2 * M_PI * f0 / CFG_SAMPLE_RATE;
    float cos_w0 = cos(w0);
    float sin_w0 = sin(w0);
    
    float alpha = sin_w0/(2*BW);

    float b[3], a[3];

    b[0] =  (1 + cos_w0)/2;
    b[1] = -(1 + cos_w0);
    b[2] =  (1 + cos_w0)/2;
    
    a[0] =   1 + alpha;
    a[1] =  -2 * cos_w0;
    a[2] =   1 - alpha;

    return (-out_buff[0]*a[1] - out_buff[1]*a[2] + in_buff[0]*b[0] + in_buff[1]*b[1] + in_buff[2]*b[2])/a[0];
}

float peaking(float* in_buff, float* out_buff, user_params u_p) {
    float f0 = u_p.f0;
    float BW = u_p.BW;
    float dbGain = u_p.dbGain;
    
    float w0 = 2 * M_PI * f0 / CFG_SAMPLE_RATE;
    float cos_w0 = cos(w0);
    float sin_w0 = sin(w0);
    float A = pow(10, (dbGain / 40));
    
    float alpha = sin_w0/(2*BW);

    float b[3], a[3];

    b[0] =   1 + alpha * A;
    b[1] =  -2 * cos_w0;
    b[2] =   1 - alpha * A;
    
    a[0] =   1 + alpha / A;
    a[1] =  -2 * cos_w0;
    a[2] =   1 - alpha / A;

    return (-out_buff[0]*a[1] - out_buff[1]*a[2] + in_buff[0]*b[0] + in_buff[1]*b[1] + in_buff[2]*b[2])/a[0];
}

float passthrough(float* in_buff, float* out_buff, user_params u_p) {
    return in_buff[0];
}

void filter(float* buff, float* out, int size, user_params u_p) {
    assert(size >= 3 && "Size of buffer too small! Must be at least 3");

    float in_buff[3] = {0};
    float out_buff[2] = {0};
    float(*filter)(float*, float*, user_params);

    switch (u_p.type)
    {
    case FILTER_LOWPASS:
        filter=lowpass;
        break;
    case FILTER_HIGHPASS:
        filter=highpass;
        break;
    case FILTER_PEAKING:
        filter=peaking;
        break;
    default:
        filter=passthrough; // no filter applied 
        break;
    }

    for(int i = 0; i < size; i++) {

        in_buff[2] = in_buff[1];
        in_buff[1] = in_buff[0];
        in_buff[0] = buff[i];
        
        if(i > 0) {
            out_buff[1] = out_buff[0];
            out_buff[0] = out[i-1];
        }

        out[i] = (*filter)(in_buff, out_buff, u_p);
    }
}