#include <stdio.h>
#include <stdlib.h>

int transform(int x) {
    return ~x + 1;
}

int main() {
    int num = 33;
    printf("%d\n", transform(num));
    return EXIT_SUCCESS;
}
