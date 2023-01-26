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

#include "qgen_entry_calculate_pid.h"

calculate_pid_State calculate_pid_memory;
void qgen_entry_calculate_pid_init (void)
{
   calculate_pid_initStates (&calculate_pid_memory);
}
void qgen_entry_calculate_pid_comp
  (qgen_entry_calculate_pid_comp_Input const* const Input,
   qgen_entry_calculate_pid_comp_Output* const Output)
{
   calculate_pid_comp (Input->k_p, Input->k_i, Input->k_d, Input->input_value, Input->target_value, &Output->output_value, &calculate_pid_memory);
   calculate_pid_up (&calculate_pid_memory);
}
/*  @EOF  */
