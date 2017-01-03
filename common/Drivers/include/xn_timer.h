/*****************************************************************************
 *   xn_timer.h:  Header file for Xinnova XN11 Family Microprocessors
 *
 *   Copyright(C) 2011, Xinnova tech. Ltd.
 *   All rights reserved.
 *
 *   History
 *   2015  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __TIMER_H 
#define __TIMER_H
#include "XN11Exxx.h"

//--TIMER Registers BITS Field---------------------------------------------------------------------------------------
struct CT16B0_IR_BITS {									// bit description
				uint32_t MR0INT:1;	//Interrupt flag for match channel 0.
				uint32_t RSVD:31;                      // 31:4 reserved
};

union CT16B0_IR_REG {
				uint32_t				all;
				struct CT16B0_IR_BITS	bit;
};
struct CT16B2_IR_BITS {									// bit description
				uint32_t MR0INT:1;	//Interrupt flag for match channel 0.
				uint32_t MR1INT:1;	//Interrupt flag for match channel 1. 
				uint32_t MR2INT:1;	//Interrupt flag for match channel 2
				uint32_t MR3INT:1;	//Interrupt flag for match channel 3. 
				uint32_t CR0INT:1;	//Interrupt flag for capture channel 0 event. 
				uint32_t CR1INT:1;	//Interrupt flag for capture channel 1 event. 
				uint32_t CR2INT:1;	//Interrupt flag for capture channel 2 event. 
				uint32_t CR3INT:1;	//Interrupt flag for capture channel 3 event. 
				uint32_t RSVD:24;                      // 31:4 reserved
};

union CT16B2_IR_REG {
				uint32_t				all;
				struct CT16B2_IR_BITS	bit;
};
struct CT16B0_TCR_BITS {									// bit description
				uint32_t CEN:1;	//Counter enable. 
				uint32_t CRST:1;	//Counter reset. 
				uint32_t RSVD:30;                      // 31:30 reserved
};
union CT16B0_TCR_REG {
				uint32_t				all;
				struct CT16B0_TCR_BITS	bit;
};
struct CT16B0_TC_BITS {									// bit description
				uint32_t TC:16;	//Timer counter value. 
				uint32_t RSVD:16;                      // 31:16 reserved
};
union CT16B0_TC_REG {
				uint32_t				all;
				struct CT16B0_TC_BITS	bit;
};
struct CT16B0_PR_BITS {									// bit description
				uint32_t PCVAL:16; 	//Prescale value.  
				uint32_t RSVD:16;                      // 31:16 reserved
};
union CT16B0_PR_REG {
				uint32_t				all;
				struct CT16B0_PR_BITS	bit;
};
struct CT16B0_PC_BITS {									// bit description
				uint32_t PC:16; 	//Prescale counter value.  
				uint32_t RSVD:16;                      // 31:16 reserved
};
union CT16B0_PC_REG {
				uint32_t				all;
				struct CT16B0_PC_BITS	bit;
};
struct CT16B0_MCR_BITS {									// bit description
				uint32_t MR0I:1; 	//Interrupt on MR0: an interrupt is generated when MR0 matches the value in the TC. 
				uint32_t MR0R:1; 	//Reset on MR0: the TC will be reset if MR0 matches it. 
				uint32_t MR0S:1; 	//Stop on MR0: the TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC. 
				uint32_t MR1I:1; 	//Interrupt on MR1: an interrupt is generated when MR1 matches the value in the TC. 
				uint32_t MR1R:1; 	//Reset on MR1: the TC will be reset if MR1 matches it. 
				uint32_t MR1S:1; 	//Stop on MR1: the TC and PC will be stopped and TCR[0] will be set to 0 if MR1 matches the TC. 
				uint32_t MR2I:1; 	//Interrupt on MR2: an interrupt is generated when MR2 matches the value in the TC. 
				uint32_t MR2R:1; 	//Reset on MR2: the TC will be reset if MR2 matches it. 
				uint32_t MR2S:1; 	//Stop on MR2: the TC and PC will be stopped and TCR[0] will be set to 0 if MR2 matches the TC. 
				uint32_t MR3I:1; 	//Interrupt on MR3: an interrupt is generated when MR3 matches the value in the TC. 
				uint32_t MR3R:1; 	//Reset on MR3: the TC will be reset if MR3 matches it. 
				uint32_t MR3S:1; 	//Stop on MR3: the TC and PC will be stopped and TCR[0] will be set to 0 if MR3 matches the TC. 
				uint32_t RSVD:20;                      // 31:12 reserved
};
union CT16B0_MCR_REG {
				uint32_t				all;
				struct CT16B0_MCR_BITS	bit;
};
struct CT16B0_MR_BITS {									// bit description
				uint32_t MATCH:16; 	//Timer counter match value. 				
				uint32_t RSVD:16;                      // 31:16 reserved
};
union CT16B0_MR_REG {
				uint32_t				all;
				struct CT16B0_MR_BITS	bit;
};
struct CT16B2_CCR_BITS {									// bit description
				uint32_t CAP0RE:1; 	//Capture on CT16Bn_CAP0 rising edge: a sequence of 0 then 1 on CT16Bn_CAP0 will cause CR0 to be loaded with the contents of TC. 
				uint32_t CAP0FE:1; 	//Capture on CT16Bn_CAP0 falling edge: a sequence of 1 then 0 on CT16Bn_CAP0 will cause CR0 to be loaded with the contents of TC. 
				uint32_t CAP0I:1; 	//Interrupt on CT16Bn_CAP0 event: a CR0 load due to a CT16Bn_CAP0 event will generate an interrupt. 
				uint32_t CAP1RE:1; 	//Capture on CT16Bn_CAP1 rising edge: a sequence of 0 then 1 on CT16Bn_CAP1 will cause CR1 to be loaded with the contents of TC. 
				uint32_t CAP1FE:1; 	//Capture on CT16Bn_CAP1 falling edge: a sequence of 1 then 0 on CT16Bn_CAP1 will cause CR1 to be loaded with the contents of TC. 
				uint32_t CAP1I:1; 	//Interrupt on CT16Bn_CAP1 event: a CR1 load due to a CT16Bn_CAP1 event will generate an interrupt. 
				uint32_t CAP2RE:1; 	//Capture on comparator n level output - rising edge: a sequence of 0 then 1 on the comparator n output will cause CR2 to be loaded with the contents of TC. 
				uint32_t CAP2FE:1; 	//Capture on comparator n level output - falling edge: a sequence of 1 then 0 on comparator n output will cause CR2 to be loaded with the contents of TC. 
				uint32_t CAP2I:1; 	//Interrupt on comparator n level output event: a CR2 load due to a comparator 0 event will generate an interrupt. 
				uint32_t CAP3RE:1; 	//Capture on comparator n edge output - rising edge: a sequence of 0 then 1 on the comparator n output will cause CR3 to be loaded with the contents of TC. 
				uint32_t CAP3FE:1; 	//Capture on comparator n edge output - falling edge: a sequence of 1 then 0 on comparator n output will cause CR3 to be loaded with the contents of TC. 
				uint32_t CAP3I:1; 	//Interrupt on comparator n edge output event: a CR3 load due to a comparator n event will generate an interrupt. 
				uint32_t RSVD:20;                      // 31:20 reserved
};
union CT16B2_CCR_REG {
				uint32_t				all;
				struct CT16B2_CCR_BITS	bit;
};
struct CT16B2_CR_BITS {									// bit description
				uint32_t CAP:16; 	//Timer counter capture value. 
				uint32_t RSVD:16;                      // 31:16 reserved
};
union CT16B2_CR_REG {
				uint32_t				all;
				struct CT16B2_CR_BITS	bit;
};
struct CT16B2_EMR_BITS {									// bit description
				uint32_t EM0:1; 	//External match 0. 
				uint32_t EM1:1; 	//External match 1. 
				uint32_t EM2:1; 	//External match 2.
				uint32_t EM3:1; 	//External match 3. 
				uint32_t EMC0:2; 	//External match Control 0. 
				uint32_t EMC1:2; 	//External match Control 1. 
				uint32_t EMC2:2; 	//External match control 2. 
				uint32_t EMC3:2; 	//External match control 3. 
				uint32_t RSVD:20;                      // 31:20 reserved
};
union CT16B2_EMR_REG {
				uint32_t				all;
				struct CT16B2_EMR_BITS	bit;
};
struct CT16B2_CTCR_BITS {									// bit description
				uint32_t CTM:3; 	//Counter/Timer Mode. 
				uint32_t ENCC:1; 	//Setting this bit to 1 enables clearing of the timer and the prescaler when the capture-edge event specified in bits 7:4 occurs. 
				uint32_t SELCC:4; 	//When bit 3 is a 1, these bits select which capture input edge will cause the timer and prescaler to be cleared. These bits have no effect when bit 3 is low. 
				uint32_t PRISEL:4; 	//Primary clock source select.
				uint32_t SECSEL:4; 	//Secondary clock source select.
				uint32_t IPS:1; 	//Secondary source input polarity select.
				uint32_t RSVD:15;                      // 31:17 reserved
};
union CT16B2_CTCR_REG {
				uint32_t				all;
				struct CT16B2_CTCR_BITS	bit;
};
struct CT16B2_PWMC_BITS {									// bit description
				uint32_t PWMEN0:1; 	//Enable MAT0 PWM output mode 
				uint32_t PWMEN1:1; 	//Enable MAT1 PWM output mode  
				uint32_t PWMEN2:1; 	//Enable MAT2 PWM output mode  
				uint32_t RSVD:29;                      // 31:17 reserved
};
union CT16B2_PWMC_REG {
				uint32_t				all;
				struct CT16B2_PWMC_BITS	bit;
};
/* ================================================================================ */
/* ================                     CT16B0                     ================ */
/* ================================================================================ */


