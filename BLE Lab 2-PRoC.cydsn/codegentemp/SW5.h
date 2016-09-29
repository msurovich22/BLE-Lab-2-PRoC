/*******************************************************************************
* File Name: SW5.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SW5_H) /* Pins SW5_H */
#define CY_PINS_SW5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SW5_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SW5_Write(uint8 value) ;
void    SW5_SetDriveMode(uint8 mode) ;
uint8   SW5_ReadDataReg(void) ;
uint8   SW5_Read(void) ;
uint8   SW5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SW5_DRIVE_MODE_BITS        (3)
#define SW5_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SW5_DRIVE_MODE_BITS))

#define SW5_DM_ALG_HIZ         (0x00u)
#define SW5_DM_DIG_HIZ         (0x01u)
#define SW5_DM_RES_UP          (0x02u)
#define SW5_DM_RES_DWN         (0x03u)
#define SW5_DM_OD_LO           (0x04u)
#define SW5_DM_OD_HI           (0x05u)
#define SW5_DM_STRONG          (0x06u)
#define SW5_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SW5_MASK               SW5__MASK
#define SW5_SHIFT              SW5__SHIFT
#define SW5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SW5_PS                     (* (reg32 *) SW5__PS)
/* Port Configuration */
#define SW5_PC                     (* (reg32 *) SW5__PC)
/* Data Register */
#define SW5_DR                     (* (reg32 *) SW5__DR)
/* Input Buffer Disable Override */
#define SW5_INP_DIS                (* (reg32 *) SW5__PC2)


#if defined(SW5__INTSTAT)  /* Interrupt Registers */

    #define SW5_INTSTAT                (* (reg32 *) SW5__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SW5_DRIVE_MODE_SHIFT       (0x00u)
#define SW5_DRIVE_MODE_MASK        (0x07u << SW5_DRIVE_MODE_SHIFT)


#endif /* End Pins SW5_H */


/* [] END OF FILE */
