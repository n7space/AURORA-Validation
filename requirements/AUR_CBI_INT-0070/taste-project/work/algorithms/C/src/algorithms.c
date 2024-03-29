/* Body file for function algorithms
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "algorithms.h"
//#include <stdio.h>


void algorithms_startup(void)
{
   // Write your initialisation code
   // You may call sporadic required interfaces and start timers
   // puts ("[algorithms] Startup");
}

void algorithms_PI_calculate_mppt
      (const asn1SccAuroraVoltage *IN_voltage,
       const asn1SccAuroraCurrent *IN_current,
       asn1SccAuroraPWM *OUT_pwm)

{
   *OUT_pwm = 0.4;
}


void algorithms_PI_calculate_pid
      (asn1SccAuroraPWM *OUT_output_value,
       const asn1SccAuroraPIDValue *IN_k_p,
       const asn1SccAuroraPIDValue *IN_k_i,
       const asn1SccAuroraPIDValue *IN_k_d,
       const asn1SccAuroraReal *IN_input_value,
       const asn1SccAuroraReal *IN_target_value)

{
    *OUT_output_value = 0.7;
}


