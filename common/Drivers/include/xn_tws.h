/*****************************************************************************
 *   XN_TWS:  Head file for Xinnova MCU TWS(TWS compatible) application
 *
 *   Copyright(C) 2012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2012.08.14  ver 1.00
 *
******************************************************************************/
#ifndef __TWS_H
#define __TWS_H

#ifdef __cplusplus
extern "C" {
#endif


#include "XN11Exxx.h"
//--TWS Registers BITS Field---------------------------------------------------------------------------------------
struct TWS_CONSET_BITS	{
			uint32_t TXRX:1;	//Transmit/receive flag
			uint32_t MASL:1;	//Master/slave flag
			uint32_t AA:1;	//Assert acknowledge flag. 
			uint32_t SI:1;	//TWS interrupt flag. 
			uint32_t STO:1;	//STOP flag. 
			uint32_t STA:1;	//START flag. 
			uint32_t TWSEN:1;	//TWS interface enable. 
			uint32_t RSVD:25;	//Reseved 31:7
};
union TWS_CONSET_REG {
				uint32_t				all;
				struct  TWS_CONSET_BITS		bit;
};	
struct TWS_STAT_BITS	{
			uint32_t STATUS:6;	//These bits give the actual status information
			uint32_t SLVADDMATCH:1;	//Slave address matched. 
			uint32_t SLVRXBUFFULL:1;	//Slave receiver buffer is full. 
			uint32_t SLVTXBUFEMPTY:1;	//Slave transmitter buffer is empty. 
			uint32_t RSVD:22;	//Reseved 31:11
};
union TWS_STAT_REG {
				uint32_t				all;
				struct  TWS_STAT_BITS		bit;
};
struct TWS_DAT_BITS	{
			uint32_t DATA:8;	//This register holds data values that have been received or are to be transmitted.
			uint32_t RSVD:24;	//Reseved 31:8
};
union TWS_DAT_REG {
				uint32_t				all;
				struct  TWS_DAT_BITS		bit;
};
struct TWS_ADR_BITS	{
			uint32_t RSVD0:1;	//Reseved 
			uint32_t ADDR:7;	//The TWS device address for slave mode. 
			uint32_t RSVD1:24;	//Reseved 31:8
};
union TWS_ADR_REG {
				uint32_t				all;
				struct  TWS_ADR_BITS		bit;
};
struct TWS_SCLH_BITS	{
			uint32_t SCLH:16;	//Count for TWS high time period selection 
			uint32_t RSVD:16;	//Reseved 31:16
};
union TWS_SCLH_REG {
				uint32_t				all;
				struct  TWS_SCLH_BITS		bit;
};
struct TWS_SCLL_BITS	{
			uint32_t SCLL:16;	//Count for TWS low time period selection 
			uint32_t RSVD:16;	//Reseved 31:16
};
union TWS_SCLL_REG {
				uint32_t				all;
				struct  TWS_SCLL_BITS		bit;
};
struct TWS_CONCLR_BITS	{
			uint32_t TXRX:1;	//TX/RX select Clear bit. 
			uint32_t MASL:1;	//Master/slave select Clear bit. 
			uint32_t AAC:1;	//Assert acknowledge Clear bit. 
			uint32_t SIC:1;	//Interrupt Clear bit. 
			uint32_t RSVD0:1; 
			uint32_t STAC:1;	//START flag Clear bit. 
			uint32_t TWSENC:1;	//TWS interface Disable bit. 
			uint32_t RSVD1:25;	//Reseved 31:7
};
union TWS_CONCLR_REG {
				uint32_t				all;
				struct  TWS_CONCLR_BITS		bit;
};
struct TWS_DATA_BITS	{
			uint32_t DAT:8;	//This register holds contents of the 8 MSBs of the DAT shift register. 
			uint32_t RSVD:24;	//Reseved 31:8
};
union TWS_DATA_REG {
				uint32_t				all;
				struct  TWS_DATA_BITS		bit;
};
struct TWS_MASK_BITS	{
			uint32_t RSVD0:1;	//Reseved 
			uint32_t MASK:7;	//Mask bits.  
			uint32_t RSVD1:24;	//Reseved 31:8
};
union TWS_MASK_REG {
				uint32_t				all;
				struct  TWS_MASK_BITS		bit;
};
/* ================================================================================ */
/* ================                       TWS                      ================ */
/* ================================================================================ */


/**
  * @brief two wires serial communication interface (TWS)
  */

typedef struct {                                    /*!< TWS Structure                                                         */
  __IO union TWS_CONSET_REG  CONSET;                            /*!< TWS control set bit register                                          */
  __I  union TWS_STAT_REG  STAT;                              /*!< TWS state register                                                    */
  __IO union TWS_DAT_REG  DAT;                               /*!< TWS data register                                                     */
  __IO union TWS_ADR_REG  ADR0;                              /*!< TWS Slave Address Register 0                                          */
  __IO union TWS_SCLH_REG  SCLH;                              /*!< Duty Cycle Register High Half Word                                    */
  __IO union TWS_SCLL_REG  SCLL;                              /*!< Duty Cycle Register Low Half Word                                     */
  __O  union TWS_CONCLR_REG  CONCLR;                            /*!< TWS Control Clear Register                                            */
  __I  uint32_t  RSVD;
  __IO union TWS_ADR_REG  ADR1;                              /*!< TWS Slave Address Register 1                                          */
  __IO union TWS_ADR_REG  ADR2;                              /*!< TWS slave address register2                                           */
  __IO union TWS_ADR_REG  ADR3;                              /*!< TWS slave address register3                                           */
  __I  union TWS_DATA_REG  DATA_BUFFER;                       /*!< TWS data buffer register                                              */
  __IO union TWS_MASK_REG  MASK0;                             /*!< TWS address mask register0                                            */
  __IO union TWS_MASK_REG  MASK1;                             /*!< TWS address mask register1                                            */
  __IO union TWS_MASK_REG  MASK2;                             /*!< TWS address mask register2                                            */
  __IO union TWS_MASK_REG  MASK3;                             /*!< TWS address mask register3                                            */
} XN_TWS_TypeDef;

#define XN_TWS                             ((XN_TWS_TypeDef                *) TWS_BASE)
//TWS mode

//TWS status	
#define TWS_IDLE				    0
#define TWS_STARTED				    1
#define TWS_RESTARTED			    2
#define TWS_REPEATED_START			3
#define DATA_ACK				    4
#define DATA_NACK				    5
#define TWS_BUSY				    6
#define TWS_NO_DATA				    7
#define TWS_NACK_ON_ADDRESS			8
#define TWS_NACK_ON_DATA		 	9
#define TWS_ARBITRATION_LOST  		10
#define TWS_TIME_OUT			    11
#define TWS_OK					    12

/* Private variables ---------------------------------------------------------*/
static uint8_t TWSMasterBuffer[8];
static uint8_t TWSSlaveBuffer[8];
static uint8_t TWSMasterState = TWS_IDLE;
static uint32_t TWSReadLength, TWSWriteLength;
static uint32_t RdIndex = 0;
static uint32_t WrIndex = 0;
static uint32_t Restart = 0;
static uint8_t Re_Start;

#define TWS_CONSET_TXRX			((uint8_t)(0x01))	/*!< Transmit/Receive flag */
#define TWS_CONSET_MASL			((uint8_t)(0x02))	/*!< Master/Slave flag */
#define TWS_CONSET_AA			((uint8_t)(0x04))	/*!< Assert acknowledge flag */
#define TWS_CONSET_SI			((uint8_t)(0x08)) 	/*!< TWS interrupt flag */
#define TWS_CONSET_STO			((uint8_t)(0x10)) 	/*!< STOP flag */
#define TWS_CONSET_STA			((uint8_t)(0x20)) 	/*!< START flag */
#define TWS_CONSET_I2EN			((uint8_t)(0x40)) 	/*!< TWS interface enable */
#define PARAM_TWS_CONSET(TWS_CONSET) 		((((TWS_CONSET) & (uint8_t)0x83) == 0x00) && ((TWS_CONSET) != 0x00))


#define TWS_CONCLR_TXRXC			((uint8_t)(0x01))  	/*!< Transmit/Receive Clear bit */
#define TWS_CONCLR_MASLC			((uint8_t)(0x02))	/*!< Master/Slave Clear bit */
#define TWS_CONCLR_AAC			((uint8_t)(0x04))  	/*!< Assert acknowledge Clear bit */
#define TWS_CONCLR_SIC			((uint8_t)(0x08))	/*!< TWS interrupt Clear bit */
#define TWS_CONCLR_STAC			((uint8_t)(0x20))	/*!< START flag Clear bit */
#define TWS_CONCLR_I2ENC			((uint8_t)(0x40))	/*!< TWS interface Disable bit */
#define PARAM_TWS_CONCLR(TWS_CONCLR) 		((((TWS_CONCLR) & (uint8_t)0x93) == 0x00) && ((TWS_CONCLR) != 0x00))
						

#define TWS_M_TX_START				0x01		/*!< A start condition has been transmitted */
#define TWS_M_TX_RESTART			0x10	 	/*!< A repeat start condition has been transmitted */
#define TWS_M_TX_SLAW_ACK			0x0B	 	/*!< SLA+W has been transmitted, ACK has been received */
#define TWS_M_TX_SLAW_NACK		0x4B	  /*!< SLA+W has been transmitted, NACK has been received */
#define TWS_M_TX_DAT_ACK			0x14		/*!< Data has been transmitted, ACK has been received */
#define TWS_M_TX_ARB_LOST			0x54	 	/*!< Arbitration lost in SLA+R/W or Data bytes */
 

#define TWS_M_RX_START				0x01		/*!< A start condition has been transmitted */
#define TWS_M_RX_RESTART			0x22		/*!< A repeat start condition has been transmitted */
#define TWS_M_RX_SLAR_ACK			0x0B		/*!< SLA+R has been transmitted, ACK has been received */
#define TWS_M_RX_SLAR_NACK		0x4B 		/*!< SLA+R has been transmitted, NACK has been received */
#define TWS_M_RX_DAT_ACK			0x1D	  	/*!< Data has been received, ACK has been returned */
#define TWS_M_RX_DAT_NACK			0x5D	 	/*!< Data has been received, NACK has been return */  

uint8_t TWS_GetTWSStatus( void );
uint8_t TWS_ReadFlag( uint8_t TWS_CONSET );
void TWS_SetFlag( uint8_t TWS_CONSET );
void TWS_ClearFlag( uint8_t CONCLR );
void TWS_SendByte( uint8_t DataByte );
uint8_t TWS_GetByte( void );

void TWS_Init(uint8_t Mode, uint32_t ClockRate, uint32_t SlaveAddress);
//void TWSMasterTransmitReceiver(uint8_t *MasterBuffer, uint8_t WriteLength,uint8_t ReadLength);		



void TWS_ReadArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Lenth, uint8_t *Buffer);
void TWS_WriteByte(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Value);
void TWS_WriteArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t *Buff, uint8_t Length);
uint8_t TWS_ReadByte(uint8_t SlaveAddress, uint8_t SubAddr);



#ifdef __cplusplus
}
#endif

#endif 

/* --------------------------------- End Of File ------------------------------ */

