/**************************************************************************//**
 * $Id: system_XN11Exxx.c,
 *
 * @file     system_XN11Exxx.c
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Source File
 *           for the XINNOVA XN11L Device Series
 * @version  v 1.0 
 * @date     2014/04/04 
 * @author   XINNOVA MCU Team
 *
 * @note
 * Copyright (C) 2010 XINNOVA Technology Ltd. All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * XINNOVA Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. XINNOVA Semiconductors
 * reserves the right to make changes in the software without
 * notification. XINNOVA Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 ******************************************************************************/

#include <stdint.h>

#include "XN11Exxx.h"
#include "XN_sys.h"


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/

#define __WDT_OSC_CLK     (32000UL)     /* Internal WDT oscillator frequency */
#define __IRC_OSC_CLK_30MHZ     (30000000UL)     /* Internal RC oscillator frequency (sample*/
#define __IRC_OSC_CLK_40MHZ     (40000000UL)     /* Internal RC oscillator frequency (sample*/
#define __IRC_OSC_CLK_48MHZ     (48000000UL)     /* Internal RC oscillator frequency (sample*/
/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = __IRC_OSC_CLK_40MHZ>>1 ; /*!< System Clock Frequency (Core Clock) after reset*/
uint32_t MainClock = __IRC_OSC_CLK_40MHZ;  /*!< Main Clock Frequency (Main Clock) after reset*/

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
  //Get MainClock source
	switch (XN_SYSCON->MAINCLKSEL.bit.SEL )
	{
		case 0: //0x0 IRC oscillator
				if (XN_SYSCON->IRCCTRL.bit.SW)
					MainClock = __IRC_OSC_CLK_48MHZ;
				else
					MainClock = __IRC_OSC_CLK_40MHZ;
				break;
		case 2: //0x2 WDT oscillator
				MainClock = __WDT_OSC_CLK;
				break;
		default: 
				break;
	}
  
  	SystemCoreClock = MainClock/XN_SYSCON->SYSAHBCLKDIV.bit.DIV;  /* Update SystemCoreClock */
	
	return;
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
	//your code here
}

