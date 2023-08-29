	section .data
    hello db "Hello World!",0

section .text
    global _start

_start:
    ; sys_write(int fd, const void *buf, size_t count)
    mov rax, 1         ; syscall number for sys_write
    mov rdi, 1         ; file descriptor 1 (stdout)
    lea rsi, [hello]   ; address of the hello string
    mov rdx, 13        ; length of the string
    syscall

    ; sys_exit(int status)
    mov rax, 60        ; syscall number for sys_exit
    xor rdi, rdi       ; exit status 0
    syscall

