/* Body file for function Component1
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "component1.h"
//#include <stdio.h>

asn1SccT_FunctionStatus component1_buildStatus()
{
    asn1SccT_FunctionStatus functionStatus;
    functionStatus.id = PID_component1;
    functionStatus.error_count = 0;
    functionStatus.state = T_FunctionStatus_state_online;

    return functionStatus;
}

void component1_startup(void)
{

}

void component1_PI_trigger1(void)
{
   asn1SccT_FunctionStatus functionStatus = component1_buildStatus();

   component1_RI_WriteStatus(&functionStatus);
}


