#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

// Function with external linkage (default)
void externalFunction();

// You should not declare the function prototype for internalFunction() in the `myfunctions.h` header file if it's intended to have internal linkage and should not be accessible from other source files. The purpose of a header file like myfunctions.h is to declare functions, types, and other declarations that are meant to be shared and used across multiple source files. Since internalFunction() is intended to be private to the translation unit (source file) where it is defined, you should not expose its prototype in the header file. Instead, only declare functions with external linkage (functions that are meant to be used across multiple source files) in header files. Functions with internal linkage (static functions) should be declared solely in the source file where they are defined, and they won't be visible or accessible from other source files. By not declaring internalFunction() in the header file, you're following the principle of information hiding and encapsulation, ensuring that it remains private to its translation unit and is not accidentally accessed or misused from other parts of your program.

#endif