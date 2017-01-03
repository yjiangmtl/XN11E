/*****************************************************************************
 *   XN_LCD:  Sourse file for Xinnova MCU LCD application
 *
 *   Copyright(C) 2012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2015.08.14  ver 1.00
 *
******************************************************************************/
#include "xn_lcd.h"
#include "xn_sys.h"
extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	LCD_Init
Function Definition	void LCD_Init (uint8_t mode,uint8_t duty, uint8_t biasanode, uint8_t finhz)
Function Description	Initial module in LCD mode and configure bias voltage, common line scan frequency
Input Parameters	Mode: LCD/LED
Duty: 1~6 present duty 1, ½, 1/3, ¼, 1/5 and 1/6. For example, if 4 COM LCD display module is applied, duty shall be set to 4.
Biasanode:LCD mode: 0-1/2 VDD, 1-1/3 VDD;LED 0- common anode, 1-common cathode
Finhz: scan frequency in HZ
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_Init (uint8_t mode,uint8_t duty, uint8_t biasanode, uint8_t finhz)
{
	XN_SYSCON->SYSAHBCLKCTRL.bit.LCD=1;
	XN_SYSCON->PRESETCTRL.bit.LCD_RST_N=0;
	XN_SYSCON->PRESETCTRL.bit.LCD_RST_N=1;
	//disable output
	XN_LCD->LCDOUTEN0.all=0;
	XN_LCD->LCDOUTEN1.all=0;
	//set duty
	XN_LCD->LCDCTRL1.bit.DUTY=duty;
	
	if ((finhz>0)&&(duty>0))
		XN_LCD->LCDCTRL1.bit.FREQDIV=SystemCoreClock/(duty*finhz);
	if (mode==LCD_MODE)
	{
		XN_SYSCON->PDRUNCFG.bit.LCD_PD=0;
		XN_LCD->LCDCTRL1.bit.BIAS=biasanode;
		XN_LCD->LCDCTRL0.bit.LEDEN=0;
		XN_LCD->LCDCTRL0.bit.LCDEN=1;
		
	}else if (mode==LED_MODE)
	{
		XN_SYSCON->PDRUNCFG.bit.LCD_PD=1;
		XN_LCD->LCDCTRL0.bit.LCDEN=0;
		XN_LCD->LCDCTRL0.bit.LEDINV=biasanode;
		XN_LCD->LCDCTRL0.bit.LEDEN=1;
	}
	return;
}


