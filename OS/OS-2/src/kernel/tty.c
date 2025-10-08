// __asm__(".code16gcc");
// #include <x16/kernel.h>

// void show_string(char *str, uint8_t color)
// {
//     color = color & 0xFF;
//     for (char *p = str; *p != 0; p++){
//         char c = (*p & 0xFF) | 0x0E00;
//         __asm__ volatile("mov $0xE, %%ah\n"
//                     "mov %[c], %%al\n\t"
//                     "int $0x10\n"
//                 :: [c]"r"(c), "b"(color));
//     }
// }

__asm__(".code16gcc");
#include <x16/kernel.h>

void show_string(char *str, uint8_t color)
{
    color = color & 0xFF;
    for (char *p = str; *p != 0; p++){
        // 只取字符的低8位，去掉0x0E00（功能码通过ah设置）
        uint8_t c = *p & 0xFF;
        // 使用bl寄存器存储颜色（8位），与uint8_t匹配
        __asm__ volatile(
            "mov $0xE, %%ah\n"    // 功能码：显示字符
            "mov %[c], %%al\n"    // 字符值（8位）
            "mov %[color], %%bl\n" // 颜色值（8位，使用bl寄存器）
            "int $0x10\n"         // 调用BIOS中断
            :: [c]"r"(c), [color]"r"(color)
            : "ax", "bx"          // 声明被修改的寄存器
        );
    }
}