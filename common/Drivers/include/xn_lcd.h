/*****************************************************************************
 *   XN_LCD:  Head file for Xinnova MCU LCD(LCD compatible) application
 *
 *   Copyright(C) 2012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2015.08.14  ver 1.00
 *
******************************************************************************/
#ifndef __LCD_H
#define __LCD_H


#include "XN11Exxx.h"
#pragma anon_unions
//--LCD Registers BITS Field---------------------------------------------------------------------------------------
struct LCD_LCDCTRL0_BITS	{
			uint32_t LCDEN:1;	//Enable LCD driver
			uint32_t LEDEN:1;	//Enable LED driver
			uint32_t LEDINV:1;//LED com output positive/negative selection
			uint32_t RSVD:29;	//Reseved 31:3
};
union LCD_LCDCTRL0_REG {
				uint32_t				all;
				struct  LCD_LCDCTRL0_BITS		bit;
};	


struct LCD_LCDCTRL1_BITS	{
			uint32_t DUTY:4;	//
			uint32_t BIAS:1;	//
			uint32_t RSVD0:2;	//
			uint32_t FREQDIV:21;	//
			uint32_t RSVD1:4;	//
};
union LCD_LCDCTRL1_REG {
				uint32_t				all;
				struct  LCD_LCDCTRL1_BITS		bit;
};


