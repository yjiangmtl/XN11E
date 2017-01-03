/*****************************************************************************
 *   xn_SYS.h:  Header file for Xinnova XN11E Family Microprocessors
 *
 *   Copyright(C) 2011, Xinnova tech. Ltd.
 *   All rights reserved.
 *
 *   History
 *   2015  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __SYS_H 
#define __SYS_H
#include "XN11Exxx.h"


//--SYS Registers BITS Field---------------------------------------------------------------------------------------
struct SYSMEMREMAP_BITS {									// bit description
				uint32_t MAP:2;                    // System memory remap
				uint32_t RSVD:30;                      // 31:2 reserved
};
union SYSMEMREMAP_REG {
				uint32_t				all;
				struct SYSMEMREMAP_BITS	bit;
};

struct SYSRESSTAT_BITS {									// bit description
				uint32_t POR:1;                    // 		POR reset status 
				uint32_t EXTRST:1;                    //		reset status 
				uint32_t WDTRST:1;                    // 		Status of the Watchdog reset 
				uint32_t BOD:1;                    // 		Status of the Brown-out detect reset 
				uint32_t SYSRST:1;                    // 		Status of the software system reset. 
				uint32_t RSVD:27;                      // 31:5 reserved
};
union SYSRESSTAT_REG {
				uint32_t				all;
				struct SYSRESSTAT_BITS	bit;
};

struct BODCTRL_BITS {									// bit description
				uint32_t RSVD0:4;
				uint32_t BODRSTEN :1;                    //		BOD reset enable 
				uint32_t RSVD1:1;                     
				uint32_t BODINTCLR:1;                    // Write 1 to clear interrupt signal 
				uint32_t RSVD2:25;                      
};
union BODCTRL_REG {
				uint32_t				all;
				struct BODCTRL_BITS	bit;
};

struct WDTOSCCTRL_BITS {									// bit description
				uint32_t DIVSEL:5;                    //	 		Select divider for Fclkana .  
				uint32_t CTRIM:3;                    //			trim watchdog oscillator capacitor
				uint32_t RTRIM:4;                    //			trim watchdog oscillator resistor
				uint32_t WDTCLKSRC:1;                    //			Watch dog timer clock source. 
				uint32_t RSVD:19;                      
};
union WDTOSCCTRL_REG {
				uint32_t				all;
				struct WDTOSCCTRL_BITS	bit;
};

struct IRCCTRL_BITS {									// bit description
				uint32_t CTRIM:2;                   //C Trim value
				uint32_t RTRIM:3;                    //R Trim value
				uint32_t SW:1;                    //40MHz/48MHz switch, 0:40MHz,1:48MHz
				uint32_t RSVD:26;                      
};
union IRCCTRL_REG {
				uint32_t				all;
				struct IRCCTRL_BITS	bit;
};

// struct RTCCFG_BITS {									// bit description
// 				uint32_t RSVD0:11;                  
// 				uint32_t RTCCLK:2;                    //RTC clock source select
// 				uint32_t RSVD1:19;                      
// };
// union RTCCFG_REG {
// 				uint32_t				all;
// 				struct RTCCFG_BITS	bit;
// };


struct MAINCLKSEL_BITS {									// bit description
				uint32_t SEL:2;                    //Clock source for main clock 
				uint32_t RSVD:30;                      
};
union MAINCLKSEL_REG {
				uint32_t				all;
				struct MAINCLKSEL_BITS	bit;
};

struct MAINCLKUEN_BITS {									// bit description
				uint32_t ENA:2;                    //Enable main clock source update  
				uint32_t RSVD:30;                      
};
union MAINCLKUEN_REG {
				uint32_t				all;
				struct MAINCLKUEN_BITS	bit;
};

struct SYSAHBCLKDIV_BITS {									// bit description
				uint32_t DIV:8;                    //System AHB clock divider values  
				uint32_t RSVD:24;                      
};
union SYSAHBCLKDIV_REG {
				uint32_t				all;
				struct SYSAHBCLKDIV_BITS	bit;
};

struct SYSAHBCLKCTRL_BITS {									// bit description
				uint32_t SYS:1;                    //Enables clock for AHB to APB bridge, to the AHB matrix, to the Cortex?-M0 FCLK and HCLK, to the SysCon, and to the PMU. 
				uint32_t RSVD0:1;
				uint32_t RAM:1;                    //Enables clock for RAM. 
				uint32_t RSVD1:2;
				uint32_t TWSCLK:1;                    //Enables clock for TWS. 
				uint32_t CRCCLK:1;                    //Enables clock for CRC. 
				uint32_t CT16B0CLK:1;                    //Enables clock for 16-bit basement counter/timer 0. 
				uint32_t CT16B1CLK:1;                    //Enables clock for 16-bit basement counter/timer 1. 
				uint32_t CT16B2CLK:1;                    // 		Enables clock for 16-bit counter/timer 2. 
				uint32_t CT16B3CLK:1;                    // 		Enables clock for 16-bit counter/timer 3. 
				uint32_t SPICLK:1;                    // 		Enables clock for SPI. 
				uint32_t UART0CLK:1;                    // 		Enables clock for UART0. Note that the UART0 pins must be configured in the IOCON block before the UART0 clock can be enabled. 
				uint32_t UART1CLK:1;                    // 		Enables clock for UART1. Note that the UART1 pins must be configured in the IOCON block before the UART1 clock can be enabled. 
				uint32_t ADCCLK:1;                    //		Enables clock for ADC
				uint32_t WDTCLK:1;                    // 		Enables clock for WDT. 
				uint32_t IOCONCLK:1;                    // 		Enables clock for IO configuration block. 
				uint32_t PWMCLK:1;                    // 		Enables clock for 16-bit PWM
				uint32_t LCD:1;                    //		Enables clock for LCD 
				uint32_t RTCCLK:1;                    // 		Enables clock for RTC. 
				uint32_t TOUCH:1;                    //		Enables clock for 24-bit Cap Touch. 
				uint32_t RSVD2:8;
				uint32_t PIO0:1;                    // 		Enables clock for GPIO port 0. 
				uint32_t PIO1:1;                    // 		Enables clock for GPIO port 1. 
				uint32_t PIO2:1;                    // 		Enables clock for GPIO port 2. 
};
union SYSAHBCLKCTRL_REG {
				uint32_t				all;
				struct SYSAHBCLKCTRL_BITS	bit;
};

struct UARTCLKDIV_BITS {									// bit description
				uint32_t DIV:8;                    //UARTn clock divider values 
				uint32_t RSVD:24;                      
};
union UARTCLKDIV_REG {
				uint32_t				all;
				struct UARTCLKDIV_BITS	bit;
};


struct CLKOUTCLKSEL_BITS {									// bit description
				uint32_t SEL:3;                    //CLKOUT clock source 
				uint32_t RSVD:29;                      
};
union CLKOUTCLKSEL_REG {
				uint32_t				all;
				struct CLKOUTCLKSEL_BITS	bit;
};

struct CLKOUTUEN_BITS {									// bit description
				uint32_t ENA:1;                    //Enable CLKOUT clock source update 
				uint32_t RSVD:31;                      
};
union CLKOUTUEN_REG {
				uint32_t				all;
				struct CLKOUTUEN_BITS	bit;
};

struct CLKOUTDIV_BITS {									// bit description
				uint32_t DIV:8;                    //Clock divider value  
				uint32_t RSVD:24;                      
};
union CLKOUTDIV_REG {
				uint32_t				all;
				struct CLKOUTDIV_BITS	bit;
};

struct IOCONFIGCLKDIV_BITS {									// bit description
				uint32_t DIV:8;                    //Clock divider value  
				uint32_t RSVD:24;                      
};
union IOCONFIGCLKDIV_REG {
				uint32_t				all;
				struct IOCONFIGCLKDIV_BITS	bit;
};

struct PCON_BITS {									// bit description
				uint32_t RSVD0:1;
				uint32_t DPDEN:1;                    //Power-down mode enable   
				uint32_t RSVD1:6;
				uint32_t SLEEPFLAG:1;                    //Sleep mode flag 
				uint32_t RSVD2:2;
				uint32_t DPDFLAG:1;                    //Power-down flag 
				uint32_t RSVD3:20;                      
};
union PCON_REG {
				uint32_t				all;
				struct PCON_BITS	bit;
};

struct PDSLEEPCFG_BITS {									// bit description
				uint32_t RSVD0:3;
				uint32_t BOD_PD:1;                    //BOD power-down control in Deep-sleep mode   
				uint32_t RSVD1:1;
				uint32_t RTCOSC_PD:1;                    //RTC oscillator power-down control in Deep-sleep mode 
				uint32_t WDTOSC_PD:1;					 //Watchdog oscillator power-down in Deep-sleep mode
				uint32_t RSVD2:25;                      
};
union PDSLEEPCFG_REG {
				uint32_t				all;
				struct PDSLEEPCFG_BITS	bit;
};

struct PDAWAKECFG_BITS {									// bit description
				uint32_t RSVD0:1;
				uint32_t IRC_PD:1;                    //IRC oscillator power-down 
				uint32_t RSVD1:1;
				uint32_t BOD_PD:1;                    //BOD detector power-down 
				uint32_t ADC_PD:1;                    //ADC power-down 
				uint32_t RTCOSC_PD:1;                    //RTC oscillator power-down 
				uint32_t WDTOSC_PD:1;                    //	Watchdog oscillator power-down 
				uint32_t LCD_PD:1;                    //LCD Voltage generator power-down 
				uint32_t TOUCH_PD:1;                    //Cap Touch Comparator power-down 
				uint32_t RSVD2:23;                      
};
union PDAWAKECFG_REG {
				uint32_t				all;
				struct PDAWAKECFG_BITS	bit;
};
union PDRUNCFG_REG {
				uint32_t				all;
				struct PDAWAKECFG_BITS	bit;
};

struct DSWAKECTL_BITS {									// bit description
				uint32_t CTLPIO0_0:1; //Edge select for wake up on pin PIO0_0 to trigger wakeup interrupt . 
				uint32_t CTLPIO0_1:1; //Edge select for wake up on pin PIO0_1 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_2:1; //Edge select for wake up on pin PIO0_2 to trigger wakeup interrupt.
				uint32_t CTLPIO0_3:1; //Edge select for wake up on pin PIO0_3 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_4:1; //Edge select for wake up on pin PIO0_4 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_5:1; //Edge select for wake up on pin PIO0_5 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_6:1; //Edge select for wake up on pin PIO0_6 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_7:1; //Edge select for wake up on pin PIO0_7 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_8:1; //Edge select for wake up on pin PIO0_8 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_9:1; //Edge select for wake up on pin PIO0_9 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_10:1; //Edge select for wake up on pin PIO0_10 to trigger wakeup interrupt. 
				uint32_t CTLPIO0_11:1; //Edge select for wake up on pin PIO0_11 to trigger wakeup interrupt.
				uint32_t RSVD:20;                      
};
union DSWAKECTL_REG {
				uint32_t				all;
				struct DSWAKECTL_BITS	bit;
};

struct DSWAKEEN_BITS {									// bit description
				uint32_t ERPIO0_0:1; //Enable pin PIO0_0 wake up function. 
				uint32_t ERPIO0_1:1; //Enable pin PIO0_1 wake up function.  
				uint32_t ERPIO0_2:1; //Enable pin PIO0_2 wake up function. 
				uint32_t ERPIO0_3:1; //Enable pin PIO0_3 wake up function. . 
				uint32_t ERPIO0_4:1; //Enable pin PIO0_4 wake up function.  
				uint32_t ERPIO0_5:1; //Enable pin PIO0_5 wake up function.  
				uint32_t ERPIO0_6:1; //Enable pin PIO0_6 wake up function.  
				uint32_t ERPIO0_7:1; //Enable pin PIO0_7 wake up function.  
				uint32_t ERPIO0_8:1; //Enable pin PIO0_8 wake up function.  
				uint32_t ERPIO0_9:1; //Enable pin PIO0_9 wake up function.  
				uint32_t ERPIO0_10:1; //Enable pin PIO0_10 wake up function.  
				uint32_t ERPIO0_11:1; //Enable pin PIO0_11 wake up function. 
				uint32_t RSVD:20;                      
};
union DSWAKEEN_REG {
				uint32_t				all;
				struct DSWAKEEN_BITS	bit;
};

struct DSWAKECLR_BITS {									// bit description
				uint32_t RSRPIO0_0:1; // 	Wake up signal reset for pin PIO0_0. 
				uint32_t RSRPIO0_1:1; // 	Wake up signal reset for pin PIO0_1. 
				uint32_t RSRPIO0_2:1; // 	Wake up signal reset for pin PIO0_2. 
				uint32_t RSRPIO0_3:1; // 	Wake up signal reset for pin PIO0_3. 
				uint32_t RSRPIO0_4:1; // 	Wake up signal reset for pin PIO0_4. 
				uint32_t RSRPIO0_5:1; // 	Wake up signal reset for pin PIO0_5. 
				uint32_t RSRPIO0_6:1; // 	Wake up signal reset for pin PIO0_6. 
				uint32_t RSRPIO0_7:1; // 	Wake up signal reset for pin PIO0_7. 
				uint32_t RSRPIO0_8:1; // 	Wake up signal reset for pin PIO0_8. 
				uint32_t RSRPIO0_9:1; // 	Wake up signal reset for pin PIO0_9. 
				uint32_t RSRPIO0_10:1; // 	Wake up signal reset for pin PIO0_10. 
				uint32_t RSRPIO0_11:1; // 	Wake up signal reset for pin PIO0_11. 
				uint32_t RSVD:20;                      
};
union DSWAKECLR_REG {
				uint32_t				all;
				struct DSWAKECLR_BITS	bit;
};

struct DSWAKE_BITS {									// bit description
				uint32_t SRPIO0_0:1; // 	Wake up signal status for pin PIO0_0. 
				uint32_t SRPIO0_1:1; // 	Wake up signal status for pin PIO0_1. 
				uint32_t SRPIO0_2:1; // 	Wake up signal status for pin PIO0_2. 
				uint32_t SRPIO0_3:1; // 	Wake up signal status for pin PIO0_3. 
				uint32_t SRPIO0_4:1; // 	Wake up signal status for pin PIO0_4. 
				uint32_t SRPIO0_5:1; // 	Wake up signal status for pin PIO0_5. 
				uint32_t SRPIO0_6:1; // 	Wake up signal status for pin PIO0_6. 
				uint32_t SRPIO0_7:1; // 	Wake up signal status for pin PIO0_7. 
				uint32_t SRPIO0_8:1; // 	Wake up signal status for pin PIO0_8. 
				uint32_t SRPIO0_9:1; // 	Wake up signal status for pin PIO0_9. 
				uint32_t SRPIO0_10:1; // 	Wake up signal status for pin PIO0_10. 
				uint32_t SRPIO0_11:1; // 	Wake up signal status for pin PIO0_11. 
				uint32_t RSVD:20;                      
};
union DSWAKE_REG {
				uint32_t				all;
				struct DSWAKE_BITS	bit;
};

struct INTNMI_BITS {									// bit description
				uint32_t NMISRC:6; //NMI interrupts source select.
				uint32_t RSVD:26;                      
};
union INTNMI_REG {
				uint32_t				all;
				struct INTNMI_BITS	bit;
};

struct PRESETCTRL_BITS {									// bit description
				uint32_t SPI_RST_N:1; //SPI reset control 
				uint32_t TWS_RST_N:1; //TWS reset control 
				uint32_t UART0_RST_N:1; //UART0 reset control 
				uint32_t UART1_RST_N:1; //UART1 reset control 
				uint32_t RSVD0:1;
				uint32_t CT16B0_RST_N:1; //16-bit basic counter/timer 0 (CT16B0) reset control 
				uint32_t CT16B1_RST_N:1; //16-bit basic counter/timer 1 (CT16B1) reset control 
				uint32_t CT16B2_RST_N:1; //16-bit counter/timer 0 (CT16B2) reset control 
				uint32_t CT16B3_RST_N:1; //16-bit counter/timer 1 (CT16B3) reset control 
				uint32_t PWM_RST_N:1; //16-bit PWM counter/timer 1 (PWMCT) reset control 
				uint32_t CRC_RST_N:1; //CRC reset control 
				uint32_t TOUCH_RST_N:1; //24-bit Cap Touch reset control 
				uint32_t ADC_RST_N:1; //ADC
				uint32_t LCD_RST_N:1; //LCD controller
				uint32_t RSVD1:18;                      
};
union PRESETCTRL_REG {
				uint32_t				all;
				struct PRESETCTRL_BITS	bit;
};

struct IOCON_BITS {									// bit description
				uint32_t FUNC:3; //Selects pin function. 
				uint32_t PDE:1; //Pull-down mode
				uint32_t PUE:1; //Pull-up mode
				uint32_t CSE:1; //Schmitt trigger enable. 
				uint32_t INV:1; //Invert input 
				uint32_t SRM:1; //Slew rate mode 
				uint32_t ADM:1; //Analog mode
				uint32_t DRV:1; //Drive current mode (Normal-drive pin). 
				uint32_t OD:1; //Open-drain mode. 
				uint32_t S_MODE:1; //Sample mode 
				uint32_t IEN:1; //Input disable
				uint32_t RSVD:19;                      
};
union IOCON_REG {
				uint32_t				all;
				struct IOCON_BITS	bit;
};

/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */


