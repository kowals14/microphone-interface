#ifndef __FILTERS_H__
#define __FILTERS_H__
    double lowpass(double*, double*, double*);
    double* filter(double*, int, double*, double (double*,double*,double*));
    
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
    double lowpass(double* in_buff, double* out_buff, double* user_params);


    /**
     * @brief
     * Applies a specified filter function to the audio buffer. 
     * @param buff 
     * audio buffer
     * @param size
     * size of the buffer
     * @param user_params
     * array of user-defined parameters
     * @param filter
     * filter function to be applied
     * @return 
     * The filtered buffer.
    */
    double* filter(double* buff, int size, double* user_params, double(*filter)(double*, double*, double*));
#endif