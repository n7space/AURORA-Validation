/* Body file for function controller
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "controller.h"
//#include <stdio.h>


void controller_startup(void)
{
   // Write your initialisation code
   // You may call sporadic required interfaces and start timers
   // puts ("[controller] Startup");
}

void controller_PI_step(void)
{
   double battery_capacity;
   controller_RI_get_battery_capacity(&battery_capacity);

   double solar_panel_voltage;
   double solar_panel_current;
   controller_RI_get_solar_panel_status(&solar_panel_voltage, &solar_panel_current);

   double payload_temperature;
   double payload_flow_rate;
   controller_RI_get_payload_status(&payload_temperature, &payload_flow_rate);

   double solar_panel_pwm;

   controller_RI_calculate_mppt(&solar_panel_voltage, &solar_panel_current, &solar_panel_pwm);

   controller_RI_set_power_point(&solar_panel_pwm);

   double payload_pwm;
   double k_p = 5.0;
   double k_i = 3.0;
   double k_d = 3.0;
   double target_temperature = 25.0;

   if(battery_capacity < 0.5)
   {
       target_temperature = 250;
   }
   else
   {
       target_temperature = 350;
   }
   if(payload_temperature < 200)
   {
       k_p = 8.0;
   }
   controller_RI_calculate_pid(&payload_pwm,
                               &k_p,
                               &k_i,
                               &k_d,
                               &payload_temperature,
                               &target_temperature);

   controller_RI_set_flow_controller(&payload_pwm);

   asn1SccAuroraControllerStatus status;
   status.battery_capacity = battery_capacity;
   status.payload_flow_rate = payload_flow_rate;
   status.payload_temperature = payload_temperature;
   status.solar_panel_current = solar_panel_current;
   status.solar_panel_voltage = solar_panel_voltage;

   controller_RI_controller_status(&status);
}


