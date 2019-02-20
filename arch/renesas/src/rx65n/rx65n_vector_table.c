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
* File Name    : r_cg_vector_table.c
* Version      : Code Generator for RX65N V1.01.02.03 [08 May 2018]
* Device(s)    : R5F565N9AxFB
* Tool-Chain   : GCCRX
* Description  : This file implements interrupt vector.
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
#include "rx65n_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
typedef void (*fp) (void);
extern void PowerON_Reset (void);
extern void stack (void);

#define EXVECT_SECT    __attribute__ ((section (".exvectors")))

const void *ExceptVectors[] EXVECT_SECT  = {
    /* 0xffffff80  Reserved */
    r_reserved_exception,
    /* 0xffffff84  Reserved */
    r_reserved_exception,
    /* 0xffffff88  Reserved */
    r_reserved_exception,
    /* 0xffffff8C  Reserved */
    r_reserved_exception,
    /* 0xffffff90  Reserved */
    r_reserved_exception,
    /* 0xffffff94  Reserved */
    r_reserved_exception,
    /* 0xffffff98  Reserved */
    r_reserved_exception,
    /* 0xffffff9C  Reserved */
    r_reserved_exception,
    /* 0xffffffA0  Reserved */
    r_reserved_exception,
    /* 0xffffffA4  Reserved */
    r_reserved_exception,
    /* 0xffffffA8  Reserved */
    r_reserved_exception,
    /* 0xffffffAC  Reserved */
    r_reserved_exception,
    /* 0xffffffB0  Reserved */
    r_reserved_exception,
    /* 0xffffffB4  Reserved */
    r_reserved_exception,
    /* 0xffffffB8  Reserved */
    r_reserved_exception,
    /* 0xffffffBC  Reserved */
    r_reserved_exception,
    /* 0xffffffC0  Reserved */
    r_reserved_exception,
    /* 0xffffffC4  Reserved */
    r_reserved_exception,
    /* 0xffffffC8  Reserved */
    r_reserved_exception,
    /* 0xffffffCC  Reserved */
    r_reserved_exception,
    /* 0xffffffd0  Exception(Supervisor Instruction) */
    r_privileged_exception,
    /* 0xffffffd4  Exception(Access Instruction) */
    r_access_exception,
    /* 0xffffffd8  Reserved */
    r_reserved_exception,
    /* 0xffffffdc  Exception(Undefined Instruction) */
    r_undefined_exception,
    /* 0xffffffe0  Reserved */
    r_reserved_exception,
    /* 0xffffffe4  Exception(Floating Point) */
    r_floatingpoint_exception,
    /* 0xffffffe8  Reserved */
    r_undefined_exception,
    /* 0xffffffec  Reserved */
    r_undefined_exception,
    /* 0xfffffff0  Reserved */
    r_undefined_exception,
    /* 0xfffffff4  Reserved */
    r_undefined_exception,
    /* 0xfffffff8  NMI */
    r_nmi_exception
};

#define FVECT_SECT    __attribute__ ((section (".fvectors")))
const void *HardwareVectors[] FVECT_SECT  = {
    /* 0xfffffffc  RESET */
    /* <<VECTOR DATA START (POWER ON RESET)>> */
    /* Power On Reset PC */
    PowerON_Reset
    /* <<VECTOR DATA END (POWER ON RESET)>> */
};

#define RVECT_SECT __attribute__ ((section (".rvectors")))

