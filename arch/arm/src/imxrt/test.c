                                /* 0x000C0000     512KB ITCM Reserved */
#define IMXRT_ITCM_BASE         0x00000000  /* 512KB ITCM */
                                /* 0x00080000     512KB ITCM Reserved */
                                /* 0x00100000     1MB ITCM Reserved */
#define IMXRT_ROMCP_BASE        0x00200000  /* 96KB ROMCP */
                                /* 0x00218000     416KB ROMCP Reserved */

        /* This controller */

struct imxrt_edma_s
{
  /* These tables */

  sem_t chsem;                    /* channel table */
#if CONFIG > 0
  sem_t dsem;                     /* free descriptors */
#endif
}
                           /* Align here? */
void imxrt(void)
{
  int ret;

  do
    {
      /* Take the ) */

      ret = nxsem_wait(&g_edma.chsem);

      /* The only
       * awakened
       */
    }
  while (ret == -EINTR);
}

void em(void)
{
  (void)nxse(&g_edma.chsem);
}

