#include <stdio.h>
#define MAX_IDS 32

int main() {
    int ids[MAX_IDS] = {0,1,2};
    
    char mystr[] = {'h', 'e', 'l', 'l', 'o', 0}; //STRINGS NEED NULL TERMINATORS
    char *myotherstr = "hello";
    //printf("Hello World\n"); // quotes denote string 
    printf("%s\n", mystr);
    printf("%s\n", myotherstr);

   // strcpy(dest, src);
   // strncpy(dest, src, n);
}
