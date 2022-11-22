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

asn1SccTestMessage buildMessage(const uint32_t magicNumber, const char* data)
{
    asn1SccTestMessage message;
    message.id = (asn1SccMyInteger)(rand() % 10000);
    message.magicNumber = (asn1SccMyInteger)magicNumber;
    strncpy(message.data.arr, data, (int)(sizeof(message.data.arr) - 1));
    message.data.arr[(int)(sizeof(message.data.arr) - 1)] = '\0';
    message.validity = TestMessage_validity_valid;
    return message;
}

void publisher_startup(void)
{
   srand(time(NULL));
}

void publisher_PI_trigger(void)
{
    asn1SccTestMessage message = buildMessage(1960, "TEST");
    publisher_RI_PI_1(&message);
}

