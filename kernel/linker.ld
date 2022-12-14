ENTRY(_start);

SECTIONS {
    . = 0x100000;

    .text : {
        *(.multiboot)
        *(.text)
    }

    .rodata ALIGN(4096) : {
        *(.rodata)
    }

    .data ALIGN(4096) : {
        *(.data)
    }

    .bss ALIGN(4096) : {
        *(.bss)
    }
}
