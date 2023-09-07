# Libraries

*What is a library?*
A C/C++ library is a collection of precompiled code modules that can be used to perform common tasks or provide reusable functionality within C or C++ programs. 

*How does a library look like on my computer?*
Libraries on your computer are typically stored as binary files. The exact file format and organization can vary depending on the programming language, the platform.
- *Shared Libraries (Dynamic Link Libraries - DLLs on Windows, Shared Objects - SO files on Linux, Dylibs on macOS)*: These are libraries that are loaded at runtime when a program is executed. They have a file extension like `.dll`, `.so`, or `.dylib`. These files contain compiled code that multiple programs can use simultaneously. They are typically stored in system directories or directories specified in the system's library search path.
- *Static Libraries (Libraries - LIB files on Windows, Archive files - A files on Linux)*: These are libraries that are linked with the program at compile-time. They contain precompiled object code. On Windows, they have a `.lib` extension, and on Linux, they are often archive files with a `.a` extension. Static libraries are linked directly into the executable, increasing the size of the resulting binary.
- *Standard Libraries*: The standard libraries for C and C++ are typically provided as part of the compiler installation. These libraries include the C Standard Library (libc on Unix-like systems), the C++ Standard Library (libstdc++ or libc++ on Unix-like systems), and others. They are typically located in system directories.
- *Header Files*: In addition to the binary library files, libraries often provide header files (with extensions like `.h`, `.hpp`, or `.hxx`) that contain declarations of functions, classes, and data structures provided by the library. Header files are typically included in your source code to use the library's functionality.

*Main categories for a C/C++ library*
- *Functionality and Purpose*:
    - *Standard Libraries*: Bundled with the programming language or platform (e.g., C Standard Library, C++ Standard Library).
    - *Utility Libraries*: Provide general-purpose functions and utilities (e.g., string manipulation, data structures).
    - *Domain-Specific Libraries*: Focus on specific application domains (e.g., graphics, scientific computing, networking).
- *Linking Method*:
    - *Static Libraries*: Linked at compile-time, resulting in larger executables.
    - *Shared Libraries*: Loaded at runtime, reducing executable size and enabling code sharing.
- *Ownership and Source*:
    - *Third-Party Libraries*: Developed by external sources, not part of the language or platform.
    - *Standard Libraries*: Officially provided and maintained by the language or platform.
- *Distribution*:
    - *Packaged Libraries*: Distributed as binary packages (e.g., DLLs, SO files) or package manager dependencies.
    - *Source Libraries*: Distributed as source code that must be compiled and linked.
- *Platform Compatibility*:
    - *Cross-Platform Libraries*: Designed to work on multiple operating systems and architectures.
    - *Platform-Specific Libraries*: Designed for a specific platform or architecture.
- *Licensing*:
    - *Open Source Libraries*: Released under open-source licenses (e.g., MIT, GPL).
    - *Proprietary Libraries*: Owned and licensed by a specific organization or company.

- *What is the header file?*
When using a library, whether static or shared, it is common practice to provide a corresponding header file (`.h`) that contains the necessary declarations for the library's functions, classes, structures, and other entities. This allows users of the library to include the header file in their own code and access the functionality provided by the library. In `C++`, the `#include` directive is used to include header files. Header files typically contain function declarations, class definitions, constants, and other declarations that are needed for the compilation and usage of functions and types defined in the external source file (`.cpp` file). It is a common convention to give them the same base name (e.g., `mylib.h` and `mylib.cpp`) for clarity and organization, but it is not a strict requirement. Header files serve as a way to communicate the interface of the library to users, enabling them to properly use and interact with the library's features.

- *What is the difference between a shared and a static library?*
Shared Libraries (Dynamic Link Libraries on Windows, Shared Objects on Linux, and Dylibs on macOS) and Static Libraries serve different purposes in software development and are linked with programs in different ways. The main difference between using a shared library and a static library lies in how the library is linked to your program at runtime. When you link against a static library, the library code is physically copied into your executable file during the linking process. This means that your program becomes self-contained and can be run independently without relying on the presence of the static library at runtime. The library code becomes part of your program's binary.

On the other hand, when you link against a shared library, your program only contains references to the functions or symbols provided by the library. The actual library code resides in a separate shared library file (`.so` file on Linux, `.dll` file on Windows). At runtime, the operating system dynamically loads the shared library and resolves the references from your program to the corresponding functions in the library. This allows multiple programs to share the same instance of the library in memory, reducing memory usage.

In terms of workflow, the process of compiling and linking your program is generally the same whether you're using a shared library or a static library. You still need to include the necessary header files, link against the library, and ensure the library is properly installed on the system.

Overall, the choice between using a shared library or a static library depends on various factors, including the specific requirements of your program, considerations for memory usage, ease of deployment, and potential library versioning issues.

A shared library is often referred to as a runtime library because it is loaded and linked dynamically at runtime when the program is executed. It provides functionality that can be accessed by multiple programs simultaneously. A static library, on the other hand, is often referred to as a development library because it is used during the development and compilation phase of a program. It contains precompiled code that is linked directly into the executable at compile time, making the program self-contained and independent of external dependencies. However, it's important to note that these terms can sometimes be used interchangeably or with different interpretations depending on the context. The key distinction is that shared libraries are dynamically linked at runtime, while static libraries are statically linked at compile time.

---
## Example

In this example, we have a main program (`main.cpp`) that includes the header file `mylib.h`. The header file provides the function prototype for `printMessage()`. The actual implementation of `printMessage()` is defined in separate source files `mylib_static.cpp` and `mylib_shared.cpp`, which are compiled into static (`libmylib_static.a`) and shared (`libmylib_shared.so`) libraries, respectively.

Now, let's compile and use these files to create both a static and shared library.

1. **Create a static library** (uncomment the `mylib.h` for the static header):
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
    Next, use the ar command to combine the object files into a static library:
    ```
    ar rcs libmylib.a foo.o bar.o
    ```
    After running the above commands, you will have a static library file `libmylib.a` that contains the compiled functions from both `foo.cpp` and `bar.cpp`. You can then link this library with your main program during the compilation process. On the other hand, when creating a shared library, you typically compile each source file separately into object files and then link them together to create the shared library file.
1. **Create a shared library** (uncomment the `mylib.h` for the shared header). When creating a shared library, you typically compile the source files into object files (`*.o`) first, and then use the linker to combine these object files into a shared library.
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
