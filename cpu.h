//Last date modified 2013.06.07

//#### スタックポインタ アドレス直接設定 ################

//#### SPIブート起動中のローダプログラムのスタックポインタ (Memory Image) #########
//Inter connect RAM0
#define	STACK_IRQ_ADR  0xE63B1FF0	//IRQモード
#define	STACK_FIQ_ADR  0xE63B1EF0	//FIQモード
#define	STACK_ABT_ADR  0xE63B1DF0	//ABTモード
#define	STACK_SVC_ADR  0xE63B1CF0	//SVC(SWI)モード
#define	STACK_UND_ADR  0xE63B1BF0	//UNDモード
#define	STACK_SYS_ADR  0xE63B1AF0	//SYSモード (モニタプログラム動作時のモード)


//#### スタックポインタ (Memory Image) ##################
//#                                                     #
//# H'E63B1AF0   System_stack (MiniMon)                 #
//# H'E63B1BF0   UND_stack                              #
//# H'E63B1CF0   SVC(SWI)_stack                         #
//# H'E63B1DF0   ABT_stack                              #
//# H'E63B1EF0   FIQ_stack                              #
//# H'E63B1FF0   IRQ_stack                              #
//#                                                     #
//#######################################################


//################### CPSRビット関連 ####################
//CPSR[4:0]＝PSRモードビット
#define	PSR_MODE_USER  0x10			//ユーザモード
#define	PSR_MODE_FIQ  0x11			//FIQモード
#define	PSR_MODE_IRQ  0x12			//IRQモード
#define	PSR_MODE_SVC  0x13			//スーパバイザモード
#define	PSR_MODE_ABT  0x17			//アボートモード
#define	PSR_MODE_UND  0x1B			//未定義モード
#define	PSR_MODE_SYS  0x1F			//システムモード


//################### バスコン初期化 ####################

//------------------------------------------------------------------------------
// PFC
// R-CarM2_01_05_PFC_0001.pdf
#define	PMMR		 	0xE6060000	//	LSI Multiplexed Pin Setting Mask Register
#define	GPSR0		 	0xE6060004	//	GPIO/peripheral function select register 0
#define	GPSR1		 	0xE6060008	//	GPIO/peripheral function select register 1
#define	GPSR2		 	0xE606000C	//	GPIO/peripheral function select register 2
#define	GPSR3		 	0xE6060010	//	GPIO/peripheral function select register 3
#define	GPSR4		 	0xE6060014	//	GPIO/peripheral function select register 4
#define	GPSR5		 	0xE6060018	//	GPIO/peripheral function select register 5
#define	GPSR6		 	0xE606001C	//	GPIO/peripheral function select register 6
#define	GPSR7		 	0xE6060074	//	GPIO/peripheral function select register 7

#define	IPSR0		 	0xE6060020	//	Peripheral function select register 0
#define	IPSR1		 	0xE6060024	//	Peripheral function select register 1
#define	IPSR2		 	0xE6060028	//	Peripheral function select register 2
#define	IPSR3		 	0xE606002C	//	Peripheral function select register 3
#define	IPSR4		 	0xE6060030	//	Peripheral function select register 4
#define	IPSR5		 	0xE6060034	//	Peripheral function select register 5
#define	IPSR6		 	0xE6060038	//	Peripheral function select register 6
#define	IPSR7		 	0xE606003C	//	Peripheral function select register 7
#define	IPSR8		 	0xE6060040	//	Peripheral function select register 8
#define	IPSR9		 	0xE6060044	//	Peripheral function select register 9
#define	IPSR10		 	0xE6060048	//	Peripheral function select register 10
#define	IPSR11		 	0xE606004C	//	Peripheral function select register 11
#define	IPSR12		 	0xE6060050	//	Peripheral function select register 12
#define	IPSR13		 	0xE6060054	//	Peripheral function select register 13
#define	IPSR14		 	0xE6060058	//	Peripheral function select register 14
#define	IPSR15		 	0xE606005C	//	Peripheral function select register 15
#define	IPSR16		 	0xE6060160	//	Peripheral function select register 16
#define	MOD_SEL		 	0xE6060090	//	Module select register
#define	MOD_SEL2	 	0xE6060094	//	Module select register 2
#define	MOD_SEL3	 	0xE6060098	//	Module select register 3
#define	MOD_SEL4	 	0xE606009C	//	Module select register 4

#define	PUPR0		 	0xE6060100	//	LSI pin pull-up control register 0
#define	PUPR1		 	0xE6060104	//	LSI pin pull-up control register 1
#define	PUPR2		 	0xE6060108	//	LSI pin pull-up control register 2
#define	PUPR3		 	0xE606010C	//	LSI pin pull-up control register 3
#define	PUPR4		 	0xE6060110	//	LSI pin pull-up control register 4
#define	PUPR5		 	0xE6060114	//	LSI pin pull-up control register 5
#define	PUPR6		 	0xE6060118	//	LSI pin pull-up control register 6
#define	PUPR7		 	0xE606011C	//	LSI pin pull-up control register 7

#define	IOCTRL0		 	0xE6060060	//	SD control register 0
#define	IOCTRL1		 	0xE6060064	//	SD control register 1
#define	IOCTRL4		 	0xE6060084	//	VI1 Driving ability control register
#define	IOCTRL5		 	0xE6060088	//	TDSEL control register
#define	IOCTRL6		 	0xE606008C	//	POC control register
#define	IOCTRL7		 	0xE6060070	//	IICDVFS and TDBG IO cell control register

#define	DDR3GPEN	 	0xE6060240	//	DDR3 General Port IO Enable register
#define	DDR3GPOE	 	0xE6060244	//	DDR3 General Port Output Enable register
#define	DDR3GPOD	 	0xE6060248	//	DDR3 General Port Output Data register
#define	DDR3GPID	 	0xE606024C	//	DDR3 General Port InputData register


