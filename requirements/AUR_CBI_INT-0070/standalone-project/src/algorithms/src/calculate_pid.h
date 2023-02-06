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

#ifndef CALCULATE_PID_H
#define CALCULATE_PID_H
#include "calculate_pid_states.h"
#include "qgen_base_workspace_aurorapidvalue.h"
#include "qgen_base_workspace_aurorareal.h"
#include "qgen_base_workspace_aurorapwm.h"
#include "qgen_types.h"

extern void calculate_pid_initStates
  (calculate_pid_State* const State);
extern void calculate_pid_comp
  (AuroraPIDValue const k_p,
   AuroraPIDValue const k_i,
   AuroraPIDValue const k_d,
   AuroraReal const input_value,
   AuroraReal const target_value,
   AuroraPWM* const output_value,
   calculate_pid_State* const State);
extern void calculate_pid_up
  (calculate_pid_State* const State);

#endif
/*  @EOF  */
