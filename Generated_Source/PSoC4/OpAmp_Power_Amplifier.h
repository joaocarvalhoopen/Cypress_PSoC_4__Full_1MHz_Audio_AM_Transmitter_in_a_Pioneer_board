/*******************************************************************************
* File Name: OpAmp_Power_Amplifier.h
* Version 1.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the OpAmp (Analog Buffer) Component.
*
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_OpAmp_Power_Amplifier_H)
#define CY_OPAMP_OpAmp_Power_Amplifier_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Data Struct Definition
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} OpAmp_Power_Amplifier_BACKUP_STRUCT;

/* Component init state */
extern uint32 OpAmp_Power_Amplifier_initVar;


/**************************************
*        Function Prototypes
**************************************/
void OpAmp_Power_Amplifier_Init(void);
void OpAmp_Power_Amplifier_Enable(void);
void OpAmp_Power_Amplifier_Start(void);
void OpAmp_Power_Amplifier_Stop(void);
void OpAmp_Power_Amplifier_SetPower(uint32 power);
void OpAmp_Power_Amplifier_PumpControl(uint32 onOff);
void OpAmp_Power_Amplifier_Sleep(void);
void OpAmp_Power_Amplifier_Wakeup(void);
void OpAmp_Power_Amplifier_SaveConfig(void);
void OpAmp_Power_Amplifier_RestoreConfig(void);


/**************************************
*           API Constants
**************************************/
#define OpAmp_Power_Amplifier_LOWPOWER                   (1u)
#define OpAmp_Power_Amplifier_MEDPOWER                   (2u)
#define OpAmp_Power_Amplifier_HIGHPOWER                  (3u)

#define OpAmp_Power_Amplifier_OUTPUT_CURRENT             (1u)
#define OpAmp_Power_Amplifier_POWER                      (3u)
#define OpAmp_Power_Amplifier_MODE                       (1u)
#define OpAmp_Power_Amplifier_OA_COMP_TRIM_VALUE         (1u)


/**************************************
*             Registers
**************************************/
#define OpAmp_Power_Amplifier_OA_CTRL                    (*(reg32 *)OpAmp_Power_Amplifier_cy_psoc4_abuf__CTBM_CTB_CTRL)
#define OpAmp_Power_Amplifier_OA_RES_CTRL                (*(reg32 *)OpAmp_Power_Amplifier_cy_psoc4_abuf__OA_RES_CTRL)
#define OpAmp_Power_Amplifier_OA_COMP_TRIM_REG           (*(reg32 *)OpAmp_Power_Amplifier_cy_psoc4_abuf__OA_COMP_TRIM)

/* Bit Field  OA_CTRL */
#define OpAmp_Power_Amplifier_OA_CTB_EN_SHIFT            (31u)

/* PUMP ON/OFF defines */
#define OpAmp_Power_Amplifier_PUMPON                     (1u)
#define OpAmp_Power_Amplifier_PUMPOFF                    (0u)

#define OpAmp_Power_Amplifier_PUMP_PROTECT_MASK          (1u)

/* Bit Field  OA_CTRL */
#define OpAmp_Power_Amplifier_OA_PWR_MODE_MASK           (0x3u)
#define OpAmp_Power_Amplifier_OA_DRIVE_STR_SEL_MASK      (0x4u)
#define OpAmp_Power_Amplifier_OA_DRIVE_STR_SEL_10X       (0x4u)
#define OpAmp_Power_Amplifier_OA_PUMP_EN_MASK            (0x800u)
#define OpAmp_Power_Amplifier_OA_PUMP_CTRL_SHIFT         (11u)

#endif    /* CY_OPAMP_OpAmp_Power_Amplifier_H */


/* [] END OF FILE */
