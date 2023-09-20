//By Max Pintchouk
//Completed 09/20/2023
//Mass Unit Converted PA1.c

/* All library Inclusions */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constant conversion and length
const double LB_TO_KG = 0.45359237;
const int MAX_UNIT_STRING_LENGTH = 256;

//enumerating UNIT in this order to reference later 
enum UNIT {
    G,
    KG,
    T,
    OZ,
    LB,
    TN,
    UNSUPPORTED
};
//creating type Unit for conversions
typedef enum UNIT Unit;

//const unit strings to have a function to determine if a unit is of a certain type 
const char * const unit_strings[] = {
    "g",
    "kg",
    "t",
    "oz",
    "lb",
    "tn"
};

//const factors for conversion (same order as enum UNIT)
const double factors[] = {
    0.001, // G -> KG
    1.0,   // KG -> KG
    1000.0, // T -> KG
    1.0/16.0, // OZ -> LB
    1.0,  // LB -> LB
    2000.0 // TN -> LB
};

//iterates through unit_strings to find a match
Unit unit_string_to_unit(const char* unit_str) {

   for (int i = 0; i < sizeof(unit_strings) / sizeof(unit_strings[0]); i++) {

        if (strcmp(unit_str, unit_strings[i]) == 0) {
            return (Unit)i;          
        }

    }
    return UNSUPPORTED;
}

//simple function to check if metric or not metric 
int is_metric(Unit unit) {

    return unit == G || unit == KG || unit == T; 

}

//print function for repeated use
void print_allowable_units() {
    printf("Allowable units: g kg t oz lb tn\n> ");    
}

double convert(double initial_amount, const char* input_unit_str, const char* output_unit_str) {

    // Initializing variables and reading user input - breaking into amount and units

    Unit input_unit = unit_string_to_unit(input_unit_str);
    Unit output_unit = unit_string_to_unit(output_unit_str);

    ////////////////////////////////////////
   
    // Catching error enums (anything that isnt a unit is set to ER)

    if (input_unit == UNSUPPORTED) {
        return NAN;
    }
    if (output_unit == UNSUPPORTED) {
        return NAN;
    }

    ////////////////////////////////////////

    // converting source unit into starting unit (KG or LB)
        
    if (is_metric(input_unit) == 1) {

        switch(input_unit) {
            
            case G:
                initial_amount = initial_amount * factors[G];
                break;

            case T:
                initial_amount = initial_amount * factors[T];
                break;

            case KG:

            default:
                input_unit = KG;
                break;
        }
        
        // CONVERTING KG TO METRIC OR NON METRIC

        if (is_metric(output_unit) == 1) {

            switch(output_unit) {

                case G:
                    return initial_amount / factors[G];

                case T:
                    return initial_amount / factors[T];

                case KG:

                default:
                    return initial_amount;

            }

        } else {

            initial_amount = initial_amount * (1 / LB_TO_KG);

            switch(output_unit) {
                case OZ:
                    return initial_amount / factors[OZ];

                case TN:
                    return initial_amount / factors[TN];

                case LB:

                default:
                    return initial_amount;

            }
        }



        
    } else {
        
        switch(input_unit) {
            
            case OZ:
                initial_amount = initial_amount * factors[OZ];
                break;

            case TN:
                initial_amount = initial_amount * factors[TN];
                break;

            case LB:

            default:
                input_unit = LB;
                break;
        }

        //converting LB to metric or non metric

        if (is_metric(output_unit) == 0) {
            
            switch(output_unit) {

                case OZ:
                    return initial_amount / factors[OZ];

                case TN:
                    return initial_amount / factors[TN];

                case LB:

                default:
                    return initial_amount;
            }


        } else {

            initial_amount = initial_amount * LB_TO_KG;

            switch(output_unit) {

                case G:
                    return initial_amount / factors[G];

                case T:
                    return initial_amount / factors[T];

                case KG:

                default:
                    return initial_amount;
            }

        }

    }
}

int main() {
    
    double initial_amount;
    char input_unit[MAX_UNIT_STRING_LENGTH];
    char output_unit[MAX_UNIT_STRING_LENGTH];

    printf("Please enter a mass quantity to convert, in the form <number> <input-unit> <output-unit>.\nEnter any letter to quit.");
    print_allowable_units();

    while (scanf("%lf %s %s", &initial_amount, input_unit, output_unit)) {
        
        double conversion = convert(initial_amount, input_unit, output_unit);

        if (isnan(conversion)) {
            print_allowable_units();
        }
        else {
            printf("%2f %s = %2f %s\n>", initial_amount, input_unit, conversion, output_unit);
        }

    }     
    return EXIT_SUCCESS;
}


