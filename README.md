# Pointers

## **What are pointers?**

In `C` and `C++`, pointers are variables that store memory addresses as their values. In essence, it "points" to the location in memory where a specific piece of data is stored. Pointers provide a way to indirectly access and manipulate data in memory (see `./basic-functionality/main.c`).

---

## **Pointer Syntax**

<table>
<tr>
    <th colspan="3"><h2>Pointer syntax</h2></th>
</tr>
<tr>
    <th>Code</th>
    <th><a href="https://www.youtube.com/watch?v=2ybLD6_2gKM&ab_channel=LowLevelLearning">How you should read it</a></th>
    <th>Comments</th>
</tr>
<tr>
    <td>${\color{blue}int \space \color{red}* \color{violet}px \space \color{green}= \space \color{yellow}\& \color{cyan}x}$</td>
    <td>${\color{blue}Integer \space \color{red}pointer \space \color{violet}named \space px \space \color{green}is \space set \space to}$
        ${\color{yellow}the \space address \space of \space \color{cyan}x}$.</td>
    <td>This syntax is used to initialize the pointer variable. This is the unique situation that $\color{red}*$ reads $\color{red}pointer$. In all others, $\color{red}*$ will denote the dereference process. By "integer pointer", we mean that this pointer points to an address whose stored value is an integer. The syntax <code>int* px = &x;</code> can also be used as an alternative to <code>int *px = &x;</code>. Although both are commonly adopted, I prefer the latter <a href="https://stackoverflow.com/questions/14536658/pointer-syntax-in-c">because</a> <code>int* a, b;</code> produces a integer pointer <code>a</code> and an integer <code>b</code>, even though it wrongly seems that both <code>a</code> and <code>b</code> are integer pointers. However, the former is useful for casting, e.g. <code>char *char_ptr = (char*)int_ptr;</code> (see the casting branch).</td>
</tr>
<tr>
    <td>${\color{blue}int \space \color{red}* \color{violet}parr \space \color{green}= \space \color{cyan}arr}$</td>
    <td>${\color{blue}Integer \space \color{red}pointer \space \color{violet}named \space parr \space \color{green}is \space set \space to}$
        ${\color{cyan}the \space address \space of \space the \space first \space element \space in}$ ${\color{cyan} the \space integer \space array \space arr}$
        <br>or<br>
        ${\color{blue}Integer \space \color{red}pointer \space \color{violet}named \space parr \space \color{green}is \space set \space to}$
        ${\color{cyan}the \space internal \space pointer \space of \space the \space}$ ${\color{cyan} variable \space arr}$.</td>
    <td>In this command, <code>arr</code> is some <code>int</code> array. When you use this syntax, you are telling <code>parr</code> to store the memory address of the first array element of <code>arr</code> (<code>arr[0]</code>). We call this memory address the <b>internal pointer variable</b>. All <a href="https://en.wikipedia.org/wiki/Composite_data_type">composite data types</a> (e.g., arrays, structures, etc...) have its own internal pointer, and it is always the memory address of its first element (see <code>./pointer-arithmetic/int_array.c</code>). Note that it also works for strings as they are represented as <code>char</code> arrays in <code>C</code> and therefore are also a composite data type (see <code>./pointer-arithmetic/char_array.c</code>). This syntax is equivalent to <code>int *parr = &arr[0]</code>, but it is much more concise and therefore more adopted. When the compiler uses the internal pointer of the variable, we often say that "the variable <b>decays</b> into a pointer to its first element". On the other hand, we cannot write <code>int *p = i</code> if <code>i</code> is a single <code>int</code> because it is a <a href="https://en.wikipedia.org/wiki/Primitive_data_type">primitive data type</a> and therefore it has no internal pointer variable.</td>
</tr>
<tr>
    <td>${\color{red}* \color{violet}px \space \color{green}= \space \color{cyan}5}$</td>
    <td>${\color{red}The \space stored \space value \space pointed \space by \space}$
        ${\color{violet}px \space \color{green}is \space set \space to \space \color{cyan}5}$.</td>
    <td>This process is called "dereference", and it is used to assign the new value to a variable that is out of the scope in question.</td>
