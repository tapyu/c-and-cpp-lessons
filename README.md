# Makefile

#### **What is the Makefile** 
[A][3] Makefile is one of the earliest build automation tool of software projects, used primarily in Unix and Unix-like operating systems. It is a text file which contains a set of rules and dependencies that specify how the project's source code files should be compiled and linked to create executables, libraries, or other output files. Makefiles are written in a simple scripting language and are processed by the `make` utility.

Makefiles are essential tools in `C`/`C++` projects for automating the build process. [Its][4] primary usage in the build automation from the source files (`.c` or `.cpp`) to object files (`.o`). By having separate `.c` or `.cpp` files, each one providing a specific functionality, can convert each file to a `.o` object file, and then link all these files together to create an executable file. **If we change we change one of these source file, we can just recompile that file in order to get this updated `.o` object file, and then link all the object files back together again. That is, we don't need to redo any work in the other object files whose source files remained untouchable**. It is a much faster and the best approach, and the `Makefile` helps developers to automate such tasks.

[However][15], in this context of having multiple `.c`/`.cpp` files, it is quite common to have situations in which a source file uses a function from another source file. It is where the header files comes in. One of its utility is to inform to the function prototypes/declarations that there exist into another source file(see `./c-header-files-for-func-prototypes/` in the `libraries-and-header-files` branch).


---

## Example
![](./assets/example.png)

### Performing it manually

To compile `tip`, run:
```
gcc -c tip.c
gcc -c gd.c
gcc -o tip tip.o gd.o
```

To compile `geom`, run:
```
gcc -c geom.c
gcc -c gd.c
gcc -o geom gd.o geom.o -lm
```

### Performing it by using `./Makefile`

Just run `make`


[1]: https://www.youtube.com/watch?v=GExnnTaBELk
[2]: https://www.learncpp.com/cpp-tutorial/header-files/
[3]: https://en.wikipedia.org/wiki/Build_automation
[4]: https://youtu.be/GExnnTaBELk?t=981
[5]: https://youtu.be/GExnnTaBELk?t=1402