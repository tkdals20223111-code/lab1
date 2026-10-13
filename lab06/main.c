#include <stdio.h>
#include "lib/calc.h"

int main(void)
{
    int a = 20;
    int b = 10;

    printf("Add: %d\n", add(a, b));
    printf("Subtract: %d\n", subtract(a, b));
    printf("Multiply: %d\n", multiply(a, b));
    printf("Divide: %.2f\n", divide(a, b));

    return 0;
}
