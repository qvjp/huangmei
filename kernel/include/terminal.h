#ifndef HUANGMEI_TERMINAL_H
#define HUANGMEI_TERMINAL_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    TERM_COLOR_BLACK,
    TERM_COLOR_BLUE,
    TERM_COLOR_GREEN,
    TERM_COLOR_CYAN,
    TERM_COLOR_RED,
    TERM_COLOR_MAGENTA,
    TERM_COLOR_BROWN,
    TERM_COLOR_LIGHT_GREY,
    TERM_COLOR_DARK_GREY,
    TERM_COLOR_LIGHT_BLUE,
    TERM_COLOR_LIGHT_GREEN,
    TERM_COLOR_LIGHT_CYAN,
    TERM_COLOR_LIGHT_RED,
    TERM_COLOR_LIGHT_MAGENTA,
    TERM_COLOR_LIGHT_BROWN,
    TERM_COLOR_WHITE,
} terminal_color_t;

void terminal_init();
void terminal_change_color(terminal_color_t fg, terminal_color_t bg);
size_t terminal_write(const void *buffer, size_t size);

#endif  // HUANGMEI_TERMINAL_H
