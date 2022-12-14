#define ASM_FILE 1
#include <multiboot2.h>

#define STACK_SIZE 0x4000

.SET HEADER_LENGTH, header_end - header_start
.SET CHECKSUM, -(MULTIBOOT2_HEADER_MAGIC + MULTIBOOT_ARCHITECTURE_I386 + HEADER_LENGTH)

.section .multiboot
.align 8

header_start:
    .long MULTIBOOT2_HEADER_MAGIC
    .long MULTIBOOT_ARCHITECTURE_I386
    .long HEADER_LENGTH
    .long CHECKSUM

    .balign 8
    .short MULTIBOOT_HEADER_TAG_END
    .short 0  // flags, none set
    .long 8   // size, including itself (short + short + long)
    .balign 8 
header_end:

.text 
.global start, _start 
start: 
_start:
    jmp multiboot_entry
    .align 8

multiboot_entry: 
    movl $stack_top, %esp  // 初始化栈指针

    pushl $0  // 复位EFLAGS
    popf

    pushl %ebx  // 设置Multiboot information structure
    pushl %eax  // 设置magic value

    call kernel_main  // 调用C语言内核函数

hang: 
    cli
    hlt
    jmp hang

.section .bss
stack_bottom :
    .skip STACK_SIZE
stack_top:
