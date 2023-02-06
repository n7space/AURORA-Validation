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

#ifndef QGEN_TYPE_WRAP_IO_QGEN_ENTRY_CALCULATE_MPPT_H
#define QGEN_TYPE_WRAP_IO_QGEN_ENTRY_CALCULATE_MPPT_H
#include "qgen_base_workspace_auroravoltage.h"
#include "qgen_base_workspace_auroracurrent.h"
#include "qgen_base_workspace_aurorapwm.h"

typedef struct {
   AuroraVoltage voltage;
   AuroraCurrent current;
} qgen_entry_calculate_mppt_comp_Input;
typedef struct {
   AuroraPWM pwm;
} qgen_entry_calculate_mppt_comp_Output;

#endif
/*  @EOF  */
