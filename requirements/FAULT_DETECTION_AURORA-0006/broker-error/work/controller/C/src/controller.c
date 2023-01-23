/* Body file for function controller
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "controller.h"
#include <stdio.h>

static asn1SccTMPacket tm_packet;

void controller_startup(void)
{
}

void controller_PI_error(void)
{
   printf("* COMMUNICATION ERROR *\n");
   fflush(stdout);
}

void controller_PI_tc
      (const asn1SccTCPacket *IN_p1)

{
   tm_packet.dummy1 = IN_p1->dummy1;
   tm_packet.dummy2 = IN_p1->dummy2;
   controller_RI_tm(&tm_packet);
}


