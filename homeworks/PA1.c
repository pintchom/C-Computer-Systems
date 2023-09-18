#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double LB_TO_KG = 0.45359237;

typedef enum {
    G,KG,T,OZ,LB,TN,ER
} Unit;

Unit unitEnum(const char* unitStr) {
    if (strcmp(unitStr, "g") == 0) return G;
    if (strcmp(unitStr, "kg") == 0) return KG;
    if (strcmp(unitStr, "t") == 0) return T;
    if (strcmp(unitStr, "oz") == 0) return OZ;
    if (strcmp(unitStr, "lb") == 0) return LB;
    if (strcmp(unitStr, "tn") == 0) return TN;
    return ER;
}

double convert(char input[30]) {
    double amount;
    char unit1str[3], unit2str[3];
    Unit unit1, unit2;
    double output;

    sscanf(input, "%lf %2s %2s", &amount, unit1str, unit2str);    

    unit1 = unitEnum(unit1str);
    unit2 = unitEnum(unit2str);

    if (unit1 == ER) {
        return -10.0;
    }
    if (unit2 == ER) {
        return -10.0;
    }


    if (unit1 == G) {
        amount = amount / 1000.0;
        unit1 = KG;
    }
    if (unit1 == T) {
        amount = amount * 1000.0;
        unit1 = KG;
    }
    if (unit1 == OZ) {
        amount = amount / 16.0;
        unit1 = LB;
    }
    if (unit1 == TN) {
        amount = amount * 2000.0;
        unit1 = LB;
    }

    if (unit1 == LB) {

        output = amount * LB_TO_KG;
        
        if (unit2 == G) {
            return output * 1000.0;
        }
        if (unit2 == T) {
            return output / 1000.0;
        }
        return output;

    } else {
        
        output = amount / LB_TO_KG;

        if (unit2 == OZ) {
            return output * 16.0;
        }
        if (unit2 == TN) {
            return output / 2000.0;
        }
        return output;
    }  
}

int main() {
    
    char inputString[30];

    printf("Allowable units: g kg t oz lb tn\n");

    do {
        printf("> ");  
        fgets(inputString, sizeof(inputString), stdin);

        double conversion;
        conversion = convert(inputString);
        printf("Conversion: %.2f", conversion);

    } while(strcmp(inputString, "q\n") != 0);
    
    return 0;
}
