#include <stdio.h>
#include <stdlib.h>

void my_assert_fail(const char *expr,
                    const char *file,
                    int line)
{
    fprintf(stderr,
            "Assertion failed: %s, file %s, line %d\n",
            expr, file, line);

    abort();
}

#define my_assert(expr) \
    ((expr) ? (void)0 : \
    my_assert_fail(#expr, __FILE__, __LINE__))

int main(void)
{
    int a = 10;
    int b = 20;

    printf("Checking a < b...\n");
    fflush(stdout);

    my_assert(a < b);

    printf("First assertion passed.\n");
    fflush(stdout);

    my_assert(a > b);

    printf("Program finished.\n");

    return 0;
}