/**
  * @brief 16 bits timer (CT16B0)
  */

typedef struct {                                    /*!< CT16B0 Structure                                                      */
  __IO union CT16B0_IR_REG  IR;                                /*!< Interrupt register                                                    */
  __IO union CT16B0_TCR_REG  TCR;                               /*!< Timer control register                                                */
  __IO union CT16B0_TC_REG  TC;                                /*!< Timer counter register                                                */
  __IO union CT16B0_PR_REG  PR;                                /*!< Prescale register                                                     */
  __IO union CT16B0_PC_REG  PC;                                /*!< Prescale Counter register                                             */
  __IO union CT16B0_MCR_REG  MCR;                               /*!< Match Control Register                                                */
  __IO union CT16B0_MR_REG  MR0;                               /*!< Match register0                                                       */                                           
} XN_CT16B0_TypeDef;
/* ================================================================================ */
/* ================                     CT16B2                     ================ */
/* ================================================================================ */


/**
  * @brief 16 bits timer (CT16B2)
  */

typedef struct {                                    /*!< CT16B2 Structure                                                      */
  __IO union CT16B2_IR_REG  IR;                                /*!< Interrupt register                                                    */
  __IO union CT16B0_TCR_REG  TCR;                               /*!< Timer control register                                                */
  __IO union CT16B0_TC_REG  TC;                                /*!< Timer counter register                                                */
  __IO union CT16B0_PR_REG  PR;                                /*!< Prescale register                                                     */
  __IO union CT16B0_PC_REG  PC;                                /*!< Prescale Counter register                                             */
  __IO union CT16B0_MCR_REG  MCR;                               /*!< Match Control Register                                                */
  __IO union CT16B0_MR_REG  MR0;                               /*!< Match register0                                                       */
  __IO union CT16B0_MR_REG  MR1;                               /*!< Match register1                                                       */
  __IO union CT16B0_MR_REG  MR2;                               /*!< Match register2                                                       */
  __IO union CT16B0_MR_REG  MR3;                               /*!< Match register3                                                       */
  __IO union CT16B2_CCR_REG  CCR;                               /*!< Capture Control Register                                              */
  __I  union CT16B2_CR_REG  CR0;                               /*!< Capture register0                                                     */
  __I  union CT16B2_CR_REG  CR1;                               /*!< Capture register1                                                     */
  __I  union CT16B2_CR_REG  CR2;                               /*!< Capture register2                                                     */
  __I  union CT16B2_CR_REG  CR3;                               /*!< Capture register3                                                     */
  __IO union CT16B2_EMR_REG  EMR;                               /*!< External match register                                               */
  __I  uint32_t  RESERVED0[12];
  __IO union CT16B2_CTCR_REG  CTCR;                              /*!< Counter control register                                              */
  __IO union CT16B2_PWMC_REG  PWMC;                              /*!< PWM output register                                              */
} XN_CT16B2_TypeDef;
#define XN_CT16B0                          ((XN_CT16B0_TypeDef             *) CT16B0_BASE)
#define XN_CT16B1                          ((XN_CT16B0_TypeDef             *) CT16B1_BASE)
#define XN_CT16B2                          ((XN_CT16B2_TypeDef             *) CT16B2_BASE)
#define XN_CT16B3                          ((XN_CT16B2_TypeDef             *) CT16B3_BASE)

