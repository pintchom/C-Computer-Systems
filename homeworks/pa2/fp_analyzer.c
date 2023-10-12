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

void print_normalized(Converter converter) {
    
    UNSIGNED_INT_TYPE sign = converter.components.sign;
    UNSIGNED_INT_TYPE exponent = converter.components.exponent;
    UNSIGNED_INT_TYPE mantissa = converter.components.mantissa;

    int true_exponent = exponent - BIAS;

    FP_TYPE mantissa_decimal = mantissa / (FP_TYPE)(1ULL << MANTISSA_BITS); // FIGURE OUT WHAT THIS DOES

    FP_TYPE reconstituted = pow(-1, sign) * (1 + mantissa_decimal) * power_of_2(true_exponent); // GET RID OF POW SIGN USE 

    printf("Original value:\n");
    printf("(-1)^{" UFP_TYPE_FORMAT "} x (1 + %f) x 2^{%d}\n", sign, mantissa_decimal, true_exponent);
    printf("  = %f x %f\n", 1 + mantissa_decimal, power_of_2(true_exponent));
    printf("  = %.45f\n", reconstituted);

}

void print_denormalized(Converter converter) {
    
    UNSIGNED_INT_TYPE sign = converter.components.sign;
    UNSIGNED_INT_TYPE mantissa = converter.components.mantissa;

    int true_exponent = 1 - BIAS;

    
    FP_TYPE mantissa_decimal = mantissa / (FP_TYPE)(1ULL << MANTISSA_BITS);
   
    FP_TYPE reconstituted = pow(-1, sign) * mantissa_decimal * power_of_2(true_exponent);

    printf("Original value:\n"); // MAKE SURE ALL OF THESE MATCH EXACTLY THE EXAMPLES AND THAT THEY LOGICALLY MAKE SENSE 
    printf("(-1)^{" UFP_TYPE_FORMAT "} x (1 + " FP_TYPE_FORMAT ") x 2^{%d - %d}\n", sign, mantissa, converter.components.exponent, BIAS);
    printf("  = " UFP_TYPE_FORMAT " x 2^{" FP_TYPE_FORMAT "}\n", sign, mantissa_decimal, true_exponent);
    printf("  = " FP_TYPE_FORMAT " x " FP_TYPE_FORMAT "\n", mantissa_decimal, power_of_2(true_exponent));
    printf("  = " FP_TYPE_FORMAT "\n", reconstituted);

}

void print_reconstitution(Converter converter) {

    if (converter.components.exponent == 0) {
        print_denormalized(converter);
    } else {
        print_normalized(converter);
    }

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


