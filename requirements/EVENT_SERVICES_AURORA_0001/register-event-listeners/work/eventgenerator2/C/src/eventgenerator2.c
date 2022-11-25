/* Body file for function EventGenerator2
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "eventgenerator2.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BIT_MASK 0xFF

asn1SccT_EventMessage eventgenerator2_buildEvent(asn1SccT_UInt32 id, asn1SccT_EventMessage_eventType eventType)
{
    char message[] = "This is message from EventGenerator2";
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

    asn1SccT_EventMessage event;
    event.id = id;
    event.eventType = eventType;
    strncpy(event.message.arr, message, sizeof(event.message.arr) - 1);
    event.message.arr[sizeof (event.message.arr) - 1] = '\0';
    event.timestamp = timestamp;

    return event;
}


void eventgenerator2_startup(void)
{
}

void eventgenerator2_PI_trigger2(void)
{
    asn1SccT_EventMessage event;
    event = eventgenerator2_buildEvent(2, T_EventMessage_eventType_lowSeverity);

    eventgenerator2_RI_notify(&event);
}


