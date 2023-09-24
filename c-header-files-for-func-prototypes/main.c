#include <stdio.h>
#include "myheader.h" // Include the header file

int main(void) {
    greet();
    int result = add(5, 7);
    printf("Result: %d\n", result);
    return 0;
}