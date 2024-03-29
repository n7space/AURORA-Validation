/* Body file for function Component
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "component.h"
#include <stdio.h>
#include <stdlib.h>

static int counter;
static asn1SccComponentStatus status;
static asn1SccMySeq data;

void component_startup(void)
{
    counter = 0;
    status = ComponentStatus_off;
}

void component_PI_trigger(void)
{
    switch(status)
    {
        case ComponentStatus_on:
        {
            printf("Component::status = on\n");
            counter++;
            printf("Component::counter = %d\n", counter);
            break;
        }
        case ComponentStatus_off:
        {
            printf("Component::status = off\n");
            break;
        }
        default:
        {
            printf("ERROR Component::status = invalid\n");
        }
    }
}

void component_PI_start(void)
{
   if(status == ComponentStatus_off)
   {
       counter = 1;
       status = ComponentStatus_on;
   }
   else
   {
       printf("ERROR, invalid state transision\n");
   }
}


void component_PI_stop(void)
{
   counter = 0;
   status = ComponentStatus_off;
}

void component_PI_resume(void)
{
}

void component_PI_suspend(void)
{
}

void component_PI_getData(asn1SccMySeq *testData)
{
    *testData = data;
}

void component_PI_setData(const asn1SccMySeq *testData)
{
    data = *testData;
}




