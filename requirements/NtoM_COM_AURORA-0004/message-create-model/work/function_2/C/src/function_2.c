/* Body file for function Function_2
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "function_2.h"
#include <stdio.h>


void function_2_startup(void)
{

}

void function_2_PI_PI_1(const asn1SccTestMessage *message)
{
    printf("%d\n", (int)message->id);
    printf("%d\n", (int)message->data);
    printf("%d\n", (int)message->validity);
    printf("\n");
}




