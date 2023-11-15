#include <stdlib.h>
#include <stdio.h>

int encode(unsigned char input, int * indices) {

}

void read_and_encode_file(char * in_file, char * out_file) {
    
}

int main(int argc, char * argv[]) {

    if (argc != 3) {
        printf("Please enter input and output file names as command-line arguments.");        
        return EXIT_FAILURE;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    read_and_encode_file(input_file, output_file);

    return EXIT_SUCCESS;
    
}
