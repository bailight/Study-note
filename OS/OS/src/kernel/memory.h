#ifndef MEMORY_H
#define MEMORY_H

#include "../lib/stdint.h"

#define PAGE_2M_SHIFT   21
#define PAGE_2M_SIZE    (1UL << PAGE_2M_SHIFT)
#define PAGE_2M_MASK    (~(PAGE_2M_SIZE - 1))
#define PAGE_2M_ALIGN(addr) (((addr) + PAGE_2M_SIZE - 1) & PAGE_2M_MASK)

#define PAGE_4K_SHIFT   12
#define PAGE_4K_SIZE    (1UL << PAGE_4K_SHIFT)  
#define PAGE_4K_MASK    (~(PAGE_4K_SIZE - 1))

struct E820{
	unsigned long address;
	unsigned long length;
	unsigned int	type;
}__attribute__((packed));

struct Global_Memory_Descriptor {
    volatile struct E820 e820[32];
    volatile unsigned long e820_length;

	unsigned long * bits_map;
	volatile unsigned long 	bits_size;
	volatile unsigned long   bits_length;

	struct Page *	pages_struct;
	volatile unsigned long	pages_size;
	volatile unsigned long 	pages_length;

	struct Zone * 	zones_struct;
	volatile unsigned long	zones_size;
	volatile unsigned long 	zones_length;

	unsigned long 	start_code , end_code , end_data , end_brk;

	unsigned long	end_of_struct;
};

struct Page
{
	struct Zone *	zone_struct;
	volatile unsigned long	PHY_address;
	volatile unsigned long	attribute;

	volatile unsigned long	reference_count;
	
	volatile unsigned long	age;
};

struct Zone
{
	struct Page * 	pages_group;
	volatile unsigned long	pages_length;
	
	volatile unsigned long	zone_start_address;
	volatile unsigned long	zone_end_address;
	volatile unsigned long	zone_length;
	volatile unsigned long	attribute;

	struct Global_Memory_Descriptor * GMD_struct;

	volatile unsigned long	page_using_count;
	volatile unsigned long	page_free_count;

	volatile unsigned long	total_pages_link;
};

extern struct Global_Memory_Descriptor memory_management_struct;

void init_memory(void);
void init_memory_map(void);
void init_zones_and_pages(void);
void setup_kernel_mapping(void);


#endif