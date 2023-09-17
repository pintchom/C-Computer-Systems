#include <stdio.h>
/* 
 Bunch of symbols and forward declarations
 # means following code is to be run by 
 C pre-processor
 PRE-PROCESSOR DIRECTIVE
*/

int main() {    

    printf("%d\n", 0);

    int array[10];

	for (int i = 0; i< 10; ++i) {
		array[i] = i + 1;
	}

    printf("%d\n", array[5]);
    printf("Value: ", array[5]);
	return 0;
}

