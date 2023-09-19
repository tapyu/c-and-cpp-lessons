# FAQ

### **"void foo(void)" vs. "void foo()"? (`C` and `C++`)**

```c
  void foo(void);
```
[That][1] is the correct way to say "no parameters" in `C`, and it also works in `C++`.

But:

```c
  void foo();
```
Means different things in `C` and `C++`! In `C` it means "could take any number of parameters of unknown types", and in `C++` it means the same as `foo(void)`, that is, no parameters are allowed.

Variable argument list functions are inherently un-typesafe and should be avoided where possible. Therefore, for the sake of unified approach, `void foo(void);` **should be used** for both `C` and `C++` whenever you want to declared a function which has no input arguments.

---

### **Object-like macro vs. constant variables (`C` and `C++`(?))**

[A][2] constant defined with the `const` qualifier, e.g.,
```c
const int maxAttempts = 3
```
is best thought of as an unmodifiable variable. It has all the properties of a variable: it has a type, it has a size, it has linkage, you can take its address. (The compiler might optimize away some of these properties if it can get away with it: for instance, constants whose address is never used may not get emitted into the executable image. But this is only by the grace of the as-if rule.) The only thing you can't do to a `const` datum is change its value. A constant defined with `enum` is a little different. It has a type and a size, but it doesn't have linkage, you can't take its address, and its type is unique. Both of these are processed during translation phase 7, so they can't be anything but an lvalue or rvalue. (I'm sorry about the jargon in the preceding sentence, but I would have to write several paragraphs otherwise.)

A macro, e.g.,
```c
#define PI 3.14159265359
```
has far fewer constraints: it can expand to any sequence of tokens, as long as the overall program remains a well-formed program. It doesn't have any of the properties of a variable. Applying `sizeof` or `&` to a macro may or may not do something useful, depending on what the macro expands to. Macros are sometimes defined to expand to numeric literals, and such macros are sometimes thought of as constants, but they're not: "the compiler proper" (that is, translation phase 7) sees them as numeric literals.

**It is generally considered good practice, nowadays, not to use a macro when a constant will do**. Macros don't obey the same scoping rules as all other identifiers, which can be confusing, and if you use a constant you give more information to translation phase 7 and thus also to the debugger. However, macros permit you to do things that cannot be done any other way, and if you need to do one of those things, you should not hesitate to use them. (Macros that are pulling their weight, in this sense, generally do not just expand to numeric literals, though I am not going to say never.)

---

### **`%f` vs. `%lf` (`C`)**
1. [For][3] `printf()` -> Arguments of type `float` are promoted to `double` so both `%f` and `%lf` are used for double.
1. For `scanf()` -> `%f` for float and `%lf` for double.

---

### **Why does the order of the `-l` option matter in the `gcc`/`g++` commands? (`C` and `C++`)**
[When][4] you add a library using the -l option, the linker does not unconditionally take all object files from the library. It only takes those object files that are currently needed, i.e. files that resolve some currently unresolved (pending) symbols. After that, the linker completely forgets about that library.

[1]: https://stackoverflow.com/questions/693788/is-it-better-to-use-c-void-arguments-void-foovoid-or-not-void-foo
[2]: https://stackoverflow.com/questions/6393776/what-is-the-difference-between-a-macro-and-a-const-in-c
[3]: https://stackoverflow.com/questions/25860850/what-is-the-difference-between-f-and-lf-in-c
[4]: https://stackoverflow.com/questions/11893996/why-does-the-order-of-l-option-in-gcc-matter/11894098#11894098
