global _es_colision

section .text
_es_colision:
    mov cl, [esp + 4]  
    
    cmp cl, '#'        
    je .pared         
    mov eax, 0        
    ret
.pared:
    mov eax, 1         ; Retornamos 1 (colisión)
    ret