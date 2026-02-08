// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

#include <stdio.h>
int power(int a, int b) {
    if (b == 0) {
        return 1; // a^0 is always 1
    } else if (b > 0) {
        return a * power(a, b - 1); // a^b = a * a^(b-1)
    } else {
        return 1 / power(a, -b); // a^-b = 1 / a^b
    }
}

int main() {
    int a, b;
    printf("Enter base (a) and exponent (b): ");
    scanf("%d %d", &a, &b);

    int result = power(a, b);
    printf("%d^%d = %d\n", a, b, result);
    return 0;
}