#ifndef __FILTERS_H__
#define __FILTERS_H__
    #include <math.h>
    // #include <cmath.h>
    #include <assert.h>
    #include <string.h>
    
    #define M_PI 3.14159265358979323846

    typedef int FILTER_TYPE;

    #define FILTER_LOWPASS (FILTER_TYPE) 0
    #define FILTER_HIGHPASS (FILTER_TYPE) 1
    #define FILTER_BANDPASS (FILTER_TYPE) 2
    #define FILTER_NOTCH (FILTER_TYPE) 3

    struct _user_params
    {
        FILTER_TYPE type;
        double Fs;
        double f0;
        double dbGain;
        double BW;
    } typedef user_params;

    /**
     * @brief
     * Returns a struct of user-defined parameters, this is mostly just for testing in python 
    */
    user_params get_params(FILTER_TYPE type, double Fs, double f0, double dbGain, double BW);
    
    /**
     * @brief
     * Implementation of an IIR lowpass filter intended to be used with the 'filter' function.
     * @param in_buff 
     * buffer of the input signal
     * @param out_buff
     * buffer of the filtered signal 
     * @param user_params
     * array of user parameters
     * @return 
     * Filtered value of the current input element (in_buff[2])
     * @note
     * The formula used for the filter was taken from Robert Bristow-Johnson's audio cookbook.
     * @note
     * Link: https://webaudio.github.io/Audio-EQ-Cookbook/Audio-EQ-Cookbook.txt
    */
    double lowpass(double* in_buff, double* out_buff, user_params u_p);


    /**
     * @brief
     * Applies a specified filter function to the audio buffer. 
     * @param buff 
     * audio buffer
     * @param buff 
     * filtered buffer
     * @param size
     * size of the buffer
     * @param user_params
     * struct of user-defined parameters
     * @param filter
     * filter function to be applied
    */
    void filter(double* buff, double* out, int size, user_params u_p);
#endif