#include <stdio.h> // Preprocessor takes whatever is supposed to do and copy and pastes it into "this code"
                   //
#define MAX_PERSONS 1024 // Creates variables that act as constants that control behavior 
#define DEBUG // Check if this thing is defined, output some code (Makefile thing)
// OR USE -DDEBUG flag with gcc
int main() {
    #ifdef DEBUG
    printf("WE ARE IN DEBUG MODE: %s:%d", __FILE__, __LINE__);  
    #endif

    return 0; 
}

// Compilation Process 
// 1) Preprocessor
// 2) Compiler
// 3) Assembling
// 4) Linking 
