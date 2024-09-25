section .data
.code
 

 section.text
 global _start

 _start:
 myVariable db 0xFF  ;Define an 8-bit variable with inital value 0xff
  mov al, byte[myVariable] ; Move the value of myVariable into AL register
  cmp al, 0xFF			
  je equal
  jmp not_equal


  equal:
  ;Code for when the value equals 0xFF
  ;You can printe a message here or preform any other action
  ; For example

  mov eax, 4
  mov ebx, 1
  mov ecx, msg_equal
  mov edx, msg_len
  int 0x80

  not_equal:

  mov eax, 4
  mov ebx, 1
  mov ecx, msg_not_equal
  mov edx, msg_len
  int 0x80

  mov eax,1
  xor ebx, ebx
  int 0x80

  section .data