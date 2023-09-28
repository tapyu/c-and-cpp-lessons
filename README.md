#### When should I use the `extern` keyword?

The extern keyword in `C` and `C++` is used to declare a global variable or function that is used in multiple source files and thus must be linked toghether. The `extern` keyword basically says that a function/variable that is referenced in a source file `file1.c` is [defined][1] somewhere else, say, in a source file `file2.c`.

Here, It is important to understand the difference between defining a variable and declaring a variable:

- A variable is declared when the compiler is informed that a variable exists (and this is its type); it does not allocate the storage for the variable at that point. You may declare a variable multiple times (though once is sufficient).
- A variable is defined when the compiler allocates the storage for the variable. You may only define it once within a given scope. A variable definition is also a declaration, but not all variable declarations are definitions.

#### How to define a global variable?

The clean, reliable way to declare and define global variables is to use a header file to contain an `extern` declaration of the variable. The header is included by the one source file that defines the variable and by all the source files that reference the variable.

For each program, one (and only one) source file defines the variable. Similarly, one header file should declare the variable. The header file is crucial; it enables cross-checking between independent TUs (the `.i` file generating after the preprocessing step. Each source file typically corresponds to a single translation unit) and ensures consistency.

The extern keyword is not required in the header file because it's common practice for header files to contain declarations, and declarations are implicitly treated as `extern`. I use the keyword `extern` in front of function declarations in headers for consistency — to match the `extern` in front of variable declarations in headers. Many people prefer not to use `extern` in front of function declarations; the compiler doesn't care


#### [Guidelines][2]

- A header file only contains `extern` declarations of variables — never `static` or unqualified variable definitions (e.g., `int myVariable = 42;`).
- For any given variable, only one header file declares it (SPOT — Single Point of Truth).
- A source file never contains extern declarations of variables — source files always include the unique header that declares them.
- For any given variable, exactly one source file defines the variable, preferably initializing it too.
- The source file that defines the variable also includes the header to ensure that the definition and the declaration are consistent.
- A function declaration does not necessarily need the `extern` keyword as it is implicitly treated as one. You can use it, though, as long as you keep this consistency across all function declaration in the header files.
- Avoid global variables whenever possible — use functions instead.

---

### **Usage of the `static` keyword (`C` and `C++`)**

The static keyword can be used in a function declaration in several different contexts, and its meaning can vary depending on where it is used:
1. *Static Member Functions*: When you declare a member function as `static` inside a class, it means that the function belongs to the class itself rather than to any specific instance of the class. You can call a static member function using the class name, without creating an object of the class. See `./static_keyword/static_member-function.cpp`.
1. *Static Local Variables*: Inside a function, you can declare variables as static. A static local variable retains its value between function calls. It's initialized only once, and its value persists across multiple function invocations. See `./static_keyword/static_local-variable.cpp`.
1. *Static Functions in a Translation Unit*: If you declare a function as `static` in a `C++` source file (outside of a class), it means that the function has *internal linkage*, that is, it will only be accessible within the [translation unit][5] where it is defined, making it effectively "private" to that translation unit. On the other hand, functions declared without the `static` keyword have external linkage by default, that is, they can be accessed from other translation units. See `./static_keyword/static_function/`. You can run
```sh
gcc -E -o static_keyword/static_function/main.i static_keyword/static_function/main.c
```
and check that, indeed, the translated unit `./static_keyword/static_function/main.i` doesn't have the `static void internalFunction()` function.

[1]: https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration/1411005#1411005
[2]: https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files/1433387#1433387
[5]: https://github.com/tapyu/c-and-cpp-lessons/tree/1-build-process#preprocessing
