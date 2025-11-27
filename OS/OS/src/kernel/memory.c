#include "memory.h"
#include "console.h"
#include "../lib/stdint.h"
#include "lib.h"

void init_memory() {
	printk_color(BLUE, BLACK, "=== Memory Initialization Start ===\n");
	init_memory_map();
    init_zones_and_pages();
    setup_kernel_mapping();
	printk_color(BLUE, BLACK, "=== Memory Initialization Complete ===\n");
}

void init_memory_map(){
	int i;
	unsigned long TotalMem = 0 ;
	struct E820 *p = NULL;
	memory_management_struct.e820_length = 0;
	
	p = (struct E820 *)0xffff800000005000;

	for(i = 0;i < 32;i++){
		printk_color(ORANGE,BLACK,"Address:%#018lx\tLength:%#018lx\tType:%#010x\n",p->address,p->length,p->type);
		if(p->type == 1){
			TotalMem +=  p->length;
		}

		memory_management_struct.e820[i].address += p->address;
		memory_management_struct.e820[i].length += p->length;
		memory_management_struct.e820[i].type += p->type;
		memory_management_struct.e820_length = i + 1;

		p++;
		if(p->type > 4 || p->length == 0 || p->type < 1){
			break;
		}	
	}

	printk_color(ORANGE,BLACK, "OS Can Used Total RAM:%#018lx=%018d\n", TotalMem, TotalMem);

	TotalMem = 0;

	for(i = 0;i <= memory_management_struct.e820_length;i++)
	{
		unsigned long start,end;
		if(memory_management_struct.e820[i].type != 1)
			continue;
		start = PAGE_2M_ALIGN(memory_management_struct.e820[i].address);
		end   = ((memory_management_struct.e820[i].address + memory_management_struct.e820[i].length) >> PAGE_2M_SHIFT) << PAGE_2M_SHIFT;
		if(end <= start)
			continue;
		TotalMem += (end - start) >> PAGE_2M_SHIFT;
	}
	
	printk_color(YELLOW,BLACK,"OS Can Used Total PAGEs:%#010x=%010d\n",TotalMem,TotalMem);    
}


void init_zones_and_pages(){
    
}

void setup_kernel_mapping(){

}