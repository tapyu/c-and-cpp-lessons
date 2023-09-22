#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "My source string";
    char destination[40] = "My destination string"; // up-to-40-sized string

    printf("Before: source string = \"%s\". Its length is %lu.\n", source, strlen(source));
    printf("Before: destination string = \"%s\". Its length is %lu.\n", destination, strlen(destination));

    strcpy(destination, source);

    printf("After: source string = \"%s\". Its length is %lu.\n", source, strlen(source));
    printf("After: destination string = \"%s\". Its length is %lu.\n", destination, strlen(destination));
    return 0;
}