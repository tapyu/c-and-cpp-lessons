#include <stdio.h>

int main() {
    char myString[] = "Hello";
    char *ptr = myString;

    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++; // go to the next memory address in the char array (i.e., string)
    }

    return 0;
}