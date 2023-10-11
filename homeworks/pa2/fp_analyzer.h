#ifdef DOUBLE
#define FP_TYPE double
#else
#define FP_TYPE float
#endif

typedef struct {
    unsigned int mantissa : 23; 
    unsigned int exponent : 8;
    unsigned int sign : 1;
} Components;

typedef union {
    FP_TYPE floatRepresentation;
    #ifdef DOUBLE
    unsigned long intRepresentation; // For double
    #else
    unsigned int intRepresentation;  // For float
    #endif
    Components components;
} Converter;
