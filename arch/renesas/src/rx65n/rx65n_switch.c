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
* File Name    : r_rsk_switch.c
* Version      : 1.00
* Device(s)    : R5F565N9AxFB
* Tool-Chain   : CCRX
* H/W Platform : RSK+RX65N
* Description  : Defines interrupt service routine functions for the switch
*                interrupts. De-bounces switch and sets a key press flag.
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 06.30.2016 1.00     First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Switch handler function definitions */
#include "rx65n_switch.h"

/* ICU function definitions */
#include "rx65n_icu.h"

/* CMT function definitions */
#include "rx65n_cmt.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/
/* Switch flag global variable */
volatile uint8_t g_switch_flag = 0x00;

/* Detected switch faults counter variable */
volatile uint16_t g_switch_faults_detected = 0;

/* Switch press callback pointer declaration */
void (*g_switch_press_callback_func)(void) = 0;

/* Switch release callback pointer declaration */
void (*g_switch_release_callback_func)(void) = 0;

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: R_SWITCH_Init
* Description  : Takes a pointer to a function, and sets it as the callback
*                function for the switch interrupts. The passed function is
*                executed every time any switch is pressed down.
* Arguments    : pointer to callback function (set to NULL to disable)
* Return Value : none
***********************************************************************************************************************/
void R_SWITCH_Init (void)
{
    /* Turn on the switch interrupts */
    R_SWITCH_ControlInterrupts(1);
}

/***********************************************************************************************************************
* End of function R_SWITCH_Init
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_SWITCH_SetPressCallback
* Description  : Takes a pointer to a function, and sets it as the callback
*                function for the switch interrupts. The passed function is
*                executed every time any switch is pressed down.
* Arguments    : pointer to callback function (set to NULL to disable)
* Return Value : none
***********************************************************************************************************************/
void R_SWITCH_SetPressCallback (void( *const callback)(void))
{
    /* Store the callback function pointer into the global variable */
    g_switch_press_callback_func = callback;
}

/***********************************************************************************************************************
* End of function R_SWITCH_SetPressCallback
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_SWITCH_SetReleaseCallback
* Description  : Takes a pointer to a function, and sets it as the callback
*                function for the switch interrupts. The passed function is
*                executed every time any switch is released. Note that switch
*                release functionality is not provided for SW3.
* Arguments    : pointer to callback function (set to NULL to disable)
* Return Value : none
***********************************************************************************************************************/
void R_SWITCH_SetReleaseCallback (void( *const callback)(void))
{
    /* Store the callback function pointer into the global variable */
    g_switch_release_callback_func = callback;
}

/***********************************************************************************************************************
* End of function R_SWITCH_SetReleaseCallback
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: R_SWITCH_IsrCallback1
* Description  : Switch 1 callback ISR function. The function disables switch
*                interrupts, then uses the debounce timer to re-enable them
*                after the debounce period finishes.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SWITCH_IsrCallback1 (void)
{
    /* Disable switch 1 interrupts */
    R_ICU_IRQ8_Stop();
                       
    /* Check if interrupt was generated by falling edge */
    if (1 == R_ICU_IRQIsFallingEdge(8U))
    {
        /* Start short debounce timer */
        R_CMT1_Start();
        
        /* Set detection direction as rising edge */
        R_ICU_IRQSetFallingEdge(8U, 0U);
        R_ICU_IRQSetRisingEdge(8U, 1);

        /* Set global switch flag to indicate SW1 is pressed */
        g_switch_flag |= SWITCHPRESS_1;
    }
    else
    {   
        /* Start long debounce timer */
    R_CMT2_Start();
            
        /* Set detection direction to falling edge */
        R_ICU_IRQSetFallingEdge(8U, 1);
        R_ICU_IRQSetRisingEdge(8U, 0);
        
        /* Clear SW1 held-down flag bit in switch flag */
        /* Type cast required to remove warning for 
            Conversion may lose significant digits */ 
        g_switch_flag &= (uint8_t) ~SWITCHPRESS_1;
        
        /* Set global switch flag to indicate SW1 released */
        g_switch_flag |= SWITCHRELEASE_1;
    
        /* Check if switch release callback function is not NULL */
        if (g_switch_release_callback_func)
        {
            /* Execute user callback function */
            g_switch_release_callback_func();
        }
    }
}