const fp RelocatableVectors[] RVECT_SECT  = {
    /* 0x0000  Reserved */
    (fp)r_reserved_exception,
    /* 0x0004  Reserved */
    (fp)r_reserved_exception,
    /* 0x0008  Reserved */
    (fp)r_reserved_exception,
    /* 0x000C  Reserved */
    (fp)r_reserved_exception,
    /* 0x0010  Reserved */
    (fp)r_reserved_exception,
    /* 0x0014  Reserved */
    (fp)r_reserved_exception,
    /* 0x0018  Reserved */
    (fp)r_reserved_exception,
    /* 0x001C  Reserved */
    (fp)r_reserved_exception,
    /* 0x0020  Reserved */
    (fp)r_reserved_exception,
    /* 0x0024  Reserved */
    (fp)r_reserved_exception,
    /* 0x0028  Reserved */
    (fp)r_reserved_exception,
    /* 0x002C  Reserved */
    (fp)r_reserved_exception,
    /* 0x0030  Reserved */
    (fp)r_reserved_exception,
    /* 0x0034  Reserved */
    (fp)r_reserved_exception,
    /* 0x0038  Reserved */
    (fp)r_reserved_exception,
    /* 0x003C  Reserved */
    (fp)r_reserved_exception,
    /* 0x0040  BSC BUSERR */
    (fp)r_undefined_exception,
    /* 0x0044  Reserved */
    (fp)r_reserved_exception,
    /* 0x0048  RAM RAMERR */
    (fp)r_undefined_exception,
    /* 0x004C  Reserved */
    (fp)r_reserved_exception,
    /* 0x0050  Reserved */
    (fp)r_reserved_exception,
    /* 0x0054  FCU FIFERR */
    (fp)r_undefined_exception,
    /* 0x0058  Reserved */
    (fp)r_reserved_exception,
    /* 0x005C  FCU FRDYI */
    (fp)r_undefined_exception,
    /* 0x0060  Reserved */
    (fp)r_reserved_exception,
    /* 0x0064  Reserved */
    (fp)r_reserved_exception,
    /* 0x0068  ICU SWINT2 */
    (fp)r_undefined_exception,
    /* 0x006C  ICU SWINT */
    (fp)r_undefined_exception,
    /* 0x0070  CMT0 CMI0 */
    (fp)r_cmt_cmi0_interrupt,
    /* 0x0074  CMT1 CMI1 */
    (fp)r_cmt_cmi1_interrupt,
    /* 0x0078  CMTW0 CMWI0 */
    (fp)r_undefined_exception,
    /* 0x007C  CMTW1 CMWI1 */
    (fp)r_undefined_exception,
    /* 0x0080  Reserved */
    (fp)r_reserved_exception,
    /* 0x0084  Reserved */
    (fp)r_reserved_exception,
    /* 0x0088  USB0 D0FIFO0 */
    (fp)r_undefined_exception,
    /* 0x008C  USB0 D1FIFO0 */
    (fp)r_undefined_exception,
    /* 0x0090  Reserved */
    (fp)r_reserved_exception,
    /* 0x0094  Reserved */
    (fp)r_reserved_exception,
    /* 0x0098  RSPI0 SPRI0 */
    (fp)r_undefined_exception,
    /* 0x009C  RSPI0 SPTI0 */
    (fp)r_undefined_exception,
    /* 0x00A0  RSPI1 SPRI1 */
    (fp)r_undefined_exception,
    /* 0x00A4  RSPI1 SPTI1 */
    (fp)r_undefined_exception,
    /* 0x00A8  QSPI SPRI */
    (fp)r_undefined_exception,
    /* 0x00AC  QSPI SPTI */
    (fp)r_undefined_exception,
    /* 0x00B0  SDHI SBFAI */
    (fp)r_undefined_exception,
    /* 0x00B4  MMCIF MBFAI */
    (fp)r_undefined_exception,
    /* 0x00B8  Reserved */
    (fp)r_reserved_exception,
    /* 0x00BC  Reserved */
    (fp)r_reserved_exception,
    /* 0x00C0  Reserved */
    (fp)r_reserved_exception,
    /* 0x00C4  Reserved */
    (fp)r_reserved_exception,
    /* 0x00C8  Reserved */
    (fp)r_reserved_exception,
    /* 0x00CC  Reserved */
    (fp)r_reserved_exception,
    /* 0x00D0  RIIC0 RXI0 */
    (fp)r_undefined_exception,
    /* 0x00D4  RIIC0 TXI0 */
    (fp)r_undefined_exception,
    /* 0x00D8  RIIC2 RXI2 */
    (fp)r_undefined_exception,
    /* 0x00DC  RIIC2 TXI2 */
    (fp)r_undefined_exception,
    /* 0x00E0  Reserved */
    (fp)r_reserved_exception,
    /* 0x00E4  Reserved */
    (fp)r_reserved_exception,
    /* 0x00E8  SCI0 RXI0 */
    (fp)r_undefined_exception,
    /* 0x00EC  SCI0 TXI0 */
    (fp)r_undefined_exception,
    /* 0x00F0  SCI1 RXI1 */
    (fp)r_undefined_exception,
    /* 0x00F4  SCI1 TXI1 */
    (fp)r_undefined_exception,
    /* 0x00F8  SCI2 RXI2 */
    (fp)r_sci2_receive_interrupt,
    /* 0x00FC  SCI2 TXI2 */
    (fp)r_sci2_transmit_interrupt,
    /* 0x0100  ICU IRQ0 */
    (fp)r_undefined_exception,
    /* 0x0104  ICU IRQ1 */
    (fp)r_undefined_exception,
    /* 0x0108  ICU IRQ2 */
    (fp)r_undefined_exception,
    /* 0x010C  ICU IRQ3 */
    (fp)r_undefined_exception,
    /* 0x0110  ICU IRQ4 */
    (fp)r_undefined_exception,
    /* 0x0114  ICU IRQ5 */
    (fp)r_undefined_exception,
    /* 0x0118  ICU IRQ6 */
    (fp)r_undefined_exception,
    /* 0x011C  ICU IRQ7 */
    (fp)r_undefined_exception,
    /* 0x0120  ICU IRQ8 */
    (fp)r_icu_irq8_interrupt,
    /* 0x0124  ICU IRQ9 */
    (fp)r_icu_irq9_interrupt,
    /* 0x0128  ICU IRQ10 */
    (fp)r_undefined_exception,
    /* 0x012C  ICU IRQ11 */
    (fp)r_undefined_exception,
    /* 0x0130  ICU IRQ12 */
    (fp)r_undefined_exception,
    /* 0x0134  ICU IRQ13 */
    (fp)r_undefined_exception,
    /* 0x0138  ICU IRQ14 */
    (fp)r_undefined_exception,
    /* 0x013C  ICU IRQ15 */
    (fp)r_undefined_exception,
    /* 0x0140  SCI3 RXI3 */
    (fp)r_undefined_exception,
    /* 0x0144  SCI3 TXI3 */
    (fp)r_undefined_exception,
    /* 0x0148  SCI4 RXI4 */
    (fp)r_undefined_exception,
    /* 0x014C  SCI4 TXI4 */
    (fp)r_undefined_exception,
    /* 0x0150  SCI5 RXI5 */
    (fp)r_undefined_exception,
    /* 0x0154  SCI5 TXI5 */
    (fp)r_undefined_exception,
    /* 0x0158  SCI6 RXI6 */
    (fp)r_undefined_exception,
    /* 0x015C  SCI6 TXI6 */
    (fp)r_undefined_exception,
    /* 0x0160  LVD LVD1 */
    (fp)r_undefined_exception,
    /* 0x0164  LVD LVD2 */
    (fp)r_undefined_exception,
    /* 0x0168  USB0 USBR0 */
    (fp)r_undefined_exception,
    /* 0x016C  Reserved */
    (fp)r_reserved_exception,
    /* 0x0170  RTC ALM */
    (fp)r_undefined_exception,
    /* 0x0174  RTC PRD */
    (fp)r_undefined_exception,
    /* 0x0178  Reserved */
    (fp)r_reserved_exception,
    /* 0x017C  IWDT IWUNI */
    (fp)r_undefined_exception,
    /* 0x0180  WDT WUNI */
    (fp)r_undefined_exception,
    /* 0x0184  PDC PCDFI */
    (fp)r_undefined_exception,
    /* 0x0188  SCI7 RXI7 */
    (fp)r_undefined_exception,
    /* 0x018C  SCI7 TXI7 */
    (fp)r_sci7_transmit_interrupt,
    /* 0x0190  SCI8 RXI8 */
    (fp)r_undefined_exception,
    /* 0x0194  SCI8 TXI8 */
    (fp)r_undefined_exception,
    /* 0x0198  SCI9 RXI9 */
    (fp)r_undefined_exception,
    /* 0x019C  SCI9 TXI9 */
    (fp)r_undefined_exception,
    /* 0x01A0  SCI10 RXI10 */
    (fp)r_undefined_exception,
    /* 0x01A4  SCI10 TXI10 */
    (fp)r_undefined_exception,
    /* 0x01A8  ICU GROUP_BE0 */
    (fp)r_icu_group_be0_interrupt,
    /* 0x01AC  ICU GROUP_BL2 */
    (fp)r_icu_group_bl2_interrupt,
    /* 0x01B0  RSPI2 SPRI2 */
    (fp)r_undefined_exception,
    /* 0x01B4  RSPI2 SPTI2 */
    (fp)r_undefined_exception,
    /* 0x01B8  ICU GROUP_BL0 */
    (fp)r_icu_group_bl0_interrupt,
    /* 0x01BC  ICU GROUP_BL1 */
    (fp)r_icu_group_bl1_interrupt,
    /* 0x01C0  ICU GROUP_AL0 */
    (fp)r_icu_group_al0_interrupt,
    /* 0x01C4  ICU GROUP_AL1 */
    (fp)r_icu_group_al1_interrupt,
    /* 0x01C8  SCI11 RXI11 */
    (fp)r_undefined_exception,
    /* 0x01CC  SCI11 TXI11 */
    (fp)r_undefined_exception,
    /* 0x01D0  SCI12 RXI12 */
    (fp)r_undefined_exception,
    /* 0x01D4  SCI12 TXI12 */
    (fp)r_undefined_exception,
    /* 0x01D8  Reserved */
    (fp)r_reserved_exception,
    /* 0x01DC  Reserved */
    (fp)r_reserved_exception,
    /* 0x01E0  DMAC DMAC0I */
    (fp)r_undefined_exception,
    /* 0x01E4  DMAC DMAC1I */
    (fp)r_undefined_exception,
    /* 0x01E8  DMAC DMAC2I */
    (fp)r_undefined_exception,
    /* 0x01EC  DMAC DMAC3I */
    (fp)r_undefined_exception,
    /* 0x01F0  DMAC DMAC74I */
    (fp)r_undefined_exception,
    /* 0x01F4  OST OSTDI */
    (fp)r_undefined_exception,
    /* 0x01F8  EXDMAC EXDMAC0I */
    (fp)r_undefined_exception,
    /* 0x01FC  EXDMAC EXDMAC1I */
    (fp)r_undefined_exception,
    /* 0x0200  PERIB INTB128 */
    (fp)r_cmt_cmi2_interrupt,
    /* 0x0204  PERIB INTB129 */
    (fp)r_s12ad0_interrupt,
    /* 0x0208  PERIB INTB130 */
    (fp)r_undefined_exception,
    /* 0x020C  PERIB INTB131 */
    (fp)r_undefined_exception,
    /* 0x0210  PERIB INTB132 */
    (fp)r_undefined_exception,
    /* 0x0214  PERIB INTB133 */
    (fp)r_undefined_exception,
    /* 0x0218  PERIB INTB134 */
    (fp)r_undefined_exception,
    /* 0x021C  PERIB INTB135 */
    (fp)r_undefined_exception,
    /* 0x0220  PERIB INTB136 */
    (fp)r_undefined_exception,
    /* 0x0224  PERIB INTB137 */
    (fp)r_undefined_exception,
    /* 0x0228  PERIB INTB138 */
    (fp)r_undefined_exception,
    /* 0x022C  PERIB INTB139 */
    (fp)r_undefined_exception,
    /* 0x0230  PERIB INTB140 */
    (fp)r_undefined_exception,
    /* 0x0234  PERIB INTB141 */
    (fp)r_undefined_exception,
    /* 0x0238  PERIB INTB142 */
    (fp)r_undefined_exception,
    /* 0x023C  PERIB INTB143 */
    (fp)r_undefined_exception,
    /* 0x0240  PERIB INTB144 */
    (fp)r_undefined_exception,
    /* 0x0244  PERIB INTB145 */
    (fp)r_undefined_exception,
    /* 0x0248  PERIB INTB146 */
    (fp)r_undefined_exception,
    /* 0x024C  PERIB INTB147 */
    (fp)r_undefined_exception,
    /* 0x0250  PERIB INTB148 */
    (fp)r_undefined_exception,
    /* 0x0254  PERIB INTB149 */
    (fp)r_undefined_exception,
    /* 0x0258  PERIB INTB150 */
    (fp)r_undefined_exception,
    /* 0x025C  PERIB INTB151 */
    (fp)r_undefined_exception,
    /* 0x0260  PERIB INTB152 */
    (fp)r_undefined_exception,
    /* 0x0264  PERIB INTB153 */
    (fp)r_undefined_exception,
    /* 0x0268  PERIB INTB154 */
    (fp)r_undefined_exception,
    /* 0x026C  PERIB INTB155 */
    (fp)r_undefined_exception,
    /* 0x0270  PERIB INTB156 */
    (fp)r_undefined_exception,
    /* 0x0274  PERIB INTB157 */
    (fp)r_undefined_exception,
    /* 0x0278  PERIB INTB158 */
    (fp)r_undefined_exception,
    /* 0x027C  PERIB INTB159 */
    (fp)r_undefined_exception,
    /* 0x0280  PERIB INTB160 */
    (fp)r_undefined_exception,
    /* 0x0284  PERIB INTB161 */
    (fp)r_undefined_exception,
    /* 0x0288  PERIB INTB162 */
    (fp)r_undefined_exception,
    /* 0x028C  PERIB INTB163 */
    (fp)r_undefined_exception,
    /* 0x0290  PERIB INTB164 */
    (fp)r_undefined_exception,
    /* 0x0294  PERIB INTB165 */
    (fp)r_undefined_exception,
    /* 0x0298  PERIB INTB166 */
    (fp)r_undefined_exception,
    /* 0x029C  PERIB INTB167 */
    (fp)r_undefined_exception,
    /* 0x02A0  PERIB INTB168 */
    (fp)r_undefined_exception,
    /* 0x02A4  PERIB INTB169 */
    (fp)r_undefined_exception,
    /* 0x02A8  PERIB INTB170 */
    (fp)r_undefined_exception,
    /* 0x02AC  PERIB INTB171 */
    (fp)r_undefined_exception,
    /* 0x02B0  PERIB INTB172 */
    (fp)r_undefined_exception,
    /* 0x02B4  PERIB INTB173 */
    (fp)r_undefined_exception,
    /* 0x02B8  PERIB INTB174 */
    (fp)r_undefined_exception,
    /* 0x02BC  PERIB INTB175 */
    (fp)r_undefined_exception,
    /* 0x02C0  PERIB INTB176 */
    (fp)r_undefined_exception,
    /* 0x02C4  PERIB INTB177 */
    (fp)r_undefined_exception,
    /* 0x02C8  PERIB INTB178 */
    (fp)r_undefined_exception,
    /* 0x02CC  PERIB INTB179 */
    (fp)r_undefined_exception,
    /* 0x02D0  PERIB INTB180 */
    (fp)r_undefined_exception,
    /* 0x02D4  PERIB INTB181 */
    (fp)r_undefined_exception,
    /* 0x02D8  PERIB INTB182 */
    (fp)r_undefined_exception,
    /* 0x02DC  PERIB INTB183 */
    (fp)r_undefined_exception,
    /* 0x02E0  PERIB INTB184 */
    (fp)r_undefined_exception,
    /* 0x02E4  PERIB INTB185 */
    (fp)r_undefined_exception,
    /* 0x02E8  PERIB INTB186 */
    (fp)r_undefined_exception,
    /* 0x02EC  PERIB INTB187 */
    (fp)r_undefined_exception,
    /* 0x02F0  PERIB INTB188 */
    (fp)r_undefined_exception,
    /* 0x02F4  PERIB INTB189 */
    (fp)r_undefined_exception,
    /* 0x02F8  PERIB INTB190 */
    (fp)r_undefined_exception,
    /* 0x02FC  PERIB INTB191 */
    (fp)r_undefined_exception,
    /* 0x0300  PERIB INTB192 */
    (fp)r_undefined_exception,
    /* 0x0304  PERIB INTB193 */
    (fp)r_undefined_exception,
    /* 0x0308  PERIB INTB194 */
    (fp)r_undefined_exception,
    /* 0x030C  PERIB INTB195 */
    (fp)r_undefined_exception,
    /* 0x0310  PERIB INTB196 */
    (fp)r_undefined_exception,
    /* 0x0314  PERIB INTB197 */
    (fp)r_undefined_exception,
    /* 0x0318  PERIB INTB198 */
    (fp)r_undefined_exception,
    /* 0x031C  PERIB INTB199 */
    (fp)r_undefined_exception,
    /* 0x0320  PERIB INTB200 */
    (fp)r_undefined_exception,
    /* 0x0324  PERIB INTB201 */
    (fp)r_undefined_exception,
    /* 0x0328  PERIB INTB202 */
    (fp)r_undefined_exception,
    /* 0x032C  PERIB INTB203 */
    (fp)r_undefined_exception,
    /* 0x0330  PERIB INTB204 */
    (fp)r_undefined_exception,
    /* 0x0334  PERIB INTB205 */
    (fp)r_undefined_exception,
    /* 0x0338  PERIB INTB206 */
    (fp)r_undefined_exception,
    /* 0x033C  PERIB INTB207 */
    (fp)r_undefined_exception,
    /* 0x0340  PERIA INTA208 */
    (fp)r_undefined_exception,
    /* 0x0344  PERIA INTA209 */
    (fp)r_undefined_exception,
    /* 0x0348  PERIA INTA210 */
    (fp)r_undefined_exception,
    /* 0x034C  PERIA INTA211 */
    (fp)r_undefined_exception,
    /* 0x0350  PERIA INTA212 */
    (fp)r_undefined_exception,
    /* 0x0354  PERIA INTA213 */
    (fp)r_undefined_exception,
    /* 0x0358  PERIA INTA214 */
    (fp)r_undefined_exception,
    /* 0x035C  PERIA INTA215 */
    (fp)r_undefined_exception,
    /* 0x0360  PERIA INTA216 */
    (fp)r_undefined_exception,
    /* 0x0364  PERIA INTA217 */
    (fp)r_undefined_exception,
    /* 0x0368  PERIA INTA218 */
    (fp)r_undefined_exception,
    /* 0x036C  PERIA INTA219 */
    (fp)r_undefined_exception,
    /* 0x0370  PERIA INTA220 */
    (fp)r_undefined_exception,
    /* 0x0374  PERIA INTA221 */
    (fp)r_undefined_exception,
    /* 0x0378  PERIA INTA222 */
    (fp)r_undefined_exception,
    /* 0x037C  PERIA INTA223 */
    (fp)r_undefined_exception,
    /* 0x0380  PERIA INTA224 */
    (fp)r_undefined_exception,
    /* 0x0384  PERIA INTA225 */
    (fp)r_undefined_exception,
    /* 0x0388  PERIA INTA226 */
    (fp)r_undefined_exception,
    /* 0x038C  PERIA INTA227 */
    (fp)r_undefined_exception,
    /* 0x0390  PERIA INTA228 */
    (fp)r_undefined_exception,
    /* 0x0394  PERIA INTA229 */
    (fp)r_undefined_exception,
    /* 0x0398  PERIA INTA230 */
    (fp)r_undefined_exception,
    /* 0x039C  PERIA INTA231 */
    (fp)r_undefined_exception,
    /* 0x03A0  PERIA INTA232 */
    (fp)r_undefined_exception,
    /* 0x03A4  PERIA INTA233 */
    (fp)r_undefined_exception,
    /* 0x03A8  PERIA INTA234 */
    (fp)r_undefined_exception,
    /* 0x03AC  PERIA INTA235 */
    (fp)r_undefined_exception,
    /* 0x03B0  PERIA INTA236 */
    (fp)r_undefined_exception,
    /* 0x03B4  PERIA INTA237 */
    (fp)r_undefined_exception,
    /* 0x03B8  PERIA INTA238 */
    (fp)r_undefined_exception,
    /* 0x03BC  PERIA INTA239 */
    (fp)r_undefined_exception,
    /* 0x03C0  PERIA INTA240 */
    (fp)r_undefined_exception,
    /* 0x03C4  PERIA INTA241 */
    (fp)r_undefined_exception,
    /* 0x03C8  PERIA INTA242 */
    (fp)r_undefined_exception,
    /* 0x03CC  PERIA INTA243 */
    (fp)r_undefined_exception,
    /* 0x03D0  PERIA INTA244 */
    (fp)r_undefined_exception,
    /* 0x03D4  PERIA INTA245 */
    (fp)r_undefined_exception,
    /* 0x03D8  PERIA INTA246 */
    (fp)r_undefined_exception,
    /* 0x03DC  PERIA INTA247 */
    (fp)r_undefined_exception,
    /* 0x03E0  PERIA INTA248 */
    (fp)r_undefined_exception,
    /* 0x03E4  PERIA INTA249 */
    (fp)r_undefined_exception,
    /* 0x03E8  PERIA INTA250 */
    (fp)r_undefined_exception,
    /* 0x03EC  PERIA INTA251 */
    (fp)r_undefined_exception,
    /* 0x03F0  PERIA INTA252 */
    (fp)r_undefined_exception,
    /* 0x03F4  PERIA INTA253 */
    (fp)r_undefined_exception,
    /* 0x03F8  PERIA INTA254 */
    (fp)r_undefined_exception,
    /* 0x03FC  PERIA INTA255 */
    (fp)r_undefined_exception
};

