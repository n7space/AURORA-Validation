/* Body file for function Component2
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "component2.h"
#include <stdlib.h>
#include <time.h>

asn1SccT_FunctionStatus component2_buildStatus()
{
    asn1SccT_UInt32 errorCount = (asn1SccT_UInt32)(rand() % 3);

    asn1SccT_FunctionStatus functionStatus;
    functionStatus.id = PID_component2;
    functionStatus.error_count = errorCount;
    if(errorCount == 0)
    {
        functionStatus.state = T_FunctionStatus_state_online;
    }
    else
    {
        functionStatus.state = T_FunctionStatus_state_error;
    }

    return functionStatus;
}

void component2_startup(void)
{
    srand((unsigned int)time(NULL));
}

void component2_PI_trigger2(void)
{
   asn1SccT_FunctionStatus functionStatus = component2_buildStatus();

   component2_RI_WriteStatus(&functionStatus);
}

