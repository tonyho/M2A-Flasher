/*
 * Copyright (C) 2014 suntec 
 * hexiongjun@pset.suntec.net
 * Function:
 *  Flash the SpiNorFlash and load the Bootloader then run it
 */

//#include<stdio.h>
#include<unistd.h>
//#include<string.h>
#include"cpu.h"
#include"io.h"
#include"r8a7791.h"
#include"serial_sh.h"

#define LED6 19
#define LED7 20
#define LED8 21
#define LED_GPIO_BASE GPIO2_BASE
#define LED_ON  1    
#define LED_OFF 0    

/*!!FixME!! Use the header file instead of directly declare*/
extern int sh_serial_init(void);
extern void sh_serial_putc(const char c);
extern struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode);
extern void sh_serial_puts(const char *s);
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

#if 0
/* QoS version 0.23 */

enum {
	DBSC3_00, DBSC3_01, DBSC3_02, DBSC3_03, DBSC3_04,
	DBSC3_05, DBSC3_06, DBSC3_07, DBSC3_08, DBSC3_09,
	DBSC3_10, DBSC3_11, DBSC3_12, DBSC3_13, DBSC3_14,
	DBSC3_15,
	DBSC3_NR,
};

static u32 dbsc3_0_r_qos_addr[DBSC3_NR] = {
	[DBSC3_00] = DBSC3_0_QOS_R0_BASE,
	[DBSC3_01] = DBSC3_0_QOS_R1_BASE,
	[DBSC3_02] = DBSC3_0_QOS_R2_BASE,
	[DBSC3_03] = DBSC3_0_QOS_R3_BASE,
	[DBSC3_04] = DBSC3_0_QOS_R4_BASE,
	[DBSC3_05] = DBSC3_0_QOS_R5_BASE,
	[DBSC3_06] = DBSC3_0_QOS_R6_BASE,
	[DBSC3_07] = DBSC3_0_QOS_R7_BASE,
	[DBSC3_08] = DBSC3_0_QOS_R8_BASE,
	[DBSC3_09] = DBSC3_0_QOS_R9_BASE,
	[DBSC3_10] = DBSC3_0_QOS_R10_BASE,
	[DBSC3_11] = DBSC3_0_QOS_R11_BASE,
	[DBSC3_12] = DBSC3_0_QOS_R12_BASE,
	[DBSC3_13] = DBSC3_0_QOS_R13_BASE,
	[DBSC3_14] = DBSC3_0_QOS_R14_BASE,
	[DBSC3_15] = DBSC3_0_QOS_R15_BASE,
};

static u32 dbsc3_0_w_qos_addr[DBSC3_NR] = {
	[DBSC3_00] = DBSC3_0_QOS_W0_BASE,
	[DBSC3_01] = DBSC3_0_QOS_W1_BASE,
	[DBSC3_02] = DBSC3_0_QOS_W2_BASE,
	[DBSC3_03] = DBSC3_0_QOS_W3_BASE,
	[DBSC3_04] = DBSC3_0_QOS_W4_BASE,
	[DBSC3_05] = DBSC3_0_QOS_W5_BASE,
	[DBSC3_06] = DBSC3_0_QOS_W6_BASE,
	[DBSC3_07] = DBSC3_0_QOS_W7_BASE,
	[DBSC3_08] = DBSC3_0_QOS_W8_BASE,
	[DBSC3_09] = DBSC3_0_QOS_W9_BASE,
	[DBSC3_10] = DBSC3_0_QOS_W10_BASE,
	[DBSC3_11] = DBSC3_0_QOS_W11_BASE,
	[DBSC3_12] = DBSC3_0_QOS_W12_BASE,
	[DBSC3_13] = DBSC3_0_QOS_W13_BASE,
	[DBSC3_14] = DBSC3_0_QOS_W14_BASE,
	[DBSC3_15] = DBSC3_0_QOS_W15_BASE,
};

static u32 dbsc3_1_r_qos_addr[DBSC3_NR] = {
	[DBSC3_00] = DBSC3_1_QOS_R0_BASE,
	[DBSC3_01] = DBSC3_1_QOS_R1_BASE,
	[DBSC3_02] = DBSC3_1_QOS_R2_BASE,
	[DBSC3_03] = DBSC3_1_QOS_R3_BASE,
	[DBSC3_04] = DBSC3_1_QOS_R4_BASE,
	[DBSC3_05] = DBSC3_1_QOS_R5_BASE,
	[DBSC3_06] = DBSC3_1_QOS_R6_BASE,
	[DBSC3_07] = DBSC3_1_QOS_R7_BASE,
	[DBSC3_08] = DBSC3_1_QOS_R8_BASE,
	[DBSC3_09] = DBSC3_1_QOS_R9_BASE,
	[DBSC3_10] = DBSC3_1_QOS_R10_BASE,
	[DBSC3_11] = DBSC3_1_QOS_R11_BASE,
	[DBSC3_12] = DBSC3_1_QOS_R12_BASE,
	[DBSC3_13] = DBSC3_1_QOS_R13_BASE,
	[DBSC3_14] = DBSC3_1_QOS_R14_BASE,
	[DBSC3_15] = DBSC3_1_QOS_R15_BASE,
};

