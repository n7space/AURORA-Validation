/* Body file for function Src1
 * Generated by TASTE on 2022-08-18 16:30:09
 * You can edit this file, it will not be overwritten
 * Provided interfaces : trigger1
 * Required interfaces : con1
 * User-defined properties for this function:
 * Timers              : 
 */

#include "src1.h"


void src1_startup(void)
{

}

void src1_PI_trigger1(void)
{
    asn1SccT_Int32 x;
    x = 42;
    src1_RI_con1(&x);
}


