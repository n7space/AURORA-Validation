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

#ifndef Q_1_FAIL_STATES_H
#define Q_1_FAIL_STATES_H
#include "qgen_types.h"

typedef struct {
   GASINGLE Fails_X_M_yz[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/OutDataPort1 */

   GASINGLE Fails_Y_M_yz[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails Y/OutDataPort1 */

   GASINGLE Fails_Z_M_xy[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails Z/OutDataPort1 */

   GABOOL Fails_X_enabled;
   GABOOL Fails_Y_enabled;
   GABOOL Fails_Z_enabled;
} q_1_Fail_State;

#endif
/*  @EOF  */
