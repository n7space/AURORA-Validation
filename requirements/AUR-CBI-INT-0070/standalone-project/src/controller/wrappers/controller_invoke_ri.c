// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#include "C_ASN1_Types.h"

extern unsigned controller_initialized;

void controller_RI_calculate_mppt_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraVoltage *IN_voltage,
       const asn1SccAuroraCurrent *IN_current,
       asn1SccAuroraPWM           *OUT_pwm
);
void controller_RI_calculate_mppt(
      const asn1SccAuroraVoltage *IN_voltage,
       const asn1SccAuroraCurrent *IN_current,
       asn1SccAuroraPWM           *OUT_pwm
);
void controller_RI_calculate_mppt(
      const asn1SccAuroraVoltage *IN_voltage,
       const asn1SccAuroraCurrent *IN_current,
       asn1SccAuroraPWM           *OUT_pwm
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_calculate_mppt_To_PID(PID_env, IN_voltage, IN_current, OUT_pwm
);
}

void controller_RI_calculate_mppt_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraVoltage *IN_voltage,
       const asn1SccAuroraCurrent *IN_current,
       asn1SccAuroraPWM           *OUT_pwm
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to algorithms (corresponding PI: calculate_mppt)
      printf ("INNER_RI: controller,algorithms,calculate_mppt,calculate_mppt,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_pwm = 0;

   // Send the message via the middleware API
   extern void vm_controller_calculate_mppt
     (asn1SccPID,
      void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_controller_calculate_mppt
     (dest_pid,
      (void *)IN_voltage, sizeof(asn1SccAuroraVoltage),
      (void *)IN_current, sizeof(asn1SccAuroraCurrent),
      (void *)OUT_pwm, &size_OUT_buf_pwm);


}



void controller_RI_calculate_pid_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraPWM            *OUT_output_value,
       const asn1SccAuroraPIDValue *IN_k_p,
       const asn1SccAuroraPIDValue *IN_k_i,
       const asn1SccAuroraPIDValue *IN_k_d,
       const asn1SccAuroraReal     *IN_input_value,
       const asn1SccAuroraReal     *IN_target_value
);
void controller_RI_calculate_pid(
      asn1SccAuroraPWM            *OUT_output_value,
       const asn1SccAuroraPIDValue *IN_k_p,
       const asn1SccAuroraPIDValue *IN_k_i,
       const asn1SccAuroraPIDValue *IN_k_d,
       const asn1SccAuroraReal     *IN_input_value,
       const asn1SccAuroraReal     *IN_target_value
);
void controller_RI_calculate_pid(
      asn1SccAuroraPWM            *OUT_output_value,
       const asn1SccAuroraPIDValue *IN_k_p,
       const asn1SccAuroraPIDValue *IN_k_i,
       const asn1SccAuroraPIDValue *IN_k_d,
       const asn1SccAuroraReal     *IN_input_value,
       const asn1SccAuroraReal     *IN_target_value
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_calculate_pid_To_PID(PID_env, OUT_output_value, IN_k_p, IN_k_i, IN_k_d, IN_input_value, IN_target_value
);
}

void controller_RI_calculate_pid_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraPWM            *OUT_output_value,
       const asn1SccAuroraPIDValue *IN_k_p,
       const asn1SccAuroraPIDValue *IN_k_i,
       const asn1SccAuroraPIDValue *IN_k_d,
       const asn1SccAuroraReal     *IN_input_value,
       const asn1SccAuroraReal     *IN_target_value
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to algorithms (corresponding PI: calculate_pid)
      printf ("INNER_RI: controller,algorithms,calculate_pid,calculate_pid,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_output_value = 0;

   // Send the message via the middleware API
   extern void vm_controller_calculate_pid
     (asn1SccPID,
      void *, size_t *,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t);

   vm_controller_calculate_pid
     (dest_pid,
      (void *)OUT_output_value, &size_OUT_buf_output_value,
      (void *)IN_k_p, sizeof(asn1SccAuroraPIDValue),
      (void *)IN_k_i, sizeof(asn1SccAuroraPIDValue),
      (void *)IN_k_d, sizeof(asn1SccAuroraPIDValue),
      (void *)IN_input_value, sizeof(asn1SccAuroraReal),
      (void *)IN_target_value, sizeof(asn1SccAuroraReal));


}



void controller_RI_controller_status_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraControllerStatus *IN_status
);
void controller_RI_controller_status(
      const asn1SccAuroraControllerStatus *IN_status
);
void controller_RI_controller_status(
      const asn1SccAuroraControllerStatus *IN_status
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_controller_status_To_PID(PID_env, IN_status
);
}

void controller_RI_controller_status_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraControllerStatus *IN_status
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to mmi (corresponding PI: controller_status)
      printf ("INNER_RI: controller,mmi,controller_status,controller_status,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_controller_controller_status
     (asn1SccPID,
      void *, size_t);

   vm_controller_controller_status
     (dest_pid,
      (void *)IN_status, sizeof(asn1SccAuroraControllerStatus));


}



void controller_RI_get_battery_capacity_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraBatteryCapacity *OUT_capacity
);
void controller_RI_get_battery_capacity(
      asn1SccAuroraBatteryCapacity *OUT_capacity
);
void controller_RI_get_battery_capacity(
      asn1SccAuroraBatteryCapacity *OUT_capacity
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_get_battery_capacity_To_PID(PID_env, OUT_capacity
);
}

