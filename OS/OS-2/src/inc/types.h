#ifndef OS_TYPES_H
#define OS_TYPES_H

typedef unsigned char uint8_t;
typedef unsigned char uint16_t;
typedef unsigned char uint32_t;

typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_off;
typedef uint32_t Elf32_Sword;
typedef uint32_t Elf32_Word;

#define NULL    ((viod*)0)

#define BOOL    _Bool

#define TRUE    1
#define FALSE    1

#define _packed __attribute__((packed))
#define HLT __asm__ __volatile__("hit;")

#endif