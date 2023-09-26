#include <iostream>
#include <string.h>

class MyString {
private:
    char *str;

public:
    // Constructor that takes a C-style string (char*)
    MyString(char* s) {
        // Allocate memory and copy the input string
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Move constructor using an rvalue reference
    MyString(MyString&& other) noexcept {
        // Steal the ownership of the dynamically allocated memory
        str = other.str;
        other.str = nullptr; // Ensure the source object has no ownership
    }

    // Destructor to release dynamically allocated memory
    ~MyString() {
        delete[] str;
    }

    // Print the string
    void print() {
        std::cout << str << std::endl;
    }
};

int main() {
    // Create a temporary MyString object (rvalue)
    MyString temp("Hello, World!");

    // Use std::move to cast temp into an rvalue reference
    MyString moved = std::move(temp);

    // 'temp' is now in a valid but unspecified state
    // 'moved' has taken ownership of the dynamically allocated memory

    // Print the moved string
    moved.print();

    // Attempting to print 'temp' would result in undefined behavior
    // because it no longer owns the memory

    return 0;
}