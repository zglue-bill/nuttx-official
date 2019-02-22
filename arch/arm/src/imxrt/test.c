/************************************************************************************
 * arch/arm/src/imxrt/chip/imxrt105x_memorymap.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

/************************************************************************************
 * Included Files
 ************************************************************************************/

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* System memory map */

#define IMXRT_ITCM_BASE           0x00000000  /* 512KB ITCM */
                               /* 0x00080000     512KB ITCM Reserved */
                               /* 0x00100000     1MB ITCM Reserved */
#define IMXRT_ROMCP_BASE          0x00200000  /* 96KB ROMCP */
                               /* 0x00218000     416KB ROMCP Reserved */
                               /* 0x00280000     1536KB Reserved */
                               /* 0x00400000     128MB Reserved */
#define IMXRT_FLEXSPI_BASE        0x08000000  /* 128MB FlexSPI (Aliased) */
#define IMXRT_SEMCA_BASE          0x10000000  /* 256MB SEMC (Aliased) */
