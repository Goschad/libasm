bits 64

%define SYS_READ 0
%define _ERROR -1

extern __errno_location

section .text
    global ft_read

ft_read:
    mov rax, SYS_READ
    syscall
    test rax, rax
    js _error
    ret

_error:
    call __errno_location WRT ..plt
    mov rax, _ERROR
    ret