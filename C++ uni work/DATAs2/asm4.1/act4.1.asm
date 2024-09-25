.model small
.stack 100h

.data
var1 SBYTE -4,-2,3,1
var2 WORD 1000h,2000h,3000h,4000h
var3 SWORD -16,-32
var4 DWORD 1,2,3,4,5
result DWORD ?

.code
main PROC
    mov ax, @data
    mov ds, ax

    ; a. mov ax, var1
    mov al, var1      ; Valid. var1 is an SBYTE and al is 1 byte.
    mov result, ax    ; Store the result for display
    call DisplayResult

    ; b. mov ax, var2
    mov ax, var2      ; Valid. var2 is a WORD and ax is a 16-bit register.
    mov result, ax    ; Store the result for display
    call DisplayResult

    ; c. mov eax, var3
    mov ax, var3      ; Invalid. var3 is an SWORD, which is 2 bytes, but eax is a 32-bit register.
    mov result, eax   ; Store the result for display
    call DisplayResult

    ; d. mov var2, var3
    mov ax, var3
    mov var2, ax      ; Invalid. Direct memory-to-memory transfer is not allowed.
    mov result, ax    ; Store the result for display
    call DisplayResult

    ; e. xchg var1, var2
    xchg ax, var2     ; Invalid. xchg exchanges the contents of the operands. Here, var1 is an SBYTE and var2 is a WORD, which are not the same size.
    mov result, ax    ; Store the result for display
    call DisplayResult

    ; f. movzx ax, var2
    movzx eax, var2   ; Invalid. movzx is used to zero-extend while moving data. Here, var2 is a WORD, which is larger than ax.
    mov result, eax   ; Store the result for display
    call DisplayResult

    ; g. movzx var2, ax
    mov ax, var2
    movzx var2, ax    ; Invalid. movzx cannot move data from a register to memory.
    mov result, ax    ; Store the result for display
    call DisplayResult

    ; h. mov ds, ax
    mov ds, ax        ; Valid. ds is a segment register and ax is a general-purpose register.
    mov result, ax    ; Store the result for display
    call DisplayResult

    ; i. mov ds, 1000h
    mov ax, 1000h
    mov ds, ax        ; Invalid. Immediate-to-segment register move is not allowed.
    mov result, ax    ; Store the result for display
    call DisplayResult

    ; Exit the program
    mov ah, 4Ch       ; DOS function: Exit program
    int 21h           ; Call DOS

main ENDP

DisplayResult PROC
    ; Display result
    mov ah, 02h       ; DOS function: Display character
    mov dl, result    ; Display the result
    add dl, '0'       ; Convert result to ASCII
    int 21h           ; Call DOS
    mov dl, ','       ; Display comma for separation
    int 21h           ; Call DOS
    ret
DisplayResult ENDP

END main
