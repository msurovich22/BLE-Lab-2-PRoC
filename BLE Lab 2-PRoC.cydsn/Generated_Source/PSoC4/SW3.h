/*******************************************************************************
* File Name: SW3.h  
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

#if !defined(CY_PINS_SW3_H) /* Pins SW3_H */
#define CY_PINS_SW3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SW3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SW3_Write(uint8 value) ;
void    SW3_SetDriveMode(uint8 mode) ;
uint8   SW3_ReadDataReg(void) ;
uint8   SW3_Read(void) ;
uint8   SW3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SW3_DRIVE_MODE_BITS        (3)
#define SW3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SW3_DRIVE_MODE_BITS))

#define SW3_DM_ALG_HIZ         (0x00u)
#define SW3_DM_DIG_HIZ         (0x01u)
#define SW3_DM_RES_UP          (0x02u)
#define SW3_DM_RES_DWN         (0x03u)
#define SW3_DM_OD_LO           (0x04u)
#define SW3_DM_OD_HI           (0x05u)
#define SW3_DM_STRONG          (0x06u)
#define SW3_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SW3_MASK               SW3__MASK
#define SW3_SHIFT              SW3__SHIFT
#define SW3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SW3_PS                     (* (reg32 *) SW3__PS)
/* Port Configuration */
#define SW3_PC                     (* (reg32 *) SW3__PC)
/* Data Register */
#define SW3_DR                     (* (reg32 *) SW3__DR)
/* Input Buffer Disable Override */
#define SW3_INP_DIS                (* (reg32 *) SW3__PC2)


#if defined(SW3__INTSTAT)  /* Interrupt Registers */

    #define SW3_INTSTAT                (* (reg32 *) SW3__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SW3_DRIVE_MODE_SHIFT       (0x00u)
#define SW3_DRIVE_MODE_MASK        (0x07u << SW3_DRIVE_MODE_SHIFT)


#endif /* End Pins SW3_H */


/* [] END OF FILE */