/*****************************************************************************
Function Name	LCD_Deinit
Function Definition	void LCD_Deinit(void)
Function Description	De-Initial module
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_Deinit(void)
{
	XN_SYSCON->PDRUNCFG.bit.LCD_PD=1;
	XN_SYSCON->SYSAHBCLKCTRL.bit.LCD=0;
	return;
}

/*****************************************************************************
Function Name	LCD_EnableOutput
Function Definition	void LCD_EnableOutput(uint8_t comchannel, uint16_t segchannel)
Function Description	Enable COM and Seg output. This function is for LCD mode only.
Input Parameters	Comchannel: combination of COM0~COM5
Segchannel: combination of SEG0~SEG15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_EnableOutput(uint8_t comchannel, uint16_t segchannel)
{
	XN_LCD->LCDOUTEN0.bit.LCDCOMEN=comchannel;
	XN_LCD->LCDOUTEN1.bit.LCDSEGEN=segchannel;
	return;
}
	
/*****************************************************************************
Function Name	LCD_SetDo
Function Definition	void LCD_SetDot (uint8_t com, uint8_t segment)
Function Description	Light the specific dot
Input Parameters	Comchannel: COM0~COM5
Segchannel: SEG0~SEG15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_SetDot (uint8_t com, uint8_t segment)
{
	uint32_t seg=0,segcol=0;

	if ((segment==0)||(com==0))return;

	if (XN_LCD->LCDCTRL0.bit.LCDEN)
	{
		if (segment&0xFF00)
		{
			seg=2;
			segment=segment>>8;
		}
		if (segment&0xF0)
		{
			seg+=1;
			segment=segment>>4;
		}
		if (segment&0xC)
		{
			segcol=16;
			segment=segment>>2;
		}	
		if (segment&0x2)
		{
			segcol+=8;
		}			

		XN_LCD->MEMMAP[seg] |= com<<segcol;
	}else if (XN_LCD->LCDCTRL0.bit.LEDEN)
	{
		XN_LCD->MEMMAP[com>>1] |= (1<<(segment+16*(com&1)));
	}
	return;
}
	
/*****************************************************************************
Function Name	LCD_ResetDo
Function Definition	void LCD_ResetDot (uint8_t com, uint8_t segment)
Function Description	Turn off the specific dot
Input Parameters	Comchannel: COM0~COM5
Segchannel: SEG0~SEG15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_ResetDot (uint8_t com, uint8_t segment)
{
	uint32_t seg=0,segcol=0;

	if ((segment==0)||(com==0)) return;

	if (XN_LCD->LCDCTRL0.bit.LCDEN)
	{
		if (segment&0xFF00)
		{
			seg=2;
			segment=segment>>8;
		}
		if (segment&0xF0)
		{
			seg+=1;
			segment=segment>>4;
		}
		if (segment&0xC)
		{
			segcol=16;
			segment=segment>>2;
		}	
		if (segment&0x2)
		{
			segcol+=8;
		}			

		XN_LCD->MEMMAP[seg] &= ~(com<<segcol);
	}else if (XN_LCD->LCDCTRL0.bit.LEDEN)
	{
		XN_LCD->MEMMAP[com>>1] &= ~(1<<(segment+16*(com&1)));
	}
	return;
}

/*****************************************************************************
FFunction Name	LCD_SetComLine
Function Definition	void LCD_SetComLine (uint8_t com, uint16_t segments)
Function Description	Light selected segments in specific COM
Input Parameters	Com: COM0~COM5
Segments: combination of SEG0~SEG15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_SetComLine (uint8_t com, uint16_t segments)
{
	uint32_t i, data=0;

	if ((segments==0)||(com==0))return;

	if (XN_LCD->LCDCTRL0.bit.LCDEN)
	{
		for (i=0;i<16;i++)
		{
			
			if (segments&0x1)
				data|=com<<((i&0x3)<<4);
			if((i&0x3)==0x3)
			{
				XN_LCD->MEMMAP[i>>2] |= data;
				data=0;
			}
			segments=segments>>1;
		}
	}else if (XN_LCD->LCDCTRL0.bit.LEDEN)
	{
		XN_LCD->MEMMAP[com>>1] |= segments<<(16*(com&1));
	}
	return;
}


/*****************************************************************************
Function Name	LCD_ResetComLine
Function Definition	void LCD_ResetComLine (uint8_t com, uint16_t segments)
Function Description	Turn off selected segments in specific COM
Input Parameters	Com: COM0~COM5
Segments: combination of SEG0~SEG15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_ResetComLine (uint8_t com, uint16_t segments)
{
	uint32_t i, data=0;

	if ((segments==0)||(com==0))return;

	if (XN_LCD->LCDCTRL0.bit.LCDEN)
	{
		for (i=0;i<16;i++)
		{
			
			if (segments&0x1)
				data|=com<<((i&0x3)<<4);
			if((i&0x3)==0x3)
			{
				XN_LCD->MEMMAP[i>>2] &= ~data;
				data=0;
			}
			segments=segments>>1;
		}
	}else if (XN_LCD->LCDCTRL0.bit.LEDEN)
	{
		XN_LCD->MEMMAP[com>>1] &= ~segments<<(16*(com&1));
	}
	return;
}
/*****************************************************************************
Function Name	LCD_WriteComLine
Function Definition	void LCD_WriteComLine(uint8_t com, uint16_t data)
Function Description	Write segments bit value in specific COM. If bit value, the related segment will be light, otherwise is turn off. 
Input Parameters	Com: COM0~COM5
data: combination of bit value related to SEG0~SEG15
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_WriteComLine(uint8_t com, uint16_t data)
{
	uint32_t i,data1=0,data0=0;

	if (com==0)return;

	if (XN_LCD->LCDCTRL0.bit.LCDEN)
	{
		for (i=0;i<16;i++)
		{
			
			if (data&0x1)
				data1|=com<<((i&0x3)<<4);
			else
				data0|=com<<((i&0x3)<<4);
			if((i&0x3)==0x3)
			{
				XN_LCD->MEMMAP[i>>2] &= ~data0;
				XN_LCD->MEMMAP[i>>2] |= ~data1;
				data0=0;
				data1=0;
			}
			data=data>>1;
		}
	}else if (XN_LCD->LCDCTRL0.bit.LEDEN)
	{
		if (com&1)
			XN_LCD->MEMMAP[com>>1] = (data<<16) + (XN_LCD->MEMMAP[com>>1]&0xFFFF);
		else
			XN_LCD->MEMMAP[com>>1] = data + (XN_LCD->MEMMAP[com>>1]&0xFFFF0000);
	}
}
/*****************************************************************************
Function Name	LCD_ClearScreen(void)
Function Definition	void LCD_ClearScreen(void)
Function Description	turn off all dot 
Input Parameters	none

Return Value	None
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_ClearScreen(void)
{
	XN_LCD->MEMMAP[0]=0;
	XN_LCD->MEMMAP[1]=0;
	XN_LCD->MEMMAP[2]=0;
	XN_LCD->MEMMAP[3]=0;
	return;
}
/*****************************************************************************
Function Name	LCD_LightFullScreen
Function Definition	void LCD_LightFullScreen(void)
Function Description	turn on all dot 
Input Parameters	none

Return Value	None
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_LightFullScreen(void)
{
	XN_LCD->MEMMAP[0]=0xFFFFFFFF;
	XN_LCD->MEMMAP[1]=0xFFFFFFFF;
	XN_LCD->MEMMAP[2]=0xFFFFFFFF;
	XN_LCD->MEMMAP[3]=0xFFFFFFFF;
	return;
}

/*****************************************************************************
Function Name	LCD_WriteMemMap
Function Definition	void LCD_WriteMemMap(uint8_t offset, uint32_t data)
Function Description	Write LCD/LED memory map table value
Input Parameters	offset: memory table offset address
data: value of map 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void LCD_WriteMemMap(uint8_t offset, uint32_t data)
{
	XN_LCD->MEMMAP[offset]=data;
	return;
}
