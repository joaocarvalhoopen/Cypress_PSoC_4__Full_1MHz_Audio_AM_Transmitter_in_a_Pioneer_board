/*******************************************************************************
* File Name: Pin_Audio_Input.c  
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
#include "Pin_Audio_Input.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Pin_Audio_Input_PC =   (Pin_Audio_Input_PC & \
                                (uint32)(~(uint32)(Pin_Audio_Input_DRIVE_MODE_IND_MASK << (Pin_Audio_Input_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Pin_Audio_Input_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Pin_Audio_Input_Write
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
void Pin_Audio_Input_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Pin_Audio_Input_DR & (uint8)(~Pin_Audio_Input_MASK));
    drVal = (drVal | ((uint8)(value << Pin_Audio_Input_SHIFT) & Pin_Audio_Input_MASK));
    Pin_Audio_Input_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Pin_Audio_Input_SetDriveMode
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
void Pin_Audio_Input_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Pin_Audio_Input__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Pin_Audio_Input_Read
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
*  Macro Pin_Audio_Input_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pin_Audio_Input_Read(void) 
{
    return (uint8)((Pin_Audio_Input_PS & Pin_Audio_Input_MASK) >> Pin_Audio_Input_SHIFT);
}


/*******************************************************************************
* Function Name: Pin_Audio_Input_ReadDataReg
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
uint8 Pin_Audio_Input_ReadDataReg(void) 
{
    return (uint8)((Pin_Audio_Input_DR & Pin_Audio_Input_MASK) >> Pin_Audio_Input_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pin_Audio_Input_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pin_Audio_Input_ClearInterrupt
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
    uint8 Pin_Audio_Input_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Pin_Audio_Input_INTSTAT & Pin_Audio_Input_MASK);
		Pin_Audio_Input_INTSTAT = maskedStatus;
        return maskedStatus >> Pin_Audio_Input_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
