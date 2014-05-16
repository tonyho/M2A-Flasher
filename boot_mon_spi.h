@#Last date modified 2013.06.07

@##### �X�^�b�N�|�C���^ �A�h���X���ڐݒ� ################

@##### SPI�u�[�g�N�����̃��[�_�v���O�����̃X�^�b�N�|�C���^ (Memory Image) #########
@#Inter connect RAM0
.EQU	STACK_IRQ_ADR, 0xE63B1FF0	@#IRQ���[�h
.EQU	STACK_FIQ_ADR, 0xE63B1EF0	@#FIQ���[�h
.EQU	STACK_ABT_ADR, 0xE63B1DF0	@#ABT���[�h
.EQU	STACK_SVC_ADR, 0xE63B1CF0	@#SVC(SWI)���[�h
.EQU	STACK_UND_ADR, 0xE63B1BF0	@#UND���[�h
.EQU	STACK_SYS_ADR, 0xE63B1AF0	@#SYS���[�h (���j�^�v���O�������쎞�̃��[�h)


@##### �X�^�b�N�|�C���^ (Memory Image) ##################
@##                                                     #
@## H'E63B1AF0   System_stack (MiniMon)                 #
@## H'E63B1BF0   UND_stack                              #
@## H'E63B1CF0   SVC(SWI)_stack                         #
@## H'E63B1DF0   ABT_stack                              #
@## H'E63B1EF0   FIQ_stack                              #
@## H'E63B1FF0   IRQ_stack                              #
@##                                                     #
@########################################################


@#################### CPSR�r�b�g�֘A ####################
@#CPSR[4:0]��PSR���[�h�r�b�g
.EQU	PSR_MODE_USER, 0x10			@#���[�U���[�h
.EQU	PSR_MODE_FIQ, 0x11			@#FIQ���[�h
.EQU	PSR_MODE_IRQ, 0x12			@#IRQ���[�h
.EQU	PSR_MODE_SVC, 0x13			@#�X�[�p�o�C�U���[�h
.EQU	PSR_MODE_ABT, 0x17			@#�A�{�[�g���[�h
.EQU	PSR_MODE_UND, 0x1B			@#����`���[�h
.EQU	PSR_MODE_SYS, 0x1F			@#�V�X�e�����[�h


@#################### �o�X�R������ ####################

@#------------------------------------------------------------------------------
@# PFC
@# R-CarM2_01_05_PFC_0001.pdf
.EQU	PFC_PMMR		,	0xE6060000	@#	LSI Multiplexed Pin Setting Mask Register
.EQU	PFC_GPSR0		,	0xE6060004	@#	GPIO/peripheral function select register 0
.EQU	PFC_GPSR1		,	0xE6060008	@#	GPIO/peripheral function select register 1
.EQU	PFC_GPSR2		,	0xE606000C	@#	GPIO/peripheral function select register 2
.EQU	PFC_GPSR3		,	0xE6060010	@#	GPIO/peripheral function select register 3
.EQU	PFC_GPSR4		,	0xE6060014	@#	GPIO/peripheral function select register 4
.EQU	PFC_GPSR5		,	0xE6060018	@#	GPIO/peripheral function select register 5
.EQU	PFC_GPSR6		,	0xE606001C	@#	GPIO/peripheral function select register 6
.EQU	PFC_GPSR7		,	0xE6060074	@#	GPIO/peripheral function select register 7

.EQU	PFC_IPSR0		,	0xE6060020	@#	Peripheral function select register 0
.EQU	PFC_IPSR1		,	0xE6060024	@#	Peripheral function select register 1
.EQU	PFC_IPSR2		,	0xE6060028	@#	Peripheral function select register 2
.EQU	PFC_IPSR3		,	0xE606002C	@#	Peripheral function select register 3
.EQU	PFC_IPSR4		,	0xE6060030	@#	Peripheral function select register 4
.EQU	PFC_IPSR5		,	0xE6060034	@#	Peripheral function select register 5
.EQU	PFC_IPSR6		,	0xE6060038	@#	Peripheral function select register 6
.EQU	PFC_IPSR7		,	0xE606003C	@#	Peripheral function select register 7
.EQU	PFC_IPSR8		,	0xE6060040	@#	Peripheral function select register 8
.EQU	PFC_IPSR9		,	0xE6060044	@#	Peripheral function select register 9
.EQU	PFC_IPSR10		,	0xE6060048	@#	Peripheral function select register 10
.EQU	PFC_IPSR11		,	0xE606004C	@#	Peripheral function select register 11
.EQU	PFC_IPSR12		,	0xE6060050	@#	Peripheral function select register 12
.EQU	PFC_IPSR13		,	0xE6060054	@#	Peripheral function select register 13
.EQU	PFC_IPSR14		,	0xE6060058	@#	Peripheral function select register 14
.EQU	PFC_IPSR15		,	0xE606005C	@#	Peripheral function select register 15
.EQU	PFC_IPSR16		,	0xE6060160	@#	Peripheral function select register 16
.EQU	PFC_MOD_SEL		,	0xE6060090	@#	Module select register
.EQU	PFC_MOD_SEL2	,	0xE6060094	@#	Module select register 2
.EQU	PFC_MOD_SEL3	,	0xE6060098	@#	Module select register 3
.EQU	PFC_MOD_SEL4	,	0xE606009C	@#	Module select register 4

.EQU	PFC_PUPR0		,	0xE6060100	@#	LSI pin pull-up control register 0
.EQU	PFC_PUPR1		,	0xE6060104	@#	LSI pin pull-up control register 1
.EQU	PFC_PUPR2		,	0xE6060108	@#	LSI pin pull-up control register 2
.EQU	PFC_PUPR3		,	0xE606010C	@#	LSI pin pull-up control register 3
.EQU	PFC_PUPR4		,	0xE6060110	@#	LSI pin pull-up control register 4
.EQU	PFC_PUPR5		,	0xE6060114	@#	LSI pin pull-up control register 5
.EQU	PFC_PUPR6		,	0xE6060118	@#	LSI pin pull-up control register 6
.EQU	PFC_PUPR7		,	0xE606011C	@#	LSI pin pull-up control register 7

.EQU	PFC_IOCTRL0		,	0xE6060060	@#	SD control register 0
.EQU	PFC_IOCTRL1		,	0xE6060064	@#	SD control register 1
.EQU	PFC_IOCTRL4		,	0xE6060084	@#	VI1 Driving ability control register
.EQU	PFC_IOCTRL5		,	0xE6060088	@#	TDSEL control register
.EQU	PFC_IOCTRL6		,	0xE606008C	@#	POC control register
.EQU	PFC_IOCTRL7		,	0xE6060070	@#	IICDVFS and TDBG IO cell control register

