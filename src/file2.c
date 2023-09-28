#include "../include/global.h"
#include "../include/prog1.h"
#include <stdio.h>

void increment_file2(void)
{
    global_variable++;
    printf("global_variable incremented in file2.c: %i\n", global_variable);
}