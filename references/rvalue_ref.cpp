#include <iostream>

int main() {
    int i = 0; // lvalue-to-rvalue assignment
    
    int& lref = i;               // lvalue reference
    const int& another_lref = 5; // lvalue reference
    
    int&& rref = 5; // rvalue reference

    std::cout << "Although rref = " << rref << " does not seem that useful, just wait until you see move semantics :)" << std::endl;
    return 0;
}