.EQU	PFC_DDR3GPEN	,	0xE6060240	@#	DDR3 General Port IO Enable register
.EQU	PFC_DDR3GPOE	,	0xE6060244	@#	DDR3 General Port Output Enable register
.EQU	PFC_DDR3GPOD	,	0xE6060248	@#	DDR3 General Port Output Data register
.EQU	PFC_DDR3GPID	,	0xE606024C	@#	DDR3 General Port InputData register


@#------------------------------------------------------------------------------
@# GPIO
@# R-CarM2_01_06_GPIO_0001_e.pdf
.EQU	GPIO_IOINTSEL0	,	0xE6050000	@# General IO/interrupt switching register 0
.EQU	GPIO_INOUTSEL0	,	0xE6050004	@# General input/output switching register 0
.EQU	GPIO_OUTDT0		,	0xE6050008	@# General output register 0
.EQU	GPIO_INDT0		,	0xE605000C	@# General input register 0
.EQU	GPIO_INTDT0		,	0xE6050010	@# Interrupt display register 0
.EQU	GPIO_INTCLR0	,	0xE6050014	@# Interrupt clear register 0
.EQU	GPIO_INTMSK0	,	0xE6050018	@# Interrupt mask register 0
.EQU	GPIO_MSKCLR0	,	0xE605001C	@# Interrupt mask clear register 0
.EQU	GPIO_POSNEG0	,	0xE6050020	@# Positive/negative logic select register 0
.EQU	GPIO_EDGLEVEL0	,	0xE6050024	@# Edge/level select register 0
.EQU	GPIO_FILONOFF0	,	0xE6050028	@# Chattering prevention on/off register 0
.EQU	GPIO_INTMSKS0	,	0xE6050038	@# Interrupt sub mask register 0
.EQU	GPIO_MSKCLRS0	,	0xE605003C	@# Interrupt sub mask clear register 0
.EQU	GPIO_OUTDTSEL0	,	0xE6050040	@# Output data select register 0
.EQU	GPIO_OUTDTH0	,	0xE6050044	@# Output data high register 0
.EQU	GPIO_OUTDTL0	,	0xE6050048	@# Output data low register 0
.EQU	GPIO_BOTHEDGE0	,	0xE605004C	@# One edge/both edge select register 0

.EQU	GPIO_IOINTSEL1	,	0xE6051000	@# General IO/interrupt switching register 1
.EQU	GPIO_INOUTSEL1	,	0xE6051004	@# General input/output switching register 1
.EQU	GPIO_OUTDT1		,	0xE6051008	@# General output register 1
.EQU	GPIO_INDT1		,	0xE605100C	@# General input register 1
.EQU	GPIO_INTDT1		,	0xE6051010	@# Interrupt display register 1
.EQU	GPIO_INTCLR1	,	0xE6051014	@# Interrupt clear register 1
.EQU	GPIO_INTMSK1	,	0xE6051018	@# Interrupt mask register 1
.EQU	GPIO_MSKCLR1	,	0xE605101C	@# Interrupt mask clear register 1
.EQU	GPIO_POSNEG1	,	0xE6051020	@# Positive/negative logic select register 1
.EQU	GPIO_EDGLEVEL1	,	0xE6051024	@# Edge/level select register 1
.EQU	GPIO_FILONOFF1	,	0xE6051028	@# Chattering prevention on/off register 1
.EQU	GPIO_INTMSKS1	,	0xE6051038	@# Interrupt sub mask register 1
.EQU	GPIO_MSKCLRS1	,	0xE605103C	@# Interrupt sub mask clear register 1
.EQU	GPIO_OUTDTSEL1	,	0xE6051040	@# Output data select register 1
.EQU	GPIO_OUTDTH1	,	0xE6051044	@# Output data high register 1
.EQU	GPIO_OUTDTL1	,	0xE6051048	@# Output data low register 1
.EQU	GPIO_BOTHEDGE1	,	0xE605104C	@# One edge/both edge select register 1

.EQU	GPIO_IOINTSEL2	,	0xE6052000	@# General IO/interrupt switching register 2
.EQU	GPIO_INOUTSEL2	,	0xE6052004	@# General input/output switching register 2
.EQU	GPIO_OUTDT2		,	0xE6052008	@# General output register 2
.EQU	GPIO_INDT2		,	0xE605200C	@# General input register 2
.EQU	GPIO_INTDT2		,	0xE6052010	@# Interrupt display register 2
.EQU	GPIO_INTCLR2	,	0xE6052014	@# Interrupt clear register 2
.EQU	GPIO_INTMSK2	,	0xE6052018	@# Interrupt mask register 2
.EQU	GPIO_MSKCLR2	,	0xE605201C	@# Interrupt mask clear register 2
.EQU	GPIO_POSNEG2	,	0xE6052020	@# Positive/negative logic select register 2
.EQU	GPIO_EDGLEVEL2	,	0xE6052024	@# Edge/level select register 2
.EQU	GPIO_FILONOFF2	,	0xE6052028	@# Chattering prevention on/off register 2
.EQU	GPIO_INTMSKS2	,	0xE6052038	@# Interrupt sub mask register 2
.EQU	GPIO_MSKCLRS2	,	0xE605203C	@# Interrupt sub mask clear register 2
.EQU	GPIO_OUTDTSEL2	,	0xE6052040	@# Output data select register 2
.EQU	GPIO_OUTDTH2	,	0xE6052044	@# Output data high register 2
.EQU	GPIO_OUTDTL2	,	0xE6052048	@# Output data low register 2
.EQU	GPIO_BOTHEDGE2	,	0xE605204C	@# One edge/both edge select register 2

.EQU	GPIO_IOINTSEL3	,	0xE6053000	@# General IO/interrupt switching register 3
.EQU	GPIO_INOUTSEL3	,	0xE6053004	@# General input/output switching register 3
.EQU	GPIO_OUTDT3		,	0xE6053008	@# General output register 3
.EQU	GPIO_INDT3		,	0xE605300C	@# General input register 3
.EQU	GPIO_INTDT3		,	0xE6053010	@# Interrupt display register 3
.EQU	GPIO_INTCLR3	,	0xE6053014	@# Interrupt clear register 3
.EQU	GPIO_INTMSK3	,	0xE6053018	@# Interrupt mask register 3
.EQU	GPIO_MSKCLR3	,	0xE605301C	@# Interrupt mask clear register 3
.EQU	GPIO_POSNEG3	,	0xE6053020	@# Positive/negative logic select register 3
.EQU	GPIO_EDGLEVEL3	,	0xE6053024	@# Edge/level select register 3
.EQU	GPIO_FILONOFF3	,	0xE6053028	@# Chattering prevention on/off register 3
.EQU	GPIO_INTMSKS3	,	0xE6053038	@# Interrupt sub mask register 3
.EQU	GPIO_MSKCLRS3	,	0xE605303C	@# Interrupt sub mask clear register 3
.EQU	GPIO_OUTDTSEL3	,	0xE6053040	@# Output data select register 3
.EQU	GPIO_OUTDTH3	,	0xE6053044	@# Output data high register 3
.EQU	GPIO_OUTDTL3	,	0xE6053048	@# Output data low register 3
.EQU	GPIO_BOTHEDGE3	,	0xE605304C	@# One edge/both edge select register 3

