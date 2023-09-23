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

In `C++`, it is introduced the `std::string` class, which is part of the Standard Template Library (STL). This class provides a high-level abstraction for working with strings. It automatically manages memory, resizing, and other string-related operations. Therefore, you can perform various string operations using member functions of the `std::string` class (see `./example2/`). Moreover, `std::string` handles memory management for you, so you don't need to worry about buffer overflows or manually allocating and deallocating memory for strings. So, when you declare a string variable like
```cpp
  std::string myString = "Hello, C++";
```
`myString` is an object of the `std::string` class.

#### `printf`/`scanf` syntax

C provides a set of standard library functions for working with these character arrays, such as `strlen(str)` (get the length of `str`), `strcpy(dest, src)` (copy to `dest` from `src`), `strcat(str1, str2)` (concatenate `str1` and `str2`), and `printf()` with `%s` format specifier.

<table>
<tr>
  <th colspan="2">Format specifier</th>
</tr>
<tr>
  <td>Syntax</td>
  <td>Variable</td>
</tr>
<tr>
  <td><code>%i</code>,<code>%d</code></td>
  <td>Integer (decimal)</td>
</tr>
<tr>
  <td><code>%li</code>,<code>%ld</code></td>
  <td>Long integer (decimal)</td>
</tr>
<tr>
  <td><code>%c</code></td>
  <td>Character</td>
</tr>
<tr>
  <td><code>%s</code></td>
  <td>String</td>
</tr>
<tr>
  <td><code>%f</code></td>
  <td>Float</td>
</tr>
<tr>
  <td><code>%lf</code></td>
  <td>Double-precision floating-point number (double)</td>
</tr>
<tr>
  <td><code>%u</code></td>
  <td>Unsigned integer (decimal)</td>
</tr>
<tr>
  <td><code>%lu</code></td>
  <td>Unsigned long integer (decimal)</td>
</tr>
<tr>
  <td><code>%x</code></td>
  <td>Integer (hexadecimal)</td>
</tr>
<tr>
  <td><code>%o</code></td>
  <td>Integer (octal)</td>
</tr>
</table>

