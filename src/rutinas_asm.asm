global contar_caracteres
global validar_movimiento
global calcular_puntaje
global detectar_objeto
global contar_celdas_libres

section .text

contar_caracteres:
    xor rax, rax
    xor r10, r10
.bucle_cc:
    cmp r10, rdx
    jge .fin_cc
    mov r11b, [rcx + r10]
    cmp r11b, r8b
    jne .sig_cc
    inc rax
.sig_cc:
    inc r10
    jmp .bucle_cc
.fin_cc:
    ret

validar_movimiento:
    mov rax, r8
    imul rax, rdx
    add rax, r9
    mov r10b, [rcx + rax]
    cmp r10b, 35
    je .bloqueado
    mov rax, 1
    ret
.bloqueado:
    mov rax, 0
    ret

calcular_puntaje:
    mov rax, rcx
    imul rax, 100
    imul rdx, 2
    sub rax, rdx
    imul r8, 500
    add rax, r8
    cmp rax, 0
    jge .fin_cp
    xor rax, rax
.fin_cp:
    ret

detectar_objeto:
    mov rax, r8
    imul rax, rdx
    add rax, r9

    mov r10b, [rcx + rax]

    ; obtener el 5to parámetro (objeto buscado)
    mov r11, [rsp + 40]

    cmp r10b, r11b
    je .encontrado

    mov rax, 0
    ret

.encontrado:
    mov rax, 1
    ret

contar_celdas_libres:
    xor rax, rax
    xor r10, r10
.bucle_cl:
    cmp r10, rdx
    jge .fin_cl
    mov r11b, [rcx + r10]
    cmp r11b, 46
    jne .sig_cl
    inc rax
.sig_cl:
    inc r10
    jmp .bucle_cl
.fin_cl:
    ret