void controller_RI_get_battery_capacity_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraBatteryCapacity *OUT_capacity
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to electrics_power_supply (corresponding PI: get_battery_capacity)
      printf ("INNER_RI: controller,electrics_power_supply,get_battery_capacity,get_battery_capacity,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_capacity = 0;

   // Send the message via the middleware API
   extern void vm_controller_get_battery_capacity
     (asn1SccPID,
      void *, size_t *);

   vm_controller_get_battery_capacity
     (dest_pid,
      (void *)OUT_capacity, &size_OUT_buf_capacity);


}



void controller_RI_get_payload_status_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraTemperature *OUT_temperature,
       asn1SccAuroraFlowRate    *OUT_flow_rate
);
void controller_RI_get_payload_status(
      asn1SccAuroraTemperature *OUT_temperature,
       asn1SccAuroraFlowRate    *OUT_flow_rate
);
void controller_RI_get_payload_status(
      asn1SccAuroraTemperature *OUT_temperature,
       asn1SccAuroraFlowRate    *OUT_flow_rate
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_get_payload_status_To_PID(PID_env, OUT_temperature, OUT_flow_rate
);
}

void controller_RI_get_payload_status_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraTemperature *OUT_temperature,
       asn1SccAuroraFlowRate    *OUT_flow_rate
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to payload (corresponding PI: get_payload_status)
      printf ("INNER_RI: controller,payload,get_payload_status,get_payload_status,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_temperature = 0;
   size_t      size_OUT_buf_flow_rate = 0;

   // Send the message via the middleware API
   extern void vm_controller_get_payload_status
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_controller_get_payload_status
     (dest_pid,
      (void *)OUT_temperature, &size_OUT_buf_temperature,
      (void *)OUT_flow_rate, &size_OUT_buf_flow_rate);


}



void controller_RI_get_solar_panel_status_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraVoltage *OUT_voltage,
       asn1SccAuroraCurrent *OUT_current
);
void controller_RI_get_solar_panel_status(
      asn1SccAuroraVoltage *OUT_voltage,
       asn1SccAuroraCurrent *OUT_current
);
void controller_RI_get_solar_panel_status(
      asn1SccAuroraVoltage *OUT_voltage,
       asn1SccAuroraCurrent *OUT_current
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_get_solar_panel_status_To_PID(PID_env, OUT_voltage, OUT_current
);
}

void controller_RI_get_solar_panel_status_To_PID(asn1SccPID dest_pid, 
      asn1SccAuroraVoltage *OUT_voltage,
       asn1SccAuroraCurrent *OUT_current
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to electrics_power_supply (corresponding PI: get_solar_panel_status)
      printf ("INNER_RI: controller,electrics_power_supply,get_solar_panel_status,get_solar_panel_status,%lld\n", msc_time);
      fflush(stdout);
   }

   size_t      size_OUT_buf_voltage = 0;
   size_t      size_OUT_buf_current = 0;

   // Send the message via the middleware API
   extern void vm_controller_get_solar_panel_status
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_controller_get_solar_panel_status
     (dest_pid,
      (void *)OUT_voltage, &size_OUT_buf_voltage,
      (void *)OUT_current, &size_OUT_buf_current);


}



void controller_RI_set_flow_controller_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraPWM *IN_pwm
);
void controller_RI_set_flow_controller(
      const asn1SccAuroraPWM *IN_pwm
);
void controller_RI_set_flow_controller(
      const asn1SccAuroraPWM *IN_pwm
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_set_flow_controller_To_PID(PID_env, IN_pwm
);
}

void controller_RI_set_flow_controller_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraPWM *IN_pwm
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to payload (corresponding PI: set_flow_controller)
      printf ("INNER_RI: controller,payload,set_flow_controller,set_flow_controller,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_controller_set_flow_controller
     (asn1SccPID,
      void *, size_t);

   vm_controller_set_flow_controller
     (dest_pid,
      (void *)IN_pwm, sizeof(asn1SccAuroraPWM));


}



void controller_RI_set_power_point_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraPWM *IN_pwm
);
void controller_RI_set_power_point(
      const asn1SccAuroraPWM *IN_pwm
);
void controller_RI_set_power_point(
      const asn1SccAuroraPWM *IN_pwm
)
{
   // When no destination is specified, send to everyone (multicast)
   controller_RI_set_power_point_To_PID(PID_env, IN_pwm
);
}

void controller_RI_set_power_point_To_PID(asn1SccPID dest_pid, 
      const asn1SccAuroraPWM *IN_pwm
)
{
   // Log MSC data on Linux when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
      innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      // Log message to electrics_power_supply (corresponding PI: set_power_point)
      printf ("INNER_RI: controller,electrics_power_supply,set_power_point,set_power_point,%lld\n", msc_time);
      fflush(stdout);
   }


   // Send the message via the middleware API
   extern void vm_controller_set_power_point
     (asn1SccPID,
      void *, size_t);

   vm_controller_set_power_point
     (dest_pid,
      (void *)IN_pwm, sizeof(asn1SccAuroraPWM));


}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void controller_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void controller_get_sender(asn1SccPID *sender_pid);
  controller_get_sender(sender_pid);
}
