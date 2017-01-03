 /**************************************************************************//**
 * @file     XN11Lxxx.h
 * @brief    CMSIS compatible Cortex-M0 Core Peripheral Access Layer Header File for
 *           ARM CMSDK
 * @version  $State: Exp $
 * @date     $Date: 2014/04/04 $
 *
 ******************************************************************************/


#ifndef __XN11Lxxx_H__
#define __XN11Lxxx_H__

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup CMSDK_Definitions CMSDK Definitions
  This file defines all structures and symbols for CMSDK:
    - Registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup CMSDK_CMSIS CMSDK CMSIS Definitions
  Configuration of the Cortex-M0 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn           = -14,    /*!< 2 Non Maskable Interrupt                           */
  HardFault_IRQn                = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                   */
  SVCall_IRQn                   = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                     */
  PendSV_IRQn                   = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                     */
  SysTick_IRQn                  = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                 */

/******  CMSDK Specific Interrupt Numbers *******************************************************/
  WAKEUP_IRQn                   = 0,        /*!< All I/O pins can be used as wakeup source.       */
  PWM_FAULT_IRQn                = 1,        /*!< PWM Fault Interrupt                              */
  TWS_IRQn                      = 2,        /*!< TWS Interrupt                                    */
  TIMER16_0_IRQn               = 3,        /*!< 16-bit Timer0 Interrupt                          */
  TIMER16_1_IRQn               = 4,        /*!< 16-bit Timer1 Interrupt                          */
  TIMER16_2_IRQn               = 5,        /*!< 16-bit Timer2 Interrupt                          */
  TIMER16_3_IRQn               = 6,        /*!< 16-bit Timer3 Interrupt                          */
  UART0_IRQn                    = 7,        /*!< UART0 Interrupt                                  */
  UART1_IRQn                    = 8,        /*!< UART1 Interrupt                                  */
  ADC_IRQn                      = 9,        /*!< A/D Converter Interrupt                        */
  WDT_IRQn                      = 10,       /*!< Watchdog timer Interrupt                         */  
  BOD_IRQn                      = 11,       /*!< Brown Out Detect(BOD) Interrupt                  */
  GPIO0_IRQn                    = 12,       /*!< External Interrupt 0 Interrupt                   */
  GPIO1_IRQn                    = 13,       /*!< External Interrupt 1 Interrupt                   */
  GPIO2_IRQn                    = 14,       /*!< External Interrupt 2 Interrupt                   */
  RTC_IRQn                      = 15,       /*!< RTC Interrupt                                    */
  SPI_IRQn                      = 16,       /*!< SSP Interrupt                                    */
  PWM_TIMER_IRQn                = 17,       /*!< PWM Timer Interrupt                                    */
  TOUCHPAD_IRQn                 = 18,       /*!< Brown Out Detect(BOD) Interrupt                  */
  ISO7816A_IRQn                 = 19,       /*!< Brown Out Detect(BOD) Interrupt                  */
  ISO7816B_IRQn                 = 20,       /*!< Brown Out Detect(BOD) Interrupt                  */

} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT             0         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */

/*@}*/ /* end of group CMSDK_CMSIS */


#include "core_cm0.h"                       /* Cortex-M0 processor and core peripherals           */
#include "system_XN11Lxxx.h"                  /* System Header                                      */

