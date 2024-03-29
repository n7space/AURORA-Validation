#ifndef __PRINTTYPESASASN1_H__
#define __PRINTTYPESASASN1_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dataview-uniq.h" // Generated by ASN1SCC

void PrintASN1AuroraInt(const char *paramName, const asn1SccAuroraInt *pData);
void PrintASN1AuroraUInt(const char *paramName, const asn1SccAuroraUInt *pData);
void PrintASN1AuroraReal(const char *paramName, const asn1SccAuroraReal *pData);
void PrintASN1AuroraVoltage(const char *paramName, const asn1SccAuroraVoltage *pData);
void PrintASN1AuroraCurrent(const char *paramName, const asn1SccAuroraCurrent *pData);
void PrintASN1AuroraPWM(const char *paramName, const asn1SccAuroraPWM *pData);
void PrintASN1AuroraPIDValue(const char *paramName, const asn1SccAuroraPIDValue *pData);
void PrintASN1AuroraTemperature(const char *paramName, const asn1SccAuroraTemperature *pData);
void PrintASN1AuroraFlowRate(const char *paramName, const asn1SccAuroraFlowRate *pData);
void PrintASN1AuroraBatteryCapacity(const char *paramName, const asn1SccAuroraBatteryCapacity *pData);
void PrintASN1AuroraControllerStatus(const char *paramName, const asn1SccAuroraControllerStatus *pData);
void PrintASN1T_Int32(const char *paramName, const asn1SccT_Int32 *pData);
void PrintASN1T_UInt32(const char *paramName, const asn1SccT_UInt32 *pData);
void PrintASN1T_Int8(const char *paramName, const asn1SccT_Int8 *pData);
void PrintASN1T_UInt8(const char *paramName, const asn1SccT_UInt8 *pData);
void PrintASN1T_Boolean(const char *paramName, const asn1SccT_Boolean *pData);
void PrintASN1T_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData);
void PrintASN1PID_Range(const char *paramName, const asn1SccPID_Range *pData);
void PrintASN1PID(const char *paramName, const asn1SccPID *pData);

#ifdef __cplusplus
}
#endif

#endif