</tr>
<tr>
    <td>${\color{blue}int \space \color{cyan}y \space \color{green}= \space \color{red}* \color{violet}px}$</td>
    <td>${\color{blue}Integer \space \color{cyan}named \space y \space \color{green}is \space set \space to \space}$
        ${\color{red}the \space stored \space value \space pointed \space by \space \color{violet}px}$.</td>
    <td>It is also a dereference, but in the other way around, that is, the value of a variable that is out of the scope in question is assigned to a local variable.</td>
</tr>
<tr>
    <td>${\color{blue}int \space \color{cyan}y \space \color{green}= \space \color{violet}parr \color{orange}[n]}$</td>
    <td>${\color{blue}Integer \space \color{cyan}named \space y \space \color{green}is \space set \space to \space}$
        ${\color{violet}the \space value \space in \space the \space memory \space address}$
        ${\color{violet}pointed \space by \space parr, \space \color{orange}but \space shifted \space}$
        ${\color{orange}in \space n\times X \space bytes}$</td>
    <td>In this expression, <code>X</code> is the memory size (in bytes) of each element in the array <code>arr</code> and <code>n</code> is any positive or negative interger value. This notation is an sintactic sugar to its <a href="https://stackoverflow.com/questions/4622461/difference-between-pointer-index-and-pointer">equivalent</a> command, <code>*(parr+n)</code>. In fact, a pointer arithmetic is performed on <code>parr</code> before dereferencing it. This syntax might be called "dereference via indexing". See the <a href="https://github.com/tapyu/c-and-cpp-lessons/tree/5-pointer-reference-memory#what-is-pointer-arithmetic">pointer arithmetic</a> section for more info.</td>
</tr>
<tr>
    <td>${\color{violet}parr \color{orange}[n] \space \color{green}= \space \color{cyan}5}$
        ${\color{violet}The \space value \space in \space the \space memory \space address}$
        ${\color{violet}pointed \space by \space parr, \space \color{orange}but \space shifted \space}$
        ${\color{orange}in \space n\times X \space bytes}$</td>
        ${\color{green}is \space set \space to \space \color{cyan}5}$
    <td>Same shit, but in the other way around.</td>
