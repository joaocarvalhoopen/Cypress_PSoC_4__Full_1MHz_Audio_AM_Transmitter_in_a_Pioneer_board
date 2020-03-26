/*******************************************************************************
* File Name: Antenna.h  
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

#if !defined(CY_PINS_Antenna_H) /* Pins Antenna_H */
#define CY_PINS_Antenna_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Antenna_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Antenna_Write(uint8 value) ;
void    Antenna_SetDriveMode(uint8 mode) ;
uint8   Antenna_ReadDataReg(void) ;
uint8   Antenna_Read(void) ;
uint8   Antenna_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Antenna_DRIVE_MODE_BITS        (3)
#define Antenna_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Antenna_DRIVE_MODE_BITS))
#define Antenna_DRIVE_MODE_SHIFT       (0x00u)
#define Antenna_DRIVE_MODE_MASK        (0x07u << Antenna_DRIVE_MODE_SHIFT)

#define Antenna_DM_ALG_HIZ         (0x00u << Antenna_DRIVE_MODE_SHIFT)
#define Antenna_DM_DIG_HIZ         (0x01u << Antenna_DRIVE_MODE_SHIFT)
#define Antenna_DM_RES_UP          (0x02u << Antenna_DRIVE_MODE_SHIFT)
#define Antenna_DM_RES_DWN         (0x03u << Antenna_DRIVE_MODE_SHIFT)
#define Antenna_DM_OD_LO           (0x04u << Antenna_DRIVE_MODE_SHIFT)
#define Antenna_DM_OD_HI           (0x05u << Antenna_DRIVE_MODE_SHIFT)
#define Antenna_DM_STRONG          (0x06u << Antenna_DRIVE_MODE_SHIFT)
#define Antenna_DM_RES_UPDWN       (0x07u << Antenna_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Antenna_MASK               Antenna__MASK
#define Antenna_SHIFT              Antenna__SHIFT
#define Antenna_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Antenna_PS                     (* (reg32 *) Antenna__PS)
/* Port Configuration */
#define Antenna_PC                     (* (reg32 *) Antenna__PC)
/* Data Register */
#define Antenna_DR                     (* (reg32 *) Antenna__DR)
/* Input Buffer Disable Override */
#define Antenna_INP_DIS                (* (reg32 *) Antenna__PC2)


#if defined(Antenna__INTSTAT)  /* Interrupt Registers */

    #define Antenna_INTSTAT                (* (reg32 *) Antenna__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Antenna_H */


/* [] END OF FILE */
