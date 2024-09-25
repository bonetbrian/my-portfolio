.386
.model flat, stdcall

.data
    operand1 dd 5       ; First operand (change value as needed)
    operand2 dd 3       ; Second operand (change value as needed)
    result   dd 0       ; Result variable

.code
_start:
    ; Initialize registers
    mov esi, operand1       ; Load first operand into esi
    mov ecx, operand2       ; Load second operand into ecx
    xor eax, eax            ; Clear eax (will store the result)
    
multiply_loop:
    test ecx, ecx           ; Check if second operand is zero
    jz multiplication_done  ; If it's zero, multiplication is done
    
    test cl, 1              ; Check if the least significant bit of ecx is set
    jnz add_operand1_to_result ; If set, add operand1 to the result
    
shift_and_dec_second_operand:
    shl esi, 1              ; Shift operand1 left by 1 (equivalent to multiplying by 2)
    shr ecx, 1              ; Shift operand2 right by 1 (equivalent to dividing by 2)
    jmp multiply_loop       ; Continue the loop
    
add_operand1_to_result:
    add eax, esi            ; Add operand1 to the result (eax)
    jmp shift_and_dec_second_operand  ; Continue the loop

multiplication_done:
    ; Store the result in the result variable
    mov [result], eax

    ; End of program
    mov eax, 1              ; Exit syscall number
    xor ebx, ebx            ; Exit code 0
    int 80                ; Execute syscall
  
  END _start