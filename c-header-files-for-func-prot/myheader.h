#ifndef MYHEADER_H
#define MYHEADER_H

// Declare functions from other source files
void greet(void); // That is the correct way to say "no parameters" in C, and it also works in C++. But: `void foo();` means different things in C and C++! In C it means "could take any number of parameters of unknown types", and in C++ it means the same as foo(void).
int add(int a, int b);

#endif