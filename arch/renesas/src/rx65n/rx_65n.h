/************************************************************************************
 * arch/renesas/src/sh1/RX_703x.h
 *
 *   Copyright (C) 2008-2009 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_RENESAS_SRC_RX_65N_H
#define __ARCH_RENESAS_SRC_RX_65N_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Memory-mapped register addresses *************************************************/

/* Serial Communications interface (SCI) */

#define RX_SCI2_BASE       (0x0008A040)


#define RX_SCI_SMR_OFFSET  (0)  /* Serial Mode Register (8-bits wide) */
#define RX_SCI_BRR_OFFSET  (1)  /* Bit Rate Register (8-bits wide) */
#define RX_SCI_SCR_OFFSET  (2)  /* Serial Control Register (8-bits wide) */
#define RX_SCI_TDR_OFFSET  (3)  /* Transmit Data Register (8-bits wide) */
#define RX_SCI_SSR_OFFSET  (4)  /* Serial Status Register (8-bits wide) */
#define RX_SCI_RDR_OFFSET  (5)  /* Receive Data Register (8-bits wide) */

#define RX_SCI2_SMR        (RX_SCI2_BASE+RX_SCI_SMR_OFFSET)
#define RX_SCI2_BRR        (RX_SCI2_BASE+RX_SCI_BRR_OFFSET)
#define RX_SCI2_SCR        (RX_SCI2_BASE+RX_SCI_SCR_OFFSET)
#define RX_SCI2_TDR        (RX_SCI2_BASE+RX_SCI_TDR_OFFSET)
#define RX_SCI2_SSR        (RX_SCI2_BASE+RX_SCI_SSR_OFFSET)
#define RX_SCI2_RDR        (RX_SCI2_BASE+RX_SCI_RDR_OFFSET)




/* Serial Communications interface (SCI) */

#define RX_SCISMR_CKSMASK  (0x03)        /* Bit 0-1: Internal clock source */
#define RX_SCISMR_DIV1     (0x00)        /*   System clock (phi) */
#define RX_SCISMR_DIV4     (0x01)        /*   phi/4 */
#define RX_SCISMR_DIV16    (0x02)        /*   phi/16 */
#define RX_SCISMR_DIV64    (0x03)        /*   phi/64 */
#define RX_SCISMR_MP       (0x04)        /* Bit 2: Multiprocessor select */
#define RX_SCISMR_STOP     (0x08)        /* Bit 3: 0:One stop bit, 1:Two stop bits */
#define RX_SCISMR_OE       (0x10)        /* Bit 4: 0:Even parity, 1:Odd parity */
#define RX_SCISMR_PE       (0x20)        /* Bit 5: Parity enable */
#define RX_SCISMR_CHR      (0x40)        /* Bit 6: 0:8-bit data, 1:7-bit data */
#define RX_SCISMR_CA       (0x80)        /* Bit 7: 0:Asynchronous, 1:clocked synchronous */

#define RX_SCISCR_CKEMASK  (0x03)        /* Bit 0-1: Internal clock source */
                                          /* Asynchronous mode: */
#define RX_SCISCR_AISIN    (0x00)        /*   Internal clock, SCK pin used for input pin */
#define RX_SCISCR_AISOUT   (0x01)        /*   Internal clock, SCK pin used for clock output */
#define RX_SCISCR_AXSIN1   (0x02)        /*   External clock, SCK pin used for clock input */
#define RX_SCISCR_AXSIN2   (0x03)        /*   External clock, SCK pin used for clock input */
                                          /* Synchronous mode: */
#define RX_SCISCR_SISOUT1  (0x00)        /*   Internal clock, SCK pin used for input pin */
#define RX_SCISCR_SISOUT2  (0x01)        /*   Internal clock, SCK pin used for clock output */
#define RX_SCISCR_SXSIN1   (0x02)        /*   External clock, SCK pin used for clock input */
#define RX_SCISCR_SXSIN2   (0x03)        /*   External clock, SCK pin used for clock input */
#define RX_SCISCR_TEIE     (0x04)        /* Bit 2: 1=Transmit end interrupt enable */
#define RX_SCISCR_MPIE     (0x08)        /* Bit 3: 1=Multiprocessor interrupt enable */
#define RX_SCISCR_RE       (0x10)        /* Bit 4: 1=Receiver enable */
#define RX_SCISCR_TE       (0x20)        /* Bit 5: 1=Transmitter enable */
#define RX_SCISCR_RIE      (0x40)        /* Bit 6: 1=Recieve-data-full interrupt enable */
#define RX_SCISCR_TIE      (0x80)        /* Bit 7: 1=Transmit-data-empty interrupt enable */
#define RX_SCISCR_ALLINTS  (0xcc)

#define RX_SCISSR_MPBT     (0x01)        /* Bit 0: Multi-processor Bit in Transmit data */
#define RX_SCISSR_MPB      (0x02)        /* Bit 1: Multi-processor Bit in receive data */
#define RX_SCISSR_TEND     (0x04)        /* Bit 2: End of transmission */
#define RX_SCISSR_PER      (0x08)        /* Bit 3: Receive parity error */
#define RX_SCISSR_FER      (0x10)        /* Bit 4: Receive framing error */
#define RX_SCISSR_ORER     (0x20)        /* Bit 5: Receive overrun error */
#define RX_SCISSR_RDRF     (0x40)        /* Bit 6: RDR contains valid received data */
#define RX_SCISSR_TDRE     (0x80)        /* Bit 7: TDR does not contain valid transmit data */


#endif /* __ARCH_RENESAS_SRC_RX_65N_H */













