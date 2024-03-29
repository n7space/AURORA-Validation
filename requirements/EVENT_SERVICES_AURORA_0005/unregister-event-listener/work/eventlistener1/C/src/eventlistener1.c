/* Body file for function EventListener1
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "eventlistener1.h"
#include "event_helper.h"

static int counter;

void eventlistener1_startup(void)
{
    counter = 0;

    asn1SccT_UInt32 eventId = 2;
    bool shouldSubscribe = true;
    eventlistener1_RI_subscribe_to_event(&eventId, &shouldSubscribe);
}

void eventlistener1_PI_receive_event
      (const asn1SccT_EventMessage *IN_eventmessage)

{
    print_event(1, IN_eventmessage);

    counter++;

    if(counter == 3)
    {
        asn1SccT_UInt32 eventId = 2;
        bool shouldSubscribe = false;
        eventlistener1_RI_subscribe_to_event(&eventId, &shouldSubscribe);
    }
}


