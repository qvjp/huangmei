#ifndef HUANGMEI_PORT_H
#define HUANGMEI_PORT_H

#include <stdint.h>

static void outportb(uint16_t port, uint8_t data) {
    asm volatile("outb %1, %0" : : "dN"(port), "a"(data));
}

#endif  // HUANGMEI_PORT_H
