#include "fp_analyzer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    Converter converter;        

    if (argc > 1 && strcmp(argv[1], "special") == 0) {

        FP_TYPE specials[] = {1.0/0.0, -1.0/0.0, 0.0/0.0, -(0.0/0.0)}; // inf, -inf, nan, -nan
        
        for (int i = 0; i < 4; i++) {
            printf("%f\n", specials[i]);
            converter.float_rep = specials[i];
            print_components(converter);
            printf("\n");
        } 

    } else {

        FP_TYPE user_input;        

        printf("Please enter a floating-point number or q to quit.\n");
     
        while (printf("> "), scanf(FP_TYPE_FORMAT, &user_input)) {

            converter.float_rep = user_input; // storing input in union
            
            printf("%f\n", user_input); // Initial numerical print
            print_components(converter); // printing binary components from struct
            print_reconstitution(converter);  // printing original value with steps                 
        } 
    }
    return EXIT_SUCCESS;    
}
