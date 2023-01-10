#include "event_helper.h"
#include <stdio.h>

#define SEC_TO_NS(sec) ((sec)*1000000000)

void print_event(const int listener_id, const asn1SccT_EventMessage *IN_eventmessage)
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

    printf("Event received by Listener %d:\n", listener_id);
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