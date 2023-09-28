#include "../include/global.h"  // Declaration made available here
#include "../include/prog1.h"  // Function declarations
#include <stdio.h>

extern int my_infile_variable; // Declare the variable as 'extern'
// Variable defined here
int global_variable = 0;    // Definition checked against declaration

void increment_file1(void)
{
    global_variable++;
    printf("global_variable incremented in file1.c: %i\n", global_variable);
    printf("I turns out that my_infile_variable is global, actually: %i\n", my_infile_variable);
}