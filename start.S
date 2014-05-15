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

	
