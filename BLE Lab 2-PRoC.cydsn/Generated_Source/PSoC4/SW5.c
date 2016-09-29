/*******************************************************************************
* File Name: SW5.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SW5.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SW5_PC =   (SW5_PC & \
                                (uint32)(~(uint32)(SW5_DRIVE_MODE_IND_MASK << (SW5_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SW5_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SW5_Write
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
void SW5_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SW5_DR & (uint8)(~SW5_MASK));
    drVal = (drVal | ((uint8)(value << SW5_SHIFT) & SW5_MASK));
    SW5_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SW5_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SW5_DM_STRONG     Strong Drive 
*  SW5_DM_OD_HI      Open Drain, Drives High 
*  SW5_DM_OD_LO      Open Drain, Drives Low 
*  SW5_DM_RES_UP     Resistive Pull Up 
*  SW5_DM_RES_DWN    Resistive Pull Down 
*  SW5_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SW5_DM_DIG_HIZ    High Impedance Digital 
*  SW5_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SW5_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SW5__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SW5_Read
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
*  Macro SW5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SW5_Read(void) 
{
    return (uint8)((SW5_PS & SW5_MASK) >> SW5_SHIFT);
}


/*******************************************************************************
* Function Name: SW5_ReadDataReg
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
uint8 SW5_ReadDataReg(void) 
{
    return (uint8)((SW5_DR & SW5_MASK) >> SW5_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SW5_INTSTAT) 

    /*******************************************************************************
    * Function Name: SW5_ClearInterrupt
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
    uint8 SW5_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SW5_INTSTAT & SW5_MASK);
		SW5_INTSTAT = maskedStatus;
        return maskedStatus >> SW5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
