/*****************************************************************************
 *   XN_TWS:  Sourse file for Xinnova MCU TWS(I2C compatible) application
 *
 *   Copyright(C) 2012, Xinnova Technology
 *   All rights reserved.
 *
 *   History
 *   2012.08.14  ver 1.00
 *
******************************************************************************/

#include "XN11Exxx.h"
#include "XN_SYS.h"
#include "XN_TWS.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
** Function name:		TWS initial
**
** Descriptions:		TWS initial function
**
** parameters:      Mode: 1---Master 0---Slave
**                  ClockRate: unit in KHz
**                  SlaveAddress: Slave address in slave mode
**                  TWSInterrupt: 1---Enable TWS Interrupt 0---Disable TWS Interrupt
**
** Returned value:	None
** 
*****************************************************************************/
void TWS_Init(uint8_t Mode, uint32_t ClockRate, uint32_t SlaveAddress)
{
	/*---  Enable TWS clock and de-assert reset  ---*/
    XN_SYSCON->PRESETCTRL.bit.TWS_RST_N |= 1;
    XN_SYSCON->SYSAHBCLKCTRL.bit.TWSCLK |= 1;

	/*---  TWS I/O config  ---*/    
//    XN_IOCON->PIO1_10 = 0x01 + (1<<10);  // TWS SCL I/O config, PIO1_10-->SCL
//    XN_IOCON->PIO1_11 = 0x01 + (1<<10);  // TWS SDA I/O config, PIO1_11-->SDA
    
	/*--- Clear flags ---*/
	XN_TWS->CONCLR.all = 0xFF;   

	/*--- Set Clock rate ---*/
	XN_TWS->SCLH.bit.SCLH= SystemCoreClock/ClockRate;
	XN_TWS->SCLL.bit.SCLL = SystemCoreClock/ClockRate;

	if (!Mode)
	{
		XN_TWS->ADR0.all = SlaveAddress; // Slave address
	}
	    
	if (Mode)
	{
		
		XN_TWS->CONSET.all = 0x42; // Master mode
	} 
	else
	{
		XN_TWS->CONSET.all = 0x40; // Slave mode
	}

	/* Enable the TWS Interrupt */

	NVIC_EnableIRQ(TWS_IRQn);
}


/*****************************************************************************
** Function name:		TWS_GetTWSStatus
**
** Descriptions:		Get TWS Status
**
** parameters:      None
**
** Returned value:	None
** 
*****************************************************************************/
uint8_t TWS_GetTWSStatus( void )
{
	return (XN_TWS->STAT.all);
}

/*****************************************************************************
** Function name:		TWS_ReadFlag
**
** Descriptions:		Read TWS Flag
**
** parameters:      Read bit
**
** Returned value:	None
** 
*****************************************************************************/
uint8_t TWS_ReadFlag( uint8_t TWS_CONSET )
{
	return(XN_TWS->CONSET.all & TWS_CONSET);      /* retuen flag */
}

/*****************************************************************************
** Function name:		TWS_SetFlag
**
** Descriptions:		Set TWS Flag
**
** parameters:      Set bit
**
** Returned value:	None
** 
*****************************************************************************/
void TWS_SetFlag( uint8_t TWS_CONSET )
{
	XN_TWS->CONSET.all = TWS_CONSET;      /* Set flag */
}

/*****************************************************************************
** Function name:		TWS_ClearFlag
**
** Descriptions:		Clear TWS Flag
**
** parameters:      Clear bit
**
** Returned value:	None
** 
*****************************************************************************/
void TWS_ClearFlag( uint8_t TWS_CONCLR )
{
	XN_TWS->CONCLR.all = TWS_CONCLR;      /* Clear flag */
}

/*****************************************************************************
** Function name:		TWS_SendByte
**
** Descriptions:		Send Byte
**
** parameters:      Send data
**
** Returned value:	None
** 
*****************************************************************************/
void TWS_SendByte( uint8_t DataByte )
{
	XN_TWS->DAT.all = DataByte; 
}


/*****************************************************************************
** Function name:		TWS_GetByte
**
** Descriptions:		Get TWS Byte
**
** parameters:      None
**
** Returned value:	TWS Data
** 
*****************************************************************************/

uint8_t TWS_GetByte( void )
{
	return(XN_TWS->DAT.all);
}