/**
  * @brief Power management unit (PMU)
  */

typedef struct {                                    /*!< PMU Structure                                                         */
  __IO union PCON_REG  PCON;                              /*!< Power control register                                                */
//   __I  uint32_t  RESERVED0[4];
//   __IO union RTCCFG_REG RTCCFG;                            /*!< RTC clock control register                                            */
} XN_PMU_TypeDef;

/* ================================================================================ */
/* ================                      IOCON                     ================ */
/* ================================================================================ */


/**
  * @brief IO config (IOCON)
  */

typedef struct {                                    /*!< IOCON Structure                                                       */
  __IO union  IOCON_REG  PIO2_13;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_14;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_15;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_7;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_8;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_9;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_0;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_1;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_2;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_3;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_4;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_5;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_6;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_7;                            /*!< Pin config register                                                   */
  __I  uint32_t    RESERVED0[8];
  __IO union  IOCON_REG  PIO1_0;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_1;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_2;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_10;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_11;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_12;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_13;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_14;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_15;                           /*!< Pin config register                                                   */
  __I  uint32_t    RESERVED1[4];
  __IO union  IOCON_REG  PIO0_8;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_9;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_10;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_11;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_12;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_13;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_10;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_11;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_14;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO0_15;                           /*!< Pin config register                                                   */
  __I  uint32_t  RESERVED2[4];
  __IO union  IOCON_REG  PIO1_3;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_4;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_5;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_6;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_7;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO2_12;                           /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_8;                            /*!< Pin config register                                                   */
  __IO union  IOCON_REG  PIO1_9;                            /*!< Pin config register                                                   */
} XN_IOCON_TypeDef;


