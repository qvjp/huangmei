#include <idt.h>

static idt_entry_t idt_entries[256];
static idt_descriptor_t idt_descriptor;

void idt_init() {
    idt_descriptor.offset = &idt_entries;
    idt_descriptor.size = sizeof(idt_entries) - 1;

    idt_load(&idt_descriptor);
}

void idt_set_entry(uint8_t num, uint32_t offset, uint16_t selector, uint8_t attr) {
    idt_entries[num].offset_low = offset & 0xFFFF;
    idt_entries[num].offset_high = offset >> 16;
    idt_entries[num].selector = selector;
    idt_entries[num].unused = 0;
    idt_entries[num].attr = attr;
}
