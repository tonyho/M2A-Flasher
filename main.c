/*
 * Copyright (C) 2014 suntec 
 * hexiongjun@pset.suntec.net
 * Function:
 *  Flash the SpiNorFlash and load the Bootloader then run it
 */

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include"cpu.h"
#include"serial_sh.h"

/*!!FixME!! Use the header file instead of directly declare*/
extern int sh_serial_init(void);
extern void sh_serial_putc(const char c);
extern struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode);
/*!!FixME!! End*/

/*
**GPIO registers,Ref datasheet page181
*/
struct Gpio_Regs {
    unsigned long IOINTSEL;    //offset=00    General IO/interrupt switching register 
    unsigned long INOUTSEL;    //offset=04    General input/output switching register
    unsigned long OUTDT;       //offset=08    General output register
    unsigned long INDT;        //offset=0c    General input register
    unsigned long INDDT;       //offset=10    Interrupt display register 
    unsigned long INTCLR;      //offset=14    Interrupt clear register 
    unsigned long INTMSK;      //offset=18    Interrupt mask register 
    unsigned long MSKCLR;      //offset=1c    Interrupt mask register 
    unsigned long POSNEG;      //offset=20    Positive/negative logic select register 
    unsigned long EDGLEVEL;    //offset=24    Edge/level select register
    unsigned long FILONOFF;    //offset=28    Chattering prevention on/off register
    unsigned long NOT_USE_0;   //offset=2c    Not use
    unsigned long NOT_USE_1;   //offset=30    Not use
    unsigned long NOT_USE_2;   //offset=34    Not use
    unsigned long INTMSKS;     //offset=38    Chattering prevention on/off register
    unsigned long MSKCLRS;     //offset=3c    Interrupt sub mask clear register
    unsigned long OUTDTSEL;    //offset=40    Output data select register
    unsigned long OUTDTH;      //offset=44    Output data high register
    unsigned long OUTDTL;      //offset=48    Output data low register
    unsigned long BOTHEDGE;    //offset=4c    One edge/both edge select register
};

/*
**GPIO 2 Output Setting Register[OUTDT0~7],Ref datasheet page188
**High or Low voltage output
*/
#ifdef TEST_LED_KOELSCH
#define GPIO2_VALUE 0xe6052008
#endif
void somedelay(unsigned long delay);
void GpioOutput(unsigned int GpioGroupBaseAddress, unsigned int pin, unsigned int HL);

int main(int argc, char * argv[]){
    int ret;
    struct spi_slave *pSpiSlave = NULL;
#ifdef TEST_LED_KOELSCH
    volatile unsigned long *pGP2 = (volatile unsigned long *)GPIO2_VALUE;
#endif
    unsigned long LedFlashCoutner = 100;
#ifdef TEST_LED_KOELSCH
    while(LedFlashCoutner--){
        *pGP2 = 0x55555555;
        somedelay(1);
        *pGP2 = 0xaaaaaaaa;
        somedelay(1);
    }
#endif

    while(LedFlashCoutner--){
        GpioOutput(GPIO2_BASE,19,0);
        GpioOutput(GPIO2_BASE,20,0);
        somedelay(1);
        GpioOutput(GPIO2_BASE,19,1);
        GpioOutput(GPIO2_BASE,20,1);
        somedelay(1);
    }
    ret = sh_serial_init();
    sh_serial_putc('A');
    pSpiSlave = spi_setup_slave(0, 0,0,0);
    return 0;
}

void somedelay(unsigned long delay){
    //unsigned long tmp = 0xffffff; //7Seconds
    unsigned long tmp = 0x50000;
    for(; delay>0; delay--){
        for(; tmp>0; tmp--){
            ;
        }
    }
}

/*
 *Para:
 *  GpioGroupBaseAddress[in]: GPIO Base address, eg: GPIO0_BASE
 *  pin[in]: pin number, eg: 0
 *  HL[in]: Output low or high 0/1, eg: 0
 */
void GpioOutput(unsigned int GpioGroupBaseAddress, unsigned int pin, unsigned int HL){
    struct Gpio_Regs *Gpio0_regs = (struct Gpio_Regs*)GpioGroupBaseAddress;
    unsigned long value = Gpio0_regs->OUTDT;
    /*!!FixME!!: Add the parameter judgement test*/
    if(HL == 0){
        value &= ~(1<<pin);
    }
    else{
        value |= (1<<pin);
    }
    Gpio0_regs->OUTDT = value;
    return ;
}
