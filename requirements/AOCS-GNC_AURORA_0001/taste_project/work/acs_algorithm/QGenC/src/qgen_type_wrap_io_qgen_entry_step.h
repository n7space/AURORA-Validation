/* Copyright (C) Your Company Name */
/*
 * @generated with QGen Code Generator 23.0 (20221010)
 * Command line arguments: ./xmi/Step.xmi
 *   --gen-entrypoint
 *   --wrap-io
 *   --pre-process-xmi
 *   --incremental
 *   --no-misra
 *   --language c
 *   --output src
*/

#ifndef QGEN_TYPE_WRAP_IO_QGEN_ENTRY_STEP_H
#define QGEN_TYPE_WRAP_IO_QGEN_ENTRY_STEP_H
#include "simulink_definition_of_types.h"

typedef struct {
   T_B_b_T BBT;
   T_Omega Omega;
   T_Float K_PB;
   T_Float K_PE;
   T_Float M_M;
   T_MT_Working MT_Working;
} qgen_entry_Step_comp_Input;
typedef struct {
   T_Control Control;
} qgen_entry_Step_comp_Output;

#endif
/*  @EOF  */
