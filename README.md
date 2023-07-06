# Shared and static libraries

Now, let's compile and use these files to create both a static and shared library.

1. Create a static library:
```
gcc -c mylib_static.cpp -o mylib_static.o
ar rcs libmylib_static.a mylib_static.o
```
1. Create a shared library:
```
gcc -shared -fPIC mylib_shared.cpp -o libmylib_shared.so
```
1. Compile and link the main program with the libraries. 
    - Using the static library:
    ```
    gcc main.cpp -L. -lmylib_static -o program_static
    ```
    - Using the shared library:
    ```
    gcc main.cpp -L. -lmylib_shared -o program_shared
    ```
1. Run the programs: `./program_static` and `./program_shared`