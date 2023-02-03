#ifdef __unix__
#include <stdio.h>
#include <string.h>

#include <assert.h>
#endif

#ifndef STATIC
#define STATIC
#endif

#include "calculate_mppt_QGenC.QGenC.h"
#include "dataview-uniq.h" // Space certified compiler generated
#include "qgen_entry_calculate_mppt.h"

static qgen_entry_calculate_mppt_comp_Input cInput;

static qgen_entry_calculate_mppt_comp_Output cOutput;

int Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage(void *pBuffer)
{
    STATIC asn1SccAuroraVoltage var_AuroraVoltage;
    var_AuroraVoltage = *(asn1SccAuroraVoltage *) pBuffer;
    {
        cInput.voltage = var_AuroraVoltage;
        return 0;
    }
}

int Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current(void *pBuffer)
{
    STATIC asn1SccAuroraCurrent var_AuroraCurrent;
    var_AuroraCurrent = *(asn1SccAuroraCurrent *) pBuffer;
    {
        cInput.current = var_AuroraCurrent;
        return 0;
    }
}

int Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm(void *pBuffer)
{
    STATIC asn1SccAuroraPWM var_AuroraPWM;
    var_AuroraPWM = (double) cOutput.pwm;
    memcpy(pBuffer, &var_AuroraPWM, sizeof(asn1SccAuroraPWM) );
    return sizeof(asn1SccAuroraPWM);
}

void Execute_calculate_mppt_QGenC()
{
    qgen_entry_calculate_mppt_comp(&cInput, &cOutput);
}

void algorithms_PI_calculate_mppt_startup(void)
{
    static int initialized = 0;
    if (!initialized) {
        initialized = 1;
         qgen_entry_calculate_mppt_init();
    }
}

void algorithms_PI_calculate_mppt(void *pvoltage, void *pcurrent, void *ppwm)
{
    Convert_From_native_To_AuroraVoltage_In_calculate_mppt_QGenC_voltage(pvoltage);
    Convert_From_native_To_AuroraCurrent_In_calculate_mppt_QGenC_current(pcurrent);
    Execute_calculate_mppt_QGenC();
    Convert_From_AuroraPWM_To_native_In_calculate_mppt_QGenC_pwm(ppwm);
}

