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
    while (fscanf(file, "%d", &count) == 1) {
        int bits[count];
        for (int i = 0; i < count; i++) {
            if (fscanf(file, "%d", &bits[i]) != 1) {
                fprintf(stderr, "Error reading encoded data.\n");
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
        fprintf(stderr, "Usage: %s <encoded_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_and_decode_file(argv[1]);
    return EXIT_SUCCESS;
}

