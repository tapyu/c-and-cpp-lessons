# Shared and static libraries

In this example, we have a main program (`main.cpp`) that includes the header file `mylib.h`. The header file provides the function prototype for `printMessage()`. The actual implementation of `printMessage()` is defined in separate source files `mylib_static.cpp` and `mylib_shared.cpp`, which are compiled into static (`libmylib_static.a`) and shared (`libmylib_shared.so`) libraries, respectively.

Now, let's compile and use these files to create both a static and shared library.

1. `Create a static library`:
    ```
    g++ -c mylib_static.cpp -o mylib_static.o
    ar rcs libmylib_static.a mylib_static.o
    ```
    - The `-c` option in the g++ command stands for "compile-only" or "compile source files to object files." When you compile a source file with the `-c` option, it instructs the compiler to perform compilation steps up to generating the object file, but it does not perform the linking step. Therefore, The C++ compiler (`g++`) only compiles `myfile.cpp` into an object file (`myfile.o`). Using the `-c` option is useful when you want to compile individual source files separately and then link them together later. It allows for faster compilation when you have multiple source files, as you can compile them independently and avoid recompiling the entire program every time.
    - `ar` stands for "archive" and is a command-line utility for creating and manipulating static libraries. It combines one or more object files into a single archive file. In the case of a static library, it allows you to package your compiled code into a single file that can be linked with other programs during the compilation process.
        - `r`: Replace or add files to the archive.
        - `c`: Create the archive if it doesn't exist.
        - `s`: Write an index into the archive, which helps with faster symbol lookup during linking
    - `libmylib_static.a` is the name of the static library that will be created. The prefix `lib` is commonly used for libraries, followed by the name of the library (`mylib_static` in this case), and **the extension `.a` indicating it's a static library**.
1. **Create a shared library**. When creating a shared library, you typically compile the source files into object files (`*.o`) first, and then use the linker to combine these object files into a shared library.
    ```
    g++ -shared -fPIC mylib_shared.cpp -o libmylib_shared.so
    ```
    - `-shared`: This option instructs the compiler (or linker) to create a shared library instead of an executable or a static library. A shared library contains code and data that can be loaded into memory and shared by multiple programs at runtime. It allows for dynamic linking, where the library is linked with the executable when it is loaded or during runtime.
    - `-fPIC`: This option stands for "Position Independent Code" and is used to generate code that can be loaded at any memory address. It is required for creating shared libraries because the library code needs to be relocatable, meaning it can be loaded at different memory locations by different processes without conflicts.
1. Compile and link the main program with the libraries. 
    - Using the static library:
    ```
    g++ main.cpp -L. -lmylib_static -o program_static
    ```
    - Using the shared library:
    ```
    g++ main.cpp -L. -lmylib_shared -o program_shared
    ```
    - The `-L.` option is a compiler flag that specifies the directory where the linker should search for libraries specified by the `-l` option. In this case, the dot `.` represents the current directory.
    - When compiling the main program, we specify the library to link against using the `-l` option (e.g., `-lmylib_static` or `-lmylib_shared`). The linker (`ld`) resolves the function call to `printMessage()` by looking for the corresponding implementation in the linked library.
1. Run the programs: `./program_static` and `./program_shared`