/* ================================================================================ */
/* ================                     SYSCON                     ================ */
/* ================================================================================ */


/**
  * @brief System control register (SYSCON)
  */

typedef struct {                                    /*!< SYSCON Structure                                                      */
  __IO union  SYSMEMREMAP_REG SYSMEMREMAP;                       /*!< System memory remap register                                          */
  __IO union  PRESETCTRL_REG PRESETCTRL;                        /*!< Peripheral reset control register                                     */
  __I  uint32_t  RESERVED0[7];
  __IO union  WDTOSCCTRL_REG WDTOSCCTRL;                        /*!< WDT oscillator control register                                       */
  __IO union  IRCCTRL_REG IRCCTRL;                           /*!< Internal RC oscillator control register                               */
  __I  uint32_t  RESERVED1;
  __IO union  SYSRESSTAT_REG SYSRESSTAT;                        /*!< System reset status register                                          */
  __I  uint32_t RESERVED2[15];
  __IO union  MAINCLKSEL_REG MAINCLKSEL;                        /*!< Main clock source select register                                     */
  __IO union  MAINCLKUEN_REG MAINCLKUEN;                        /*!< Main clock source update enable register                              */
  __IO union  SYSAHBCLKDIV_REG SYSAHBCLKDIV;                      /*!< System AHB clock divider register                                     */
  __I  uint32_t  RESERVED3;
  __IO union  SYSAHBCLKCTRL_REG SYSAHBCLKCTRL;                     /*!< AHB clock control register                                            */
  __I  uint32_t RESERVED4[5];
  __IO union  UARTCLKDIV_REG UART0CLKDIV;                       /*!< UART0 clock divider register                                          */
  __IO union  UARTCLKDIV_REG UART1CLKDIV;                       /*!< UART1 clock divider register                                          */
  __I  uint32_t RESERVED5[16];
  __IO union  CLKOUTCLKSEL_REG CLKOUTCLKSEL;                      /*!< Clockout clock source select register                                 */
  __IO union  CLKOUTUEN_REG CLKOUTUEN;                         /*!< Clockout clock source update enable register                          */
  __IO union  CLKOUTDIV_REG CLKOUTDIV;                         /*!< Clockout clock divider register                                       */
  __I  uint32_t RESERVED6[24];
  __IO union  IOCONFIGCLKDIV_REG IOCONFIGCLKDIV;                   /*!< IO input filter0 register                                             */
  __IO union  BODCTRL_REG BODCTRL;                           /*!< BOD power down control register                                       */
  __I  uint32_t RESERVED7[8];
  __IO union  INTNMI_REG INTNMI;                            /*!< NMI interrupt source configuration control                            */
  __I  uint32_t  RESERVED8[34];
  __IO union  DSWAKECTL_REG DSWAKECTL;                         /*!< Deep sleep wake up control register                                   */
  __IO union  DSWAKEEN_REG DSWAKEEN;                          /*!< Deep sleep wake up signal enable control register                     */
  __O  union  DSWAKECLR_REG DSWAKECLR;                         /*!< Deep sleep wake up signal reset register                              */
  __I  union  DSWAKE_REG DSWAKE;                            /*!< Deep sleep wake up signal status register                             */
  __I  uint32_t  RESERVED9[8];
  __IO union  PDSLEEPCFG_REG PDSLEEPCFG;                        /*!< Power-down states in Deep-sleep mode                                  */
  __IO union  PDAWAKECFG_REG PDAWAKECFG;                        /*!< Power-down states after wake-up from Deep-sleep mode                  */
  __IO union  PDRUNCFG_REG PDRUNCFG;                          /*!< Power-down configuration register                                     */
} XN_SYSCON_TypeDef;