/***********************************************************************************************************************
* Function Name: r_icu_group_be0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_icu_group_be0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_icu_group_bl0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_icu_group_bl0_interrupt(void)
{
    if (ICU.GRPBL0.BIT.IS4 == 1U)
    {
        r_sci2_transmitend_interrupt();
    }
    if (ICU.GRPBL0.BIT.IS5 == 1U)
    {
        r_sci2_receiveerror_interrupt();
    }
    if (ICU.GRPBL0.BIT.IS14 == 1U)
    {
        r_sci7_transmitend_interrupt();
    }
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_icu_group_bl1_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_icu_group_bl1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_icu_group_bl2_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_icu_group_bl2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_icu_group_al0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_icu_group_al0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_icu_group_al1_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_icu_group_al1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

#define OFS_REG   __attribute__ ((section (".ofs1"))) /* 0xFE7F5D00 */ /* MDE, OFS0, OFS1 */
#define OFS_TMINF __attribute__ ((section (".ofs2"))) /* 0xFE7F5D10 */
#define OFS_SPCC  __attribute__ ((section (".ofs3"))) /* 0xFE7F5D40 */
#define OFS_TMEF  __attribute__ ((section (".ofs4"))) /* 0xFE7F5D48 */
#define OFS_OSIS  __attribute__ ((section (".ofs5"))) /* 0xFE7F5D50 */
#define OFS_FAW   __attribute__ ((section (".ofs6"))) /* 0xFE7F5D64 */
#define OFS_ROMCODE __attribute__ ((section (".ofs7"))) /* 0xFE7F5D70 */

