#include <log.h>
#include <stddef.h> /* size_t */
#include <stdint.h> /* uintX_t */

const size_t col = 80;
const size_t row = 25;

enum ConsoleColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_BROWN = 14,
    WHITE = 15,
};

int make_color(uint8_t f, uint8_t b) { return (b << 4) + f; }

void print() {
    /*B8000是x86的VGA文本模式缓存地址，要显示文字，向这个内存地址写数据即可*/
    uint8_t *video = (uint8_t *)0xB8000;

    const char *hello = "Hello World! This is Huangmei";
    const size_t lengthOfHello = 29;

    /*
     * 初始化终端，将其设置为指定颜色
     * 每个VGA buffer都是BBBBFFFFCCCCCCCC的结构
     * B是背景色
     * F是前景色
     * C是ASCII字符
     */
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            video[2 * (col * i + j)] = ' ';
            video[2 * (col * i + j) + 1] = make_color(BLACK, (j + i) % 15);
        }
    }

    size_t startLocation = col * (row / 2) + col / 3;
    for (size_t i = 0; i < lengthOfHello; i++) {
        video[2 * (startLocation + i)] = hello[i];
        video[2 * (startLocation + i) + 1] = make_color(WHITE, DARK_GREY);
    }
}