//------------------------------------------------------------------------------
// GPIO
// R-CarM2_01_06_GPIO_0001_e.pdf
#define	     GPIO0_BASE	 	0xE6050000	// General IO/interrupt switching register 0
#define	     IOINTSEL0	 	0xE6050000	// General IO/interrupt switching register 0
#define	     INOUTSEL0	 	0xE6050004	// General input/output switching register 0
#define	     OUTDT0		 	0xE6050008	// General output register 0
#define	     INDT0		 	0xE605000C	// General input register 0
#define	     INTDT0		 	0xE6050010	// Interrupt display register 0
#define	     INTCLR0	 	0xE6050014	// Interrupt clear register 0
#define	     INTMSK0	 	0xE6050018	// Interrupt mask register 0
#define	     MSKCLR0	 	0xE605001C	// Interrupt mask clear register 0
#define	     POSNEG0	 	0xE6050020	// Positive/negative logic select register 0
#define	     EDGLEVEL0	 	0xE6050024	// Edge/level select register 0
#define	     FILONOFF0	 	0xE6050028	// Chattering prevention on/off register 0
#define	     INTMSKS0	 	0xE6050038	// Interrupt sub mask register 0
#define	     MSKCLRS0	 	0xE605003C	// Interrupt sub mask clear register 0
#define	     OUTDTSEL0	 	0xE6050040	// Output data select register 0
#define	     OUTDTH0	 	0xE6050044	// Output data high register 0
#define	     OUTDTL0	 	0xE6050048	// Output data low register 0
#define	     BOTHEDGE0	 	0xE605004C	// One edge/both edge select register 0

#define	     GPIO1_BASE	 	0xE6051000	// General IO/interrupt switching register 0
#define	     IOINTSEL1	 	0xE6051000	// General IO/interrupt switching register 1
#define	     INOUTSEL1	 	0xE6051004	// General input/output switching register 1
#define	     OUTDT1		 	0xE6051008	// General output register 1
#define	     INDT1		 	0xE605100C	// General input register 1
#define	     INTDT1		 	0xE6051010	// Interrupt display register 1
#define	     INTCLR1	 	0xE6051014	// Interrupt clear register 1
#define	     INTMSK1	 	0xE6051018	// Interrupt mask register 1
#define	     MSKCLR1	 	0xE605101C	// Interrupt mask clear register 1
#define	     POSNEG1	 	0xE6051020	// Positive/negative logic select register 1
#define	     EDGLEVEL1	 	0xE6051024	// Edge/level select register 1
#define	     FILONOFF1	 	0xE6051028	// Chattering prevention on/off register 1
#define	     INTMSKS1	 	0xE6051038	// Interrupt sub mask register 1
#define	     MSKCLRS1	 	0xE605103C	// Interrupt sub mask clear register 1
#define	     OUTDTSEL1	 	0xE6051040	// Output data select register 1
#define	     OUTDTH1	 	0xE6051044	// Output data high register 1
#define	     OUTDTL1	 	0xE6051048	// Output data low register 1
#define	     BOTHEDGE1	 	0xE605104C	// One edge/both edge select register 1

#define	     GPIO2_BASE	 	0xE6052000	// General IO/interrupt switching register 0
#define	     IOINTSEL2	 	0xE6052000	// General IO/interrupt switching register 2
#define	     INOUTSEL2	 	0xE6052004	// General input/output switching register 2
#define	     OUTDT2		 	0xE6052008	// General output register 2
#define	     INDT2		 	0xE605200C	// General input register 2
#define	     INTDT2		 	0xE6052010	// Interrupt display register 2
#define	     INTCLR2	 	0xE6052014	// Interrupt clear register 2
#define	     INTMSK2	 	0xE6052018	// Interrupt mask register 2
#define	     MSKCLR2	 	0xE605201C	// Interrupt mask clear register 2
#define	     POSNEG2	 	0xE6052020	// Positive/negative logic select register 2
#define	     EDGLEVEL2	 	0xE6052024	// Edge/level select register 2
#define	     FILONOFF2	 	0xE6052028	// Chattering prevention on/off register 2
#define	     INTMSKS2	 	0xE6052038	// Interrupt sub mask register 2
#define	     MSKCLRS2	 	0xE605203C	// Interrupt sub mask clear register 2
#define	     OUTDTSEL2	 	0xE6052040	// Output data select register 2
#define	     OUTDTH2	 	0xE6052044	// Output data high register 2
#define	     OUTDTL2	 	0xE6052048	// Output data low register 2
#define	     BOTHEDGE2	 	0xE605204C	// One edge/both edge select register 2

#define	     GPIO3_BASE	 	0xE6053000	// General IO/interrupt switching register 0
#define	     IOINTSEL3	 	0xE6053000	// General IO/interrupt switching register 3
#define	     INOUTSEL3	 	0xE6053004	// General input/output switching register 3
#define	     OUTDT3		 	0xE6053008	// General output register 3
#define	     INDT3		 	0xE605300C	// General input register 3
#define	     INTDT3		 	0xE6053010	// Interrupt display register 3
#define	     INTCLR3	 	0xE6053014	// Interrupt clear register 3
#define	     INTMSK3	 	0xE6053018	// Interrupt mask register 3
#define	     MSKCLR3	 	0xE605301C	// Interrupt mask clear register 3
#define	     POSNEG3	 	0xE6053020	// Positive/negative logic select register 3
#define	     EDGLEVEL3	 	0xE6053024	// Edge/level select register 3
#define	     FILONOFF3	 	0xE6053028	// Chattering prevention on/off register 3
#define	     INTMSKS3	 	0xE6053038	// Interrupt sub mask register 3
#define	     MSKCLRS3	 	0xE605303C	// Interrupt sub mask clear register 3
#define	     OUTDTSEL3	 	0xE6053040	// Output data select register 3
#define	     OUTDTH3	 	0xE6053044	// Output data high register 3
#define	     OUTDTL3	 	0xE6053048	// Output data low register 3
#define	     BOTHEDGE3	 	0xE605304C	// One edge/both edge select register 3

