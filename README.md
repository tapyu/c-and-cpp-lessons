# Pointers

## **What are pointers?**

In `C` and `C++`, pointers are variables that store memory addresses as their values. They are a fundamental concept in both languages and are used extensively for tasks like dynamic memory allocation, working with arrays, and passing data by reference. 

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
    <td>This syntax is used to initialize the pointer variable. This is the unique situation that $\color{red}*$ reads $\color{red}pointer$. In all others, $\color{red}*$ will denote the dereference process. By "integer pointer", we mean that this pointer points to an address whose stored value is an integer. The syntax <code>int* px = &x;</code> can also be used as an alternative to <code>int *px = &x;</code>. Although both are commonly adopted, I prefer the latter <a href="https://stackoverflow.com/questions/14536658/pointer-syntax-in-c">because</a> <code>int* a, b;</code> produces an integer <code>a</code> and a pointer integer <code>b</code>, even though it wrongly seems that both <code>a</code> and <code>b</code> are integer pointers.</td>
</tr>
<tr>
    <td>${\color{blue}int \space \color{red}* \color{violet}parr \space \color{green}= \space \color{cyan}arr}$</td>
    <td>${\color{blue}Integer \space \color{red}pointer \space \color{violet}named \space parr \space \color{green}is \space set \space to}$
        ${\color{cyan}the \space address \space of \space the \space first \space element \space in}$ ${\color{cyan} the \space integer \space array \space arr}$.</td>
    <td>When you use the array name in this context, it implicitly decays into the address of the first element of that array. In other words, <code>arr</code> represents the address of the first element <code>arr[0]</code>. In the context of <code>C</code> and <code>C++</code>, the term "<b>array decay</b>" refers to the automatic conversion of an array to the address of its first element (see <code>./pointer-arithmetic/main1.c</code>). This conversion happens implicitly in many expressions involving arrays. This syntax is equivalent to <code>int *parr = &arr[0]</code>, but it is much more concise and therefore more adopted.  It also works for a string as it is represented as a <code>char</code> array in <code>C</code> (see <code>./pointer-arithmetic/main1.c</code>).</td>
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
     <td>${\color{red}p->age \space \color{green}= \space \color{cyan}5}$</td>
    <td>${\color{red}The \space stored \space value \space of \space the \space struct's}$
        ${\color{red}feild \space age \space that \space p \space points \space to \space \color{green}is \space set \space to \space \color{cyan}5}.$</td>
    <td>In this case, the pointer <code>p</code> is a structure pointer, e.g., <code>struct Person *p = &mike</code>. Note that the syntax <code>p->age</code> <a href="https://stackoverflow.com/questions/2575048/arrow-operator-usage-in-c/2575050#2575050">is equivalent to</a> <code>(*p).age</code></td>
</tr>
</table>

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

#### **What is pointer arithmetic?**

Pointer arithmetic is a fundamental concept in programming languages like `C` and `C++`, which allows you to perform arithmetic operations on pointers. Specifically, it involves adding or subtracting integers to/from pointers to manipulate memory addresses (see `./pointer-arithmetic/` examples).

- *Adding an Integer to a Pointer*: When you add an integer value to a pointer, you are effectively moving the pointer to point to a memory location that is offset by a certain number of bytes. The size of the offset depends on the data type that the pointer points to. For example (you could use `ptr++;` instead of `ptr = ptr + 1;`):
```c
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr; // ptr points to the first element (10)
    ptr = ptr + 1; // Move ptr to the next integer (20)
```
In this example, adding 1 to the pointer ptr moves it to the next integer in the array.
- *Subtracting an Integer from a Pointer*: You can also subtract an integer from a pointer, which has the opposite effect of moving the pointer backward in memory. Again, the size of the offset depends on the data type. For example (you could use `ptr--;` instead of `ptr = ptr - 1;`):
```c
    int arr[] = {10, 20, 30, 40};
    int *ptr = &arr[2]; // ptr points to the third element (30)
    ptr = ptr - 1; // Move ptr to the previous integer (20)
```

## Memory size of variables (in bytes)

*The memory size of common data types in C can vary depending on the compiler and the target system's architecture*. However, there are standard data types with specified **minimum size** requirements in the `C` language standard. The sizes of unsigned types are typically the same as their signed counterparts on most systems and compilers (e.g., `unsigned int` typically uses at least 2 bytes, just like `int`). See `./memory-size-variables/main.c`.

<table>
<tr>
    <th colspan="3"><h2>Minimum memory size of variables</h2></th>
</tr>
<tr>
    <th>Variable type</th>
    <th>Bytes (a byte contains 8 bits)</th>
    <th>Comments</th>
</tr>
<tr>
    <td><code>char</code></td>
    <td>Tipically 1 byte (8 bits)</td>
    <td></td>
</tr>
<tr>
    <td><code>int</code></td>
    <td>At least 2 byte (16 bits)</td>
    <td></td>
</tr>
<tr>
    <td><code>short</code></td>
    <td>2 byte (16 bits)</td>
    <td>An integer variant designed to have a smaller range of values compared to <code>int</code>. It typically has a minimum range of -32,767 to 32,767 for a signed short (16 bits), but the exact range can vary depending on the system and compiler.</td>
</tr>
<tr>
    <td><code>long</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td>The <code>long</code> data type in <code>C</code> is used to represent integers just like <code>int</code> and <code>short</code>, but it typically has a larger range and requires more memory compared to <code>int</code>.</td>
</tr>
<tr>
    <td><code>long long</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td>The <code>long long</code> data type in C is used to represent integers with an even larger range than <code>long</code>. It's typically <code>64</code> bits in size on most modern systems, allowing it to hold very large integer values. The long long data type was introduced in the C99 (ISO/IEC 9899:1999) standard.</td>
</tr>
<tr>
    <td><code>float</code></td>
    <td>At least 4 bytes (32 bits).</td>
    <td></td>
</tr>
<tr>
    <td><code>double</code></td>
    <td>At least 8 bytes (64 bits).</td>
    <td>Also known as "Double-precision floating-point number".</td>
</tr>
<tr>
    <td><code>long double</code></td>
    <td>At least 10 bytes (80 bits) on some systems.</td>
    <td></td>
</tr>
<tr>
    <td><code>size_t</code></td>
    <td>On 32-bit systems, <code>size_t</code> is typically 32 bits (4 bytes), while on 64-bit systems, it is typically 64 bits (8 bytes).</td>
    <td>It is an unsigned integer type that is used for representing the sizes of objects in memory.  The size_t type is guaranteed to be able to represent the size of the largest object that can exist in the memory of the system.</td>
</tr>
<tr>
    <th colspan="3"><h3><code>C++</code>-only data types</h3></th>
</tr>
<tr>
    <th>Variable type</th>
    <th>Bytes (a byte contains 8 bits)</th>
    <th>Comments</th>
</tr>
<tr>
    <td><code>bool</code></td>
    <td>Typically 1 byte (8 bits), representing <code>true</code> or <code>false</code>.</td>
    <td></td>
</tr>
<tr>
    <td>User-defined types</td>
    <td>Classes and structures in C++ can have variable sizes based on their member variables and alignment requirements.</td>
    <td></td>
</tr>
</table>


---

# References


#### **What are references?**

In `C++` (and some other programming languages, but not in `C`), a reference is a mechanism that allows you to create an alias or an alternative name for an existing variable (see `./refs-vs-pointers/`).

#### **References vs. Pointers**

In `C`, which has no references, you primarily work with pointers to achieve similar functionality to what references provide in `C++`. In other words, there is an overlap in the functionalities provided by them. Certain things can be done by using either pointer or references (see `./pointers-refs-comparison/`). However, there are fundamental differences beween both:
1. References cannot be `NULL` (e.g., you cannot write `int &ref = NULL;`);
1. You cannot change the variable e.g. referenced by a reference. Once a reference is *associated* to a variable, it is that way forever (e.g., if `int $ref = i;`, you cannot also write `int $ref = another_i;`);
1. You cannot do math on references (e.g., you cannot write `int &a = i + 1;`) as you can do on pointers (e.g., you can write `int *pi = &i + 1`). See `./pointer-arithmetic/main2.c`;
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

---

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

---

Good refs:

1. [you will never ask about pointers again after watching this video](https://www.youtube.com/watch?v=2ybLD6_2gKM&ab_channel=LowLevelLearning)
1. [so... what even is a "reference"?][2]

[2]: https://www.youtube.com/watch?v=wro8Bb6JnwU&ab_channel=LowLevelLearning