//Re_Define XN PMU, IOCON and SYSCON
#define XN_PMU						((XN_PMU_TypeDef   *) PMU_BASE )
#define XN_IOCON					((XN_IOCON_TypeDef   *) IOCON_BASE )
#define XN_SYSCON					((XN_SYSCON_TypeDef   *) SYSCON_BASE )

#define IRC_CLK 			0x0
#define MAIN_CLK 			0x1
#define SYS_CLK 			0x2
#define WDT_CLK 			0x3
#define RTC_CLK 			0x4


#define AHB_TWS 		0x20
#define AHB_CRC 		0x40
#define AHB_CT16B0 	0x80 
#define AHB_CT16B1 	0x100 
#define AHB_CT16B2 	0x200 
#define AHB_CT16B3 	0x400
#define AHB_SPI 		0x800
#define AHB_UART0 	0x1000 
#define AHB_UART1 	0x2000
#define AHB_ADC 		0x4000
#define AHB_WDT 		0x8000
#define AHB_IOCON 	0x10000
#define AHB_PWM 		0x20000
#define AHB_LCD 		0x40000
#define AHB_RTC 		0x80000
#define AHB_TOUCH 	0x100000

#define PD_IRC 		0x02
#define PD_BOD 		0x08
#define PD_ADC 		0x10
#define PD_RTCOSC 0x20
#define PD_WDTOSC 0x40
#define PD_LCD		0x80
#define PD_TOUCH 	0x100