/*****************************************************************************
* Function name:    TWS_IRQHandler
*
* Descriptions:     Use status to control process
*
* parameters:       None
* Returned value:   None
* 
*****************************************************************************/
void TWS_IRQHandler(void) 
{
	uint8_t StatValue;
	
	StatValue = TWS_GetTWSStatus();
	// 0x4B--SLA+W transmitted but no ACK 
	// 0x54--Data byte in DAT transmitted;no ACK received.
	if 	((StatValue == 0x4B) || (StatValue == 0x54))
	{
			TWS_SetFlag(TWS_CONSET_STO);				// Set Stop flag
			TWSMasterState = TWS_OK;
			TWS_ClearFlag(TWS_CONCLR_SIC| TWS_CONCLR_STAC |TWS_CONCLR_TXRXC );
			return;	
	}
	StatValue &= ~(0x40); 
	switch ( StatValue )
	{
		case TWS_M_TX_START:				/* 0x01: A Start condition is issued. */
			if (Restart == 1)
			{
				//RX SLAD TWS_M_TX_RESTART:
				Restart = 0;
				RdIndex = 0;
				TWS_SendByte(TWSMasterBuffer[0] + 1); 			/* Send SLA with R bit set */
				WrIndex++;
				TWS_ClearFlag(TWS_CONCLR_SIC | TWS_CONCLR_STAC |TWS_CONCLR_TXRXC);
			}
			else
			{
				// Start master transmit process
				WrIndex = 0;
				RdIndex = 0;
				TWS_SetFlag(TWS_CONSET_TXRX); 		 // Set tx flag
				TWS_SendByte(TWSMasterBuffer[0]);  // Transmit address first 
				WrIndex++;
				TWS_ClearFlag(TWS_CONCLR_SIC | TWS_CONCLR_STAC);
			}
			break;
		
		case TWS_M_TX_RESTART:			/* 0x10: A repeated started is issued */
			RdIndex = 0;
			TWS_SendByte(TWSMasterBuffer[WrIndex++]); 			/* Send SLA with R bit set */
			TWS_ClearFlag(TWS_CONCLR_SIC | TWS_CONCLR_STAC);
			break;
		
		case TWS_M_TX_SLAW_ACK:			/* 0x0B: Regardless, it's a ACK */
			if ((XN_TWS->CONSET.all & 0x1)==0x1) // Transmit
			{
				if (TWSWriteLength == 1)
				{
					TWS_SetFlag(TWS_CONSET_STO);      			// Set Stop flag
					TWSMasterState = TWS_NO_DATA;
				}
				else
				{
					TWS_SendByte(TWSMasterBuffer[WrIndex++]); // Transmit
				}
				TWS_ClearFlag(TWS_CONCLR_SIC);
			}
			else
			{
				if ( (RdIndex + 1) < TWSReadLength ) // Read form slave device
				{
					/* Will go to State 0x50 */
					TWS_SetFlag(TWS_CONSET_AA);					/* assert ACK after data is received */
				}
				else
				{
					/* Last byte will no ack, Will go to State 0x58 */
					TWS_ClearFlag(TWS_CONCLR_AAC);				/* assert NACK after data is received */
				}
				TWS_ClearFlag(TWS_CONCLR_SIC | TWS_CONCLR_STAC);
			}
			break;	
		
		case TWS_M_TX_DAT_ACK:			/* 0x14: Data byte has been transmitted, regardless ACK or NACK */
			if ( WrIndex < TWSWriteLength )
			{   
				TWS_SendByte(TWSMasterBuffer[WrIndex++]);	
			}
			else		/* this should be the last one */
			{
				if ( TWSReadLength != 0 )	  
				{
					Restart = 0;
					RdIndex = 0;
					if(Re_Start)
					{
						TWS_SendByte(TWSMasterBuffer[0] + 1); 			/* Send SLA with R bit set */
						TWS_SetFlag(TWS_CONSET_STA);				/* Set Repeated-start flag */
					}

					else
					{
						TWS_SendByte(TWSMasterBuffer[0] + 1); 			/* Send SLA with R bit set */
					}

					TWS_ClearFlag(TWS_CONCLR_SIC  |TWS_CONCLR_TXRXC);
					break;
				}
				else
				{
					TWS_SetFlag(TWS_CONSET_STO);				/* Set Stop flag */
					TWSMasterState = TWS_OK;
				}
			}
			TWS_ClearFlag(TWS_CONCLR_SIC);
			break;			
		
		case TWS_M_RX_DAT_ACK:			/* 0x1D, 0x5D: Data byte has been received, regardless following ACK or NACK */
			TWSSlaveBuffer[RdIndex++] = TWS_GetByte();
			if ( (RdIndex + 1) < TWSReadLength )
			{   
				TWS_SetFlag(TWS_CONSET_AA);					/* assert ACK after data is received */
				TWS_ClearFlag(TWS_CONCLR_SIC);
			}
			else
			{
				if ((XN_TWS->CONSET.all &0x04)==0x04)
					TWS_ClearFlag(TWS_CONCLR_AAC | TWS_CONCLR_SIC);
				else 
			   {
					 TWSMasterState = TWS_OK;
					 TWS_SetFlag(TWS_CONSET_STO);	/* assert NACK on last byte */
					 TWS_ClearFlag(TWS_CONCLR_SIC);
				 }
			}
			break;
			
		default:
			TWSMasterState = TWS_ARBITRATION_LOST;
			TWS_ClearFlag(TWS_CONCLR_SIC);	
			break;
	}
	return;
}
/*****************************************************************************
* Function name:    TWS_WriteByte
*
* Descriptions:     Write byte to slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
					Value :   Value write to slave chip register address
* Returned value:   None
* 
*****************************************************************************/

