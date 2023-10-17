#include "fp_analyzer.h"
#include <stdio.h>

void print_bits(UNSIGNED_INT_TYPE value, int num_bits) {

    for (int i = num_bits - 1; i >= 0; i--) {

        if (value & (1ULL << i)) {
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

    FP_TYPE mantissa_decimal = mantissa / (FP_TYPE)(1ULL << MANTISSA_BITS); 
    
    if (sign < 1) {  

        FP_TYPE reconstituted = 1 * (1 + mantissa_decimal) * power_of_2(true_exponent); 
        
        printf("Original value:\n");
        printf("(-1)^{0} x (1 + %f) x 2^{" UFP_TYPE_FORMAT " - %d}\n", mantissa_decimal, exponent, BIAS);
        printf("  = 1 x %f x 2^{%d}\n", 1 + mantissa_decimal, true_exponent);
        printf("  = %f x %.0f\n", 1 + mantissa_decimal, power_of_2(true_exponent));
        printf("  = %.45f\n", reconstituted);

    } else {

        FP_TYPE reconstituted = -1 * (1 + mantissa_decimal) * power_of_2(true_exponent);         

        printf("Original value:\n");
        printf("(-1)^{1} x (1 + %f) x 2^{" UFP_TYPE_FORMAT " - %d}\n", mantissa_decimal, exponent, BIAS);
        printf("  = -1 x %f x 2^{%d}\n", 1 + mantissa_decimal, true_exponent);
        printf("  = -1 x %f x %.0f\n", 1 + mantissa_decimal, power_of_2(true_exponent));
        printf("  = %.45f\n", reconstituted);
    }
}

void print_denormalized(Converter converter) {
    
    UNSIGNED_INT_TYPE mantissa = converter.components.mantissa;
    UNSIGNED_INT_TYPE sign = converter.components.sign;

    int true_exponent = 1 - BIAS;
    
    FP_TYPE mantissa_decimal = mantissa / (FP_TYPE)(1ULL << MANTISSA_BITS);
   
    FP_TYPE reconstituted = 1 * mantissa_decimal * power_of_2(true_exponent);
    // power always 0 in the first operator of this formula 
    
    if (sign < 1) {

        if (mantissa == 0) {
            printf("Original value: 0.0\n");
            return;
        }

        printf("Original value:\n");
        printf("(-1)^{0} x %.45f x 2^{1 - %d}\n", mantissa_decimal, BIAS);
        printf("  = 1 x %f x 2^{%d}\n", mantissa_decimal, true_exponent);
        printf("  = %.45f x 1/%.0f\n", mantissa_decimal, power_of_2(true_exponent * -1));
        printf("  = %.45f\n", reconstituted); 

    } else {

        if (mantissa == 0) {
            printf("Original value: -0.0\n");
            return;
        }

        printf("Original value:\n");
        printf("(-1)^{1} x " FP_TYPE_FORMAT " x 2^{1 - %d}\n", mantissa_decimal, BIAS);
        printf("  = -1 x " FP_TYPE_FORMAT " x 2^{%d}\n", mantissa_decimal, true_exponent);
        printf("  = -1 x " FP_TYPE_FORMAT " x 1/%.0f\n", mantissa_decimal, power_of_2(true_exponent * -1));
        printf("  = -%.45f\n", reconstituted);
    }
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
        for (int i = 0; i < exponent; i++) {
            result *= 2.0;
        } 
    } else {
        for (int i = 0; i > exponent; i--) {
            result /= 2.0;
        }
    }
    return result;
}


