#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "q8_4.txt"
#define string "bc"

FILE * fopen_checked(const char * const file_name, const char * const mode) {
    FILE * fp = fopen(file_name, mode);
    if (!fp) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

int main() {
    FILE * fp = fopen(FILE_NAME, "w");
    fputs(string, fp);
    fclose(fp);
    fp = fopen(FILE_NAME, "r");
    unsigned short value;
    fscanf(fp, "%hx", &value);
    fclose(fp);
    printf("%x\n", value);
    return EXIT_SUCCESS;
}
