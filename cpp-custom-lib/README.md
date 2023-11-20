## Creating static and shared libraries

In this example, we have a main program (`main.cpp`) that includes the header file `mylib.h`. The header file provides the function prototype for `printMessage()`. The actual implementation of `printMessage()` is defined in separate source files `mylib_static.cpp` and `mylib_shared.cpp`, which are compiled into static (`libmylib_static.a`) and shared (`libmylib_shared.so`) libraries, respectively.

Now, let's compile and use these files to create both a static and shared library.

1. **Create a static library** (leave only the function declaration of the static library in `mylib.h`):
    ```
    g++ -c mylib_static.cpp -o mylib_static.o
    ar rcs libmylib_static.a mylib_static.o
    ```
    - The `-c` option in the `g++` command stands for "compile-only" or "compile source files to object files." When you compile a source file with the `-c` option, it instructs the compiler to perform compilation steps up to generating the object file, but it does not perform the linking step. Therefore, The C++ compiler (`g++`) only compiles `myfile.cpp` into an object file (`myfile.o`). Using the `-c` option is useful when you want to compile individual source files separately and then link them together later. It allows for faster compilation when you have multiple source files, as you can compile them independently and avoid recompiling the entire program every time.
    - `ar` stands for "archive" and is a command-line utility for creating and manipulating static libraries. It combines one or more object files into a single archive file. In the case of a static library, it allows you to package your compiled code into a single file that can be linked with other programs during the compilation process.
        - `r`: Replace or add files to the archive.
        - `c`: Create the archive if it doesn't exist.
        - `s`: Write an index into the archive, which helps with faster symbol lookup during linking
    - `libmylib_static.a` is the name of the static library that will be created. The prefix `lib` is commonly used for libraries, followed by the name of the library (`mylib_static` in this case), and **the extension `.a` indicating it's a static library**.
    - The reason you needed to use the `ar` command separately is that creating a static library involves an additional step of archiving the object files into a single library file. When you compile a source file with `g++`, it produces an object file (e.g., `mylib_static.o`) that contains the compiled machine code for the functions in that source file. To create a static library, you may need to combine multiple object files into a single library file, which can be achieved using the `ar` command. Let's say you have two source files: `foo.cpp` and `bar.cpp`. You want to create a static library that includes the functions defined in both files. First, compile each source file into object files:
    ```
    g++ -c foo.cpp -o foo.o
    g++ -c bar.cpp -o bar.o
    ```
    Next, use the `ar` command to combine the object files into a static library:
    ```
    ar rcs libmylib.a foo.o bar.o
    ```
    After running the above commands, you will have a static library file `libmylib.a` that contains the compiled functions from both `foo.cpp` and `bar.cpp`. You can then link this library with your main program during the compilation process. On the other hand, when creating a shared library, you typically compile each source file separately into object files and then link them together to create the shared library file.
1. **Create a shared library** (leave only the function declaration of the shared library in `mylib.h`). When creating a shared library, you typically compile the source files into object files (`*.o`) first, and then use the linker to combine these object files into a shared library. To convert the `.cpp` file to an object file, run:
    ```
        g++ -c -fPIC mylib_shared.cpp -o mylib_shared.o
    ```
    - `-fPIC`: This option stands for "Position Independent Code" is used when creating a shared library to ensure that the generated code is relocatable. Relocatable code can be loaded into memory at different addresses by the operating system without any issues. This is crucial for shared libraries because multiple processes can use the same shared library, and each process may load the library at a different address in memory.

    Then, you can create an shared library `.so` by linking these object files together:
    ```
        g++ -shared mylib_shared.o -o libmylib_shared.so
    ```
    - `-shared`: This option instructs the compiler (or linker) to create a shared library instead of an executable or a static library. A shared library contains code and data that can be loaded into memory and shared by multiple programs at runtime. It allows for dynamic linking, where the library is linked with the executable when it is loaded or during runtime.

    The reason you use different tools (`ar` for static libraries and `g++` for shared libraries) to create libraries is due to the nature of the libraries themselves and how they are meant to be used. When you create a static library, you're essentially creating an archive of object files. `ar` is specifically designed for that task. On the other hand, `g++` (or any `C`/`C++` compiler) can be used to create shared libraries. When you use `g++` to create a shared library, you're essentially compiling the source code directly into a shared library file (`.so` on Linux).

    Alternatively, if your shared library is based only on one `.cpp` file, you can directly convert it to the shared library as follows:
    ```
        g++ -shared -fPIC mylib_shared.cpp -o libmylib_shared.so
    ```
    In practice, both approaches are common, and the choice between them often depends on the development workflow and the complexity of the project. Compiling to object file first is the more traditional and flexible approach. You first compile the source code into object files separately. This approach offers several advantages:
        - Incremental Builds: If your project has multiple source files, you can compile them individually to object files. When you make changes to one source file, you only need to recompile that file and relink, which can significantly speed up development.
        - Reusability: You can reuse the object files in multiple projects or when creating different libraries/executables.
        - Better Control: You have more control over the compilation process and can optimize individual source files differently.
    In the direct compilation to shared library, you compile the source code directly into a shared library without generating intermediate object files. This can simplify the build process, especially for small projects. However, it has some limitations:
        - Slower Builds: Compiling the entire source code into a shared library in one step can be slower, especially for larger projects, as all code must be recompiled each time.
        - Limited Reusability: The shared library generated may not be as reusable across projects, as it includes all the compiled code in one file.
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
    - When compiling the main program, we specify the library to link against using the `-l` option (e.g., `-lmylib_static` or `-lmylib_shared`). The linker (`ld`) resolves the function call `printMessage()` by looking for the corresponding implementation in the linked library.
1. Run the programs:
    - `./program_static` for the static library
    - Before running `./program_shared` for the shared library, you must check whether the path of your shared library (`libmylib_shared.so`) is within the `LD_LIBRARY_PATH` environment variable. Setting the LD_LIBRARY_PATH environment variable is often necessary when you want to run an executable that depends on shared libraries that are not in the standard library search paths. This environment variable tells the dynamic linker where to find those libraries at runtime. If it is not set, you can run `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)` and then run `./program_shared`. Otherwise, you will get the error "./program_shared: error while loading shared libraries: libmylib_shared.so: cannot open shared object file: No such file or directory". This shows the fundamental difference between static and shared (or dynamic) library: shared library is loaded and linked dynamically at runtime when the program is executed. If it is not found by the linker, the program doesn't run.