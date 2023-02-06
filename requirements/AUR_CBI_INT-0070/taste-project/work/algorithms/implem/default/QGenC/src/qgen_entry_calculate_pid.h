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

#ifndef QGEN_ENTRY_CALCULATE_PID_H
#define QGEN_ENTRY_CALCULATE_PID_H
#include "calculate_pid.h"
#include "qgen_type_wrap_io_qgen_entry_calculate_pid.h"
#include "calculate_pid_states.h"

extern calculate_pid_State calculate_pid_memory;
extern void qgen_entry_calculate_pid_init (void);
extern void qgen_entry_calculate_pid_comp
  (qgen_entry_calculate_pid_comp_Input const* const Input,
   qgen_entry_calculate_pid_comp_Output* const Output);

#endif
/*  @EOF  */
