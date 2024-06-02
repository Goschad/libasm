bits 64

%define SYS_WRITE 1
%define _ERROR -1

section .text
    global ft_write

ft_write:
    mov rax, SYS_WRITE      ; set write syscall
    syscall         ; call write
    test rax, rax   ; check if rax is null or neg
    js _error       ; jump to _error if rax is neg
    ret             ; return

_error:
    mov rax, _ERROR     ; set return value to -1
    ret             ; return