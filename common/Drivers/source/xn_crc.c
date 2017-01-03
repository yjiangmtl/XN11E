/*****************************************************************************
 *   xn_crc.h:  Header file for Xinnova XN11
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

#include "xn_crc.h"
#include "xn_sys.h"
/*****************************************************************************
Function Name	CRC_CCITT
Function Definition	Int16_t CRC_CCITT(uint8_t * str, uint16_t strlen,uint32_t crcseed);
Function Description	CRC CCITT Calculate
Input Parameters	*str: pointer to string
strlen: length of string
crcseed: seed of CRC
Return Value	CRC calculation result
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
uint16_t CRC_CCITT(uint8_t * str, uint16_t strlen,uint32_t crcseed)
{
	uint16_t crcvalue;
	//initial CRC
	XN_SYSCON->SYSAHBCLKCTRL.bit.CRCCLK = 1;
	XN_CRC->MODE.bit.CRC_POLY=0;
	XN_CRC->SEED.all = crcseed; 
	XN_CRC->MODE.bit.SEED_SET=1;

	//calculate CRC
	while ( strlen != 0)
	{
		 XN_CRC->DATA.all = *str++;
		 strlen --;
	}
	crcvalue=(uint16_t) XN_CRC->DATA.all;
	
	XN_SYSCON->SYSAHBCLKCTRL.bit.CRCCLK = 0;
	
	return crcvalue;
}
/*****************************************************************************
Function Name	CRC_16
Function Definition	uint16_t CRC_16(uint8_t * str, uint16_t strlen,uint32_t crcseed);
Function Description	CRC 16 Calculate
Input Parameters	*str: pointer to string
strlen: length of string
crcseed: seed of CRC
Return Value	CRC calculation result
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
uint16_t CRC_16(uint8_t * str, uint16_t strlen,uint32_t crcseed)
{
	uint16_t crcvalue;
	//initial CRC
	XN_SYSCON->SYSAHBCLKCTRL.bit.CRCCLK = 1;
	XN_CRC->MODE.bit.CRC_POLY=1;
	XN_CRC->SEED.all = crcseed; 
	XN_CRC->MODE.bit.SEED_SET=1;

	//calculate CRC
	while ( strlen != 0)
	{
		 XN_CRC->DATA.all = *str++;
		 strlen --;
	}
	crcvalue=(uint16_t) XN_CRC->DATA.all;
	
	XN_SYSCON->SYSAHBCLKCTRL.bit.CRCCLK = 0;
	
	return crcvalue;
}
/*****************************************************************************
Function Name	CRC_32
Function Definition	uint32_t CRC_32(uint8_t * str, uint16_t strlen,uint32_t crcseed);
Function Description	CRC 32 Calculate
Input Parameters	*str: pointer to string
strlen: length of string
crcseed: seed of CRC
Return Value	CRC calculation result
Condition	No
Function called	-

Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
uint32_t CRC_32(uint8_t * str, uint16_t strlen,uint32_t crcseed)
{
	uint32_t crcvalue;
	//initial CRC
	XN_SYSCON->SYSAHBCLKCTRL.bit.CRCCLK = 1;
	XN_CRC->MODE.bit.CRC_POLY=2;
	XN_CRC->SEED.all = crcseed; 
	XN_CRC->MODE.bit.SEED_SET=1;

	//calculate CRC
	while ( strlen != 0)
	{
		 XN_CRC->DATA.all = *str++;
		 strlen --;
	}
	crcvalue=XN_CRC->DATA.all;
	
	XN_SYSCON->SYSAHBCLKCTRL.bit.CRCCLK = 0;
	
	return crcvalue;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
