#ifndef __FILTERS_H__
#define __FILTERS_H__
    #include <math.h>
    #include <assert.h>
    #include <string.h>
    #include "config.h"
    
    #define M_PI 3.14159265358979323846

    typedef int FILTER_TYPE;

    #define FILTER_LOWPASS (FILTER_TYPE) 0
    #define FILTER_HIGHPASS (FILTER_TYPE) 1
    #define FILTER_PEAKING (FILTER_TYPE) 2

    struct _user_params
    {
        FILTER_TYPE type;
        int f0; // 20 - 20KHz
        float dbGain; 
        float BW;
    } typedef user_params;

    user_params get_params(FILTER_TYPE type, int f0, int dbGain, float BW);
    
    float lowpass(float* in_buff, float* out_buff, user_params u_p);
    float highpass(float* in_buff, float* out_buff, user_params u_p);
    float peaking(float* in_buff, float* out_buff, user_params u_p);

    void filter(float* buff, float* out, int size, user_params u_p);
#endif