.EQU	GPIO_IOINTSEL4	,	0xE6054000	@# General IO/interrupt switching register 4
.EQU	GPIO_INOUTSEL4	,	0xE6054004	@# General input/output switching register 4
.EQU	GPIO_OUTDT4		,	0xE6054008	@# General output register 4
.EQU	GPIO_INDT4		,	0xE605400C	@# General input register 4
.EQU	GPIO_INTDT4		,	0xE6054010	@# Interrupt display register 4
.EQU	GPIO_INTCLR4	,	0xE6054014	@# Interrupt clear register 4
.EQU	GPIO_INTMSK4	,	0xE6054018	@# Interrupt mask register 4
.EQU	GPIO_MSKCLR4	,	0xE605401C	@# Interrupt mask clear register 4
.EQU	GPIO_POSNEG4	,	0xE6054020	@# Positive/negative logic select register 4
.EQU	GPIO_EDGLEVEL4	,	0xE6054024	@# Edge/level select register 4
.EQU	GPIO_FILONOFF4	,	0xE6054028	@# Chattering prevention on/off register 4
.EQU	GPIO_INTMSKS4	,	0xE6054038	@# Interrupt sub mask register 4
.EQU	GPIO_MSKCLRS4	,	0xE605403C	@# Interrupt sub mask clear register 4
.EQU	GPIO_OUTDTSEL4	,	0xE6054040	@# Output data select register 4
.EQU	GPIO_OUTDTH4	,	0xE6054044	@# Output data high register 4
.EQU	GPIO_OUTDTL4	,	0xE6054048	@# Output data low register 4
.EQU	GPIO_BOTHEDGE4	,	0xE605404C	@# One edge/both edge select register 4

.EQU	GPIO_IOINTSEL5	,	0xE6055000	@# General IO/interrupt switching register 5
.EQU	GPIO_INOUTSEL5	,	0xE6055004	@# General input/output switching register 5
.EQU	GPIO_OUTDT5		,	0xE6055008	@# General output register 5
.EQU	GPIO_INDT5		,	0xE605500C	@# General input register 5
.EQU	GPIO_INTDT5		,	0xE6055010	@# Interrupt display register 5
.EQU	GPIO_INTCLR5	,	0xE6055014	@# Interrupt clear register 5
.EQU	GPIO_INTMSK5	,	0xE6055018	@# Interrupt mask register 5
.EQU	GPIO_MSKCLR5	,	0xE605501C	@# Interrupt mask clear register 5
.EQU	GPIO_POSNEG5	,	0xE6055020	@# Positive/negative logic select register 5
.EQU	GPIO_EDGLEVEL5	,	0xE6055024	@# Edge/level select register 5
.EQU	GPIO_FILONOFF5	,	0xE6055028	@# Chattering prevention on/off register 5
.EQU	GPIO_INTMSKS5	,	0xE6055038	@# Interrupt sub mask register 5
.EQU	GPIO_MSKCLRS5	,	0xE605503C	@# Interrupt sub mask clear register 5
.EQU	GPIO_OUTDTSEL5	,	0xE6055040	@# Output data select register 5
.EQU	GPIO_OUTDTH5	,	0xE6055044	@# Output data high register 5
.EQU	GPIO_OUTDTL5	,	0xE6055048	@# Output data low register 5
.EQU	GPIO_BOTHEDGE5	,	0xE605504C	@# One edge/both edge select register 5

.EQU	GPIO_IOINTSEL6	,	0xE6055400	@# General IO/interrupt switching register 6
.EQU	GPIO_INOUTSEL6	,	0xE6055404	@# General input/output switching register 6
.EQU	GPIO_OUTDT6		,	0xE6055408	@# General output register 6
.EQU	GPIO_INDT6		,	0xE605540C	@# General input register 6
.EQU	GPIO_INTDT6		,	0xE6055410	@# Interrupt display register 6
.EQU	GPIO_INTCLR6	,	0xE6055414	@# Interrupt clear register 6
.EQU	GPIO_INTMSK6	,	0xE6055418	@# Interrupt mask register 6
.EQU	GPIO_MSKCLR6	,	0xE605541C	@# Interrupt mask clear register 6
.EQU	GPIO_POSNEG6	,	0xE6055420	@# Positive/negative logic select register 6
.EQU	GPIO_EDGLEVEL6	,	0xE6055424	@# Edge/level select register 6
.EQU	GPIO_FILONOFF6	,	0xE6055428	@# Chattering prevention on/off register 6
.EQU	GPIO_INTMSKS6	,	0xE6055438	@# Interrupt sub mask register 6
.EQU	GPIO_MSKCLRS6	,	0xE605543C	@# Interrupt sub mask clear register 6
.EQU	GPIO_OUTDTSEL6	,	0xE6055440	@# Output data select register 6
.EQU	GPIO_OUTDTH6	,	0xE6055444	@# Output data high register 6
.EQU	GPIO_OUTDTL6	,	0xE6055448	@# Output data low register 6
.EQU	GPIO_BOTHEDGE6	,	0xE605544C	@# One edge/both edge select register 6

.EQU	GPIO_IOINTSEL7	,	0xE6055800	@# General IO/interrupt switching register 7
.EQU	GPIO_INOUTSEL7	,	0xE6055804	@# General input/output switching register 7
.EQU	GPIO_OUTDT7		,	0xE6055808	@# General output register 7
.EQU	GPIO_INDT7		,	0xE605580C	@# General input register 7
.EQU	GPIO_INTDT7		,	0xE6055810	@# Interrupt display register 7
.EQU	GPIO_INTCLR7	,	0xE6055814	@# Interrupt clear register 7
.EQU	GPIO_INTMSK7	,	0xE6055818	@# Interrupt mask register 7
.EQU	GPIO_MSKCLR7	,	0xE605581C	@# Interrupt mask clear register 7
.EQU	GPIO_POSNEG7	,	0xE6055820	@# Positive/negative logic select register 7
.EQU	GPIO_EDGLEVEL7	,	0xE6055824	@# Edge/level select register 7
.EQU	GPIO_FILONOFF7	,	0xE6055828	@# Chattering prevention on/off register 7
.EQU	GPIO_INTMSKS7	,	0xE6055838	@# Interrupt sub mask register 7
.EQU	GPIO_MSKCLRS7	,	0xE605583C	@# Interrupt sub mask clear register 7
.EQU	GPIO_OUTDTSEL7	,	0xE6055840	@# Output data select register 7
.EQU	GPIO_OUTDTH7	,	0xE6055844	@# Output data high register 7
.EQU	GPIO_OUTDTL7	,	0xE6055848	@# Output data low register 7
.EQU	GPIO_BOTHEDGE7	,	0xE605584C	@# One edge/both edge select register 7


