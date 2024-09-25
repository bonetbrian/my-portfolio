section.data
    prompt db 'Enter a string (max 50 chars): ', 0
    buffer db 51 ; reserve 51 bytes in memory for the string and null character

section.text
    global _start

_start:
    ; Display the prompt
    mov eax, 4 ; syscall number (sys_write)
    mov ebx, 1 ; file descriptor (stdout)
    mov ecx, prompt ; message to write
    mov edx, 24 ; message length
    int 0x80 ; call kernel

    ; Read the string
    mov eax, 3 ; syscall number (sys_read)
    mov ebx, 0 ; file descriptor (stdin)
    mov ecx, buffer ; buffer to read into
    mov edx, 50 ; number of bytes to read
    int 0x80 ; call kernel

    ; Display the string
    mov eax, 4 ; syscall number (sys_write)
    mov ebx, 1 ; file descriptor (stdout)
    mov ecx, buffer ; message to write
    mov edx, 50 ; message length
    int 0x80 ; call kernel

    ; Exit
    mov eax, 1 ; syscall number (sys_exit)
    xor ebx, ebx ; exit code
    int 0x80 ; call kernel

; End of the program
END _start
