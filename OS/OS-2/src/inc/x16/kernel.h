__asm__(".code16gcc");
#include <types.h>
#ifndef OS_X16_KERNEL_H
#define OS_X16_KERNEL_H


#define BMB __asm__ volatile("xchgw %bx, %bx")

#define MEMORY_MAX_COUNT    24


typedef struct memory_raw_t
{
    uint32_t base_l;
    uint32_t base_h;
    uint32_t length_l;
    uint32_t length_h;
    uint32_t type;
} memory_raw_t;

typedef struct memory_info_t
{
    memory_raw_t raws[MEMORY_MAX_COUNT];
    uint32_t count;

}memory_info_t;

extern memory_info_t memery_info;

void memory_check();

void show_string(char *str, uint8_t color);

memory_info_t *get_memory_info();

#endif