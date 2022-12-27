#include <idt.h>
#include <irq.h>
#include <isr.h>
#include <log.h>

static handler_t isr_handlers[256];

static char *exception_msgs[] = {
    "Division By Zero",
    "Debugger",
    "Non-Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Bounds Range Exceeded",
    "Invalid Opcode",
    "Coprocessor Not Available",
    "Double fault",
    "Coprocessor Segment Overrun",
    "Invalid Task State Segment",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Reserved",
    "x87 Floating-Point",
    "Alignment Check",
    "Machine Check",
    "SIMD Floating-Point Exception",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
};

extern void isr_0();
extern void isr_1();
extern void isr_2();
extern void isr_3();
extern void isr_4();
extern void isr_5();
extern void isr_6();
extern void isr_7();
extern void isr_8();
extern void isr_9();
extern void isr_10();
extern void isr_11();
extern void isr_12();
extern void isr_13();
extern void isr_14();
extern void isr_15();
extern void isr_16();
extern void isr_17();
extern void isr_18();
extern void isr_19();
extern void isr_20();
extern void isr_21();
extern void isr_22();
extern void isr_23();
extern void isr_24();
extern void isr_25();
extern void isr_26();
extern void isr_27();
extern void isr_28();
extern void isr_29();
extern void isr_30();
extern void isr_31();

// IRQ
extern void isr_32();
extern void isr_33();
extern void isr_34();
extern void isr_35();
extern void isr_36();
extern void isr_37();
extern void isr_38();
extern void isr_39();
extern void isr_40();
extern void isr_41();
extern void isr_42();
extern void isr_43();
extern void isr_44();
extern void isr_45();
extern void isr_46();
extern void isr_47();

void isr_install() {
    idt_set_entry(0, (uint32_t)isr_0, 0x8, IDT_INT_KERNEL);
    idt_set_entry(1, (uint32_t)isr_1, 0x8, IDT_INT_KERNEL);
    idt_set_entry(2, (uint32_t)isr_2, 0x8, IDT_INT_KERNEL);
    idt_set_entry(3, (uint32_t)isr_3, 0x8, IDT_INT_KERNEL);
    idt_set_entry(4, (uint32_t)isr_4, 0x8, IDT_INT_KERNEL);
    idt_set_entry(5, (uint32_t)isr_5, 0x8, IDT_INT_KERNEL);
    idt_set_entry(6, (uint32_t)isr_6, 0x8, IDT_INT_KERNEL);
    idt_set_entry(7, (uint32_t)isr_7, 0x8, IDT_INT_KERNEL);
    idt_set_entry(8, (uint32_t)isr_8, 0x8, IDT_INT_KERNEL);
    idt_set_entry(9, (uint32_t)isr_9, 0x8, IDT_INT_KERNEL);
    idt_set_entry(10, (uint32_t)isr_10, 0x8, IDT_INT_KERNEL);
    idt_set_entry(11, (uint32_t)isr_11, 0x8, IDT_INT_KERNEL);
    idt_set_entry(12, (uint32_t)isr_12, 0x8, IDT_INT_KERNEL);
    idt_set_entry(13, (uint32_t)isr_13, 0x8, IDT_INT_KERNEL);
    idt_set_entry(14, (uint32_t)isr_14, 0x8, IDT_INT_KERNEL);
    idt_set_entry(15, (uint32_t)isr_15, 0x8, IDT_INT_KERNEL);
    idt_set_entry(16, (uint32_t)isr_16, 0x8, IDT_INT_KERNEL);
    idt_set_entry(17, (uint32_t)isr_17, 0x8, IDT_INT_KERNEL);
    idt_set_entry(18, (uint32_t)isr_18, 0x8, IDT_INT_KERNEL);
    idt_set_entry(19, (uint32_t)isr_19, 0x8, IDT_INT_KERNEL);
    idt_set_entry(20, (uint32_t)isr_20, 0x8, IDT_INT_KERNEL);
    idt_set_entry(21, (uint32_t)isr_21, 0x8, IDT_INT_KERNEL);
    idt_set_entry(22, (uint32_t)isr_22, 0x8, IDT_INT_KERNEL);
    idt_set_entry(23, (uint32_t)isr_23, 0x8, IDT_INT_KERNEL);
    idt_set_entry(24, (uint32_t)isr_24, 0x8, IDT_INT_KERNEL);
    idt_set_entry(25, (uint32_t)isr_25, 0x8, IDT_INT_KERNEL);
    idt_set_entry(26, (uint32_t)isr_26, 0x8, IDT_INT_KERNEL);
    idt_set_entry(27, (uint32_t)isr_27, 0x8, IDT_INT_KERNEL);
    idt_set_entry(28, (uint32_t)isr_28, 0x8, IDT_INT_KERNEL);
    idt_set_entry(29, (uint32_t)isr_29, 0x8, IDT_INT_KERNEL);
    idt_set_entry(30, (uint32_t)isr_30, 0x8, IDT_INT_KERNEL);
    idt_set_entry(31, (uint32_t)isr_31, 0x8, IDT_INT_KERNEL);

    idt_set_entry(32, (uint32_t)isr_32, 0x8, IDT_INT_KERNEL);
    idt_set_entry(33, (uint32_t)isr_33, 0x8, IDT_INT_KERNEL);
    idt_set_entry(34, (uint32_t)isr_34, 0x8, IDT_INT_KERNEL);
    idt_set_entry(35, (uint32_t)isr_35, 0x8, IDT_INT_KERNEL);
    idt_set_entry(36, (uint32_t)isr_36, 0x8, IDT_INT_KERNEL);
    idt_set_entry(37, (uint32_t)isr_37, 0x8, IDT_INT_KERNEL);
    idt_set_entry(38, (uint32_t)isr_38, 0x8, IDT_INT_KERNEL);
    idt_set_entry(39, (uint32_t)isr_39, 0x8, IDT_INT_KERNEL);
    idt_set_entry(40, (uint32_t)isr_40, 0x8, IDT_INT_KERNEL);
    idt_set_entry(41, (uint32_t)isr_41, 0x8, IDT_INT_KERNEL);
    idt_set_entry(42, (uint32_t)isr_42, 0x8, IDT_INT_KERNEL);
    idt_set_entry(43, (uint32_t)isr_43, 0x8, IDT_INT_KERNEL);
    idt_set_entry(44, (uint32_t)isr_44, 0x8, IDT_INT_KERNEL);
    idt_set_entry(45, (uint32_t)isr_45, 0x8, IDT_INT_KERNEL);
    idt_set_entry(46, (uint32_t)isr_46, 0x8, IDT_INT_KERNEL);
    idt_set_entry(47, (uint32_t)isr_47, 0x8, IDT_INT_KERNEL);
}

