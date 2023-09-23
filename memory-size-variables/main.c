#include <stdio.h>

int main() {
    // Declare a char variable
    char c = 'a';
    printf("Value of char: %c\n", c);
    printf("Size of char: %zu bytes\n\n", sizeof(c)); // or sizeof(char)
    
    // Declare a float variable
    float f = 3.1416;
    printf("Value of float: %f\n", f);
    printf("Size of float: %zu bytes\n\n", sizeof(f)); // or sizeof(float)
    
    // Declare a double variable
    double d = 3.1416;
    printf("Value of double: %lf\n", d);
    printf("Size of double: %zu bytes\n\n", sizeof(d)); // or sizeof(double)
    
    // Declare a long double variable
    long double ld = 3.141592653589793238462643383279502884L;
    printf("Value of long double: %Lf\n", ld);
    printf("Size of long double: %zu bytes\n\n", sizeof(ld)); // or sizeof(long double)

    // Declare a integer variable
    int i = 32767; // The maximum value that can be represented in a signed int
    printf("Value of int: %d\n", i);
    printf("Size of int: %zu bytes\n\n", sizeof(i)); // or sizeof(int)

    // Declare a integer variable (in octal)
    int octa_i = 032;
    printf("Value of octal int: %o\n", octa_i); // // use %d to convert from octal to decimal
    printf("Size of octal int: %zu bytes\n\n", sizeof(octa_i)); // or sizeof(int)

    // Declare a integer variable (in hexadecimal)
    int hex_i = 0x1a;
    printf("Value of hexadecimal int: %x\n", hex_i); // use %d to convert from hexadecimal to decimal
    printf("Size of hexadecimal int: %zu bytes\n\n", sizeof(hex_i)); // or sizeof(int)

    // Declare a short integer variable
    short s = 32767; // The maximum value that can be represented in a signed short
    printf("Value of short: %d\n", s);
    printf("Size of short: %zu bytes\n", sizeof(s)); // or sizeof(short)
    // Attempt to exceed the range of a short
    s = s + 1; // This will result in numeric overflow
    printf("Value of short after overflow: %d\n\n", s);

    // Declare a long integer variable
    long l = 1234567890;
    printf("Value of long: %ld\n", l);
    printf("Size of long: %zu bytes\n\n", sizeof(long)); // or sizeof(long)
    
    // Declare a long long integer variable
    long long ll = 1234567890123456789LL;
    printf("Value of long long: %lld\n", ll);
    printf("Size of long long: %zu bytes\n\n", sizeof(long long)); // or sizeof(long long)

    // Declare size_t variable
    size_t size = 42;
    // Print the stored value of 'size' and its memory size
    printf("Value of 'size': %zu\n", size);
    printf("Memory size of 'size': %zu bytes\n", sizeof(size));

    return 0;
}