/*******************************************************************************
* File Name: SW4.h  
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

#if !defined(CY_PINS_SW4_H) /* Pins SW4_H */
#define CY_PINS_SW4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SW4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SW4_Write(uint8 value) ;
void    SW4_SetDriveMode(uint8 mode) ;
uint8   SW4_ReadDataReg(void) ;
uint8   SW4_Read(void) ;
uint8   SW4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SW4_DRIVE_MODE_BITS        (3)
#define SW4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SW4_DRIVE_MODE_BITS))

#define SW4_DM_ALG_HIZ         (0x00u)
#define SW4_DM_DIG_HIZ         (0x01u)
#define SW4_DM_RES_UP          (0x02u)
#define SW4_DM_RES_DWN         (0x03u)
#define SW4_DM_OD_LO           (0x04u)
#define SW4_DM_OD_HI           (0x05u)
#define SW4_DM_STRONG          (0x06u)
#define SW4_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SW4_MASK               SW4__MASK
#define SW4_SHIFT              SW4__SHIFT
#define SW4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SW4_PS                     (* (reg32 *) SW4__PS)
/* Port Configuration */
#define SW4_PC                     (* (reg32 *) SW4__PC)
/* Data Register */
#define SW4_DR                     (* (reg32 *) SW4__DR)
/* Input Buffer Disable Override */
#define SW4_INP_DIS                (* (reg32 *) SW4__PC2)


#if defined(SW4__INTSTAT)  /* Interrupt Registers */

    #define SW4_INTSTAT                (* (reg32 *) SW4__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SW4_DRIVE_MODE_SHIFT       (0x00u)
#define SW4_DRIVE_MODE_MASK        (0x07u << SW4_DRIVE_MODE_SHIFT)


#endif /* End Pins SW4_H */


/* [] END OF FILE */
