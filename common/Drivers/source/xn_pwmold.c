/*****************************************************************************
 *   xn_pwm.c:  Header file for Xinnova XN12,62
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
#include "xn_pwm.h"

extern uint32_t SystemCoreClock;

/*****************************************************************************
** Function name:		PWM_Init
**
** Descriptions:		Init PWM Module
**
** parameters:			
**                	freq: PWM Frequency  
**									pair: PWM_COMPLEMENT,PWM_DEPENDENT
**									align: PWM_CENTER,PWM_EDGE
**                  polarity: PWM_POSITIVE,PWM_NEGATIVE
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_Init(uint16_t freq,uint8_t pair, uint8_t align, uint8_t polarity)
{
	uint32_t prescaler = 0; //00 PWM Operation Clock Frequency;
													//01 PWM Operation Clock Frequency /2
													//10 PWM Operation Clock Frequency /4
													//11 PWM Operation Clock Frequency /8
	//enable PWM clk
	(*XN_SYSCON).SYSAHBCLKCTRL.bit.PWMCLK = 1;
	
	//set prescaler 
	(*XN_PWM).CTRL.bit.PRSC = prescaler;
	
	//Config 0-1,2-3,4-5 pair
	(*XN_PWM).CNFG.bit.NDEP01 = 0;
	(*XN_PWM).CNFG.bit.NDEP23 = 0;
	(*XN_PWM).CNFG.bit.NDEP45 = 0;
	
	(*XN_PWM).CNFG.bit.TOPNEG01 = polarity;
	(*XN_PWM).CNFG.bit.BOTNEG01 = 0;
	(*XN_PWM).CNFG.bit.TOPNEG23 = polarity;
	(*XN_PWM).CNFG.bit.BOTNEG23 = 0;
	(*XN_PWM).CNFG.bit.TOPNEG45 = polarity;
	(*XN_PWM).CNFG.bit.BOTNEG45 = 0;
	
	//Cofig PMW0 as Center-Aligned
	(*XN_PWM).CNFG.bit.EDG = align;

	//set modulu register, to generate freq Hz wave form
	if(align==1)
	{
		(*XN_PWM).CMOD.all = 20000000/freq;
		(*XN_PWM).CTRL.bit.HALF = 0;
	}
	else
	{
		(*XN_PWM).CMOD.all = 10000000/freq;
		(*XN_PWM).CTRL.bit.HALF = 1;
	}
	
	//Complement,define PWM out pair
	(*XN_PWM).PSCR.bit.CINV0 = polarity;
	(*XN_PWM).PSCR.bit.CINV1 = polarity;
	(*XN_PWM).PSCR.bit.CINV2 = polarity;
	(*XN_PWM).PSCR.bit.CINV3 = polarity;
	(*XN_PWM).PSCR.bit.CINV4 = polarity;
	(*XN_PWM).PSCR.bit.CINV5 = polarity;
	
	//0-1,2-3,4-5 pair
	(*XN_PWM).CTRL.bit.IPOL0 = 1;	// VAL1
	(*XN_PWM).CTRL.bit.IPOL1 = 1;	// VAL3
	(*XN_PWM).CTRL.bit.IPOL2 = 1;	// VAL5
	
	//Intial phase
	(*XN_PWM).CNTRINI.bit.INITVAL = 0;
	
	//Load Value
	(*XN_PWM).CTRL.bit.LDOK = 1;
}

/*****************************************************************************
** Function name:		PWM_DeInit
**
** Descriptions:		De_Initial PWM module
**
** parameters:			none
**                	
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_DeInit(void)
{
	//Disable PWM clk
	(*XN_SYSCON).SYSAHBCLKCTRL.bit.PWMCLK = 0;
}

/*****************************************************************************
** Function name:		PWM_SetRelaodFreq
**
** Descriptions:		set PWM reload frequency
**
** parameters:			
**                	  
**									everytimes: how much time to reload
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetRelaodFreq(uint8_t everytimes)
{
	(*XN_PWM).CTRL.bit.LDFQ = everytimes;
}

/*****************************************************************************
** Function name:		PWM_SetRelaodFreq
**
** Descriptions:		Set PWM Duty
** parameters:			
**                	channelindex: PWM0~5 
**									dutyval: 0-100
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetDuty(uint8_t channelindex, uint16_t dutyval)
{
	uint8_t i;
	uint32_t channelenable;
	
	for (i=0;i<6;i++)
	{
		channelenable = channelindex & (1<<i);
		if (channelenable != 0)
		{
			switch (i)
			{
				case 0:
					(*XN_PWM).VAL0.all = ((*XN_PWM).CMOD.all*dutyval)/100;
					break;
				case 1:
					(*XN_PWM).VAL1.all = ((*XN_PWM).CMOD.all*dutyval)/100;
					break;
				case 2:
					(*XN_PWM).VAL2.all = ((*XN_PWM).CMOD.all*dutyval)/100;
					break;
				case 3:
					(*XN_PWM).VAL3.all = ((*XN_PWM).CMOD.all*dutyval)/100;
					break;
				case 4:
					(*XN_PWM).VAL4.all = ((*XN_PWM).CMOD.all*dutyval)/100;
					break;
				case 5:
					(*XN_PWM).VAL5.all = ((*XN_PWM).CMOD.all*dutyval)/100;
					break;
				default:
					break;
			}
		}
	}
	
	(*XN_PWM).CTRL.bit.LDOK = 1;
}

/*****************************************************************************
** Function name:		PWM_SetRiseDeadZone
**
** Descriptions:		odd channel on rising edge
**
** parameters:			
**                	
**									rdtimeticks: deadtime us
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetRiseDeadZone(uint16_t rdtimeticks)
{
	(*XN_PWM).DTIM0.all = 20*rdtimeticks;
}


/*****************************************************************************
** Function name:		PWM_SetFallDeadZone
**
** Descriptions:		odd channel on falling edge
**
** parameters:			
**                	
**									rdtimeticks: deadtime us
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_SetFallDeadZone(uint16_t rdtimeticks)
{
	(*XN_PWM).DTIM1.all = 20*rdtimeticks;
}

/*****************************************************************************
** Function name:		PWM_EnableFaultProtect
**
** Descriptions:		Set PWM fault type and  interrupt
**
** parameters:			
**                	
**										faults: 		PWMFAULT, ADCFAULT, SWFAULT
**										cleartype:	PWM_MANUAL, PWM_AUTOMATIC
**										faultint:		DISINT, ENINT
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_EnableFaultProtect(uint8_t faults, uint8_t cleartype, uint8_t faultint)
{
	switch(faults)
	{
		case 0:
			(*XN_PWM).FCTRL.bit.FMODE0 = cleartype;
			(*XN_PWM).FCTRL.bit.FIE0 = faultint;
			break;
		case 1:
			(*XN_PWM).FCTRL.bit.FMODE1 = cleartype;
			(*XN_PWM).FCTRL.bit.FIE1 = faultint;
			break;
		case 2:
			(*XN_PWM).FCTRL.bit.FMODE2 = cleartype;
			(*XN_PWM).FCTRL.bit.FIE2 = faultint;
			break;
		default:
			break;
	}
}

/*****************************************************************************
** Function name:		PWM_ClearFault
**
** Descriptions:		Clear PWM fault signal 
**
** parameters:			
**                	
**										none
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_ClearFault(void)
{
	(*XN_PWM).FLTACK.bit.FTACK0 = 1;
	(*XN_PWM).FLTACK.bit.FTACK1 = 1;
	(*XN_PWM).FLTACK.bit.FTACK2 = 1;
}

/*****************************************************************************
** Function name:		PWM_Start
**
** Descriptions:		Enable PWM output
**
** parameters:			
**                	
**										none
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_Start(void)
{
	// Enable PWM0
	(*XN_PWM).CTRL.bit.PWMEN = 1;
	
	// UnMask PWM0~5
	(*XN_PWM).CCTRL.bit.MSK0 = 0;
	(*XN_PWM).CCTRL.bit.MSK1 = 0;
	(*XN_PWM).CCTRL.bit.MSK2 = 0;
	(*XN_PWM).CCTRL.bit.MSK3 = 0;
	(*XN_PWM).CCTRL.bit.MSK4 = 0;
	(*XN_PWM).CCTRL.bit.MSK5 = 0;

	
	// Reload signal output enable control
	(*XN_PWM).CTRL.bit.CH0OUTEN = 1;
	(*XN_PWM).CTRL.bit.CH1OUTEN = 1;
	(*XN_PWM).CTRL.bit.CH2OUTEN = 1;
	(*XN_PWM).CTRL.bit.CH3OUTEN = 1;
	(*XN_PWM).CTRL.bit.CH4OUTEN = 1;
	(*XN_PWM).CTRL.bit.CH5OUTEN = 1;
	
	//enable PWM0_0~5 pwm pad output
	(*XN_PWM).ICCTRL.bit.PAD_EN = 1;
	
	//Load value
	(*XN_PWM).CTRL.bit.LDOK = 1;
}

/*****************************************************************************
** Function name:		PWM_Stop
**
** Descriptions:		Disable PWM output
**
** parameters:			
**                	
**										none
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_Stop(void)
{
	// Disable PWM0
	(*XN_PWM).CTRL.bit.PWMEN = 0;
	
	// Mask PWM0~5
	(*XN_PWM).CCTRL.bit.MSK0 = 1;
	(*XN_PWM).CCTRL.bit.MSK1 = 1;
	(*XN_PWM).CCTRL.bit.MSK2 = 1;
	(*XN_PWM).CCTRL.bit.MSK3 = 1;
	(*XN_PWM).CCTRL.bit.MSK4 = 1;
	(*XN_PWM).CCTRL.bit.MSK5 = 1;

	
	// Reload signal output enable control
	(*XN_PWM).CTRL.bit.CH0OUTEN = 0;
	(*XN_PWM).CTRL.bit.CH1OUTEN = 0;
	(*XN_PWM).CTRL.bit.CH2OUTEN = 0;
	(*XN_PWM).CTRL.bit.CH3OUTEN = 0;
	(*XN_PWM).CTRL.bit.CH4OUTEN = 0;
	(*XN_PWM).CTRL.bit.CH5OUTEN = 0;
	
	//Disable PWM0_0~5 pwm pad output
	(*XN_PWM).ICCTRL.bit.PAD_EN = 0;
	
	//Load value
	(*XN_PWM).CTRL.bit.LDOK = 1;
}

/*****************************************************************************
** Function name:		PWM_Stop
**
** Descriptions:		Enable PWM Relaod Interrupt
**
** parameters:			
**                	
**										inttype: PWM_FULLINT, PWM_HALFINT
**
** Returned value:		none
** 
*****************************************************************************/
void	PWM_EnableInt(uint8_t inttype)
{
	(*XN_PWM).CTRL.bit.PWMRIE = 1;
	(*XN_PWM).CTRL.bit.HALF = inttype;
}

/*****************************************************************************
** Function name:		PWM_ADCTrigger
**
** Descriptions:		PWM signal trigger ADC
**
** parameters:			
**                	channel:PWM0~5
**
** Returned value:		none
** 
*****************************************************************************/
void PWM_ADCTrigger(uint8_t channel)
{
	uint8_t i;
	
	for(i=0;i<6;i++)
	{
		if(channel&(1<<i))
		{
			switch(i)
			{
				case 0:
					(*XN_PWM).CTRL.bit.CH0OUTEN = 1;
					break;
				case 1:
					(*XN_PWM).CTRL.bit.CH1OUTEN = 1;	
					break;
				case 2:
					(*XN_PWM).CTRL.bit.CH2OUTEN = 1;
					break;
				case 3:
					(*XN_PWM).CTRL.bit.CH3OUTEN = 1;
					break;
				case 4:
					(*XN_PWM).CTRL.bit.CH4OUTEN = 1;
					break;
				case 5:
					(*XN_PWM).CTRL.bit.CH5OUTEN = 1;
					break;
				default:
					break;
			}
		}
	}	
}

/******************************************************************************
**                            End Of File
******************************************************************************/
