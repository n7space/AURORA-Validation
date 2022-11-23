/* Body file for function Observer
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "observer.h"
#include <stdio.h>

#define COMPONENTS_COUNT 3

static asn1SccT_FunctionStatus componentsStatuses[COMPONENTS_COUNT];
static asn1SccPID pids[COMPONENTS_COUNT];

void observer_startup(void)
{
    pids[PID_component1] = PID_component1;
    pids[PID_component2] = PID_component2;
    pids[PID_component3] = PID_component3;
}

void observer_PI_trigger4(void)
{
    observer_RI_ReadStatus(&pids[PID_component1], &componentsStatuses[0]);
    observer_RI_ReadStatus(&pids[PID_component2], &componentsStatuses[1]);
    observer_RI_ReadStatus(&pids[PID_component3], &componentsStatuses[2]);

    for(int i = 0; i < COMPONENTS_COUNT; i++)
    {
        printf("Component %d status:\n", i);
        printf("    id =             %d\n", componentsStatuses[i].id);
        printf("    error_count =    %ld\n", componentsStatuses[i].error_count);
        switch(componentsStatuses[i].state)
        {
            case T_FunctionStatus_state_online:
            {
                printf("    state =          online\n");
                break;
            }
            case T_FunctionStatus_state_offline:
            {
                printf("    state =          offline\n");
                break;
            }
            case T_FunctionStatus_state_error:
            {
                printf("    state =          error\n");
                break;
            }
        }
    }
    printf("\n------------------\n\n");
}




