#include <stdio.h>
#include <stdlib.h>

int string_length(char * string) { // THING IS TAKING ADDRESS OF FIRST CHARACTER OF STRING
                                   
    int length = 0; // HOLDING STRING LENGTH FROM STRING GIVEN

    char * current = string; // CURRENT IS A POINTER THAT POINTS TO A POINTER THAT POINTS TO FIRST INDEX OF STRING ADDRESS

    while (current[length] != '\0') { // KEEPS MOVING UNTIL LAST INDEX OF STRING 
        ++length;
    }
    return length;
}

int main(int argc, char * argv[]) { // ARGC PARAMTER - NUMBER OF ARGUMENTS UPON RUN 
                                    // ARGV PARAMETER - List of arguments given upon run
                                    // ARGV = Pointer to first char in string of second argument 
    puts(argv[1]);
    printf("Length: %d\n", string_length(argv[1]));
    printf("Argument Count: %d\n", argc); // PRINTS 4 for - ./run run run run 
    return EXIT_SUCCESS;
}
