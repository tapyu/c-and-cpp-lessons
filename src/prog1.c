#include "../include/global.h"
#include "../include/prog1.h"
#include <stdio.h>

int my_infile_variable = 42; // local variable visible within this .c file scope

void print_local()
{
    printf("Can I see this? %i\n", my_infile_variable);
    my_infile_variable = 0;
}

int main(void)
{
    print_local();
    print_local();
    printf("global_variable is initially: %i\n", global_variable);
    increment_file2();
    global_variable++;
    printf("global_variable incremented in prog1.c: %i\n", global_variable);
    increment_file1();
    printf("the final global variable I see in prog1.c: %i\n", global_variable);
    return 0;
}