/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/*------------- System Control (SYSCON) --------------------------------------*/
/** @addtogroup XN12Lxxx_SYSCON XN12Lxxx System Control Block 
  @{
  Verified Dec. 21 YL
*/
typedef struct
{
  __IO uint32_t SYSMEMREMAP;            /*!< Offset: 0x000 System memory remap (R/W) */
  __IO uint32_t PRESETCTRL;             /*!< Offset: 0x004 Peripheral reset control (R/W) */
  __IO uint32_t SYSPLLCTRL;             /*!< Offset: 0x008 System PLL control (R/W) */
  __IO uint32_t SYSPLLSTAT;             /*!< Offset: 0x00C System PLL status (R/ ) */
       uint32_t RESERVED0[4];

  __IO uint32_t SYSOSCCTRL;             /*!< Offset: 0x020 System oscillator control (R/W) */
  __IO uint32_t WDTOSCCTRL;             /*!< Offset: 0x024 Watchdog oscillator control (R/W) */
  __IO uint32_t IRCCTRL;                /*!< Offset: 0x028 IRC control (R/W) */
       uint32_t RESERVED1[1];             /*!< Offset: 0x02C RTC oscillator control (R/W) */
  
  __IO uint32_t SYSRESSTAT;             /*!< Offset: 0x030 System reset status Register (R/ ) */
       uint32_t RESERVED2[3];
  __IO uint32_t SYSPLLCLKSEL;           /*!< Offset: 0x040 System PLL clock source select (R/W) */	
  __IO uint32_t SYSPLLCLKUEN;           /*!< Offset: 0x044 System PLL clock source update enable (R/W) */
       uint32_t RESERVED3[10];

  __IO uint32_t MAINCLKSEL;             /*!< Offset: 0x070 Main clock source select (R/W) */
  __IO uint32_t MAINCLKUEN;             /*!< Offset: 0x074 Main clock source update enable (R/W) */
  __IO uint32_t SYSAHBCLKDIV;           /*!< Offset: 0x078 System AHB clock divider (R/W) */
       uint32_t RESERVED4[1];

  __IO uint32_t SYSAHBCLKCTRL;          /*!< Offset: 0x080 System AHB clock control (R/W) */
       uint32_t RESERVED5[5];
                            
  __IO uint32_t UART0CLKDIV;            /*!< Offset: 0x098 UART0 clock divider (R/W) */
  __IO uint32_t UART1CLKDIV;            /*!< Offset: 0x09C UART1 clock divider (R/W) */
  
       uint32_t RESERVED6[16];             
     
            
  __IO uint32_t CLKOUTCLKSEL;           /*!< Offset: 0x0E0 CLKOUT clock source select (R/W) */
  __IO uint32_t CLKOUTUEN;              /*!< Offset: 0x0E4 CLKOUT clock source update enable (R/W) */
  __IO uint32_t CLKOUTDIV;              /*!< Offset: 0x0E8 CLKOUT clock divider (R/W) */       
       uint32_t RESERVED8[5];   

  __I  uint32_t PIOPORCAP0;             /*!< Offset: 0x100 POR captured PIO0 status  (R/) */            
  __I  uint32_t PIOPORCAP1;             /*!< Offset: 0x104 POR captured PIO1 status  (R/) */ 
  __I  uint32_t PIOPORCAP2;             /*!< Offset: 0x104 POR captured PIO2 status  (R/) */
       uint32_t RESERVED9[10];
       
  __IO uint32_t IOCONFIGCLKDIV6;          /* Offset 0x134 */
  __IO uint32_t IOCONFIGCLKDIV5;
  __IO uint32_t IOCONFIGCLKDIV4;
  __IO uint32_t IOCONFIGCLKDIV3;          /* Offset 0x140 */
  __IO uint32_t IOCONFIGCLKDIV2;
  __IO uint32_t IOCONFIGCLKDIV1;
  __IO uint32_t IOCONFIGCLKDIV0;	
    	  	            
  __IO uint32_t BODCTRL;                 /*!< Offset: 0x150 BOD control (R/W) */
       uint32_t RESERVED10[1];              
  __IO uint32_t AHBPRIO;                 /*!< Offset: 0x158 AHB priority setting (R/W) */
  
       uint32_t RESERVED11[5];    
  __IO uint32_t IRQLATENCY;             /*!< Offset: 0x170 IRQ delay (R/W) */
  __IO uint32_t INTNMI;                 /*!< Offset: 0x174 NMI interrupt source configuration control (R/W) */
       uint32_t RESERVED12[34];          

  __IO uint32_t DSWAKECTL;
  __IO uint32_t DSWAKEEN;
  __O  uint32_t DSWAKECLR;
  __I  uint32_t DSWAKE;
       uint32_t RESERVED13[8];

  __IO uint32_t PDSLEEPCFG;             /*!< Offset: 0x230 Power-down states in Deep-sleep mode (R/W) */
  __IO uint32_t PDAWAKECFG;             /*!< Offset: 0x234 Power-down states after wake-up (R/W) */       
  __IO uint32_t PDRUNCFG;               /*!< Offset: 0x238 Power-down configuration Register (R/W) */
  __IO uint32_t PMUCFG;                 /*!< Offset: 0x23C PMU config Register (R/W) */

       uint32_t RESERVED14[2];

  __IO uint32_t U7816ACLKDIV;            /*!< Offset: 0x248 7816A clock divider Register (R/W) */
  __IO uint32_t U7816ACTRL;               /*!< Offset: 0x24C 7816A control Register (R/W) */
  __IO uint32_t U7816BCLKDIV;            /*!< Offset: 0x250 7816A clock divider Register (R/W) */
  __IO uint32_t U7816BCTRL;               /*!< Offset: 0x254 7816A control Register (R/W) */

       uint32_t RESERVED15[103];

       
  __O  uint32_t DEVICE_ID;              /*!< Offset: 0x3F4 Device ID (R/ ) */  
} XN_SYSCON_TypeDef;
/*@}*/ /* end of group XN_SYSCON */


