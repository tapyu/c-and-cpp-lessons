#include <iostream>

// When using C++ code in conjunction with C code or when creating a shared library that will be used by C code, it's necessary to specify extern "C" to ensure that the function names are not mangled by the C++ compiler.
extern "C" void printMessage() {
    std::cout << "Hello, Library! (Shared)" << std::endl;
}