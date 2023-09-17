#include <stdio.h>

int main() {
    int array1[10];
    for (int i = 0; i < 10; ++i) {
        array1[i] = i + 1;
    }
    printf("Value: %d\n", (int)array1[5]);
    return 0;

}

/*
 * When using %_\n in printf
 * f -> float
 * d -> integer 
 * s -> string 
 *
 * for printf("%f\n", variable) variable has to be a float so 
 * printf("%f\n", variable) -> printf("%f\n", (double)variable)
 *
 * for printf("%d\n", variable) variable has to be a integer so 
 *  printf("%d\n", variable) ->  printf("%d\n", (int)variable)
 * 
*/
