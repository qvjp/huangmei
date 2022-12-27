//
// Created by qujunping on 2022/12/27.
//

#include <irq.h>
#include <port.h>

void irq_remap() {
    outportb(PIC1_CMD, PIC_RESTART);
    outportb(PIC2_CMD, PIC_RESTART);

    outportb(PIC1_DATA, 32);
    outportb(PIC2_DATA, 40);

    outportb(PIC1_DATA, 4);
    outportb(PIC2_DATA, 2);

    outportb(PIC1_DATA, 1);
    outportb(PIC2_DATA, 1);
}

void irq_send_eoi(uint8_t isr) {
    // 中断处理结束后，要发送EOI(End Of Interrupt)给PIC的命令端口
    // 如果IDT入口号大于40(IRQ8-15)，也就是说这个IRQ来自从PIC，我们需要给从PIC的命令端口发送一个EOI
    // 而如果IRQ来自主PIC，我们只需要向主PIC发送EOI即可

    if (isr >= 40) {
        outportb(PIC2_CMD, PIC_EOI);
    }
    outportb(PIC1_CMD, PIC_EOI);
}
