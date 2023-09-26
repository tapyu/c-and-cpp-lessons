#include <iostream>

int main() {
    // Dynamic memory allocation for an integer variable
    int *x = new int;
    
    if (x == nullptr) {
        // Memory allocation failed
        std::cerr << "Memory allocation failed!" << std::endl;
        return 1;
    }

    // Memory allocation was successful
    *x = 42;
    // Using the dynamically allocated integer
    std::cout << "x = " << *x << std::endl;
    delete x;  // Don't forget to free the allocated memory

    return 0;
}