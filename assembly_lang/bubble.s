.section .data
values:
    .int 105, 235, 61, 315, 134, 221, 53, 145, 117, 5
.section .text
.globl _start
_start:
    movl $values, %esi
    movl %9, %ecx
    movl %9, %ebx
    