#define	     GPIO4_BASE	 	0xE6054000	// General IO/interrupt switching register 0
#define	     IOINTSEL4	 	0xE6054000	// General IO/interrupt switching register 4
#define	     INOUTSEL4	 	0xE6054004	// General input/output switching register 4
#define	     OUTDT4		 	0xE6054008	// General output register 4
#define	     INDT4		 	0xE605400C	// General input register 4
#define	     INTDT4		 	0xE6054010	// Interrupt display register 4
#define	     INTCLR4	 	0xE6054014	// Interrupt clear register 4
#define	     INTMSK4	 	0xE6054018	// Interrupt mask register 4
#define	     MSKCLR4	 	0xE605401C	// Interrupt mask clear register 4
#define	     POSNEG4	 	0xE6054020	// Positive/negative logic select register 4
#define	     EDGLEVEL4	 	0xE6054024	// Edge/level select register 4
#define	     FILONOFF4	 	0xE6054028	// Chattering prevention on/off register 4
#define	     INTMSKS4	 	0xE6054038	// Interrupt sub mask register 4
#define	     MSKCLRS4	 	0xE605403C	// Interrupt sub mask clear register 4
#define	     OUTDTSEL4	 	0xE6054040	// Output data select register 4
#define	     OUTDTH4	 	0xE6054044	// Output data high register 4
#define	     OUTDTL4	 	0xE6054048	// Output data low register 4
#define	     BOTHEDGE4	 	0xE605404C	// One edge/both edge select register 4

#define	     GPIO5_BASE	 	0xE6055000	// General IO/interrupt switching register 0
#define	     IOINTSEL5	 	0xE6055000	// General IO/interrupt switching register 5
#define	     INOUTSEL5	 	0xE6055004	// General input/output switching register 5
#define	     OUTDT5		 	0xE6055008	// General output register 5
#define	     INDT5		 	0xE605500C	// General input register 5
#define	     INTDT5		 	0xE6055010	// Interrupt display register 5
#define	     INTCLR5	 	0xE6055014	// Interrupt clear register 5
#define	     INTMSK5	 	0xE6055018	// Interrupt mask register 5
#define	     MSKCLR5	 	0xE605501C	// Interrupt mask clear register 5
#define	     POSNEG5	 	0xE6055020	// Positive/negative logic select register 5
#define	     EDGLEVEL5	 	0xE6055024	// Edge/level select register 5
#define	     FILONOFF5	 	0xE6055028	// Chattering prevention on/off register 5
#define	     INTMSKS5	 	0xE6055038	// Interrupt sub mask register 5
#define	     MSKCLRS5	 	0xE605503C	// Interrupt sub mask clear register 5
#define	     OUTDTSEL5	 	0xE6055040	// Output data select register 5
#define	     OUTDTH5	 	0xE6055044	// Output data high register 5
#define	     OUTDTL5	 	0xE6055048	// Output data low register 5
#define	     BOTHEDGE5	 	0xE605504C	// One edge/both edge select register 5

#define	     GPIO6_BASE	 	0xE6055400	// General IO/interrupt switching register 0
#define	     IOINTSEL6	 	0xE6055400	// General IO/interrupt switching register 6
#define	     INOUTSEL6	 	0xE6055404	// General input/output switching register 6
#define	     OUTDT6		 	0xE6055408	// General output register 6
#define	     INDT6		 	0xE605540C	// General input register 6
#define	     INTDT6		 	0xE6055410	// Interrupt display register 6
#define	     INTCLR6	 	0xE6055414	// Interrupt clear register 6
#define	     INTMSK6	 	0xE6055418	// Interrupt mask register 6
#define	     MSKCLR6	 	0xE605541C	// Interrupt mask clear register 6
#define	     POSNEG6	 	0xE6055420	// Positive/negative logic select register 6
#define	     EDGLEVEL6	 	0xE6055424	// Edge/level select register 6
#define	     FILONOFF6	 	0xE6055428	// Chattering prevention on/off register 6
#define	     INTMSKS6	 	0xE6055438	// Interrupt sub mask register 6
#define	     MSKCLRS6	 	0xE605543C	// Interrupt sub mask clear register 6
#define	     OUTDTSEL6	 	0xE6055440	// Output data select register 6
#define	     OUTDTH6	 	0xE6055444	// Output data high register 6
#define	     OUTDTL6	 	0xE6055448	// Output data low register 6
#define	     BOTHEDGE6	 	0xE605544C	// One edge/both edge select register 6

#define	     GPIO7_BASE	 	0xE6055800	// General IO/interrupt switching register 0
#define	     IOINTSEL7	 	0xE6055800	// General IO/interrupt switching register 7
#define	     INOUTSEL7	 	0xE6055804	// General input/output switching register 7
#define	     OUTDT7		 	0xE6055808	// General output register 7
#define	     INDT7		 	0xE605580C	// General input register 7
#define	     INTDT7		 	0xE6055810	// Interrupt display register 7
#define	     INTCLR7	 	0xE6055814	// Interrupt clear register 7
#define	     INTMSK7	 	0xE6055818	// Interrupt mask register 7
#define	     MSKCLR7	 	0xE605581C	// Interrupt mask clear register 7
#define	     POSNEG7	 	0xE6055820	// Positive/negative logic select register 7
#define	     EDGLEVEL7	 	0xE6055824	// Edge/level select register 7
#define	     FILONOFF7	 	0xE6055828	// Chattering prevention on/off register 7
#define	     INTMSKS7	 	0xE6055838	// Interrupt sub mask register 7
#define	     MSKCLRS7	 	0xE605583C	// Interrupt sub mask clear register 7
#define	     OUTDTSEL7	 	0xE6055840	// Output data select register 7
#define	     OUTDTH7	 	0xE6055844	// Output data high register 7
#define	     OUTDTL7	 	0xE6055848	// Output data low register 7
#define	     BOTHEDGE7	 	0xE605584C	// One edge/both edge select register 7


