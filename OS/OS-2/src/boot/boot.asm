[bits 16]

_start:
    ; 初始化所有段寄存器
    mov ax, 0
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00  ; 设置栈指针

read_disk:
    ; 读取参数设置
    mov bx, 0x7e00   ; 读取到的内容存放地址（es:bx）
    mov ah, 0x02     ; BIOS功能号：读磁盘
    mov al, 0x01     ; 读取扇区数量
    mov ch, 0x00     ; 磁道号（柱面号）
    mov cl, 0x02     ; 扇区号（从1开始）
    mov dh, 0x00     ; 磁头号
    mov dl, 0x80     ; 驱动器号（0x80表示第一块硬盘）
    
    int 0x13         ; 调用BIOS磁盘服务
    jc .retry        ; 如果出错则重试
    
    jmp 0x0000:0x7e00  ; 跳转到加载的程序执行

.retry:
    dec cx
    jnz read_disk    ; 限制重试次数
    
    ; 如果多次重试失败，可以在这里添加错误处理
    hlt
    jmp $

; 填充MBR到512字节，并添加结束标志
times 510 - ($ - $$) db 0
dw 0xaa55