static u32 dbsc3_1_w_qos_addr[DBSC3_NR] = {
	[DBSC3_00] = DBSC3_1_QOS_W0_BASE,
	[DBSC3_01] = DBSC3_1_QOS_W1_BASE,
	[DBSC3_02] = DBSC3_1_QOS_W2_BASE,
	[DBSC3_03] = DBSC3_1_QOS_W3_BASE,
	[DBSC3_04] = DBSC3_1_QOS_W4_BASE,
	[DBSC3_05] = DBSC3_1_QOS_W5_BASE,
	[DBSC3_06] = DBSC3_1_QOS_W6_BASE,
	[DBSC3_07] = DBSC3_1_QOS_W7_BASE,
	[DBSC3_08] = DBSC3_1_QOS_W8_BASE,
	[DBSC3_09] = DBSC3_1_QOS_W9_BASE,
	[DBSC3_10] = DBSC3_1_QOS_W10_BASE,
	[DBSC3_11] = DBSC3_1_QOS_W11_BASE,
	[DBSC3_12] = DBSC3_1_QOS_W12_BASE,
	[DBSC3_13] = DBSC3_1_QOS_W13_BASE,
	[DBSC3_14] = DBSC3_1_QOS_W14_BASE,
	[DBSC3_15] = DBSC3_1_QOS_W15_BASE,
};

