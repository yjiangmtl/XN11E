/*****************************************************************************
 *   xn_touch.c:  Header file for Xinnova XN11
 *
 *   Copyright(C) 20012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2015.04.21  ver 1.00    Prelimnary version
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "XN11Exxx.h"
#include "XN_SYS.h"
#include "xn_touch.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	CAPTOUCH_Init
Function Definition	void CAPTOUCH_Init(void)
Function Description	Initial Cap Touch module, default sense clock selection is 0x01(~1.3MHz) 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_Init(void)
{
	XN_SYSCON->PDRUNCFG.bit.TOUCH_PD=0;
	XN_SYSCON->SYSAHBCLKCTRL.bit.TOUCH=1;
	XN_SYSCON->PRESETCTRL.bit.TOUCH_RST_N=0;
	XN_SYSCON->PRESETCTRL.bit.TOUCH_RST_N=1;
	
	#if OLD_VERSION
		XN_CAPTOUCH->CTRL.bit.EXTRSEL=1;
	#else
		XN_CAPTOUCH->CTRL.bit.EXTRSEL=0;
	#endif

	XN_CAPTOUCH->CTRL.bit.INTERNALRSET=CAPTOUCH_SENSE_CLK_800; //seleect 800KHZ as default
	XN_CAPTOUCH->CTRL.bit.OSCEN=1;
	XN_CAPTOUCH->CTRL.bit.CAPTEN=1;
	return;
}
/*****************************************************************************
Function Name	CAPTOUCH_Deinit
Function Definition	void CAPTOUCH_Deinit(void)
Function Description	Shut down Cap Touch module
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_Deinit(void)
{
	XN_CAPTOUCH->CTRL.bit.OSCEN=0;
	XN_CAPTOUCH->CTRL.bit.CAPTEN=0;
	XN_SYSCON->PDRUNCFG.bit.TOUCH_PD=1;
	XN_SYSCON->SYSAHBCLKCTRL.bit.TOUCH=0;

	return;
}
/*****************************************************************************
Function Name	CAPTOUCH_SelSenseClk
Function Definition	void CAPTOUCH_SelSenseClk (uint8_t clkfreq)
Function Description	Select sense clock fequency
Input Parameters	Clkfreq: CAPTOUCH_SENSE_CLK_3600 0
													CAPTOUCH_SENSE_CLK_1400	1
													CAPTOUCH_SENSE_CLK_600	2
													CAPTOUCH_SENSE_CLK_350	3
													CAPTOUCH_SENSE_CLK_EXT	4
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_SelSenseClk (uint8_t clkfreq)
{
	if (clkfreq==CAPTOUCH_SENSE_CLK_EXT)
	#if OLD_VERSION
		XN_CAPTOUCH->CTRL.bit.EXTRSEL=0;
	#else
		XN_CAPTOUCH->CTRL.bit.EXTRSEL=1;
	#endif
	else
	{
	#if OLD_VERSION
		XN_CAPTOUCH->CTRL.bit.EXTRSEL=1;
	#else
		XN_CAPTOUCH->CTRL.bit.EXTRSEL=0;
	#endif		
		XN_CAPTOUCH->CTRL.bit.INTERNALRSET=clkfreq; 
	}

	return;
}
/*****************************************************************************
Function Name	CAPTOUCH_EnableTouchCHN
Function Definition	void CAPTOUCH_EnableTouchCHN(uint32_t channels)
Function Description	Enable scan selected channel. The unselected channel scanning is ignored. 
Input Parameters	Channels: combination of TOUCH0~TOUCH21
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_EnableTouchCHN(uint32_t channels)
{
	XN_CAPTOUCH->CTRL.bit.CHNEN|=channels;
	
	return;
}
/*****************************************************************************
Function Name	CAPTOUCH_SetScanTime
Function Definition	void CAPTOUCH_SetScanTime(uint32_t minisec)
Function Description	Setup sensing time for each touch pin
Input Parameters	minisec: mini seconds
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_SetScanTime(uint32_t minisec)
{
		XN_CAPTOUCH->SENSTM.all=SystemCoreClock*minisec/1000;
	return;

}
/*****************************************************************************
Function Name	CAPTOUCH_SetWaterMark
Function Definition	void CAPTOUCH_SetWaterMark(uint32_t level)
Function Description	Setup sensing threshold for touched pin
Input Parameters	Level: counter number. If Cap Touch counter number lower than level, 
the interrupt is triggered. if level is 0, disable watermark function.
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_SetWaterMark(uint32_t level)
{
	XN_CAPTOUCH->CTRL.bit.INTEN=1;
	XN_CAPTOUCH->WATMK.all=level;

	return;

}
/*****************************************************************************
Function Name	CAPTOUCH_EnableScanInt
Function Definition	void CAPTOUCH_EnableScanInt(void)
Function Description	Enable interrupt for each touch pin scan completed
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_EnableScanInt(void)
{
	XN_CAPTOUCH->CTRL.bit.SCANINTEN=1;
	XN_CAPTOUCH->CTRL.bit.INTEN=1;
	return;

}
/*****************************************************************************
Function Name	CAPTOUCH_DisableScanInt
Function Definition	void CAPTOUCH_DisableScanInt(void)
Function Description	Disable interrupt for each touch pin scan completed
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_DisableScanInt(void)
{
	XN_CAPTOUCH->CTRL.bit.SCANINTEN=0;
	return;

}
/*****************************************************************************
Function Name	CAPTOUCH_GetScanVal
Function Definition	void CAPTOUCH_GetScanVal(uint8_8 * channel, uint32_t *val)
Function Description	Get channel number and counter value of last completed scan 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_GetScanVal(uint8_t * channel, uint32_t *val)
{
	*channel=XN_CAPTOUCH->SCANCHN.bit.CHN;
	*val=XN_CAPTOUCH->SCANCNT.all;
	return;

}
/*****************************************************************************
Function Name	CAPTOUCH_GetTouchedVal
Function Definition	void CAPTOUCH_GetTouchedVal (uint8_t * channel, uint32_t *val)
Function Description	Get channel number and counter value when touch is sensed 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_GetTouchedVal (uint8_t * channel, uint32_t *val)
{
	*channel=XN_CAPTOUCH->TOUCHCHN.bit.CHN;
	*val=XN_CAPTOUCH->TOUCHCNT.all;
	return;

}
/*****************************************************************************
Function Name	CAPTOUCH_ClearIntFlag
Function Definition	void CAPTOUCH_ClearIntFlag(void)
Function Description	Clear Cap Touch interrupt flag
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void CAPTOUCH_ClearIntFlag(void)
{
	XN_CAPTOUCH->RAWSTAT.all=0x3;
	return;

}
/******************************************************************************
**                            End Of File
******************************************************************************/
