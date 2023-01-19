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

#ifndef QGEN_TYPE_WRAP_IO_QGEN_ENTRY_CALCULATE_PID_H
#define QGEN_TYPE_WRAP_IO_QGEN_ENTRY_CALCULATE_PID_H
#include "qgen_base_workspace_aurorapidvalue.h"
#include "qgen_base_workspace_aurorareal.h"
#include "qgen_base_workspace_aurorapwm.h"

typedef struct {
   AuroraPIDValue k_p;
   AuroraPIDValue k_i;
   AuroraPIDValue k_d;
   AuroraReal input_value;
   AuroraReal target_value;
} qgen_entry_calculate_pid_comp_Input;
typedef struct {
   AuroraPWM output_value;
} qgen_entry_calculate_pid_comp_Output;

#endif
/*  @EOF  */
