#ifndef HUANGMEI_IRQ_H
#define HUANGMEI_IRQ_H

#include <stdint.h>
#define PIC1_CMD  0x20
#define PIC1_DATA 0x21

#define PIC2_CMD  0xA0
#define PIC2_DATA 0xA1

#define PIC_EOI     0x20
#define PIC_RESTART 0x11

void irq_remap();
void irq_send_eoi(uint8_t isr);

#endif  // HUANGMEI_IRQ_H
