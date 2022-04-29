# example of passing input values to a system call
.section .data              // 这个区段里地址都是连续的
output:
    .ascii "This is a test message.\n"
output_end:
    .equ len, output_end - output
.section .text

.globl _start
_start:
    movl $4, %eax        # load write system call into the eax register   
    
    movl $1, %ebx        # first arg to write  (file descriptor) -- here, STDOUT
    movl $output, %ecx   # second arg to write    -- str to display
    movl $len, %edx      # third arg to write
    int $0x80            # system interrupt

    movl $1, %eax        # load exit syscall into eax reigster
    movl $0, %ebx        # load exit code into ebx register (use echo $? to check)
    int $0x80            # system interrupt
