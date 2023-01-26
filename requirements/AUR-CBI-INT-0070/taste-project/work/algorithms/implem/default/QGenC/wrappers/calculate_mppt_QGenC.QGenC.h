#ifndef __QGENC_DATAVIEW_UNIQASN_CALCULATE_MPPT_QGENC_H__
#define __QGENC_DATAVIEW_UNIQASN_CALCULATE_MPPT_QGENC_H__

#include <stdlib.h> /* for size_t */

int Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage(void *pBuffer);
int Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current(void *pBuffer);
int Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm(void *pBuffer);
void Execute_calculate_mppt_QGenC(void);
void algorithms_PI_calculate_mppt_startup(void);
void algorithms_PI_calculate_mppt(void *pvoltage, void *pcurrent, void *ppwm);

#endif