//------------------------------------------------------------------------------
// LBSC
// R-CarM2_01_16_LBSC_0010_e.pdf
#define	     EXB_BASE	 	0xFEC00000	// Area 0 control register
#define	     CS0CTRL	 	0x00000200	// Area 0 control register
#define	     CS1CTRL	 	0x00000204	// Area 1 control register
#define	     ECS0CTRL	 	0x00000208	// Expansion area 0 control register
#define	     ECS1CTRL	 	0x0000020C	// Expansion area 1 control register
#define	     ECS2CTRL	 	0x00000210	// Expansion area 2 control register
#define	     ECS3CTRL	 	0x00000214	// Expansion area 3 control register
#define	     ECS4CTRL	 	0x00000218	// Expansion area 4 control register
#define	     ECS5CTRL	 	0x0000021C	// Expansion area 5 control register
#define	     CSWCR0		 	0x00000230	// Area 0 RD/WE pulse control register
#define	     CSWCR1		 	0x00000234	// Area 1 RD/WE pulse control register
#define	     ECSWCR0	 	0x00000238	// Expansion area 0 RD/WE pulse control register
#define	     ECSWCR1	 	0x0000023C	// Expansion area 1 RD/WE pulse control register
#define	     ECSWCR2	 	0x00000240	// Expansion area 2 RD/WE pulse control register
#define	     ECSWCR3	 	0x00000244	// Expansion area 3 RD/WE pulse control register
#define	     ECSWCR4	 	0x00000248	// Expansion area 4 RD/WE pulse control register
#define	     ECSWCR5	 	0x0000024C	// Expansion area 5 RD/WE pulse control register
#define	     EXDMAWCR0	 	0x00000250	// LBSC-DMAC channel 0 RD/WE pulse control register
#define	     EXDMAWCR1	 	0x00000254	// LBSC-DMAC channel 1 RD/WE pulse control register
#define	     EXDMAWCR2	 	0x00000258	// LBSC-DMAC channel 2 RD/WE pulse control register
#define	     CSPWCR0	 	0x00000280	// Area 0 external wait control register
#define	     CSPWCR1	 	0x00000284	// Area 1 external wait control register
#define	     ECSPWCR0	 	0x00000288	// Expansion area 0 external wait control register
#define	     ECSPWCR1	 	0x0000028C	// Expansion area 1 external wait control register
#define	     ECSPWCR2	 	0x00000290	// Expansion area 2 external wait control register
#define	     ECSPWCR3	 	0x00000294	// Expansion area 3 external wait control register
#define	     ECSPWCR4	 	0x00000298	// Expansion area 4 external wait control register
#define	     ECSPWCR5	 	0x0000029C	// Expansion area 5 external wait control register
#define	     EXWTSYNC	 	0x000002A0	// External wait input control register
#define	     CS0BSTCTL	 	0x000002B0	// Area 0 burst control register
#define	     CS0BTPH	 	0x000002B4	// Area 0 burst pitch set register
#define	     CS1GDST	 	0x000002C0	// Area 1 guard setting register
#define	     ECS0GDST	 	0x000002C4	// Expansion area 0 guard setting register
#define	     ECS1GDST	 	0x000002C8	// Expansion area 1 guard setting register
#define	     ECS2GDST	 	0x000002CC	// Expansion area 2 guard setting register
#define	     ECS3GDST	 	0x000002D0	// Expansion area 3 guard setting register
#define	     ECS4GDST	 	0x000002D4	// Expansion area 4 guard setting register
#define	     ECS5GDST	 	0x000002D8	// Expansion area 5 guard setting register
#define	     EXDMASET0	 	0x000002F0	// LBSC-DMAC channel 0 area allocation register
#define	     EXDMASET1	 	0x000002F4	// LBSC-DMAC channel 1 area allocation register
#define	     EXDMASET2	 	0x000002F8	// LBSC-DMAC channel 2 area allocation register
#define	     EXDMCR0	 	0x00000310	// LBSC-DMAC channel 0 control register
#define	     EXDMCR1	 	0x00000314	// LBSC-DMAC channel 1 control register
#define	     EXDMCR2	 	0x00000318	// LBSC-DMAC channel 2 control register
#define	     BCINTSR	 	0x00000330	// BSC interrupt source status register
#define	     BCINTCR	 	0x00000334	// BSC interrupt source clear register
#define	     BCINTMR	 	0x00000338	// BSC interrupt enable register
#define	     EXBATLV	 	0x00000340	// EX-BUS priority level set register
#define	     EXWTSTS	 	0x00000344	// External wait status register
#define	     ATACSCTRL	 	0x00000380	// ATACS control register
#define	     EXBCT		 	0x000003C0	// EX-BUS wait timeout detection base counter register
#define	     EXTCT		 	0x000003C4	// EX-BUS wait timeout detection counter register
#define	     EXTSR		 	0x00000010	// EX-BUS wait timeout detection access source indication register
#define	     EXTADR		 	0x00000014	// EX-BUS wait timeout detection address indication register
#define	EXB_W(offset, val)	writel(val, EXB_BASE + (offset))