void qos_init(void)
{
	int i;
	struct r8a7791_s3c *s3c;
	struct r8a7791_s3c_qos *s3c_qos;
	struct r8a7791_dbsc3_qos *qos_addr;
	struct r8a7791_mxi *mxi;
	struct r8a7791_mxi_qos *mxi_qos;
	struct r8a7791_axi_qos *axi_qos;

	/* DBSC DBADJ2 */
	writel(0x20042004, DBSC3_0_DBADJ2);

	/* S3C -QoS */
	s3c = (struct r8a7791_s3c *)S3C_BASE;
	writel(0x00FF1B1D, &s3c->s3cadsplcr);
	writel(0x1F0D0C0C, &s3c->s3crorr);
	writel(0x1F0D0C0A, &s3c->s3cworr);

	/* QoS Control Registers */
	s3c_qos = (struct r8a7791_s3c_qos *)S3C_QOS_CCI0_BASE;
	writel(0x00890089, &s3c_qos->s3cqos0);
	writel(0x20960010, &s3c_qos->s3cqos1);
	writel(0x20302030, &s3c_qos->s3cqos2);
	writel(0x20AA2200, &s3c_qos->s3cqos3);
	writel(0x00002032, &s3c_qos->s3cqos4);
	writel(0x20960010, &s3c_qos->s3cqos5);
	writel(0x20302030, &s3c_qos->s3cqos6);
	writel(0x20AA2200, &s3c_qos->s3cqos7);
	writel(0x00002032, &s3c_qos->s3cqos8);

	s3c_qos = (struct r8a7791_s3c_qos *)S3C_QOS_CCI1_BASE;
	writel(0x00890089, &s3c_qos->s3cqos0);
	writel(0x20960010, &s3c_qos->s3cqos1);
	writel(0x20302030, &s3c_qos->s3cqos2);
	writel(0x20AA2200, &s3c_qos->s3cqos3);
	writel(0x00002032, &s3c_qos->s3cqos4);
	writel(0x20960010, &s3c_qos->s3cqos5);
	writel(0x20302030, &s3c_qos->s3cqos6);
	writel(0x20AA2200, &s3c_qos->s3cqos7);
	writel(0x00002032, &s3c_qos->s3cqos8);

	s3c_qos = (struct r8a7791_s3c_qos *)S3C_QOS_MXI_BASE;
	writel(0x00820082, &s3c_qos->s3cqos0);
	writel(0x20960020, &s3c_qos->s3cqos1);
	writel(0x20302030, &s3c_qos->s3cqos2);
	writel(0x20AA20DC, &s3c_qos->s3cqos3);
	writel(0x00002032, &s3c_qos->s3cqos4);
	writel(0x20960020, &s3c_qos->s3cqos5);
	writel(0x20302030, &s3c_qos->s3cqos6);
	writel(0x20AA20DC, &s3c_qos->s3cqos7);
	writel(0x00002032, &s3c_qos->s3cqos8);

	s3c_qos = (struct r8a7791_s3c_qos *)S3C_QOS_AXI_BASE;
	writel(0x00820082, &s3c_qos->s3cqos0);
	writel(0x20960020, &s3c_qos->s3cqos1);
	writel(0x20302030, &s3c_qos->s3cqos2);
	writel(0x20AA20FA, &s3c_qos->s3cqos3);
	writel(0x00002032, &s3c_qos->s3cqos4);
	writel(0x20960020, &s3c_qos->s3cqos5);
	writel(0x20302030, &s3c_qos->s3cqos6);
	writel(0x20AA20FA, &s3c_qos->s3cqos7);
	writel(0x00002032, &s3c_qos->s3cqos8);

	/* DBSC -QoS */
	/* DBSC0 - Read */
	for (i = DBSC3_00; i < DBSC3_NR; i++) {
		qos_addr = (struct r8a7791_dbsc3_qos *)dbsc3_0_r_qos_addr[i];
		writel(0x00000002, &qos_addr->dblgcnt);
		writel(0x00002096, &qos_addr->dbtmval0);
		writel(0x00002064, &qos_addr->dbtmval1);
		writel(0x00002032, &qos_addr->dbtmval2);
		writel(0x00001FB0, &qos_addr->dbtmval3);
		writel(0x00000001, &qos_addr->dbrqctr);
		writel(0x00002078, &qos_addr->dbthres0);
		writel(0x0000204B, &qos_addr->dbthres1);
		writel(0x00001FE7, &qos_addr->dbthres2);
		writel(0x00000001, &qos_addr->dblgqon);
	}

	/* DBSC0 - Write */
	for (i = DBSC3_00; i < DBSC3_NR; i++) {
		qos_addr = (struct r8a7791_dbsc3_qos *)dbsc3_0_w_qos_addr[i];
		writel(0x00000002, &qos_addr->dblgcnt);
		writel(0x000020EB, &qos_addr->dbtmval0);
		writel(0x0000206E, &qos_addr->dbtmval1);
		writel(0x00002050, &qos_addr->dbtmval2);
		writel(0x0000203A, &qos_addr->dbtmval3);
		writel(0x00000001, &qos_addr->dbrqctr);
		writel(0x00002078, &qos_addr->dbthres0);
		writel(0x0000205A, &qos_addr->dbthres1);
		writel(0x0000203C, &qos_addr->dbthres2);
		writel(0x00000001, &qos_addr->dblgqon);
	}

	/* DBSC1 - Read */
	for (i = DBSC3_00; i < DBSC3_NR; i++) {
		qos_addr = (struct r8a7791_dbsc3_qos *)dbsc3_1_r_qos_addr[i];
		writel(0x00000002, &qos_addr->dblgcnt);
		writel(0x00002096, &qos_addr->dbtmval0);
		writel(0x00002064, &qos_addr->dbtmval1);
		writel(0x00002032, &qos_addr->dbtmval2);
		writel(0x00001FB0, &qos_addr->dbtmval3);
		writel(0x00000001, &qos_addr->dbrqctr);
		writel(0x00002078, &qos_addr->dbthres0);
		writel(0x0000204B, &qos_addr->dbthres1);
		writel(0x00001FE7, &qos_addr->dbthres2);
		writel(0x00000001, &qos_addr->dblgqon);
	}

	/* DBSC1 - Write */
	for (i = DBSC3_00; i < DBSC3_NR; i++) {
		qos_addr = (struct r8a7791_dbsc3_qos *)dbsc3_1_w_qos_addr[i];
		writel(0x00000002, &qos_addr->dblgcnt);
		writel(0x000020EB, &qos_addr->dbtmval0);
		writel(0x0000206E, &qos_addr->dbtmval1);
		writel(0x00002050, &qos_addr->dbtmval2);
		writel(0x0000203A, &qos_addr->dbtmval3);
		writel(0x00000001, &qos_addr->dbrqctr);
		writel(0x00002078, &qos_addr->dbthres0);
		writel(0x0000205A, &qos_addr->dbthres1);
		writel(0x0000203C, &qos_addr->dbthres2);
		writel(0x00000001, &qos_addr->dblgqon);
	}

	/* CCI-400 -QoS */
	writel(0x20001000, CCI_400_MAXOT_1);
	writel(0x20001000, CCI_400_MAXOT_2);
	writel(0x0000000C, CCI_400_QOSCNTL_1);
	writel(0x0000000C, CCI_400_QOSCNTL_2);

	/* MXI -QoS */
	/* Transaction Control (MXI) */
	mxi = (struct r8a7791_mxi *)MXI_BASE;
	writel(0x00000013, &mxi->mxrtcr);
	writel(0x00000013, &mxi->mxwtcr);
	writel(0x00780080, &mxi->mxsaar0);
	writel(0x02000800, &mxi->mxsaar1);

	/* QoS Control (MXI) */
	mxi_qos = (struct r8a7791_mxi_qos *)MXI_QOS_BASE;
	writel(0x0000000C, &mxi_qos->vspdu0);
	writel(0x0000000C, &mxi_qos->vspdu1);
	writel(0x0000000D, &mxi_qos->du0);
	writel(0x0000000D, &mxi_qos->du1);

	/* AXI -QoS */
	/* Transaction Control (MXI) */
	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_SYX64TO128_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_AVB_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020A6, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_G2D_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020A6, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_IMP0_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002021, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_IMP1_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002037, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_IMUX0_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_IMUX1_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_IMUX2_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_LBS_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000214C, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MMUDS_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MMUM_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MMUR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MMUS0_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MMUS1_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MTSB0_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002021, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MTSB1_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002021, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_PCI_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000214C, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_RTX_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_SDS0_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020A6, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_SDS1_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020A6, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_USB20_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_USB21_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_USB22_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_USB30_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000214C, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_AX2M_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_CC50_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002029, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_CCI_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_CS_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_DDM_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020A6, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_ETH_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_MPXM_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_SAT0_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_SAT1_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_SDM0_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000214C, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_SDM1_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000214C, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_TRAB_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020A6, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_UDM0_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI_UDM1_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	/* QoS Register (RT-AXI) */
	axi_qos = (struct r8a7791_axi_qos *)RT_AXI_SHX_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)RT_AXI_DBG_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)RT_AXI_RDM_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002299, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)RT_AXI_RDS_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002029, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)RT_AXI_RTX64TO128_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)RT_AXI_STPRO_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002029, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)RT_AXI_SY2RT_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	/* QoS Register (MP-AXI) */
	axi_qos = (struct r8a7791_axi_qos *)MP_AXI_ADSP_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002037, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MP_AXI_ASDS0_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002014, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MP_AXI_ASDS1_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002014, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MP_AXI_MLP_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002014, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MP_AXI_MMUMP_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MP_AXI_SPU_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002053, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MP_AXI_SPUC_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000206E, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	/* QoS Register (SYS-AXI256) */
	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI256_AXI128TO256_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI256_SYX_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI256_MPX_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)SYS_AXI256_MXI_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	/* QoS Register (CCI-AXI) */
	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_MMUS0_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_SYX2_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_MMUR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_MMUDS_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_MMUM_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_MXI_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x00002245, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_MMUS1_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)CCI_AXI_MMUMP_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000000, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	/* QoS Register (Media-AXI) */
	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_MXR_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x000020DC, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x000020AA, &axi_qos->qosthres0);
	writel(0x00002032, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_MXW_BASE;
	writel(0x00000002, &axi_qos->qosconf);
	writel(0x000020DC, &axi_qos->qosctset0);
	writel(0x00002096, &axi_qos->qosctset1);
	writel(0x00002030, &axi_qos->qosctset2);
	writel(0x00002030, &axi_qos->qosctset3);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x000020AA, &axi_qos->qosthres0);
	writel(0x00002032, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_JPR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_JPW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

#if 0
	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_GCU0R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_GCU0W_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_GCU1R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_GCU1W_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002004, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);
