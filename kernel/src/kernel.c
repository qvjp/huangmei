#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <log.h>
#include <stdint.h>  // uintX_t
#include <terminal.h>

// 内核入口函数
_Noreturn void kernel_main(uint32_t magic, uintptr_t multiboot) {
    (void)magic;
    (void)multiboot;

    terminal_init();
    printf("terminal initialized\n");
    gdt_init();
    printf("gdt initialized\n");
    idt_init();
    isr_init();
    interrupt_enable();
    printf("interrupt initialized\n");

    while (1) {
    }
}
