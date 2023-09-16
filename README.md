# Build process

**What is a compiler?**

C/C++ compilers are software tools that translate human-readable source code written in the C or C++ programming languages into [*machine languages*][10], that is, a set of instructions made of zeros and ones. This set of instructions are represented in the computer as an executable file that can run on a computer's hardware.

**What is the build process?**

Build process is a multi-stage process that includes
- Preprocessing
- Compiling
- Assembling
- Linking

The key step is the compilation phase, where the source code is analyzed, optimized, and translated into an intermediate representation known as assembly code (for `C`) or object code (for `C++`). The software that perform these processes tasks are called *compiler* (although compiling is just one of the steps performed by the compiler).

**What are the main `C`/`C++` compilers?**

- GCC (GNU Compiler Collection): One of the most widely used open-source compilers, GCC supports a variety of programming languages, including `C` and `C++`. It's available on multiple platforms, making it a popular choice for `C`/`C++` development.
  - `gcc`: The GNU `C` Compiler, which primarily compiles `C` code.
  - `g++`: The GNU `C++` Compiler, which compiles `C++` code.
Both `gcc` and `g++` are part of the GCC suite and are commonly used to compile `C` and `C++` programs on various platforms, including Unix-like systems (Linux, macOS, BSD), as well as Windows through tools like MinGW or MSYS2.
  - MinGW (Minimalist GNU for Windows): MinGW is a port of the GCC (GNU Compiler Collection) for Windows. It provides a GCC-based development environment on Windows.
Developers who prefer GCC and a more Unix-like development experience often use MinGW on Windows.
It is suitable for cross-platform development and can target various platforms, including Windows.
- Clang: Developed by the LLVM project, Clang is known for its fast compilation times and excellent diagnostics. It's often used as an alternative to GCC, especially in the `C++` community. On [macOS][2], the most commonly used `C`/`C++` compiler is Clang, which is part of the LLVM (Low-Level Virtual Machine) project. Clang has become the default compiler on macOS for `C` and `C++` development.
  - `clang`: `C` compiler
  - `clang++`: `C++` compiler
- Microsoft Visual `C++` (MSVC): MSVC is the compiler provided by Microsoft as part of Visual Studio. It's a primary choice for [Windows][4] development with `C++`.
- Intel `C++` Compiler: Intel's compiler is known for its optimization capabilities, especially for Intel processors. It's commonly used in high-performance computing (HPC) and scientific computing.

---

## The usual and most direct compilation process (without build automation tools)

For 99.9999% of cases, to get the compilation done, it is enough to run
  ```
  ❯ gcc main.c -o straight-forward-program
  ❯ ./straight-forward-program
  Hello, World!
```

However, under the hood, the preprocessing, compiling, assembling, and linking have occurred silently. Let us break each step down.

---

## Preprocessing

![](./assets/preprocessing.png)

