#include <gdt.h>
#include <log.h>
#include <stdint.h>  // uintX_t
#include <terminal.h>

// 内核入口函数
void kernel_main(uint32_t magic, uintptr_t multiboot) {
    (void)magic;
    (void)multiboot;

    terminal_init();
    printf("terminal initialized\n");
    gdt_init();
    printf("gdt initialized\n");
}
