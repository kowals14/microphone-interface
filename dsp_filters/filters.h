#ifndef __FILTERS_H__
#define __FILTERS_H__
    #include <math.h>
    #include <assert.h>
    #include <string.h>
    
    #define M_PI 3.14159265358979323846

    typedef int FILTER_TYPE;

    #define FILTER_LOWPASS (FILTER_TYPE) 0
    #define FILTER_HIGHPASS (FILTER_TYPE) 1
    #define FILTER_PEAKING (FILTER_TYPE) 2

    struct _user_params
    {
        FILTER_TYPE type;
        double Fs;
        double f0;
        double dbGain;
        double BW;
    } typedef user_params;

    user_params get_params(FILTER_TYPE type, double Fs, double f0, double dbGain, double BW);
    
    double lowpass(double* in_buff, double* out_buff, user_params u_p);
    double highpass(double* in_buff, double* out_buff, user_params u_p);
    double peaking(double* in_buff, double* out_buff, user_params u_p);

    void filter(double* buff, double* out, int size, user_params u_p);
#endif