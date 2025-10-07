[bits 16]

_start:
    mov ax, 0
    mov es, ax

read_disk:
    mov bx, 0x7e00
    mov cx, 0x02
    mov ax, 0x201
    mov dx, 0x80
    int 0x13
    jc read_disk
    xchg bx, bx
    xchg bx, bx
    jmp 0:0x7e00