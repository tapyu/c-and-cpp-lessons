#include <iostream>
#include <string>

int main() {
    std::string search_pattern = "Hello, World!";

    // Define a lambda function with a capture clause that captures search_pattern by reference
    auto search = [&](const std::string pattern) {
        // You can access search_pattern here by reference
        if (search_pattern.find(pattern) != std::string::npos) {
            std::cout << "Pattern found!" << std::endl;
        } else {
            std::cout << "Pattern not found." << std::endl;
        }
    };

    search("World"); // Call the lambda function

    return 0;
}