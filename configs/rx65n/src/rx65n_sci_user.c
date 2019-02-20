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
* File Name    : r_cg_sci_user.c
* Version      : Code Generator for RX65N V1.01.02.03 [08 May 2018]
* Device(s)    : R5F565N9AxFB
* Tool-Chain   : GCCRX
* Description  : This file implements device driver for SCI module.
* Creation Date: 12/31/2018
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
#include "rx65n_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "rx65n_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern uint8_t *gp_sci2_tx_address;                /* SCI2 send buffer address */
extern uint16_t g_sci2_tx_count;                   /* SCI2 send data number */
extern uint8_t *gp_sci2_rx_address;                /* SCI2 receive buffer address */
extern uint16_t g_sci2_rx_count;                   /* SCI2 receive data number */
extern uint16_t g_sci2_rx_length;                  /* SCI2 receive data length */
extern uint8_t *gp_sci7_tx_address;                /* SCI7 send buffer address */
extern uint16_t g_sci7_tx_count;                   /* SCI7 send data number */
/* Start user code for global. Do not edit comment generated here */
/* Global used to receive a character from the PC terminal */
uint8_t g_rx_char;
/* Flag used to control transmission to PC terminal */
volatile uint8_t g_tx_flag = FALSE;
/* Flag used locally to detect transmission complete */
static volatile uint8_t sci7_txdone;
static volatile uint8_t sci2_txdone;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_sci2_transmit_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_transmit_interrupt(void)
{
    if (0U < g_sci2_tx_count)
    {
        SCI2.TDR = *gp_sci2_tx_address;
        gp_sci2_tx_address++;
        g_sci2_tx_count--;
    }
    else
    {
        SCI2.SCR.BIT.TIE = 0U;
        SCI2.SCR.BIT.TEIE = 1U;
    }
}
/***********************************************************************************************************************
* Function Name: r_sci2_transmitend_interrupt
* Description  : This function is TEI2 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_transmitend_interrupt(void)
{
    /* Set TXD2 pin */
    PORT5.PMR.BYTE &= 0xFEU;

    SCI2.SCR.BIT.TIE = 0U;
    SCI2.SCR.BIT.TE = 0U;
    SCI2.SCR.BIT.TEIE = 0U;

    r_sci2_callback_transmitend();
}
/***********************************************************************************************************************
* Function Name: r_sci2_receive_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_receive_interrupt(void)
{
    if (g_sci2_rx_length > g_sci2_rx_count)
    {
        *gp_sci2_rx_address = SCI2.RDR;
        gp_sci2_rx_address++;
        g_sci2_rx_count++;
    }

    if (g_sci2_rx_length <= g_sci2_rx_count)
    {
        /* All data received */
        SCI2.SCR.BIT.RIE = 0U;
        SCI2.SCR.BIT.RE = 0U;
        r_sci2_callback_receiveend();
    }
}
/***********************************************************************************************************************
* Function Name: r_sci2_receiveerror_interrupt
* Description  : This function is ERI2 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_receiveerror_interrupt(void)
{
    uint8_t err_type;

    r_sci2_callback_receiveerror();

    /* Clear overrun, framing and parity error flags */
    err_type = SCI2.SSR.BYTE;
    err_type &= 0xC7U;
    err_type |= 0xC0U;
    SCI2.SSR.BYTE = err_type;
}
/***********************************************************************************************************************
* Function Name: r_sci2_callback_transmitend
* Description  : This function is a callback function when SCI2 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_callback_transmitend(void)
{
    /* Start user code. Do not edit comment generated here */
	sci2_txdone = TRUE;
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_sci2_callback_receiveend
* Description  : This function is a callback function when SCI2 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
	/* Check the contents of g_rx_char */
	if (('c' == g_rx_char) || ('C' == g_rx_char))
	{
	g_adc_trigger = TRUE;
	}
	/* Set up SCI2 receive buffer and callback function again */
	R_SCI2_Serial_Receive((uint8_t *)&g_rx_char, 1);
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_sci2_callback_receiveerror
* Description  : This function is a callback function when SCI2 reception encounters error.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_callback_receiveerror(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_sci7_transmit_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci7_transmit_interrupt(void)
{
    if (0U < g_sci7_tx_count)
    {
        SCI7.TDR = *gp_sci7_tx_address;
        gp_sci7_tx_address++;
        g_sci7_tx_count--;
    }
    else
    {
        SCI7.SCR.BIT.TIE = 0U;
        SCI7.SCR.BIT.TEIE = 1U;
    }
}
/***********************************************************************************************************************
* Function Name: r_sci7_transmitend_interrupt
* Description  : This function is TEI7 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci7_transmitend_interrupt(void)
{
    SCI7.SCR.BIT.TIE = 0U;
    SCI7.SCR.BIT.TEIE = 0U;

    /* Clear TE and RE bits */
    if(0U == SCI7.SCR.BIT.RIE)
    {
        SCI7.SCR.BYTE &= 0xCFU;
    }

    r_sci7_callback_transmitend();
}
/***********************************************************************************************************************
* Function Name: r_sci7_callback_transmitend
* Description  : This function is a callback function when SCI7 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci7_callback_transmitend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* Global used to receive a character from the PC terminal */
uint8_t g_rx_char;
/* Flag used to control transmission to PC terminal */
//volatile uint8_t g_tx_flag = FALSE;
/* Flag used locally to detect transmission complete */
static volatile uint8_t sci7_txdone;
static volatile uint8_t sci2_txdone;
/*******************************************************************************
* Function Name: R_SCI2_AsyncTransmit
* Description : This function sends SCI2 data and waits for the transmit end flag.
* Arguments : tx_buf -
* transfer buffer pointer
* tx_num -
* buffer size
* Return Value : status -
* MD_OK or MD_ARGERROR
*******************************************************************************/
MD_STATUS R_SCI2_AsyncTransmit (uint8_t * const tx_buf, const uint16_t tx_num)
{
MD_STATUS status = MD_OK;
/* clear the flag before initiating a new transmission */
sci2_txdone = FALSE;
/* Send the data using the API */
status = R_SCI2_Serial_Send(tx_buf, tx_num);
/* Wait for the transmit end flag */
while (FALSE == sci2_txdone)
{
/* Wait */
}
return (status);
}
/*******************************************************************************
* End of function R_SCI2_AsyncTransmit
*******************************************************************************/
/* End user code. Do not edit comment generated here */
