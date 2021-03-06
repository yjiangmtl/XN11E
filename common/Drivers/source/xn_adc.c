/*****************************************************************************
 *   xn_adc.c:  Header file for Xinnova XN11
 *
 *   Copyright(C) 20012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2012.07.21  ver 1.01    Prelimnary version
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "XN11Exxx.h"
#include "xn_sys.h"
#include "xn_adc.h"

extern uint32_t SystemCoreClock;

/*****************************************************************************
Function Name	ADC_Init
Function Definition	void ADC_Init(uint32_t conversionrate)
Function Description	Initial ADC module
Input Parameters	Conversionrate: conversion rate, must less 1000000 (1MHz)
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_Init(uint32_t conversionrate)
{
	uint32_t temp,div;

	//Power up ADC
	(*XN_SYSCON).PDRUNCFG.bit.ADC_PD = 0;
	
	//enable clock of ADC digital
	(*XN_SYSCON).SYSAHBCLKCTRL.bit.ADCCLK = 1;

	//reset ADC digital
	(*XN_SYSCON).PRESETCTRL.bit.ADC_RST_N = 0;
	(*XN_SYSCON).PRESETCTRL.bit.ADC_RST_N = 1;

	//limit convertion rate to 1M/s
	if (conversionrate>1000000)
		conversionrate = 1000000;
	conversionrate=conversionrate<<4;
	
	//caculate clk divider
	div = SystemCoreClock/conversionrate;

	if (((div*conversionrate)!=SystemCoreClock)&&(SystemCoreClock>16000000*div))
		div++;
	
	//set up divider
	(*XN_ADC).CR.bit.CLKDIV = div;
	
	//insert a delay
	temp=0xff;
	while (temp--);
	
	//select external sample clk
	(*XN_ADC).CR.bit.SCMODE=1;
	
	//wait untile adc ready
	while((*XN_ADC).STAT.bit.ADCRDY ==0);

	return;
}
/*****************************************************************************
Function Name	ADC_DeInit
Function Definition	Void ADC_DeInit(viod)
Function Description	De_Initial ADC module. Disable interrupt generated by module and stop any conversion.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_DeInit(void)
{
	
	XN_ADC->INTEN.all=0;
	XN_ADC->STAT.all = 0xFFFFFFFF;
	//Power down ADC
	(*XN_SYSCON).PDRUNCFG.bit.ADC_PD = 1;
	//disable clock of ADC digital
	(*XN_SYSCON).SYSAHBCLKCTRL.bit.ADCCLK = 0;

	return;
}
/*****************************************************************************
Function Name	ADC_SetupChannels
Function Definition	Void ADC_SetupChannels (uint32_t channelassign, uint32_t triggermode)
Function Description	Select AD channels to be converted and AD conversion trigger mode
Input Parameters		channelassign: AD channel and DR assignment. Ref CHSEL register description. 
										Example (AD1<<ADC_DR0SEL)|(AD2<<ADC_DR0SEL), channel AD1 conversion value will be in DR1, and channel AD2 conversion value will be in DR4. DRncan not be duplicated.
										triggermode;	BURSTMODE/TRIGGERMODE
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_SetupChannels (uint32_t channelassign, uint32_t triggermode)
{
	uint32_t i;
	uint32_t temp;
	uint32_t adcchannel=0;
	
	//setup DR conversion enable
	for (i=0;i<32;i=i+4)
	{
		temp = (channelassign & (0xF<<i))>>i;
		if (temp!=0)
		{
			if (temp==0xF)
				temp=0;

			if (temp<8)
			adcchannel |= temp<<i;
			
			XN_ADC->CR.bit.CNVEN |= 1<<(i/4);								
		}		
	}
	
	//Setup channel
	(*XN_ADC).CHSEL.all = adcchannel;
	
	//Select burst mode or triggermode
	if (triggermode == BURSTMODE)
		(*XN_ADC).CR.bit.START=0;
	(*XN_ADC).CR.bit.BURST = triggermode;
	
	if (triggermode==TRIGGERMODE)
	{
		//wait untile adc ready
		while(!XN_ADC->STAT.bit.ADCRDY );		
	}
	return;
}
/*****************************************************************************
Function Name	ADC_SetTrigger
Function Definition	Void ADC_SetTrigger(uint8_t triggersrc, uint8_t edge)
Function Description	Setup trigger source signal if ADC is in trigger mode
Input Parameters	Triggersrc: select one option
										ADC_TRIGGER_SOFTWAER, 
										ADC_TRIGGER_CT16B2_CAP0, 
										ADC_TRIGGER_CT16B2_CAP1, 
										ADC_TRIGGER_CT16B2_MAT0,
										ADC_TRIGGER_CT16B2_MAT1,
										ADC_TRIGGER_CT16B3_MAT0,
										ADC_TRIGGER_CT16B3_MAT1,
										ADC_TRIGGER_PWM
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_SetTrigger(uint8_t triggersrc, uint8_t edge)
{
	//set up ADC start mode 
	(*XN_ADC).CR.bit.START = triggersrc;
	(*XN_ADC).CR.bit.EDGE	= edge;
	
	while(!XN_ADC->STAT.bit.ADCRDY );	
	
	return;
}
/*****************************************************************************
Function Name	ADC_SetHighCmp0
Function Definition	void ADC_SetHighCmp0(uint32_t val, uint8_t selchannel)
Function Description	Setup high limit register 0 value and channel to be compare
Input Parameters	val: 	high limit value
									selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_SetHighCmp0(uint32_t val, uint8_t selchannel)
{
	(*XN_ADC).HILMT.bit.HILMT0 = val;
	if (selchannel==AD0)
		selchannel=0;
	(*XN_ADC).HILMT.bit.CHNSEL0 = selchannel;
	return;
}
/*****************************************************************************
Function Name	ADC_SetHighCmp1
Function Definition	void ADC_SetHighCmp1(uint32_t val, uint8_t selchannel)
Function Description	Setup high limit register 1 value and channel to be compare
Input Parameters		val: high limit value
										selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_SetHighCmp1(uint32_t val, uint8_t selchannel)
{
	(*XN_ADC).HILMT.bit.HILMT1 = val;
	if (selchannel==AD0)
		selchannel=0;
	(*XN_ADC).HILMT.bit.CHNSEL1 = selchannel;
	return;
}
	
/*****************************************************************************
Function Name	ADC_SetLowCmp0
Function Definition	void ADC_SetLowCmp0(uint32_t val, uint8_t selchannel)
Function Description	Setup low limit register 0 value and channel to be compare
Input Parameters		val: high limit value
										selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_SetLowCmp0(uint32_t val, uint8_t selchannel)
{
	(*XN_ADC).LOLMT.bit.LOLMT0 = val;
	if (selchannel==AD0)
		selchannel=0;
	(*XN_ADC).LOLMT.bit.CHNSEL0 = selchannel;
	return;
}
/*****************************************************************************
Function Name	ADC_SetLowCmp1
Function Definition	void ADC_SetLowCmp1(uint32_t val, uint8_t selchannel)
Function Description	Setup low limit register 1 value and channel to be compare
Input Parameters			val: high limit value
											selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_SetLowCmp1(uint32_t val, uint8_t selchannel)
{
	(*XN_ADC).LOLMT.bit.LOLMT1 = val;
	if (selchannel==AD0)
		selchannel=0;
	(*XN_ADC).LOLMT.bit.CHNSEL1 = selchannel;
	return;
}
/*****************************************************************************
Function Name	ADC_EnableConversionInt
Function Definition	Void ADC_EnableConversionInt(uint32_t inttype)
Function Description	Setup conversion completed interrupt
Input Parameters		inttype: combination of interrupt source-
										bit 0~7 related to ADC_DR0~ ADC_DR7 value updated
										bit 8 related ADC global register updated
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void ADC_EnableConversionInt(uint32_t inttype)
{
	(*XN_ADC).INTEN.all =  inttype;
	return;
}
/*****************************************************************************
Function Name	ADC_GetConversionData
Function Definition	uint32_t ADC_GetConversionData(uint8_t dr)
Function Description	Read conversion data 
Input Parameters	dr: data register ADC_DR0~ ADC_DR7
Return Value	Conversion value. If no new value, return 0xFFFF FFFF. GDR value bit 14:12 value represent ADC channel 0~7
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
uint32_t ADC_GetConversionData(uint8_t dr)
{
	uint32_t DRvalue;
	do
	{
		DRvalue = (*XN_ADC).DR[dr].all;
	}while(( DRvalue & 0x80000000) == 0);
		
	return DRvalue&0xFFF;
}


/******************************************************************************
**                            End Of File
******************************************************************************/
