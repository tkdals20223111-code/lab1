#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
    void *handle;

    int (*add_func)(int, int);
    int (*sub_func)(int, int);
    int (*mul_func)(int, int);
    double (*div_func)(int, int);

    handle = dlopen("./lib/libcalc.so", RTLD_LAZY);

    if (handle == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    add_func = dlsym(handle, "add");
    sub_func = dlsym(handle, "subtract");
    mul_func = dlsym(handle, "multiply");
    div_func = dlsym(handle, "divide");

    if (add_func == NULL || sub_func == NULL ||
        mul_func == NULL || div_func == NULL) {
        fprintf(stderr, "Function load error\n");
        dlclose(handle);
        return 1;
    }

    printf("Add: %d\n", add_func(20, 10));
    printf("Subtract: %d\n", sub_func(20, 10));
    printf("Multiply: %d\n", mul_func(20, 10));
    printf("Divide: %.2f\n", div_func(20, 10));

    dlclose(handle);

    return 0;
}
