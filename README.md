## How to handle strings in `C`?

In `C`, strings are represented as arrays of characters (i.e., `char` vectors). This is because `C` does not have a native string data type like some other high-level programming languages (e.g., `Python` or `Java`). Instead, each character array represents a sequence of characters, with a null character `\0` marking the end of the string. For instance, is
```c
  char myString[] = "Hello";
```
the `[]` symbol means that `myString` is an array of characters (i.e., a string). In this case, the size of the array is determined automatically by the compiler based on the length of the initializer string "Hello". This means the array `myString` will be just long enough to hold the characters in the string "Hello", plus one extra character for the null terminator `\0`, which is added automatically by the compiler to mark the end of the string. So, `myString` will have a size of 6 characters in this case: `h`, `e`, `l`, `l`, `o`, and `\0`.

On the other hand, if you write:
```c
  char myString[64] = "Hello";
```
You are explicitly specifying that myString is an array of characters with a size of 64 characters. However, the initializer string "Hello" is still just 6 characters long. In this case, the compiler will initialize the first 6 elements of myString with the characters `H`, `e`, `l`, `l`, `o`, and `\0`, and the remaining elements (from index 6 to 63) will be set to null characters (`\0`).

### Multiple strings in a argument function

Note that you can pass multiple strings to the `printf()` function as long as you don't put any whitespace of operator between them (break line is allowed, though). They will be automatically concatenated by the compiler, thus resulting in more readable code when you want to split a long string across multiple lines. For instance,
```c
printf("These are"
"muiltiple strings"
"but will the cat to one"
"by the compiler");
```

### `C` string function operators

`C` provides a set of standard library functions for working with these character arrays, such as `strlen(str)` (get the length of `str`), `strcpy(dest, src)` (copy to `dest` from `src`), `strcat(str1, str2)` (concatenate `str1` and `str2`), and `printf()` with `%s` format specifier. Note that, in `C`, **you cannot directly assign a string (e.g., "Mike") to a character array (e.g., name) using the assignment operator `=`**. You need to use functions like `strcpy()` to copy a string into a character array (see `./string-manipulation-c-vs-cpp/main.c`). On the other hand, `C++` codes can handle strings in a much more efficient way (see `/.string-manipulation-c-vs-cpp/main.cpp`).


### How do `C` functions tipically handle strings?

Tipically, `C` functions handles strings (i.e., `char` arrays) via `char` pointers. In other words, function declaration/prototype usually use `char *` to handle a string as its input argument. The benefit is that, once we might not know the string length in advance, using a `char` pointer gives to the function the fredoom of reading each character until it finds null character, `\0`. Therefore, if `char str[] = "Hello my string";`, you can pass either:

- If you pass a string (i.e., a char array) (e.g., `str`): The compiler will *decay* the memory addres to its internal pointer variable, which is the memory address of its first element (i.e., `&str[0]`).
- If you pass a `char` (e.g., `str[0]` or `c`, where `char c = 'a';`): In this case, we don't have an internal pointer variable as this variable type is not structured. Only structured types (e.g., array, structs, etc) have internal point variable (?). Therefore, the passed argument does not *decay* to any memory address and the compiler prompts an error message.
- If you pass the memory address of one of the `char` element array (i.e., `&str[n]`, where `n` can be any `char` element position in the `str` array): The compiler will get this memory address and will assume that the string begins there. You could also pass the address of a single characters. e.g., `&c`, but that makes no since address location of the null character `\0` in the subsequent memory addresses is uncertain (single `char` characters don't have `\0` as trailing character).
- If you pass a `char` pointer (i.e., `char *pstr = str`): The compiler will assume that the memory address stored by the pointer is the beginning of the string.

Afterwards, the function reads each stored character at that memory address onwards until it finds the null character `\0`. **Therefore, in most of the cases, it is enough to work with `char` pointers instead of the string itself.**. For instance, the `%s` formater specifier in the `printf()` function expects a char pointer instead of a char array. On the other hand, keep in mind that `char *pstr ≠ char str[]`

See `./char-strings-pointers`).

## How to handle strings in `C++`?

In `C++`, it is introduced the `std::string` class, which is part of the Standard Template Library (STL). This class provides a high-level abstraction for working with strings. It automatically manages memory, resizing, and other string-related operations. Therefore, you can perform various string operations using member functions of the `std::string` class (see `./string-manipulation-c-vs-cpp/main.cpp`). Moreover, `std::string` handles memory management for you, so you don't need to worry about buffer overflows or manually allocating and deallocating memory for strings. So, when you declare a string variable like
```cpp
  std::string myString = "Hello, C++";
```
`myString` is an object of the `std::string` class.


#### [`printf`/`scanf` `%` syntax in `C`/`C++`](https://github.com/tapyu/c-and-cpp-lessons/tree/5-pointer-reference-memory#memory-size-of-variables-in-bytes)
