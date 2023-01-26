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

#include "qgen_entry_calculate_mppt.h"

calculate_mppt_State calculate_mppt_memory;
void qgen_entry_calculate_mppt_init (void)
{
   calculate_mppt_initStates (&calculate_mppt_memory);
}
void qgen_entry_calculate_mppt_comp
  (qgen_entry_calculate_mppt_comp_Input const* const Input,
   qgen_entry_calculate_mppt_comp_Output* const Output)
{
   calculate_mppt_comp (Input->voltage, Input->current, &Output->pwm, &calculate_mppt_memory);
   calculate_mppt_up (&calculate_mppt_memory);
}
/*  @EOF  */
