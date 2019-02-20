/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer 
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.    
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_rsk_switch.h
* Version      : 1.00
* Device(s)    : R5F565N9AxFB
* Tool-Chain   : CCRX
* H/W Platform : RSK+RX65N
* Description  : Provides declarations of functions defined in switch.c
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 30.06.2016 1.00     First Release
***********************************************************************************************************************/
/* Multiple inclusion prevention macro */
#ifndef SWITCH_H
#define SWITCH_H

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/* Switch 1 pressed flag mask */
#define SWITCHPRESS_1       (0x08u)

/* Switch 1 released flag mask */
#define SWITCHRELEASE_1     (0x80u)

/* Switch 2 pressed flag mask */
#define SWITCHPRESS_2       (0x04u)

/* Switch 2 released flag mask */
#define SWITCHRELEASE_2     (0x40u)

/* Switch 3 pressed flag mask */
#define SWITCHPRESS_3       (0x02u)

/* Switch 3 released flag mask */
#define SWITCHRELEASE_3     (0x20u)

/* Any switch pressed flag mask */
#define SWITCHPRESS_ALL     (0x0Eu)

/* Any switch held down flag mask */
#define SWITCHRELEASE_ALL   (0xE0u)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/* Switch flag global variable. Switch status bits:
        b7 : Switch 1 release flag*
        b6 : Switch 2 release flag*
        b5 : Switch 3 release flag*
        b4 : Unused
        b3 : Switch 1 pressed status flag
        b2 : Switch 2 pressed status flag
        b1 : Switch 3 pressed status flag
        b0 : Unused
         * Switch release flags must be cleared manually */
extern volatile uint8_t g_switch_flag;

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
/* Switch initialization function */
void R_SWITCH_Init(void);

/* Switch 1 interrupt callback function */
void R_SWITCH_IsrCallback1(void);

/* Switch 2 interrupt callback function */
void R_SWITCH_IsrCallback2(void);

/* All switch debounce interrupt callback function */
void R_SWITCH_DebounceIsrCallback(void);

/* Switch callback function initialization function prototype */
void R_SWITCH_SetPressCallback(void( *const callback)(void) );

/* Switch callback function initialization function prototype */
void R_SWITCH_SetReleaseCallback(void( *const callback)(void) );

/* Turns switch interrupts on/off */
void R_SWITCH_ControlInterrupts (const uint8_t control);

/* End of multiple inclusion prevention macro */
#endif