@#------------------------------------------------------------------------------
@# LBSC
@# R-CarM2_01_16_LBSC_0010_e.pdf
.EQU	LBSC_CS0CTRL	,	0xFEC00200	@# Area 0 control register
.EQU	LBSC_CS1CTRL	,	0xFEC00204	@# Area 1 control register
.EQU	LBSC_ECS0CTRL	,	0xFEC00208	@# Expansion area 0 control register
.EQU	LBSC_ECS1CTRL	,	0xFEC0020C	@# Expansion area 1 control register
.EQU	LBSC_ECS2CTRL	,	0xFEC00210	@# Expansion area 2 control register
.EQU	LBSC_ECS3CTRL	,	0xFEC00214	@# Expansion area 3 control register
.EQU	LBSC_ECS4CTRL	,	0xFEC00218	@# Expansion area 4 control register
.EQU	LBSC_ECS5CTRL	,	0xFEC0021C	@# Expansion area 5 control register
.EQU	LBSC_CSWCR0		,	0xFEC00230	@# Area 0 RD/WE pulse control register
.EQU	LBSC_CSWCR1		,	0xFEC00234	@# Area 1 RD/WE pulse control register
.EQU	LBSC_ECSWCR0	,	0xFEC00238	@# Expansion area 0 RD/WE pulse control register
.EQU	LBSC_ECSWCR1	,	0xFEC0023C	@# Expansion area 1 RD/WE pulse control register
.EQU	LBSC_ECSWCR2	,	0xFEC00240	@# Expansion area 2 RD/WE pulse control register
.EQU	LBSC_ECSWCR3	,	0xFEC00244	@# Expansion area 3 RD/WE pulse control register
.EQU	LBSC_ECSWCR4	,	0xFEC00248	@# Expansion area 4 RD/WE pulse control register
.EQU	LBSC_ECSWCR5	,	0xFEC0024C	@# Expansion area 5 RD/WE pulse control register
.EQU	LBSC_EXDMAWCR0	,	0xFEC00250	@# LBSC-DMAC channel 0 RD/WE pulse control register
.EQU	LBSC_EXDMAWCR1	,	0xFEC00254	@# LBSC-DMAC channel 1 RD/WE pulse control register
.EQU	LBSC_EXDMAWCR2	,	0xFEC00258	@# LBSC-DMAC channel 2 RD/WE pulse control register
.EQU	LBSC_CSPWCR0	,	0xFEC00280	@# Area 0 external wait control register
.EQU	LBSC_CSPWCR1	,	0xFEC00284	@# Area 1 external wait control register
.EQU	LBSC_ECSPWCR0	,	0xFEC00288	@# Expansion area 0 external wait control register
.EQU	LBSC_ECSPWCR1	,	0xFEC0028C	@# Expansion area 1 external wait control register
.EQU	LBSC_ECSPWCR2	,	0xFEC00290	@# Expansion area 2 external wait control register
.EQU	LBSC_ECSPWCR3	,	0xFEC00294	@# Expansion area 3 external wait control register
.EQU	LBSC_ECSPWCR4	,	0xFEC00298	@# Expansion area 4 external wait control register
.EQU	LBSC_ECSPWCR5	,	0xFEC0029C	@# Expansion area 5 external wait control register
.EQU	LBSC_EXWTSYNC	,	0xFEC002A0	@# External wait input control register
.EQU	LBSC_CS0BSTCTL	,	0xFEC002B0	@# Area 0 burst control register
.EQU	LBSC_CS0BTPH	,	0xFEC002B4	@# Area 0 burst pitch set register
.EQU	LBSC_CS1GDST	,	0xFEC002C0	@# Area 1 guard setting register
.EQU	LBSC_ECS0GDST	,	0xFEC002C4	@# Expansion area 0 guard setting register
.EQU	LBSC_ECS1GDST	,	0xFEC002C8	@# Expansion area 1 guard setting register
.EQU	LBSC_ECS2GDST	,	0xFEC002CC	@# Expansion area 2 guard setting register
.EQU	LBSC_ECS3GDST	,	0xFEC002D0	@# Expansion area 3 guard setting register
.EQU	LBSC_ECS4GDST	,	0xFEC002D4	@# Expansion area 4 guard setting register
.EQU	LBSC_ECS5GDST	,	0xFEC002D8	@# Expansion area 5 guard setting register
.EQU	LBSC_EXDMASET0	,	0xFEC002F0	@# LBSC-DMAC channel 0 area allocation register
.EQU	LBSC_EXDMASET1	,	0xFEC002F4	@# LBSC-DMAC channel 1 area allocation register
.EQU	LBSC_EXDMASET2	,	0xFEC002F8	@# LBSC-DMAC channel 2 area allocation register
.EQU	LBSC_EXDMCR0	,	0xFEC00310	@# LBSC-DMAC channel 0 control register
.EQU	LBSC_EXDMCR1	,	0xFEC00314	@# LBSC-DMAC channel 1 control register
.EQU	LBSC_EXDMCR2	,	0xFEC00318	@# LBSC-DMAC channel 2 control register
.EQU	LBSC_BCINTSR	,	0xFEC00330	@# BSC interrupt source status register
.EQU	LBSC_BCINTCR	,	0xFEC00334	@# BSC interrupt source clear register
.EQU	LBSC_BCINTMR	,	0xFEC00338	@# BSC interrupt enable register
.EQU	LBSC_EXBATLV	,	0xFEC00340	@# EX-BUS priority level set register
.EQU	LBSC_EXWTSTS	,	0xFEC00344	@# External wait status register
.EQU	LBSC_ATACSCTRL	,	0xFEC00380	@# ATACS control register
.EQU	LBSC_EXBCT		,	0xFEC003C0	@# EX-BUS wait timeout detection base counter register
.EQU	LBSC_EXTCT		,	0xFEC003C4	@# EX-BUS wait timeout detection counter register
.EQU	LBSC_EXTSR		,	0xFEC00010	@# EX-BUS wait timeout detection access source indication register
.EQU	LBSC_EXTADR		,	0xFEC00014	@# EX-BUS wait timeout detection address indication register