/*------------- Pin Connect Block (IOCON) --------------------------------*/
/** @addtogroup XN_IOCON XN12Lxxx I/O Configuration Block 
  @{
  Verified Dec. 21 YL
*/
typedef struct
{
  __IO uint32_t PIO2_13;            /*!< Offset: 0x008 Configures pin PIO0_19/ACMP0_I0/CT32B0_1.  (R/W) */
  __IO uint32_t PIO2_14;
  __IO uint32_t PIO2_15;
  __IO uint32_t PIO2_7;
  __IO uint32_t PIO2_8;
  __IO uint32_t PIO2_9;

  __IO uint32_t PIO0_0;     /*!< Offset: 0x020 pin SWDIO/ACMP1_I2/CT32B1_2/CT16B0_RST/PIO0_25.  (R/W) */
  __IO uint32_t PIO0_1;
  __IO uint32_t PIO0_2;
  __IO uint32_t PIO0_3;
  __IO uint32_t PIO0_4;
  __IO uint32_t PIO0_5;
  __IO uint32_t PIO0_6;
  __IO uint32_t PIO0_7;
  uint32_t RESERVED0[8];
  __IO uint32_t PIO1_0;            /*!< Offset: 0x040 Configures pin PIO0_29/ROSC/CT16B0_1.  (R/W) */
  __IO uint32_t PIO1_1;
  __IO uint32_t PIO1_2;
  __IO uint32_t PIO1_10;
  __IO uint32_t PIO1_11;
  __IO uint32_t PIO1_12;
  __IO uint32_t PIO1_13;
  __IO uint32_t PIO1_14;
  __IO uint32_t PIO1_15;
  uint32_t RESERVED1[4];
  __IO uint32_t PIO0_8;             /*!< Offset: 0x060 Configures pin PIO0_6/RI0/CT32B1_0.  (R/W) */
  __IO uint32_t PIO0_9;
  __IO uint32_t PIO0_10;
  __IO uint32_t PIO0_11;
  __IO uint32_t PIO0_12;
  __IO uint32_t PIO0_13;
  __IO uint32_t PIO2_10;
  __IO uint32_t PIO2_11;
  __IO uint32_t PIO0_14;
  __IO uint32_t PIO0_15;
  uint32_t RESERVED2[4];
  __IO uint32_t PIO1_3;             /*!< Offset: 0x080 Configures pin PIO2_4/CT32B0_0/CTS0.  (R/W) */
  __IO uint32_t PIO1_4;
  __IO uint32_t PIO1_5;
  __IO uint32_t PIO1_6;
  __IO uint32_t PIO1_7;
  __IO uint32_t PIO2_12;
  __IO uint32_t PIO1_8;
  __IO uint32_t PIO1_9;
  
} XN_IOCON_TypeDef;
/*@}*/ /* end of group XN_IOCON */

/*------------- Micro DMA controller (DMA) --------------------------*/
/** @addtogroup XN_DMA XN12Lxxx Micro DMA controller 
  @{
Verified Aug. 23 YL
*/
typedef struct
{
  __I  uint32_t STATUS;             /*!< Offset: 0x000 DMA status register (R/) */
  __O  uint32_t CFG;
  __IO uint32_t CTRL_BASE_PTR;
	
  uint32_t RESERVED0[2];
	
  __O  uint32_t CHNL_SW_REQUEST;
  __IO uint32_t CHNL_USEBURST_SET;
  __O  uint32_t CHNL_USEBURST_CLR;
  
  __IO uint32_t CHNL_REQ_MASK_SET;  /*!< Offset: 0x020 Channel request mask set register (R/W) */
  __O  uint32_t CHNL_REQ_MASK_CLR;
  __IO uint32_t CHNL_ENABLE_SET;
  __O  uint32_t CHNL_ENABLE_CLR;
	
  uint32_t RESERVED1[2];
	
  __IO uint32_t CHNL_PRIORITY_SET;
  __O  uint32_t CHNL_PRIORITY_CLR;   /*!< Offset: 0x034 Channel priority clear register (W) */
  
  uint32_t RESERVED2[16];        /* 0x40 */
  	   
  __IO uint32_t CHNL_IRQ_STATUS;    /*!< Offset: 0x080 Channel DMA interrupt status register (R/W) */
  
  uint32_t RESERVED3;
 
	__IO uint32_t CHNL_IRQ_ENABLE;     
} XN_DMA_TypeDef;
/*@}*/ /* end of group XN_DMA */


