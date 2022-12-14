/* Body file for function Publisher
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "publisher.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SEC_TO_NS(sec) ((sec)*1000000000)

asn1SccTestMessage buildMessage()
{
    uint64_t nanoseconds = 0;
    struct timespec ts;
    int return_code = timespec_get(&ts, TIME_UTC);

    if(return_code != 0)
    {
        nanoseconds = SEC_TO_NS((uint64_t)ts.tv_sec) + (uint64_t)ts.tv_nsec;
    }
    asn1SccTestMessage message;
    message.id = (asn1SccMyInteger)(rand() % 10000);
    message.timestamp = nanoseconds;

    return message;
}

void publisher_startup(void)
{
   srand((unsigned int)time(NULL));
}

void publisher_PI_trigger(void)
{
    asn1SccTestMessage message = buildMessage();
    publisher_RI_PI_1(&message);
}


