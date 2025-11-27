#include "../lib/stdint.h"
#include "memory.h"
#include "console.h"
#include "keyboard.h"
#include "interrupt.h"

struct Global_Memory_Descriptor memory_management_struct = {{0},0};

void kernel_init() {
    console_init();

    interrupt_init();

    keyboard_init();

    print_str("Kernel initialized successfully.\n");
    print_str("This is LightNightOS.\n");

    printk("This test print: num=%d, hex=%x, str=%s\n", 123, 0xABC, "test");

	init_memory();

    print_str("\nKeyboard ready. Type here: ");
    
    vt_render_active();
    sti();

    while(1);
}