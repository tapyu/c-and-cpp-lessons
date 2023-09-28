#include <stdio.h>
#include "myfunctions.h"

// Function with internal linkage (static)
// `internalFunction` is declared as static in myfunctions.c, giving it internal linkage. It cannot be accessed from other source files, such as main.c. Attempting to call it from those files will result in a compilation error.
static void internalFunction() {
    printf("This is an internal function.\n");
}

// Function with external linkage (default)
// `externalFunction` is declared without the static keyword in myfunctions.c, giving it external linkage. It can be accessed from any source file that includes the myfunctions.h header.
void externalFunction() {
    printf("This is an external function.\n");
}