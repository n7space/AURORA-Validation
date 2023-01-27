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

#include "fails_x.h"

void Fails_X_initOutputs
  (GASINGLE M_yz[3])
{
   GAUINT8 i;

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/M_yz' */
   for (i = 0; i <= 2; i++) {
      M_yz[i] = 0.0E+00;
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/M_yz' */

}
void Fails_X_comp
  (GASINGLE const B_tot,
   GASINGLE const b[3],
   GASINGLE const T_Nm[3],
   GASINGLE M_yz[3])
{
   GASINGLE Mux_1_out1[6];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Mux/OutDataPort1 */

   GASINGLE Reshape_out1[2][3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Reshape/OutDataPort1 */

   GASINGLE Product1_out1[2];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Product1/OutDataPort1 */

   GASINGLE Product3_out1[2];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Product3/OutDataPort1 */

   GASINGLE Mux_out1[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Mux/OutDataPort1 */

   GAUINT8 Idx;
   GAUINT8 i;
   GAUINT8 h;
   GAUINT8 Idx1;

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn9' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn8' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn7' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn6' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn5' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn10' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/b' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Mux' */
   Mux_1_out1[0] = b[2];
   Mux_1_out1[1] = -b[1];
   Mux_1_out1[2] = b[1] * b[2] / (b[0] + (GASINGLE) qgen_saturate_gareal (1.0E-10 * (GAREAL) (b[0] == 0.0E+00), 3.4028234663852886E+38, -3.4028234663852886E+38, GATRUE));
   /* Value '2.0E+00' below was obtained by casting and saturating the evaluated value 'Saturating_Cast (2.0E+00, T real single)' to single */
   /* Value '1.0E+00' below was obtained by casting and saturating the evaluated value 'Saturating_Cast (1.0E+00, T real single)' to single */
   Mux_1_out1[3] = (1.0E+00 - qgen_pow_gasingle (b[1], 2.0E+00)) / (b[0] + (GASINGLE) qgen_saturate_gareal (1.0E-10 * (GAREAL) (b[0] == 0.0E+00), 3.4028234663852886E+38, -3.4028234663852886E+38, GATRUE));
   /* Value '2.0E+00' below was obtained by casting and saturating the evaluated value 'Saturating_Cast (2.0E+00, T real single)' to single */
   /* Value '1.0E+00' below was obtained by casting and saturating the evaluated value 'Saturating_Cast (1.0E+00, T real single)' to single */
   Mux_1_out1[4] = -(1.0E+00 - qgen_pow_gasingle (b[2], 2.0E+00)) / (b[0] + (GASINGLE) qgen_saturate_gareal (1.0E-10 * (GAREAL) (b[0] == 0.0E+00), 3.4028234663852886E+38, -3.4028234663852886E+38, GATRUE));
   Mux_1_out1[5] = -(b[1] * b[2]) / (b[0] + (GASINGLE) qgen_saturate_gareal (1.0E-10 * (GAREAL) (b[0] == 0.0E+00), 3.4028234663852886E+38, -3.4028234663852886E+38, GATRUE));
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Mux' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/b' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn10' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn5' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn6' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn7' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn8' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Fcn9' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Reshape' */
   for (Idx = 0; Idx <= 5; Idx++) {
      Reshape_out1[qgen_mod_gauint8 (Idx, 2)][Idx / 2] = Mux_1_out1[Idx];
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Matrix x-fails/Reshape' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/T_Nm' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Product1' */
   for (i = 0; i <= 1; i++) {
      Product1_out1[i] = Reshape_out1[i][0] * T_Nm[0];
      for (h = 1; h <= 2; h++) {
         Product1_out1[i] = Product1_out1[i] + Reshape_out1[i][h] * T_Nm[h];
      }
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Product1' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/T_Nm' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/B_tot' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Product3' */
   for (i = 0; i <= 1; i++) {
      Product3_out1[i] = 1.0E+00 / B_tot * Product1_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Product3' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/B_tot' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Constant' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Mux' */
   Mux_out1[0] = 0.0E+00;
   for (Idx1 = 0; Idx1 <= 1; Idx1++) {
      Mux_out1[Idx1 + 1] = Product3_out1[Idx1];
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Mux' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/Constant' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/M_yz' */
   for (i = 0; i <= 2; i++) {
      M_yz[i] = Mux_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail/Fails X/M_yz' */

}
/*  @EOF  */
