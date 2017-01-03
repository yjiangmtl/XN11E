/* Includes ------------------------------------------------------------------*/

#include "XN11Exxx.h"
#include "xn_iap.h"

/*****************************************************************************
Function Name	FMC_SetFlashReadTime
Function Definition	void FMC_SetFlashReadTime(uint8_t clocks)
Function Description	Set Read flash cycle
Input Parameters	No
Return Value	No
Condition	No
Function called	-


Last Chang Date: 2015/09/12			By:YL
*****************************************************************************/
void FMC_SetFlashReadTime(uint8_t clocks)
{
	FMC->FLASH_RDCYC = clocks;
}
	