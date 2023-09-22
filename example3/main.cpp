#include <iostream>
#include <vector>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};

    // Using an rvalue reference to enable move semantics
    std::vector<int> &&rref = std::move(source);

    // Now, 'source' is in a valid but unspecified state
    // 'rref' has taken ownership of the contents of 'source'

    // Access and print elements of 'rref'
    for (int num : rref) {
        std::cout << num << " ";
    }
    
    return 0;
}