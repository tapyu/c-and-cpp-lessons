#include <stdio.h>
#include <string.h>

int main(void)
{
    char *pstr1;
    // When you write `pstr1 = "hello";`, you are creating a string literal in memory and making the pointer point to it.
    pstr1 = "hello1";
    // When you create another string literal `"new1"` and assign it to `pstr1`, all you are doing is changing where the pointer points.
    pstr1 = "new1";
    printf("%s\n", pstr1);

    // When you say `char str2[] = "Hello"`, you are creating a string literal and putting it in the array during its definition
    char str2[] = "hello2";
    // You cannot reassign anything to that array without resizing it. That is why `str2 = "four"` will not work.
    // str2 = "foo";
    strcpy(str2, "foo");
    printf("%s",str2);

    return 0;
}