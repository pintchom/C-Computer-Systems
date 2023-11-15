#include <stdlib.h>
#include <stdio.h>

#define MAX_BITS 8

int getSetBits(unsigned char ch, int *bits) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (ch & (1 << i)) {
            bits[count++] = i;
        }
    }
    return count;
}

int encode(unsigned char input, int *indices) {
    int bits[8];
    int count = getSetBits(input, bits);

    for (int i = 0; i < count; ++i) {
        int rotated = (bits[i] + count) % 8;
        indices[i] = 9 - rotated;
    }

    return count;
}

void read_and_encode_file(char *in_file, char *out_file) {
    FILE *fin, *fout;
    int ch;  
    int indices[MAX_BITS];
    int count, i;

    fin = fopen(in_file, "r");
    if (!fin) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    fout = fopen(out_file, "w");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fin)) != EOF) {
        count = encode((unsigned char)ch, indices);

        fprintf(fout, "%d", count);
        for (i = 0; i < count; i++) {
            fprintf(fout, "%d", indices[i]);
        }
    }

    fclose(fin);
    fclose(fout);
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

