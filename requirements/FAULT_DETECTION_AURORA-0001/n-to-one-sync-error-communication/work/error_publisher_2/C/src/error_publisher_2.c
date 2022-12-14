/* Body file for function Error_publisher_2
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "error_publisher_2.h"
#include <stdlib.h>
#include <time.h>

#define BIT_MASK 0xFF
#define SEC_TO_NS(sec) ((sec)*1000000000)

asn1SccT_ErrorMessage error_publisher_2_buildError(asn1SccPID functionPid)
{
    uint64_t seconds = 0;
    uint64_t nanoseconds = 0;
    struct timespec ts;
    int return_code = timespec_get(&ts, TIME_UTC);

    if(return_code != 0)
    {
        seconds = (uint64_t)ts.tv_sec;
        nanoseconds = (uint64_t)ts.tv_nsec;
    }

    asn1SccT_CUCTimestamp timestamp;
    timestamp.c1 = (seconds >> 24) & BIT_MASK;
    timestamp.c2 = (seconds >> 16) & BIT_MASK;
    timestamp.c3 = (seconds >> 8) & BIT_MASK;
    timestamp.c4 = seconds & BIT_MASK;
    timestamp.f1 = (nanoseconds >> 24) & BIT_MASK;
    timestamp.f2 = (nanoseconds >> 16) & BIT_MASK;
    timestamp.f3 = (nanoseconds >> 8) & BIT_MASK;

    asn1SccT_FunctionStatus functionStatus;
    functionStatus.id = functionPid;
    functionStatus.error_count = 0;
    functionStatus.state = T_FunctionStatus_state_online;

    asn1SccT_ErrorMessage errorMessage;
    errorMessage.id = (asn1SccT_UInt32)(rand() % 10000);
    errorMessage.timestamp = timestamp;
    errorMessage.function_status = functionStatus;

    return errorMessage;
}

void error_publisher_2_startup(void)
{
    srand((unsigned int)time(NULL));
}

void error_publisher_2_PI_trigger2(void)
{
    asn1SccT_ErrorMessage errorMessage = error_publisher_2_buildError(PID_error_publisher_2);

    error_publisher_2_RI_Error_send(&errorMessage);
}


