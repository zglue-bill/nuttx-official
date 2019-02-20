/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2018 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_tmr.c
* Version      : Code Generator for RX65N V1.01.02.03 [08 May 2018]
* Device(s)    : R5F565N9AxFB
* Tool-Chain   : GCCRX
* Description  : This file implements device driver for TMR module.
* Creation Date: 11-01-2019
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"
#include "rx65n_tmr.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "rx65n_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TMR_Create
* Description  : This function initializes the TMR module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_Create(void)
{
    /* Cancel TMR module stop state */
    MSTP(TMR01) = 0U;
    MSTP(TMR23) = 0U;

    /* Set counter clear and interrupt */
    TMR0.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _08_TMR_CNT_CLR_COMP_MATCH_A;

    /* Set A/D trigger and output */
    TMR0.TCSR.BYTE = _00_TMR_AD_TRIGGER_DISABLE | _E0_TMR02_TCSR_DEFAULT;

    /* Set compare match value */
    TMR0.TCORA = _EF_TMR0_COMP_MATCH_VALUE_A;
    TMR0.TCORB = _BF_TMR0_COMP_MATCH_VALUE_B;

    R_TMR0_Start();
    R_TMR0_Stop();
    /* Set counter clear and interrupt */
    TMR1.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _00_TMR_CNT_CLR_DISABLE;

    /* Set compare match value */
    TMR1.TCORA = _BF_TMR1_COMP_MATCH_VALUE_A;
    TMR1.TCORB = _BF_TMR1_COMP_MATCH_VALUE_B;

    /* Set counter clear and interrupt */
    TMR2.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _00_TMR_CNT_CLR_DISABLE;

    /* Set A/D trigger and output */
    TMR2.TCSR.BYTE = _00_TMR_AD_TRIGGER_DISABLE | _E0_TMR02_TCSR_DEFAULT;

    /* Set compare match value */
    TMR2.TCORA = _EF_TMR2_COMP_MATCH_VALUE_A;
    TMR2.TCORB = _BF_TMR2_COMP_MATCH_VALUE_B;

    /* Set counter clear and interrupt */
    TMR3.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _00_TMR_CNT_CLR_DISABLE;

    /* Set compare match value */
    TMR3.TCORA = _EF_TMR3_COMP_MATCH_VALUE_A;
    TMR3.TCORB = _BF_TMR3_COMP_MATCH_VALUE_B;
}
/***********************************************************************************************************************
* Function Name: R_TMR0_Start
* Description  : This function starts TMR0 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR0_Start(void)
{
    /* Start counting */
    TMR0.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR0_Stop
* Description  : This function stops TMR0 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR0_Stop(void)
{
    /* Stop counting */
    TMR0.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_TMR1_Start
* Description  : This function starts TMR1 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR1_Start(void)
{
    /* Start counting */
    TMR1.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR1_Stop
* Description  : This function stops TMR1 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR1_Stop(void)
{
    /* Stop counting */
    TMR1.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_TMR2_Start
* Description  : This function starts TMR2 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR2_Start(void)
{
    /* Start counting */
    TMR2.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR2_Stop
* Description  : This function stops TMR2 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR2_Stop(void)
{
    /* Stop counting */
    TMR2.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_TMR3_Start
* Description  : This function starts TMR3 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR3_Start(void)
{
    /* Start counting */
    TMR3.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR3_Stop
* Description  : This function stops TMR3 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR3_Stop(void)
{
    /* Stop counting */
    TMR3.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
