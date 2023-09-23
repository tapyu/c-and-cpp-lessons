#include <stdio.h>

int main() {
    char my_string[] = "Hello";
    char *ptr = my_string;

    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++; // go to the next memory address in the char array (i.e., string)
    }

    return 0;
}