/* Body file for function algorithms
 * Generated by TASTE (kazoo/templates/glue/language_wrappers/vm-if-body/function.tmplt)
 */
#include "algorithms_vm_if.h"
#include "C_ASN1_Types.h"
#include <stdio.h>
extern long long getTimeInMilliseconds(void);

// Define a global PID variable used to keep track of the sender of the last message
static asn1SccPID sender_pid = PID_env;

// API to provide to the user code the PID of the last PI caller
void algorithms_get_sender(asn1SccPID *OUT_sender_pid, asn1SccPID unused)
{
  *OUT_sender_pid = sender_pid;
}




unsigned algorithms_initialized = 0;
void init_algorithms(void)
{
   if (0 == algorithms_initialized) {
      // Initialize epoch for the MSC tracing in debug mode
      long long unused = getTimeInMilliseconds();
      algorithms_initialized = 1;
      // Call user code startup function
      algorithms_PI_calculate_mppt_startup();
      algorithms_PI_calculate_pid_startup();
      puts ("[TASTE] Initialization completed for function algorithms");
      algorithms_initialized = 2;
   }
}
void algorithms_calculate_mppt
      (const char *IN_voltage, size_t IN_voltage_len,
       const char *IN_current, size_t IN_current_len,
       char *OUT_pwm, size_t *OUT_pwm_len)

{
   sender_pid = algorithms_calculate_mppt_get_sender();
   // In Debug mode and x86 builts only: log MSC data when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
     innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      printf ("INNER_PI: algorithms,calculate_mppt,%lld\n", msc_time);
      fflush(stdout);
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void algorithms_PI_calculate_mppt
      (const asn1SccAuroraVoltage *,
       const asn1SccAuroraCurrent *,
       asn1SccAuroraPWM *);





   // Call user code
   algorithms_PI_calculate_mppt ((asn1SccAuroraVoltage *)IN_voltage, (asn1SccAuroraCurrent *)IN_current, (asn1SccAuroraPWM *)OUT_pwm);

}




void algorithms_calculate_pid
      (char *OUT_output_value, size_t *OUT_output_value_len,
       const char *IN_k_p, size_t IN_k_p_len,
       const char *IN_k_i, size_t IN_k_i_len,
       const char *IN_k_d, size_t IN_k_d_len,
       const char *IN_input_value, size_t IN_input_value_len,
       const char *IN_target_value, size_t IN_target_value_len)

{
   sender_pid = algorithms_calculate_pid_get_sender();
   // In Debug mode and x86 builts only: log MSC data when environment variable is set
   static int innerMsc = -1;
   if (-1 == innerMsc)
     innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
   if (1 == innerMsc) {
      long long msc_time = getTimeInMilliseconds();
      printf ("INNER_PI: algorithms,calculate_pid,%lld\n", msc_time);
      fflush(stdout);
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void algorithms_PI_calculate_pid
      (asn1SccAuroraPWM *,
       const asn1SccAuroraPIDValue *,
       const asn1SccAuroraPIDValue *,
       const asn1SccAuroraPIDValue *,
       const asn1SccAuroraReal *,
       const asn1SccAuroraReal *);





   // Call user code
   algorithms_PI_calculate_pid ((asn1SccAuroraPWM *)OUT_output_value, (asn1SccAuroraPIDValue *)IN_k_p, (asn1SccAuroraPIDValue *)IN_k_i, (asn1SccAuroraPIDValue *)IN_k_d, (asn1SccAuroraReal *)IN_input_value, (asn1SccAuroraReal *)IN_target_value);

}