//------------------------------------------------------------------------------
// DBSC3
// R-CarM2_01_17_DBSC_0000_j.pdf
#define	DBSC3_0_BASE		 	0xE6790000
#define	DBSC3_0_DBSTATE1	 	(DBSC3_0_BASE + 0x00C)	//	DBSC3ステータスレジスタ1
#define	DBSC3_0_DBACEN		 	(DBSC3_0_BASE + 0x010)	//	SDRAMアクセス許可レジスタ
#define	DBSC3_0_DBRFEN		 	(DBSC3_0_BASE + 0x014)	//	自動リフレッシュ許可レジスタ
#define	DBSC3_0_DBCMD		 	(DBSC3_0_BASE + 0x018)	//	手動コマンド発行レジスタ
#define	DBSC3_0_DBWAIT		 	(DBSC3_0_BASE + 0x01C)	//	操作完了待ちレジスタ
#define	DBSC3_0_DBKIND		 	(DBSC3_0_BASE + 0x020)	//	SDRAM種類設定レジスタ
#define	DBSC3_0_DBCONF0		 	(DBSC3_0_BASE + 0x024)	//	SDRAM構成設定レジスタ0
#define	DBSC3_0_DBPHYTYPE	 	(DBSC3_0_BASE + 0x030)	//	PHY種類設定レジスタ
#define	DBSC3_0_DBTR0		 	(DBSC3_0_BASE + 0x040)	//	SDRAMタイミングレジスタ0
#define	DBSC3_0_DBTR1		 	(DBSC3_0_BASE + 0x044)	//	SDRAMタイミングレジスタ1
#define	DBSC3_0_DBTR2		 	(DBSC3_0_BASE + 0x048)	//	SDRAMタイミングレジスタ2
#define	DBSC3_0_DBTR3		 	(DBSC3_0_BASE + 0x050)	//	SDRAMタイミングレジスタ3
#define	DBSC3_0_DBTR4		 	(DBSC3_0_BASE + 0x054)	//	SDRAMタイミングレジスタ4
#define	DBSC3_0_DBTR5		 	(DBSC3_0_BASE + 0x058)	//	SDRAMタイミングレジスタ5
#define	DBSC3_0_DBTR6		 	(DBSC3_0_BASE + 0x05C)	//	SDRAMタイミングレジスタ6
#define	DBSC3_0_DBTR7		 	(DBSC3_0_BASE + 0x060)	//	SDRAMタイミングレジスタ7
#define	DBSC3_0_DBTR8		 	(DBSC3_0_BASE + 0x064)	//	SDRAMタイミングレジスタ8
#define	DBSC3_0_DBTR9		 	(DBSC3_0_BASE + 0x068)	//	SDRAMタイミングレジスタ9
#define	DBSC3_0_DBTR10		 	(DBSC3_0_BASE + 0x06C)	//	SDRAMタイミングレジスタ10
#define	DBSC3_0_DBTR11		 	(DBSC3_0_BASE + 0x070)	//	SDRAMタイミングレジスタ11
#define	DBSC3_0_DBTR12		 	(DBSC3_0_BASE + 0x074)	//	SDRAMタイミングレジスタ12
#define	DBSC3_0_DBTR13		 	(DBSC3_0_BASE + 0x078)	//	SDRAMタイミングレジスタ13
#define	DBSC3_0_DBTR14		 	(DBSC3_0_BASE + 0x07C)	//	SDRAMタイミングレジスタ14
#define	DBSC3_0_DBTR15		 	(DBSC3_0_BASE + 0x080)	//	SDRAMタイミングレジスタ15
#define	DBSC3_0_DBTR16		 	(DBSC3_0_BASE + 0x084)	//	SDRAMタイミングレジスタ16
#define	DBSC3_0_DBTR17		 	(DBSC3_0_BASE + 0x088)	//	SDRAMタイミングレジスタ17
#define	DBSC3_0_DBTR18		 	(DBSC3_0_BASE + 0x08C)	//	SDRAMタイミングレジスタ18
#define	DBSC3_0_DBTR19		 	(DBSC3_0_BASE + 0x090)	//	SDRAMタイミングレジスタ19
#define	DBSC3_0_DBBL		 	(DBSC3_0_BASE + 0x0B0)	//	SDRAM動作設定レジスタ
#define	DBSC3_0_DBADJ0		 	(DBSC3_0_BASE + 0x0C0)	//	DBSC3動作調整レジスタ0
#define	DBSC3_0_DBADJ2		 	(DBSC3_0_BASE + 0x0C8)	//	DBSC3動作調整レジスタ2
#define	DBSC3_0_DBRFCNF0	 	(DBSC3_0_BASE + 0x0E0)	//	リフレッシュ設定レジスタ0
#define	DBSC3_0_DBRFCNF1	 	(DBSC3_0_BASE + 0x0E4)	//	リフレッシュ設定レジスタ1
#define	DBSC3_0_DBRFCNF2	 	(DBSC3_0_BASE + 0x0E8)	//	リフレッシュ設定レジスタ2
#define	DBSC3_0_DBCALCNF	 	(DBSC3_0_BASE + 0x0F4)	//	DDR3-SDRAMキャリブレーション設定レジスタ
#define	DBSC3_0_DBCALTR		 	(DBSC3_0_BASE + 0x0F8)	//	DDR3-SDRAMキャリブレーションタイミングレジスタ
#define	DBSC3_0_DBRNK0		 	(DBSC3_0_BASE + 0x100)	//	ODT動作設定レジスタ
#define	DBSC3_0_DBPDNCNF	 	(DBSC3_0_BASE + 0x180)	//	パワーダウン設定レジスタ
#define	DBSC3_0_DBDFISTAT	 	(DBSC3_0_BASE + 0x240)	//	DBIステータスIF入力レジスタ
#define	DBSC3_0_DBDFICNT	 	(DBSC3_0_BASE + 0x244)	//	DBIステータスIF出力レジスタ
#define	DBSC3_0_DBPDLCK		 	(DBSC3_0_BASE + 0x280)	//	PHY部ロックレジスタ
#define	DBSC3_0_DBPDRGA		 	(DBSC3_0_BASE + 0x290)	//	PHY部内部レジスタアドレス
#define	DBSC3_0_DBPDRGD		 	(DBSC3_0_BASE + 0x2A0)	//	PHY部内部レジスタアクセス
#define	DBSC3_0_DBBS0CNT1	 	(DBSC3_0_BASE + 0x304)	//	バス制御部0制御レジスタ1
#define	DBSC3_0_DBWT0CNF0	 	(DBSC3_0_BASE + 0x380)	//	AXIポート設定レジスタ0
#define	DBSC3_0_DBWT0CNF1	 	(DBSC3_0_BASE + 0x384)	//	AXIポート設定レジスタ1
#define	DBSC3_0_DBWT0CNF2	 	(DBSC3_0_BASE + 0x388)	//	AXIポート設定レジスタ2
#define	DBSC3_0_DBWT0CNF3	 	(DBSC3_0_BASE + 0x38C)	//	AXIポート設定レジスタ3
#define	DBSC3_0_DBWT0CNF4	 	(DBSC3_0_BASE + 0x390)	//	AXIポート設定レジスタ4
#define	DBSC3_0_DBSCHECNT0	 	(DBSC3_0_BASE + 0x500)	//	スケジューラ設定レジスタ0

