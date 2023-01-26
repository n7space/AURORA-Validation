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

#include "calculate_mppt.h"

void calculate_mppt_initStates
  (calculate_mppt_State* const State)
{
   /* Block 'calculate_mppt/Unit Delay' */
   State->Unit_Delay_memory = 0.0E+00;
   /* End Block 'calculate_mppt/Unit Delay' */

}
void calculate_mppt_comp
  (AuroraVoltage const voltage,
   AuroraCurrent const current,
   AuroraPWM* const pwm,
   calculate_mppt_State* const State)
{
   /* Block 'calculate_mppt/Constant4' */
   /* Block 'calculate_mppt/Constant2' */
   /* Block 'calculate_mppt/Constant3' */
   /* Block 'calculate_mppt/Switch' */
   /* Block 'calculate_mppt/Sum' */
   /* Block 'calculate_mppt/Product' */
   /* Block 'calculate_mppt/current' */
   /* Block 'calculate_mppt/voltage' */
   /* Block 'calculate_mppt/Product1' */
   /* Block 'calculate_mppt/Constant1' */
   /* Block 'calculate_mppt/pwm' */
   *pwm = voltage * current * 3.5E-02 + 7.0E-01;
   /* End Block 'calculate_mppt/pwm' */
   /* End Block 'calculate_mppt/Constant1' */
   /* End Block 'calculate_mppt/Product1' */
   /* End Block 'calculate_mppt/voltage' */
   /* End Block 'calculate_mppt/current' */
   /* End Block 'calculate_mppt/Product' */
   /* End Block 'calculate_mppt/Sum' */
   /* End Block 'calculate_mppt/Switch' */
   /* End Block 'calculate_mppt/Constant3' */
   /* End Block 'calculate_mppt/Constant2' */
   /* End Block 'calculate_mppt/Constant4' */

   /* Block 'calculate_mppt/Constant' */
   State->Constant_out1 = 1.0E+00;
   /* End Block 'calculate_mppt/Constant' */

}
void calculate_mppt_up
  (calculate_mppt_State* const State)
{
   /* update 'calculate_mppt/Unit Delay' */
   State->Unit_Delay_memory = State->Constant_out1;
   /* End update 'calculate_mppt/Unit Delay' */

}
/*  @EOF  */
