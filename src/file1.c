#include "../include/file1.h"  // Declaration made available here
#include "../include/prog1.h"  // Function declarations
#include <stdio.h>

// Variable defined here
int global_var_file1 = 0; // Definition of the global variable from file1

void increment_file1(void)
{
    global_var_file1++;
    printf("global_var_file1 incremented in file1.c: %i\n", global_var_file1);
    printf("I can access global_var_file1(%i) and global_var_prog1(%i), but I can't access my_infile_var1.\n", global_var_file1, global_var_prog1);
    // printf("however, we cannot access my_infile_var1 as it have a prog1.c file scope %i\n", my_infile_var1);
    global_func_prog1("file1.c");
}