/*------------- Comparator (COMP) --------------------------*/
/** @addtogroup XN_COMP XN12Lxxx Comparator 
  @{
*/
typedef struct
{
  __IO uint32_t CCR;        /*!< Offset: 0x000 Comparator control register (R/W) */
  __IO uint32_t VLAD;       /*!< Offset: 0x004 Voltage ladder register (R/W) */
  __IO uint32_t reserved;
  __IO uint32_t INTSTA;     /*!< Offset: 0x00C Interrupt status */
} XN_COMP_TypeDef;
/*@}*/ /* end of group XN_COMP */


/*------------- Real Time Clock (RTC) --------------------------*/
/** @addtogroup XN_RTC XN12Lxxx Real Time Clock 
  @{
*/
typedef struct
{    
  __I  uint32_t DR;     /*!< Offset: 0x000 Data register (R/) */
  __IO uint32_t MR;
  __IO uint32_t LR;
  __IO uint32_t CR;
  __IO uint32_t ICSC;
  __I  uint32_t RIS;
  __I  uint32_t MIS;
  __O uint32_t ICR;
} XN_RTC_TypeDef;
/*@}*/ /* end of group XN_RTC */


/*------------- Power Management Unit (PMU) --------------------------*/
/** @addtogroup XN_PMU XN12Lxxx Power Management Unit 
  @{
*/
typedef struct
{
  __IO uint32_t PCON;                   /*!< Offset: 0x000 Power control Register (R/W) */
  __IO uint32_t GPREG0;                 /*!< Offset: 0x004 General purpose Register 0 (R/W) */
  __IO uint32_t GPREG1;                 /*!< Offset: 0x008 General purpose Register 1 (R/W) */
  __IO uint32_t GPREG2;                 /*!< Offset: 0x00C General purpose Register 2 (R/W) */
  __IO uint32_t GPREG3;                 /*!< Offset: 0x010 General purpose Register 3 (R/W) */
  __IO uint32_t SYSCFG;                 /*!< Offset: 0x014 General purpose Register 4 (R/W) */
} XN_PMU_TypeDef;
/*@}*/ /* end of group XN_PMU */


