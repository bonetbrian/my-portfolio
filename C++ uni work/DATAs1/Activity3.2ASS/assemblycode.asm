.MODEL flat, stdcall

.data
val1 QWORD 10000h
val2 QWORD 40000h
val3 QWORD 20000h
finalVal QWORD ?

.code
main PROC
    mov rax, val1       ; start with 10000h
    add rax, val2       ; add 40000h
    sub rax, val3       ; subtract 20000h
    mov finalVal, rax   ; store the result (30000h)
    ; You can add additional instructions here if needed
    ret                  ; Return from the main procedure
main ENDP

END main