#endif

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_TDMR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_TDMW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

#if 0
	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP0CR_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002005, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP0CW_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002005, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);
#endif

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP1CR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP1CW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPDU0CR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPDU0CW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPDU1CR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPDU1CW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002190, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VIN0W_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

#if 0
	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP0R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002005, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP0W_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002007, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);
#endif

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_FDP0R_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_FDP0W_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_IMSR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_IMSW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP1R_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSP1W_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_FDP1R_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_FDP1W_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_IMRR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_IMRW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

#if 0
	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_FDP2R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000200F, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_FDP2W_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000200F, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);
#endif

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPD0R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPD0W_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPD1R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VSPD1W_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x000020C8, &axi_qos->qosctset0);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_DU0R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002063, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_DU0W_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002063, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

#if 0
	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_DU1R_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002002, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_DU1W_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002003, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);
#endif

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP0CR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002073, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP0CW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002073, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP0VR_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002073, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP0VW_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002073, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VPC0R_BASE;
	writel(0x00000001, &axi_qos->qosconf);
	writel(0x00002073, &axi_qos->qosctset0);
	writel(0x00000020, &axi_qos->qosreqctr);
	writel(0x00002064, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00000001, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

#if 0
	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP1CR_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002001, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP1CW_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002009, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP1VR_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000200F, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VCP1VW_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x0000200F, &axi_qos->qosctset0);
	writel(0x00000001, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000001, &axi_qos->qosqon);

	axi_qos = (struct r8a7791_axi_qos *)MEDIA_AXI_VPC1R_BASE;
	writel(0x00000000, &axi_qos->qosconf);
	writel(0x00002001, &axi_qos->qosctset0);
	writel(0x00000000, &axi_qos->qosreqctr);
	writel(0x00002006, &axi_qos->qosthres0);
	writel(0x00002004, &axi_qos->qosthres1);
	writel(0x00002002, &axi_qos->qosthres2);
	writel(0x00000000, &axi_qos->qosqon);

	/* CCI-AXI Function Register */
	writel(0x00000011, CCI_AXI_IPMMUIDVMCR);
	writel(0x00000011, CCI_AXI_IPMMURDVMCR);
	writel(0x00000011, CCI_AXI_IPMMUS0DVMCR);
	writel(0x00000011, CCI_AXI_IPMMUS1DVMCR);
	writel(0x00000011, CCI_AXI_IPMMUMPDVMCR);
	writel(0x00000011, CCI_AXI_IPMMUDSDVMCR);
	writel(0x0000F700, CCI_AXI_AX2ADDRMASK);