- [The][1] input file for this stage is `*.c` file.
- It performs the following tasks:
  - Removing comments : It removes all the comments.
  - [Line Splicing][18] (`\`): The backslash `\` is used for line splicing, allowing you to break long lines of code into multiple lines for readability, are concatenated to form a single line.
  - Header files inclusion: [For][16] example, if the directive `#include <stdio.h>` is available in the program, then the preprocessor interprets the directive and replaces this directive with the content of the `/usr/include/stdio.h` file.
  - *Macro* expansion: A macro is a preprocessor directive that allows you to define a symbolic name or identifier for a sequence of code. They are used to create code snippets that can be easily reused and to introduce simple text substitutions. The most common use of macros in C is through the `#define` directive, which defines a macro. They can be [constant][17] macros, e.g., `#define BUFFER_SIZE 1024`, or [function-like][18] macros, e.g., `#define MAX(a, b) ((a) > (b) ? (a) : (b))`.
  - Resolve the *conditional compilation directives*: Using special preprocessing directives, you can include or exclude parts of the program according to various conditions. For example, `#ifdef DEBUG printf("Debugging is enabled.\n"); #endif`. Other conditional compilations are `#ifndef`, `#if`, `#elif`, `#else`. The preprocessor evaluates these conditions and determines whether the enclosed code should be included in the preprocessed output file.
  - *Line Control*: The `C` preprocessor [informs][19] the `C` compiler of the location in your source code where each token came from. A token in C can be defined as the smallest individual element of the C programming language that is meaningful to the compiler. It is the basic component of a C program. They can be Keywords (`double`, `if`, `while`, `return`, ...); Identifiers (variable and function names); Constants (`const int c_var = 20;`); Strings;  Special Symbols (`[]`, `()`, `{}`, `,`, `#`, ...); Operators (unary, binary, and ternary operators);
- In nutshell, the preprocessor expands the code.
- The output file is `*.i` or preprocessed file.

### Example

```
  gcc -E main.c -o main.i
```
- [The][15] option `-E` Stop after the preprocessing stage; do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output (or to a file with the `-o` option).

Alternatively, you can directly use `cpp` (`C` preprocessor) to obtain the preprocessed file:

```
  cpp main.c -o main2.i
```
Note that both file are exactly the same
```
  ❯ cmp main.i main2.i && echo "Files are equal" || echo "Files are not equal"
  Files are equal
```

### Compilation

![](./assets/compiling.png)

- The input file for this stage is `*.i` file.
- [It][15] takes the output of the preprocessor and converts it to assembly language.
- Assembly code, often referred to as assembly language or just assembly, is a low-level programming language that uses mnemonic symbols (e.g., MOV for "move," ADD for "add") to represent CPU instructions (the so-called opcode), thus making the code human-readable. Each assembly instruction typically corresponds to a single machine code instruction that is specific to the target CPU. Therefore, Assembly code is highly platform-specific, meaning that it is tailored to a specific computer architecture and operating system. Code written in assembly for one type of CPU will not run on a different CPU architecture without modification.
- This is exactly the same code you may have worked with when programming some microcontrollers directly in assembly language (e.g., 8051 microcontroller).
``![](./assets/compiler_parts.png)

- The first part of the compiler is called Front End: in which, the analysis of program syntax and semantics happens. First stage of the front-end part of the compiler is scanning the input text and Tokenization by identifying tokens such as keywords, identifiers, operators, and literals, then passing the scanned token to the parsing tool that ensures tokens are organized according to C rules to avoid compiler syntax errors. Second stage of the front-end of the compiler is checking if the sentence that has been parsed has the right meaning. And, this semantic check, if it fails you get a Semantic Error.
- The second part convert the code to assembly code. This conversion is not a one to one mapping of lines but instead a decomposition of `C` operations into numerous assembly operations.
- The output file is `*.s` or `*.asm` file.

### example

```
  gcc -S main.i -o main.s
```
- `-S`: Stop after the stage of compilation proper;

Strictly speaking, this is the most crucial part of the compilation process and cannot be done by no one but the `gcc` compiler. When we use the `gcc` to directly generate the executable file (without breaking down all the steps), what happens under the hood is: The `gcc` delegates all other compilation steps (preprocessing, assembling, and linking) to `cpp`, `as`, and `ld`, respectively, and only performs the compilation step. By doing so, we, `C` developers, can be unworried in calling such tools as it is already done by `gcc`. Therefore, we can work with a unique command interface (the `gcc`) to perform all the compilation process.

## Assembling

![](./assets/assembler.png)

- The input file for this stage is `*.asm` or `*.s` file.
- If you use `gcc` to assemble the file, you must name the extension to `.s`. Otherwise, the `-c` option of `gcc` will try to link the file instead to assemble it.
- The assembler will convert the assembly code into lower-level intermediate representation, which is stored in the `.o` file, known as object file. This intermediate representation contains machine-level code, that is, non-human-readable instructions and data structures that represent the functions and variables defined in your code. The `.o` file is not the final executable code. It contains machine-readable instructions but is not directly executable by the operating system. It lacks some necessary information, such as the memory addresses of functions and variables, which is resolved during the linking phase.
- The output file is `*.o` or `*.obj` file.

### example

```
  gcc -c main.s -o main.o
```
Alternatively, you can run
```
  as main.s -o main.o
```

where `as` the the GNU assembler. Note that both output are exactly the same. Again, you can check that both approaches produce the same output:
```
  ❯ cmp main.o main2.o && echo "Files are equal" || echo "Files are not equal"
  Files are equal
```

## Linking

*A quick historical note:*
[In][20] the old days, when dinosaurs roamed the data centers, many programs were complete in themselves. In those days there was generally no compiler–people wrote directly in assembly code–and the assembler actually generated an executable file which the machine could execute directly. As languages liked Fortran and Cobol started to appear, people began to think in terms of libraries of subroutines, which meant that there had to be some way to run the assembler at two different times, and combine the output into a single executable file. This required the assembler to generate a different type of output, which became known as an object file (I have no idea where this name came from). And a new program was required to combine different object files together into a single executable. This new program became known as the linker (the source of this name should be obvious).

![](./assets/linker.png)

- The input file for this stage is `*.o` file.
- The linker merges all the object code from multiple modules into a single one. If we are using a function from libraries, linker will link our code with that library function code.
- The `C` Standard Libraries are typically bundled with the `gcc` compiler. When you install `gcc` or any other `C` compiler, it includes the necessary standard libraries required to compile and link `C` programs. These libraries are an integral part of the compiler distribution. Therefore, they don't exist as a separate shared library file on your system and you won't find it by looking for a `.so` (shared library) or `.a` (static library) file.
- For libraries outside the `C` standard library, you must to link it manually.


### example

```
  gcc main.o -o myprogram
```

where `myprogram` is the executable file. Alternatively, you could directly use the `ld` command, but guess what? Although it is not the most crucial part, manually linking you object file to an executable file is **COMPLICATED AS HELL**. At this point you are literally twiddling bits to perfectly match with the hardware and OS specifications of your machine. You must undestand stuffs such as computer organization and architecture, endianness, File Types, dynamic linker/loader paths, Build ID, OS Compatibility, Magic numbers, stripped and non-stripped executables, etc... Thankfully, `gcc` already knows all these details and wonderfully does this hard work for us by internally invoking `ld` with all the necessary options set.


---

## From executable code to the bit level: A deeper dive

The content inside `./myprogram` is the machine code or binary representation of your compiled program. It consists of instructions and data that the computer's processor can understand and execute directly. We can dive deeper and the the `./myprogram` at bit level or, equivalently, at hexadecimal level by using the `xxd` tool.

```
  xxd ./myprogram -o myprogram.hex
```

Use the `-b` flag if you want to obtain bits instead hexadecimals and save it with the `.bin` extension. The first line of hex digits are:

```
  00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000  .ELF............
```

1. Each hexadecimal digit contains 4 bits.
1. Each set of 4 hexadecimal digits contain 16 bits or 2 bytes (each byte contains 8 bits)
1. `00000000` counts, in hexadecimal, the number of bytes in the executable file (?). At the end of this line goes to `00000010`.
1. `.ELF............` is the actual content that the hexadecimal digits represents.
  - `7f45 4c46` represents the `ELF` values, which stands for Executable and Linkable Format. This sequence of hex digits is magic number, which is a signature indicating that this is an ELF file.
  - `0201` represents the ELF file class and data encoding (e.g., 32-bit or 64-bit, little-endian or big-endian).
  - `0100` represents the ELF file version.


[1]: https://www.linkedin.com/pulse/c-build-process-details-abdelaziz-moustafa/

[2]: https://medium.com/hayoung-techlog/setup-for-c-on-mac-d2056a025c85#:~:text=Oct%203%2C%202022-,Clang%20vs%20G%2B%2B,%2B%2B%20is%20GNU%20c%2B%2B%20compiler.

[4]: https://www.reddit.com/r/cpp/comments/3pe6j9/why_should_i_use_clang_over_g/

[5]: https://llvm.org/

[6]: https://stackoverflow.com/questions/5708670/llvm-vs-clang-on-os-x#:~:text=LLVM%20is%20a%20backend%20compiler,a%20representation%20suitable%20for%20LLVM.

[8]: https://en.wikipedia.org/wiki/LLVM

[9]: https://en.wikipedia.org/wiki/Just-in-time_compilation (?)

[10]: https://cplusplus.com/doc/tutorial/introduction/

[11]: https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B

[12]: https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/

[13]: https://www.learncpp.com/cpp-tutorial/introduction-to-programming-languages/

[14]: https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/

[15]: https://www.linkedin.com/pulse/understanding-c-program-compilation-process-fernandez-barreto/

[16]: https://www.linkedin.com/pulse/explanation-all-steps-compilation-juan-diego-petter/

[17]: https://gcc.gnu.org/onlinedocs/cpp/Object-like-Macros.html

[18]: https://en.wikipedia.org/wiki/C_preprocessor#Phases

[19]: https://gcc.gnu.org/onlinedocs/cpp/Line-Control.html

[20]: https://www.airs.com/blog/archives/38
