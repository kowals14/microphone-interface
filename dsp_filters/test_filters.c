#include "filters.h"
#include "stdio.h"

int main() {
    double signal_in[5] = {0};
    double signal_out[5] = {0};

    user_params u_p = get_params(FILTER_LOWPASS, 5, 5, 0, 5);

    filter(signal_in, signal_out, 5, u_p);

    for (size_t i = 0; i < 5; i++)
    {
        printf("%f ", signal_out[i]);
    }    
}