@#------------------------------------------------------------------------------
@# DBSC3
@# R-CarM2_01_17_DBSC_0000_j.pdf
.EQU	DBSC3_0_BASE		,	0xE6790000
.EQU	DBSC3_0_DBSTATE1	,	(DBSC3_0_BASE + 0x00C)	@#	DBSC3�X�e�[�^�X���W�X�^1
.EQU	DBSC3_0_DBACEN		,	(DBSC3_0_BASE + 0x010)	@#	SDRAM�A�N�Z�X�����W�X�^
.EQU	DBSC3_0_DBRFEN		,	(DBSC3_0_BASE + 0x014)	@#	�������t���b�V�������W�X�^
.EQU	DBSC3_0_DBCMD		,	(DBSC3_0_BASE + 0x018)	@#	�蓮�R�}���h���s���W�X�^
.EQU	DBSC3_0_DBWAIT		,	(DBSC3_0_BASE + 0x01C)	@#	���슮���҂����W�X�^
.EQU	DBSC3_0_DBKIND		,	(DBSC3_0_BASE + 0x020)	@#	SDRAM��ސݒ背�W�X�^
.EQU	DBSC3_0_DBCONF0		,	(DBSC3_0_BASE + 0x024)	@#	SDRAM�\���ݒ背�W�X�^0
.EQU	DBSC3_0_DBPHYTYPE	,	(DBSC3_0_BASE + 0x030)	@#	PHY��ސݒ背�W�X�^
.EQU	DBSC3_0_DBTR0		,	(DBSC3_0_BASE + 0x040)	@#	SDRAM�^�C�~���O���W�X�^0
.EQU	DBSC3_0_DBTR1		,	(DBSC3_0_BASE + 0x044)	@#	SDRAM�^�C�~���O���W�X�^1
.EQU	DBSC3_0_DBTR2		,	(DBSC3_0_BASE + 0x048)	@#	SDRAM�^�C�~���O���W�X�^2
.EQU	DBSC3_0_DBTR3		,	(DBSC3_0_BASE + 0x050)	@#	SDRAM�^�C�~���O���W�X�^3
.EQU	DBSC3_0_DBTR4		,	(DBSC3_0_BASE + 0x054)	@#	SDRAM�^�C�~���O���W�X�^4
.EQU	DBSC3_0_DBTR5		,	(DBSC3_0_BASE + 0x058)	@#	SDRAM�^�C�~���O���W�X�^5
.EQU	DBSC3_0_DBTR6		,	(DBSC3_0_BASE + 0x05C)	@#	SDRAM�^�C�~���O���W�X�^6
.EQU	DBSC3_0_DBTR7		,	(DBSC3_0_BASE + 0x060)	@#	SDRAM�^�C�~���O���W�X�^7
.EQU	DBSC3_0_DBTR8		,	(DBSC3_0_BASE + 0x064)	@#	SDRAM�^�C�~���O���W�X�^8
.EQU	DBSC3_0_DBTR9		,	(DBSC3_0_BASE + 0x068)	@#	SDRAM�^�C�~���O���W�X�^9
.EQU	DBSC3_0_DBTR10		,	(DBSC3_0_BASE + 0x06C)	@#	SDRAM�^�C�~���O���W�X�^10
.EQU	DBSC3_0_DBTR11		,	(DBSC3_0_BASE + 0x070)	@#	SDRAM�^�C�~���O���W�X�^11
.EQU	DBSC3_0_DBTR12		,	(DBSC3_0_BASE + 0x074)	@#	SDRAM�^�C�~���O���W�X�^12
.EQU	DBSC3_0_DBTR13		,	(DBSC3_0_BASE + 0x078)	@#	SDRAM�^�C�~���O���W�X�^13
.EQU	DBSC3_0_DBTR14		,	(DBSC3_0_BASE + 0x07C)	@#	SDRAM�^�C�~���O���W�X�^14
.EQU	DBSC3_0_DBTR15		,	(DBSC3_0_BASE + 0x080)	@#	SDRAM�^�C�~���O���W�X�^15
.EQU	DBSC3_0_DBTR16		,	(DBSC3_0_BASE + 0x084)	@#	SDRAM�^�C�~���O���W�X�^16
.EQU	DBSC3_0_DBTR17		,	(DBSC3_0_BASE + 0x088)	@#	SDRAM�^�C�~���O���W�X�^17
.EQU	DBSC3_0_DBTR18		,	(DBSC3_0_BASE + 0x08C)	@#	SDRAM�^�C�~���O���W�X�^18
.EQU	DBSC3_0_DBTR19		,	(DBSC3_0_BASE + 0x090)	@#	SDRAM�^�C�~���O���W�X�^19
.EQU	DBSC3_0_DBBL		,	(DBSC3_0_BASE + 0x0B0)	@#	SDRAM����ݒ背�W�X�^
.EQU	DBSC3_0_DBADJ0		,	(DBSC3_0_BASE + 0x0C0)	@#	DBSC3���쒲�����W�X�^0
.EQU	DBSC3_0_DBADJ2		,	(DBSC3_0_BASE + 0x0C8)	@#	DBSC3���쒲�����W�X�^2
.EQU	DBSC3_0_DBRFCNF0	,	(DBSC3_0_BASE + 0x0E0)	@#	���t���b�V���ݒ背�W�X�^0
.EQU	DBSC3_0_DBRFCNF1	,	(DBSC3_0_BASE + 0x0E4)	@#	���t���b�V���ݒ背�W�X�^1
.EQU	DBSC3_0_DBRFCNF2	,	(DBSC3_0_BASE + 0x0E8)	@#	���t���b�V���ݒ背�W�X�^2
.EQU	DBSC3_0_DBCALCNF	,	(DBSC3_0_BASE + 0x0F4)	@#	DDR3-SDRAM�L�����u���[�V�����ݒ背�W�X�^
.EQU	DBSC3_0_DBCALTR		,	(DBSC3_0_BASE + 0x0F8)	@#	DDR3-SDRAM�L�����u���[�V�����^�C�~���O���W�X�^
.EQU	DBSC3_0_DBRNK0		,	(DBSC3_0_BASE + 0x100)	@#	ODT����ݒ背�W�X�^
.EQU	DBSC3_0_DBPDNCNF	,	(DBSC3_0_BASE + 0x180)	@#	�p���[�_�E���ݒ背�W�X�^
.EQU	DBSC3_0_DBDFISTAT	,	(DBSC3_0_BASE + 0x240)	@#	DBI�X�e�[�^�XIF��̓��W�X�^
.EQU	DBSC3_0_DBDFICNT	,	(DBSC3_0_BASE + 0x244)	@#	DBI�X�e�[�^�XIF�o�̓��W�X�^
.EQU	DBSC3_0_DBPDLCK		,	(DBSC3_0_BASE + 0x280)	@#	PHY�����b�N���W�X�^
.EQU	DBSC3_0_DBPDRGA		,	(DBSC3_0_BASE + 0x290)	@#	PHY���������W�X�^�A�h���X
.EQU	DBSC3_0_DBPDRGD		,	(DBSC3_0_BASE + 0x2A0)	@#	PHY���������W�X�^�A�N�Z�X
.EQU	DBSC3_0_DBBS0CNT1	,	(DBSC3_0_BASE + 0x304)	@#	�o�X���䕔0���䃌�W�X�^1
.EQU	DBSC3_0_DBWT0CNF0	,	(DBSC3_0_BASE + 0x380)	@#	AXI�|�[�g�ݒ背�W�X�^0
.EQU	DBSC3_0_DBWT0CNF1	,	(DBSC3_0_BASE + 0x384)	@#	AXI�|�[�g�ݒ背�W�X�^1
.EQU	DBSC3_0_DBWT0CNF2	,	(DBSC3_0_BASE + 0x388)	@#	AXI�|�[�g�ݒ背�W�X�^2
.EQU	DBSC3_0_DBWT0CNF3	,	(DBSC3_0_BASE + 0x38C)	@#	AXI�|�[�g�ݒ背�W�X�^3
.EQU	DBSC3_0_DBWT0CNF4	,	(DBSC3_0_BASE + 0x390)	@#	AXI�|�[�g�ݒ背�W�X�^4
.EQU	DBSC3_0_DBSCHECNT0	,	(DBSC3_0_BASE + 0x500)	@#	�X�P�W���[���ݒ背�W�X�^0

