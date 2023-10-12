#ifndef FP_ANALYZER_H
#define FP_ANALYZER_H

#ifdef DOUBLE
#define FP_TYPE double
#define UNSIGNED_INT_TYPE unsigned long
#define BIAS 1023
#define EXPONENT_BITS 11
#define MANTISSA_BITS 52
#define FP_TYPE_FORMAT "%lf"
#define UFP_TYPE_FORMAT "%lu"
#else
#define FP_TYPE float
#define UNSIGNED_INT_TYPE unsigned int
#define BIAS 127
#define EXPONENT_BITS 8
#define MANTISSA_BITS 23 
#define FP_TYPE_FORMAT "%f"
#define UFP_TYPE_FORMAT "%u"
#endif

typedef struct {
    UNSIGNED_INT_TYPE mantissa : MANTISSA_BITS;
    UNSIGNED_INT_TYPE exponent : EXPONENT_BITS;
    UNSIGNED_INT_TYPE sign : 1;
} Components;

typedef union Converter {
    FP_TYPE float_rep; 
    UNSIGNED_INT_TYPE int_rep;
    Components components;
} Converter;

void print_bits(UNSIGNED_INT_TYPE value, int length);
void print_components(Converter converter);
void print_normalized(Converter converter);
void print_denormalized(Converter converter);
void print_reconstitution(Converter converter);
FP_TYPE power_of_2(int exponent);

#endif 
