#include <terminal.h>

#define ENTRY(x, y) terminal_buffer[(y)*TERMINAL_WIDTH + (x)]
#define CHAR(x, y) ENTRY((x), (y)) & 0xFF

const size_t TERMINAL_WIDTH = 80;
const size_t TERMINAL_HEIGHT = 25;
const intptr_t VGA_BUFFER = 0xB8000;

static uint32_t terminal_x;
static uint32_t terminal_y;
static uint8_t terminal_color;
static uint16_t *terminal_buffer;

static inline uint8_t terminal_make_color(terminal_color_t fg, terminal_color_t bg) {
    return fg | bg << 4;
}

// Entry format: [ BLINK BG BG BG FG FG FG FG | C C C C C C C C ]
//               [           8-bits           |      8-bits     ]
static inline uint16_t terminal_make_entry(char c, uint8_t color) {
    return (uint16_t)c | ((uint16_t)color) << 8;
}

void terminal_change_color(terminal_color_t fg, terminal_color_t bg) {
    terminal_color = terminal_make_color(fg, bg);
    for (size_t x = 0; x < TERMINAL_WIDTH; x++) {
        for (size_t y = 0; y < TERMINAL_HEIGHT; y++) {
            ENTRY(x, y) = terminal_make_entry(CHAR(x, y), terminal_color);
        }
    }
}

void terminal_scroll() {
    for (size_t y = 0; y < TERMINAL_HEIGHT; y++) {
        for (size_t x = 0; x < TERMINAL_WIDTH; x++) {
            if (y < TERMINAL_HEIGHT - 1) {  // 不是最后一行
                ENTRY(x, y) = ENTRY(x, y + 1);
            } else {
                ENTRY(x, y) = terminal_make_entry(' ', terminal_color);
            }
        }
    }

    terminal_y--;
}

static void terminal_putchar(char c) {
    if (c == '\n' || terminal_x >= TERMINAL_WIDTH) {
        terminal_x = 0;
        terminal_y++;
    }

    if (terminal_y >= TERMINAL_HEIGHT) {
        terminal_scroll();
    }

    if (c == '\n') {
        return;
    }

    ENTRY(terminal_x, terminal_y) = terminal_make_entry(c, terminal_color);

    terminal_x++;
}

size_t terminal_write(const void *buffer, size_t size) {
    const char *buf = (const char *)buffer;
    for (size_t i = 0; i < size; i++) {
        terminal_putchar(buf[i]);
    }

    return size;
}

void terminal_init() {
    terminal_color = terminal_make_color(TERM_COLOR_WHITE, TERM_COLOR_BLACK);
    terminal_buffer = (uint16_t *)VGA_BUFFER;
    terminal_x = 0;
    terminal_y = 0;

    uint16_t entry = terminal_make_entry(' ', terminal_color);

    for (size_t x = 0; x < TERMINAL_WIDTH; x++) {
        for (size_t y = 0; y < TERMINAL_HEIGHT; y++) {
            ENTRY(x, y) = entry;
        }
    }
}
