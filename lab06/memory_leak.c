#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr;

    ptr = malloc(10 * sizeof(int));

    if (ptr == NULL)
        return 1;

    ptr[0] = 100;

    printf("Value: %d\n", ptr[0]);
    
    free(ptr);

    return 0;
}
