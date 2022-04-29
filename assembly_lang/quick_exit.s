.section .text
.globl _start
_start:
    xor %eax, %eax
    xor %ebx, %ebx
    movl $1, %eax
    movl $0, %ebx
    int $0x80