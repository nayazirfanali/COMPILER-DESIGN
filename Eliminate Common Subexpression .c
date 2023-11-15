#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int c, d, e;

    // Eliminate common subexpression
    int common = a + b;
    c = common;
    d = common;
    e = c + d;

    printf("e = %d\n", e);

    return 0;
}
