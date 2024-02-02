#ifndef __DELAY_H__ 
#define __DELAY_H__

    struct _user_params
    {
        double offset;
        double dbGain;
    } typedef user_params;

    user_params get_params(double offset, double dbGain);

    double* delay(double* buff, user_params u_p);

#endif