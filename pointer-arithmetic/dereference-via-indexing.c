#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr; // ptr points to the internal pointer variable of `arr`, that is, the address of its first array element, 10.
    printf("The pointer address before the pointer arithmetic: %p\n", (void*)ptr);
    ptr = ptr + 1; // Move ptr to the next integer (20)
    printf("The pointer address after the pointer arithmetic:  %p (the memory size of an `int` variable is %zu bytes)\n", (void*)ptr, sizeof(int));
    int i = *ptr; // `i` is `20`
    printf("The value of i is %i\n\n", i);

    //alternatively, you can dereference via indexing
    int arr2[] = {50, 60, 70, 80, 90, 100, 110};
    int *ptr2 = arr2; // ptr2 points to the internal pointer variable of `arr2`, that is, the address of its first array element, 50.
    printf("The pointer address before dereferencing via index: %p\n", (void*)ptr2);
    int i2 = ptr2[2]; // dereference via indexing: `i` is equal to `70`, the memory address of ptr2 did not change
    printf("The pointer address after dereferencing via index:  %p\n", (void*)ptr2);
    printf("The value of i2 is %i", i2);
}