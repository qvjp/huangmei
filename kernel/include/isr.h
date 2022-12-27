#ifndef HUANGMEI_ISR_H
#define HUANGMEI_ISR_H

#include <stdint.h>

typedef struct {
    // segment registers
    uint32_t gs;  // 16 bits
    uint32_t fs;  // 16 bits
    uint32_t es;  // 16 bits
    uint32_t ds;  // 16 bits

    // registers save by pusha
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;

    uint32_t int_no;

    // save by `int` instruction
    uint32_t err_code;
    uint32_t eip;
    uint32_t cs;  // 16 bits
    uint32_t eflags;
    uint32_t user_esp;
    uint32_t ss;  // 16 bits
} registers_t;

typedef void (*handler_t)(registers_t *);

void isr_init();
void interrupt_enable();

#endif  // HUANGMEI_ISR_H
