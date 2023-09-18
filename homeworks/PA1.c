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
    double originalAmount;
    char unit1str[3], unit2str[3];
    Unit unit1, unit2;
    double output;

    sscanf(input, "%lf %2s %2s", &originalAmount, unit1str, unit2str);    
    
    double tempAmount = originalAmount;
    unit1 = unitEnum(unit1str);
    unit2 = unitEnum(unit2str);
    Unit ogUnit1 = unit1;

    if (unit1 == ER) {
        printf("Allowable units: g kg t oz lb tn");
        return -10.0;
    }
    if (unit2 == ER) {
        printf("Allowable units: g kg t oz lb tn");
        return -10.0;
    }


    if (unit1 == G) {
        tempAmount = tempAmount / 1000.0;
        unit1 = KG;
    }
    if (unit1 == T) {
        tempAmount = tempAmount * 1000.0;
        unit1 = KG;
    }
    if (unit1 == OZ) {
        tempAmount = tempAmount / 16.0;
        unit1 = LB;
    }
    if (unit1 == TN) {
        tempAmount = tempAmount * 2000.0;
        unit1 = LB;
    }

    if (unit1 == LB) {

        output = tempAmount * LB_TO_KG;
        
        if (unit2 == G) {
            return output * 1000.0;
        }
        else if (unit2 == T) {
            return output / 1000.0;
        }
        else {
            return output;
        }

    } else {
        
        output = tempAmount / LB_TO_KG;

        if (unit2 == OZ) {
            printf("%.4f kg = %.4f lb", originalAmount, output);                        
            return output * 16.0;
        }
        else if (unit2 == TN) {
            printf("%.4f kg = %.4f lb", originalAmount, output);                        
            return output / 2000.0;
        }
        else {
            printf("%.4f kg = %.4f lb", originalAmount, output);            
            return output;
        }
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