void interrupt_handler(registers_t *reg) {
    if (reg->int_no < 32) {
        printf("eax: 0x%X, ebx: 0x%X, ecx: 0x%X, edx: 0x%X\n", reg->eax, reg->ebx, reg->ecx, reg->edx);
        printf("edi: 0x%X, esi: 0x%X, ebp: 0x%X, esp: 0x%X\n", reg->edi, reg->esi, reg->ebp, reg->esp);
        printf("cs: 0x%X, ds: 0x%X, es: 0x%X, fs: 0x%X, ss: 0x%X\n", reg->cs, reg->ds, reg->es, reg->fs, reg->ss);
        printf("eip: 0x%X, eflags: 0x%X, user_esp: 0x%X, err_code: 0x%X\n", reg->eip, reg->eflags, reg->user_esp,
               reg->err_code);
        printf("%s", exception_msgs[reg->int_no]);
        printf(" Exception. System Halted!\n");
        while (1) {
        }
    }

    if (reg->int_no <= 47 && reg->int_no >= 32) {
        printf("IRQ %u occurred!\n", reg->int_no - 32);

        handler_t handler;
        handler = isr_handlers[reg->int_no];
        if (handler) {
            handler(reg);
        }

        irq_send_eoi(reg->int_no);
    } else {
        printf("Unknown interrupt %u!\n", reg->int_no);
    }
}

void isr_register_handler(uint32_t num, handler_t handler) {
    if (isr_handlers[num]) {
        printf("interrupt handler %d already registered", num, exception_msgs[num]);
    } else {
        isr_handlers[num] = handler;
    }
}

void isr_init() {
    irq_remap();
    isr_install();
}

void interrupt_enable() {
    asm volatile("sti");
}
