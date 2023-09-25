#include <stdio.h>
#include <string.h>

int main(void)
{
    // what is the difference between these three variables
    char str[] = "Hello my string";         // a string variable, i.e., a char array
    char *pstr = str;                       // a char pointer to the first element (`H`) of the `str` char array
    char *str2 = "Hello my string, again."; // a char pointer to the first element (`H`) of the char array literal "Hello my string, again."
    char c = 'a';

    // you can printf %s format specifier for all of the following commands
    printf("%s\n", str2);    // the compiler will get its internal pointer variable, which is the memory address of its first element (i.e., `&str[0]`).
    printf("%s\n", str);     // same situation
    printf("%s\n", &str[1]); // the compiler will get this memory address and will assume that the string begins there.
    printf("%s\n", pstr);    // the compiler will assume that the memory address stored by the pointer is the beginning of the string.
    printf("%s\n\n", &c);      // if you pass the memory address of a char, the subsequent memory addresses' contents won't be ASCII-compliant, which will result in non-recognized characters, and the location of the null character, `\0`, is uncertain. Even though, the compiler will read until find it.

    // if you ask the memory address, it happens
    printf("%p\n",   str);
    printf("%p\n",   &str[0]);
    printf("%p\n",   pstr);
    printf("%p\n",   &c);
    printf("%p\n\n", str2);

    // when you get the 
    printf("%c\n", str[1]);
    printf("%c\n", pstr[1]);

    // char another_str[strlen(pstr)];
    // strcpy(another_str, pstr);
    // printf("Test: \"%c\"\n", pstr[0]);
    // printf("Test: \"%i\"\n", str);
    // printf("I can print the sentence by using the str variable: \"%s\"\n", &str[0]);
    // printf("For some reason, I can printf all the string by using the pointer: \"%s\"\n", pstr);
    // printf("I can even initialize a new string with this pointer: \"%s\"\n", another_str);
    // printf("Can I also do it with the int array? %i", piarr);

    
    // int iarr[] = {55, 10, 12, 66};
    // int *piarr = iarr;

    // printf("The stored memory addresses:\n"
    //        "char array=%p\n"
    //        "int array =%p\n",
    //        pstr, piarr);
    return 0;
}