//Int Status
#define CT_MATCH_0_INT 0x1
#define CT_MATCH_1_INT 0x2
#define CT_MATCH_2_INT 0x4
#define CT_MATCH_3_INT 0x8
#define CT_CAPTURE_0_INT 0x10
#define CT_CAPTURE_1_INT 0x20
#define CT_CAPTURE_2_INT 0x40
#define CT_CAPTURE_3_INT	 0x80

//Capture control
#define CT_CAPTURE_DO_NOTHING 0x0
#define CT_CAPTURE_RISE_EDGE 0x1
#define CT_CAPTURE_FALL_EDGE 0x2
#define CT_CAPTURE_TRIGGER_INT	 0x4

//Match Control
#define CT_MATCH_TRIGGER_INT 0x1
#define CT_MATCH_RESET_COUNTER 0x2
#define CT_MATCH_STOP_COUNTER 0x4
#define CT_MATCH_DO_NOTHING 0x0

//Match Output Control
#define CT_MATCH_OUT_DO_NOTHING 0x0
#define CT_MATCH_OUT_RESET 0x1
#define CT_MATCH_OUT_SET	 0x2
#define CT_MATCH_OUT_TRIGGER_PLUS	 0x3
//Match PWM Output Channel
#define CT_PWM0_ON_MAT0 0x1
#define CT_PWM1_ON_MAT1 0x2
#define CT_PWM2_ON_MAT2 0x4
//Macros
#define CT16B0_START  (XN_CT16B0->TCR.bit.CEN = 1)
#define CT16B1_START  (XN_CT16B1->TCR.bit.CEN = 1)
#define CT16B0_STOP  (XN_CT16B0->TCR.bit.CEN = 0)
#define CT16B1_STOP  (XN_CT16B1->TCR.bit.CEN = 0)
#define CT16B0_RESET_COUNTER  (XN_CT16B0->TCR.bit.CRST = 1)
#define CT16B1_RESET_COUNTER  (XN_CT16B1->TCR.bit.CRST = 1)

