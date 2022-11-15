/* Body file for function Dst
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "dst.h"
#include <stdio.h>
#include <routing.h>

void dst_startup(void)
{
}

void dst_PI_con1
      (const asn1SccT_Int32 *IN_p1)

{
    if((dst_con1_get_sender() == PID_src1 && *IN_p1 == 42) ||
       (dst_con1_get_sender() == PID_src2 && *IN_p1 == 1969) ||
       (dst_con1_get_sender() == PID_src3 && *IN_p1 == 3000))
    {
        dst_RI_reply1();
    }
    else
    {
        printf("ERROR\n");
    }

}


