/*******************************************************************************
* File Name: Clock_1_carrier.h
* Version 2.10
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_1_carrier_H)
#define CY_CLOCK_Clock_1_carrier_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void Clock_1_carrier_Start(void);
void Clock_1_carrier_Stop(void);

void Clock_1_carrier_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock_1_carrier_GetDividerRegister(void);
uint8  Clock_1_carrier_GetFractionalDividerRegister(void);

#define Clock_1_carrier_Enable()                         Clock_1_carrier_Start()
#define Clock_1_carrier_Disable()                        Clock_1_carrier_Stop()
#define Clock_1_carrier_SetDividerRegister(clkDivider, reset)  \
                        Clock_1_carrier_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock_1_carrier_SetDivider(clkDivider)           Clock_1_carrier_SetDividerRegister((clkDivider), 1u)
#define Clock_1_carrier_SetDividerValue(clkDivider)      Clock_1_carrier_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/

#define Clock_1_carrier_DIV_REG    (*(reg32 *)Clock_1_carrier__REGISTER)
#define Clock_1_carrier_ENABLE_REG Clock_1_carrier_DIV_REG

#endif /* !defined(CY_CLOCK_Clock_1_carrier_H) */

/* [] END OF FILE */
