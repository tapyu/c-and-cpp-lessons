# Shared and static libraries

In this example, we have a main program (`main.cpp`) that includes the header file `mylib.h`. The header file provides the function prototype for `printMessage()`. The actual implementation of `printMessage()` is defined in separate source files `mylib_static.cpp` and `mylib_shared.cpp`, which are compiled into static (`libmylib_static.a`) and shared (`libmylib_shared.so`) libraries, respectively.

Now, let's compile and use these files to create both a static and shared library.

1. Create a static library:
    ```
    g++ -c mylib_static.cpp -o mylib_static.o
    ar rcs libmylib_static.a mylib_static.o
    ```
    - The `-c` option in the g++ command stands for "compile-only" or "compile source files to object files." When you compile a source file with the `-c` option, it instructs the compiler to perform compilation steps up to generating the object file, but it does not perform the linking step. Therefore, The C++ compiler (`g++`) only compiles `myfile.cpp` into an object file (`myfile.o`). Using the `-c` option is useful when you want to compile individual source files separately and then link them together later. It allows for faster compilation when you have multiple source files, as you can compile them independently and avoid recompiling the entire program every time.
    - 
1. Create a shared library:
    ```
    g++ -shared -fPIC mylib_shared.cpp -o libmylib_shared.so
    ```
1. Compile and link the main program with the libraries. 
    - Using the static library:
    ```
    g++ main.cpp -L. -lmylib_static -o program_static
    ```
    - Using the shared library:
    ```
    g++ main.cpp -L. -lmylib_shared -o program_shared
    ```
    When compiling the main program, we specify the library to link against using the `-l` option (e.g., `-lmylib_static` or `-lmylib_shared`). The linker (`ld`) resolves the function call to `printMessage()` by looking for the corresponding implementation in the linked library.
1. Run the programs: `./program_static` and `./program_shared`