set(CMAKE_C_FLAGS "-O0 -g -ffreestanding -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld -ffreestanding -nostdlib")

ENABLE_LANGUAGE(ASM)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES
    src/arch/i686/gdt.S
    src/arch/i686/idt.S
    src/arch/i686/interrupt.S
    src/arch/i686/start.S
    src/arch/i686/gdt.c
    src/arch/i686/idt.c
    src/arch/i686/irq.c
    src/arch/i686/isr.c
    src/kernel.c
    src/log.c
    src/terminal.c
    )

add_executable(kernel.elf ${SOURCE_FILES})
