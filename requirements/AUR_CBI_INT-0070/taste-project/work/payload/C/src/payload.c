/* Body file for function payload
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "payload.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double payload_temperature;
static double payload_flow_rate;
static double payload_target_flow_rate;

static int step_count;

static double amp_100;
static double amp_50;
static double amp_25;

void payload_startup(void)
{
    payload_temperature = 18.0;
    payload_flow_rate = 4.0;
    payload_target_flow_rate = 0.0;

    step_count = 0;
    amp_100 = 0.0;
    amp_50 = 0.0;
    amp_25 = 0.0;
}

void payload_PI_get_payload_status
      (asn1SccAuroraTemperature *OUT_temperature,
       asn1SccAuroraFlowRate *OUT_flow_rate)

{
   *OUT_temperature = payload_temperature;
   *OUT_flow_rate = payload_flow_rate;
}

void payload_PI_set_flow_controller
      (const asn1SccAuroraPWM *IN_pwm)

{
   payload_target_flow_rate = *IN_pwm;
}

void payload_PI_step(void)
{
   if(step_count == 0)
   {
       amp_100 = 0.5 * (rand() / (RAND_MAX - 2.0) - 1.0);
   }

   if(step_count % 50 == 0)
   {
       amp_50 = 0.4 * (rand() / (RAND_MAX - 2.0) - 1.0);
   }

   if(step_count % 25 == 0)
   {
       amp_25 = 0.2 * (rand() / (RAND_MAX - 2.0) - 1.0);
   }

   payload_flow_rate = payload_target_flow_rate * 20;

   payload_temperature = 305.0
           + 20.0 * amp_100 * sin(2.0 * M_PI * ((step_count % 100) * 0.001))
           + 20.0 * amp_50 * sin(2.0 * M_PI * ((step_count % 50) * 0.02))
           + 20.0 * amp_25 * sin(2.0 * M_PI * ((step_count % 25) * 0.04))
           + payload_flow_rate / 5.0;

   ++step_count;
   if(step_count == 100)
   {
       step_count = 0;
   }
}
