bits 64

section .text
    global ft_strlen

ft_strlen:
    mov rax, 0                  ; init rax to 0
    .loop:                      ; start loop
        cmp byte [rdi, rax], 0  ; condition if rdi with rax index (rdi[rax]) 
        je .done                ; end of 
        inc rax                 ; rax++
        jmp .loop               ; return in top of the loop
    .done:                      ; end of loop
    ret                         ; return rax supposed value