#include <iostream>

int main() {
    // Dynamic memory allocation for an integer variable
    int* x = new int;
    
    *x = 10;

    // Using the dynamically allocated integer
    std::cout << "x = " << *x << std::endl;

    // Freeing the allocated memory
    delete x;

    return 0;
}