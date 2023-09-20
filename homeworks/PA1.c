#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double LB_TO_KG = 0.45359237;
int MAX_UNIT_STRING_LENGTH = 256;

enum UNIT {
    G,
    KG,
    T,
    OZ,
    LB,
    TN,
    UNSOPPURTED
};

typedef enum UNIT Unit;

Unit unit_string_to_unit(const char* unit_str) {

   for (int i = 0; i < sizeof(unit_strings) / sizeof(unit_strings[0]); i++) {

        if (strcmp(unit_str, unit_strings[i]) == 0) {
            return (Unit)i;          
        }

    }
    return UNSUPPORTED;
}

const char * const unit_strings[] = {
    "g",
    "kg",
    "t",
    "oz",
    "lb",
    "tn"
};

const double factors[] {
    0.001, // G -> KG
    1.0, // KG -> KG
    1000.0, // T -> KG
    1.0/16.0, // OZ -> LB
    1.0, // LB -> LB
    2000.0 // TN -> LB
}

double convert(double initial_amount, const char* input_unit, const char* output_unit) {

    // Initializing variables and reading user input - breaking into amount and units

    Unit input_unit = unit_string_to_unit(input_unit);
    Unit output_unit = unit_string_to_unit(output_unit);

    ////////////////////////////////////////
   
    // Catching error enums (anything that isnt a unit is set to ER)

    if (input_unit == UNSUPPORTED) {
        return -10.0;
    }
    if (output_unit == UNSUPPORTED) {
        return -10.0;
    }

    ////////////////////////////////////////

    // converting source unit into starting unit (KG or LB)

    if (source_unit == G) {
        temp_amount = temp_amount / 1000.0;
        source_unit = KG;
    }
    if (source_unit == T) {
        temp_amount = temp_amount * 1000.0;
        source_unit = KG;
    }
    if (source_unit == OZ) {
        temp_amount = temp_amount / 16.0;
        source_unit = LB;
    }
    if (source_unit == TN) {
        temp_amount = temp_amount * 2000.0;
        source_unit = LB;
    }

    ////////////////////////////////////////
    
    // Converting into final unit 

    if (source_unit == LB) {

        if (target_unit == OZ) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);                           
            return output * 16.0;
        }
        else if (target_unit == TN) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);
            return output/ 2000.0;
        }

        output = temp_amount * LB_TO_KG;
        
        if (target_unit == G) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);
            return output * 1000.0;
        }
        else if (target_unit == T) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);
            return output / 1000.0;
        }
        
        printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);
        return output;

    } else {

        if (target_unit == G) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);                           
            return output * 1000.0;
        }

        if (target_unit == G) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);                           
            return output / 1000.0;
        }
        
        output = temp_amount / LB_TO_KG;

        if (target_unit == OZ) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);                        
            return output * 16.0;
        }
        else if (target_unit == TN) {
            printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);                        
            return output / 2000.0;
        }

        printf("%.4f %s = %.4f %s", original_amount, source_unit_str, output, target_unit_str);                        
        return output;
    }  
}

int main() {
    
    double initial_amount;
    char input_unit[MAX_UNIT_STRING_LENGTH];
    char ouput_unit[MAX_UNIT_STRING_LENGTH];

    printf("Allowable units: g kg t oz lb tn");

    while (scanf("%lf %s %s", &initial_amount, source_unit, target_unit)) {
        
        printf("\n>");        
        double conversion = convert(initial_amount, source_unit, target_unit)

    }     
    return EXIT_SUCCESS;
}


