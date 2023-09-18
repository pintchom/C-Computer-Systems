#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];

    //stdin -- command line input
    //stdout -- command line output
    //stderr -- command line output for error messages 
    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        fputs(buffer, stdout);
    }
    return EXIT_SUCCESS;
}   
