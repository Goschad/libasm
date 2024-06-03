bits 64

extern ft_strlen
extern malloc

section .text
    global ft_strdup

ft_strdup:
    call ft_strlen
    inc rax
    push rdi
    mov rdi, rax
    call malloc WRT ..plt
    cmp rax, 0
    je _error
    pop rdi
    mov rdx, -1
    mov rbx, rax
    .loop:
        inc rdx
        cmp byte [rdi, rdx], 0
        je .done 
        mov al, byte [rdi + rdx]
        mov byte [rbx + rdx], al
        jmp .loop
    .done:
    mov byte [rbx + rdx], 0x0
    mov rax, rbx
    ret

_error:
    mov rax, 0
    ret