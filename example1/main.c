#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "My source string";
    char destination[50] = "My destination string"; // up-to-50-sized string

    printf("Before strcpy: source string = \"%s\". Its length is %lu.\n", source, strlen(source));
    printf("Before strcpy: destination string = \"%s\". Its length is %lu.\n", destination, strlen(destination));

    strcpy(destination, source);

    printf("After strcpy: source string = \"%s\". Its length is %lu.\n", source, strlen(source));
    printf("After strcpy: destination string = \"%s\". Its length is %lu.\n", destination, strlen(destination));

    char newString[] = ". This is a new string.";

    strcat(destination, newString);

    printf("After strcat: \"%s\". Its length is %lu.\n", destination, strlen(destination));

    return 0;
}