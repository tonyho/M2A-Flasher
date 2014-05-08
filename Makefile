INCDIR = ../inc
INCS =  -I$(INCDIR) 
CROSS_COMPILE = /work/SmartAuto-312/prebuilt/toolchains/arm-fsl-linux-gnueabi/4.6.2/bin/arm-fsl-linux-gnueabi-
all:
	#$(CROSS_COMPILE)gcc -c -g -fPIC boot_mon_spi.S  -o boot_mon_spi.o
	$(CROSS_COMPILE)gcc -c -g -fPIC start.S  -o start.o
	#$(CROSS_COMPILE)gcc -c -g  main.c  -o main.o $(INCS)
	$(CROSS_COMPILE)ld -TFlasher.lds start.o -o Flasher 
	$(CROSS_COMPILE)objdump -d start.o > start.dis
	$(CROSS_COMPILE)objdump -d Flasher > Flasher.dis
	$(CROSS_COMPILE)objcopy --output-target=binary Flasher Flasher.bin
	$(CROSS_COMPILE)objcopy --output-target=srec Flasher Flasher.srec
clean:
	-rm *.bin
	-rm *.srec
	-rm *.s
	-rm *.o
	-rm *_elf
