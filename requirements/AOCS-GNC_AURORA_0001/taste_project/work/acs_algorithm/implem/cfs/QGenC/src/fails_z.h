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

#ifndef FAILS_Z_H
#define FAILS_Z_H
#include "qgen_types.h"
#include "qgen_saturate_gareal.h"
#include "qgen_pow_gasingle.h"
#include "qgen_mod_gauint8.h"

extern void Fails_Z_initOutputs
  (GASINGLE M_xy[3]);
extern void Fails_Z_comp
  (GASINGLE const B_tot,
   GASINGLE const b[3],
   GASINGLE const T_Nm[3],
   GASINGLE M_xy[3]);

#endif
/*  @EOF  */
