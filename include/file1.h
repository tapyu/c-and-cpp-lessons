#ifndef FILE1_H
#define FILE1_H

void increment_file1(void); // it is implicitly treated as a `extern`. You can put the `extern` keyword without any problem for the sake of clarity. Although it is also correct, it is less common. Therefore the `extern` keyword is commonly used for global variables only

extern int global_var_file1;  // Declaration of the global variable

#endif