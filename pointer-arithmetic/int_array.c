#include <stdio.h>

int main() {
    int i[] = {10, 20, 30, 40};
    int *pi = i; // pi points to the internal pointer variable of `i`, that is, the address of its first array element, 10.

    printf("The internal pointer variable of the int array is             : %p\n"
           "The address of the first int array element is                 : %p\n"
           "The stored value (.i.e., the memory address) of the pointer is: %p\n"
           "PS: Each memory address, by definition, stores 1 byte and is usually represented in hexadecimal.\n\n",
           &i, &i[0], pi);


    printf("The memory size the a int variable is: %zu bytes, or equivalently %lu bits as each byte has 8 bits.\n");
    printf("Therefore, the integer number `i[0]` occupies the ");

    printf("Since `pi` is a int pointer, the command `pi = pi + 1` shifts stored memory address of `pi` in %zu bytes.\n\n",
            sizeof(int), 8*sizeof(int), sizeof(int));
    pi = pi + 1; // Move pi to the memory address of the next integer (20) (instead, you could use `pi++`)
    printf("The internal pointer variable of the int array is            : %p\n"
           "The address of the first int array element is                : %p\n"
           "The stored value (.i.e., the memory address) of the pointer is: %p\n\n",
           &i, &i[0], pi);



    return 0;
}