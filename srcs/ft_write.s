bits 64

%define SYS_WRITE 1
%define _ERROR -1

extern __errno_location

section .text
    global ft_write

ft_write:
    mov rax, SYS_WRITE
    syscall
    cmp rax, 0
    jl _error
    ret

_error:
    neg rax
    mov rdi, rax
    call __errno_location WRT ..plt
    mov [rax], rdi
    mov rax, _ERROR
    ret