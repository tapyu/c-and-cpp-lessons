#include <stdio.h>
#include <string.h>

int main(void)
{
    int iarr[] = {10, 15, 20, 25};
    int another_iarr[] = {666, 999, 1000, 0};
    const int *piarr = iarr; // points to the internal pointer of `iarr` variable, that is, &iarr[0]

    int len_iarr = sizeof(iarr)/sizeof(iarr[0]);

    printf("iarr is: {");
    for (int j = 0; j < len_iarr-1; j++)
    {
        printf("%i, ", iarr[j]);
    }
    printf("%i}\n\n", iarr[len_iarr-1]);

    iarr[2] = 0; // however, you can modify the int array as it is not `const`
    printf("Obviously, we can can modify iarr directly: {");
    for (int j = 0; j < len_iarr-1; j++)
    {
        printf("%i, ", iarr[j]);
    }
    printf("%i}\n", iarr[len_iarr-1]);
    // piarr[2] = 0; // however, trying to modify through a const pointer will prompt an error

    printf("The constant pointer piarr initially points to: %p\n", (void*) piarr);
    printf("Being a const pointer means that we cannot modify the value it points to.\n"
           "However we do can modify the stored value of piarr, that is, we can modify the memory address it points to.\n");
    piarr = another_iarr; // points to the internal pointer of `another_iarr` variable, that is, &another_iarr[0]
    printf("Now, the constant pointer piarr is points to: %p\n", (void*) piarr);

    return 0;
}