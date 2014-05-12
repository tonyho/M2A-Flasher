/*
 * SuperH SCIF device driver.
 * Copyright (C) 2013  Renesas Electronics Corporation
 * Copyright (C) 2007,2008,2010 Nobuhiro Iwamatsu
 * Copyright (C) 2002 - 2008  Paul Mundt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

//#include <common.h>
//#include <asm/io.h>
//#include <asm/processor.h>
#include "io.h"
#include "cpu.h"
#include "serial_sh.h"
#include <stdarg.h>
//#include <serial.h>
//#include <linux/compiler.h>
/*!!FixME!! See the circuit to right config, and move this definition to config.h*/
#define CONFIG_R8A7791
#define CONFIG_CONS_SCIF0
#define SCIF0_BASE 0xe6e60000
#define CONFIG_SCIF_CLK_FREQ 14745600 
#define CONFIG_SYS_CLK_FREQ  10000000
/*!!FixME!! End*/
#if defined(CONFIG_CONS_SCIF0)
# define SCIF_BASE	SCIF0_BASE
#elif defined(CONFIG_CONS_SCIF1)
# define SCIF_BASE	SCIF1_BASE
#elif defined(CONFIG_CONS_SCIF2)
# define SCIF_BASE	SCIF2_BASE
#elif defined(CONFIG_CONS_SCIF3)
# define SCIF_BASE	SCIF3_BASE
#elif defined(CONFIG_CONS_SCIF4)
# define SCIF_BASE	SCIF4_BASE
#elif defined(CONFIG_CONS_SCIF5)
# define SCIF_BASE	SCIF5_BASE
#elif defined(CONFIG_CONS_SCIF6)
# define SCIF_BASE	SCIF6_BASE
#elif defined(CONFIG_CONS_SCIF7)
# define SCIF_BASE	SCIF7_BASE
#else
# error "Default SCIF doesn't set....."
#endif

#if defined(CONFIG_SCIF_A)
	#define SCIF_BASE_PORT	PORT_SCIFA
#else
	#define SCIF_BASE_PORT	PORT_SCIF
#endif

static struct uart_port sh_sci = {
	.membase	= (unsigned char*)SCIF_BASE,
	.mapbase	= SCIF_BASE,
	.type		= SCIF_BASE_PORT,
};

void udelay(unsigned long delay){
    //unsigned long tmp = 0xffffff; //7Seconds
    //unsigned long tmp = 0x50000;
    unsigned long tmp = 0x100;
    for(; delay>0; delay--){
        for(; tmp>0; tmp--){
            ;
        }
    }
}

//#define putc	sh_serial_putc
/*
 * Conver int to string based on radix (usually 2, 8, 10, and 16)
 */
char *itoa(int num, char *str, int radix) 
{
    char string[] = "0123456789abcdefghijklmnopqrstuvwxyz";

    char* ptr = str;
    int i;
    int j;

    while (num)
    {
        if(16 == radix){
            *ptr++ = string[num % 16];
            num /= 16;

            if (num < 16)
            {
                *ptr++ = string[num];
                *ptr = '\0';
                break;
            }
        }
        if(10 == radix){
            *ptr++ = string[num % 10];
            num /= 10;

            if (num < 10)
            {
                *ptr++ = string[num];
                *ptr = '\0';
                break;
            }
        }
        if(8 == radix){
            *ptr++ = string[num % 8];
            num /= 8;

            if (num < 8)
            {
                *ptr++ = string[num];
                *ptr = '\0';
                break;
            }
        }
#if 0
        //for the compiler setting, we have to use the above 10/16 const value instead of radix
        //Otherwise it will hint the below link error:
        //undefined reference to `__aeabi_idivmod'
        //undefined reference to `__aeabi_idiv'
        *ptr++ = string[num % radix];
        num /= radix;

        if (num < radix)
        {
            *ptr++ = string[num];
            *ptr = '\0';
            break;
        }
#endif
    }

    j = ptr - str - 1;

    for (i = 0; i < (ptr - str) / 2; i++)
    {
        int temp = str[i];
        str[i] = str[j];
        str[j--] = temp;
    }

    return str;
}

void sh_serial_setbrg(void)
{
#if defined(CONFIG_R8A7790) || defined(CONFIG_R8A7791)
	//sci_out(&sh_sci, DL,CONFIG_SCIF_CLK_FREQ);
	sci_out(&sh_sci, DL,DL_VALUE(38400,CONFIG_SCIF_CLK_FREQ));
	//udelay((1000000 * 2 * 16 / CONFIG_SYS_CLK_FREQ) * 1000 + 1);
	udelay(1);
#else
	sci_out(&sh_sci, SCBRR, SCBRR_VALUE(gd->baudrate, CONFIG_SYS_CLK_FREQ));
#endif
}

int sh_serial_init(void)
{
	sci_out(&sh_sci, SCSCR , SCSCR_INIT(&sh_sci));
	sci_out(&sh_sci, SCSCR , SCSCR_INIT(&sh_sci));
	sci_out(&sh_sci, SCSMR, 0);
	sci_out(&sh_sci, SCSMR, 0);
	sci_out(&sh_sci, SCFCR, SCFCR_RFRST|SCFCR_TFRST);
	sci_in(&sh_sci, SCFCR);
	sci_out(&sh_sci, SCFCR, 0);

	sh_serial_setbrg();
	return 0;
}

