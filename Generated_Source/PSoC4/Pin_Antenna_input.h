/*******************************************************************************
* File Name: Pin_Antenna_input.h  
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

#if !defined(CY_PINS_Pin_Antenna_input_H) /* Pins Pin_Antenna_input_H */
#define CY_PINS_Pin_Antenna_input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pin_Antenna_input_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_Antenna_input_Write(uint8 value) ;
void    Pin_Antenna_input_SetDriveMode(uint8 mode) ;
uint8   Pin_Antenna_input_ReadDataReg(void) ;
uint8   Pin_Antenna_input_Read(void) ;
uint8   Pin_Antenna_input_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_Antenna_input_DRIVE_MODE_BITS        (3)
#define Pin_Antenna_input_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pin_Antenna_input_DRIVE_MODE_BITS))
#define Pin_Antenna_input_DRIVE_MODE_SHIFT       (0x00u)
#define Pin_Antenna_input_DRIVE_MODE_MASK        (0x07u << Pin_Antenna_input_DRIVE_MODE_SHIFT)

#define Pin_Antenna_input_DM_ALG_HIZ         (0x00u << Pin_Antenna_input_DRIVE_MODE_SHIFT)
#define Pin_Antenna_input_DM_DIG_HIZ         (0x01u << Pin_Antenna_input_DRIVE_MODE_SHIFT)
#define Pin_Antenna_input_DM_RES_UP          (0x02u << Pin_Antenna_input_DRIVE_MODE_SHIFT)
#define Pin_Antenna_input_DM_RES_DWN         (0x03u << Pin_Antenna_input_DRIVE_MODE_SHIFT)
#define Pin_Antenna_input_DM_OD_LO           (0x04u << Pin_Antenna_input_DRIVE_MODE_SHIFT)
#define Pin_Antenna_input_DM_OD_HI           (0x05u << Pin_Antenna_input_DRIVE_MODE_SHIFT)
#define Pin_Antenna_input_DM_STRONG          (0x06u << Pin_Antenna_input_DRIVE_MODE_SHIFT)
#define Pin_Antenna_input_DM_RES_UPDWN       (0x07u << Pin_Antenna_input_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Pin_Antenna_input_MASK               Pin_Antenna_input__MASK
#define Pin_Antenna_input_SHIFT              Pin_Antenna_input__SHIFT
#define Pin_Antenna_input_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_Antenna_input_PS                     (* (reg32 *) Pin_Antenna_input__PS)
/* Port Configuration */
#define Pin_Antenna_input_PC                     (* (reg32 *) Pin_Antenna_input__PC)
/* Data Register */
#define Pin_Antenna_input_DR                     (* (reg32 *) Pin_Antenna_input__DR)
/* Input Buffer Disable Override */
#define Pin_Antenna_input_INP_DIS                (* (reg32 *) Pin_Antenna_input__PC2)


#if defined(Pin_Antenna_input__INTSTAT)  /* Interrupt Registers */

    #define Pin_Antenna_input_INTSTAT                (* (reg32 *) Pin_Antenna_input__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Pin_Antenna_input_H */


/* [] END OF FILE */
