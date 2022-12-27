.section .text

.macro isr no
.global isr_\no
isr_\no:
    cli
    push $0 // 对于没有错误码的异常，push一个0是为了统一栈帧
    push $\no
    jmp isr_commonHandler
.endm

.macro isr_error_code no
.global isr_\no
isr_\no:
    cli
    // 有错误码的isr就不需要手动push了，已经自动push进错误码了
    push $\no
    jmp isr_commonHandler
.endm

isr_commonHandler:
    pusha  // push edi, esi, ebp, esp, ebx, edx, ecx, eax
    push %ds
    push %es
    push %fs
    push %gs

    mov $0x10, %ax  // 0x10是数据段
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %gs
    mov %esp, %eax
    push %eax
    call interrupt_handler

    // 恢复现场的顺序和保存现场的顺序正好相反
    pop %eax
    pop %gs
    pop %fs
    pop %es
    pop %ds
    popa  // pop edi, esi, ebp, esp, ebx, edx, ecx, eax

    add $8, %esp  // 从堆栈中移除错误码和ISR号
    iret  // pop cs, eip, eflags, ss, esp

/* Exceptions */
isr 0
isr 1
isr 2
isr 3
isr 4
isr 5
isr 6
isr 7
isr_error_code 8
isr 9
isr_error_code 10
isr_error_code 11
isr_error_code 12
isr_error_code 13
isr_error_code 14
isr 15
isr 16
isr 17
isr 18
isr 19
isr 20
isr 21
isr 22
isr 23
isr 24
isr 25
isr 26
isr 27
isr 28
isr 29
isr 30
isr 31

/* IRQs */
isr 32
isr 33
isr 34
isr 35
isr 36
isr 37
isr 38
isr 39
isr 40
isr 41
isr 42
isr 43
isr 44
isr 45
isr 46
isr 47