void TWS_WriteByte(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Value)
{
	uint8_t i;
	TWSMasterBuffer[0] = SlaveAddress; // Slave chip address
	TWSMasterBuffer[1] = SubAddr;	   // Chip register address
	TWSMasterBuffer[2] = Value;
	
	Re_Start = 0;

	TWSReadLength = 0; // Read length
	TWSWriteLength = 3;	// Write length


	TWS_SetFlag(TWS_CONSET_STA); //Set start signal

	TWSMasterState = TWS_IDLE;
	while( TWSMasterState != TWS_OK ); // Wait for finished

	i = 0xFF;
	while(i--);
}


/*****************************************************************************
* Function name:    TWS_WriteArray
*
* Descriptions:     Write array value to slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
					Buff: 	  Write value pointer
					Length:   Length to write
* Returned value:   None
* 
*****************************************************************************/
void TWS_WriteArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t *Buff, uint8_t Length)
{
	uint8_t i;
	TWSMasterBuffer[0] = SlaveAddress; // Slave chip address
	TWSMasterBuffer[1] = SubAddr;

	for( i = 0; i < Length; i++ )
	{
	 	TWSMasterBuffer[i+2] = *( Buff + i ); // Write value to slave chip register  		
	}
	
	Re_Start = 0;
	TWSReadLength = 0;
	TWSWriteLength = Length+2; // Write Length
	TWS_SetFlag(TWS_CONSET_STA); // Start

	TWSMasterState = TWS_IDLE;
	while( TWSMasterState != TWS_OK ); // Wait for finished

	i = 0xFF;
	while(i--);
}

/*****************************************************************************
* Function name:    TWS_ReadByte
*
* Descriptions:     Read byte from slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
* Returned value:   return read value
* 
*****************************************************************************/
uint8_t TWS_ReadByte(uint8_t SlaveAddress, uint8_t SubAddr)
{
	uint8_t i;
	TWSMasterBuffer[0] = SlaveAddress; // Slave chip address
	TWSMasterBuffer[1] = SubAddr;

	TWSWriteLength = 2;
	TWSReadLength = 1;
	
	Re_Start = 1;
	TWS_SetFlag(TWS_CONSET_STA); // Start

	TWSMasterState = TWS_IDLE;
	while( TWSMasterState != TWS_OK ); // Wait for finished

	i = 0xFF;
	while(i--);
	
	return(TWSSlaveBuffer[0]);
}

/*****************************************************************************
* Function name:    TWS_ReadArray
*
* Descriptions:     Read array value from slave chip
*
* parameters:       SlaveAddress: Slave chip address
					SubAddr:  Slave chip register address
					Length:   Length for reading
					Buffer:   Read value pointer
* Returned value:   None
* 
*****************************************************************************/
void TWS_ReadArray(uint8_t SlaveAddress, uint8_t SubAddr, uint8_t Lenth, uint8_t *Buffer)
{
	uint8_t i;
	TWSMasterBuffer[0] = SlaveAddress; // Slave chip address
	TWSMasterBuffer[1] = SubAddr;

	TWSWriteLength = 2;
	TWSReadLength = Lenth;
	
	Re_Start = 1;
	TWS_SetFlag(TWS_CONSET_STA); // Start

	TWSMasterState = TWS_IDLE;
	while( TWSMasterState != TWS_OK ); // Wait for finished
	
	for(i = 0; i < Lenth; i++)
	{
		*(Buffer+i) = TWSSlaveBuffer[i]; // Get pointer value
	}

	i = 0xFF;
	while(i--);
}


/* --------------------------------- End Of File ------------------------------ */
