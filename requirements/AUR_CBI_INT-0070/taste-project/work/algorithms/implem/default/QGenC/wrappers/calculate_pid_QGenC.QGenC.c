#ifdef __unix__
#include <stdio.h>
#include <string.h>

#include <assert.h>
#endif

#ifndef STATIC
#define STATIC
#endif

#include "calculate_pid_QGenC.QGenC.h"
#include "dataview-uniq.h" // Space certified compiler generated
#include "qgen_entry_calculate_pid.h"

static qgen_entry_calculate_pid_comp_Input cInput;

static qgen_entry_calculate_pid_comp_Output cOutput;

int Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value(void *pBuffer)
{
    STATIC asn1SccAuroraPWM var_AuroraPWM;
    var_AuroraPWM = (double) cOutput.output_value;
    memcpy(pBuffer, &var_AuroraPWM, sizeof(asn1SccAuroraPWM) );
    return sizeof(asn1SccAuroraPWM);
}

int Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p(void *pBuffer)
{
    STATIC asn1SccAuroraPIDValue var_AuroraPIDValue;
    var_AuroraPIDValue = *(asn1SccAuroraPIDValue *) pBuffer;
    {
        cInput.k_p = var_AuroraPIDValue;
        return 0;
    }
}

int Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i(void *pBuffer)
{
    STATIC asn1SccAuroraPIDValue var_AuroraPIDValue;
    var_AuroraPIDValue = *(asn1SccAuroraPIDValue *) pBuffer;
    {
        cInput.k_i = var_AuroraPIDValue;
        return 0;
    }
}

int Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d(void *pBuffer)
{
    STATIC asn1SccAuroraPIDValue var_AuroraPIDValue;
    var_AuroraPIDValue = *(asn1SccAuroraPIDValue *) pBuffer;
    {
        cInput.k_d = var_AuroraPIDValue;
        return 0;
    }
}

int Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value(void *pBuffer)
{
    STATIC asn1SccAuroraReal var_AuroraReal;
    var_AuroraReal = *(asn1SccAuroraReal *) pBuffer;
    {
        cInput.input_value = var_AuroraReal;
        return 0;
    }
}

int Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value(void *pBuffer)
{
    STATIC asn1SccAuroraReal var_AuroraReal;
    var_AuroraReal = *(asn1SccAuroraReal *) pBuffer;
    {
        cInput.target_value = var_AuroraReal;
        return 0;
    }
}

void Execute_calculate_pid_QGenC()
{
    qgen_entry_calculate_pid_comp(&cInput, &cOutput);
}

void algorithms_PI_calculate_pid_startup(void)
{
    static int initialized = 0;
    if (!initialized) {
        initialized = 1;
         qgen_entry_calculate_pid_init();
    }
}

void algorithms_PI_calculate_pid(void *poutput_value, void *pk_p, void *pk_i, void *pk_d, void *pinput_value, void *ptarget_value)
{
    Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_p(pk_p);
    Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_i(pk_i);
    Convert_From_native_To_AuroraPIDValue_In_calculate_pid_QGenC_k_d(pk_d);
    Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_input_value(pinput_value);
    Convert_From_native_To_AuroraReal_In_calculate_pid_QGenC_target_value(ptarget_value);
    Execute_calculate_pid_QGenC();
    Convert_From_AuroraPWM_To_native_In_calculate_pid_QGenC_output_value(poutput_value);
}

