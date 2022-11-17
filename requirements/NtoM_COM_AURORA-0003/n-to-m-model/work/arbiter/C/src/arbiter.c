/* Body file for function Arbiter
 * Generated by TASTE on 2022-08-18 16:30:09
 * You can edit this file, it will not be overwritten
 * Provided interfaces : reply1
 * Required interfaces : 
 * User-defined properties for this function:
 * Timers              : 
 */

#include "arbiter.h"
#include <stdio.h>

int reply_counter;

void arbiter_startup(void)
{
    reply_counter = 0;
}

void arbiter_PI_reply1()

{
    reply_counter++;

    if(reply_counter == 8)
    {
        printf("n to m test - OK\n");
        // stdout must be flushed for file capture
        fflush(stdout);
        // Regular exit does not terminate the program
        // probably waiting on a clean-up operation
        // which is not needed for this test case.
        _Exit(0);
    }
}


