; Start of the data segment
_data segment
    ; Define two 16-bit variables, var1 and var2
    var1 dw 10 ; 
    var2 dw 30 ; 
    RES1 dw 0 ; Result variable
    RES2 dw 0 ; Result variable
    RES3 dw 0 ; Result variable
    RES4 dw 0 ; Result variable
    RES5 dw 0 ; Result variable
_data ends

; Start of the code segment
_code segment
assume cs:_code, ds:_data
_start:
    ; Load the data segment into ds
    mov ax, _data
    mov ds, ax

    ; Execute the following statements and store the result in the variable RES
    mov ax, var1
    add ax, var2
    and ax, 55h
    mov RES1, ax

    mov ax, var1
    add ax, var2
    or ax, var2
    mov RES2, ax

    mov ax, var1
    and ax, var2
    xor ax, 0E9h
    mov RES3, ax

    ; For operations that may exceed 16 bits, use dx:ax (32 bits)
    mov ax, var1
    or ax, 39E7h
    mov bx, var2
    xor bx, 9696h
    add ax, bx
    mov RES4, ax ; Store only the low word

    mov ax, var1
    mov bx, var2
    xor bx, 0B7AAh
    add ax, bx
    mov RES5, ax ; Store only the low word

    ; Compute the two’s complement for each of the RES items
    mov ax, RES1
    not ax
    add ax, 1
    mov RES1, ax

    ; Store the low word for each of the answer
    ; In this case, RES is already a low word

    ; End of the program
    mov ah, 4ch
    int 21h
_code ends

end _start
