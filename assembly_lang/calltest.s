# an example of using the call instruction
.section .data
output:
    .asciz "This is section %d\n"
.section .text
.globl _start
_start:
    pushl $1
    pushl $output           //此处push进来的是一个指针
    call printf
    add $8, %esp
    call overhere
    pushl $3
    pushl $output
    call printf
    add $8, %esp
    pushl $0
    call exit
overhere:
    pushl %ebp
    movl %esp, %ebp
    pushl $2
    pushl $output
    call printf
    add $8, %esp
    movl %ebp, %esp
    popl %ebp
    ret