ROOT = ..
include $(ROOT)/build-aux/config.mk

BUILD = $(BUILD_DIR)/$(ARCH)/kernel

OBJ := kernel.o
OBJ += arch/i686/start.o

OBJ := $(addprefix $(BUILD)/, $(OBJ))

all: $(BUILD)/kernel

$(BUILD)/kernel: $(OBJ)
	$(GCC) $(LDFLAGS) -o $(BUILD)/kernel.elf $^ $(LIBS)

$(BUILD)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(GCC) $(CFLAGS) -c -o $@ $^

$(BUILD)/%.o: src/%.S
	@mkdir -p $(dir $@)
	$(GCC) $(ASFLAGS) -c -o $@ $^

clean:
	rm -rf $(BUILD)

.PHONY: all clean
