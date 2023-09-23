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

## Memory size (in bytes)

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

In `C++` (and some other programming languages, but not in `C`), a reference is a mechanism that allows you to create an alias or an alternative name for an existing variable (see `./example4/`).

#### **References vs. Pointers**

In `C`, which has no references, you primarily work with pointers to achieve similar functionality to what references provide in `C++`. In other words, there is an overlap in the functionalities provided by them. Certain things can be done by using either pointer or references (see `./pointers-refs-comparison/`). However, there are fundamental differences beween both:
1. References cannot be `NULL` (e.g., you cannot write `int &ref = NULL;`);
1. You cannot change the variable e.g. referenced by a reference. Once a reference is *associated* to a variable, it is that way forever (e.g., if `int $ref = i;`, you cannot also write `int $ref = another_i;`);
1. You cannot do math on references (e.g., you cannot write `int &a = i + 1;`) as you can do on pointers (e.g., you can write `int *px = &x + 1`). See `./pointer-arithmetic/main2.c`;
1. While you can have pointer to pointer (e.g., if `int *px = &x;` you can write `int **ppx = &px;`), you cannot have references to references (e.g., if `int &rx = x;`, you cannot write `int &&rrx = rx`). See `./pointers-to-pointers/`.


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
