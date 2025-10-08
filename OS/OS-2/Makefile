BUILD = ./build
SRC = ./src
INC = $(SRC)/inc
CFLAGS = -gdwarf-2 -O0 -c -m32 -I$(INC) -fno-pie -fno-stack-protector -nostdlib -ffreestanding -fno-exceptions -fno-asynchronous-unwind-tables -Wa,-mnaked-reg

$(BUILD)/%.o: $(SRC)/%.asm
	$(shell mkdir -p $(dir $@))
	nasm -g -F dwarf -f elf32 $< -o $@

$(BUILD)/%.o: $(SRC)/%.c
	$(shell mkdir -p $(dir $@))
	gcc $(CFLAGS) $< -o $@

$(BUILD)/boot.bin: $(BUILD)/boot/boot.o
	$(shell mkdir -p $(dir $@))
	ld -m i386pe -Ttext=0x7c00 -e start $^ -o $(BUILD)/boot/boot.elf
	objcopy -O binary $(BUILD)/boot/boot.elf $@

$(BUILD)/kernel.bin: $(BUILD)/kernel/start.o $(BUILD)/kernel/kernel.o $(BUILD)/kernel/tty.o $(BUILD)/kernel/memory.o
	$(shell mkdir -p $(dir $@))
	ld -m i386pe -Ttext=0x7e00 $^ -o $(BUILD)/kernel.elf
	objcopy -O binary $(BUILD)/kernel.elf $@

.PHONY: master
master: $(BUILD)/boot.bin $(BUILD)/kernel.bin
	dd if=$(BUILD)/boot.bin of=master.img bs=512 count=1 conv=notrunc
	dd if=$(BUILD)/kernel.bin of=master.img bs=512 count=10 seek=1 conv=notrunc

.PHONY: clean
clean:
	@rm -rf $(BUILD)/*

.PHONY: bochs
bochs: master
	bochsdbg -q -f bochsrc.bxrc

.PHONY: qemu
qemu: clean master
	qemu-system-i386 -s -S -m 128M -drive file=master.img,index=0,media=disk,format=raw