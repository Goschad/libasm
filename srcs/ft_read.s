bits 64

%define SYS_READ 0
%define _ERROR -1

extern __errno_location

section .text
    global ft_read

ft_read:
    mov rax, SYS_READ
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