#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double LB_TO_KG = 0.45359237;

typedef enum {
    G,KG,T,OZ,LB,TN,ER
} Unit;

Unit unitEnum(const char* unit_str) {
    if (strcmp(unit_str, "g") == 0) return G;
    if (strcmp(unit_str, "kg") == 0) return KG;
    if (strcmp(unit_str, "t") == 0) return T;
    if (strcmp(unit_str, "oz") == 0) return OZ;
    if (strcmp(unit_str, "lb") == 0) return LB;
    if (strcmp(unit_str, "tn") == 0) return TN;
    return ER;
}

double convert(char input[30]) {

    // Initializing variables and reading user input - breaking into amount and units

    double original_amount;
    char source_unit_str[3], target_unit_str[3];
    Unit source_unit, target_unit;
    double output;

    sscanf(input, "%lf %2s %2s", &original_amount, source_unit_str, target_unit_str);    
    
    double temp_amount = original_amount;
    source_unit = unitEnum(source_unit_str);
    target_unit = unitEnum(target_unit_str);
    Unit original_source_unit = source_unit;

    ////////////////////////////////////////
   
    // Catching error enums (anything that isnt a unit is set to ER)

    if (source_unit == ER) {
        printf("Allowable units: g kg t oz lb tn");
        return -10.0;
    }
    if (target_unit == ER) {
        printf("Allowable units: g kg t oz lb tn");
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
    
    char inputString[30];

    printf("Allowable units: g kg t oz lb tn");

    while (strcmp(inputString, "q\n")) {

        printf("\n> ");  
        fgets(inputString, sizeof(inputString), stdin);

        double conversion;
        conversion = convert(inputString);
    }     
    return 0;
}


