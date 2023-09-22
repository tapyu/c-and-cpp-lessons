#include <iostream>

void add_to_int(int &r) {
    r+=5;
}

int main() {
    int i = 0;
    int &ri = i;

    std::cout << "The value of the variable  i is " << i << std::endl;
    std::cout << "The value of the variable ri is " << ri << std::endl;

    add_to_int(ri);

    std::cout << "The value of the variable  i is " << i << std::endl;
    std::cout << "The value of the variable ri is " << ri << std::endl;

    return 0;
}