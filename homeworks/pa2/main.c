#include "fp_analyzer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

int main(int argc, char *argv[]) {

    if (argc > 1 && strcmp(argv[1], "special") == 0) {
        return EXIT_SUCCESS;
    } 
    else {
       
        Converter converter;        
        FP_TYPE user_input;
        printf("Please enter a floating-point number or q to quit.\n");
        printf("> ");
     
        while (scanf(FP_TYPE_FORMAT, &user_input)) {
            
            printf(FP_TYPE_FORMAT "\n", user_input); 

            converter.float_rep = user_input;

            print_components(converter);

            if (converter.float_rep == 0) {
                printf("Original Value: " FP_TYPE_FORMAT, converter.float_rep); 
            } else {
                
            }
            
            printf("> ");
        } 
    }

    return EXIT_SUCCESS;    
}
