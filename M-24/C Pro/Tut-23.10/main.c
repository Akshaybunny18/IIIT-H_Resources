// main.c
#include <stdio.h>
#include "math_ops.h"

int main() {
    int result1 = add(10, 5);
    int result2 = subtract(10, 5);

    printf("Addition: %d\n", result1);
    printf("Subtraction: %d\n", result2);

    return 0;
}
