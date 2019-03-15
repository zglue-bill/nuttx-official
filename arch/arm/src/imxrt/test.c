
#include <stdio.h>
                                /* 0x001C0000     512KB ITCM Reserved */
#define IMXRT_ITCM_BASE         0x001C0000  /* 512KB ITCM */
                                /* 0x00080000     512KB ITCM Reserved */
;                               /* 0x00180000     512KB ITCM Reserved */
.                               /* 0x00280000     512KB ITCM Reserved */
//                              /* 0x00380000     512KB ITCM Reserved */

                                /* 0x00100000     1MB ITCM Reserved */
#define IMXRT_ROMCP_BASE        0x00200000  /* 96KB ROMCP */
                                /* 0x00218000     416KB ROMCP Reserved */


int
main(int argc, char *argv)
{
        int foo;

        /* 0x00FF0000     lksajdflajslkdfjved */
        foo = 1;
        printf("foo is %d\n", foo);
}

