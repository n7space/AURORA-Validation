/* Body file for function Controller
 * Generated by TASTE on 2022-08-10 13:26:48
 * You can edit this file, it will not be overwritten
 * Provided interfaces : Trigger
 * Required interfaces : Iface
 * User-defined properties for this function:
 * Timers              : 
 */

#include "controller.h"
#include <stdio.h>
#include <assert.h>


void controller_startup(void)
{
}

void controller_PI_Trigger(void)
{
    asn1SccMyReal inputParam = 5.0;
    asn1SccMyReal outputParam = 0.0;
    asn1SccMyReal expectedOutput = 10.0;
    controller_RI_Iface( &inputParam, &outputParam );
    printf("Output: %f\n", outputParam);
    assert(abs(outputParam - expectedOutput) < 0.001f);
}



