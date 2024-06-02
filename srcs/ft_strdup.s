bits 64

extern ft_strcpy
extern ft_strlen

section .text
    global ft_strdup

ft_strdup:
    mov rax, 9
    mov rdi, 5
    syscall
    ret