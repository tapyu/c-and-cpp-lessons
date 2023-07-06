#include <iostream>

extern "C" void printMessage() {
    std::cout << "Hello, Library! (Shared)" << std::endl;
}