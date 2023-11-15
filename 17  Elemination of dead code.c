#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    int z;

    // Dead code: This block will never be executed
    if (x > y) {
        z = x + y;
    } else {
        z = x - y;
    }

    // Live code: This block will be executed
    printf("Result: %d\n", z);

    return 0;
}