/*******************************************************************************
* File Name: OpAmp_Power_Amplifier.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for OpAmp (Analog Buffer)
*  Component.
*
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "OpAmp_Power_Amplifier.h"
#include <CyLib.h>

uint32 OpAmp_Power_Amplifier_initVar = 0u;


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  OpAmp_Power_Amplifier_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void OpAmp_Power_Amplifier_Init(void)
{
    /* Enable STB */
    OpAmp_Power_Amplifier_OA_CTRL |= ((uint32)1u << OpAmp_Power_Amplifier_OA_CTB_EN_SHIFT);
    OpAmp_Power_Amplifier_OA_RES_CTRL = 0u;
    OpAmp_Power_Amplifier_OA_COMP_TRIM_REG = OpAmp_Power_Amplifier_OA_COMP_TRIM_VALUE;
    #if(0u != OpAmp_Power_Amplifier_OUTPUT_CURRENT)
        /* 10 mA current */
        OpAmp_Power_Amplifier_OA_RES_CTRL |= OpAmp_Power_Amplifier_OA_DRIVE_STR_SEL_10X;
    #endif /* 0u != OpAmp_Power_Amplifier_OUTPUT_CURRENT */
}


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_Enable
********************************************************************************
*
* Summary:
*  Enables the OpAmp block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void OpAmp_Power_Amplifier_Enable(void)
{
    OpAmp_Power_Amplifier_OA_RES_CTRL &= (~(uint32)OpAmp_Power_Amplifier_OA_PWR_MODE_MASK);
    OpAmp_Power_Amplifier_OA_RES_CTRL |= OpAmp_Power_Amplifier_POWER | ((uint32)1u << OpAmp_Power_Amplifier_OA_PUMP_CTRL_SHIFT);
}


/*******************************************************************************
* Function Name:   OpAmp_Power_Amplifier_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Buffer with the default values and
*  sets the power to the given level. A power level of 0, is same as
*  executing the stop function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  OpAmp_Power_Amplifier_initVar: Used to check the initial configuration, modified
*  when this function is called for the first time.
*
*******************************************************************************/
void OpAmp_Power_Amplifier_Start(void)
{
    if(OpAmp_Power_Amplifier_initVar == 0u)
    {
        OpAmp_Power_Amplifier_initVar = 1u;
        OpAmp_Power_Amplifier_Init();
    }
    OpAmp_Power_Amplifier_Enable();
}


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void OpAmp_Power_Amplifier_Stop(void)
{
    OpAmp_Power_Amplifier_OA_RES_CTRL &= (~(uint32)(OpAmp_Power_Amplifier_OA_PWR_MODE_MASK |
        ((uint32)1u << OpAmp_Power_Amplifier_OA_PUMP_CTRL_SHIFT)));
}


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_SetPower
********************************************************************************
*
* Summary:
*  Sets power level of Analog buffer.
*
* Parameters:
*  power: Sets power level between low (1) and high power (3).
*
* Return:
*  None
*
**********************************************************************************/
void OpAmp_Power_Amplifier_SetPower(uint32 power)
{
    OpAmp_Power_Amplifier_OA_RES_CTRL &= (~(uint32)OpAmp_Power_Amplifier_OA_PWR_MODE_MASK);
    OpAmp_Power_Amplifier_OA_RES_CTRL |= (power & OpAmp_Power_Amplifier_OA_PWR_MODE_MASK);
}


/*******************************************************************************
* Function Name: OpAmp_Power_Amplifier_PumpControl
********************************************************************************
*
* Summary:
*  Turns the boost pump on or off.
*
* Parameters:
*  onOff: OpAmp_Power_Amplifier_PUMPON, OpAmp_Power_Amplifier_PUMPOFF.
*
* Return:
*  None
*
**********************************************************************************/
void OpAmp_Power_Amplifier_PumpControl(uint32 onOff)
{
    OpAmp_Power_Amplifier_OA_RES_CTRL &= (~(uint32)OpAmp_Power_Amplifier_OA_PUMP_EN_MASK);
    OpAmp_Power_Amplifier_OA_RES_CTRL |= ((onOff & OpAmp_Power_Amplifier_PUMP_PROTECT_MASK)
        << OpAmp_Power_Amplifier_OA_PUMP_CTRL_SHIFT);
}


/* [] END OF FILE */
