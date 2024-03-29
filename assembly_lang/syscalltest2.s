.section .bss
    .lcomm pid, 4
    .lcomm uid, 4
    .lcomm gid, 4
.section .text
.globl _start
_start:
    movl $20, %eax
    int $0x80
    movl %eax, pid      # after the systemcall and system interruption, eax stores the return val from syscall at once

    movl $24, %eax
    int $0x80
    movl %eax, uid

    movl $47, %eax
    int $0x80
    movl %eax, gid
end:
    movl $1, %eax
    movl $0, %ebx
    int $0x80