</tr>
<tr>
     <td>${\color{red}p->age \space \color{green}= \space \color{cyan}5}$</td>
    <td>${\color{red}The \space stored \space value \space of \space the \space struct's}$
        ${\color{red}feild \space age \space that \space p \space points \space to \space \color{green}is \space set \space to \space \color{cyan}5}.$</td>
    <td>In this case, the pointer <code>p</code> is a structure pointer, e.g., <code>struct Person *p = &mike</code>. Note that the syntax <code>p->age</code> <a href="https://stackoverflow.com/questions/2575048/arrow-operator-usage-in-c/2575050#2575050">is equivalent to</a> <code>(*p).age</code></td>
</tr>
</table>

#### **What is pointer arithmetic?**

Pointer arithmetic is a fundamental concept in programming languages like `C` and `C++`, which allows you to perform arithmetic operations on pointers. Specifically, it involves adding or subtracting integers to/from pointers to manipulate memory addresses (see `./pointer-arithmetic/` examples).

- *Adding an Integer to a Pointer*: When you add an integer value to a pointer, you are effectively shifting forward the memory address stored by the pointer in a certain number of bytes. The size of the offset depends on the data type that the pointer points to. If `ptr` points to a variable type `X`, and this type occupies `Y` bytes in the memory, then the memory addres that `ptr` stores will be shifted forward in `Y` bytes. Desipe the memory size offset that the stored memory address will undergo, you can simply type `ptr = ptr + n;` (or `ptr+=n`), and then the memory address stored in `ptr` will be shifted forward in `n*Y` bytes. For example (you could use `ptr++`):
```c
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr; // ptr points to the internal pointer variable of `arr`, that is, the address of its first array element, 10.
    ptr = ptr + 1; // Move ptr to the next integer (20)
    int i = *ptr; // `i` is `20`
```
- *Subtracting an Integer from a Pointer*: You can also subtract an integer from a pointer, which has the opposite effect of moving the pointer backward in memory. Again, the size of the offset depends on the data type. For example (you could use `ptr--;` instead of `ptr = ptr - 1;`):
```c
    int arr[] = {10, 20, 30, 40};
    int *ptr = &arr[2]; // ptr points to the third element (30)
    ptr = ptr - 1; // Move ptr to the previous integer (20)
```

Sometimes you want to derefence the memory address pointed by `ptr` shifted by some amount, but you don't want to modify the the memory address stored in `ptr` during this process. In that situation, you can dereference via indexing:
```c
int arr[] = {50, 60, 70, 80, 90, 100, 110};
int *ptr = arr; // ptr points to the internal pointer variable of `arr`, that is, the address of its first array element, 50.
int i = ptr[2]; // dereference via indexing: `i` is set to `70`, the memory address of `ptr` did not change
```

Although this notation conveys the idea of an ordinary array indexing (i.e., `arr[2]`) and although it yields the same result of `arr[2]`, what we are doing here is: 1- Pointer arithmetic (but without modifying `parr`) 2- Dereference. In fact, the syntax `parr[2]` is equivalent to `*(parr + 2)` (first we do pointer arithmetic wihtout changing `parr`, then we dereference the resulting memory address). See `./pointer-arithmetic/dereference-via-indexing.c`.

---

# Memory

#### **What is memory allocation?**

Memory allocation involves reserving a specific number of bytes in the computer's memory (RAM - Random Access Memory) for a specific purpose. This reserved space can be used to store data structures, variables, arrays, objects, and other program-related information.. It is a fundamental concept in computer programming and is crucial for managing data and resources efficiently.

#### **Static vs. dynamic memory allocation**

Memory can be allocated either at compile-time (static memory allocation) or at runtime (dynamic memory allocation). Dynamic memory allocation, often used in languages like C and C++, allows memory to be allocated and deallocated during program execution, providing flexibility in managing memory resources. When memory is allocated dynamically, a pointer is used to keep track of the allocated memory's location.

#### **What are deallocation and memory leak?**

Proper memory management also involves deallocating memory when it is no longer needed. Failure to deallocate memory can result in memory leaks, where memory is reserved but never released, leading to decreased system performance and potential program crashes.

#### **What are memory safety and garbage collector?**

Ensuring that allocated memory is used correctly and avoiding issues like buffer overflows (writing beyond allocated memory) is essential for memory safety. Languages like `C` and `C++` provide powerful memory management but also require careful coding practices to prevent memory-related errors. In some programming languages (e.g., `Java`, `C#`), automatic memory management techniques like garbage collection are used to automatically reclaim memory that is no longer in use. This simplifies memory management for programmers but introduces its own set of considerations.  In contrast to languages with garbage collection, languages like `C` and `C++` require manual memory management using `malloc()`, `free()`, `new()`, and `delete()` to allocate and deallocate memory. This can be error-prone but offers more control over memory usage.

## Memory size of variables (in bytes)

*The memory size of common data types in C can vary depending on the compiler and the target system's architecture*. However, there are standard data types with specified **minimum size** requirements in the `C` language standard. The sizes of unsigned types are typically the same as their signed counterparts on most systems and compilers (e.g., `unsigned int` typically uses at least 2 bytes, just like `int`). See `./memory-size-variables/main.c`.

<table>
<tr>
    <th colspan="5"><h2>Variables</h2></th>
</tr>
<tr>
    <th>Variable type</th>
    <th>Bytes (a byte contains 8 bits)</th>
    <th><code>%</code> syntax</th>
    <th>Suffix for literals</th>
    <th>Comments</th>
</tr>
<tr>
    <td><code>char</code></td>
    <td>Tipically 1 byte (8 bits)</td>
    <td><code>%c</code></td>
    <td></td>
    <td>The a <code>char</code> variable may be signed or unsigned depending on the compiler's implementation. To explicitly specify the signedness of a <code>char</code>, you can use <code>signed char</code> or <code>unsigned char</code>.</td>
</tr>
<tr>
    <td><code>signed char</code></td>
    <td>Tipically 1 byte (8 bits)</td>
    <td><code>%c</code> (or <code>%hhi</code> for numerical output)</td>
    <td></td>
    <td>Of the same size as <code>char</code>, but guaranteed to be signed. Capable of containing at least the <code>[−127, +127]</code> range.</td>
</tr>
<tr>
    <td><code>unsigned char</code></td>
    <td>Tipically 1 byte (8 bits)</td>
    <td><code>%c</code> (or <code>%hhi</code> for numerical output)</td>
    <td></td>
    <td>Of the same size as <code>char</code>, but guaranteed to be unsigned. Capable of containing at least the <code>[0, 255]</code> range.</td>
</tr>
<tr>
    <td><code>int</code>, <code>signed</code>, <code>signed int</code></td>
    <td>At least 2 bytes (16 bits)</td>
    <td><code>%i</code>,<code>%d</code> (or <code>%o</code> or <code>%x</code> if you are using octal or hexadecimal representation, respectively)</td>
    <td></td>
    <td>Basic signed integer type. Capable of containing at least the <code>[−32,767, +32,767]</code> range. Use <code>0</code> or <code>0x</code> prefix if you are using octal or hexadecimal representation. The convesion to decimal (and vice-versa) is direct when you use <code>%i</code> or <code>%d</code> to refer to a hexadecimal or octal number.</td>
</tr>
<tr>
    <td><code>unsigned</code>, <code>unsigned int</code></td>
    <td>2 bytes (16 bits)</td>
    <td><code>%u</code></td>
    <td><code>u</code>, <code>U</code></td>
    <td>Basic unsigned integer type. Contains at least the <code>[0, 65,535]</code> range.</td>
</tr>
<tr>
    <td><code>short</code>, <code>short int</code>, <code>signed short</code>, <code>signed short int</code></td>
    <td>2 bytes (16 bits)</td>
    <td><code>%hi</code> or <code>%hd</code></td>
    <td></td>
    <td>Short signed integer type. Capable of containing at least the <code>[−32,767, +32,767]</code> range.</td>
</tr>
<tr>
    <td><code>unsigned short</code>, <code>unsigned short int</code></td>
    <td>2 bytes (16 bits)</td>
    <td><code>%hu</code></td>
    <td></td>
    <td>Short unsigned integer type. Contains at least the <code>[0, 65,535]</code> range.</td>
</tr>
<tr>
    <td><code>long</code>, <code>long int</code>, <code>signed long</code>, <code>signed long int</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td><code>%li</code>,<code>%ld</code></td>
    <td><code>l</code>, <code>L</code></td>
    <td>Long signed integer type. Capable of containing at least the <code>[−2,147,483,647, +2,147,483,647]</code> range.</td>
</tr>
<tr>
    <td><code>unsigned long</code>, <code>unsigned long int</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td><code>%lu</code></td>
    <td>both <code>l</code> or <code>L</code> and <code>u</code> or <code>U</code></td>
    <td>Long unsigned integer type. Capable of containing at least the <code>[0, 4,294,967,295]</code> range.</td>
</tr>
<tr>
    <td><code>long long</code>, <code>long long int</code>, <code>signed long long</code>, <code>signed long long int</code></td>
    <td>At least 8 bytes (64 bits).</td>
    <td><code>%lli</code>, <code>%lld</code</td>
    <td><code>ll</code> or <code>LL</code></td>
    <td>Long long signed integer type. Capable of containing at least the <code>[−9,223,372,036,854,775,807, +9,223,372,036,854,775,807]</code> range. Specified since the C99 (ISO/IEC 9899:1999) version of the standard.</td>
</tr>
<tr>
    <td><code>unsigned long long</code>, <code>unsigned long long int</code></td>
    <td>At least 8 bytes (64 bits).</td>
    <td><code>%llu</code></td>
    <td>both <code>u</code> or <code>U</code> and <code>ll</code> or <code>LL</code></td>
    <td>Long long unsigned integer type. Capable of containing at least the <code>[0, 18,446,744,073,709,551,615]</code> range. Specified since the C99 (ISO/IEC 9899:1999) version of the standard.</td>
</tr>
<tr>
    <td><code>float</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td><code>%f</code>, <code>%F</code>, <code>%g</code>, <code>%G</code>, <code>%e</code>, <code>%E</code>, <code>%a</code>, <code>%A</code></td>
    <td><code>f</code>, <code>F</code></td>
    <td>Real floating-point type, usually referred to as a "single-precision floating-point type". It is a <b>good practice</b> to add the <code>f</code> suffix to make it clear to the compiler and other developers that you are working with a <code>float</code> rather than a <code>double</code>. By default, many compilers treat numeric literals without suffixes as double. For example, <code>float f1 = 3.14;</code> may be implicitly treated as a <code>double</code>, while <code>float f2 = 3.14f;</code> is not. It's important to note that while using the <code>f</code> suffix is a good practice for <code>float</code> literals, it's not mandatory. In many situations, the compiler can perform implicit conversions from <code>double</code> to <code>float</code> when necessary. However, using the <code>f</code> suffix can help prevent unexpected behavior or type mismatch issues in your code, especially when dealing with <code>float</code> variables and constants.</td>
</tr>
<tr>
    <td><code>double</code></td>
    <td>At least 8 bytes (64 bits).</td>
    <td><code>%lf</code>, <code>%lF</code>, <code>%lg</code>, <code>%lG</code>, <code>%le</code>, <code>%lE</code>, <code>%la</code>, <code>%lA</code></td>
    <td></td>
    <td>Real floating-point type, usually referred to as a "double-precision floating-point type", or simply "double".</td>
</tr>
<tr>
    <td><code>long double</code></td>
    <td>At least 10 bytes (80 bits) on some systems.</td>
    <td><code>%Lf</code>, <code>%LF</code>, <code>%Lg</code>, <code>%LG</code>, <code>%Le</code>, <code>%LE</code>, <code>%La</code>, <code>%LA</code></td>
    <td><code>L</code>, <code>l<code></td>
    <td></td>
</tr>
<tr>
    <td><code>size_t</code></td>
    <td>Typically 32 bits (4 bytes) on 32-bit systems or 64 bits (8 bytes) on 64-bit systems</td>
    <td><code>%zu</code></td>
    <td></td>
    <td>An unsigned integer type that is used for representing the sizes of objects in memory. It is often used when dealing with memory allocation, arrays, and indexing. The <code>size_t</code> type is guaranteed to be able to represent the size of the largest object that can exist in the memory of the system.</td>
</tr>
<tr>
    <td>Any pointer type</td>
    <td>4 bytes (32 bits) of memory on 32-bit systems, or 8 bytes (64 bits) of memory on 64-bit systems.</td>
    <td><code>%p</code></td>
    <td></td>
    <td>It can be a memory address of any-type variable, and you can pass it by accessing the value stored (i.e., the memory address) of a pointer that points to it, or you can access its memory address directly (e.g., <code>&x</code>, where <code>x</code> is any variable type).</td>
</tr>
<tr>
    <th colspan="5"><h3><code>C++</code>-only data types</h3></th>
</tr>
<tr>
    <th>Variable type</th>
    <th>Bytes (a byte contains 8 bits)</th>
    <th><code>%</code> syntax</th>
    <th>Suffix for literals</th>
    <th>Comments</th>
</tr>
<tr>
    <td><code>bool</code></td>
    <td>Typically 1 byte (8 bits), representing <code>true</code> or <code>false</code>.</td>
    <td></td>
    <td></td>
    <td></td>
</tr>
<tr>
    <td>User-defined types</td>
    <td>Classes and structures in C++ can have variable sizes based on their member variables and alignment requirements.</td>
    <td></td>
    <td></td>
    <td></td>
</tr>
</table>


---

# References

## **Reference syntax**

<table>
<tr>
    <th colspan="3"><h2>Pointer syntax</h2></th>
</tr>
<tr>
    <th>Code</th>
    <th>How you should read it</th>
    <th>Comments</th>
</tr>
<tr>
    <td>${\color{blue}int \space \color{yellow}\& \color{violet}rx \color{green}= \color{cyan}i}$</td>
    <td>${\color{blue}Integer \space \color{yellow}reference \space \color{violet}named \space rx \space \color{green}is \space set \space to \space \color{cyan}the \space integer \space variable \space i}$</td>
    <td>This syntax is used to initialize a reference variable.</td>
</tr>
</table>

#### **What are references?**

In `C++` (and some other programming languages, but not in `C`), a reference is a mechanism that allows you to create an alias or an alternative name for an existing variable (see `./refs-vs-pointers/`).

#### **References vs. Pointers**

In `C`, which has no references, you primarily work with pointers to achieve similar functionality to what references provide in `C++`. In other words, there is an overlap in the functionalities provided by them. Certain things can be done by using either pointer or references (see `./refs-vs-pointers/ref-pointer-equivalency.cpp`). However, there are fundamental differences beween both:
1. References cannot be `NULL` (e.g., you cannot write `int &ref = NULL;`);
1. You cannot change the variable e.g. referenced by a reference. Once a reference is *associated* to a variable, it is that way forever (e.g., if `int $ref = i;`, you cannot also write `int $ref = another_i;`);
1. You cannot do math on references (e.g., you cannot write `int &a = i + 1;`) as you can do on pointers (e.g., you can write `int *pi = &i + 1`). See `./pointer-arithmetic/pointerpp.c`;
1. While you can have pointer to pointer (e.g., if `int *px = &x;` you can write `int **ppx = &px;`), you cannot have references to references (e.g., if `int &rx = x;`, you cannot write `int &&rrx = rx`). See `./pointers-to-pointers/`.

**The main point is, for some tasks, it is easier to work with references instead of pointers** (see `./refs-vs-pointers/with-ref-is-much-easier.cpp`). Moreover, [this crazy guy here][2] said that **all references is, under the hood, a pointer** but with some operation restrictions that make it easier to work with for some tasks. By running

```sh
objdump -d -Mintel ./refs-vs-pointers/how | less
```

we get in `main` section
```
0000000000001169 <main>:
    1169:       f3 0f 1e fa             endbr64 
    116d:       55                      push   rbp
    116e:       48 89 e5                mov    rbp,rsp
    1171:       48 83 ec 20             sub    rsp,0x20
    1175:       64 48 8b 04 25 28 00    mov    rax,QWORD PTR fs:0x28
    117c:       00 00 
    117e:       48 89 45 f8             mov    QWORD PTR [rbp-0x8],rax
    1182:       31 c0                   xor    eax,eax
    1184:       c7 45 e4 00 00 00 00    mov    DWORD PTR [rbp-0x1c],0x0
    118b:       48 8d 45 e4             lea    rax,[rbp-0x1c]
    118f:       48 89 45 e8             mov    QWORD PTR [rbp-0x18],rax
    1193:       48 8d 45 e4             lea    rax,[rbp-0x1c]
    1197:       48 89 45 f0             mov    QWORD PTR [rbp-0x10],rax
    119b:       48 8b 45 e8             mov    rax,QWORD PTR [rbp-0x18]
    119f:       8b 00                   mov    eax,DWORD PTR [rax]
    11a1:       8d 50 01                lea    edx,[rax+0x1]
    11a4:       48 8b 45 e8             mov    rax,QWORD PTR [rbp-0x18]
    11a8:       89 10                   mov    DWORD PTR [rax],edx
    11aa:       48 8b 45 f0             mov    rax,QWORD PTR [rbp-0x10]
    11ae:       8b 00                   mov    eax,DWORD PTR [rax]
    11b0:       8d 50 01                lea    edx,[rax+0x1]
    11b3:       48 8b 45 f0             mov    rax,QWORD PTR [rbp-0x10]
    11b7:       89 10                   mov    DWORD PTR [rax],edx
    11b9:       8b 45 e4                mov    eax,DWORD PTR [rbp-0x1c]
    11bc:       89 c6                   mov    esi,eax
    11be:       48 8d 05 3f 0e 00 00    lea    rax,[rip+0xe3f]        # 2004 <_IO_stdin_used+0x4>
    11c5:       48 89 c7                mov    rdi,rax
    11c8:       b8 00 00 00 00          mov    eax,0x0
    11cd:       e8 9e fe ff ff          call   1070 <printf@plt>
    11d2:       b8 00 00 00 00          mov    eax,0x0
    11d7:       48 8b 55 f8             mov    rdx,QWORD PTR [rbp-0x8]
    11db:       64 48 2b 14 25 28 00    sub    rdx,QWORD PTR fs:0x28
    11e2:       00 00 
    11e4:       74 05                   je     11eb <main+0x82>
    11e6:       e8 75 fe ff ff          call   1060 <__stack_chk_fail@plt>
    11eb:       c9                      leave  
    11ec:       c3                      ret    
```

Let us break it down:
- `1184: mov    DWORD PTR [rbp-0x1c],0x0`: Move the value `0` into a 32-bit memory location located 28 bytes below the base pointer (`rbp`). That is our "high"-level `C` command `int i = 0;`.
    - `mov`: This is the mnemonic for the "move" instruction, which is used to transfer data from one location to another.
    - `DWORD PTR`: specifies the size of the data being moved. In this case, `DWORD PTR` stands for "Double Word Pointer", which typically refers to a 32-bit value. It means that we are working with a 32-bit (4-byte) data item.
    - `[rbp-0x1c]`: This is the destination memory address where the data will be stored. `[rbp-0x1c]` means that we are accessing memory at an offset of 0x1c bytes (28 bytes) below the base pointer (rbp). The base pointer (`rbp`) is often used as a frame pointer in function prologues to access local variables and parameters. Note that `[rbp-0x1c]` is the address of the integer variable `i`.
    - `0x0`: This is the immediate value being moved into the specified memory location. In this case, it's the value zero (0x0).
- `118b: lea    rax,[rbp-0x1c]`: Calculate the address of a memory location of `[rbp-0x1c]`. The result of this calculation is stored in the `rax` register.
    - `lea`: This is the mnemonic for the "load effective address" instruction, which is used to calculate an effective memory address and load it into a register.
    - `rax`: This specifies the destination register where the calculated address will be stored. In this case, the result will be placed in the `rax` register.
    - `[rbp-0x1c]`: This is the memory address calculation. It calculates the effective address by subtracting `0x1c` (28 in decimal) from the value in the base pointer (`rbp`). So, it computes the address that is 28 bytes below the value in `rbp`.
- `118f: mov    QWORD PTR [rbp-0x18],rax`: move the 64-bit value contained in the `rax` register into an 8-byte memory location located 24 bytes below the base pointer (`rbp`). In other words, it puts it on the [stack][2]. Note that the address of `px` is `[rbp-0x18]`, and its value is indeed the addres of the variable `i`, which is `[rbp-0x1c]`. The instruction `118b` and `118f` form the implementation of our "high"-level `C` command `int *pi = &i`.
    - `QWORD PTR`: This part specifies the size of the data being moved. `QWORD PTR` stands for "Quad Word Pointer," which typically refers to a 64-bit (8-byte) value. It means that we are working with an 8-byte data item.
- `1193: lea    rax,[rbp-0x1c]`: Does exactly the same as the instruction `1184`.
- `1197: mov    QWORD PTR [rbp-0x10],rax`: Does exactly the same as the instruction `118f`, but in the memory `[rbp-0x10]`. Note that `1193` and `1197` form our "high"-level `C` command `int &ri = i`.

As you can see, pointers and the refereces are initialized in the same way. The difference between a pointer and a reference occurs after they are initialzied. The compiler manipulates them differently, applying severeal protections/restriction on the reference, which prevent us from things such as doing math with it. On the other hand, for some tasks, such restrictions enable us to use references in a more straightforward way when compared to pointers. For example, modifying a variable value by reference is much more straightforward when compared to the same solution via pointers.

---

Good refs:

1. [you will never ask about pointers again after watching this video](https://www.youtube.com/watch?v=2ybLD6_2gKM&ab_channel=LowLevelLearning)
1. [so... what even is a "reference"?][2]
1. [you will never ask about pointer arithmetic after watching this video][3]
1. [wiki: Basic types table][4]
1. [Is the size of C "int" 2 bytes or 4 bytes?][5]

[2]: https://www.youtube.com/watch?v=wro8Bb6JnwU&ab_channel=LowLevelLearning
[3]: https://www.youtube.com/watch?v=q24-QTbKQS8&t=2s&ab_channel=LowLevelLearning
[4]: https://en.wikipedia.org/wiki/C_data_types#Basic_types
[5]: https://stackoverflow.com/a/11438838/13998346
[6]: https://en.wikipedia.org/wiki/Primitive_data_type
