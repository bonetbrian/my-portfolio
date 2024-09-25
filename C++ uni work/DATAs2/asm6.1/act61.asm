.386
.model flat, stdcall
.stack 4096

include irvine32.inc

.data
prompt1 db "Enter the first number: ", 0
prompt2 db "Enter the second number: ", 0
gcd_msg db "The Greatest Common Divisor (GCD) is ", 0
.data?
num1 dd ? 
num2 dd ?
gcd_result dd ?
.code

main PROC
call CLrscr

mov edx, OFFSET prompt1
call WriteString

call ReadInt
mov num1, eax

mov edx, OFFSET prompt2
call WriteString

call ReadINt
mov num2, eax

mov eax, num1
mov ebx, num2
call findGCD

movesx, OFFSET gcd_msg
call WriteString
mov eax, gcd_result
call WriteDec
exit

main ENDP

findGCD PROC
	gcd_loop:
		cmp eax, ebx
		jl swap_numbers
		sub eax, ebx
		jmp check_zero
	swap_numbers:
		xchg eax, ebx
	check_zero:
		cmp eax, 0
		jnz gcd_loop
		mov gcd_result, ebx
	ret
findGCD ENDP

END main
