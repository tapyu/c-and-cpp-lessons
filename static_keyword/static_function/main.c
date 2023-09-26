#include <stdio.h>
#include "myfunctions.h"

int main() {
    externalFunction(); // Call the external function from another source file
    // internalFunction(); // Uncommenting this line would result in a compilation error
    return 0;
}