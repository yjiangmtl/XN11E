/*****************************************************************************
 *   xn_GPIO.h:  Header file for Xinnova XN11E Family Microprocessors
 *
 *   Copyright(C) 2011, Xinnova tech. Ltd.
 *   All rights reserved.
 *
 *   History
 *   2012  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __GPIO_H 
#define __GPIO_H

#include "XN11Exxx.h"


//--GPIO Registers BITS Field---------------------------------------------------------------------------------------
struct GPIO_BITS {										// bit description: 0=not masked/LOW; 1=masked/HIGH
				uint32_t IO0:1;							// 0 PIO2_0 access control
				uint32_t IO1:1;							// 1 PIO2_1 access control
				uint32_t IO2:1;							// 2 PIO2_2 access control
				uint32_t IO3:1;							// 3 PIO2_3 access control
				uint32_t IO4:1;							// 4 PIO2_4 access control
				uint32_t IO5:1;							// 5 PIO2_5 access control
				uint32_t IO6:1;							// 6 PIO2_6 access control
				uint32_t IO7:1;							// 7 PIO2_7 access control
				uint32_t IO8:1;							// 8 PIO2_8 access control
				uint32_t IO9:1;							// 9 PIO2_9 access control
				uint32_t IO10:1;						// 10 PIO2_10 access control
				uint32_t IO11:1;						// 11 PIO2_11 access control
				uint32_t IO12:1;						// 12 PIO2_12 access control
				uint32_t IO13:1;						// 13 PIO2_13 access control
				uint32_t IO14:1;						// 14 PIO2_14 access control
				uint32_t IO15:1;						// 15 PIO2_15 access control
				uint32_t RSVD:16;						// 31:16 Reserved
};

union GPIO_MASK_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

union GPIO_PIN_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

union GPIO_OUT_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

union GPIO_SET_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

union GPIO_CLR_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

union GPIO_NOT_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

union GPIO_DIR_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Sense Register: 0=edge, 1=level, Reset=0
union GPIO_IS_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Both Edge Sense Register: 0=depend on IEV, 1=Both edge, Reset=0
union GPIO_IBE_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Event Register(depend on IS): 
//0=falling edge/LOW level, 1=rising edge/HIGH level, Reset=0
union GPIO_IEV_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Mask Register: 0=Masked, 1=Not masked
union GPIO_IM_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

// GPIO Raw Interrupt Mask Status Register: 0=No, 1=Yes(RO)
union GPIO_RIS_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

// GPIO Masked Interrupt Status Register: 0=No, 1=Yes(RO)
union GPIO_MIS_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Clear Register: 0=No effect, 1=Clear Flag(WO)
union GPIO_IC_REG {
				uint32_t					all;
				struct GPIO_BITS			bit;
};

	 
/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @addtogroup XN_GPIO XN11Exx General Purpose Input/Output 
  @{
*/
typedef struct
{    
	__IO	union GPIO_MASK_REG		MASK;		/*!< Offset:0x000 GPIO mask register:PIN,OUT,SET,CLR,NOT (R/W) */
	__I		union GPIO_PIN_REG		PIN;		/*!< Offset:0x004 GPIO value register (RO) */
	__IO	union GPIO_OUT_REG		OUT;		/*!< Offset:0x008 GPIO output value register (R/W) */
	__O		union GPIO_SET_REG		SET;		/*!< Offset:0x00C GPIO output value set register (WO) */
	__O		union GPIO_CLR_REG		CLR;		/*!< Offset:0x010 GPIO output value clear register (WO) */
	__O		union GPIO_NOT_REG		NOT;		/*!< Offset:0x014 GPIO output value invert register (WO) */
	__IO	uint32_t RESERVE[2];
	__IO	union GPIO_DIR_REG		DIR;        /*!< Offset:0x020 Data direction register (R/W) */
	__IO	union GPIO_IS_REG		IS;			/*!< Offset:0x024 Interrupt sense register (R/W) */
	__IO	union GPIO_IBE_REG		IBE;		/*!< Offset:0x028 Interrupt both edges register (R/W) */
	__IO	union GPIO_IEV_REG		IEV;		/*!< Offset:0x02C Interrupt event register (R/W) */
	__IO	union GPIO_IM_REG		IE;			/*!< Offset:0x030 Interrupt mask register (R/W) */
	__I		union GPIO_RIS_REG		RIS;		/*!< Offset:0x034 Raw Interrupt status register (RO) */
	__I		union GPIO_MIS_REG		MIS;		/*!< Offset:0x038 Masked Interrupt status register (RO) */
	__O		union GPIO_IC_REG		IC;			/*!< Offset:0x03C Interrupt clear register (WO) */
} XN_GPIO_TypeDef;

//Define XN GPIO
#define		XN_GPIO0			((XN_GPIO_TypeDef   *) GPIO0_BASE )
#define		XN_GPIO1			((XN_GPIO_TypeDef   *) GPIO1_BASE )
#define		XN_GPIO2			((XN_GPIO_TypeDef   *) GPIO2_BASE )

#define PIN_SET 					0x1
#define PIN_RESET 				0x0
#define PIN_EDGE_SENSE 		0x0
#define PIN_LEVEL_SENSE 	0x1
#define PIN_IEV_CTL 			0x0
#define PIN_BOTH_EDGE_CTL 0x1
#define PIN_FALLEDGE_OR_LOWLEVEL_TRIGGER 	0x0
#define PIN_RISEEDGE_OR_HIGHLEVEL_TRIGGER 0x1

#define ENABLEGPIO0CLK (XN_SYSCON->SYSAHBCLKCTRL |= (1<<29))
#define ENABLEGPIO1CLK (XN_SYSCON->SYSAHBCLKCTRL |= (1<<30))
#define ENABLEGPIO2CLK (XN_SYSCON->SYSAHBCLKCTRL |= (1<<31))
#define DISABLEGPIO0CLK (XN_SYSCON->SYSAHBCLKCTRL &= ~(1<<29))
#define DISABLEGPIO1CLK (XN_SYSCON->SYSAHBCLKCTRL &= ~(1<<30))
#define DISABLEGPIO2CLK (XN_SYSCON->SYSAHBCLKCTRL &= ~(1<<31))
#define SETGPIO0MASK(mask) (XN_GPIO0->MASK = mask)

void GPIO_ConfigPinsAsInput(XN_GPIO_TypeDef*port, uint16_t pins);
void GPIO_ConfigPinsAsOutput(XN_GPIO_TypeDef*port, uint16_t pins);
void GPIO_SetPin (XN_GPIO_TypeDef*port, uint16_t pin);
void GPIO_ResetPin (XN_GPIO_TypeDef*port, uint16_t pin);
void GPIO_InvertOutPin(XN_GPIO_TypeDef*port, uint16_t pin);
uint8_t GPIO_GetPinState(XN_GPIO_TypeDef*port, uint16_t pin);
uint16_t GPIO_GetPortState(XN_GPIO_TypeDef*port);
void GPIO_SetPortMask(XN_GPIO_TypeDef*port, uint16_t pins);
void GPIO_ResetPortMask(XN_GPIO_TypeDef*port, uint16_t pins);
uint16_t GPIO_ReadPort(XN_GPIO_TypeDef*port);
void GPIO_WritePort(XN_GPIO_TypeDef*port, uint16_t data);
void GPIO_EnableInt(XN_GPIO_TypeDef*port, uint16_t pin, uint8_t triggeredge);


#endif /* end __GPIO_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
