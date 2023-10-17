#include <stdio.h>

int div_qr(int dividend, int divisor, int *remainder);

int main(int argc, char *argv[]) {
    int x, y;
    int quotient, remainder; 

    printf("Please enter an integer dividend and divisor, or \"q\" to quit.\n");

    while (printf("> "), scanf("%d %d", &x, &y)) {

        if (y == 0) {
            printf("Division by 0 is undefined.\n");
            continue;           
        }

        quotient = div_qr(x, y, &remainder);
        printf("%d / %d = %d, r %d\n", x, y, quotient, remainder);
    }
    return 0;
}
