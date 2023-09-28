#include "../include/file1.h"
#include "../include/file2.h"
#include <stdio.h>

void increment_file2(void)
{
    global_var_file1++;
    printf("global_var_file1 incremented in file2.c: %i\n", global_var_file1);
    global_func_prog1("file2.c");
}