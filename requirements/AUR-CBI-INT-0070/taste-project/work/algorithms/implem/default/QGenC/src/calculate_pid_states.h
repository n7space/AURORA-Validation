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

#ifndef CALCULATE_PID_STATES_H
#define CALCULATE_PID_STATES_H
#include "qgen_types.h"

typedef struct {
   GAREAL Discrete_Time_Integrator_in_memory;
   GAREAL Discrete_Time_Integrator_out_memory;
   GAREAL Discrete_Time_Integrator_gain;
   GAREAL Discrete_Time_Integrator_init_cond;
   GAREAL Discrete_Derivative_memory;
   GAREAL Unit_Delay_memory;
   /* Memory from calculate_pid/Unit Delay */

   GAREAL Ki_out1;
   /* Output from calculate_pid/Ki/OutDataPort1 */

   GAREAL Kd_out1;
   /* Output from calculate_pid/Kd/OutDataPort1 */

   GAREAL Constant_out1;
   /* Output from calculate_pid/Constant/OutDataPort1 */

} calculate_pid_State;

#endif
/*  @EOF  */
