ARCH := i686
BUILD_DIR = $(ROOT)/build
GCC := $(ARCH)-elf-gcc

CFLAGS ?= -O2 -g
CFLAGS += -I $(ROOT)/kernel/include
CFLAGS += -std=gnu17 -ffreestanding -Wall -Wextra
ASFLAGS ?= -I $(ROOT)/kernel/include
LDFLAGS ?= -T $(ROOT)/kernel/linker.ld -ffreestanding -nostdlib
LIBS ?= -lgcc

MKRESCUE ?= grub-mkrescue

ISO ?= Huangmei.iso
