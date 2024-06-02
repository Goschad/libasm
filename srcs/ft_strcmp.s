bits 64

%define _ERROR -1

section .text
    global ft_strcmp

ft_strcmp:
    .loop:      
        mov al, [rsi]
        mov bl, [rdi]
        cmp al, bl
        jne _is_false
        inc rsi
        inc rdi
        cmp byte [rsi], 0
        je .done
        jmp .loop
    .done:  
    mov rax, 0
    ret

_is_false:
    mov rax, _ERROR
    ret