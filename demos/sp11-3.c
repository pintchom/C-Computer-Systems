#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a1[10];
    memset(a1, 0, sizeof(a1));
    printf("a1: %p\n", a1);
    int * addr1 = &a1[0];
    int * addr2 = &a1[1];
    int * addr3 = &a1[2];
    
    printf("addr1: %p\n", addr1); // first address
    printf("addr2: %p\n", addr2); // previous address += 4
    printf("addr3: %p\n", addr3); // previous address += 4 
    return EXIT_SUCCESS;
}
