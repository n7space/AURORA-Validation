/* Body file for function Subscriber1
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "subscriber1.h"
#include <stdio.h>
#include "routing.h"

void subscriber1_startup(void)
{

}

void subscriber1_PI_con1
      (const asn1SccT_Int32 *IN_p1)

{
    if((subscriber1_con1_get_sender() == PID_publisher1 && *IN_p1 == 42) ||
       (subscriber1_con1_get_sender() == PID_publisher2 && *IN_p1 == 1969) ||
       (subscriber1_con1_get_sender() == PID_publisher3 && *IN_p1 == 3000))
    {
        subscriber1_RI_reply1();
    }
    else
    {
        printf("ERROR\n");
    }
}


