int div_qr(int dividend, int divisor, int *remainder) {
    *remainder = dividend % divisor;
    return  dividend / divisor;
}