#define	DBSC3_1_BASE		 	0xE67A0000
#define	DBSC3_1_DBSTATE1	 	(DBSC3_1_BASE + 0x00C)	//	DBSC3ステータスレジスタ1
#define	DBSC3_1_DBACEN		 	(DBSC3_1_BASE + 0x010)	//	SDRAMアクセス許可レジスタ
#define	DBSC3_1_DBRFEN		 	(DBSC3_1_BASE + 0x014)	//	自動リフレッシュ許可レジスタ
#define	DBSC3_1_DBCMD		 	(DBSC3_1_BASE + 0x018)	//	手動コマンド発行レジスタ
#define	DBSC3_1_DBWAIT		 	(DBSC3_1_BASE + 0x01C)	//	操作完了待ちレジスタ
#define	DBSC3_1_DBKIND		 	(DBSC3_1_BASE + 0x020)	//	SDRAM種類設定レジスタ
#define	DBSC3_1_DBCONF0		 	(DBSC3_1_BASE + 0x024)	//	SDRAM構成設定レジスタ0
#define	DBSC3_1_DBPHYTYPE	 	(DBSC3_1_BASE + 0x030)	//	PHY種類設定レジスタ
#define	DBSC3_1_DBTR0		 	(DBSC3_1_BASE + 0x040)	//	SDRAMタイミングレジスタ0
#define	DBSC3_1_DBTR1		 	(DBSC3_1_BASE + 0x044)	//	SDRAMタイミングレジスタ1
#define	DBSC3_1_DBTR2		 	(DBSC3_1_BASE + 0x048)	//	SDRAMタイミングレジスタ2
#define	DBSC3_1_DBTR3		 	(DBSC3_1_BASE + 0x050)	//	SDRAMタイミングレジスタ3
#define	DBSC3_1_DBTR4		 	(DBSC3_1_BASE + 0x054)	//	SDRAMタイミングレジスタ4
#define	DBSC3_1_DBTR5		 	(DBSC3_1_BASE + 0x058)	//	SDRAMタイミングレジスタ5
#define	DBSC3_1_DBTR6		 	(DBSC3_1_BASE + 0x05C)	//	SDRAMタイミングレジスタ6
#define	DBSC3_1_DBTR7		 	(DBSC3_1_BASE + 0x060)	//	SDRAMタイミングレジスタ7
#define	DBSC3_1_DBTR8		 	(DBSC3_1_BASE + 0x064)	//	SDRAMタイミングレジスタ8
#define	DBSC3_1_DBTR9		 	(DBSC3_1_BASE + 0x068)	//	SDRAMタイミングレジスタ9
#define	DBSC3_1_DBTR10		 	(DBSC3_1_BASE + 0x06C)	//	SDRAMタイミングレジスタ10
#define	DBSC3_1_DBTR11		 	(DBSC3_1_BASE + 0x070)	//	SDRAMタイミングレジスタ11
#define	DBSC3_1_DBTR12		 	(DBSC3_1_BASE + 0x074)	//	SDRAMタイミングレジスタ12
#define	DBSC3_1_DBTR13		 	(DBSC3_1_BASE + 0x078)	//	SDRAMタイミングレジスタ13
#define	DBSC3_1_DBTR14		 	(DBSC3_1_BASE + 0x07C)	//	SDRAMタイミングレジスタ14
#define	DBSC3_1_DBTR15		 	(DBSC3_1_BASE + 0x080)	//	SDRAMタイミングレジスタ15
#define	DBSC3_1_DBTR16		 	(DBSC3_1_BASE + 0x084)	//	SDRAMタイミングレジスタ16
#define	DBSC3_1_DBTR17		 	(DBSC3_1_BASE + 0x088)	//	SDRAMタイミングレジスタ17
#define	DBSC3_1_DBTR18		 	(DBSC3_1_BASE + 0x08C)	//	SDRAMタイミングレジスタ18
#define	DBSC3_1_DBTR19		 	(DBSC3_1_BASE + 0x090)	//	SDRAMタイミングレジスタ19
#define	DBSC3_1_DBBL		 	(DBSC3_1_BASE + 0x0B0)	//	SDRAM動作設定レジスタ
#define	DBSC3_1_DBADJ0		 	(DBSC3_1_BASE + 0x0C0)	//	DBSC3動作調整レジスタ0
#define	DBSC3_1_DBADJ2		 	(DBSC3_1_BASE + 0x0C8)	//	DBSC3動作調整レジスタ2
#define	DBSC3_1_DBRFCNF0	 	(DBSC3_1_BASE + 0x0E0)	//	リフレッシュ設定レジスタ0
#define	DBSC3_1_DBRFCNF1	 	(DBSC3_1_BASE + 0x0E4)	//	リフレッシュ設定レジスタ1
#define	DBSC3_1_DBRFCNF2	 	(DBSC3_1_BASE + 0x0E8)	//	リフレッシュ設定レジスタ2
#define	DBSC3_1_DBCALCNF	 	(DBSC3_1_BASE + 0x0F4)	//	DDR3-SDRAMキャリブレーション設定レジスタ
#define	DBSC3_1_DBCALTR		 	(DBSC3_1_BASE + 0x0F8)	//	DDR3-SDRAMキャリブレーションタイミングレジスタ
#define	DBSC3_1_DBRNK0		 	(DBSC3_1_BASE + 0x100)	//	ODT動作設定レジスタ
#define	DBSC3_1_DBPDNCNF	 	(DBSC3_1_BASE + 0x180)	//	パワーダウン設定レジスタ
#define	DBSC3_1_DBDFISTAT	 	(DBSC3_1_BASE + 0x240)	//	DBIステータスIF入力レジスタ
#define	DBSC3_1_DBDFICNT	 	(DBSC3_1_BASE + 0x244)	//	DBIステータスIF出力レジスタ
#define	DBSC3_1_DBPDLCK		 	(DBSC3_1_BASE + 0x280)	//	PHY部ロックレジスタ
#define	DBSC3_1_DBPDRGA		 	(DBSC3_1_BASE + 0x290)	//	PHY部内部レジスタアドレス
#define	DBSC3_1_DBPDRGD		 	(DBSC3_1_BASE + 0x2A0)	//	PHY部内部レジスタアクセス
#define	DBSC3_1_DBBS0CNT1	 	(DBSC3_1_BASE + 0x304)	//	バス制御部0制御レジスタ1
#define	DBSC3_1_DBWT0CNF0	 	(DBSC3_1_BASE + 0x380)	//	AXIポート設定レジスタ0
#define	DBSC3_1_DBWT0CNF1	 	(DBSC3_1_BASE + 0x384)	//	AXIポート設定レジスタ1
#define	DBSC3_1_DBWT0CNF2	 	(DBSC3_1_BASE + 0x388)	//	AXIポート設定レジスタ2
#define	DBSC3_1_DBWT0CNF3	 	(DBSC3_1_BASE + 0x38C)	//	AXIポート設定レジスタ3
#define	DBSC3_1_DBWT0CNF4	 	(DBSC3_1_BASE + 0x390)	//	AXIポート設定レジスタ4
#define	DBSC3_1_DBSCHECNT0	 	(DBSC3_1_BASE + 0x500)	//	スケジューラ設定レジスタ0




