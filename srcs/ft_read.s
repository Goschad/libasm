bits 64

%define SYS_READ 0
%define _ERROR -1

section .text
    global ft_read

ft_read:
    mov rax, SYS_READ
    syscall
    test rax, rax
    js _error
    ret

_error:
    mov rax, _ERROR
    ret