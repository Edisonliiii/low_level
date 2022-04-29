# an example of the CMOV instructions
# find the largest integer in a series defined in the values array
# ebx register is used to hold the current largest integer found
.section .data
output:
    .asciz "The largest value is %d\n"
values:
    .int 105, 235, 61, 315, 134, 221, 53, 145, 117, 5
.section .text
.globl _start
_start:
    nop
    movl values, %ebx       # load the first element in ebx
    movl $1, %edi           # 
loop:
    movl values(, %edi, 4), %eax
    cmp %ebx, %eax
    cmova %eax, %ebx
    inc %edi
    cmp $10, %edi
    jne loop
    pushl %ebx
    pushl $output
    calll printf
    addl $8, %esp
    pushl $0
    call exit