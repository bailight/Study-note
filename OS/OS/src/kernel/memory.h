#ifndef MEMORY_H
#define MEMORY_H

#include "../lib/stdint.h"

struct E820{
	unsigned long address;
	unsigned long length;
	unsigned int	type;
}__attribute__((packed));

struct Global_Memory_Descriptor
{
	struct E820 	e820[32];
	unsigned long 	e820_length;	
};

extern struct Global_Memory_Descriptor memory_management_struct;

void init_memory();

#endif