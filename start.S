.global Init_set_WDT
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
    bl main 

/*restore the regs to go back to Uboot  */
    sub sp, fp, #12
    ldmfd sp, {fp, sp, pc}

GoMain:

	LDR		R1, =GoMain
	LDR		PC, [R1]

