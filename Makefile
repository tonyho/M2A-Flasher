INCDIR = ../inc
INCS =  -I$(INCDIR) 
#CROSS_COMPILE = /work/SmartAuto-312/prebuilt/toolchains/arm-fsl-linux-gnueabi/4.6.2/bin/arm-fsl-linux-gnueabi-
#CROSS_COMPILE = /media/work/BBB/tools/arm-2010.09/bin/arm-none-linux-gnueabi-
CROSS_COMPILE = /work/SmartAuto-312/prebuilt/toolchains/arm-fsl-linux-gnueabi/4.6.2/bin/arm-fsl-linux-gnueabi-
CFAGS = -nostdlib
all:
	#$(CROSS_COMPILE)gcc -c -g -fPIC boot_mon_spi.S  -o boot_mon_spi.o
	$(CROSS_COMPILE)gcc -c -g $(CFAGS) -fPIC start.S  -o start.o
	$(CROSS_COMPILE)gcc -c -g  $(CFAGS) main.c  -o main.o $(INCS)
	$(CROSS_COMPILE)gcc -c -g  $(CFAGS) sh_qspi.c  -o sh_qspi.o $(INCS)
	$(CROSS_COMPILE)gcc -c -g  $(CFAGS) serial_sh.c  -o serial_sh.o $(INCS)
	$(CROSS_COMPILE)ld -TFlasher.lds start.o main.o serial_sh.o sh_qspi.o -o Flasher 
	$(CROSS_COMPILE)objdump -d start.o > start.dis
	$(CROSS_COMPILE)objdump -d Flasher > Flasher.dis
	$(CROSS_COMPILE)objcopy --output-target=binary Flasher Flasher.bin
	$(CROSS_COMPILE)objcopy --output-target=srec Flasher Flasher.srec
	cp Flasher.srec ~/Share/
install:	
	cp Flasher.srec ~/Share/
clean:
	-rm *.bin
	-rm *.srec
	-rm *.s
	-rm *.o
	-rm *_elf
	-rm Flasher
	-rm *.dis
