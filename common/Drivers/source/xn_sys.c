/* Includes ------------------------------------------------------------------*/

#include "XN11Exxx.h"
#include "xn_timer.h"
#include "xn_sys.h"
#include "xn_ioconfig.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	SYS_SystemInitial
Function Definition	void SYS_SystemInitial(void)
Function Description	Initial system-configure clock, IO pin function
Input Parameters	None
Return Value	None
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SystemInitial(void)
{
	//Patch
	if (DIA->IRCTRIM!=0xFFFFFFFF)
	XN_SYSCON->IRCCTRL.all=DIA->IRCTRIM; //Redo trim to IRC to make sure IRC working on right frequency in debug mode
	//initial main clk to 48M
	XN_SYSCON->IRCCTRL.bit.SW=1;

	FMC->FLASH_RDCYC=2;
	XN_SYSCON->SYSAHBCLKDIV.all=1;
	SystemCoreClockUpdate ();	
	

	CAPTOUCH->CTRL |=0x10; //select internal touch resister, remove effect to PIO0_15 and PIO1_3
	LCDCON->LCDOUTEN0=0;
	LCDCON->LCDOUTEN1=0;	
	//Configure WDT clock if need
	
	//Configure RTC clock if need
	#ifdef ENABLE_RTCOSC
	PIO2_14_INIT (PIO2_14_OSC32_IN);					//Init PIO2_14 function as RTC OSC PIN
	PIO2_15_INIT (PIO2_15_OSC32_OUT );				//Init PIO2_15 function as  RTC OSC PIN
	SYS_PowerUpAngIP (PD_RTCOSC ); 		//Power On RTC OSC 

	#endif
	

	//Configure peripheral IO pin
	
	#ifdef ENABLE_UART0
	/**********UART0************************************************************/
	//RXD0 	v	v	v	v	I	PIO0_3 	PIO0_10
	PIO0_3_INIT (PIO0_3_RXD0 );
	//TXD0 	v	v	v	v	O	PIO0_2 	PIO0_9 
	PIO0_2_INIT(PIO0_2_TXD0 );

	#endif
	#ifdef ENABLE_UART1
	/**********UART1************************************************************/
	//RXD1 	v	v	v		I	PIO0_15 	PIO1_7
	PIO1_7_INIT (PIO1_7_RXD1 );
	//TXD1 	v	v	v		O	PIO0_14	PIO1_6 
	PIO1_6_INIT (PIO1_6_TXD1 );
	#endif
	
	/**********CT16B2************************************************************/
	//CT16B2_CAP0 	v	v	v	v	I	PIO0_6	PIO1_4
	//CT16B2_CAP1 	v		v	v	I	PIO0_7	PIO1_5
	//CT16B2_CAP2 	v	v	v		I	PIO1_0	PIO0_11
	//CT16B2_CAP3 	v		v		I	PIO1_1	PIO1_14
	//CT16B2_MAT0 	v	v	v	v	O	PIO0_6 	PIO1_4
	//CT16B2_MAT1	v		v	v	O	PIO0_7	PIO1_5
	//CT16B2_MAT2 	v	v	v		O	PIO1_0	PIO0_11
	//CT16B2_MAT3	v		v		I	PIO1_1	PIO1_14

	#ifdef ENABLE_CT16B3
	/**********CT16B3************************************************************/
	//CT16B3_CAP0 	v	v	v	v	I	PIO0_2 	PIO1_6
	//CT16B3_CAP1 	v	v	v	v	I	PIO0_3	PIO1_7
	PIO1_7_INIT (PIO1_7_CT16B3_CAP1 );
	//CT16B3_CAP2	v		v	v	I	PIO0_4	PIO1_8
	//CT16B3_CAP3	v	v	v		I	PIO1_15	PIO0_8
	PIO1_15_INIT (PIO1_15_CT16B3_CAP3 );
	//CT16B3_MAT0 	v	v	v	v	O	PIO0_2 	PIO1_6
	//CT16B3_MAT1 	v	v	v	v	O	PIO0_3	PIO1_7
	//CT16B3_MAT2	v		v	v	O	PIO0_4	PIO1_8
	//CT16B3_MAT3	v	v	v		O	PIO1_15	PIO0_8
	#endif

	#ifdef ENABLE_SPI
	/**********SPI***************************************************************/
	//SSEL I/O:	PIO0_4	P0_15	PIO1_12
	PIO0_4_INIT (PIO0_4_SPI_SSEL );	//avaible on LQFP48, QFN32, SOP28, SSOP20 		 
	//PIO0_15_INIT (PIO0_15_SPI_SSEL );			//avaible on LQFP48, QFN32, SOP28
	//PIO1_12_INIT (PIO1_13_SPI_SSEL );	//avaible on LQFP48
	
	//SCK I/O:	PIO0_5	P1_3	PIO1_13
	PIO0_5_INIT (PIO0_5_SPI_SCK );	//avaible on LQFP48, QFN32, SOP28	 
	//PIO1_3_INIT (PIO1_3_SPI_SCK );			//avaible on LQFP48, QFN32, SOP28 
	//PIO1_13_INIT (PIO1_13_SPI_SCK );	//avaible on LQFP48, QFN32, SSOP20 
	
	//MISO I/O:		P1_4	PIO1_14
	PIO1_4_INIT (PIO1_4_SPI_MISO);		//avaible on LQFP48, QFN32, SOP28	
	//XN_IOCON->PIO1_14.all=0x231;	//avaible on LQFP48, SSOP20
	
	//MOSII/O:		P1_5	PIO1_15
	PIO1_5_INIT (PIO1_5_SPI_MOSI );		//avaible on LQFP48, QFN32, SOP28
	//PIO1_15_INIT (PIO1_15_SPI_MISO);	//avaible on LQFP48, SSOP20
	#endif
	
	#ifdef ENABLE_TWS
	/**********TWS************************************************************/
	//SCL 	v	v	v	v	I/O	PIO1_10 	PIO0_9 	PIO1_8	PIO2_10 	PIO1_6
	PIO1_8_INIT (PIO1_8_TWS_SCL );
	//SDA 	v	v	v	v	I/O	PIO1_11 	PIO0_10 	PIO1_9	PIO2_11	PIO1_7
	PIO1_9_INIT (PIO1_9_TWS_SDA );
	#endif
	
	#ifdef ENABLE_ADC
	/**********ADC************************************************************/
	//AD0	v	v	v	v	I	PIO0_0 
	PIO0_0_INIT (PIO0_0_ADC_IN0 );
	//AD1 	v	v	v	v	I	PIO0_1 
	//PIO0_1_INIT (PIO0_1_ADC_IN1 );
	//AD2 	v	v	v	v	I	PIO0_2 
	//PIO0_2_INIT (PIO0_2_ADC_IN2 );
	//AD3 	v	v	v	v	I	PIO0_3 
	//PIO0_3_INIT (PIO0_3_ADC_IN3 );
	//AD4 	v	v	v	v	I	PIO0_4 
	//PIO0_4_INIT (PIO0_4_ADC_IN4 );
	//AD5 	v	v	v	v	I	PIO0_5 
	//PIO0_5_INIT (PIO0_5_ADC_IN5 );
	//AD6 	v	v	v	v	I	PIO0_6 
	//PIO0_6_INIT (PIO0_6_ADC_IN6 );
	//AD7 	v	v	v	v	I	PIO0_7 
	//PIO0_7_INIT (PIO0_7_ADC_IN7 );
	#endif
	
	#ifdef ENABLE_LCD
	/**********LCD************************************************************/
	//initial LCD pin
	//LCD_COM0 	¡Ì			O	PIO1_2
	PIO1_2_INIT (PIO1_2_LCD_COM0 );
	//LCD_COM1 	¡Ì			O	PIO1_10
	PIO1_10_INIT (PIO1_10_LCD_COM1 );
	//LCD_COM2 	¡Ì			O	PIO1_11
	PIO1_11_INIT (PIO1_11_LCD_COM2 );
	//LCD_COM3 	¡Ì	¡Ì		O	PIO1_6
	PIO1_6_INIT (PIO1_6_LCD_COM3 );
	//LCD_COM4 	¡Ì	¡Ì		O	PIO1_7
	//LCD_COM5	¡Ì	¡Ì		O	PIO2_12
	//LCD_SEG0 	¡Ì			O	PIO1_12
	PIO1_12_INIT (PIO1_12_LCD_SEG0 );
	//LCD_SEG1 	¡Ì			O	PIO1_13
	PIO1_13_INIT (PIO1_13_LCD_SEG1 );
	//LCD_SEG2	¡Ì			O	PIO1_14
	PIO1_14_INIT (PIO1_14_LCD_SEG2 );
	//LCD_SEG3 	¡Ì			O	PIO1_15
	PIO1_15_INIT (PIO1_15_LCD_SEG3 );
	//LCD_SEG4	¡Ì	¡Ì		O	PIO0_8
	PIO0_8_INIT (PIO0_8_LCD_SEG4 );
	//LCD_SEG5	¡Ì	¡Ì		O	PIO0_9
	PIO0_9_INIT (PIO0_9_LCD_SEG5 );
	//LCD_SEG6	¡Ì	¡Ì		O	PIO0_10
	PIO0_10_INIT (PIO0_10_LCD_SEG6 );
	//LCD_SEG7	¡Ì	¡Ì		O	PIO0_11
	PIO0_11_INIT (PIO0_11_LCD_SEG7 ); 
	//LCD_SEG8	¡Ì	¡Ì		O	PIO0_12
	//LCD_SEG9	¡Ì	¡Ì		O	PIO0_13
	//LCD_SEG10	¡Ì			O	PIO2_10
	//LCD_SEG11	¡Ì			O	PIO2_11
	//LCD_SEG12	¡Ì			O	PIO2_7
	//LCD_SEG13	¡Ì			O	PIO2_8
	//LCD_SEG14	¡Ì			O	PIO1_8
	//LCD_SEG15	¡Ì			O	PIO1_9
	#endif
	
	/**********LED************************************************************/
	//LED_COM0	v	v			O	PIO0_0
	//LED_COM1	v	v			O	PIO0_1
	//LED_COM2	v	v			O	PIO0_2
	//LED_COM3	v	v			O	PIO0_3
	//LED_COM4	v				O	PIO1_0
	//LED_COM5	v				O	PIO1_1
	//LED_COM6	v				O	PIO1_2
	//LED_COM7	v				O	PIO1_10
	//LED_SEG0	v	v			O	PIO0_4
	//LED_SEG1	v	v			O	PIO0_5
	//LED_SEG2	v	v			O	PIO0_6
	//LED_SEG3	v	v			O	PIO0_7
	//LED_SEG4	v	v			O	PIO1_11
	//LED_SEG5	v	v			O	PIO1_12
	//LED_SEG6	v				O	PIO1_13
	//LED_SEG7	v				O	PIO1_14

	#ifdef ENABLE_CAPTOUCH
	/**********CAPTOUCH********************************************************/
	//TOUCH0	v				I/O	PIO1_15
	//PIO1_15_INIT (PIO1_15_TOUCH0 );
	//TOUCH1	v	v	v		I/O	PIO0_8
	//PIO0_8_INIT (PIO0_8_TOUCH1 );
	//TOUCH2	v	v	v	v	I/O	PIO0_9
	//PIO0_9_INIT (PIO0_9_TOUCH2 );
	//TOUCH3	v	v	v	v	I/O	PIO0_10
	//PIO0_10_INIT (PIO0_10_TOUCH3 );
	//TOUCH4	v	v	v		I/O	PIO0_11
	//PIO0_11_INIT (PIO0_11_TOUCH4 );
	//TOUCH5	v	v			I/O	PIO0_12
	//PIO0_12_INIT (PIO0_12_TOUCH5 );
	//TOUCH6	v	v	v	v	I/O	PIO0_13
	//PIO0_13_INIT (PIO0_13_TOUCH6 );
	//TOUCH7	v				I/O	PIO2_10
	PIO2_10_INIT (PIO2_10_TOUCH7 );
	//TOUCH8	v				I/O	PIO2_11
	PIO2_11_INIT (PIO2_11_TOUCH8 );
	//TOUCH9	v	v	v	v	I/O	PIO0_14
	//PIO0_14_INIT (PIO0_14_TOUCH9 );
	//TOUCH10	v	v	v		I/O	PIO1_4
	//PIO1_4_INIT (PIO1_4_TOUCH10 );
	//XN_IOCON->PIO1_5.all = 0x107;
	//PIO1_5_INIT (PIO1_5_TOUCH11 );
	//XN_IOCON->PIO2_12.all = 0x107;
	//PIO2_12_INIT (PIO2_12_TOUCH12 );
	//TOUCH13	v				I/O	P1_8
	//PIO1_8_INIT (PIO1_8_TOUCH13 );
	//TOUCH14	v				I/O	P1_9
	//PIO1_9_INIT (PIO1_9_TOUCH14);
	//TOUCH15	v				I/O	P2_13
	//PIO2_13_INIT (PIO2_13_TOUCH15 );
	//TOUCH16	v	v			I/O	P2_14
	//PIO2_14_INIT (PIO2_14_TOUCH16 );
	//TOUCH17	v	v			I/O	P2_15
	//PIO2_15_INIT (PIO2_15_TOUCH17 );
	//TOUCH18	v			v	I/O	P2_7
	//PIO2_7_INIT (PIO2_7_TOUCH18 );
	//TOUCH19	v		v	v	I/O	P2_8
	//PIO2_8_INIT (PIO2_8_TOUCH19 );
	//TOUCH20	v	v	v	v	I/O	P2_9
	//PIO2_9_INIT (PIO2_9_TOUCH20 );
	//TOUCH21	v	v	v		I/O	P1_7
	//PIO1_7_INIT (PIO1_7_TOUCH21 );
	//TOUCH_OUT	v	v	v		O	P0_15
	//PIO0_15_INIT (PIO0_15_TOUCH_OUT );
	//TOUCH_IN	v	v	v		I	P1_3
	//PIO1_3_INIT (PIO1_3_TOUCH_IN );
		
	#endif
	
	#ifdef ENABLE_PWM
	/**********PWM************************************************************/
	//PWM_OUT0	v	v	v		O	PIO0_8
	PIO0_8_INIT (PIO0_8_PWM_OUT0 );
	//PWM_OUT1	v	v	v	v	O	PIO0_7	PIO1_13
	PIO0_7_INIT (PIO0_7_PWM_OUT1 );
	//PWM_OUT2	v	v	v	v	O	PIO0_9	
	PIO0_9_INIT (PIO0_9_PWM_OUT2 );
	//PWM_OUT3	v	v	v		O	PIO1_0	PIO1_14
	PIO1_0_INIT (PIO1_0_PWM_OUT3 );
	//PWM_OUT4	v	v	v	v	O	PIO0_10	
	PIO0_10_INIT (PIO0_10_PWM_OUT4 );
	//PWM_OUT5	v	v	v	v	O	PIO1_1	PIO1_15
	PIO1_1_INIT (PIO1_1_PWM_OUT5 );
	//PWM_FAULT	v	v	v	v	I	PIO0_6	PIO1_12	
	//PIO1_12_INIT ( PIO1_12_PWM_FAULT);
	#endif
	
	
	return;
}
/*****************************************************************************
Function Name	SYS_SelectMainClkSrc
Function Definition	Void SYS_SelectMainClkSrc(uint8_t src)
Function Description	Select Main clcok source
Input Parameters	src:IRC_CLK
								WDT_CLK
Other are invalid
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SelectMainClkSrc(uint8_t src)
{
	//switch main clk source
	XN_SYSCON->MAINCLKUEN.bit.ENA= 1;					//disable main clk update
	//switch main clk source to Specifyed source
	if (src==IRC_CLK)
		XN_SYSCON->MAINCLKSEL.bit.SEL=0;
	else if (src==WDT_CLK)
		XN_SYSCON->MAINCLKSEL.bit.SEL=2; 	
	XN_SYSCON->MAINCLKUEN.bit.ENA=0; 						//enable main clk update
	
	SystemCoreClockUpdate ();
	return;
}
/*****************************************************************************
Function Name	SYS_SetAHBClkDivider
Function Definition	Void SYS_SetAHBClkDivider (uint8_t div)
Function Description	Set divider, that divides the main clock to provide the system clock to the core, memories,and the peripherals.
Input Parameters	div:1~255, 0 is forbidented
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SetAHBClkDivider (uint8_t div)
{
// 	if (((*XN_SYSCON).MAINCLKSEL.bit.SEL==0)&&(div<2))
// 			(*FMC).FLASH_RDCYC = 1;
	
	(*XN_SYSCON).SYSAHBCLKDIV.bit.DIV = div;
	SystemCoreClockUpdate ();   
	return;
}
/*****************************************************************************
Function Name	SYS_SelectWDTClkSrc
Function Definition	Void SYS_SelectWDTClkSrc(uint8_t src)
Function Description	Select clock source as WDT counter clock.
Input Parameters	src:IRC_CLK
WDT_CLK
Other are invalid
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SelectWDTClkSrc(uint8_t src)
{
	if (src==IRC_CLK)
		(*XN_SYSCON).WDTOSCCTRL.bit.WDTCLKSRC = 0;
	else if (src==WDT_CLK)
		(*XN_SYSCON).WDTOSCCTRL.bit.WDTCLKSRC = 1;
 
	return;
}

/*****************************************************************************
Function Name	SYS_SelectClkOutSrc
Function Definition	SYS_SelectClkOutSrc(uint8_t src)
Function Description	Select clock source as clock output
Input Parameters	src:IRC_CLK
											SYS_CLK
											WDT_CLK
											MAIN_CLK
											RTC_CLK
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SelectClkOutSrc(uint8_t src)
{
	switch (src)
	{
		case IRC_CLK:
			src=0;
		break;
		case SYS_CLK:
			src=1;
		break;
		case WDT_CLK:
			src=2;
		break;
		case MAIN_CLK:
			src=3;
		break;
		case RTC_CLK:
			src=4;
		break;
		default:
			return;
	}
	//switch clock
	(*XN_SYSCON).CLKOUTUEN.bit.ENA = 1;
	(*XN_SYSCON).CLKOUTCLKSEL.bit.SEL = src; 	//select clk out source
	(*XN_SYSCON).CLKOUTUEN.bit.ENA = 0;
 
	return;
}

/*****************************************************************************
Function Name	SYS_SetClkOutDivider
Function Definition	SYS_SetClkOutDivider(uint8_t src)
Function Description	Select clock source as clock output
Input Parameters	div:Clock output divider, valid 1~255 
											0: clock is disable
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SetClkOutDivider(uint8_t div)
{
	(*XN_SYSCON).CLKOUTDIV.bit.DIV = div;
 
	return;
}

/*****************************************************************************
Function Name	SYS_EnableClkOut
Function Description	Enable clock output
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_EnableClkOut(void)
{
	(*XN_IOCON).PIO2_8.all = 0x231;   							//enable clock out pin 
 
	return;
}

/*****************************************************************************
Function Name	SYS_DisableClkOut
Function Definition	Void SYS_DisableClkOut(void)
Function Description	Disable clock output
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_DisableClkOut(void)
{
	(*XN_SYSCON).CLKOUTDIV.bit.DIV = 0;
	(*XN_IOCON).PIO2_8.all = 0x230;   							//enable clock out pin 
 
	return;
}
/*****************************************************************************
Function Name	SYS_SetIOFilter
Function Definition	Void SYS_SetIOFilter(uint8_t ticks)
Function Description	Set IO filter 
Input Parameters	Ticks: 1~255, every ticks sample IO input
0, no sample
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SetIOFilter(uint8_t ticks)
{
	(*XN_SYSCON).IOCONFIGCLKDIV.bit.DIV = ticks;
 
	return;
}
/*****************************************************************************
Function Name	SYS_PowerDownAngIP
Function Definition	SYS_PowerDownAngIP(uint32_t angips)
Function Description	Shut down specific analog IPs power supply
Input Parameters	Angips: analog IPs bit
Valid bit values are PD_IRC, PD_BOD, PD_ADC, PD_RTC, PD_WDTOSC, PD_LCD, PD_TOUCH
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_PowerDownAngIP(uint32_t angips)
{
	(*XN_SYSCON).PDRUNCFG.all |= angips;
 
	return;
}
/*****************************************************************************
Function Name	SYS_PowerUpAngIP
Function Definition	SYS_PowerUpAngIP(uint32_t angips)
Function Description	Power up specific analog IPs power supply
Input Parameters	Angips: analog IPs bit 
Valid bit values are PD_IRC, PD_BOD, PD_ADC, PD_RTC, PD_WDTOSC, PD_LCD, PD_TOUCH
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_PowerUpAngIP(uint32_t angips)
{
	(*XN_SYSCON).PDRUNCFG.all &= ~angips;
 
	return;
}
/*****************************************************************************
Function Name	SYS_EnablePhrClk
Function Definition	void SYS_EnablePhrClk(uint32_t phrs)
Function Description	Enable specific peripherals clock
Input Parameters	phrs: peripherals clock bit 
Valid bit values are AHB_TWS, AHB_CRC, AHB_CT16B0, AHB_CT16B1, AHB_CT16B2, 
	AHB_CT16B3, AHB_SPI, AHB_UART0, AHB_UART1,AHB_ADC, AHB_WDT, AHB_IOCON, 
	AHB_PWM,AHB_LCD, AHB_RTC,AHB_TOUCH 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_EnablePhrClk(uint32_t phrs)
{
	(*XN_SYSCON).SYSAHBCLKCTRL.all |= phrs;
 
	return;
}
/*****************************************************************************
Function Name	SYS_DisablePhrClk
Function Definition	void SYS_DisablePhrClk(uint32_t phrs)
Function Description	Disable specific peripherals clock
Input Parameters	phrs: peripherals clock bit 
Valid bit values are AHB_TWS, AHB_CRC, AHB_CT16B0, AHB_CT16B1, AHB_CT16B2, 
AHB_CT16B3, AHB_SPI, AHB_UART0, AHB_UART1,AHB_ADC, AHB_WDT, AHB_IOCON, 
AHB_PWM,AHB_LCD, AHB_RTC,AHB_TOUCH 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_DisablePhrClk(uint32_t phrs)
{
	(*XN_SYSCON).SYSAHBCLKCTRL.all &= ~phrs;
 
	return;
}
/*****************************************************************************
Function Name	SYS_ResetPhr
Function Definition	void SYS_ResetPhr(uint32_t phrs)
Function Description	Reset specific peripherals 
Input Parameters	phrs: peripherals clock bit 
Valid bit values are RTS_TWS, RST_CRC, RST_CT16B0, RST_CT16B1, RST_CT16B2, 
RST_CT16B3, RST_SPI, RST_UART0, RST_UART1,RST_ADC, RST_WDT, 
RST_IOCON, RST_PWM,RST_LCD, RST_RTC,RST_TOUCH 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_ResetPhr(uint32_t phrs)
{
	(*XN_SYSCON).PRESETCTRL.all &= ~phrs;
	(*XN_SYSCON).PRESETCTRL.all |= phrs;
	return;
}
/*****************************************************************************
Function Name	SYS_ResetSystem
Function Definition	void SYS_ResetSystem(void)
Function Description	Software Reset system
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_ResetSystem(void)
{
	NVIC_SystemReset();
}
/*****************************************************************************
Function Name	SYS_BODResetSystem
Function Definition	void SYS_BODResetSystem (uint8_t bodsel)
Function Description	Enable BOD and config BOD Reset option
Input Parameters	Bodsel: 
BOD_INT
BOD_RESET
Other values are invalid
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_BODResetSystem (uint8_t bodsel)
{
	if (bodsel==BOD_RESET)
	{
		XN_SYSCON->BODCTRL.bit.BODRSTEN=1 ;
	}
	else
	{
		XN_SYSCON->BODCTRL.bit.BODRSTEN = 0 ;
		XN_SYSCON->BODCTRL.bit.BODINTCLR = 1;
	}
	return;
}
/*****************************************************************************
Function Name	SYS_GetResetStatus
Function Definition	uint32_t SYS_GetResetStatus(void)
Function Description	Return reset status
Input Parameters	No
Return Value	Reset status
				Bit0 	POR 
				Bit1 	EXTRST
				Bit2 	WDT 
				Bit3 	BOD 
				Bit4 	SYSRST
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
uint32_t SYS_GetResetStatus(void)
{
	return XN_SYSCON->SYSRESSTAT.all;
}
/*****************************************************************************
Function Name	SYS_ClearResetStatus
Function Definition	void SYS_ClearResetStatus (void)
Function Description	Clear reset status
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_ClearResetStatus (void)
{
	XN_SYSCON->SYSRESSTAT.all=0xFF;
	return;
}
/*****************************************************************************
Function Name	SYS_EnterSleep
Function Definition	void SYS_EnterSleep (void)
Function Description	Enter sleep mode
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_EnterSleep (void)
{
	//Sleep
	(*XN_PMU).PCON.bit.DPDEN = 0;			//sleep
	SCB->SCR &= ~(1<<2);							//sleep
	
	//issue sleep command
	__WFI();	//enter sleep
	return;
}
/*****************************************************************************
Function Name	SYS_SetDeepSleepWakeupPin
Function Definition	void SYS_SetDeepSleepWakeupPin (uint16_t selio, uint16_t edge)
Function Description	Set deep sleep wake up pin
Input Parameters	Selio:IO_PIN0~PIN11
Edge: FALL_EDGE/RISE_EDGE
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_SetDeepSleepWakeupPin (uint16_t selio, uint16_t edge)
{
	
	(*XN_SYSCON).DSWAKECTL.all	|=1<<16;
	
	(*XN_SYSCON).DSWAKEEN.all		|= selio;		//enable the pin
	
	if(edge == FALL_EDGE)
	{
		(*XN_SYSCON).DSWAKECTL.all &=~ selio;
	}
	else
	{
		(*XN_SYSCON).DSWAKECTL.all	|= selio;			//wake up signal
	}
	
	SYSCON->DSWAKECLR=1;	//clear int status
	* (uint32_t *)0xE000E280 = 0xffffffff;
	NVIC_EnableIRQ(WAKEUP_IRQn); 				//enable Wakeup IRQ
	
	return;
}
/*****************************************************************************
Function Name	SYS_ResetDeepSleepWakeupPin
Function Definition	void SYS_ResetDeepSleepWakeupPin(void)
Function Description	Reset all deep sleep wake pin . The wakeup pin must be reset before use.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_ResetDeepSleepWakeupPin(void)
{
	(*XN_SYSCON).DSWAKEEN.all		= 0;
	(*XN_SYSCON).DSWAKECLR.all	= 0xFFF;			//clear int status

}
/*****************************************************************************
Function Name	SYS_EnterDeepSleep
Function Definition	void SYS_EnterDeepSleep (uint32_t deepsleepconfig, uint32_t wakeupconfig)
Function Description	Enter deep sleep mode
Input Parameters	deepsleepconfig: config PDSLEEPCFG. Avalable bit PD_BOD, PD_RTCOSC and PD_WDTOSC. 
									If WDTOSC_PD bit is not set, the system won't wakeup except power up
			Wakeupconfig: config PDAWAKECFG. Avalable bit PD_IRC, PD_BOD, PD_ADC, PD_RTC, PD_WDTOSC, PD_LCD, PD_TOUCH. 
			If bit is set, the IP will power down after wake up from deep sleep.
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_EnterDeepSleep(uint32_t deepsleepconfig, uint32_t wakeupconfig)
{
	uint32_t volatile i=0;
	//if WDT osc is not powered, power osc and wait for stable
	if ((*XN_SYSCON).PDRUNCFG.bit.WDTOSC_PD != 0)
	{
		(*XN_SYSCON).PDRUNCFG.bit.WDTOSC_PD = 0;
		
		//wait for a while
		while(i++<0xff);
	}
	
	//set WDT osc as back up clk for powerdown
	(*XN_SYSCON).PDSLEEPCFG.all = ~deepsleepconfig;
	(*XN_SYSCON).PDAWAKECFG.all = ~(wakeupconfig|PD_IRC|0x4); //bit 2 must be 0
	//switch main clk to WDT osc
	(*XN_SYSCON).MAINCLKUEN.bit.ENA = 1;
	(*XN_SYSCON).MAINCLKSEL.bit.SEL = 2;
	(*XN_SYSCON).MAINCLKUEN.bit.ENA = 0;

	//Deep Sleep
	(*XN_PMU).PCON.bit.DPDEN = 0; 		//deep sleep
	SCB->SCR |= (1<<2);								//deep sleep
	
	//issue deep sleep command
	__WFI();	//enter deep sleep
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	
	//switch back to IRC
	(*XN_SYSCON).MAINCLKUEN.bit.ENA = 1;
	(*XN_SYSCON).MAINCLKSEL.bit.SEL = 0;
	(*XN_SYSCON).MAINCLKUEN.bit.ENA = 0;

	return;
}
/*****************************************************************************
Function Name	SYS_EnterPowerDown
Function Definition	void SYS_EnterPowerDown (uint32_t powerdownconfig)
Function Description	Enter sleep mode
Input Parameters	powerdownconfig : config PDSLEEPCFG. Avalable bit  PD_RTCOSC . 
	If bit is set, the IP will power down duing deep sleep.
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_EnterPowerDown(uint32_t powerdownconfig)
{
	if (powerdownconfig & PD_RTCOSC)
		(*XN_SYSCON).PDSLEEPCFG.bit.RTCOSC_PD	=0;
	else
		(*XN_SYSCON).PDSLEEPCFG.bit.RTCOSC_PD	= 1;
	
	(*XN_SYSCON).PDSLEEPCFG.bit.BOD_PD = 1;
	(*XN_SYSCON).PDSLEEPCFG.bit.WDTOSC_PD	= 1;
	
	//Power Down
	(*XN_PMU).PCON.bit.DPDEN = 1;
	
	SCB->SCR |= (1<<2);	//deep sleep	
	
	__WFI();	//enter power down
}
/*****************************************************************************
Function Name	SYS_IOConfig
Function Definition	void SYS_IOConfig(IOCON_REG *pio, uint32_t config)
Function Description	Config IO pin
Input Parameters	*pio : pointer to IOCON. IOCON->PIO0_0~ IOCON->PIO0_15, IOCON->PIO1_0~ IOCON->PIO1_15, IOCON->PIO2_7~ IOCON->PIO0_15
Config: IO config value
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_IOConfig(volatile union IOCON_REG *pio, uint32_t config)
{
	pio->all=config;
	return;
}
/*****************************************************************************
Function Name	SYS_IOSetPullup
Function Definition	void SYS_IOSetPullup(IOCON_REG *pio)
Function Description	Config IO pin pull up
Input Parameters	*pio : pointer to IOCON’s IO. IOCON->PIO0_0~ IOCON->PIO0_15, IOCON->PIO1_0~ IOCON->PIO1_15, IOCON->PIO2_7~ IOCON->PIO0_15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_IOSetPullup(volatile union IOCON_REG *pio)
{
	pio->bit.PDE=0;
	pio->bit.PUE=1;
	
	return;
}
/*****************************************************************************
Function Name	SYS_IOSetPulldown
Function Definition	void SYS_IOSetPulldown (IOCON_REG *pio)
Function Description	Config IO pin pull down
Input Parameters	*pio : pointer to IOCON’s IO. IOCON->PIO0_0~ IOCON->PIO0_15, IOCON->PIO1_0~ IOCON->PIO1_15, IOCON->PIO2_7~ IOCON->PIO0_15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_IOSetPulldown (volatile union IOCON_REG *pio)
{
	pio->bit.PUE=0;
	pio->bit.PDE=1;
	return;
}
/*****************************************************************************
Function Name	SYS_IOSwitchtoAng
Function Definition	void SYS_IOSwitchtoAng (IOCON_REG *pio)
Function Description	Switch IO pin to analog function
Input Parameters	*pio : pointer to IOCON’s IO. IOCON->PIO0_0~ IOCON->PIO0_15, IOCON->PIO1_0~ IOCON->PIO1_15, IOCON->PIO2_7~ IOCON->PIO0_15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_IOSwitchtoAng (volatile union IOCON_REG *pio)
{
	pio->bit.ADM=0;
	return;
}
/*****************************************************************************
Function Name	SYS_IOSwitchtoDigit
Function Definition	void SYS_IOSwitchtoDigit (IOCON_REG *pio)
Function Description	Switch IO pin digital function
Input Parameters	*pio : pointer to IOCON’s IO. IOCON->PIO0_0~ IOCON->PIO0_15, IOCON->PIO1_0~ IOCON->PIO1_15, IOCON->PIO2_7~ IOCON->PIO0_15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_IOSwitchtoDigit (volatile union IOCON_REG *pio)
{
	pio->bit.ADM=1;
	return;
}
/*****************************************************************************
Function Name	SYS_IOEnableFilter
Function Definition	void SYS_IOEnableFilter (IOCON_REG *pio)
Function Description	Enable IO pin filter function
Input Parameters	*pio : pointer to IOCON’s IO. IOCON->PIO0_0~ IOCON->PIO0_15, IOCON->PIO1_0~ IOCON->PIO1_15, IOCON->PIO2_7~ IOCON->PIO0_15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_IOEnableFilter (volatile union IOCON_REG *pio)
{
	pio->bit.S_MODE=1;
	return;
}
/*****************************************************************************
Function Name	SYS_ IODisableFilter
Function Definition	void SYS_ IODisableFilter (IOCON_REG *pio)
Function Description	Disable IO pin filter function
Input Parameters	*pio : pointer to IOCON’s IO. IOCON->PIO0_0~ IOCON->PIO0_15, IOCON->PIO1_0~ IOCON->PIO1_15, IOCON->PIO2_7~ IOCON->PIO0_15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void SYS_IODisableFilter (volatile union IOCON_REG *pio)
{
	pio->bit.S_MODE=0;
	return;
}
