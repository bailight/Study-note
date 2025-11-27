#include "memory.h"
#include "console.h"
#include "../lib/stdint.h"
#include "lib.h"

void init_memory() {
	int i;
	unsigned long TotalMem = 0 ;
	struct E820 *p = NULL;
	memory_management_struct.e820_length = 0;
	
	printk_color(BLUE, BLACK, "Display Physics Address MAP \n");
	p = (struct E820 *)0xffff800000007e00;

	for(i = 0;i < 32;i++){
		printk_color(ORANGE,BLACK,"Address:%#018lx\tLength:%#018lx\tType:%#010x\n",p->address,p->length,p->type);
		unsigned long tmp = 0;
		if(p->type == 1){
			TotalMem +=  p->length;
		}

		// memory_management_struct.e820[i].address = p->address;
        // memory_management_struct.e820[i].length  = p->length;
        // memory_management_struct.e820[i].type    = p->type;

        memory_management_struct.e820_length = i + 1;
		printk_color(RED,BLACK, "%d\n",memory_management_struct.e820_length);

		p++;

		if(p->type > 4 || p->length == 0 || p->type < 1){
			break;
		}	
	}

	printk_color(ORANGE,BLACK, "OS Can Used Total RAM:%#018lx\n",TotalMem);
}