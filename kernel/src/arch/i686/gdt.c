#include <gdt.h>

static gdt_entry_t gdt_entries[] = {
    GDT_ENTRY(0, 0, 0, 0),
    GDT_ENTRY(0, 0xFFFFFFFF, GDT_ACCESS_KERNEL_CODE, GDT_FLAGS),
    GDT_ENTRY(0, 0xFFFFFFFF, GDT_ACCESS_KERNEL_DATA, GDT_FLAGS),
};

static gdt_descriptor_t gdt_descriptor;

void gdt_init() {
    gdt_descriptor.offset = &gdt_entries;
    gdt_descriptor.size = (sizeof(gdt_entries) - 1);

    gdt_load(&gdt_descriptor);
}
