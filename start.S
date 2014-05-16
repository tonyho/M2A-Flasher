.INCLUDE "boot_mon_spi.h"
#define 	BOOT_MODE SPI_BOOT

.global Init_set_WDT
.globl _start
_start: b	reset

reset:
Init_set_WDT:
/* store the regs for go back to Uboot */
    mov ip, sp
    stmfd sp!, {fp, ip, lr, pc}
    sub fp, ip, #4

/*Set the LED*/
/*
	LDR		R0,	=0xe6052008
	LDR		R1, =0xaaaaaaaa	
	STR		R1, [R0]
*/
	/*
	 * set the cpu to SVC32 mode
	 */
	mrs r0, cpsr
	bic r0, r0, #0x1f
	orr r0, r0, #0xd3
	msr cpsr,r0

    bl	cpu_init_cp15

	
	@####################################################################################################
	@####		RWDT,secureWDT setting (Timer Disable setting)
	@####################################################################################################
@	Init_set_WDT:
		LDR 	R0, =RWDT_RWTCSRA
		ldr 	r1, =0xA5A5A500 			@#Timer disabled
		STR 	R1, [R0]
	
	Init_set_SECWDT:
		LDR 	R0, =SECWDT_WTCSRA
		LDR 	R1, =0xA5A5A500 			@#Timer  disabled (Enable -> disabled)
		STR 	R1, [R0]
	
	
	@####################################################################################################
	@####		PFC setting
	@####################################################################################################
	Init_set_PFC:
	
	@#-- MOD_SEL set ------------------------------------------------------------------------------------
	Init_set_PFC_MOD_SEL:
	
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x60000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_MOD_SEL
		STR 	R1, [R0]
	
	@#-- MOD_SEL2 set -----------------------------------------------------------------------------------
	Init_set_PFC_MOD_SEL2:
	
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x60000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_MOD_SEL2
		STR 	R1, [R0]
	
	@#-- MOD_SEL3 set -----------------------------------------------------------------------------------
	Init_set_PFC_MOD_SEL3:
	
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00800200
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_MOD_SEL3
		STR 	R1, [R0]
	
	
	
	@#-- MOD_SEL4 set -----------------------------------------------------------------------------------
	Init_set_PFC_MOD_SEL4:
	
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_MOD_SEL4
		STR 	R1, [R0]
	
	
	
	@#-- IPSR set  --------------------------------------------------------------------------------------
	@#-- IPSR0 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR0:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR0
		STR 	R1, [R0]
	
	@#-- IPSR1 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR1:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR1
		STR 	R1, [R0]
	
	@#-- IPSR2 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR2:
		LDR 	R0, =PFC_PMMR
	
	.IF BOOT_MODE == AREA0_BOOT
		LDR 	R1, =0x00000000
	.ENDIF
	
	.IF BOOT_MODE == SPI_BOOT
		LDR 	R1, =0x000244C8
	.ENDIF
	
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR2
		STR 	R1, [R0]
	
	@#-- IPSR3 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR3:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR3
		STR 	R1, [R0]
	
	@#-- IPSR4 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR4:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00002400
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR4
		STR 	R1, [R0]
	
	@#-- IPSR5 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR5:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x01520000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR5
		STR 	R1, [R0]
	
	@#-- IPSR6 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR6:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00724003
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR6
		STR 	R1, [R0]
	
	@#-- IPSR7 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR7:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR7
		STR 	R1, [R0]
	
	@#-- IPSR8 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR8:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR8
		STR 	R1, [R0]
	
	@#-- IPSR9 set --------------------------------------------------------------------------------------
	Init_set_PFC_IPSR9:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR9
		STR 	R1, [R0]
	
	@#-- IPSR10 set -------------------------------------------------------------------------------------
	Init_set_PFC_IPSR10:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR10
		STR 	R1, [R0]
	
	@#-- IPSR11 set -------------------------------------------------------------------------------------
	Init_set_PFC_IPSR11:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR11
		STR 	R1, [R0]
	
	@#-- IPSR12 set -------------------------------------------------------------------------------------
	Init_set_PFC_IPSR12:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR12
		STR 	R1, [R0]
	
	@#-- IPSR13 set -------------------------------------------------------------------------------------
	Init_set_PFC_IPSR13:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR13
		STR 	R1, [R0]
	
	@#-- IPSR14 set -------------------------------------------------------------------------------------
	Init_set_PFC_IPSR14:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR14
		STR 	R1, [R0]
	
	@#-- IPSR15 set -------------------------------------------------------------------------------------
	Init_set_PFC_IPSR15:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR15
		STR 	R1, [R0]
	
	@#-- IPSR16 set -------------------------------------------------------------------------------------
	Init_set_PFC_IPSR16:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00000000
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_IPSR16
		STR 	R1, [R0]
	
	
	@#-- GPSR set  --------------------------------------------------------------------------------------
	@#-- GPSR0 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR0:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0xFFFFFFFF
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR0
		STR 	R1, [R0]
	
	@#-- GPSR1 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR1:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x00EC3FFF
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR1
		STR 	R1, [R0]
	
	@#-- GPSR2 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR2:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x3BC001E7
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR2
		STR 	R1, [R0]
	
	@#-- GPSR3 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR3:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x5BFFFFFF
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR3
		STR 	R1, [R0]
	
	@#-- GPSR4 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR4:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x1FFFFFFB
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR4
		STR 	R1, [R0]
	
	@#-- GPSR5 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR5:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x01BFFFF0
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR5
		STR 	R1, [R0]
	
	@#-- GPSR6 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR6:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0xCF7FFFFF
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR6
		STR 	R1, [R0]
	
	@#-- GPSR7 set --------------------------------------------------------------------------------------
	Init_set_PFC_GPSR7:
		LDR 	R0, =PFC_PMMR
		LDR 	R1, =0x0381FC00
		MVN 	R2, R1
		STR 	R2, [R0]
	
		LDR 	R0, =PFC_GPSR7
		STR 	R1, [R0]
	
	
	@#-- PUPCTL set  ------------------------------------------------------------------------------------
	@#-- PUPCTL0 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL0:
		LDR 	R0, =PFC_PUPR0
	
	.IF BOOT_MODE == AREA0_BOOT
		LDR 	R1, =0x00000000 	@# Area0_boot
	.ENDIF
	
	.IF BOOT_MODE == SPI_BOOT
		LDR 	R1, =0xFFFFFFDF 	@# QSPI_boot
	.ENDIF
	
		STR 	R1, [R0]
	
	@#-- PUPCTL1 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL1:
		LDR 	R0, =PFC_PUPR1
	
	.IF BOOT_MODE == AREA0_BOOT
		LDR 	R1, =0xC8838000 	@# Area0_boot
	.ENDIF
	
	.IF BOOT_MODE == SPI_BOOT
		LDR 	R1, =0xC883C3FF 	@# QSPI_boot
	.ENDIF
	
		STR 	R1, [R0]
	
	
	
	@#-- PUPCTL2 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL2:
		LDR 	R0, =PFC_PUPR2
		LDR 	R1, =0x1201F3C9
		STR 	R1, [R0]
	
	@#-- PUPCTL3 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL3:
		LDR 	R0, =PFC_PUPR3
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- PUPCTL4 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL4:
		LDR 	R0, =PFC_PUPR4
		LDR 	R1, =0xFFFFEB04
		STR 	R1, [R0]
	
	@#-- PUPCTL5 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL5:
		LDR 	R0, =PFC_PUPR5
		LDR 	R1, =0xC003FFFF
		STR 	R1, [R0]
	
	@#-- PUPCTL6 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL6:
		LDR 	R0, =PFC_PUPR6
		LDR 	R1, =0x0800000F
		STR 	R1, [R0]
	
	@#-- PUPCTL7 set ------------------------------------------------------------------------------------
	Init_set_PFC_PUPCTL7:
		LDR 	R0, =PFC_PUPR7
	
	.IF BOOT_MODE == AREA0_BOOT
	@#	LDR 	R1, =0x000000F0 	@# Area0_boot
		LDR 	R1, =0x000800F0 	@# Area0_boot	KOELSCH_SPI Ver0.04   Enable:ASEBRK_N_ACK is pulled down (bit19)
	.ENDIF
	
	.IF BOOT_MODE == SPI_BOOT
	@#	LDR 	R1, =0x001000F0 	@# QSPI_boot
		LDR 	R1, =0x001800F0 	@# QSPI_boot	KOELSCH_SPI Ver0.04   Enable:ASEBRK_N_ACK is pulled down (bit19)
	.ENDIF
	
		STR 	R1, [R0]
	
	
	
	@####		 end PFC setting		#################################################################
	
	
	@####################################################################################################
	@####		output GPIO setting
	@####################################################################################################
	Init_set_GPIO:
	@#-- POSNEGx set  --(POG or NEG) --------------------------------------------------------------------
	@#-- POSNEG1  ---------------------------------------------------------------------------------------
	Init_set_GPIO_POSNEG1:
		LDR 	R0, =GPIO_POSNEG1
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- POSNEG2  ---------------------------------------------------------------------------------------
	Init_set_GPIO_POSNEG2:
		LDR 	R0, =GPIO_POSNEG2
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- POSNEG3  ---------------------------------------------------------------------------------------
	Init_set_GPIO_POSNEG3:
		LDR 	R0, =GPIO_POSNEG3
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- POSNEG4  ---------------------------------------------------------------------------------------
	Init_set_GPIO_POSNEG4:
		LDR 	R0, =GPIO_POSNEG4
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- POSNEG5  ---------------------------------------------------------------------------------------
	Init_set_GPIO_POSNEG5:
		LDR 	R0, =GPIO_POSNEG5
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	@#---------------------------------------------------------------------------------------------------
	
	@#-- POSNEG6  ---------------------------------------------------------------------------------------
	Init_set_GPIO_POSNEG6:
		LDR 	R0, =GPIO_POSNEG6
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	@#---------------------------------------------------------------------------------------------------
	
	@#-- POSNEG7  ---------------------------------------------------------------------------------------
	Init_set_GPIO_POSNEG7:
		LDR 	R0, =GPIO_POSNEG7
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	@#---------------------------------------------------------------------------------------------------
	
	
	@#-- IOINTSELxset --(IN/OUT or INTER)----------------------------------------------------------------
	@#-- IOINTSEL1	-------------------------------------------------------------------------------------
	Init_set_GPIO_IOINTSEL1:
		LDR 	R0, =GPIO_IOINTSEL1
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- IOINTSEL2	-------------------------------------------------------------------------------------
	Init_set_GPIO_IOINTSEL2:
		LDR 	R0, =GPIO_IOINTSEL2
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- IOINTSEL3	-------------------------------------------------------------------------------------
	Init_set_GPIO_IOINTSEL3:
		LDR 	R0, =GPIO_IOINTSEL3
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- IOINTSEL4	-------------------------------------------------------------------------------------
	Init_set_GPIO_IOINTSEL4:
		LDR 	R0, =GPIO_IOINTSEL4
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- IOINTSEL5	-------------------------------------------------------------------------------------
	Init_set_GPIO_IOINTSEL5:
		LDR 	R0, =GPIO_IOINTSEL5
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- IOINTSEL6	-------------------------------------------------------------------------------------
	Init_set_GPIO_IOINTSEL6:
		LDR 	R0, =GPIO_IOINTSEL6
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- IOINTSEL7	-------------------------------------------------------------------------------------
	Init_set_GPIO_IOINTSEL7:
		LDR 	R0, =GPIO_IOINTSEL7
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	@#---------------------------------------------------------------------------------------------------
	
	@#-- OUTDTxset --------------------------------------------------------------------------------------
	@#-- OUTDT2  ----------------------------------------------------------------------------------------
	Init_set_GPIO_OUTDT2:
		LDR 	R0, =GPIO_OUTDT2
		LDR 	R1, =0x04381000
	
		STR 	R1, [R0]
	
	@#-- OUTDT5  ----------------------------------------------------------------------------------------
	Init_set_GPIO_OUTDT5:
		LDR 	R0, =GPIO_OUTDT5
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- OUTDT7  ----------------------------------------------------------------------------------------
	Init_set_GPIO_OUTDT7:
		LDR 	R0, =GPIO_OUTDT7
		LDR 	R1, =0x000E0000
		STR 	R1, [R0]
	@#---------------------------------------------------------------------------------------------------
	
	
	@#-- INOUTSELxset --(IN or OUT)----------------------------------------------------------------------
	@#-- INOUTSEL1	-------------------------------------------------------------------------------------
	Init_set_GPIO_INOUTSEL1:
		LDR 	R0, =GPIO_INOUTSEL1
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- INOUTSEL2	-------------------------------------------------------------------------------------
	Init_set_GPIO_INOUTSEL2:
		LDR 	R0, =GPIO_INOUTSEL2
		LDR 	R1, =0x04381010
	
		STR 	R1, [R0]
	
	@#-- INOUTSEL3	-------------------------------------------------------------------------------------
	Init_set_GPIO_INOUTSEL3:
		LDR 	R0, =GPIO_INOUTSEL3
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- INOUTSEL4	-------------------------------------------------------------------------------------
	Init_set_GPIO_INOUTSEL4:
		LDR 	R0, =GPIO_INOUTSEL4
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- INOUTSEL5	-------------------------------------------------------------------------------------
	Init_set_GPIO_INOUTSEL5:
		LDR 	R0, =GPIO_INOUTSEL5
		LDR 	R1, =0x00400000
		STR 	R1, [R0]
	
	@#-- INOUTSEL6	-------------------------------------------------------------------------------------
	Init_set_GPIO_INOUTSEL6:
		LDR 	R0, =GPIO_INOUTSEL6
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
	
	@#-- INOUTSEL7	-------------------------------------------------------------------------------------
	Init_set_GPIO_INOUTSEL7:
		LDR 	R0, =GPIO_INOUTSEL7
		LDR 	R1, =0x000E0380
		STR 	R1, [R0]
	
	@#---------------------------------------------------------------------------------------------------
	
	
	@####		end Output GPIO  setting	#############################################################
	
	
	
	@####################################################################################################
	@####		CPG , RST_WDt setting  (Module Reset setting)
	@####################################################################################################
	Init_set_CPG:
	
	@####		end CPG setting 	#####################################################################
	
	
	
	
	@####################################################################################################
	@#####	LBSC setting
	@####################################################################################################
	Init_set_LBSC:
	Init_set_LBSC_CS:
		LDR 	R0, =LBSC_CS0CTRL
		LDR 	R1, =0x00000020 			@# CS0: I/F=SRAM
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_CS1CTRL
		LDR 	R1, =0x00000020 			@# CS1: width=16bit , I/F=SRAM
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECS0CTRL
		LDR 	R1, =0x00002020 			@# EXCS0: CP=32MB , width=16bit , I/F=SRAM
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECS1CTRL
		LDR 	R1, =0x00002020 			@# EXCS1: CP=32MB , width=16bit , I/F=SRAM
		STR 	R1, [R0]
	
	@#---------------------------------------------------------------------------------------------------
	Init_set_LBSC_CSWCR:
		LDR 	R0, =LBSC_CSWCR0
	@#	LDR 	R1, =0xFF70FF70 			@# WRPulse=31,WRS=7,WRH=7 / RDPulse=31,RDS=7,RDH=7	(initial value)
		LDR 	R1, =0x2A103320 			@# WRPulse=5, WRS=2,WRH=1 / RDPulse=6, RDS=3,RDH=2	@# KOELSCH			//KOELSCH_SPI Ver0.02
	@#	LDR 	R1, =0x02150326 			@# WRS=2,WRH=1,WRPulse=5  / RDS=3,RDH=2,RDPulse=6	@# LAGER Ver0.12
	@#	LDR 	R1, =0x02140326 			@# WRS=2,WRH=1,WRPulse=4  / RDS=3,RDH=2,RDPulse=6	@# MARZEN
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_CSWCR1
	@#	LDR 	R1, =0xFF70FF70 			@# WRPulse=31,WRS=7,WRH=7 / RDPulse=31,RDS=7,RDH=7	(initial value)
		LDR 	R1, =0x2A103320 			@# WRPulse=5, WRS=2,WRH=1 / RDPulse=6, RDS=3,RDH=2	@# KOELSCH			//KOELSCH_SPI Ver0.02
	@#	LDR 	R1, =0x02150326 			@# WRS=2,WRH=1,WRPulse=5 / RDS=3,RDH=2,RDPulse=6	@# LAGER Ver0.12
	@#	LDR 	R1, =0x02140326 			@# WRS=2,WRH=1,WRPulse=4 / RDS=3,RDH=2,RDPulse=6	@# MARZEN
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECSWCR0
		LDR 	R1, =0xFF70FF70 			@# WRPulse=31,WRS=7,WRH=7 / RDPulse=31,RDS=7,RDH=7	(initial value)
	@#	LDR 	R1, =0x077F077F 			@# WRS=7,WRH=7,WRPulse=15 / RDS=7,RDH=7,RDPulse=15 (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECSWCR1
		LDR 	R1, =0xFF70FF70 			@# WRPulse=31,WRS=7,WRH=7 / RDPulse=31,RDS=7,RDH=7	(initial value)
	@#	LDR 	R1, =0x077F077F 			@# WRS=7,WRH=7,WRPulse=15 / RDS=7,RDH=7,RDPulse=15 (initial value)
		STR 	R1, [R0]
	
	@#---------------------------------------------------------------------------------------------------
	Init_set_LBSC_CSPWCR:
		LDR 	R0, =LBSC_CSPWCR0
		LDR 	R1, =0x00000000 			@# Wait_set:Disable (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_CSPWCR1
		LDR 	R1, =0x00000000 			@# Wait_set:Disable (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECSPWCR0
		LDR 	R1, =0x00000000 			@# Wait_set:Disable (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECSPWCR1
		LDR 	R1, =0x00000000 			@# Wait_set:Disable (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_EXWTSYNC
		LDR 	R1, =0x00000000 			@# Wait_set:Disable (initial value)
		STR 	R1, [R0]
	
	@#---------------------------------------------------------------------------------------------------
	Init_set_LBSC_CSGDST:
		LDR 	R0, =LBSC_CS1GDST
		LDR 	R1, =0x00000000 			@# Timer_set:Disable (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECS0GDST
		LDR 	R1, =0x00000000 			@# Timer_set:Disable (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ECS1GDST
		LDR 	R1, =0x00000000 			@# Timer_set:Disable (initial value)
		STR 	R1, [R0]
	
		LDR 	R0, =LBSC_ATACSCTRL
		LDR 	R1, =0x00000000 			@# ATACS:Disable (initial value)
		STR 	R1, [R0]
	
	@####		end LBSC setting	#####################################################################
	
	
	
	@####################################################################################################
	@#####		DDR Setting
	@####################################################################################################
	
	Init_set_DDR:
	Init_set_DDR_wait00:
		LDR 	R0, =100000
	
	Init_set_DDR_wait00_loop:
		SUBS	R0,R0,#1
		BNE 	Init_set_DDR_wait00_loop
	
	@# --------------------------------------------------------------------------------------------------
	@####		START DDR1600(800MHz) setting	#########################################################
	@# --------------------------------------------------------------------------------------------------
	
	Init_DDR1600:
	@#(1)	(a)After power is turned on, apply a power-on reset and wait until the DBSC3 is released from the reset state.
	@#(1)-1.Here, the setting on the M0/1RESET# signals should be executed (The following 3 lines correspond to this setting):
	@#(1)-1-1�ｿｽEWrite H�ｿｽf21000000 to the manual command-issuing register (DBCMD).
	Init_DDR1600_1_1_1:
		LDR 	R0, =DBSC3_0_DBCMD
		LDR 	R2, =DBSC3_1_DBCMD
		LDR 	R1, =0x21000000 	@# opc=RstH(RESET => H)
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(1)-1-2�ｿｽEWrite H�ｿｽf11000000 to the manual command-issuing register (DBCMD).
	Init_DDR1600_1_1_2:
		LDR 	R0, =DBSC3_0_DBCMD
		LDR 	R2, =DBSC3_1_DBCMD
		LDR 	R1, =0x11000000 	@# opc==PDXt(CKE=H)
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(1)-1-3�ｿｽEWrite H�ｿｽf10000000 to the manual command-issuing register (DBCMD).
	Init_DDR1600_1_1_3:
		LDR 	R0, =DBSC3_0_DBCMD
		LDR 	R2, =DBSC3_1_DBCMD
		LDR 	R1, =0x10000000 	@# opc=PDEn(CKE=L)
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	
	@#(1)-2.After release from the reset state, set the registers as follows:
	@#(1)-2-1 Write H�ｿｽf0000A55A to the PHY unit lock register (DBPDLCK).
	Init_DDR1600_1_2_1:
		LDR 	R0, =DBSC3_0_DBPDLCK
		LDR 	R2, =DBSC3_1_DBPDLCK
		LDR 	R1, =0x0000A55A
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	
	
	@# KOELSCH_SPI Ver0.03	Add ES1 Setting
	@#====================================================================================================
	.IF DBSC3_ADDPHY_SET == YES
	@#====================================================================================================
	@#(5) (E)Additional PHY Setting --------------------------------------------------------------------
	
	@#(5)-5.	Write H�ｿｽf00000010 to the PHY unit address register (DBPDRGA).
	Init_DDR1600_5_5:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000010
		STR 	R1, [R0]
		STR 	R1, [R2]
	@#(5)-6.	Write H�ｿｽfF004649B to the PHY unit access register (DBPDRGD).
	Init_DDR1600_5_6:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0xF004649B
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#====================================================================================================
	.ENDIF
	@#====================================================================================================
	
	
	
	@#(2)  (b)DBSC3 Setting 1-----------------------------------------------------------------------------
	@#(2)-1 �ｿｽESDRAM�ｿｽ�ｿｽﾞ�ﾝ�����ｿｽW�ｿｽX�ｿｽ^�ｿｽiDBKIND�ｿｽj
	Init_DDR1600_2_1:
		LDR 	R0, =DBSC3_0_DBKIND
		LDR 	R2, =DBSC3_1_DBKIND
		LDR 	R1, =0x00000007 	@# bit[2:0]=b'111 DDR3-SDRAM
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-2 �ｿｽESDRAM�ｿｽ\�ｿｽ�ｿｽ�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^0�ｿｽiDBCONF0�ｿｽj
	Init_DDR1600_2_2:
		LDR 	R0, =DBSC3_0_DBCONF0
		LDR 	R2, =DBSC3_1_DBCONF0
	@#	LDR 	R1, =0x10030A02 	@# RowAd=16,Bank=8,CoulumAd=10
		LDR 	R1, =0x0F030A02 	@# RowAd=15,Bank=8,CoulumAd=10	  <32Bit x 2ch Mode>
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_2_3:
	@#(2)-3 �ｿｽEPHY�ｿｽ�ｿｽﾞ�ﾝ�����ｿｽW�ｿｽX�ｿｽ^(DBPHYTYPE)
		LDR 	R0, =DBSC3_0_DBPHYTYPE
		LDR 	R2, =DBSC3_1_DBPHYTYPE
		LDR 	R1, =0x00000001 	@# bit[1:0]=b'01 DFI
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-4 �ｿｽESDRAM�ｿｽ�ｿｽ�ｿｽ�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^(DBBL)
	Init_DDR1600_2_4:
		LDR 	R0, =DBSC3_0_DBBL
		LDR 	R2, =DBSC3_1_DBBL
		LDR 	R1, =0x00000000 	@# bit[1:0]=b'00 BL=8
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽ@�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^0 �ｿｽiDBTR0�ｿｽj
	Init_DDR1600_2_5_1:
		LDR 	R0, =DBSC3_0_DBTR0
		LDR 	R2, =DBSC3_1_DBTR0
		LDR 	R1, =0x0000000B 	@# CL=11
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽA�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^1 �ｿｽiDBTR1�ｿｽj
	Init_DDR1600_2_5_2:
		LDR 	R0, =DBSC3_0_DBTR1
		LDR 	R2, =DBSC3_1_DBTR1
		LDR 	R1, =0x00000008 	@# CWL=8
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽB�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^2 �ｿｽiDBTR2�ｿｽj
	Init_DDR1600_2_5_3:
		LDR 	R0, =DBSC3_0_DBTR2
		LDR 	R2, =DBSC3_1_DBTR2
		LDR 	R1, =0x00000000 	@# AL=0
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽC�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^3 �ｿｽiDBTR3�ｿｽj
	Init_DDR1600_2_5_4:
		LDR 	R0, =DBSC3_0_DBTR3
		LDR 	R2, =DBSC3_1_DBTR3
		LDR 	R1, =0x0000000B 	@# TRCD=11
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽD�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^4 �ｿｽiDBTR4�ｿｽj
	Init_DDR1600_2_5_5:
		LDR 	R0, =DBSC3_0_DBTR4
		LDR 	R2, =DBSC3_1_DBTR4
		LDR 	R1, =0x000C000B 	@# TRPA=12,TRP=11
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽE�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^5 �ｿｽiDBTR5�ｿｽj
	Init_DDR1600_2_5_6:
		LDR 	R0, =DBSC3_0_DBTR5
		LDR 	R2, =DBSC3_1_DBTR5
		LDR 	R1, =0x00000027 	@# TRC=39
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽF�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^6 �ｿｽiDBTR6�ｿｽj
	Init_DDR1600_2_5_7:
		LDR 	R0, =DBSC3_0_DBTR6
		LDR 	R2, =DBSC3_1_DBTR6
		LDR 	R1, =0x0000001C 	@# TRAS=28
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽG�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^7 �ｿｽiDBTR7�ｿｽj
	Init_DDR1600_2_5_8:
		LDR 	R0, =DBSC3_0_DBTR7
		LDR 	R2, =DBSC3_1_DBTR7
	@#	LDR 	R1, =0x00000005 	@# TRRD=5
		LDR 	R1, =0x00000006 	@# TRRD=6	 <32Bit x 2ch Mode>
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽH�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^8 �ｿｽiDBTR8�ｿｽj
	Init_DDR1600_2_5_9:
		LDR 	R0, =DBSC3_0_DBTR8
		LDR 	R2, =DBSC3_1_DBTR8
	@#	LDR 	R1, =0x00000018 	@# TFAW=24
		LDR 	R1, =0x00000020 	@# TFAW=32	 <32Bit x 2ch Mode>
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽI�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^9 �ｿｽiDBTR9�ｿｽj
	Init_DDR1600_2_5_10:
		LDR 	R0, =DBSC3_0_DBTR9
		LDR 	R2, =DBSC3_1_DBTR9
		LDR 	R1, =0x00000008 	@# TRDPR=8
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽJ�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^10�ｿｽiDBTR10�ｿｽj
	Init_DDR1600_2_5_11:
		LDR 	R0, =DBSC3_0_DBTR10
		LDR 	R2, =DBSC3_1_DBTR10
		LDR 	R1, =0x0000000C 	@# TWR=12
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽK�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^11�ｿｽiDBTR11�ｿｽj
	Init_DDR1600_2_5_12:
		LDR 	R0, =DBSC3_0_DBTR11
		LDR 	R2, =DBSC3_1_DBTR11
		LDR 	R1, =0x00000009 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽL�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^12�ｿｽiDBTR12�ｿｽj
	Init_DDR1600_2_5_13:
		LDR 	R0, =DBSC3_0_DBTR12
		LDR 	R2, =DBSC3_1_DBTR12
		LDR 	R1, =0x00000012 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽM�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^13�ｿｽiDBTR13�ｿｽj
	Init_DDR1600_2_5_14:
		LDR 	R0, =DBSC3_0_DBTR13
		LDR 	R2, =DBSC3_1_DBTR13
		LDR 	R1, =0x000000D0 	@# TRFC=208
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽN�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^14�ｿｽiDBTR14�ｿｽj
	Init_DDR1600_2_5_15:
		LDR 	R0, =DBSC3_0_DBTR14
		LDR 	R2, =DBSC3_1_DBTR14
		LDR 	R1, =0x00140005 	@# TCKEH DLL=20   TCKEH=5
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽO�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^15�ｿｽiDBTR15�ｿｽj
	Init_DDR1600_2_5_16:
		LDR 	R0, =DBSC3_0_DBTR15
		LDR 	R2, =DBSC3_1_DBTR15
		LDR 	R1, =0x00050004 	@# TCKESR=5  TCKEL=4
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽP�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^16�ｿｽiDBTR16�ｿｽj
	Init_DDR1600_2_5_17:
		LDR 	R0, =DBSC3_0_DBTR16
		LDR 	R2, =DBSC3_1_DBTR16
	@#	LDR 	R1, =0x70234006 	@#
		LDR 	R1, =0x70233005 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽQ�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^17�ｿｽiDBTR17�ｿｽj
	Init_DDR1600_2_5_18:
		LDR 	R0, =DBSC3_0_DBTR17
		LDR 	R2, =DBSC3_1_DBTR17
		LDR 	R1, =0x000C0000 	@# TMOD=12
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽR�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^18�ｿｽiDBTR18�ｿｽj
	Init_DDR1600_2_5_19:
		LDR 	R0, =DBSC3_0_DBTR18
		LDR 	R2, =DBSC3_1_DBTR18
	@#	LDR 	R1, =0x00000200 	@# WODT BL/2+2
		LDR 	R1, =0x00000300 	@# DEBUG
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-5-�ｿｽS�ｿｽESDRAM�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^19�ｿｽiDBTR19�ｿｽj
	Init_DDR1600_2_5_20:
		LDR 	R0, =DBSC3_0_DBTR19
		LDR 	R2, =DBSC3_1_DBTR19
		LDR 	R1, =0x00000040 	@# TZQCS 64
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-6 �ｿｽEODT�ｿｽ�ｿｽ�ｿｽ�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^0 (DBRNK0)
	Init_DDR1600_2_6:
		LDR 	R0, =DBSC3_0_DBRNK0
		LDR 	R2, =DBSC3_1_DBRNK0
		LDR 	R1, =0x00000001 	@# ODT Output Level (Read=0 Low  Write=1 High)
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-7�ｿｽ]�ｿｽ@�ｿｽEDBSC�ｿｽ�ｿｽ�ｿｽ��ｲ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^0(DBADJ0)
	Init_DDR1600_2_7_1:
		LDR 	R0, =DBSC3_0_DBADJ0
		LDR 	R2, =DBSC3_1_DBADJ0
		LDR 	R1, =0x00020001 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-7�ｿｽ]�ｿｽA�ｿｽEDBSC�ｿｽ�ｿｽ�ｿｽ��ｲ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^2(DBADJ2)
	Init_DDR1600_2_7_2:
		LDR 	R0, =DBSC3_0_DBADJ2
		LDR 	R2, =DBSC3_1_DBADJ2
		LDR 	R1, =0x20082008 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(2)-8�ｿｽ]�ｿｽ@�ｿｽEAXI�ｿｽ|�ｿｽ[�ｿｽg0�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^0(DBWT0CNF0)
	Init_DDR1600_2_8_1:
		LDR 	R0, =DBSC3_0_DBWT0CNF0
		LDR 	R2, =DBSC3_1_DBWT0CNF0
		LDR 	R1, =0x00020002 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#Init_DDR1600_2_8_1_1:
	@#	LDR 	R0, =DBSC3_0_DBWT0CNF2
	@#	LDR 	R1, =0x00000000 	@# out of order(�ｿｽ�ｿｽ�ｿｽ�ｿｽl)
	@#	STR 	R1, [R0]
	
	@#(2)-8�ｿｽ]�ｿｽA�ｿｽEAXI�ｿｽ|�ｿｽ[�ｿｽg0�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^4(DBWT0CNF4)
	Init_DDR1600_2_8_2:
		LDR 	R0, =DBSC3_0_DBWT0CNF4
		LDR 	R2, =DBSC3_1_DBWT0CNF4
	@#	LDR 	R1, =0x0000000F 	@# RDFIFO 16(1ch mode)
		LDR 	R1, =0x0000001F 	@# RDFIFO 32(2ch mode)		<32Bit x 2ch Mode>
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	
	@#(3)  (c)	PHY Setting 1---------------------------------------------------------------------------
	@#(3)-(1)	DBDFISTAT�ｿｽﾌ��ｿｽ�ｿｽW�ｿｽX�ｿｽ^�ｿｽ�ｿｽread�ｿｽ�ｿｽ�ｿｽ�ｿｽINITCOMPL (bit0)�ｿｽﾉ�h1�ｿｽh�ｿｽ�ｿｽread�ｿｽ�ｿｽ�ｿｽ�ｿｽ��ｱ�ｿｽﾆ��ｿｽ�ｿｽm�ｿｽF�ｿｽ�ｿｽ�ｿｽﾜ��ｿｽ�ｿｽB�ｿｽg1�ｿｽh�ｿｽ�ｿｽread�ｿｽ�ｿｽ�ｿｽ�ｿｽ����ｿｽﾔ�ﾉ�ﾈ��ｿｽ�ｿｽRESET#�ｿｽ[�ｿｽq�ｿｽ�ｿｽLow�ｿｽﾉ�ﾈ��ｿｽﾜ��ｿｽ�ｿｽB
	@#Init_DDR1600_3_1:
	Init_DDR1600_3_1_0:
		LDR 	R0, =DBSC3_0_DBDFISTAT
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_1_0	@# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	
	Init_DDR1600_3_1_1:
		LDR 	R0, =DBSC3_1_DBDFISTAT
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_1_1	@# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	
	
	Init_DDR1600_3_2:
		LDR 	R0, =DBSC3_0_DBDFICNT
		LDR 	R2, =DBSC3_1_DBDFICNT
		LDR 	R1, =0x00000011 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_3:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000006
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_4:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x0001C000 	@#	DDR1600
	@	LDR 	R1, =0x0005C000 	@#	DDR1333
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_5:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000003
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_6:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x0300C481
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_7:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000023
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_8:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
	@#	LDR 	R1, =0x00FD2480
		LDR 	R1, =0x00FDB6C0
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_9:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000011
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_10:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x1000040B
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_11:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000012
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_12:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
	@#	LDR 	R1, =0x9D5CBB66 	@
		LDR 	R1, =0x9D9CBB66 	@
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_13:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000013
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_14:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
	@#	LDR 	R1, =0x1A868300 	@
		LDR 	R1, =0x1A868400 	@
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_15:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000014
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_16:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x300214D8 	@
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_17:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000015
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_18:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x00000D70 	@#[31:16]=0 ,[15:0]=MR0
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_19:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000016
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_20:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x00000006 	@#[31:16]=0 ,[15:0]=MR1
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_21:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000017
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_22:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x00000018 	@#[31:16]=0 ,[15:0]=MR2
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_23:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x0000001A
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_24:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
	@#	LDR 	R1, =0x930035C7
		LDR 	R1, =0x910035C7
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_25:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000004
		STR 	R1, [R0]
		STR 	R1, [R2]
	@#Init_DDR1600_3_26:
	Init_DDR1600_3_26_0:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_26_0 @# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	Init_DDR1600_3_26_1:
		LDR 	R0, =DBSC3_1_DBPDRGD
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_26_1 @# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	
	
	
	Init_DDR1600_3_27:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000001
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_28:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x00000181 	@
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(3)-29	�ｿｽE�ｿｽ��ｮ�ｿｽR�ｿｽ}�ｿｽ�ｿｽ�ｿｽh�ｿｽ�ｿｽ�ｿｽs�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^�ｿｽiDBCMD�ｿｽj�ｿｽﾉ��ｿｽ�ｿｽSDRAM�ｿｽ�ｿｽCKE�ｿｽ[�ｿｽq�ｿｽ�ｿｽHigh�ｿｽﾉ��ｿｽ�ｿｽﾜ��ｿｽ�ｿｽB
	Init_DDR1600_3_29:
		LDR 	R0, =DBSC3_0_DBCMD
		LDR 	R2, =DBSC3_1_DBCMD
	@#	LDR 	R1, =0x110000DB 	@# opc=PDXt, arg=270ns
		LDR 	R1, =0x11000000 	@# opc=PDXt
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_30:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000004
		STR 	R1, [R0]
		STR 	R1, [R2]
	@#Init_DDR1600_3_31:
	Init_DDR1600_3_31_0:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_31_0 @# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	Init_DDR1600_3_31_1:
		LDR 	R0, =DBSC3_1_DBPDRGD
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_31_1 @# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	
	
	
	Init_DDR1600_3_32:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000001
		STR 	R1, [R0]
		STR 	R1, [R2]
	Init_DDR1600_3_33:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R2, =DBSC3_1_DBPDRGD
		LDR 	R1, =0x0000FE01
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_3_34:
		LDR 	R0, =DBSC3_0_DBPDRGA
		LDR 	R2, =DBSC3_1_DBPDRGA
		LDR 	R1, =0x00000004
		STR 	R1, [R0]
		STR 	R1, [R2]
	@#Init_DDR1600_3_35:
	Init_DDR1600_3_35_0:
		LDR 	R0, =DBSC3_0_DBPDRGD
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_35_0 @# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	Init_DDR1600_3_35_1:
		LDR 	R0, =DBSC3_1_DBPDRGD
		LDR 	R1, [R0]			@# R1 = Read Data
		TST 	R1, #0x00000001 	@# Bit0�ｿｽ�ｿｽ"0"�ｿｽ�ｿｽ�ｿｽﾇ��ｿｽ�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽ�ｿｽ�ｿｽ	[ R1 & H'1 -> 0�ｿｽﾌ����:Zeroflag=1 , 1�ｿｽﾌ����:Zeroflag=0 ]
		BEQ 	Init_DDR1600_3_35_1 @# Bit0�ｿｽ�ｿｽ"0"(Z=1)�ｿｽﾌ�����ｿｽ�ｿｽ�ｿｽ[�ｿｽv    [ BEQ [Z=1�ｿｽﾌ��ｿｽ]	 ,BNE [Z=0�ｿｽﾌ��ｿｽ] ]
	
	
	
	@#(4)  (d)	DBSC Setting 2--------------------------------------------------------------------------
	@#(4)-1 �ｿｽE�ｿｽo�ｿｽX�ｿｽ�ｿｽ�ｿｽ���0�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^1 (DBBS0CNT1)
	Init_DDR1600_4_1:
		LDR 	R0, =DBSC3_0_DBBS0CNT1
		LDR 	R2, =DBSC3_1_DBBS0CNT1
		LDR 	R1, =00000000		@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(4)-2 �ｿｽEDDR3-SDRAM�ｿｽL�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽu�ｿｽ�ｿｽ�ｿｽ[�ｿｽV�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^(DBCALCNF)
	Init_DDR1600_4_2:
		LDR 	R0, =DBSC3_0_DBCALCNF
		LDR 	R2, =DBSC3_1_DBCALCNF
		LDR 	R1, =0x01004C20 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(4)-3 �ｿｽEDDR3-SDRAM�ｿｽL�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽu�ｿｽ�ｿｽ�ｿｽ[�ｿｽV�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ^�ｿｽC�ｿｽ~�ｿｽ�ｿｽ�ｿｽO�ｿｽ�ｿｽ�ｿｽW�ｿｽX�ｿｽ^(DBCALTR)
	Init_DDR1600_4_3:
		LDR 	R0, =DBSC3_0_DBCALTR
		LDR 	R2, =DBSC3_1_DBCALTR
		LDR 	R1, =0x014000AA 	@#
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(4)-4-�ｿｽ@�ｿｽE�ｿｽ�ｿｽ�ｿｽt�ｿｽ�ｿｽ�ｿｽb�ｿｽV�ｿｽ�ｿｽ�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^0�ｿｽiDBRFCNF0�ｿｽj
	Init_DDR1600_4_4_1:
		LDR 	R0, =DBSC3_0_DBRFCNF0
		LDR 	R2, =DBSC3_1_DBRFCNF0
		LDR 	R1, =0x00000140 	@# 320Cycle
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(4)-4-�ｿｽA�ｿｽE�ｿｽ�ｿｽ�ｿｽt�ｿｽ�ｿｽ�ｿｽb�ｿｽV�ｿｽ�ｿｽ�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^1�ｿｽiDBRFCNF1�ｿｽj
	Init_DDR1600_4_4_2:
		LDR 	R0, =DBSC3_0_DBRFCNF1
		LDR 	R2, =DBSC3_1_DBRFCNF1
		LDR 	R1, =0x00081860 	@# REFFPMAX=8,REFINT=6240Cycle 800MHz
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(4)-4-�ｿｽB�ｿｽE�ｿｽ�ｿｽ�ｿｽt�ｿｽ�ｿｽ�ｿｽb�ｿｽV�ｿｽ�ｿｽ�ｿｽﾝ�����ｿｽW�ｿｽX�ｿｽ^2�ｿｽiDBRFCNF2�ｿｽj
	Init_DDR1600_4_4_3:
		LDR 	R0, =DBSC3_0_DBRFCNF2
		LDR 	R2, =DBSC3_1_DBRFCNF2
		LDR 	R1, =0x00010000 	@# REFINT = 1/1
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(4)-5 �ｿｽE�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽt�ｿｽ�ｿｽ�ｿｽb�ｿｽV�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽﾂ��ｿｽ�ｿｽW�ｿｽX�ｿｽ^�ｿｽiDBRFEN�ｿｽj�ｿｽ�ｿｽARFEN�ｿｽr�ｿｽb�ｿｽg�ｿｽ�ｿｽ1�ｿｽﾉ�ﾝ���ｵ�ｿｽﾜ��ｿｽ�ｿｽB
	Init_DDR1600_4_5:
		LDR 	R0, =DBSC3_0_DBRFEN
		LDR 	R2, =DBSC3_1_DBRFEN
		LDR 	R1, =0x00000001 	@# AREF=Enable
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	@#(4)-6 �ｿｽESDRAM�ｿｽA�ｿｽN�ｿｽZ�ｿｽX�ｿｽ�ｿｽ�ｿｽﾂ��ｿｽ�ｿｽW�ｿｽX�ｿｽ^�ｿｽiDBACEN�ｿｽj�ｿｽ�ｿｽACCEN�ｿｽr�ｿｽb�ｿｽg�ｿｽ�ｿｽ1�ｿｽi�ｿｽA�ｿｽN�ｿｽZ�ｿｽX�ｿｽ�ｿｽ�ｿｽﾂ�j�ｿｽﾉ�ﾝ���ｵ�ｿｽﾜ��ｿｽ�ｿｽB
	Init_DDR1600_4_6:
		LDR 	R0, =DBSC3_0_DBACEN
		LDR 	R2, =DBSC3_1_DBACEN
		LDR 	R1, =0x00000001 	@# ACCEN=Enable
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	Init_DDR1600_4_7:
		LDR 	R0, =DBSC3_0_DBPDLCK
		LDR 	R2, =DBSC3_1_DBPDLCK
		LDR 	R1, =0x00000000
		STR 	R1, [R0]
		STR 	R1, [R2]
	
	
	@#Init_DDR1600_end:
	@#	LDR 	R0, =DBSC3_0_DBWAIT
	@#	LDR 	R1, [R0]			@# READ (WAIT)
	
	
	@# --------------------------------------------------------------------------------------------------
	@####		END DDR1600(800MHz) setting #########################################################
	@# --------------------------------------------------------------------------------------------------
		B		Init_set_DDR_END
	
	 .pool
	
	
	Init_set_DDR_END:
	@####	 end DDR Setting		####################################################################
	
	
	
	
	
	@####################################################################################################
	@####		S3CTRL setting (DDR0,1�ｿｽA�ｿｽh�ｿｽ�ｿｽ�ｿｽX�ｿｽ�ｿｽ�ｿｽ �ｿｽA�ｿｽ�ｿｽ�ｿｽﾌ��ｿｽA�ｿｽN�ｿｽZ�ｿｽX�ｿｽﾝ��ｿｽ)
	@####################################################################################################
	Init_set_S3CTRL:
		LDR 	R0, =S3CTRL_S3CMAAR
		LDR 	R1, =0x0000000C 			@#�ｿｽ�ｿｽ�ｿｽ�ｿｽl�ｿｽ�ｿｽ0x04080000
		STR 	R1, [R0]

	ldr r3, =0xe633fff0
	sub sp, r3, #4

    bl main 

/*restore the regs to go back to Uboot  */
    sub sp, fp, #12
    ldmfd sp, {fp, sp, pc}

GoMain:

	LDR		R1, =GoMain
	LDR		PC, [R1]

/*************************************************************************
 *
 * cpu_init_cp15
 *
 * Setup CP15 registers (cache, MMU, TLBs). The I-cache is turned on unless
 * CONFIG_SYS_ICACHE_OFF is defined.
 *
 *************************************************************************/
cpu_init_cp15:
	/*
	 * Invalidate L1 I/D
	 */
	mov r0, #0			@ set up for MCR
	mcr p15, 0, r0, c8, c7, 0	@ invalidate TLBs
	mcr p15, 0, r0, c7, c5, 0	@ invalidate icache
	mcr p15, 0, r0, c7, c5, 6	@ invalidate BP array
	mcr 	p15, 0, r0, c7, c10, 4	@ DSB
	mcr 	p15, 0, r0, c7, c5, 4	@ ISB

	/*
	 * disable MMU stuff and caches
	 */
	mrc p15, 0, r0, c1, c0, 0
	bic r0, r0, #0x00002000 @ clear bits 13 (--V-)
	bic r0, r0, #0x00000007 @ clear bits 2:0 (-CAM)
	orr r0, r0, #0x00000002 @ set bit 1 (--A-) Align
	orr r0, r0, #0x00000800 @ set bit 11 (Z---) BTB
#ifdef CONFIG_SYS_ICACHE_OFF
	bic r0, r0, #0x00001000 @ clear bit 12 (I) I-cache
#else
	orr r0, r0, #0x00001000 @ set bit 12 (I) I-cache
#endif
	mcr p15, 0, r0, c1, c0, 0
	mov pc, lr			@ back to my caller

	