struct LCD_MEMMAP0_BITS	{
			uint32_t Seg0Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg0Com1:1;	//Reseved 31:8
			uint32_t Seg0Com2:1;
			uint32_t Seg0Com3:1;
			uint32_t Seg0Com4:1;
			uint32_t Seg0Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg1Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg1Com1:1;	//Reseved 31:8
			uint32_t Seg1Com2:1;
			uint32_t Seg1Com3:1;
			uint32_t Seg1Com4:1;
			uint32_t Seg1Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg2Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg2Com1:1;	//Reseved 31:8
			uint32_t Seg2Com2:1;
			uint32_t Seg2Com3:1;
			uint32_t Seg2Com4:1;
			uint32_t Seg2Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg3Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg3Com1:1;	//Reseved 31:8
			uint32_t Seg3Com2:1;
			uint32_t Seg3Com3:1;
			uint32_t Seg3Com4:1;
			uint32_t Seg3Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP0_REG {
				uint32_t				all;
				struct  LCD_MEMMAP0_BITS	bit;
};

struct LCD_MEMMAP1_BITS	{
			uint32_t Seg4Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg4Com1:1;	//Reseved 31:8
			uint32_t Seg4Com2:1;
			uint32_t Seg4Com3:1;
			uint32_t Seg4Com4:1;
			uint32_t Seg4Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg5Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg5Com1:1;	//Reseved 31:8
			uint32_t Seg5Com2:1;
			uint32_t Seg5Com3:1;
			uint32_t Seg5Com4:1;
			uint32_t Seg5Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg6Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg6Com1:1;	//Reseved 31:8
			uint32_t Seg6Com2:1;
			uint32_t Seg6Com3:1;
			uint32_t Seg6Com4:1;
			uint32_t Seg6Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg7Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg7Com1:1;	//Reseved 31:8
			uint32_t Seg7Com2:1;
			uint32_t Seg7Com3:1;
			uint32_t Seg7Com4:1;
			uint32_t Seg7Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP1_REG {
				uint32_t				all;
				struct  LCD_MEMMAP1_BITS	bit;
};

struct LCD_MEMMAP2_BITS	{
			uint32_t Seg8Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg8Com1:1;	//Reseved 31:8
			uint32_t Seg8Com2:1;
			uint32_t Seg8Com3:1;
			uint32_t Seg8Com4:1;
			uint32_t Seg8Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg9Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg9Com1:1;	//Reseved 31:8
			uint32_t Seg9Com2:1;
			uint32_t Seg9Com3:1;
			uint32_t Seg9Com4:1;
			uint32_t Seg9Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg10Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg10Com1:1;	//Reseved 31:8
			uint32_t Seg10Com2:1;
			uint32_t Seg10Com3:1;
			uint32_t Seg10Com4:1;
			uint32_t Seg10Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg11Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg11Com1:1;	//Reseved 31:8
			uint32_t Seg11Com2:1;
			uint32_t Seg11Com3:1;
			uint32_t Seg11Com4:1;
			uint32_t Seg11Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP2_REG {
				uint32_t				all;
				struct  LCD_MEMMAP2_BITS	bit;
};


struct LCD_MEMMAP3_BITS	{
			uint32_t Seg12Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg12Com1:1;	//Reseved 31:8
			uint32_t Seg12Com2:1;
			uint32_t Seg12Com3:1;
			uint32_t Seg12Com4:1;
			uint32_t Seg12Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg13Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg13Com1:1;	//Reseved 31:8
			uint32_t Seg13Com2:1;
			uint32_t Seg13Com3:1;
			uint32_t Seg13Com4:1;
			uint32_t Seg13Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg14Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg14Com1:1;	//Reseved 31:8
			uint32_t Seg14Com2:1;
			uint32_t Seg14Com3:1;
			uint32_t Seg14Com4:1;
			uint32_t Seg14Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg15Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg15Com1:1;	//Reseved 31:8
			uint32_t Seg15Com2:1;
			uint32_t Seg15Com3:1;
			uint32_t Seg15Com4:1;
			uint32_t Seg15Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP3_REG {
				uint32_t				all;
				struct  LCD_MEMMAP3_BITS	bit;
};

struct LCD_MEMMAP4_BITS	{
			uint32_t Seg10Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg10Com1:1;	//Reseved 31:8
			uint32_t Seg10Com2:1;
			uint32_t Seg10Com3:1;
			uint32_t Seg10Com4:1;
			uint32_t Seg10Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg11Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg11Com1:1;	//Reseved 31:8
			uint32_t Seg11Com2:1;
			uint32_t Seg11Com3:1;
			uint32_t Seg11Com4:1;
			uint32_t Seg11Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg12Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg12Com1:1;	//Reseved 31:8
			uint32_t Seg12Com2:1;
			uint32_t Seg12Com3:1;
			uint32_t Seg12Com4:1;
			uint32_t Seg12Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg13Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg13Com1:1;	//Reseved 31:8
			uint32_t Seg13Com2:1;
			uint32_t Seg13Com3:1;
			uint32_t Seg13Com4:1;
			uint32_t Seg13Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP4_REG {
				uint32_t				all;
				struct  LCD_MEMMAP4_BITS	bit;
};

struct LCD_MEMMAP5_BITS	{
			uint32_t Seg10Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg10Com1:1;	//Reseved 31:8
			uint32_t Seg10Com2:1;
			uint32_t Seg10Com3:1;
			uint32_t Seg10Com4:1;
			uint32_t Seg10Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg11Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg11Com1:1;	//Reseved 31:8
			uint32_t Seg11Com2:1;
			uint32_t Seg11Com3:1;
			uint32_t Seg11Com4:1;
			uint32_t Seg11Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg12Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg12Com1:1;	//Reseved 31:8
			uint32_t Seg12Com2:1;
			uint32_t Seg12Com3:1;
			uint32_t Seg12Com4:1;
			uint32_t Seg12Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg13Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg13Com1:1;	//Reseved 31:8
			uint32_t Seg13Com2:1;
			uint32_t Seg13Com3:1;
			uint32_t Seg13Com4:1;
			uint32_t Seg13Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP5_REG {
				uint32_t				all;
				struct  LCD_MEMMAP4_BITS	bit;
};

struct LCD_MEMMAP6_BITS	{
			uint32_t Seg10Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg10Com1:1;	//Reseved 31:8
			uint32_t Seg10Com2:1;
			uint32_t Seg10Com3:1;
			uint32_t Seg10Com4:1;
			uint32_t Seg10Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg11Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg11Com1:1;	//Reseved 31:8
			uint32_t Seg11Com2:1;
			uint32_t Seg11Com3:1;
			uint32_t Seg11Com4:1;
			uint32_t Seg11Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg12Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg12Com1:1;	//Reseved 31:8
			uint32_t Seg12Com2:1;
			uint32_t Seg12Com3:1;
			uint32_t Seg12Com4:1;
			uint32_t Seg12Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg13Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg13Com1:1;	//Reseved 31:8
			uint32_t Seg13Com2:1;
			uint32_t Seg13Com3:1;
			uint32_t Seg13Com4:1;
			uint32_t Seg13Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP6_REG {
				uint32_t				all;
				struct  LCD_MEMMAP4_BITS	bit;
};

struct LCD_MEMMAP7_BITS	{
			uint32_t Seg10Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg10Com1:1;	//Reseved 31:8
			uint32_t Seg10Com2:1;
			uint32_t Seg10Com3:1;
			uint32_t Seg10Com4:1;
			uint32_t Seg10Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg11Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg11Com1:1;	//Reseved 31:8
			uint32_t Seg11Com2:1;
			uint32_t Seg11Com3:1;
			uint32_t Seg11Com4:1;
			uint32_t Seg11Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg12Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg12Com1:1;	//Reseved 31:8
			uint32_t Seg12Com2:1;
			uint32_t Seg12Com3:1;
			uint32_t Seg12Com4:1;
			uint32_t Seg12Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg13Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg13Com1:1;	//Reseved 31:8
			uint32_t Seg13Com2:1;
			uint32_t Seg13Com3:1;
			uint32_t Seg13Com4:1;
			uint32_t Seg13Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP7_REG {
				uint32_t				all;
				struct  LCD_MEMMAP4_BITS	bit;
};

struct LCD_MEMMAP8_BITS	{
			uint32_t Seg10Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg10Com1:1;	//Reseved 31:8
			uint32_t Seg10Com2:1;
			uint32_t Seg10Com3:1;
			uint32_t Seg10Com4:1;
			uint32_t Seg10Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg11Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg11Com1:1;	//Reseved 31:8
			uint32_t Seg11Com2:1;
			uint32_t Seg11Com3:1;
			uint32_t Seg11Com4:1;
			uint32_t Seg11Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg12Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg12Com1:1;	//Reseved 31:8
			uint32_t Seg12Com2:1;
			uint32_t Seg12Com3:1;
			uint32_t Seg12Com4:1;
			uint32_t Seg12Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg13Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg13Com1:1;	//Reseved 31:8
			uint32_t Seg13Com2:1;
			uint32_t Seg13Com3:1;
			uint32_t Seg13Com4:1;
			uint32_t Seg13Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP8_REG {
				uint32_t				all;
				struct  LCD_MEMMAP4_BITS	bit;
};

struct LCD_MEMMAP9_BITS	{
			uint32_t Seg10Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg10Com1:1;	//Reseved 31:8
			uint32_t Seg10Com2:1;
			uint32_t Seg10Com3:1;
			uint32_t Seg10Com4:1;
			uint32_t Seg10Com5:1;
			uint32_t RSVD0:2;
			uint32_t Seg11Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg11Com1:1;	//Reseved 31:8
			uint32_t Seg11Com2:1;
			uint32_t Seg11Com3:1;
			uint32_t Seg11Com4:1;
			uint32_t Seg11Com5:1;
			uint32_t RSVD1:2;
			uint32_t Seg12Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg12Com1:1;	//Reseved 31:8
			uint32_t Seg12Com2:1;
			uint32_t Seg12Com3:1;
			uint32_t Seg12Com4:1;
			uint32_t Seg12Com5:1;
			uint32_t RSVD2:2;
			uint32_t Seg13Com0:1;	//This register holds data values that have been received or are to be transmitted.
			uint32_t Seg13Com1:1;	//Reseved 31:8
			uint32_t Seg13Com2:1;
			uint32_t Seg13Com3:1;
			uint32_t Seg13Com4:1;
			uint32_t Seg13Com5:1;
			uint32_t RSVD3:2;
			
};
union LCD_MEMMAP9_REG {
				uint32_t				all;
				struct  LCD_MEMMAP4_BITS	bit;
};


struct LCD_LCDOUTEN0_BITS	{
			uint32_t LCDCOMEN:6;	//Enable LCD driver
			uint32_t RSVD:26;	//Reseved 31:6
};
union LCD_LCDOUTEN0_REG {
				uint32_t				all;
				struct  LCD_LCDOUTEN0_BITS		bit;
};	


struct LCD_LCDOUTEN1_BITS	{
			uint32_t LCDSEGEN:16;	//Enable LCD driver
			uint32_t RSVD:16;	//Reseved 31:6
};
union LCD_LCDOUTEN1_REG {
				uint32_t				all;
				struct  LCD_LCDOUTEN1_BITS		bit;
};	


/* ================================================================================ */
/* ================                       LCD                      ================ */
/* ================================================================================ */
/**
  * @brief LCD 
  */

typedef struct {                                    								                                             
  __IO union LCD_LCDCTRL0_REG  LCDCTRL0;                            /*!< LCD driver enable                  */
  __IO union LCD_LCDCTRL1_REG  LCDCTRL1;                            /*!< LCD driver control register    */
	union {
	uint32_t MEMMAP[10];
//  __IO union LCD_MEMMAP0_REG  	MEMMAP0;                              /*!< Data memory map0                                                  */
//  __IO union LCD_MEMMAP1_REG  	MEMMAP1;                              /*!< Data memory map1                                       */
//  __IO union LCD_MEMMAP2_REG  	MEMMAP2;                              /*!< Data memory map2                                   */
//  __IO union LCD_MEMMAP3_REG  	MEMMAP3;                              /*!< Data memory map3                                  */
//  __IO union LCD_MEMMAP4_REG  	MEMMAP4;                            	/*!< Data memory map4                                      */
//  __IO union LCD_MEMMAP5_REG  	MEMMAP5;															/*!< Data memory map5                                          */
//  __IO union LCD_MEMMAP6_REG  	MEMMAP6;                              /*!< Data memory map6                                          */
//  __IO union LCD_MEMMAP7_REG  	MEMMAP7;                              /*!< Data memory map7                                       */
//  __IO union LCD_MEMMAP8_REG  	MEMMAP8;                              /*!< Data memory map8                                          */
//  __IO union LCD_MEMMAP9_REG  	MEMMAP9;                       				/*!< Data memory map9                                      */
	struct{
      uint32_t COM0TOSEG   : 8;            /*!< (@ 0x00000000) Com0 cross to Segment0~7                                   */
      uint32_t             : 8;
      uint32_t COM1TOSEG   : 8;            /*!< (@ 0x00000010) Com1 cross to Segment0~7 */
			uint32_t             : 8;
      uint32_t COM2TOSEG   : 8;            /*!< (@ 0x00000000) Com2 cross to Segment0~7                                   */
      uint32_t             : 8;
      uint32_t COM3TOSEG   : 8;            /*!< (@ 0x00000010) Com3 cross to Segment0~7 */
			uint32_t             : 8;
      uint32_t COM4TOSEG   : 8;            /*!< (@ 0x00000000) Com4 cross to Segment0~7                                   */
      uint32_t             : 8;
      uint32_t COM5TOSEG   : 8;            /*!< (@ 0x00000010) Com5 cross to Segment0~7 */
			uint32_t             : 8;
       uint32_t COM6TOSEG   : 8;            /*!< (@ 0x00000000) Com7 cross to Segment0~7                                   */
      uint32_t             : 8;
      uint32_t COM7TOSEG   : 8;            /*!< (@ 0x00000010) Com7 cross to Segment0~7*/ 
			uint32_t             : 8;
	}	LEDMEMMAP;
};
  __IO union LCD_LCDOUTEN0_REG  LCDOUTEN0;                          /*!< TWS address mask register0                                            */
  __IO union LCD_LCDOUTEN1_REG  LCDOUTEN1;                          /*!< TWS address mask register1                                            */
} XN_LCD_TypeDef;


#define XN_LCD                             ((XN_LCD_TypeDef                *) LCDCON_BASE)


//LCD config	
#define LCD_MODE	0
#define LED_MODE 1
#define DUTY_1				    2						 
#define DUTY_2				    2						 
#define DUTY_3				    3					 
#define DUTY_4			    	4						 
#define DUTY_5						5					
#define DUTY_6				    6						 
#define DUTY_7				    7					 
#define DUTY_8				    8		
#define LCD_BIAS_3			    	0					 
#define LCD_BIAS_2				    1						 
#define LED_ANODE	0
#define LED_CATHODE 1

#define COM0				    0x1						 
#define COM1				    0x2					 
#define COM2			    	0x4						 
#define COM3						0x8					 
#define COM4				    0x10					 
#define COM5				    0x20					 
#define COM6				    0x40					 
#define COM7				    0x80					 
#define SEG0			    	0x1					 
#define SEG1				    0x2						
#define SEG2						0x4
#define SEG3		 				0x8
#define SEG4		 				0x10
#define SEG5		 				0x20	
#define SEG6		 				0x40	
#define SEG7		 				0x80	
#define SEG8	 					0x100	
#define SEG9	 					0x200	
#define SEG10	 					0x400	
#define SEG11	 					0x800	
#define SEG12	 					0x1000	
#define SEG13	 					0x2000	
#define SEG14	 					0x4000	
#define SEG15	 					0x8000	

/* Private variables ---------------------------------------------------------*/

void LCD_Init (uint8_t mode,uint8_t duty, uint8_t biasanode, uint8_t finhz);
void LCD_Deinit(void);
void LCD_EnableOutput(uint8_t comchannel, uint16_t segchannel);
void LCD_SetDot (uint8_t com, uint8_t segment);
void LCD_ResetDot (uint8_t com, uint8_t segment);
void LCD_SetComLine (uint8_t com, uint16_t segments);
void LCD_ResetComLine (uint8_t com, uint16_t segments);
void LCD_WriteComLine(uint8_t com, uint16_t data);
void LCD_ClearScreen(void);
void LCD_LightFullScreen(void);
void LCD_WriteMemMap(uint8_t offset, uint32_t data);
#endif /* end __LCD_H */


/* --------------------------------- End Of File ------------------------------ */

