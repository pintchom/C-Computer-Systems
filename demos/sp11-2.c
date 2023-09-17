#include <stdio.h>
//#define EXIT_SUCCESS 0
#include <stdlib.h>

void func1(int a[]) {
    printf("Size of a1: %zu\n", sizeof(a)); //40 BYTES
    // This will print 8 because referencing a list in func 
    // parameters will simply refer to memory location of 
    // the original list address.
    // Machines are 64 bits meaning it will always return 
    // 8 bytes 
}

int main() {
    int a1[10];
    printf("Size of a1: %zu\n", sizeof(a1)); //40 BYTES
    func1(a1);
    printf("Size of int: %zu\n", sizeof(int));
    printf("Size of double: %zu\n", sizeof(double));        
    return EXIT_SUCCESS;
}