//-------------------------- ---------------------------------------------------
//CPG : Module Standby, Software Reset
// R-CarM2_01_07A_CPG_MSTPRST_0010_e.pdf
#define	CPG_MSTPRST_BASE	 	0xE6150000
#define	CPG_MSTPSR0			 	(CPG_MSTPRST_BASE+0x0030)	// Module stop status register 0
#define	CPG_MSTPSR1			 	(CPG_MSTPRST_BASE+0x0038)	// Module stop status register 1
#define	CPG_MSTPSR2			 	(CPG_MSTPRST_BASE+0x0040)	// Module stop status register 2
#define	CPG_MSTPSR3			 	(CPG_MSTPRST_BASE+0x0048)	// Module stop status register 3
#define	CPG_MSTPSR4			 	(CPG_MSTPRST_BASE+0x004C)	// Module stop status register 4
#define	CPG_MSTPSR5			 	(CPG_MSTPRST_BASE+0x003C)	// Module stop status register 5
#define	CPG_MSTPSR6			 	(CPG_MSTPRST_BASE+0x01C0)	// Module stop status register 6
#define	CPG_MSTPSR7			 	(CPG_MSTPRST_BASE+0x01C4)	// Module stop status register 7
#define	CPG_MSTPSR8			 	(CPG_MSTPRST_BASE+0x09A0)	// Module stop status register 8
#define	CPG_MSTPSR9			 	(CPG_MSTPRST_BASE+0x09A4)	// Module stop status register 9
#define	CPG_MSTPSR10		 	(CPG_MSTPRST_BASE+0x09A8)	// Module stop status register 10
#define	CPG_MSTPSR11		 	(CPG_MSTPRST_BASE+0x09AC)	// Module stop status register 11

#define	CPG_RMSTPCR0		 	(CPG_MSTPRST_BASE+0x0110)	// Realtime module stop control register 0
#define	CPG_RMSTPCR1		 	(CPG_MSTPRST_BASE+0x0114)	// Realtime module stop control register 1
#define	CPG_RMSTPCR2		 	(CPG_MSTPRST_BASE+0x0118)	// Realtime module stop control register 2
#define	CPG_RMSTPCR3		 	(CPG_MSTPRST_BASE+0x011C)	// Realtime module stop control register 3
#define	CPG_RMSTPCR4		 	(CPG_MSTPRST_BASE+0x0120)	// Realtime module stop control register 4
#define	CPG_RMSTPCR5		 	(CPG_MSTPRST_BASE+0x0124)	// Realtime module stop control register 5
#define	CPG_RMSTPCR6		 	(CPG_MSTPRST_BASE+0x0128)	// Realtime module stop control register 6
#define	CPG_RMSTPCR7		 	(CPG_MSTPRST_BASE+0x012C)	// Realtime module stop control register 7
#define	CPG_RMSTPCR8		 	(CPG_MSTPRST_BASE+0x0980)	// Realtime module stop control register 8
#define	CPG_RMSTPCR9		 	(CPG_MSTPRST_BASE+0x0984)	// Realtime module stop control register 9
#define	CPG_RMSTPCR10		 	(CPG_MSTPRST_BASE+0x0988)	// Realtime module stop control register 10
#define	CPG_RMSTPCR11		 	(CPG_MSTPRST_BASE+0x098C)	// Realtime module stop control register 11

#define	CPG_SMSTPCR0		 	(CPG_MSTPRST_BASE+0x0130)	// System module stop control register 0
#define	CPG_SMSTPCR1		 	(CPG_MSTPRST_BASE+0x0134)	// System module stop control register 1
#define	CPG_SMSTPCR2		 	(CPG_MSTPRST_BASE+0x0138)	// System module stop control register 2
#define	CPG_SMSTPCR3		 	(CPG_MSTPRST_BASE+0x013C)	// System module stop control register 3
#define	CPG_SMSTPCR4		 	(CPG_MSTPRST_BASE+0x0140)	// System module stop control register 4
#define	CPG_SMSTPCR5		 	(CPG_MSTPRST_BASE+0x0144)	// System module stop control register 5
#define	CPG_SMSTPCR6		 	(CPG_MSTPRST_BASE+0x0148)	// System module stop control register 6
#define	CPG_SMSTPCR7		 	(CPG_MSTPRST_BASE+0x014C)	// System module stop control register 7
#define	CPG_SMSTPCR8		 	(CPG_MSTPRST_BASE+0x0990)	// System module stop control register 8
#define	CPG_SMSTPCR9		 	(CPG_MSTPRST_BASE+0x0994)	// System module stop control register 9
#define	CPG_SMSTPCR10		 	(CPG_MSTPRST_BASE+0x0998)	// System module stop control register 10
#define	CPG_SMSTPCR11		 	(CPG_MSTPRST_BASE+0x099C)	// System module stop control register 11

