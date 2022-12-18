#include <log.h>
#include <stdarg.h>
#include <terminal.h>

const int max_length_of_int32 = 11;

static void print_character(char c) {
    terminal_write(&c, 1);
}

static void print_string(const char *s) {
    while (*s) {
        print_character(*s++);
    }
}
static void print_number(unsigned u, int base) {
    static const char *digits = "0123456789ABCDEF";
    char buffer[max_length_of_int32];
    char *p = buffer + 10;
    *p = '\0';
    do {
        *--p = digits[u % base];
        u /= base;
    } while (u);

    print_string(p);
}

void printf(const char *format, ...) {
    va_list ap;
    va_start(ap, format);

    unsigned u;
    unsigned char c;
    const char *s;
    while (*format) {
        if (*format != '%') {
            print_character(*format);
        } else {
            switch (*++format) {
                case 'u':
                    u = va_arg(ap, unsigned);
                    print_number(u, 10);
                    break;
                case 'X':
                    u = va_arg(ap, unsigned);
                    print_number(u, 16);
                    break;
                case 'c':
                    c = va_arg(ap, int);
                    print_character((char)c);
                    break;
                case 's':
                    s = va_arg(ap, const char *);
                    print_string(s);
                    break;
                case '%':
                    print_character('%');
                    break;
                case '\0':
                    va_end(ap);
                    return;
                default:
                    print_character('%');
                    print_character(*format);
            }
        }
        format++;
    }
    va_end(ap);
}