/* Start user code for adding. Do not edit comment generated here */
/* SPCC register */
const unsigned long __SPCCreg OFS_SPCC = 0xFFFFFFFF;

/* TMEF register */
const unsigned long __TMEFreg OFS_TMEF = 0xFFFFFFFF;

/* OSIS register (ID codes) */
const unsigned long __OSISreg[4] OFS_OSIS = {
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
};

/* TMINF register */
const unsigned long __TMINFreg OFS_TMINF = 0xFFFFFFFF;

/* FAW register */
const unsigned long __FAWreg OFS_FAW = 0xFFFFFFFF;

/* ROMCODE register */
const unsigned long __ROMCODEreg OFS_ROMCODE = 0xFFFFFFFF;
/* End user code. Do not edit comment generated here */

/* MDE register (Single Chip Mode) */
#ifdef __RX_BIG_ENDIAN__
    const unsigned long __MDEreg OFS_REG = 0xFFFFFFF8; /* big */
#else
    const unsigned long __MDEreg OFS_REG = 0xFFFFFFFF; /* little */
#endif

/* OFS0 register */
const unsigned long __OFS0reg OFS_REG = 0xFFFFFFFF;

/* OFS1 register */
const unsigned long __OFS1reg OFS_REG = 0xFFFFFFFF;

/***********************************************************************************************************************
* Function Name: r_undefined_exception
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_undefined_exception(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_reserved_exception
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_reserved_exception(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_nmi_exception
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_nmi_exception(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_brk_exception
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_brk_exception(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_privileged_exception
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_privileged_exception(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_access_exception
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_access_exception(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_floatingpoint_exception
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_floatingpoint_exception(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

