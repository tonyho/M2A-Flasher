INCDIR = ../inc
INCS =  -I$(INCDIR) 
#CROSS_COMPILE = /home/hexiongjun/github/BBB/arm-2010.09/bin/arm-none-linux-gnueabi-
CROSS_COMPILE = /work/SmartAuto-312/prebuilt/toolchains/arm-fsl-linux-gnueabi/4.6.2/bin/arm-none-linux-gnueabi-
NOSTDLIB = -nostdlib 
NOBUILTIN = -fno-builtin -fno-builtin-putc -fno-builtin-printf
OPTMIZATION = -O1 # Optimize for size
#LIBS = -lgcc -L/work/SmartAuto-312/prebuilt/toolchains/arm-fsl-linux-gnueabi/4.6.2/lib/gcc/arm-fsl-linux-gnueabi/4.6.2
#LIBS = /home/hexiongjun/github/BBB/arm-2010.09/lib/gcc/arm-none-linux-gnueabi/4.5.1
CFLAGS = $(NOSTDLIB) $(NOBUILTIN) $(OPTMIZATION) #$(LIBS) 
all:
	#$(CROSS_COMPILE)gcc -c -g -fPIC boot_mon_spi.S  -o boot_mon_spi.o
	$(CROSS_COMPILE)gcc -c -g  $(CFLAGS) -fPIC start.S  -o start.o
	$(CROSS_COMPILE)gcc -c -g  $(CFLAGS) main.c  -o main.o $(INCS)
	$(CROSS_COMPILE)gcc -c -g  $(CFLAGS) sh_qspi.c  -o sh_qspi.o $(INCS)
	$(CROSS_COMPILE)gcc -c -g  $(CFLAGS) spi_flash.c  -o spi_flash.o $(INCS)
	$(CROSS_COMPILE)gcc -c -g  $(CFLAGS) spansion.c  -o spansion.o $(INCS)
	$(CROSS_COMPILE)gcc -c -g  $(CFLAGS) serial_sh.c  -o serial_sh.o $(INCS)
	$(CROSS_COMPILE)ld -TFlasher.lds start.o main.o  sh_qspi.o spi_flash.o serial_sh.o spansion.o -o Flasher 
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
