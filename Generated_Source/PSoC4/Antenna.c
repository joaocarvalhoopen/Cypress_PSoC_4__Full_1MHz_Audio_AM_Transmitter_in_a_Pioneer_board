/*******************************************************************************
* File Name: Antenna.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Antenna.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Antenna_PC =   (Antenna_PC & \
                                (uint32)(~(uint32)(Antenna_DRIVE_MODE_IND_MASK << (Antenna_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Antenna_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Antenna_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Antenna_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Antenna_DR & (uint8)(~Antenna_MASK));
    drVal = (drVal | ((uint8)(value << Antenna_SHIFT) & Antenna_MASK));
    Antenna_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Antenna_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Antenna_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Antenna__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Antenna_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Antenna_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Antenna_Read(void) 
{
    return (uint8)((Antenna_PS & Antenna_MASK) >> Antenna_SHIFT);
}


/*******************************************************************************
* Function Name: Antenna_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Antenna_ReadDataReg(void) 
{
    return (uint8)((Antenna_DR & Antenna_MASK) >> Antenna_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Antenna_INTSTAT) 

    /*******************************************************************************
    * Function Name: Antenna_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Antenna_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Antenna_INTSTAT & Antenna_MASK);
		Antenna_INTSTAT = maskedStatus;
        return maskedStatus >> Antenna_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
