#ifndef HUANGMEI_IDT_H
#define HUANGMEI_IDT_H

#include <stdint.h>

/**
 *                               * IDT ENTRY *
 * |-------------------------------------------------------------------------|
 * |                     |        |        |                |                |
 * |     Offset          |  Attr  |  Zero  |    Selector    |     Offset     |
 * |      16:31          |        | 16:23  |      0:15      |      0:15      |
 * |                     |        |        |                |                |
 * |-------------------------------------------------------------------------|
 * |63                 48|47    40|39    32|31            16|15             0|
 *
 * 如图，IDT每个条目都是64位，其中：
 * 0-15和48-63共32位，用来存放ISR的入口地址
 * 16-31共16位，用来存放指向GDT某个段的段选择子
 * 32-39共8位，没有被使用，全部设为0
 * 40-47共8位，是类型和属性位，下边具体分析：
 *
 *             * Attr Byte *
 * |-------------------------------------|
 * |    |       |    |                   |
 * | Pr |  DPL  | S  |       TYPE        |
 * |    |       |    |                   |
 * |-------------------------------------|
 * |    7       5    4    3    2    1   0|
 *
 * TYPE共四位，在32位模式中，TYPE可能的设置有
 *     0101(0x5) 表示IDT中此条是一个task gate
 *     1110(0xE) 表示IDT中此条是一个interrupt gate
 *     1111(0xF) 表示IDT中此条是一个trap gate
 * S（Storage Segment）设置为0
 * DPL即Descriptor Privilege Level，指定调用此描述符所属最高特权级，不被用户空间直接使用，设置为0即可
 * PR设置为0表示未使用
 */

// attr
#define IDT_INTERRUPT_GATE 0xE
#define IDT_RING0          (0 << 5)
#define IDT_PRESENT        (1 << 7)

// idt flags
#define IDT_INT_KERNEL (IDT_INTERRUPT_GATE | IDT_RING0 | IDT_PRESENT)

typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t unused;
    uint8_t attr;
    uint16_t offset_high;
} __attribute__((__packed__)) idt_entry_t;

typedef struct {
    uint16_t size;
    void *offset;
} __attribute__((__packed__)) idt_descriptor_t;

void idt_init();
void idt_set_entry(uint8_t num, uint32_t offset, uint16_t selector, uint8_t attr);

extern void idt_load(idt_descriptor_t *idt_desc);

#endif  // HUANGMEI_IDT_H
