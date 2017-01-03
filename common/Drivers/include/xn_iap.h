/*****************************************************************************
 *   xn_iap.h:  Header file for Xinnova XN12/62 Family Microprocessors
 *
 *   Copyright(C) 2011, Xinnova tech. Ltd.
 *   All rights reserved.
 *
 *   History
 *   2012  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __IAP_H 
#define __IAP_H
#include "XN11Exxx.h"

#define	SECTORSIZE 0x200  //512 bytes sector size
#define	IAPENTRYVECTOR			0x1FFF00FC

//IAP Command
#define	SECTORERASE					0x11		//Erase flash sector
#define	WORDPROGRAMMING			0x15		//Programming word to flash
#define BSLVERSION					0x31		//Read Boot loader version


//IAP RETURN CODE
#define CMD_SUCC		0x00
#define INVALID_ADDR	0x01
#define ERASE_FAILED	0x02
#define PROG_FAILED		0x03
#define NOT_BLANK		0x04
#define INVALID_CMD		0x05
#define INVALID_PWD		0x06
#define IRC_NOT_POWERED		0x07

//Device Information
# define DEVICEID (DIA->DID)
# define DEVICEUID (DIA->UNIQUEID0)
# define DEVICEVERSION (DIA->VERID)


typedef void (*IAP)(uint32_t *,uint32_t*);
//Flash access speed control
void FMC_SetFlashReadTime(uint8_t clocks);
#endif /* end __IAP_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
