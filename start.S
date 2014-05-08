.global Init_set_WDT
Init_set_WDT:
mov ip, sp
stmfd sp!, {fp, ip, lr, pc}
sub fp, ip, #4
	LDR		R0,	=0xe6052008
	LDR		R1, =0xaaaaaaaa	
	STR		R1, [R0]
sub sp, fp, #12
ldmfd sp, {fp, sp, pc}

GoMain:

	LDR		R1, =GoMain
	LDR		PC, [R1]

