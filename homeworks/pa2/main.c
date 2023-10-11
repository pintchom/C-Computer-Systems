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
     
        while (scanf(FP_TYPE_FORMAT "> ", &user_input)) {
            
            printf(FP_TYPE_FORMAT "\n", user_input); 
            converter.float_rep = user_input;
            print_components(converter); 

            //printf(FP_TYPE_FORMAT "\n", power_of_2(3)) 
            //print_components(user_input);
        } 
    }

    return EXIT_SUCCESS;    
}
