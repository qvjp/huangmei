ROOT = .

include $(ROOT)/build-aux/config.mk

KERNEL = $(BUILD_DIR)/$(ARCH)/kernel/kernel.elf
ISO = $(BUILD_DIR)/$(ARCH)/Huangmei.iso

all: kernel iso

kernel: $(KERNEL)

iso: $(ISO)

$(KERNEL):
	$(MAKE) -C kernel

$(ISO): $(KERNEL)
	mkdir $(BUILD_DIR)/iso
	cp -rf meta/boot $(BUILD_DIR)/iso
	cp -f $(KERNEL) $(BUILD_DIR)/iso
	$(MKRESCUE) -o $@ $(BUILD_DIR)/iso

qemu: $(ISO)
	qemu-system-i386 -cdrom $^

install-toolchain:
	bash $(ROOT)/build-aux/install-toolchain.sh

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all kernel iso clean