#define RST_SPI 		0x1
#define RST_TWS 		0x2
#define RST_UART0 	0x4 
#define RST_UART1 	0x8
#define RST_CT16B0 	0x20 
#define RST_CT16B1 	0x40 
#define RST_CT16B2 	0x80 
#define RST_CT16B3 	0x100
#define RST_PWM 		0x200
#define RST_CRC 		0x400
#define RST_TOUCH 	0x800
#define RST_ADC 		0x1000
#define RST_LCD 		0x2000

#define BOD_INT 		0
#define BOD_RESET 	1

#define IO_PIN0 		0x00000001
#define IO_PIN1 		0x00000002
#define IO_PIN2 		0x00000004
#define IO_PIN3 		0x00000008
#define IO_PIN4 		0x00000010
#define IO_PIN5 		0x00000020
#define IO_PIN6 		0x00000040
#define IO_PIN7 		0x00000080
#define IO_PIN8  		0x00000100
#define IO_PIN9  		0x00000200
#define IO_PIN10 		0x00000400
#define IO_PIN11 		0x00000800
#define IO_PIN12 		0x00001000
#define IO_PIN13 		0x00002000
#define IO_PIN14 		0x00004000
#define IO_PIN15 		0x00008000

#define FALL_EDGE 	0
#define RISE_EDGE 	1
#define BOTH_EDGE 	2

