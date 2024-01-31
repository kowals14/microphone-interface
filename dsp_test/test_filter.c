#include "../dsp_filters/filters.h"
#include <stdlib.h>
#include <stdio.h>


int main() {

    double signal_in[10] = {0};
    double signal_out[10] = {0};
    
    user_params u_p = get_params(FILTER_LOWPASS, 10, 1, 0, 1);

    filter(signal_in, signal_out, 10, u_p);

    for(int i = 0; i < 10; i++) {
        printf("%f ", signal_out[i]);
    }

    return 0;
}