#define CT16B2_START  (XN_CT16B2->TCR.bit.CEN = 1)
#define CT16B3_START  (XN_CT16B3->TCR.bit.CEN = 1)
#define CT16B2_STOP  (XN_CT16B2->TCR.bit.CEN = 0)
#define CT16B3_STOP  (XN_CT16B3->TCR.bit.CEN = 0)
#define CT16B2_RESET_COUNTER  (XN_CT16B2->TCR.bit.CRST = 1)
#define CT16B3_RESET_COUNTER  (XN_CT16B3->TCR.bit.CRST = 1)


void CT16B0_Init(XN_CT16B0_TypeDef *ct, uint32_t tickpersecond);
void CT16B0_ConfigMatch(XN_CT16B0_TypeDef *ct, uint16_t ticks, uint8_t action);
void CT16B0_SetTimerCounter(XN_CT16B0_TypeDef *ct, uint16_t tick);
void CT16B0_ResetTimerCounter(XN_CT16B0_TypeDef *ct);
uint16_t CT16B0_GetTimerCounter(XN_CT16B0_TypeDef *ct);
void CT16B0_ClearIntFlag(XN_CT16B0_TypeDef *ct);
void CT16B0_EnableInt(XN_CT16B0_TypeDef *ct);
void CT16B0_DisableInt(XN_CT16B0_TypeDef *ct);