/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @addtogroup XN_GPIO XN12Lxx General Purpose Input/Output 
  @{
*/
typedef struct
{    
  __IO uint32_t MASK;       /*!< Offset: 0x000 Pin value mask register (R/W) */
  __I  uint32_t PIN;
  __IO uint32_t OUT;
  __O  uint32_t SET;
  __O  uint32_t CLR;        /*!< Offset: 0x010 Pin output value clear register (R/W) */
  __O  uint32_t NOT;
  	   uint32_t RESERVE[2];
  __IO uint32_t DIR;        /*!< Offset: 0x020 Data direction register (R/W) */
  __IO uint32_t IS;
  __IO uint32_t IBE;
  __IO uint32_t IEV;
  __IO uint32_t IE;
  __I  uint32_t RIS;
  __I  uint32_t MIS;
  __O  uint32_t IC;
} XN_GPIO_TypeDef;
/*@}*/ /* end of group XN_GPIO */


/*------------- Timer (TMR) --------------------------------------------------*/
/** @addtogroup XN_TMR XN12Lxxx 16/32-bit Counter/Timer 
  @{
  Verified Dec. 21 YL
*/
typedef struct
{
  __IO uint32_t IR;                     /*!< Offset: 0x000 Interrupt Register (R/W) */
  __IO uint32_t TCR;                    /*!< Offset: 0x004 Timer Control Register (R/W) */
  __IO uint32_t TC;                     /*!< Offset: 0x008 Timer Counter Register (R/W) */
  __IO uint32_t PR;                     /*!< Offset: 0x00C Prescale Register (R/W) */
  __IO uint32_t PC;                     /*!< Offset: 0x010 Prescale Counter Register (R/W) */
  __IO uint32_t MCR;                    /*!< Offset: 0x014 Match Control Register (R/W) */
	__IO uint32_t MR[4];
  //__IO uint32_t MR0;                    /*!< Offset: 0x018 Match Register 0 (R/W) */
  //__IO uint32_t MR1;                    /*!< Offset: 0x01C Match Register 1 (R/W) */
  //__IO uint32_t MR2;                    /*!< Offset: 0x020 Match Register 2 (R/W) */
  //__IO uint32_t MR3;                    /*!< Offset: 0x024 Match Register 3 (R/W) */
  __IO uint32_t CCR;                    /*!< Offset: 0x028 Capture Control Register (R/W) */
	__I  uint32_t CR[4];
  //__I  uint32_t CR0;                    /*!< Offset: 0x02C Capture Register 0 (R/ ) */
  //__I  uint32_t CR1;                    /*!< Offset: 0x030 Capture Register 1 (R/ ) */
  //__I  uint32_t CR2;                    /*!< Offset: 0x034 Capture Register 2 (R/ ) */
  //__I  uint32_t CR3;                    /*!< Offset: 0x038 Capture Register 3 (R/ ) */
  __IO uint32_t EMR;                    /*!< Offset: 0x03C External Match Register (R/W) */
       uint32_t RESERVED2[12];
  __IO uint32_t CTCR;                   /*!< Offset: 0x070 Count Control Register (R/W) */
  __IO uint32_t PWMC;                   /*!< Offs   et: 0x074 PWM Control Register (R/W) */ 
} XN_TMR_TypeDef;
/*@}*/ /* end of group XN_TMR */


/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
/** @addtogroup CMSDK_UART CMSDK Universal Asynchronous Receiver/Transmitter
  memory mapped structure for CMSDK_UART
  @{
  Verified Dec. 21 YL
*/
typedef struct
{
  __IO   uint32_t  DATA;          /*!< Offset: 0x000 Data Register    (R/W) */
  __IO   uint32_t  STATE;         /*!< Offset: 0x004 Status Register  (R/W) */
  __IO   uint32_t  CTRL;          /*!< Offset: 0x008 Control Register (R/W) */
  union {
    __I    uint32_t  INTSTATUS;   /*!< Offset: 0x00C Interrupt Status Register (R/ ) */
    __O    uint32_t  INTCLEAR;    /*!< Offset: 0x00C Interrupt Clear Register ( /W) */
    };
  __IO   uint32_t  BAUDDIV;       /*!< Offset: 0x010 Baudrate Divider Register (R/W) */
  __O 	 uint32_t  FIFOCLR; 

} XN_UART_TypeDef;


/*------------- Serial Peripheral Interface (SPI) -----------------------*/
/** @addtogroup XN_SPI XN12Lxxx Serial Peripheral Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CR0;                    /*!< Offset: 0x000 Control Register 0 (R/W) */
  __IO uint32_t CR1;                    /*!< Offset: 0x004 Control Register 1 (R/W) */
  __IO uint32_t DR;                     /*!< Offset: 0x008 Data Register (R/W) */
  __I  uint32_t SR;                     /*!< Offset: 0x00C Status Registe (R/ ) */
  __IO uint32_t CPSR;                   /*!< Offset: 0x010 Clock Prescale Register (R/W) */
  __IO uint32_t IMSC;                   /*!< Offset: 0x014 Interrupt Mask Set and Clear Register (R/W) */
  __IO uint32_t RIS;                    /*!< Offset: 0x018 Raw Interrupt Status Register (R/W) */
  __IO uint32_t MIS;                    /*!< Offset: 0x01C Masked Interrupt Status Register (R/W) */
  __IO uint32_t ICR;                    /*!< Offset: 0x020 Interrupt Clear Register (R/W) */
  __IO uint32_t DMACR;                  /*!< Offset: 0x024 DMA Control Register (R/W) */
} XN_SPI_TypeDef;
/*@}*/ /* end of group XN_SPI */

