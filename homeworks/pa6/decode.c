#include <stdio.h>
#include <stdlib.h>

char decode(const int count, const int bits[]) {
    unsigned char output = 0;
    for (int i = 0; i < count; i++) {
        int originalBit = (9 - bits[i] + 8 - count) % 8;
        output |= (1 << originalBit);
    }
    return output;
}

void read_and_decode_file(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int count;
    while (1) {
        if (fscanf(file, "%1d", &count) != 1) {
            if (feof(file)) {
                break;
            }
            fprintf(stderr, "Error reading count from encoded data.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        if (count < 0 || count > 7) {
            fprintf(stderr, "Invalid count value: %d\n", count);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        int bits[count];
        for (int i = 0; i < count; i++) {
            if (fscanf(file, "%1d", &bits[i]) != 1) {
                fprintf(stderr, "Error reading bit index from encoded data.\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
            if (bits[i] < 0 || bits[i] > 7) {
                fprintf(stderr, "Invalid bit index: %d\n", bits[i]);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }

        char decodedChar = decode(count, bits);
        printf("%c", decodedChar);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter an input file name as a command-line argument.");        
        return EXIT_FAILURE;
    }

    read_and_decode_file(argv[1]);
    return EXIT_SUCCESS;
}

