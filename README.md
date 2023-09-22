#### Syntax

In `C`, strings are represented as arrays of characters (i.e., `char` vectors). This is because C does not have a native string data type like some other high-level programming languages (e.g., `Python` or `Java`). Instead, each character array represents a sequence of characters, with a null character `\0` marking the end of the string. For instance, is
```c
  char myString[] = "Hello";
```
the `[]` symbol means that `myString` is an array of characters (i.e., a string). In this case, the size of the array is determined automatically by the compiler based on the length of the initializer string "Hello". This means the array myString will be just long enough to hold the characters in the string "Hello", plus one extra character for the null terminator '\0', which is added automatically by the compiler to mark the end of the string. So, myString will have a size of 6 characters in this case: `h`, `e`, `l`, `l`, `o`, and `\0`.

On the other hand, if you write:
```c
  char myString[64] = "Hello";
```
You are explicitly specifying that myString is an array of characters with a size of 64 characters. However, the initializer string "Hello" is still just 6 characters long. In this case, the compiler will initialize the first 6 elements of myString with the characters `H`, `e`, `l`, `l`, `o`, and `\0`, and the remaining elements (from index 6 to 63) will be set to null characters (`\0`).

#### String operations

C provides a set of standard library functions for working with these character arrays, such as `strlen()`, `strcpy()`, `strcat()`, and `printf()` with `%s` format specifier.


#### Using pointers to manipulate strings

In `C`, **character arrays are often manipulated using pointers to char.** Since arrays can be treated as pointers to their first elements, you can use pointer arithmetic to traverse the characters of a string. This is a fundamental feature of C that allows you to manipulate strings efficiently.



