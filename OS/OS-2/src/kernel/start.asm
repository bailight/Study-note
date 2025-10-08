 [bits 16]

 extern _kernel_init
 global _start

 _start:
    mov ax, 0x3
    int 0x10
    jmp _kernel_init