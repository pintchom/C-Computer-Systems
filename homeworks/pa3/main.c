#include <stdio.h>

int div_qr(int dividend, int divisor, int *remainder);

int main() {
    int dividend, divisor;
    int quotient, remainder; 

    printf("Please enter an integer dividend and divisor, or \"q\" to quit.\n");

    while (printf("> "), scanf("%d %d", &dividend, &divisor)) {

        if (divisor == 0) {
            printf("Division by 0 is undefined.\n");
            continue;           
        }

        quotient = div_qr(dividend, divisor, &remainder);
        printf("%d / %d = %d, r %d\n", dividend, divisor, quotient, remainder);
    }
    return 0;
}
