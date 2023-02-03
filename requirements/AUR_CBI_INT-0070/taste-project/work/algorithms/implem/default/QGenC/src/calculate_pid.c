/* Copyright (C) Your Company Name */
/*
 * @generated with QGen Code Generator 23.0w (20211221)
 * Command line arguments: ./xmi/calculate_pid.xmi
 *   --gen-entrypoint
 *   --wrap-io
 *   --pre-process-xmi
 *   --incremental
 *   --no-misra
 *   --language c
 *   --output src
*/

#include "calculate_pid.h"

void calculate_pid_initStates
  (calculate_pid_State* const State)
{
   /* Block 'calculate_pid/Discrete-Time Integrator' */
   State->Discrete_Time_Integrator_gain = 1.0E+00;
   State->Discrete_Time_Integrator_in_memory = 0.0E+00;
   State->Discrete_Time_Integrator_init_cond = 0.0E+00;
   State->Discrete_Time_Integrator_out_memory = State->Discrete_Time_Integrator_init_cond;
   /* End Block 'calculate_pid/Discrete-Time Integrator' */

   /* Block 'calculate_pid/Discrete Derivative' */
   State->Discrete_Derivative_memory = 0.0E+00;
   /* End Block 'calculate_pid/Discrete Derivative' */

   /* Block 'calculate_pid/Unit Delay' */
   State->Unit_Delay_memory = 0.0E+00;
   /* End Block 'calculate_pid/Unit Delay' */

}
void calculate_pid_comp
  (AuroraPIDValue const k_p,
   AuroraPIDValue const k_i,
   AuroraPIDValue const k_d,
   AuroraReal const input_value,
   AuroraReal const target_value,
   AuroraPWM* const output_value,
   calculate_pid_State* const State)
{
   AuroraReal Sum1_out1;
   /* Output from calculate_pid/Sum1/OutDataPort1 */

   GAREAL Discrete_Time_Integrator_out1;
   /* Output from calculate_pid/Discrete-Time Integrator/OutDataPort1 */


   /* Block 'calculate_pid/target_value' */
   /* Block 'calculate_pid/input_value' */
   /* Block 'calculate_pid/Sum1' */
   Sum1_out1 = target_value - input_value;
   /* End Block 'calculate_pid/Sum1' */
   /* End Block 'calculate_pid/input_value' */
   /* End Block 'calculate_pid/target_value' */

   /* Block 'calculate_pid/Discrete-Time Integrator' */
   Discrete_Time_Integrator_out1 = State->Discrete_Time_Integrator_out_memory + State->Discrete_Time_Integrator_gain * 2.0E-01 * State->Discrete_Time_Integrator_in_memory;
   State->Discrete_Time_Integrator_out_memory = Discrete_Time_Integrator_out1;
   /* End Block 'calculate_pid/Discrete-Time Integrator' */

   /* Block 'calculate_pid/k_d' */
   /* Block 'calculate_pid/Kd' */
   State->Kd_out1 = Sum1_out1 * k_d;
   /* End Block 'calculate_pid/Kd' */
   /* End Block 'calculate_pid/k_d' */

   /* Block 'calculate_pid/Sum' */
   /* Block 'calculate_pid/k_p' */
   /* Block 'calculate_pid/Kp' */
   /* Block 'calculate_pid/Discrete Derivative' */
   /* Block 'calculate_pid/output_value' */
   *output_value = Sum1_out1 * k_p + Discrete_Time_Integrator_out1 + (State->Kd_out1 / 2.0E-01 - State->Discrete_Derivative_memory);
   /* End Block 'calculate_pid/output_value' */
   /* End Block 'calculate_pid/Discrete Derivative' */
   /* End Block 'calculate_pid/Kp' */
   /* End Block 'calculate_pid/k_p' */
   /* End Block 'calculate_pid/Sum' */

   /* Block 'calculate_pid/k_i' */
   /* Block 'calculate_pid/Ki' */
   State->Ki_out1 = Sum1_out1 * k_i;
   /* End Block 'calculate_pid/Ki' */
   /* End Block 'calculate_pid/k_i' */

   /* Block 'calculate_pid/Constant' */
   State->Constant_out1 = 1.0E+00;
   /* End Block 'calculate_pid/Constant' */

}
void calculate_pid_up
  (calculate_pid_State* const State)
{
   /* update 'calculate_pid/Discrete-Time Integrator' */
   State->Discrete_Time_Integrator_in_memory = State->Ki_out1;
   /* End update 'calculate_pid/Discrete-Time Integrator' */

   /* update 'calculate_pid/Discrete Derivative' */
   State->Discrete_Derivative_memory = State->Kd_out1 / 2.0E-01;
   /* End update 'calculate_pid/Discrete Derivative' */

   /* update 'calculate_pid/Unit Delay' */
   State->Unit_Delay_memory = State->Constant_out1;
   /* End update 'calculate_pid/Unit Delay' */

}
/*  @EOF  */
