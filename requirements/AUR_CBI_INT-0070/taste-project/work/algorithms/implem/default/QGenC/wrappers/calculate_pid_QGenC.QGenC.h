#ifndef __QGENC_DATAVIEW_UNIQASN_CALCULATE_PID_QGENC_H__
#define __QGENC_DATAVIEW_UNIQASN_CALCULATE_PID_QGENC_H__

#include <stdlib.h> /* for size_t */

int Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value(void *pBuffer);
int Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p(void *pBuffer);
int Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i(void *pBuffer);
int Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d(void *pBuffer);
int Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value(void *pBuffer);
int Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value(void *pBuffer);
void Execute_calculate_pid_QGenC(void);
void algorithms_PI_calculate_pid_startup(void);
void algorithms_PI_calculate_pid(void *poutput_value, void *pk_p, void *pk_i, void *pk_d, void *pinput_value, void *ptarget_value);

#endif