/*------------- Serial Peripheral Quad Interface (QSPI) -----------------------*/
/** @addtogroup XN_QSPI XN12Lxxx Serial Peripheral Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CR0;                    /*!< Offset: 0x000 Control Register 0 (R/W) */
  __IO uint32_t CR1;                    /*!< Offset: 0x004 Control Register 1 (R/W) */
  __IO uint32_t DR;                     /*!< Offset: 0x008 Data Register (R/W) */
  __I  uint32_t SR;                     /*!< Offset: 0x00C Status Registe (R/ ) */
  __IO uint32_t CPSR;                   /*!< Offset: 0x010 Clock Prescale Register (R/W) */
  __IO uint32_t IMSC;                   /*!< Offset: 0x014 Interrupt Mask Set and Clear Register (R/W) */
  __IO uint32_t RIS;                    /*!< Offset: 0x018 Raw Interrupt Status Register (R/W) */
  __IO uint32_t MIS;                    /*!< Offset: 0x01C Masked Interrupt Status Register (R/W) */
  __IO uint32_t ICR;                    /*!< Offset: 0x020 Interrupt Clear Register (R/W) */
  __IO uint32_t DMACR;                  /*!< Offset: 0x024 DMA Control Register (R/W) */
} XN_QSPI_TypeDef;
/*@}*/ /* end of group XN_QSPI */

/*------------- Two Wire Serial Communication(TWS) -------------------------------*/
/** @addtogroup XN_TWS XN12Lxxx TWS-Bus Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CONSET;                 /*!< Offset: 0x000 TWS Control Set Register (R/W) */
  __I  uint32_t STAT;                   /*!< Offset: 0x004 TWS Status Register (R/ ) */
  __IO uint32_t DAT;                    /*!< Offset: 0x008 TWS Data Register (R/W) */
  __IO uint32_t ADR0;                   /*!< Offset: 0x00C TWS Slave Address Register 0 (R/W) */
  __IO uint32_t SCLH;                   /*!< Offset: 0x010 SCH Duty Cycle Register High Half Word (R/W) */
  __IO uint32_t SCLL;                   /*!< Offset: 0x014 SCL Duty Cycle Register Low Half Word (R/W) */
  __O  uint32_t CONCLR;                 /*!< Offset: 0x018 TWS Control Clear Register ( /W) */
		uint32_t RESERVED;                 /*!< Offset: 0x01C Monitor mode control register (R/W) */
  __IO uint32_t ADR1;                   /*!< Offset: 0x020 TWS Slave Address Register 1 (R/W) */
  __IO uint32_t ADR2;                   /*!< Offset: 0x024 TWS Slave Address Register 2 (R/W) */
  __IO uint32_t ADR3;                   /*!< Offset: 0x028 TWS Slave Address Register 3 (R/W) */
  __I  uint32_t DATA_BUFFER;            /*!< Offset: 0x02C Data buffer register ( /W) */
  __IO uint32_t MASK0;                  /*!< Offset: 0x030 TWS Slave address mask register 0 (R/W) */
  __IO uint32_t MASK1;                  /*!< Offset: 0x034 TWS Slave address mask register 1 (R/W) */
  __IO uint32_t MASK2;                  /*!< Offset: 0x038 TWS Slave address mask register 2 (R/W) */
  __IO uint32_t MASK3;                  /*!< Offset: 0x03C TWS Slave address mask register 3 (R/W) */
} XN_TWS_TypeDef;
/*@}*/ /* end of group XN_TWS */


/*------------- Watchdog Timer (WDT) -----------------------------------------*/
/** @addtogroup XN_WDT XN12Lxxx WatchDog Timer 
  @{
*/
typedef struct
{
  __IO uint32_t MOD;                    /*!< Offset: 0x000 Watchdog mode register (R/W) */
  __IO uint32_t TC;                     /*!< Offset: 0x004 Watchdog timer constant register (R/W) */
  __O  uint32_t FEED;                   /*!< Offset: 0x008 Watchdog feed sequence register ( /W) */
  __I  uint32_t TV;                     /*!< Offset: 0x00C Watchdog timer value register (R/ ) */
  __IO uint32_t WDCLKSEL;               /*!< Offset: 0x010 Watchdog clock source selectuin register (R/W ) */ 
  __IO uint32_t WARNINT;                /*!< Offset: 0x014 Watchdog Warning Interrupt compare value register (R/W ) */
  __IO uint32_t WINDOW;                 /*!< Offset: 0x018 Watchdog Window compare value register (R/W ) */  
} XN_WDT_TypeDef;
/*@}*/ /* end of group XN_WDT */