.EQU	DBSC3_1_BASE		,	0xE67A0000
.EQU	DBSC3_1_DBSTATE1	,	(DBSC3_1_BASE + 0x00C)	@#	DBSC3�X�e�[�^�X���W�X�^1
.EQU	DBSC3_1_DBACEN		,	(DBSC3_1_BASE + 0x010)	@#	SDRAM�A�N�Z�X�����W�X�^
.EQU	DBSC3_1_DBRFEN		,	(DBSC3_1_BASE + 0x014)	@#	�������t���b�V�������W�X�^
.EQU	DBSC3_1_DBCMD		,	(DBSC3_1_BASE + 0x018)	@#	�蓮�R�}���h���s���W�X�^
.EQU	DBSC3_1_DBWAIT		,	(DBSC3_1_BASE + 0x01C)	@#	���슮���҂����W�X�^
.EQU	DBSC3_1_DBKIND		,	(DBSC3_1_BASE + 0x020)	@#	SDRAM��ސݒ背�W�X�^
.EQU	DBSC3_1_DBCONF0		,	(DBSC3_1_BASE + 0x024)	@#	SDRAM�\���ݒ背�W�X�^0
.EQU	DBSC3_1_DBPHYTYPE	,	(DBSC3_1_BASE + 0x030)	@#	PHY��ސݒ背�W�X�^
.EQU	DBSC3_1_DBTR0		,	(DBSC3_1_BASE + 0x040)	@#	SDRAM�^�C�~���O���W�X�^0
.EQU	DBSC3_1_DBTR1		,	(DBSC3_1_BASE + 0x044)	@#	SDRAM�^�C�~���O���W�X�^1
.EQU	DBSC3_1_DBTR2		,	(DBSC3_1_BASE + 0x048)	@#	SDRAM�^�C�~���O���W�X�^2
.EQU	DBSC3_1_DBTR3		,	(DBSC3_1_BASE + 0x050)	@#	SDRAM�^�C�~���O���W�X�^3
.EQU	DBSC3_1_DBTR4		,	(DBSC3_1_BASE + 0x054)	@#	SDRAM�^�C�~���O���W�X�^4
.EQU	DBSC3_1_DBTR5		,	(DBSC3_1_BASE + 0x058)	@#	SDRAM�^�C�~���O���W�X�^5
.EQU	DBSC3_1_DBTR6		,	(DBSC3_1_BASE + 0x05C)	@#	SDRAM�^�C�~���O���W�X�^6
.EQU	DBSC3_1_DBTR7		,	(DBSC3_1_BASE + 0x060)	@#	SDRAM�^�C�~���O���W�X�^7
.EQU	DBSC3_1_DBTR8		,	(DBSC3_1_BASE + 0x064)	@#	SDRAM�^�C�~���O���W�X�^8
.EQU	DBSC3_1_DBTR9		,	(DBSC3_1_BASE + 0x068)	@#	SDRAM�^�C�~���O���W�X�^9
.EQU	DBSC3_1_DBTR10		,	(DBSC3_1_BASE + 0x06C)	@#	SDRAM�^�C�~���O���W�X�^10
.EQU	DBSC3_1_DBTR11		,	(DBSC3_1_BASE + 0x070)	@#	SDRAM�^�C�~���O���W�X�^11
.EQU	DBSC3_1_DBTR12		,	(DBSC3_1_BASE + 0x074)	@#	SDRAM�^�C�~���O���W�X�^12
.EQU	DBSC3_1_DBTR13		,	(DBSC3_1_BASE + 0x078)	@#	SDRAM�^�C�~���O���W�X�^13
.EQU	DBSC3_1_DBTR14		,	(DBSC3_1_BASE + 0x07C)	@#	SDRAM�^�C�~���O���W�X�^14
.EQU	DBSC3_1_DBTR15		,	(DBSC3_1_BASE + 0x080)	@#	SDRAM�^�C�~���O���W�X�^15
.EQU	DBSC3_1_DBTR16		,	(DBSC3_1_BASE + 0x084)	@#	SDRAM�^�C�~���O���W�X�^16
.EQU	DBSC3_1_DBTR17		,	(DBSC3_1_BASE + 0x088)	@#	SDRAM�^�C�~���O���W�X�^17
.EQU	DBSC3_1_DBTR18		,	(DBSC3_1_BASE + 0x08C)	@#	SDRAM�^�C�~���O���W�X�^18
.EQU	DBSC3_1_DBTR19		,	(DBSC3_1_BASE + 0x090)	@#	SDRAM�^�C�~���O���W�X�^19
.EQU	DBSC3_1_DBBL		,	(DBSC3_1_BASE + 0x0B0)	@#	SDRAM����ݒ背�W�X�^
.EQU	DBSC3_1_DBADJ0		,	(DBSC3_1_BASE + 0x0C0)	@#	DBSC3���쒲�����W�X�^0
.EQU	DBSC3_1_DBADJ2		,	(DBSC3_1_BASE + 0x0C8)	@#	DBSC3���쒲�����W�X�^2
.EQU	DBSC3_1_DBRFCNF0	,	(DBSC3_1_BASE + 0x0E0)	@#	���t���b�V���ݒ背�W�X�^0
.EQU	DBSC3_1_DBRFCNF1	,	(DBSC3_1_BASE + 0x0E4)	@#	���t���b�V���ݒ背�W�X�^1
.EQU	DBSC3_1_DBRFCNF2	,	(DBSC3_1_BASE + 0x0E8)	@#	���t���b�V���ݒ背�W�X�^2
.EQU	DBSC3_1_DBCALCNF	,	(DBSC3_1_BASE + 0x0F4)	@#	DDR3-SDRAM�L�����u���[�V�����ݒ背�W�X�^
.EQU	DBSC3_1_DBCALTR		,	(DBSC3_1_BASE + 0x0F8)	@#	DDR3-SDRAM�L�����u���[�V�����^�C�~���O���W�X�^
.EQU	DBSC3_1_DBRNK0		,	(DBSC3_1_BASE + 0x100)	@#	ODT����ݒ背�W�X�^
.EQU	DBSC3_1_DBPDNCNF	,	(DBSC3_1_BASE + 0x180)	@#	�p���[�_�E���ݒ背�W�X�^
.EQU	DBSC3_1_DBDFISTAT	,	(DBSC3_1_BASE + 0x240)	@#	DBI�X�e�[�^�XIF��̓��W�X�^
.EQU	DBSC3_1_DBDFICNT	,	(DBSC3_1_BASE + 0x244)	@#	DBI�X�e�[�^�XIF�o�̓��W�X�^
.EQU	DBSC3_1_DBPDLCK		,	(DBSC3_1_BASE + 0x280)	@#	PHY�����b�N���W�X�^
.EQU	DBSC3_1_DBPDRGA		,	(DBSC3_1_BASE + 0x290)	@#	PHY���������W�X�^�A�h���X
.EQU	DBSC3_1_DBPDRGD		,	(DBSC3_1_BASE + 0x2A0)	@#	PHY���������W�X�^�A�N�Z�X
.EQU	DBSC3_1_DBBS0CNT1	,	(DBSC3_1_BASE + 0x304)	@#	�o�X���䕔0���䃌�W�X�^1
.EQU	DBSC3_1_DBWT0CNF0	,	(DBSC3_1_BASE + 0x380)	@#	AXI�|�[�g�ݒ背�W�X�^0
.EQU	DBSC3_1_DBWT0CNF1	,	(DBSC3_1_BASE + 0x384)	@#	AXI�|�[�g�ݒ背�W�X�^1
.EQU	DBSC3_1_DBWT0CNF2	,	(DBSC3_1_BASE + 0x388)	@#	AXI�|�[�g�ݒ背�W�X�^2
.EQU	DBSC3_1_DBWT0CNF3	,	(DBSC3_1_BASE + 0x38C)	@#	AXI�|�[�g�ݒ背�W�X�^3
.EQU	DBSC3_1_DBWT0CNF4	,	(DBSC3_1_BASE + 0x390)	@#	AXI�|�[�g�ݒ背�W�X�^4
.EQU	DBSC3_1_DBSCHECNT0	,	(DBSC3_1_BASE + 0x500)	@#	�X�P�W���[���ݒ背�W�X�^0




