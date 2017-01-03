/*****************************************************************************
 *   xn_touch.h:  Header file for Xinnova XN11
 *
 *   Copyright(C) 20012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2015.01.21  ver 1.0    Prelimnary version
 *
******************************************************************************/

#ifndef __TOUCH_H 
#define __TOUCH_H
#include "XN11Exxx.h"

//--CAP TOUCH Registers BITS Field---------------------------------------------------------------------------------------
struct CAPTOUCH_INTSTAT_BITS {									// bit description
				uint32_t WATSTAT:1;		//Interrupt state flag trigger by water mark
				uint32_t SCANSTAT:1;		//Scan interrupt state flag 
				uint32_t RSVD:30;                      // 31:2 reserved
};

union CAPTOUCH_INTSTAT_REG {
				uint32_t				all;
				struct CAPTOUCH_INTSTAT_BITS	bit;
};
struct CAPTOUCH_CTRL_BITS {									// bit description
				uint32_t CAPTEN:1;		//Cap Touch enable
				uint32_t INTEN:1;		//Touch pad interrupt enable
				uint32_t INTERNALRSET:2;		//Internal resister select
				uint32_t EXTRSEL:1;		//Select internal resister or external resister
				uint32_t OSCEN:1;		//Enable oscillator
				uint32_t SCANINTEN:1;		//Enable interrupt at every time a pad scanned
				uint32_t RSVD0:1;                      // 7 reserved
				uint32_t CHNEN:22;		//Touch pad channel enable. 
				uint32_t RSVD1:2;                      // 30:31 reserved
};
union CAPTOUCH_CTRL_REG {
				uint32_t				all;
				struct CAPTOUCH_CTRL_BITS	bit;
};

union CAPTOUCH_SENSTM_REG {
				uint32_t				all;
};
struct CAPTOUCH_RAWSTAT_MODE_BITS {									// bit description
				uint32_t RAWWATSTAT:1;		//Interrupt raw state flag trigger by water mark
				uint32_t RAWSCANSTAT:1;		//Scan interrupt raw state flag 
				uint32_t RSVD:30;                      // 31:2 reserved
};
union CAPTOUCH_RAWSTAT_REG {
				uint32_t				all;
				struct CAPTOUCH_RAWSTAT_MODE_BITS	bit;
};
union CAPTOUCH_WATMK_REG {
				uint32_t				all;
};
struct CAPTOUCH_TOUCHCHN_BITS {									// bit description
				uint32_t CHN:5;		//Touched pad channel number. 
				uint32_t RSVD:27;                      // 31:5 reserved
};
union CAPTOUCH_TOUCHCHN_REG {
				uint32_t				all;
				struct CAPTOUCH_TOUCHCHN_BITS	bit;
};
union CAPTOUCH_TOUCHCNT_REG {
				uint32_t				all;
};
struct CAPTOUCH_SCANCHN_BITS {									// bit description
				uint32_t CHN:5;		//Last scanned pad channel number. 
				uint32_t RSVD:27;                      // 31:5 reserved
};
union CAPTOUCH_SCANCHN_REG {
				uint32_t				all;
				struct CAPTOUCH_SCANCHN_BITS	bit;
};
union CAPTOUCH_SCANCNT_REG {
				uint32_t				all;
};



typedef struct {                                    						/*!< TWS Structure                                                         */
  __IO union CAPTOUCH_INTSTAT_REG  INTSTAT;                            /*!< TWS control set bit register                                          */
	__IO  union CAPTOUCH_CTRL_REG  CTRL;                             		/*!< TWS state register                                                    */
  __IO union CAPTOUCH_SENSTM_REG  SENSTM;                               /*!< TWS data register                                                     */
  __IO union CAPTOUCH_RAWSTAT_REG  RAWSTAT;                              /*!< TWS Slave Address Register 0                                          */
  __IO union CAPTOUCH_WATMK_REG  WATMK;                              /*!< Duty Cycle Register High Half Word                                    */
   __I  uint32_t  RESERVED0[1];                         							/*!< Duty Cycle Register Low Half Word                                     */
  __O  union CAPTOUCH_TOUCHCHN_REG  TOUCHCHN;                            /*!< TWS Control Clear Register                                            *///

	__O union CAPTOUCH_TOUCHCNT_REG  TOUCHCNT;												/*!< TWS Slave Address Register 1                                          *///
  __IO union CAPTOUCH_SCANCHN_REG  SCANCHN;                              /*!< TWS Slave Address Register 1                                          */
  __IO union CAPTOUCH_SCANCNT_REG  SCANCNT;                              /*!< TWS slave address register2                                           */ 
} XN_CAPTOUCH_TypeDef;

#define XN_CAPTOUCH                             ((XN_CAPTOUCH_TypeDef                *) CAPTOUCH_BASE)

//Touch pin
#define TOUCH0  0x1
#define TOUCH1  0x2
#define TOUCH2  0x4
#define TOUCH3  0x8
#define TOUCH4  0x10
#define TOUCH5  0x20
#define TOUCH6  0x40
#define TOUCH7  0x80
#define TOUCH8  0x100
#define TOUCH9  0x200
#define TOUCH10 0x400
#define TOUCH11 0x800
#define TOUCH12 0x1000
#define TOUCH13 0x2000
#define TOUCH14 0x4000
#define TOUCH15 0x8000
#define TOUCH16 0x10000
#define TOUCH17 0x20000
#define TOUCH18 0x40000
#define TOUCH19 0x80000
#define TOUCH20 0x100000
#define TOUCH21 0x200000

#define CAPTOUCH_SENSE_CLK_5000 0
#define CAPTOUCH_SENSE_CLK_2000	1
#define CAPTOUCH_SENSE_CLK_800	2
#define CAPTOUCH_SENSE_CLK_500	3
#define CAPTOUCH_SENSE_CLK_EXT	4

void CAPTOUCH_Init(void);
void CAPTOUCH_Deinit(void);
void CAPTOUCH_SelSenseClk (uint8_t clkfreq);
void CAPTOUCH_EnableTouchCHN(uint32_t channels);
void CAPTOUCH_SetScanTime(uint32_t minisec);
void CAPTOUCH_SetWaterMark(uint32_t level);
void CAPTOUCH_EnableScanInt(void);
void CAPTOUCH_DisableScanInt(void);
void CAPTOUCH_GetScanVal(uint8_t *channel, uint32_t *val);
void CAPTOUCH_GetTouchedVal (uint8_t *channel, uint32_t *val);
void CAPTOUCH_ClearIntFlag (void);

#endif /* end __TOUCH_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
