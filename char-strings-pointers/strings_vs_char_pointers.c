#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Hello my string";         // a string variable, i.e., a char array
    char *pstr = str;                       // a char pointer to the first element (`H`) of the `str` char array
    char *str2 = "Hello my string, again."; // a char pointer to the first element (`H`) of the char array literal "Hello my string, again."
    char c = 'a'; // a primitive data type `char`
    int iarr[] = {10, 20, 30, 15};
    int *piarr = iarr; // a int pointer that points to the internal pointer of iarr, that is, the memory address of its first element, `&iarr[0]`

    // the printf %s format specifier expects a char pointer, and therefore all the following syntax are allowed
    printf("Accessed string values:\n");
    printf("str2: %s\n", str2);    // the compiler will get its internal pointer variable, which is the memory address of its first element (i.e., `&str[0]`).
    printf("str: %s\n", str);     // same situation
    printf("&str[1]: %s\n", &str[1]); // the compiler will get this memory address and will assume that the string begins there.
    printf("pstr: %s\n", pstr);    // the compiler will assume that the memory address stored by the pointer is the beginning of the string.
    // printf("%s\n", c);    //  you cannot do it because if you pass the memory address of a char, it doesn't **decay** into its internal pointer variable since it doesn't have one. It is because the `char` variable is a primitive data type, and primitive data types have no internal pointer variable.
    printf("&c: %s\n\n", &c);      // if you pass the memory address of a char, the subsequent memory addresses' content won't probably be ASCII-compliant, which will result in non-recognized characters. Moreover, the location of the null character, `\0`, is uncertain. Even though, the compiler will read the memory addresses' content until find it.

    // The memory address, it happens
    printf("Memory addresses:\n");
    printf("&str[0]: %p\n", &str[0]);
    printf("str:     %p\n", str);  // same as `&str[0]`
    printf("pstr:    %p\n", pstr); // same as `&str[0]`
    printf("&c:      %p\n", &c);
    printf("str2:    %p\n", str2);

    return 0;
}