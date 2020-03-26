/*******************************************************************************
* File Name: OpAmp_Power_Amplifier_PM.c
* Version 1.0
*
* Description:
*  This file provides the power management source code to the API for the
*  OpAmp (Analog Buffer) component.
*
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "OpAmp_Power_Amplifier.h"

static OpAmp_Power_Amplifier_BACKUP_STRUCT  OpAmp_Power_Amplifier_backup;


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration registers.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void OpAmp_Power_Amplifier_SaveConfig(void)
{
}


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration registers.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void OpAmp_Power_Amplifier_RestoreConfig(void)
{
}


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  OpAmp_Power_Amplifier_backup: The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void OpAmp_Power_Amplifier_Sleep(void)
{
    /* Save OpAmp enable state */
    if((OpAmp_Power_Amplifier_OA_RES_CTRL & OpAmp_Power_Amplifier_OA_PWR_MODE_MASK) != 0u)
    {
        /* Component is enabled */
        OpAmp_Power_Amplifier_backup.enableState = 1u;
        /* Stops the component */
        OpAmp_Power_Amplifier_Stop();
    }
    else
    {
        /* Component is disabled */
        OpAmp_Power_Amplifier_backup.enableState = 0u;
    }
    /* Saves the configuration */
    OpAmp_Power_Amplifier_SaveConfig();
}


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  OpAmp_Power_Amplifier_backup: The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void OpAmp_Power_Amplifier_Wakeup(void)
{
    /* Restore the user configuration */
    OpAmp_Power_Amplifier_RestoreConfig();

    /* Enables the component operation */
    if(OpAmp_Power_Amplifier_backup.enableState == 1u)
    {
        OpAmp_Power_Amplifier_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
