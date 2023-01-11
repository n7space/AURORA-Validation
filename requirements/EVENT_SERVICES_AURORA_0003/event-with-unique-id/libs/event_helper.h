#ifndef EVENT_HELPER_H
#define EVENT_HELPER_H

#include "dataview-uniq.h"

asn1SccT_EventMessage build_event(const asn1SccT_UInt32 id,
                                  const asn1SccT_EventMessage_eventType eventType,
                                  const char message[]);
void print_event(const asn1SccT_UInt32 listener_id,
                 const asn1SccT_EventMessage *IN_eventmessage);

#endif
