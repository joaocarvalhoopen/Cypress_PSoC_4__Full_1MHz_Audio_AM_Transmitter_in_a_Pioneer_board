/*******************************************************************************
* File Name: Pin_Audio_Input.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_Audio_Input_H) /* Pins Pin_Audio_Input_H */
#define CY_PINS_Pin_Audio_Input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pin_Audio_Input_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_Audio_Input_Write(uint8 value) ;
void    Pin_Audio_Input_SetDriveMode(uint8 mode) ;
uint8   Pin_Audio_Input_ReadDataReg(void) ;
uint8   Pin_Audio_Input_Read(void) ;
uint8   Pin_Audio_Input_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_Audio_Input_DRIVE_MODE_BITS        (3)
#define Pin_Audio_Input_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pin_Audio_Input_DRIVE_MODE_BITS))
#define Pin_Audio_Input_DRIVE_MODE_SHIFT       (0x00u)
#define Pin_Audio_Input_DRIVE_MODE_MASK        (0x07u << Pin_Audio_Input_DRIVE_MODE_SHIFT)

#define Pin_Audio_Input_DM_ALG_HIZ         (0x00u << Pin_Audio_Input_DRIVE_MODE_SHIFT)
#define Pin_Audio_Input_DM_DIG_HIZ         (0x01u << Pin_Audio_Input_DRIVE_MODE_SHIFT)
#define Pin_Audio_Input_DM_RES_UP          (0x02u << Pin_Audio_Input_DRIVE_MODE_SHIFT)
#define Pin_Audio_Input_DM_RES_DWN         (0x03u << Pin_Audio_Input_DRIVE_MODE_SHIFT)
#define Pin_Audio_Input_DM_OD_LO           (0x04u << Pin_Audio_Input_DRIVE_MODE_SHIFT)
#define Pin_Audio_Input_DM_OD_HI           (0x05u << Pin_Audio_Input_DRIVE_MODE_SHIFT)
#define Pin_Audio_Input_DM_STRONG          (0x06u << Pin_Audio_Input_DRIVE_MODE_SHIFT)
#define Pin_Audio_Input_DM_RES_UPDWN       (0x07u << Pin_Audio_Input_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Pin_Audio_Input_MASK               Pin_Audio_Input__MASK
#define Pin_Audio_Input_SHIFT              Pin_Audio_Input__SHIFT
#define Pin_Audio_Input_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_Audio_Input_PS                     (* (reg32 *) Pin_Audio_Input__PS)
/* Port Configuration */
#define Pin_Audio_Input_PC                     (* (reg32 *) Pin_Audio_Input__PC)
/* Data Register */
#define Pin_Audio_Input_DR                     (* (reg32 *) Pin_Audio_Input__DR)
/* Input Buffer Disable Override */
#define Pin_Audio_Input_INP_DIS                (* (reg32 *) Pin_Audio_Input__PC2)


#if defined(Pin_Audio_Input__INTSTAT)  /* Interrupt Registers */

    #define Pin_Audio_Input_INTSTAT                (* (reg32 *) Pin_Audio_Input__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Pin_Audio_Input_H */


/* [] END OF FILE */
