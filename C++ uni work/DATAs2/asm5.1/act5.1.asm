.model small
.stack 100h

.data
myVar DB 0FFh 
.code
_main PROC
    mov al, myVar 
    cmp al, 0FFh 

    je equal ; If equal (ZF=1), jump to equal
    jmp notequal ; If not equal (ZF=0), jump to notequal

equal:
   
    lea dx, equalMsg
    mov ah, 09h
    int 21h
    jmp _exit ; Jump to exit

notequal:
    
    lea dx, notEqualMsg
    mov ah, 09h
    int 21h

_exit:
    mov ah, 4Ch
    int 21h
_main ENDP
END _main
