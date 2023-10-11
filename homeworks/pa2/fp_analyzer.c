#include "fp_analyzer.h"
#include <math.h> 
#include <stdio.h>

void print_bits(UNSIGNED_INT_TYPE value, int num_bits) {

    for (int i = num_bits - 1; i >= 0; i--) {

        if (value & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

void print_components(Converter converter) {
    printf("All bits: ");
    print_bits(converter.components.sign, 1);
    print_bits(converter.components.exponent, EXPONENT_BITS);
    print_bits(converter.components.mantissa, MANTISSA_BITS);
    printf("\nSign: ");
    print_bits(converter.components.sign, 1);
    printf("\nExponent: ");
    print_bits(converter.components.exponent, EXPONENT_BITS);
    printf("\nMantissa: ");
    print_bits(converter.components.mantissa, MANTISSA_BITS);
    printf("\n");
}

FP_TYPE power_of_2(int exponent) {

    FP_TYPE result = 1.0;

    if (exponent >= 0) {
        //printf(FP_TYPE_FORMAT "\n", result);
        for (int i = 0; i < exponent; i++) {
            result *= 2.0;
            //printf(FP_TYPE_FORMAT "\n", result);
        } 
    }

    else {
        //printf(FP_TYPE_FORMAT "\n", result);
        for (int i = 0; i > exponent; i--) {
            result /= 2.0;
            //printf(FP_TYPE_FORMAT "\n", result);
        }
    }

    return result;
}


