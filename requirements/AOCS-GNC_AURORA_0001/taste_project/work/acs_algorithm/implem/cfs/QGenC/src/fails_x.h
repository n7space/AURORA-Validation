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

#ifndef FAILS_X_H
#define FAILS_X_H
#include "qgen_types.h"
#include "qgen_saturate_gareal.h"
#include "qgen_pow_gasingle.h"
#include "qgen_mod_gauint8.h"

extern void Fails_X_initOutputs
  (GASINGLE M_yz[3]);
extern void Fails_X_comp
  (GASINGLE const B_tot,
   GASINGLE const b[3],
   GASINGLE const T_Nm[3],
   GASINGLE M_yz[3]);

#endif
/*  @EOF  */