/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** @addtogroup XN_ADC XN12Lxxx Analog-to-Digital Converter 
  @{
*/
typedef struct
{
 	__IO uint32_t CR; 	/*!< Offset: 	0x000 	ADC Control Register. */ 
	__IO uint32_t GDR; 	/*!< Offset:  	0x004 	ADC Global Data Register. */ 
	__IO uint32_t CHSEL;	/*!< Offset: 	0x008 	Channel select register */
	__IO uint32_t INTEN; 	/*!< Offset:  	0x00C 	ADC Interrupt Enable Register. */ 
	__IO uint32_t DR[8]; 	/*!< Offset:  	0x010~0x02C 	A/D Channel 0 Data Register. */ 
	__O uint32_t INTSTAT; 	/*!< Offset:  	0x030 	ADC Status Register. */ 
	__IO uint32_t HILMT;	/*!< Offset: 	0x034 	ADC High Limit Control Register. */
	__IO uint32_t LOLMT;	/*!< Offset: 	0x038	ADC Low Limit Control Register. */
	__IO uint32_t RESERVED1;
	__IO uint32_t SSCR;	   /*!< Offset: 	0x040	Software trigger register */
	
} XN_ADC_TypeDef;


/*@}*/ /* end of group XN_ADC */

/*-------------- Digital-to-Analog Converter (DAC) ----------------------------*/
/** @addtogroup XN_DAC XN12Lxxx Digital-to-Analog Converter
  @{
*/
typedef struct
{
  __IO uint32_t CTRL;
  __O uint32_t BUFF;
}XN_DAC_TypeDef;

/*@}*/ /* end of group XN_DAC */


/*------------- CRC Engine (CRC) ----------------------------*/
/** @addtogroup XN_CRC XN12Lxxx CRC Engine 
  @{
*/
typedef struct
{
  __IO uint32_t MODE;
  __IO uint32_t SEED;
  union {
  __I  uint32_t SUM; 
  __O  uint32_t WR_DATA_DWORD;
  __O  uint16_t WR_DATA_WORD;
  __O  uint8_t WR_DATA_BYTE;
  };
} XN_CRC_TypeDef;
/*@}*/ /* end of group XN_CRC */


/*------------- 7816 Interface ----------------------------*/ 
/** @addtogroup XN_CRC XN12Lxxx CRC Engine 
  @{
*/
typedef struct
{   
  __IO uint32_t WRBUF;
  __IO uint32_t RDBUF;
  __IO uint32_t TXDONE;
  __IO uint32_t RXDONE;
  __IO uint32_t STADET;
  __O  uint32_t EOITX;
  __O  uint32_t EOIRX;
  __O  uint32_t EOISTADET;
  __IO uint32_t TRANSSTAT;
  __IO uint32_t FIFOSTAT;
  __IO uint32_t INTMASK;
  __IO uint32_t MODE;
  __IO uint32_t ETUCFG;
  __O  uint32_t INTRAWSTAT;
  __O  uint32_t INTSTAT;
} XN_7816_TypeDef;

/*---------------- CAP Sensor -------------------------------*/
typedef struct
{   
  __O  uint32_t RAWINT;
  __IO uint32_t CR;
  __IO uint32_t SENLEN; 
  __IO uint32_t INTSTAT;
  __IO uint32_t WATMARK;
       uint32_t RESERVED; 
  __IO uint32_t FREQCNT;
} XN_TOUCHPAD_TypeDef;
/*------------- Flash Memory Controller (FMC) ----------------------------*/
/** @addtogroup XN12Lxxx Flash Memory 
  @{
  Verified Dec. 21 YL
*/
typedef struct
{
       uint32_t RESERVED1[10];
  __IO uint32_t FLASHRDCYC;           /* Flash read access cycle config register */
  __I  uint16_t MID;          /* Manufactual ID */
  __I  uint16_t DID;          /* Device ID */
  __I  uint32_t VERID;          /* Device version ID */
  __I  uint32_t UNIQEID;          /* Device serial ID */

} XN_FMC_TypeDef;
/*@}*/ /* end of group XN12Lxx_FMC */


#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define XN_FLASH_BASE        (0x00000000UL)
#define XN_RAM_BASE          (0x10000000UL)
#define XN_APB0_BASE         (0x40000000UL)
#define XN_AHB_BASE          (0x50000000UL)

/* APB0 peripherals                                                           */
#define XN_TWS_BASE          (XN_APB0_BASE + 0x00000)
#define XN_WDT_BASE          (XN_APB0_BASE + 0x04000)
#define XN_UART0_BASE        (XN_APB0_BASE + 0x08000)
#define XN_UART1_BASE        (XN_APB0_BASE + 0x0C000)
#define XN_UART2_BASE        (XN_APB0_BASE + 0x64000)
#define XN_CT16B0_BASE       (XN_APB0_BASE + 0x10000)
#define XN_CT16B1_BASE       (XN_APB0_BASE + 0x14000)
#define XN_CT16B2_BASE       (XN_APB0_BASE + 0x18000)
#define XN_CT16B3_BASE       (XN_APB0_BASE + 0x1C000)
#define XN_ADC_BASE          (XN_APB0_BASE + 0x20000)
#define XN_PMU_BASE          (XN_APB0_BASE + 0x38000)
#define XN_SPI_BASE          (XN_APB0_BASE + 0x40000)
#define XN_IOCON_BASE        (XN_APB0_BASE + 0x44000)
#define XN_SYSCON_BASE       (XN_APB0_BASE + 0x48000)
#define XN_RTC_BASE          (XN_APB0_BASE + 0x50000)
#define XN_7816A_BASE        (XN_APB0_BASE + 0x70000)
#define XN_7816B_BASE        (XN_APB0_BASE + 0x74000)
#define XN_TOUCHPAD_BASE     (XN_APB0_BASE + 0x78000)
/* AHB peripherals                                                            */	
#define XN_GPIO_BASE         (XN_AHB_BASE  + 0x00000)
#define XN_GPIO0_BASE        (XN_AHB_BASE  + 0x00000)
#define XN_GPIO1_BASE        (XN_AHB_BASE  + 0x10000)
#define XN_GPIO2_BASE        (XN_AHB_BASE  + 0x20000)

#define XN_FMC_BASE          (XN_AHB_BASE  + 0x60000)
#define XN_CRC_BASE          (XN_AHB_BASE  + 0x70000)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define XN_TWS               ((XN_TWS_TypeDef    *) XN_TWS_BASE   )
#define XN_WDT               ((XN_WDT_TypeDef    *) XN_WDT_BASE   )
#define XN_UART0             ((XN_UART_TypeDef   *) XN_UART0_BASE)
#define XN_UART1             ((XN_UART_TypeDef   *) XN_UART1_BASE)
#define XN_UART2             ((XN_UART_TypeDef   *) XN_UART2_BASE)
#define XN_TMR16B0           ((XN_TMR_TypeDef    *) XN_CT16B0_BASE)
#define XN_TMR16B1           ((XN_TMR_TypeDef    *) XN_CT16B1_BASE)
#define XN_TMR32B0           ((XN_TMR_TypeDef    *) XN_CT32B0_BASE)
#define XN_TMR32B1           ((XN_TMR_TypeDef    *) XN_CT32B1_BASE)
#define XN_ADC               ((XN_ADC_TypeDef    *) XN_ADC_BASE   )
#define XN_PMU               ((XN_PMU_TypeDef    *) XN_PMU_BASE   )
#define XN_SPI               ((XN_SPI_TypeDef    *) XN_SPI_BASE  )
#define XN_IOCON             ((XN_IOCON_TypeDef  *) XN_IOCON_BASE )
#define XN_SYSCON            ((XN_SYSCON_TypeDef *) XN_SYSCON_BASE)
#define XN_RTC               ((XN_RTC_TypeDef    *) XN_RTC_BASE)
#define XN_GPIO0             ((XN_GPIO_TypeDef   *) XN_GPIO0_BASE )
#define XN_GPIO1             ((XN_GPIO_TypeDef   *) XN_GPIO1_BASE )
#define XN_GPIO2             ((XN_GPIO_TypeDef   *) XN_GPIO2_BASE )
#define XN_7816A             ((XN_7816_TypeDef   *) XN_7816A_BASE)
#define XN_7816B             ((XN_7816_TypeDef   *) XN_7816B_BASE)
#define XN_FMC               ((XN_FMC_TypeDef    *) XN_FMC_BASE)
#define XN_CRC               ((XN_CRC_TypeDef    *) XN_CRC_BASE)
#ifdef __cplusplus
}
#endif


#endif  /* __CMSDK_H__ */

