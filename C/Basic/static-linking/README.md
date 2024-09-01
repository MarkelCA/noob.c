# static-linking
Trying to use custom statically linked libs using this resource: https://www.geeksforgeeks.org/static-vs-dynamic-libraries/

Compile the library:
```bash
# Compile the library:
gcc -c lib_mylib.c -o lib_mylib.o
# Create static library.
ar rcs lib_mylib.a lib_mylib.o 
```

# Use the library:
```bash
# Compile the main program:
gcc -c driver.c -o driver.o
# Link the compiled driver program to the static library
gcc -o driver driver.o -L. lib_mylib.a
# Run the program
./driver
```
