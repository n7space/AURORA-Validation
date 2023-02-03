/* Copyright (C) Your Company Name */
/*
 * @generated with QGen Code Generator 23.0w (20211221)
 * Command line arguments: ./xmi/calculate_mppt.xmi
 *   --gen-entrypoint
 *   --wrap-io
 *   --pre-process-xmi
 *   --incremental
 *   --no-misra
 *   --language c
 *   --output src
*/

#ifndef CALCULATE_MPPT_H
#define CALCULATE_MPPT_H
#include "calculate_mppt_states.h"
#include "qgen_base_workspace_auroravoltage.h"
#include "qgen_base_workspace_auroracurrent.h"
#include "qgen_base_workspace_aurorapwm.h"

extern void calculate_mppt_initStates
  (calculate_mppt_State* const State);
extern void calculate_mppt_comp
  (AuroraVoltage const voltage,
   AuroraCurrent const current,
   AuroraPWM* const pwm,
   calculate_mppt_State* const State);
extern void calculate_mppt_up
  (calculate_mppt_State* const State);

#endif
/*  @EOF  */