#define	CPG_SRCR0			 	(CPG_MSTPRST_BASE+0x00A0)	// Software reset register 0
#define	CPG_SRCR1			 	(CPG_MSTPRST_BASE+0x00A8)	// Software reset register 1
#define	CPG_SRCR2			 	(CPG_MSTPRST_BASE+0x00B0)	// Software reset register 2
#define	CPG_SRCR3			 	(CPG_MSTPRST_BASE+0x00B8)	// Software reset register 3
#define	CPG_SRCR4			 	(CPG_MSTPRST_BASE+0x00BC)	// Software reset register 4
#define	CPG_SRCR5			 	(CPG_MSTPRST_BASE+0x00C4)	// Software reset register 5
#define	CPG_SRCR6			 	(CPG_MSTPRST_BASE+0x01C8)	// Software reset register 6
#define	CPG_SRCR7			 	(CPG_MSTPRST_BASE+0x01CC)	// Software reset register 7
#define	CPG_SRCR8			 	(CPG_MSTPRST_BASE+0x0920)	// Software reset register 8
#define	CPG_SRCR9			 	(CPG_MSTPRST_BASE+0x0924)	// Software reset register 9
#define	CPG_SRCR10			 	(CPG_MSTPRST_BASE+0x0928)	// Software reset register 10
#define	CPG_SRCR11			 	(CPG_MSTPRST_BASE+0x092C)	// Software reset register 11

#define	CPG_SRSTCLR0		 	(CPG_MSTPRST_BASE+0x0940)	// Software reset clear register 0
#define	CPG_SRSTCLR1		 	(CPG_MSTPRST_BASE+0x0944)	// Software reset clear register 1
#define	CPG_SRSTCLR2		 	(CPG_MSTPRST_BASE+0x0948)	// Software reset clear register 2
#define	CPG_SRSTCLR3		 	(CPG_MSTPRST_BASE+0x094C)	// Software reset clear register 3
#define	CPG_SRSTCLR4		 	(CPG_MSTPRST_BASE+0x0950)	// Software reset clear register 4
#define	CPG_SRSTCLR5		 	(CPG_MSTPRST_BASE+0x0954)	// Software reset clear register 5
#define	CPG_SRSTCLR6		 	(CPG_MSTPRST_BASE+0x0958)	// Software reset clear register 6
#define	CPG_SRSTCLR7		 	(CPG_MSTPRST_BASE+0x095C)	// Software reset clear register 7
#define	CPG_SRSTCLR8		 	(CPG_MSTPRST_BASE+0x0960)	// Software reset clear register 8
#define	CPG_SRSTCLR9		 	(CPG_MSTPRST_BASE+0x0964)	// Software reset clear register 9
#define	CPG_SRSTCLR10		 	(CPG_MSTPRST_BASE+0x0968)	// Software reset clear register 10
#define	CPG_SRSTCLR11		 	(CPG_MSTPRST_BASE+0x096C)	// Software reset clear register 11


//------------------------------------------------------------------------------
// RST
// R-CarM2_01_08_RST_0010_e.pdf
#define	RST_BASE		 	0xE6160000
#define	RST_MODEMR		 	(RST_BASE + 0x0060)		// Mode Monitor Register
#define	RST_CA15RESCNT	 	(RST_BASE + 0x0040)		// CA15 Reset Control Register
#define	RST_SHXSFTRST	 	(RST_BASE + 0x0048)		// SH-4A Software Reset Register
#define	RST_RESCNT		 	(RST_BASE + 0x0050)		// Reset Control Register
#define	RST_WDTRSTCR	 	(RST_BASE + 0x0054)		// Watchdog Timer Reset Control Register
#define	RST_RSTOUTCR	 	(RST_BASE + 0x0058)		// PRESETOUT Control Register
#define	RST_RBAR		 	(RST_BASE + 0x0000)		// RT Boot Address Register
#define	RST_SBAR		 	(RST_BASE + 0x0010)		// SYS Boot Address Register
#define	RST_SBAR2		 	(RST_BASE + 0x0014)		// SYS Boot Address Register2
#define	RST_RBAR2		 	(RST_BASE + 0x0004)		// RT Boot Address Register2
#define	RST_CA15BAR		 	(RST_BASE + 0x6020)		// CA15 Boot Address Register
#define	RST_CA15BAR2	 	(RST_BASE + 0x6024)		// CA15 Boot Address Register2

#define	RST_SH4AWDTST	 	0xFFEF0080				// SH-4A watchdog timer stop time register
#define	RST_SH4AWDTCSR	 	0xFFEF0084				// SH-4A watchdog timer control/status register
#define	RST_SH4AWDTBST	 	0xFFEF0088				// SH-4A watchdog timer base stop time register
#define	RST_SH4AWDTCNT	 	0xFFEF0090				// SH-4A watchdog timer counter
#define	RST_SH4AWDTBCNT	 	0xFFEF0098				// SH-4A watchdog timer base counter
#define	RST_SH4ARESETVEC 	0xFFEF0040				// SH-4A reset vector setting register


//---------------------- -------------------------------------------------------
// RWDT
// R-CarM2_01_66_RWDT_0020_e.pdf
#define	RWDT_RWTCNT		 	0xE6020000				// RCLK watchdog timer counter
#define	RWDT_RWTCSRA	 	0xE6020004				// RCLK watchdog timer control/status register A
#define	RWDT_RWTCSRB	 	0xE6020008				// RCLK watchdog timer control/status register B


//---------------------- -------------------------------------------------------
// secureWDT
// R-CarM2_01_67_secureWDT_0010_e.pdf
#define	SECWDT_WTCNT	 	0xE6030000				// watchdog timer counter
#define	SECWDT_WTCSRA	 	0xE6030004				// watchdog timer control/status register A
#define	SECWDT_WTCSRB	 	0xE6030008				// watchdog timer control/status register B







//------------------------------------------------------------------------------
// S3CTRL
// R-CarM2_01_17B_S3CTRL_0001_e.pdf
#define 	S3CTRL_S3CEXCLADDMSK	 	0xE6784000		// Exclusive Address Mask Register	
#define 	S3CTRL_S3CEXCLIDMSK		 	0xE6784004		// Exclusive ID Mask Register	
#define 	S3CTRL_S3CADSPLCR		 	0xE6784008		// S3C Address Split Control Register	
#define 	S3CTRL_S3CMAAR			 	0xE678400C		// S3C Mirror Area Address Register	





