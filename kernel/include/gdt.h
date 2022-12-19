#ifndef HUANGMEI_GDT_H
#define HUANGMEI_GDT_H

#include <stdint.h>

/**
 *                             * GDT ENTRY *
 * |-------------------------------------------------------------------------|
 * |         |     |     |        |        |                |                |
 * |  Base   |Flags|Limit| Access |  Base  |      Base      |      Limit     |
 * |  24:31  |     |16:19|        | 16:23  |      0:15      |      0:15      |
 * |         |     |     |        |        |                |                |
 * |-------------------------------------------------------------------------|
 * |63     56|55 52|51 48|47    40|39    32|31            16|15             0|
 * Limit: 20 bit 最大地址单元
 * Base: 32 bit  段开始处的线性地址
 * Access: 8 bit
 * Flags: 4 bit
 *             * Access Byte *                                 * Flags *
 * |-------------------------------------|               |-------------------|
 * |    |       |    |    |    |    |    |               |    |    |    |    |
 * | Pr | Privl | DT | Ex | DC | RW | AC |               | Gr | Sz | 0  | 0  |
 * |    |       |    |    |    |    |    |               |    |    |    |    |
 * |-------------------------------------|               |-------------------|
 * |    7       5    4    3    2    1   0|               |    7    6    5   4|
 * Pr: Present, 1 bit 所有有效的selectors这一位都设置为1
 * Privl: Privilege, 2 bit 0 = highest(kernel), 3 = lowest(user applications)
 * DT: Descriptor Type, 设置为1
 * Ex: Executable, 1是代码, 0是数据
 * DC: Direction/Conforming,
 *     对数据选择子是方向位，当DC = 0, 段向上增长, DC = 1, 段向下增长
 *     对代码选择子是权限控制位，当DC = 1, 允许设定的或更低权限执行, DC = 0, 只能设定的权限等级执行
 * RW: Readable/Writable,
 *     代码段可读，数据段可写
 *     并且代码段永远不可写，数据段永远可读
 * AC: Accessed, 设置为0即可，CPU在访问后会设置此位为1
 * Gr: Granularity, Gr = 0, limit 在1 Byte(byte粒度)范围内, Gr = 1, limit在4 Kib内(page粒度)
 * SZ: Size, SZ = 0, 16位保护模式, SZ = 1, 32位保护模式
 *
 * https://wiki.osdev.org/Global_Descriptor_Table
 */

// flags
#define GDT_GRANULARITY_4KiB (1 << 7)
#define GDT_PROTECTED_MODE   (1 << 6)

// access
#define GDT_READ_WRITE (1 << 1)
#define GDT_EXEC       (1 << 3)
#define GDT_DT         (1 << 4)
#define GDT_RING0      (0 << 5)
#define GDT_PRESENT    (1 << 7)

// access and flags
#define GDT_ACCESS_KERNEL_CODE (GDT_READ_WRITE | GDT_EXEC | GDT_DT | GDT_RING0 | GDT_PRESENT)
#define GDT_ACCESS_KERNEL_DATA (GDT_READ_WRITE | GDT_DT | GDT_RING0 | GDT_PRESENT)
#define GDT_FLAGS              (GDT_GRANULARITY_4KiB | GDT_PROTECTED_MODE)

// clang-format off
#define GDT_ENTRY(base, limit, access, flags) \
{ \
    (limit)          & 0xFFFF, \
    (base)           & 0xFFFF, \
    ((base) >> 16)   & 0xFF,   \
    (access)         & 0xFF,   \
    (((limit) >> 16) & 0x0F) | ((flags) & 0xF0), \
    ((base) >> 24)   & 0xFF    \
}
// clang-format on

typedef struct {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t limit_high_flags;
    uint8_t base_high;
} __attribute__((__packed__)) gdt_entry_t;

typedef struct {
    uint16_t size;
    void *offset;
} __attribute__((__packed__)) gdt_descriptor_t;

void gdt_init();

extern void gdt_load(gdt_descriptor_t *gdt_desc);

#endif  // HUANGMEI_GDT_H
