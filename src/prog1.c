#include "../include/file1.h"
#include "../include/file2.h"
#include "../include/prog1.h"
#include <stdio.h>

int global_var_prog1 = 100; // Definition of the global variable from prog1
static int my_infile_var1 = 161616; // the `static` keyword makes the variable have file scope and limits its visibility to only the functions within prog1.c

static void increment_infunction_var()
{
    static int static_infunction = 0; // you can also declare and define 
    static_infunction++;
    printf("static_infunction is now %i\n", static_infunction);
}

static void print_local()
{
    printf("I can access my_infile_var1(%i), global_var_prog1(%i), and global_var_file1(%i).\n", my_infile_var1, global_var_prog1, global_var_file1);
    // printf("but I cannot access static_infunction(%i) as it exists only within the increment_infunction_var scope", static_infunction);
}

void global_func_prog1(const char* c)
{
    printf("Hello my global function from %s\n", c);
}

int main(void)
{
    increment_infunction_var();
    increment_infunction_var();
    print_local();
    printf("I can access my_infile_var1(%i), global_var_prog1(%i), and global_var_file1(%i).\n", my_infile_var1, global_var_prog1, global_var_file1);
    global_func_prog1("prog1.c");
    increment_file1();
    global_var_file1++;
    printf("global_var_file1 incremented in prog1.c: %i\n", global_var_file1);
    increment_file2();
    my_infile_var1++;
    printf("the final global variable I see in prog1.c: %i. Final value of my_infile_var1: %i\n", global_var_file1, my_infile_var1);
    return 0;
}