void CT16B2_Init(XN_CT16B2_TypeDef *ct, uint32_t tickpersecond);
void CT16B2_SetCTType(XN_CT16B2_TypeDef *ct, uint8_t mode);
void CT16B2_SelectTimerClearSignal(XN_CT16B2_TypeDef *ct, uint8_t capsignal, uint8_t edge);
void CT16B2_SelectPriSrc(XN_CT16B2_TypeDef *ct, uint8_t clksrc);
void CT16B2_SelectSecSrc (XN_CT16B2_TypeDef *ct, uint8_t clksrc, uint8_t polarity);
void CT16B2_ConfigMatch0(XN_CT16B2_TypeDef *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void CT16B2_ConfigMatch1(XN_CT16B2_TypeDef *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void CT16B2_ConfigMatch2(XN_CT16B2_TypeDef *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void CT16B2_ConfigMatch3(XN_CT16B2_TypeDef *ct, uint16_t ticks, uint8_t internalaction, uint8_t externalaction);
void CT16B2_ConfigCapture0(XN_CT16B2_TypeDef *ct, uint8_t edge, uint8_t intreq);
void CT16B2_ConfigCapture1(XN_CT16B2_TypeDef *ct, uint8_t edge, uint8_t intreq);
void CT16B2_ConfigCapture2(XN_CT16B2_TypeDef *ct, uint8_t edge, uint8_t intreq);
void CT16B2_ConfigCapture3(XN_CT16B2_TypeDef *ct, uint8_t edge, uint8_t intreq);
uint16_t CT16B2_GetCapture0Value (XN_CT16B2_TypeDef *ct);
uint16_t CT16B2_GetCapture1Value (XN_CT16B2_TypeDef *ct);
uint16_t CT16B2_GetCapture2Value (XN_CT16B2_TypeDef *ct);
uint16_t CT16B2_GetCapture3Value (XN_CT16B2_TypeDef *ct);
void CT16B2_SetTimerCounter(XN_CT16B2_TypeDef *ct, uint16_t ticks);
void CT16B2_ResetTimerCounter(XN_CT16B2_TypeDef *ct);
uint16_t CT16B2_GetTimerCounter (XN_CT16B2_TypeDef *ct);
void CT16B2_ClearIntFlag(XN_CT16B2_TypeDef *ct);
void CT16B2_EnableInt(XN_CT16B2_TypeDef *ct, uint8_t intbit);
void CT16B2_DisableInt(XN_CT16B2_TypeDef *ct, uint8_t intbit);
uint8_t CT16B2_GetIntStatus(XN_CT16B2_TypeDef *ct);
void CT16B2_CTPWMInit(XN_CT16B2_TypeDef *ct, uint32_t pwmfreqinhz);
void CT16B2_EnableCTPWMOutput(XN_CT16B2_TypeDef *ct, uint8_t pwmchannels);
void CT16B2_DisableCTPWM(XN_CT16B2_TypeDef *ct, uint8_t pwmchannels);
void CT16B2_SetCTPWM0Duty(XN_CT16B2_TypeDef *ct, uint8_t duty);
void CT16B2_SetCTPWM1Duty(XN_CT16B2_TypeDef *ct, uint8_t duty);
void CT16B2_SetCTPWM2Duty(XN_CT16B2_TypeDef *ct, uint8_t duty);
#endif /* end __TIMER_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
