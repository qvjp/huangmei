.section .text
.align 4

// 加载gdt
.global gdt_load
.type gdt_load, @function
gdt_load:
    mov 4(%esp), %eax
    lgdt (%eax)

    // 段选择子的低三位为权限/标志位，从第四位开始才是index，
    // 所以这里0x10表示GDT中index为2的项，也就是数据段。
    // 然后刷新各个寄存器
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss


    // 其他段寄存器可以直接通过mov来改变，但是代码段寄存器（cs）需要用jmp来加载此段（0x8是代码段偏移量1）
    // 这里用ljmp直接跳到下一条指令并同时设置了cs寄存器
    ljmp $0x08, $load
load:
    ret
