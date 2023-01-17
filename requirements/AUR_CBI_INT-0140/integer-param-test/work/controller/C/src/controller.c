/* Body file for function Controller
 * Generated by TASTE on 2022-08-10 13:16:54
 * You can edit this file, it will not be overwritten
 * Provided interfaces : Trigger
 * Required interfaces : IntIface
 * User-defined properties for this function:
 * Timers              : 
 */

#include "controller.h"
#include <stdio.h>
#include <assert.h>


void controller_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   // puts ("[Controller] Startup");
}

void controller_PI_Trigger(void)
{
    asn1SccMyInteger inputParam = 5;
    asn1SccMyInteger outputParam = 0;
    asn1SccMyInteger expectedOutput = 10;
    controller_RI_IntIface( &inputParam, &outputParam );
    printf("Output: %lu\n", outputParam);
    assert(outputParam == expectedOutput);
}
