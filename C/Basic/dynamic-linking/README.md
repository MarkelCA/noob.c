# dynamic-link
Step 1: Create the dynamic link:
```sh
# Compile the code into a position-independent object file: Use the -fPIC flag to create position-independent code, which is necessary for dynamic libraries.
gcc -c -fPIC example.c -o example.o
# Link the object file into a shared library: Use the -shared flag to create the shared library (.so file).
gcc -shared example.o -o libexample.so
```

Step 2: Run main using the dynamic library:
```bash
# Here, -L. tells the compiler to look in the current directory for libraries, and -lexample links against libexample.so.
gcc main.c -L. -lexample -o main
# LD_LIBRARY_PATH is used to tell the dynamic linker where to find libexample.so.
LD_LIBRARY_PATH=. ./main
```

Now try to the message in `example.c` and compile the library again. You should see the changes reflected in the output of `main` when you run it.