#if defined(CONFIG_CPU_SH7760) || \
	defined(CONFIG_CPU_SH7780) || \
	defined(CONFIG_CPU_SH7785) || \
	defined(CONFIG_CPU_SH7786)
static int scif_rxfill(struct uart_port *port)
{
	return sci_in(port, SCRFDR) & 0xff;
}
#elif defined(CONFIG_CPU_SH7763)
static int scif_rxfill(struct uart_port *port)
{
	if ((port->mapbase == 0xffe00000) ||
		(port->mapbase == 0xffe08000)) {
		/* SCIF0/1*/
		return sci_in(port, SCRFDR) & 0xff;
	} else {
		/* SCIF2 */
		return sci_in(port, SCFDR) & SCIF2_RFDC_MASK;
	}
}
#elif defined(CONFIG_ARCH_SH7372)
static int scif_rxfill(struct uart_port *port)
{
	if (port->type == PORT_SCIFA)
		return sci_in(port, SCFDR) & SCIF_RFDC_MASK;
	else
		return sci_in(port, SCRFDR);
}
#else
static int scif_rxfill(struct uart_port *port)
{
	return sci_in(port, SCFDR) & SCIF_RFDC_MASK;
}
#endif

static int serial_rx_fifo_level(void)
{
	return scif_rxfill(&sh_sci);
}

static void handle_error(void)
{
	sci_in(&sh_sci, SCxSR);
	sci_out(&sh_sci, SCxSR, SCxSR_ERROR_CLEAR(&sh_sci));
	sci_in(&sh_sci, SCLSR);
	sci_out(&sh_sci, SCLSR, 0x00);
}

void serial_raw_putc(const char c)
{
	while (1) {
		/* Tx fifo is empty */
		if (sci_in(&sh_sci, SCxSR) & SCxSR_TEND(&sh_sci))
			break;
	}

	sci_out(&sh_sci, SCxTDR, c);
	sci_out(&sh_sci, SCxSR, sci_in(&sh_sci, SCxSR) & ~SCxSR_TEND(&sh_sci));
}

void sh_serial_putc(const char c)
{
	if (c == '\n')
		serial_raw_putc('\r');
	serial_raw_putc(c);
}

void sh_serial_puts(const char *s)
{
    char c = *s;
    while('\0' != c){
        if (c == '\n')
            serial_raw_putc('\r');
        serial_raw_putc(c);
        s++;
        c= *s;
    }
}


/*
 * A simple printf function. Only support the following format:
 * Code Format
 * %c character
 * %d signed integers
 * %i signed integers
 * %s a string of characters
 * %o octal
 * %x unsigned hexadecimal
 * Notice: This printf can output >0x80000000 value 
 */
int printf( const char* format, ...)
{
    va_list arg;
    int done = 0;

    va_start (arg, format);

    while( *format != '\0')
    {
        if( *format == '%')
        {
            if( *(format+1) == 'c' )
            {
                char c = (char)va_arg(arg, int);
                sh_serial_putc(c);
            } else if( *(format+1) == 'd' || *(format+1) == 'i')
            {
                char store[20];
                int i = va_arg(arg, int);
                char* str = store;
                itoa(i, store, 10);
                while( *str != '\0') sh_serial_putc(*str++); 
            } else if( *(format+1) == 'o')
            {
                char store[20];
                int i = va_arg(arg, int);
                char* str = store;
                itoa(i, store, 8);
                while( *str != '\0') sh_serial_putc(*str++); 
            } else if( *(format+1) == 'x')
            {
                char store[30];
                //int i = va_arg(arg, int);
                long i = va_arg(arg, long);
                char* str = store;
                itoa(i, store, 16);
                while( *str != '\0') sh_serial_putc(*str++); 
            } else if( *(format+1) == 's' )
            {
                char* str = va_arg(arg, char*);
                while( *str != '\0') sh_serial_putc(*str++);
            }

            // Skip this two characters.

            format += 2;
        } else {
            sh_serial_putc(*format++);
        }
    }

    va_end (arg);

    return done;
} 

static int sh_serial_tstc(void)
{
	if (sci_in(&sh_sci, SCxSR) & SCIF_ERRORS) {
		handle_error();
		return 0;
	}

	return serial_rx_fifo_level() ? 1 : 0;
}


int serial_getc_check(void)
{
	unsigned short status;

	status = sci_in(&sh_sci, SCxSR);

	if (status & SCIF_ERRORS)
		handle_error();
	if (sci_in(&sh_sci, SCLSR) & SCxSR_ORER(&sh_sci))
		handle_error();
	return status & (SCIF_DR | SCxSR_RDxF(&sh_sci));
}

int sh_serial_getc(void)
{
	unsigned short status;
	char ch;

	while (!serial_getc_check())
		;

	ch = sci_in(&sh_sci, SCxRDR);
	status = sci_in(&sh_sci, SCxSR);

	sci_out(&sh_sci, SCxSR, SCxSR_RDxF_CLEAR(&sh_sci));

	if (status & SCIF_ERRORS)
			handle_error();

	if (sci_in(&sh_sci, SCLSR) & SCxSR_ORER(&sh_sci))
		handle_error();
	return ch;
}

