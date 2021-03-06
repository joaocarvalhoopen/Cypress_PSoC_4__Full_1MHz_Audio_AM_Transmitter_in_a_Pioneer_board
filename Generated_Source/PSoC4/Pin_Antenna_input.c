/*******************************************************************************
* File Name: Pin_Antenna_input.c  
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
#include "Pin_Antenna_input.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Pin_Antenna_input_PC =   (Pin_Antenna_input_PC & \
                                (uint32)(~(uint32)(Pin_Antenna_input_DRIVE_MODE_IND_MASK << (Pin_Antenna_input_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Pin_Antenna_input_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Pin_Antenna_input_Write
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
void Pin_Antenna_input_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Pin_Antenna_input_DR & (uint8)(~Pin_Antenna_input_MASK));
    drVal = (drVal | ((uint8)(value << Pin_Antenna_input_SHIFT) & Pin_Antenna_input_MASK));
    Pin_Antenna_input_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Pin_Antenna_input_SetDriveMode
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
void Pin_Antenna_input_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Pin_Antenna_input__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Pin_Antenna_input_Read
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
*  Macro Pin_Antenna_input_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pin_Antenna_input_Read(void) 
{
    return (uint8)((Pin_Antenna_input_PS & Pin_Antenna_input_MASK) >> Pin_Antenna_input_SHIFT);
}


/*******************************************************************************
* Function Name: Pin_Antenna_input_ReadDataReg
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
uint8 Pin_Antenna_input_ReadDataReg(void) 
{
    return (uint8)((Pin_Antenna_input_DR & Pin_Antenna_input_MASK) >> Pin_Antenna_input_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pin_Antenna_input_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pin_Antenna_input_ClearInterrupt
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
    uint8 Pin_Antenna_input_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Pin_Antenna_input_INTSTAT & Pin_Antenna_input_MASK);
		Pin_Antenna_input_INTSTAT = maskedStatus;
        return maskedStatus >> Pin_Antenna_input_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
