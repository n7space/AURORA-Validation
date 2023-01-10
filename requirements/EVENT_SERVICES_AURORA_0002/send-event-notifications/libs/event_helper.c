#include "event_helper.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BIT_MASK 0xFF
#define SEC_TO_NS(sec) ((sec)*1000000000)

asn1SccT_EventMessage build_event(const asn1SccT_UInt32 id, 
                                  const asn1SccT_EventMessage_eventType eventType,
                                  const char message[])
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

    asn1SccT_EventMessage event;
    event.id = id;
    event.eventType = eventType;
    strncpy(event.message.arr, message, sizeof(event.message.arr) - 1);
    event.message.arr[sizeof (event.message.arr) - 1] = '\0';
    event.timestamp = timestamp;

    return event;
}

void print_event(const asn1SccT_UInt32 listener_id, 
                 const asn1SccT_EventMessage *IN_eventmessage)
{
    uint64_t time = 0;
    uint32_t seconds = 0;
    uint32_t nanoseconds = 0;

    seconds += (uint32_t)IN_eventmessage->timestamp.c1 << 24;
    seconds += (uint32_t)IN_eventmessage->timestamp.c2 << 16;
    seconds += (uint32_t)IN_eventmessage->timestamp.c3 << 8;
    seconds += (uint32_t)IN_eventmessage->timestamp.c4;

    nanoseconds += (uint32_t)IN_eventmessage->timestamp.f1 << 24;
    nanoseconds += (uint32_t)IN_eventmessage->timestamp.f2 << 16;
    nanoseconds += (uint32_t)IN_eventmessage->timestamp.f3 << 8;

    time = SEC_TO_NS((uint64_t)seconds) + (uint64_t)nanoseconds;

    printf("Event received by Listener %ld:\n", listener_id);
    printf("  event id =       %ld\n", IN_eventmessage->id);
    switch(IN_eventmessage->eventType)
    {
        case T_EventMessage_eventType_informative:
        {
            printf("  eventType =      informative\n");
            break;
        }
        case T_EventMessage_eventType_lowSeverity:
        {
            printf("  eventType =      low severity\n");
            break;
        }
        case T_EventMessage_eventType_mediumSeverity:
        {
            printf("  eventType =      medium severity\n");
           break;
        }
        case T_EventMessage_eventType_highSeverity:
        {
            printf("  eventType =      high severity\n");
            break;
        }
    }
    printf("  message =        %s\n", IN_eventmessage->message.arr);
    printf("  timestamp =      %ld\n\n", time);
}