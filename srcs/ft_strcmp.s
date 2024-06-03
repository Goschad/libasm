bits 64

section .text
    global ft_strcmp

ft_strcmp:
    .loop:
        mov al, [rdi]
        mov bl, [rsi]
        cmp al, bl
        jne .done
        inc rsi
        inc rdi
        test al, al
        jz .done 
        jmp .loop
    .done:
    sub al, bl
    movsx rax, al
    ret