/***********************************************************************************************************************
* End of function R_SWITCH_IsrCallback1
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_SWITCH_IsrCallback2
* Description  : Switch 2 callback ISR function. The function disables switch
*                interrupts, then uses the debounce timer to re-enable them
*                after the debounce period finishes.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SWITCH_IsrCallback2 (void)
{
    /* Disable switch 2 interrupts */
    R_ICU_IRQ9_Stop();

    /* Check if interrupt was generated by falling edge */
    if (1 == R_ICU_IRQIsFallingEdge(9U))
    {
        /* Start short debounce timer */
        R_CMT1_Start();

        /* Set detection direction as rising edge */
        R_ICU_IRQSetFallingEdge(9U, 0U);
        R_ICU_IRQSetRisingEdge(9U, 1);

        /* Set global switch flag to indicate SW2 is pressed */
        g_switch_flag |= SWITCHPRESS_2;
}
    else
    {
        /* Start long debounce timer */
        R_CMT2_Start();

        /* Set detection direction to falling edge */
        R_ICU_IRQSetFallingEdge(9U, 1);
        R_ICU_IRQSetRisingEdge(9U, 0);

        /* Clear SW2 held-down flag bit in switch flag */
        /* Type cast required to remove warning for
            Conversion may lose significant digits */
        g_switch_flag &= (uint8_t) ~SWITCHPRESS_2;

        /* Set global switch flag to indicate SW2 released */
        g_switch_flag |= SWITCHRELEASE_2;

        /* Check if switch release callback function is not NULL */
        if (g_switch_release_callback_func)
        {
            /* Execute user callback function */
            g_switch_release_callback_func();
        }
    }
}

/***********************************************************************************************************************
* End of function R_SWITCH_IsrCallback2
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: R_SWITCH_DebounceIsrCallback
* Description  : Switch debounce timer callback function. Function is executed
*                by the timer ISR used for debounce. Function re-enables all
*                switch interrupts; then verifies a correct switch press was
*                detected, and calls the user switch press callback function.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SWITCH_DebounceIsrCallback (void)
{
    /* Clear IRQ8 interrupt flag */
    IR(ICU, IRQ8) = 0;

    /* Re-enable switch 1 interrupts */
    R_ICU_IRQ8_Start();

    /* Clear IRQ9 interrupt flag */
    IR(ICU, IRQ9) = 0;

    /* Re-enable switch 2 interrupts */
    R_ICU_IRQ9_Start();

    /* Check if switch 1 hold flag is set */
    if ((g_switch_flag & 0x0F) & ((SWITCHPRESS_1 | SWITCHPRESS_2) | SWITCHPRESS_3))
    {
       /* Check if switch press callback function is not NULL */
        if (g_switch_press_callback_func)
        {
            /* Execute user callback function */
            g_switch_press_callback_func();
        }
    }
}

/***********************************************************************************************************************
* End of function R_SWITCH_DebounceIsrCallback
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_SWITCH_ControlInterrupts
* Description  : Enables or disables the switch IRQ interrupts, based on the
*                input variable, control.
* Arguments    : uint8_t - 0x1  : Enables switch interrupts.
*                          0x0  : Disables switch interrupts.
* Return Value : none
***********************************************************************************************************************/
void R_SWITCH_ControlInterrupts (const uint8_t control)
{
    /* Check if control input is 0x1 */
    if (control)
    {
        /* Enable SW1 interrupt requests */
        R_ICU_IRQ8_Start();

        /* Enable SW2 interrupt requests */
        R_ICU_IRQ9_Start();

    }
    else
    {
        /* Control input is 0x0 */

        /* Disable SW1 interrupts */
        R_ICU_IRQ8_Stop();

        /* Disable SW2 interrupts */
        R_ICU_IRQ9_Stop();

    }
}

/***********************************************************************************************************************
* End of function R_SWITCH_ControlInterrupts
***********************************************************************************************************************/



