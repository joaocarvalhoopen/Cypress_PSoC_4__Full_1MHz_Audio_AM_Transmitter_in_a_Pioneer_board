/*******************************************************************************
* File Name: Pin_send_carrier_to_ground.h  
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

#if !defined(CY_PINS_Pin_send_carrier_to_ground_H) /* Pins Pin_send_carrier_to_ground_H */
#define CY_PINS_Pin_send_carrier_to_ground_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pin_send_carrier_to_ground_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_send_carrier_to_ground_Write(uint8 value) ;
void    Pin_send_carrier_to_ground_SetDriveMode(uint8 mode) ;
uint8   Pin_send_carrier_to_ground_ReadDataReg(void) ;
uint8   Pin_send_carrier_to_ground_Read(void) ;
uint8   Pin_send_carrier_to_ground_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_send_carrier_to_ground_DRIVE_MODE_BITS        (3)
#define Pin_send_carrier_to_ground_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pin_send_carrier_to_ground_DRIVE_MODE_BITS))
#define Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT       (0x00u)
#define Pin_send_carrier_to_ground_DRIVE_MODE_MASK        (0x07u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)

#define Pin_send_carrier_to_ground_DM_ALG_HIZ         (0x00u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)
#define Pin_send_carrier_to_ground_DM_DIG_HIZ         (0x01u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)
#define Pin_send_carrier_to_ground_DM_RES_UP          (0x02u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)
#define Pin_send_carrier_to_ground_DM_RES_DWN         (0x03u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)
#define Pin_send_carrier_to_ground_DM_OD_LO           (0x04u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)
#define Pin_send_carrier_to_ground_DM_OD_HI           (0x05u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)
#define Pin_send_carrier_to_ground_DM_STRONG          (0x06u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)
#define Pin_send_carrier_to_ground_DM_RES_UPDWN       (0x07u << Pin_send_carrier_to_ground_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Pin_send_carrier_to_ground_MASK               Pin_send_carrier_to_ground__MASK
#define Pin_send_carrier_to_ground_SHIFT              Pin_send_carrier_to_ground__SHIFT
#define Pin_send_carrier_to_ground_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_send_carrier_to_ground_PS                     (* (reg32 *) Pin_send_carrier_to_ground__PS)
/* Port Configuration */
#define Pin_send_carrier_to_ground_PC                     (* (reg32 *) Pin_send_carrier_to_ground__PC)
/* Data Register */
#define Pin_send_carrier_to_ground_DR                     (* (reg32 *) Pin_send_carrier_to_ground__DR)
/* Input Buffer Disable Override */
#define Pin_send_carrier_to_ground_INP_DIS                (* (reg32 *) Pin_send_carrier_to_ground__PC2)


#if defined(Pin_send_carrier_to_ground__INTSTAT)  /* Interrupt Registers */

    #define Pin_send_carrier_to_ground_INTSTAT                (* (reg32 *) Pin_send_carrier_to_ground__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Pin_send_carrier_to_ground_H */


/* [] END OF FILE */
