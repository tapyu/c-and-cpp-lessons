#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 5;
    const int *pi = &i;
    int j = 3;

    printf("i is %i\n", i);

    i = 0; // you can modify the i as it is not `const`
    printf("Obviously, we can can modify i directly: %i\n", i);
    // *pi = 100; // however, trying to modify through a const pointer will prompt an error

    printf("The constant pointer pi initially points to: %p\n", (void*) pi);
    printf("Being a const pointer means that we cannot modify the value it points to.\n"
           "However we do can modify the stored value of pi, that is, we can modify the memory address it points to.\n");
    pi = &j;
    printf("Now, the constant pointer pi points to: %p\n", (void*) pi);

    return 0;
}