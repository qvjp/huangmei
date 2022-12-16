#include <log.h>  // print
// GCC提供的头文件
#include <stdint.h>  // uintX_t

// 内核入口函数
void kernel_main(uint32_t magic, uintptr_t multiboot) {
    (void)magic;
    (void)multiboot;

    print();
}