@#------------------------------------------------------------------------------
@#CPG : Module Standby, Software Reset
@# R-CarM2_01_07A_CPG_MSTPRST_0010_e.pdf
.EQU	CPG_MSTPRST_BASE	,	0xE6150000
.EQU	CPG_MSTPSR0			,	(CPG_MSTPRST_BASE+0x0030)	@# Module stop status register 0
.EQU	CPG_MSTPSR1			,	(CPG_MSTPRST_BASE+0x0038)	@# Module stop status register 1
.EQU	CPG_MSTPSR2			,	(CPG_MSTPRST_BASE+0x0040)	@# Module stop status register 2
.EQU	CPG_MSTPSR3			,	(CPG_MSTPRST_BASE+0x0048)	@# Module stop status register 3
.EQU	CPG_MSTPSR4			,	(CPG_MSTPRST_BASE+0x004C)	@# Module stop status register 4
.EQU	CPG_MSTPSR5			,	(CPG_MSTPRST_BASE+0x003C)	@# Module stop status register 5
.EQU	CPG_MSTPSR6			,	(CPG_MSTPRST_BASE+0x01C0)	@# Module stop status register 6
.EQU	CPG_MSTPSR7			,	(CPG_MSTPRST_BASE+0x01C4)	@# Module stop status register 7
.EQU	CPG_MSTPSR8			,	(CPG_MSTPRST_BASE+0x09A0)	@# Module stop status register 8
.EQU	CPG_MSTPSR9			,	(CPG_MSTPRST_BASE+0x09A4)	@# Module stop status register 9
.EQU	CPG_MSTPSR10		,	(CPG_MSTPRST_BASE+0x09A8)	@# Module stop status register 10
.EQU	CPG_MSTPSR11		,	(CPG_MSTPRST_BASE+0x09AC)	@# Module stop status register 11

.EQU	CPG_RMSTPCR0		,	(CPG_MSTPRST_BASE+0x0110)	@# Realtime module stop control register 0
.EQU	CPG_RMSTPCR1		,	(CPG_MSTPRST_BASE+0x0114)	@# Realtime module stop control register 1
.EQU	CPG_RMSTPCR2		,	(CPG_MSTPRST_BASE+0x0118)	@# Realtime module stop control register 2
.EQU	CPG_RMSTPCR3		,	(CPG_MSTPRST_BASE+0x011C)	@# Realtime module stop control register 3
.EQU	CPG_RMSTPCR4		,	(CPG_MSTPRST_BASE+0x0120)	@# Realtime module stop control register 4
.EQU	CPG_RMSTPCR5		,	(CPG_MSTPRST_BASE+0x0124)	@# Realtime module stop control register 5
.EQU	CPG_RMSTPCR6		,	(CPG_MSTPRST_BASE+0x0128)	@# Realtime module stop control register 6
.EQU	CPG_RMSTPCR7		,	(CPG_MSTPRST_BASE+0x012C)	@# Realtime module stop control register 7
.EQU	CPG_RMSTPCR8		,	(CPG_MSTPRST_BASE+0x0980)	@# Realtime module stop control register 8
.EQU	CPG_RMSTPCR9		,	(CPG_MSTPRST_BASE+0x0984)	@# Realtime module stop control register 9
.EQU	CPG_RMSTPCR10		,	(CPG_MSTPRST_BASE+0x0988)	@# Realtime module stop control register 10
.EQU	CPG_RMSTPCR11		,	(CPG_MSTPRST_BASE+0x098C)	@# Realtime module stop control register 11

.EQU	CPG_SMSTPCR0		,	(CPG_MSTPRST_BASE+0x0130)	@# System module stop control register 0
.EQU	CPG_SMSTPCR1		,	(CPG_MSTPRST_BASE+0x0134)	@# System module stop control register 1
.EQU	CPG_SMSTPCR2		,	(CPG_MSTPRST_BASE+0x0138)	@# System module stop control register 2
.EQU	CPG_SMSTPCR3		,	(CPG_MSTPRST_BASE+0x013C)	@# System module stop control register 3
.EQU	CPG_SMSTPCR4		,	(CPG_MSTPRST_BASE+0x0140)	@# System module stop control register 4
.EQU	CPG_SMSTPCR5		,	(CPG_MSTPRST_BASE+0x0144)	@# System module stop control register 5
.EQU	CPG_SMSTPCR6		,	(CPG_MSTPRST_BASE+0x0148)	@# System module stop control register 6
.EQU	CPG_SMSTPCR7		,	(CPG_MSTPRST_BASE+0x014C)	@# System module stop control register 7
.EQU	CPG_SMSTPCR8		,	(CPG_MSTPRST_BASE+0x0990)	@# System module stop control register 8
.EQU	CPG_SMSTPCR9		,	(CPG_MSTPRST_BASE+0x0994)	@# System module stop control register 9
.EQU	CPG_SMSTPCR10		,	(CPG_MSTPRST_BASE+0x0998)	@# System module stop control register 10
.EQU	CPG_SMSTPCR11		,	(CPG_MSTPRST_BASE+0x099C)	@# System module stop control register 11

