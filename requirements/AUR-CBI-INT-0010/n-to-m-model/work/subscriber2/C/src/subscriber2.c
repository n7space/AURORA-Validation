/* Body file for function Subscriber2
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "subscriber2.h"
#include <stdio.h>
#include "routing.h"

void subscriber2_startup(void)
{

}

void subscriber2_PI_con1
      (const asn1SccT_Int32 *IN_p1)

{
    if((subscriber2_con1_get_sender() == PID_publisher1 && *IN_p1 == 42) ||
       (subscriber2_con1_get_sender() == PID_publisher2 && *IN_p1 == 1969) ||
       (subscriber2_con1_get_sender() == PID_publisher3 && *IN_p1 == 3000))
    {
        subscriber2_RI_reply1();
    }
    else
    {
        printf("ERROR\n");
    }
}


