bits 64

section .text
    global ft_strcpy

ft_strcpy:
    push rdi
    .copy:
        mov al, byte [rsi]
        mov byte [rdi], al
        test al, al
        je .done
        inc rsi
        inc rdi
        jnz .copy
    .done:
    pop rdi
    mov rax, rdi
    ret