#endif
}


#define s_init_wait(cnt) \
		({	\
			volatile u32 i = 0x10000 * cnt;	\
			while (i > 0)	\
				i--;	\
		})

void s_init(void)
{
	struct r8a7791_rwdt *rwdt = (struct r8a7791_rwdt *)RWDT_BASE;
	struct r8a7791_swdt *swdt = (struct r8a7791_swdt *)SWDT_BASE;
	struct r8a7791_lbsc *lbsc = (struct r8a7791_lbsc *)LBSC_BASE;
	struct r8a7791_dbsc3 *dbsc3_0 = (struct r8a7791_dbsc3 *)DBSC3_0_BASE;

	/* Watchdog init */
	writel(0xA5A5A500, &rwdt->rwtcsra);
	writel(0xA5A5A500, &swdt->swtcsra);

	/* QoS */
	//qos_init();

#if defined(CONFIG_NORFLASH)
	/* LBSC */
	writel(0x00000020, &lbsc->cs0ctrl);
	writel(0x00000020, &lbsc->cs1ctrl);
	writel(0x00002020, &lbsc->ecs0ctrl);
	writel(0x00002020, &lbsc->ecs1ctrl);

	writel(0x077F077F, &lbsc->cswcr0);
	writel(0x077F077F, &lbsc->cswcr1);
	writel(0x077F077F, &lbsc->ecswcr0);
	writel(0x077F077F, &lbsc->ecswcr1);

	/* DBSC3 */
	s_init_wait(10);

	writel(0x0000A55A, &dbsc3_0->dbpdlck);
	writel(0x00000001, &dbsc3_0->dbpdrga);
	writel(0x80000000, &dbsc3_0->dbpdrgd);
	writel(0x00000004, &dbsc3_0->dbpdrga);
	while ((readl(&dbsc3_0->dbpdrgd) & 0x00000001) != 0x00000001)
		;

	writel(0x00000006, &dbsc3_0->dbpdrga);
	writel(0x0001C000, &dbsc3_0->dbpdrgd);

	writel(0x00000023, &dbsc3_0->dbpdrga);
	writel(0x00FD2480, &dbsc3_0->dbpdrgd);

	writel(0x00000010, &dbsc3_0->dbpdrga);
	writel(0xF004649B, &dbsc3_0->dbpdrgd);

	writel(0x0000000F, &dbsc3_0->dbpdrga);
	writel(0x00181EE4, &dbsc3_0->dbpdrgd);

	writel(0x0000000E, &dbsc3_0->dbpdrga);
	writel(0x33C03812, &dbsc3_0->dbpdrgd);

	writel(0x00000003, &dbsc3_0->dbpdrga);
	writel(0x0300C481, &dbsc3_0->dbpdrgd);

	writel(0x00000007, &dbsc3_0->dbkind);
	writel(0x10030A02, &dbsc3_0->dbconf0);
	writel(0x00000001, &dbsc3_0->dbphytype);
	writel(0x00000000, &dbsc3_0->dbbl);
	writel(0x0000000B, &dbsc3_0->dbtr0);
	writel(0x00000008, &dbsc3_0->dbtr1);
	writel(0x00000000, &dbsc3_0->dbtr2);
	writel(0x0000000B, &dbsc3_0->dbtr3);
	writel(0x000C000B, &dbsc3_0->dbtr4);
	writel(0x00000027, &dbsc3_0->dbtr5);
	writel(0x0000001C, &dbsc3_0->dbtr6);
	writel(0x00000005, &dbsc3_0->dbtr7);
	writel(0x00000018, &dbsc3_0->dbtr8);
	writel(0x00000008, &dbsc3_0->dbtr9);
	writel(0x0000000C, &dbsc3_0->dbtr10);
	writel(0x00000009, &dbsc3_0->dbtr11);
	writel(0x00000012, &dbsc3_0->dbtr12);
	writel(0x000000D0, &dbsc3_0->dbtr13);
	writel(0x00140005, &dbsc3_0->dbtr14);
	writel(0x00050004, &dbsc3_0->dbtr15);
	writel(0x70233005, &dbsc3_0->dbtr16);
	writel(0x000C0000, &dbsc3_0->dbtr17);
	writel(0x00000300, &dbsc3_0->dbtr18);
	writel(0x00000040, &dbsc3_0->dbtr19);
	writel(0x00000001, &dbsc3_0->dbrnk0);
	writel(0x00020001, &dbsc3_0->dbadj0);
	writel(0x20082008, &dbsc3_0->dbadj2);
	writel(0x00020002, &dbsc3_0->dbwt0cnf0);
	writel(0x0000000F, &dbsc3_0->dbwt0cnf4);

	writel(0x00000015, &dbsc3_0->dbpdrga);
	writel(0x00000D70, &dbsc3_0->dbpdrgd);

	writel(0x00000016, &dbsc3_0->dbpdrga);
	writel(0x00000006, &dbsc3_0->dbpdrgd);

	writel(0x00000017, &dbsc3_0->dbpdrga);
	writel(0x00000018, &dbsc3_0->dbpdrgd);

	writel(0x00000012, &dbsc3_0->dbpdrga);
	writel(0x9D5CBB66, &dbsc3_0->dbpdrgd);

	writel(0x00000013, &dbsc3_0->dbpdrga);
	writel(0x1A868300, &dbsc3_0->dbpdrgd);

	writel(0x00000023, &dbsc3_0->dbpdrga);
	writel(0x00FDB6C0, &dbsc3_0->dbpdrgd);

	writel(0x00000014, &dbsc3_0->dbpdrga);
	writel(0x300214D8, &dbsc3_0->dbpdrgd);

	writel(0x0000001A, &dbsc3_0->dbpdrga);
	writel(0x930035C7, &dbsc3_0->dbpdrgd);

	writel(0x00000060, &dbsc3_0->dbpdrga);
	writel(0x330657B2, &dbsc3_0->dbpdrgd);

	writel(0x00000011, &dbsc3_0->dbpdrga);
	writel(0x1000040B, &dbsc3_0->dbpdrgd);

	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x00000001, &dbsc3_0->dbpdrga);
	writel(0x00000071, &dbsc3_0->dbpdrgd);

	writel(0x00000004, &dbsc3_0->dbpdrga);
	while ((readl(&dbsc3_0->dbpdrgd) & 0x00000001) != 0x00000001)
		;

	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x2100FA00, &dbsc3_0->dbcmd);
	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x0000FA00, &dbsc3_0->dbcmd);
	writel(0x0000FA00, &dbsc3_0->dbcmd);

	writel(0x110000DB, &dbsc3_0->dbcmd);

	writel(0x00000001, &dbsc3_0->dbpdrga);
	writel(0x00000181, &dbsc3_0->dbpdrgd);

	writel(0x00000004, &dbsc3_0->dbpdrga);
	while ((readl(&dbsc3_0->dbpdrgd) & 0x00000001) != 0x00000001)
		;

	writel(0x00000001, &dbsc3_0->dbpdrga);
	writel(0x0000FE01, &dbsc3_0->dbpdrgd);

	writel(0x00000004, &dbsc3_0->dbpdrga);
	while ((readl(&dbsc3_0->dbpdrgd) & 0x00000001) != 0x00000001)
		;

	writel(0x00000000, &dbsc3_0->dbbs0cnt1);
	writel(0x01004C20, &dbsc3_0->dbcalcnf);
	writel(0x014000AA, &dbsc3_0->dbcaltr);
	writel(0x00000140, &dbsc3_0->dbrfcnf0);
	writel(0x00081860, &dbsc3_0->dbrfcnf1);
	writel(0x00010000, &dbsc3_0->dbrfcnf2);
	writel(0x00000001, &dbsc3_0->dbrfen);
	writel(0x00000001, &dbsc3_0->dbacen);
