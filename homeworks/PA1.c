#include <stdio.h>
#include <string.h>

double LB_TO_KG = 0.45359237;

int main() {
    
    char inputString[30];

    printf("Allowable units: g kg t oz lb tn\n");

    do {
        printf("> ");  // Displaying the > on the next line
        scanf("%29s", &inputString);

    } while(strcmp(inputString, "q") != 0);

    return 0;
}

double convert(char[30] input) {
    double kg; 
    double lb;

    if (strcmp(input, "t") != 0 {

    }
    if (strcmp(input, "g") != 0 {

    }
    if (strcmp(input, "t") != 0 {

    }
    if (strcmp(input, "t") != 0 {

    }

}

