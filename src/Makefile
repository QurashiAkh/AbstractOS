OBJECTS = loader.o kmain.o drivers/io.o segmentation/memory_segments.o segmentation/gdt.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
			-nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

AbstractOS.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o AbstractOS.iso iso
	
run: AbstractOS.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o drivers/*.o segmentation/*.o kernel.elf AbstractOS.iso bochslog.txt com1.out