#define SYS_MemRemaptoBSL (XN_SYSCON->SYSMEMREMAP.bit.MAP=0)
#define SYS_MemRemaptoSRAM (XN_SYSCON->SYSMEMREMAP.bit.MAP=1)
#define SYS_MemRemaptoFlash (XN_SYSCON->SYSMEMREMAP.bit.MAP=2)

void SYS_SystemInitial(void);
void SYS_SelectMainClkSrc(uint8_t src);
void SYS_SetAHBClkDivider (uint8_t div);
void SYS_SelectWDTClkSrc(uint8_t src);
void SYS_SelectClkOutSrc(uint8_t src);
void SYS_SetClkOutDivider(uint8_t div);
void SYS_EnableClkOut(void);
void SYS_DisableClkOut(void);
void SYS_SetIOFilter(uint8_t ticks);
void SYS_PowerUpAngIP(uint32_t angips);
void SYS_PowerDownAngIP(uint32_t angips);
void SYS_EnablePhrClk(uint32_t phrs);
void SYS_DisablePhrClk(uint32_t phrs);
void SYS_ResetPhr(uint32_t phrs);
void SYS_ResetSystem(void);
void SYS_BODConfigure(uint8_t bodsel);
uint32_t SYS_GetResetStatus(void);
void SYS_ClearResetStatus (void);
void SYS_EnterSleep (void);
void SYS_SetDeepSleepWakeupPin (uint16_t selio, uint16_t edge);
void SYS_ResetDeepSleepWakeupPin(void);
void SYS_EnterDeepSleep (uint32_t deepsleepconfig, uint32_t wakeupconfig);
void SYS_EnterPowerDown (uint32_t powerdownconfig);
void SYS_IOConfig(volatile union IOCON_REG *pio, uint32_t config);
void SYS_IOSetPullup(volatile union IOCON_REG *pio);
void SYS_IOSetPulldown (volatile union IOCON_REG *pio);
void SYS_IOSwitchtoAng (volatile union IOCON_REG *pio);
void SYS_IOSwitchtoDigit (volatile union IOCON_REG *pio);
void SYS_IOEnableFilter (volatile union IOCON_REG *pio);
void SYS_IODisableFilter (volatile union IOCON_REG *pio);


#endif /* end __SYS__H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