.EQU	CPG_SRCR0			,	(CPG_MSTPRST_BASE+0x00A0)	@# Software reset register 0
.EQU	CPG_SRCR1			,	(CPG_MSTPRST_BASE+0x00A8)	@# Software reset register 1
.EQU	CPG_SRCR2			,	(CPG_MSTPRST_BASE+0x00B0)	@# Software reset register 2
.EQU	CPG_SRCR3			,	(CPG_MSTPRST_BASE+0x00B8)	@# Software reset register 3
.EQU	CPG_SRCR4			,	(CPG_MSTPRST_BASE+0x00BC)	@# Software reset register 4
.EQU	CPG_SRCR5			,	(CPG_MSTPRST_BASE+0x00C4)	@# Software reset register 5
.EQU	CPG_SRCR6			,	(CPG_MSTPRST_BASE+0x01C8)	@# Software reset register 6
.EQU	CPG_SRCR7			,	(CPG_MSTPRST_BASE+0x01CC)	@# Software reset register 7
.EQU	CPG_SRCR8			,	(CPG_MSTPRST_BASE+0x0920)	@# Software reset register 8
.EQU	CPG_SRCR9			,	(CPG_MSTPRST_BASE+0x0924)	@# Software reset register 9
.EQU	CPG_SRCR10			,	(CPG_MSTPRST_BASE+0x0928)	@# Software reset register 10
.EQU	CPG_SRCR11			,	(CPG_MSTPRST_BASE+0x092C)	@# Software reset register 11

.EQU	CPG_SRSTCLR0		,	(CPG_MSTPRST_BASE+0x0940)	@# Software reset clear register 0
.EQU	CPG_SRSTCLR1		,	(CPG_MSTPRST_BASE+0x0944)	@# Software reset clear register 1
.EQU	CPG_SRSTCLR2		,	(CPG_MSTPRST_BASE+0x0948)	@# Software reset clear register 2
.EQU	CPG_SRSTCLR3		,	(CPG_MSTPRST_BASE+0x094C)	@# Software reset clear register 3
.EQU	CPG_SRSTCLR4		,	(CPG_MSTPRST_BASE+0x0950)	@# Software reset clear register 4
.EQU	CPG_SRSTCLR5		,	(CPG_MSTPRST_BASE+0x0954)	@# Software reset clear register 5
.EQU	CPG_SRSTCLR6		,	(CPG_MSTPRST_BASE+0x0958)	@# Software reset clear register 6
.EQU	CPG_SRSTCLR7		,	(CPG_MSTPRST_BASE+0x095C)	@# Software reset clear register 7
.EQU	CPG_SRSTCLR8		,	(CPG_MSTPRST_BASE+0x0960)	@# Software reset clear register 8
.EQU	CPG_SRSTCLR9		,	(CPG_MSTPRST_BASE+0x0964)	@# Software reset clear register 9
.EQU	CPG_SRSTCLR10		,	(CPG_MSTPRST_BASE+0x0968)	@# Software reset clear register 10
.EQU	CPG_SRSTCLR11		,	(CPG_MSTPRST_BASE+0x096C)	@# Software reset clear register 11


@#------------------------------------------------------------------------------
@# RST
@# R-CarM2_01_08_RST_0010_e.pdf
.EQU	RST_BASE		,	0xE6160000
.EQU	RST_MODEMR		,	(RST_BASE + 0x0060)		@# Mode Monitor Register
.EQU	RST_CA15RESCNT	,	(RST_BASE + 0x0040)		@# CA15 Reset Control Register
.EQU	RST_SHXSFTRST	,	(RST_BASE + 0x0048)		@# SH-4A Software Reset Register
.EQU	RST_RESCNT		,	(RST_BASE + 0x0050)		@# Reset Control Register
.EQU	RST_WDTRSTCR	,	(RST_BASE + 0x0054)		@# Watchdog Timer Reset Control Register
.EQU	RST_RSTOUTCR	,	(RST_BASE + 0x0058)		@# PRESETOUT Control Register
.EQU	RST_RBAR		,	(RST_BASE + 0x0000)		@# RT Boot Address Register
.EQU	RST_SBAR		,	(RST_BASE + 0x0010)		@# SYS Boot Address Register
.EQU	RST_SBAR2		,	(RST_BASE + 0x0014)		@# SYS Boot Address Register2
.EQU	RST_RBAR2		,	(RST_BASE + 0x0004)		@# RT Boot Address Register2
.EQU	RST_CA15BAR		,	(RST_BASE + 0x6020)		@# CA15 Boot Address Register
.EQU	RST_CA15BAR2	,	(RST_BASE + 0x6024)		@# CA15 Boot Address Register2

.EQU	RST_SH4AWDTST	,	0xFFEF0080				@# SH-4A watchdog timer stop time register
.EQU	RST_SH4AWDTCSR	,	0xFFEF0084				@# SH-4A watchdog timer control/status register
.EQU	RST_SH4AWDTBST	,	0xFFEF0088				@# SH-4A watchdog timer base stop time register
.EQU	RST_SH4AWDTCNT	,	0xFFEF0090				@# SH-4A watchdog timer counter
.EQU	RST_SH4AWDTBCNT	,	0xFFEF0098				@# SH-4A watchdog timer base counter
.EQU	RST_SH4ARESETVEC,	0xFFEF0040				@# SH-4A reset vector setting register


@#------------------------------------------------------------------------------
@# RWDT
@# R-CarM2_01_66_RWDT_0020_e.pdf
.EQU	RWDT_RWTCNT		,	0xE6020000				@# RCLK watchdog timer counter
.EQU	RWDT_RWTCSRA	,	0xE6020004				@# RCLK watchdog timer control/status register A
.EQU	RWDT_RWTCSRB	,	0xE6020008				@# RCLK watchdog timer control/status register B


@#------------------------------------------------------------------------------
@# secureWDT
@# R-CarM2_01_67_secureWDT_0010_e.pdf
.EQU	SECWDT_WTCNT	,	0xE6030000				@# watchdog timer counter
.EQU	SECWDT_WTCSRA	,	0xE6030004				@# watchdog timer control/status register A
.EQU	SECWDT_WTCSRB	,	0xE6030008				@# watchdog timer control/status register B







@#------------------------------------------------------------------------------
@# S3CTRL
@# R-CarM2_01_17B_S3CTRL_0001_e.pdf
.EQU 	S3CTRL_S3CEXCLADDMSK	,	0xE6784000		@# Exclusive Address Mask Register
.EQU 	S3CTRL_S3CEXCLIDMSK		,	0xE6784004		@# Exclusive ID Mask Register
.EQU 	S3CTRL_S3CADSPLCR		,	0xE6784008		@# S3C Address Split Control Register
.EQU 	S3CTRL_S3CMAAR			,	0xE678400C		@# S3C Mirror Area Address Register





