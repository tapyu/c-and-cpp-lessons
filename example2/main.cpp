#include <iostream>
#include <string> // Include the string header to use std::string

int main() {
    std::string myString = "Hello, C++"; // Creating a string variable

    // Accessing string functions and properties
    std::cout << "Length of myString: " << myString.length() << std::endl;
    std::cout << "myString: " << myString << std::endl;

    std::string toCat = "This is a new string that we concat.";

    std::string finalString = myString + ". " + toCat;

    std::cout << "Concatenated string: " << finalString << std::endl;

    return 0;
}