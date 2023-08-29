```bash
nasm -f elf64 hello.asm -o hello.o # Get the object file
ld ./hello.o -o hello # Link the object file to an executable
```
