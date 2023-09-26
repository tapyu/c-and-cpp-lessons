#include <iostream>

void counting_static()
{
    static int static_int = 0;
    std::cout << "Now the value of my static variable is " << static_int << std::endl;
    static_int++;
}

void counting_nonstatic()
{
    int static_int = 0;
    std::cout << "Now the value of my nonstatic variable is " << static_int << std::endl;
    static_int++;
}

int main()
{
    counting_static();
    counting_static();
    counting_static();
    counting_nonstatic();
    counting_nonstatic();
    counting_nonstatic();
}