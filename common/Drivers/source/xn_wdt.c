/*****************************************************************************
 *   xn_wdt.h:  Header file for Xinnova XN12,62
 *
 *   Copyright(C) 20012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2014.02.21  ver 1.01    Prelimnary version
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "XN11Exxx.h"
#include "xn_sys.h"
#include "xn_wdt.h"
extern uint32_t MainClock;
/*****************************************************************************
Function Name	WDT_Init
Function Definition	void WDT_Init (void)
Function Description	Initial WDT module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_Init (void)
{
	//enable WDT PCLK
	XN_SYSCON->SYSAHBCLKCTRL.bit.WDTCLK=1;
	//initial WDT to trigger interrupt
	
	#if OLD_VERSION
		XN_WDT->MOD.bit.WDRESET=0;
	#else
		XN_WDT->MOD.bit.WDRESET=1;
	#endif	
	return;
}
/*****************************************************************************
Function Name	WDT_Deinit
Function Definition	void WDT_Deinit (void)
Function Description	De-Initial WDT module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_Deinit(void)
{
	//disable WDT PCLK
	XN_SYSCON->SYSAHBCLKCTRL.bit.WDTCLK=0;	
	return;
}
/*****************************************************************************
Function Name	WDT_SetWindowValue
Function Definition	void WDT_SetWindowValue (uint32_t intticks,uint32_t windowticks)
Function Description	Set WDT two windows value. 
Input Parameters	intticks: if WDT counter decrease to intticks value, the interrupt is generated
windowticks: if WDT counter decrease to windowticks value, no more feed valid. 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_SetWindowValue (uint32_t intticks,uint32_t windowticks)
{
	XN_WDT->WARNINT.bit.WARNINT=intticks;
	XN_WDT->WINDOW.bit.WDWINDOW=windowticks;
	return;
}

/*****************************************************************************
Function Name	WDT_Feed
Function Definition	void WDT_Feed (void)
Function Description	Watchdog feed
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_Feed (void)
{
	XN_WDT->FEED.bit.WDFEED  = 0xAA;
	XN_WDT->FEED.bit.WDFEED  = 0x55;
	return;	
}
/*****************************************************************************
Function Name	WDT_SetIntervalinTick
Function Definition	void WDT_SetIntervalinTick (uint32_t ticks)
Function Description	Setup WDT time out interval
Input Parameters	ticks: time interval in WDT tick
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_SetIntervalinTick(uint32_t ticks)
{
	XN_WDT->TC.bit.WDTC=ticks;
	
	return;
}
/*****************************************************************************
Function Name	WDT_SetIntervalinMiliSec
Function Definition	void WDT_SetIntervalinMiliSec(uint32_t ms)
Function Description	Setup WDT time out interval
Input Parameters	ms: time interval in mili second
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_SetIntervalinMiliSec(uint32_t ms)
{
	volatile uint32_t ticks=0;
	//limit WDT interval to 10s
	if (ms>10000)
		ms=10000;
// 	if (ms>1600)
// 	{
// 		XN_SYSCON->PDRUNCFG.bit.WDTOSC_PD=0;
// 		XN_SYSCON->WDTOSCCTRL.bit.WDTCLKSRC=1; //the max internal is 16777ms when WDT clock counter source is MAIN_CLK	
// 	}
// 	if (XN_SYSCON->WDTOSCCTRL.bit.WDTCLKSRC)
// 		ticks=32000/1000;
// 	else
// 		ticks=MainClock/1000;
	XN_SYSCON->WDTOSCCTRL.bit.WDTCLKSRC=0;
	XN_SYSCON->WDTOSCCTRL.bit.DIVSEL=ms/1600+1;
	
	ticks=MainClock/(1000*XN_SYSCON->WDTOSCCTRL.bit.DIVSEL);
	//convert mili second to ticks
	ticks=(ticks*ms)>>2;
	if (ticks>0xFFFFFF)
		ticks=0xFFFFFF;
	//set WDT timeout interval
	XN_WDT->TC.bit.WDTC=ticks;
	ticks=0;
	while (ticks++<0xFFF);
	return;
}
/*****************************************************************************
Function Name	WDT_EnableResetSystem
Function Definition	void WDT_EnableResetSystem(void)
Function Description	Enable system reset after WDT timeout occurs
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_EnableResetSystem(void)
{
	#if OLD_VERSION
		XN_WDT->MOD.bit.WDRESET=1;
	#else
		XN_WDT->MOD.bit.WDRESET=0;
	#endif	
	return;
}
/*****************************************************************************
Function Name	WDT_ClearlntFlag
Function Definition	void WDT_ClearIntFlag(void)
Function Description	Clear WDT interrupt flag
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_ClearIntFlag(void)
{
	//clr time out flag
	XN_WDT->MOD.bit.WDTOF=0;
	//clr window int flag
	XN_WDT->MOD.bit.WDINT=1;
}
/*****************************************************************************
Function Name	WDT_ClearlntFlag
Function Definition	uint32_t WDT_GetCounterValue (void)
Function Description	Return WDT counter value
Input Parameters	No
Return Value	WDT counter value
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
uint32_t WDT_GetCounterValue (void)
{
	return XN_WDT->TV.all;
}
/*****************************************************************************
Function Name	WDT_EnableLock
Function Definition	void WDT_EnableLock (void)
Function Description	Lock WDT Setting. Once WDT is locked, you can not do any changing to WDT, 
including enable/disable timer, changing of WDT timer out interval, and reset system setting when time out.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void WDT_EnableLock (void)
{
	XN_WDT->MOD.bit.WDLOCKCLK=1;
	XN_WDT->MOD.bit.WDLOCKDP=1;
	XN_WDT->MOD.bit.WDLOCKEN=1;
	
	return;
}
 