#endif /* CONFIG_NORFLASH */
}
#endif
#define	SetGuardREG(addr, mask, value)		\
			{ \
				u32 val; \
				val = (readl(addr) & ~(mask)) | (value);	\
				writel(~val, PMMR); \
				writel(val, addr); \
			}


unsigned char buf[512];

#define	MSTPSR7		0xE61501C4
#define	SMSTPCR7	0xE615014C
#define SCIF0_MSTP721	(1 << 21)


int main(int argc, char * argv[]){
    int ret, input;
//    unsigned char buf[512];
	int Count4Printf;
	int len;
  	unsigned long * pBinaryStart = (unsigned long * )0x50000000;
    struct spi_slave *pSpiSlave = NULL;
    struct spi_flash *spi_flash_new;
#ifdef TEST_LED_KOELSCH
    volatile unsigned long *pGP2 = (volatile unsigned long *)GPIO2_VALUE;
#endif
    unsigned long LedFlashCoutner = 10;
unsigned long *pGPSR, pinValue;

#ifdef TEST_LED_KOELSCH
    while(LedFlashCoutner--){
        *pGP2 = 0x55555555;
        somedelay(1);
        *pGP2 = 0xaaaaaaaa;
        somedelay(1);
    }
#endif

#if 0
    while(LedFlashCoutner--){
        GpioOutput(GPIO2_BASE,19,0);
        GpioOutput(GPIO2_BASE,20,0);
        somedelay(1);
        GpioOutput(GPIO2_BASE,19,1);
        GpioOutput(GPIO2_BASE,20,1);
        somedelay(1);
    }
#endif    
	//s_init();

#if 0
	pGPSR = (volatile unsigned long *)PMMR;
	*pGPSR =	0xFFFFFFFF;


/*Setting the GPSR2*/
//	unsigned long *pGPSR = (volatile unsigned long *)GPSR2;
	pGPSR = (volatile unsigned long *)GPSR2;
//	*pGPSR = 0x3BC001E7;
	pinValue = *pGPSR;
	pinValue &= ~((1<<22)|(1<<23));
	pinValue |= ((1<<22)|(1<<23));
	*pGPSR = pinValue;

//0x3BC001E7
	pGPSR = (volatile unsigned long *)IPSR5;
//	*pGPSR = 0x01520000;
	pinValue = *pGPSR;
	pinValue &= ~((1<<17)|(1<<20));
	pinValue |= ((1<<17)|(1<<20));
	*pGPSR = pinValue;
#endif
#if 1
#if 1
	pinValue = readl(MSTPSR7);
	pinValue &= ~SCIF0_MSTP721;
	writel(pinValue, SMSTPCR7);
#endif
SetGuardREG(GPSR2,	0x00000000, 0x0);
SetGuardREG(IPSR5,	0x00000000, 0x01520000);
SetGuardREG(GPSR2,	0x00000000, 0x3BC001E7);

SetGuardREG(GPSR0,	0x00000000, 0xffffffff);
SetGuardREG(GPSR1,	0x00000000, 0x00ec3fff);
SetGuardREG(GPSR3,	0x00000000, 0x5bffffff);
SetGuardREG(GPSR4,	0x00000000, 0x1ffffffb);
SetGuardREG(GPSR5,	0x00000000, 0x1ffffff0);
SetGuardREG(GPSR6,	0x00000000, 0xcf7fffff);

SetGuardREG(IPSR2,	0x00000000, 0x000244c8);
SetGuardREG(IPSR4,	0x00000000, 0x00002400);
SetGuardREG(IPSR6,	0x00000000, 0x00724003);
#endif
somedelay(10);


/*Setting the IPSR*/
//IPSR5	0x01520000
    ret = sh_serial_init();
    somedelay(10);

#if 1
    GpioOutput(LED_GPIO_BASE,LED6,LED_OFF);
    GpioOutput(LED_GPIO_BASE,LED7,LED_OFF);
    GpioOutput(LED_GPIO_BASE,LED8,LED_OFF);

    GpioOutput(LED_GPIO_BASE,LED6,LED_ON);
    sh_serial_putc('A');
    sh_serial_putc('B');
    sh_serial_putc('C');
#endif
    sh_serial_puts("Loader Flasher 1\n");
    //Below cannot be output, for the implement of printf
    //printf("LEDbase=%x\n",0x80000000);
    //printf("LEDbase=%x\n",0x8034c6bf);
    //printf("LEDbase=%d\n",0x8034c6bf);
 //   printf("Please hit a key to continue:\n");
    input = sh_serial_getc();
    printf("input=%c\n",input);
#if 1	
    GpioOutput(LED_GPIO_BASE,LED7,LED_ON);
	//    pSpiSlave = spi_setup_slave(0, 0,0,0);
    
	printf("Test probe..........................\n");
	spi_flash_new = spi_flash_probe(0, 0, 0, 0);
	if (!spi_flash_new) {
		printf("Failed to initialize SPI flash at %u:%u\n", 0, 0);
		return 1;
	}
	for(Count4Printf=0; Count4Printf<512; Count4Printf++){
		buf[Count4Printf] = 0x12;
	}

		printf("Test Read..........................\n");
	ret = spi_flash_read(spi_flash_new, 0, 512, buf);
	if (ret) {
		printf("SPI flash read failed\n");
		return 1;
	}
	udelay(3);
	for(Count4Printf=0; Count4Printf<512;Count4Printf++){
		if(Count4Printf%10==0){
			printf("\n");
		}
		printf("%xH=[%xH] ",Count4Printf,buf[Count4Printf]);

	}
	printf("\n");
#if 0
	for(Count4Printf=0; Count4Printf<512;Count4Printf++){
		if(Count4Printf%10==0){
			printf("\n");
		}
		printf("%xH=[%xH] ",Count4Printf,buf[Count4Printf]);

	}
	printf("\n");
#endif
#if 0
	printf("Test Erase..........................\n");
	ret = spi_flash_erase(spi_flash_new,0,16384);
	if (ret) {
		printf("SPI flash erase failed\n");
		return 1;
	}

	printf("Test Write..........................\n");
	ret = spi_flash_write(spi_flash_new, 0, 16384, pBinaryStart);
	if (ret) {
		printf("SPI flash write failed\n");
		return 1;
	}
#endif

#if 0
	printf("Test Erase..........................\n");
	ret = spi_flash_erase(spi_flash_new,8192,4096);
	if (ret) {
		printf("SPI flash erase failed\n");
		return 1;
	}

	printf("Test Write..........................\n");
	ret = spi_flash_write(spi_flash_new, 8192, 512, buf);
	if (ret) {
		printf("SPI flash write failed\n");
		return 1;
	}
#endif

#if 0
	printf("Test Read..........................\n");
	ret = spi_flash_read(spi_flash_new, 8192, 512, buf);
	if (ret) {
		printf("SPI flash read failed\n");
		return 1;
	}
	udelay(3);
	for(Count4Printf=0; Count4Printf<512;Count4Printf++){
		if(Count4Printf%10==0){
			printf("\n");
		}
		printf("%xH=[%xH] ",Count4Printf,buf[Count4Printf]);

	}
	printf("\n");

	udelay(3);
	printf("Test Read..........................\n");
	ret = spi_flash_read(spi_flash_new, 0, 512, buf);
	if (ret) {
		printf("SPI flash read failed\n");
		return 1;
	}
	for(Count4Printf=0; Count4Printf<512;Count4Printf++){
		if(Count4Printf%10==0){
			printf("\n");
		}
		printf("%xH=[%xH] ",Count4Printf,buf[Count4Printf]);

	}
	printf("\n");
#endif	
#endif
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

#if 0
u8 asc2hex(const u8 *asc)
{
	u8 hex[2];
	u8 out = 0;
	u32 i = 0;

	for (i=0;i<2;i++)
	{
		if ((asc[i]>='0')&&(asc[i]<='9'))
		{
			hex[i] = asc[i]-0x30;
		}

		if((asc[i]>='A')&&(asc[i]<='F'))
		{
			hex[i] = asc[i]-0x37;
		}
	}

	out = hex[0]*16+hex[1];
	return out;
}

int rec2bin(u8 *srec, u32 start_addr, u32 len)
{
	int i = 0;
	u8 frame_lengh = 0;
	int k = 0;
	int j = 0;
	u8 c;

	while (1)
	{
		if (i < len)
		{
			if (srec[i] == 'S')
			{
				switch (srec[i+1])
				{
					case '0':
						frame_lengh = asc2hex(srec+i+2);
						i += frame_lengh*2+4;
						break;
					case '1':
						frame_lengh = asc2hex(srec+i+2);
						for (k=i+8;k<i+8+frame_lengh*2-6;)
						{
							//bin[j++] = asc2hex(srec+k);
							c = asc2hex(srec+k);
							write_flash_sequential(start_addr++, &c, 1);
							k+=2;
						}
						i += frame_lengh*2+4;
						if (((frame_lengh-2-1)%4) != 0)
						{
							c = 0xFF;

							for (j=0;j<(4-((frame_lengh-2-1)%4));j++)
							{
								write_flash_sequential(start_addr++, &c, 1);
							}
						}
						break;
					case '2':
						frame_lengh = asc2hex(srec+i+2);
						for (k=i+10;k<i+10+frame_lengh*2-8;)
						{
							//bin[j++] = asc2hex(srec+k);
							c = asc2hex(srec+k);
							write_flash_sequential(start_addr++, &c, 1);
							k+=2;
						}
						i += frame_lengh*2+4;
						if (((frame_lengh-3-1)%4) != 0)
						{
							c = 0xFF;

							for (j=0;j<(4-((frame_lengh-3-1)%4));j++)
							{
								write_flash_sequential(start_addr++, &c, 1);
							}
						}
						break;
					case '3':
						frame_lengh = asc2hex(srec+i+2);
						for (k=i+12;k<i+12+frame_lengh*2-10;)
						{
							//bin[j++] = asc2hex(srec+k);
							c = asc2hex(srec+k);
							write_flash_sequential(start_addr++, &c, 1);
							k+=2;
						}
						i += frame_lengh*2+4;
						if (((frame_lengh-4-1)%4) != 0)
						{
							c = 0xFF;

							for (j=0;j<(4-((frame_lengh-4-1)%4));j++)
							{
								write_flash_sequential(start_addr++, &c, 1);
							}
						}
						break;
					case '9':
					case '8':
					case '7':
						frame_lengh = asc2hex(srec+i+2);
						i += frame_lengh*2+4;
						i = len+1000;
						break;
					default:
						i = len+1000;
						break;
				}
			}
			else
			{
				i++;
				if(('\n' == srec[i-1]) || ('\r' == srec[i-1])|| (0 == srec[i-1])){
					//serial_puts("Change Line --- [OK]\n");
				}
				else{
					printf("Error Data occurs:[");
					printf(srec[i-1]);
					printf("] --- [NG]\n");

				}
			}
		}
		else
		{
			// serial_puts("srec2bin ok\n");
			//serial_putc(j);
			//return j;
			return start_addr;
		}
	}

}
#endif
