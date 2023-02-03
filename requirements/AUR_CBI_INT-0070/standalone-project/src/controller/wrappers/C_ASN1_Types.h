#ifndef __C_DATAVIEW_UNIQ_H__
#define __C_DATAVIEW_UNIQ_H__

#if defined( __unix__ ) || defined( __MSP430__ )
#include <stdlib.h> /* for size_t */
#else
typedef unsigned size_t;
#endif

#ifndef STATIC
#define STATIC
#endif


#include "dataview-uniq.h" // Space certified compiler generated

#include "../../system_config.h" // Choose ASN.1 Types to use

#ifdef __NEED_AuroraInt_UPER
int Encode_UPER_AuroraInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraInt *pSrc);
#endif

#ifdef __NEED_AuroraInt_ACN
int Encode_ACN_AuroraInt(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraInt *pSrc);
#endif

#ifdef __NEED_AuroraInt_NATIVE
int Encode_NATIVE_AuroraInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraInt *pSrc);
#endif

#ifdef __NEED_AuroraInt_UPER
int Decode_UPER_AuroraInt(asn1SccAuroraInt *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraInt_ACN
int Decode_ACN_AuroraInt(asn1SccAuroraInt *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraInt_NATIVE
int Decode_NATIVE_AuroraInt(asn1SccAuroraInt *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraUInt_UPER
int Encode_UPER_AuroraUInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraUInt *pSrc);
#endif

#ifdef __NEED_AuroraUInt_ACN
int Encode_ACN_AuroraUInt(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraUInt *pSrc);
#endif

#ifdef __NEED_AuroraUInt_NATIVE
int Encode_NATIVE_AuroraUInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraUInt *pSrc);
#endif

#ifdef __NEED_AuroraUInt_UPER
int Decode_UPER_AuroraUInt(asn1SccAuroraUInt *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraUInt_ACN
int Decode_ACN_AuroraUInt(asn1SccAuroraUInt *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraUInt_NATIVE
int Decode_NATIVE_AuroraUInt(asn1SccAuroraUInt *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraReal_UPER
int Encode_UPER_AuroraReal(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraReal *pSrc);
#endif

#ifdef __NEED_AuroraReal_ACN
int Encode_ACN_AuroraReal(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraReal *pSrc);
#endif

#ifdef __NEED_AuroraReal_NATIVE
int Encode_NATIVE_AuroraReal(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraReal *pSrc);
#endif

#ifdef __NEED_AuroraReal_UPER
int Decode_UPER_AuroraReal(asn1SccAuroraReal *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraReal_ACN
int Decode_ACN_AuroraReal(asn1SccAuroraReal *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraReal_NATIVE
int Decode_NATIVE_AuroraReal(asn1SccAuroraReal *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraVoltage_UPER
int Encode_UPER_AuroraVoltage(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraVoltage *pSrc);
#endif

#ifdef __NEED_AuroraVoltage_ACN
int Encode_ACN_AuroraVoltage(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraVoltage *pSrc);
#endif

#ifdef __NEED_AuroraVoltage_NATIVE
int Encode_NATIVE_AuroraVoltage(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraVoltage *pSrc);
#endif

#ifdef __NEED_AuroraVoltage_UPER
int Decode_UPER_AuroraVoltage(asn1SccAuroraVoltage *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraVoltage_ACN
int Decode_ACN_AuroraVoltage(asn1SccAuroraVoltage *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraVoltage_NATIVE
int Decode_NATIVE_AuroraVoltage(asn1SccAuroraVoltage *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraCurrent_UPER
int Encode_UPER_AuroraCurrent(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraCurrent *pSrc);
#endif

#ifdef __NEED_AuroraCurrent_ACN
int Encode_ACN_AuroraCurrent(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraCurrent *pSrc);
#endif

#ifdef __NEED_AuroraCurrent_NATIVE
int Encode_NATIVE_AuroraCurrent(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraCurrent *pSrc);
#endif

#ifdef __NEED_AuroraCurrent_UPER
int Decode_UPER_AuroraCurrent(asn1SccAuroraCurrent *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraCurrent_ACN
int Decode_ACN_AuroraCurrent(asn1SccAuroraCurrent *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraCurrent_NATIVE
int Decode_NATIVE_AuroraCurrent(asn1SccAuroraCurrent *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraPWM_UPER
int Encode_UPER_AuroraPWM(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPWM *pSrc);
#endif

#ifdef __NEED_AuroraPWM_ACN
int Encode_ACN_AuroraPWM(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraPWM *pSrc);
#endif

#ifdef __NEED_AuroraPWM_NATIVE
int Encode_NATIVE_AuroraPWM(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPWM *pSrc);
#endif

#ifdef __NEED_AuroraPWM_UPER
int Decode_UPER_AuroraPWM(asn1SccAuroraPWM *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraPWM_ACN
int Decode_ACN_AuroraPWM(asn1SccAuroraPWM *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraPWM_NATIVE
int Decode_NATIVE_AuroraPWM(asn1SccAuroraPWM *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraPIDValue_UPER
int Encode_UPER_AuroraPIDValue(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPIDValue *pSrc);
#endif

#ifdef __NEED_AuroraPIDValue_ACN
int Encode_ACN_AuroraPIDValue(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraPIDValue *pSrc);
#endif

#ifdef __NEED_AuroraPIDValue_NATIVE
int Encode_NATIVE_AuroraPIDValue(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPIDValue *pSrc);
#endif

#ifdef __NEED_AuroraPIDValue_UPER
int Decode_UPER_AuroraPIDValue(asn1SccAuroraPIDValue *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraPIDValue_ACN
int Decode_ACN_AuroraPIDValue(asn1SccAuroraPIDValue *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraPIDValue_NATIVE
int Decode_NATIVE_AuroraPIDValue(asn1SccAuroraPIDValue *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraTemperature_UPER
int Encode_UPER_AuroraTemperature(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraTemperature *pSrc);
#endif

#ifdef __NEED_AuroraTemperature_ACN
int Encode_ACN_AuroraTemperature(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraTemperature *pSrc);
#endif

#ifdef __NEED_AuroraTemperature_NATIVE
int Encode_NATIVE_AuroraTemperature(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraTemperature *pSrc);
#endif

#ifdef __NEED_AuroraTemperature_UPER
int Decode_UPER_AuroraTemperature(asn1SccAuroraTemperature *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraTemperature_ACN
int Decode_ACN_AuroraTemperature(asn1SccAuroraTemperature *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraTemperature_NATIVE
int Decode_NATIVE_AuroraTemperature(asn1SccAuroraTemperature *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraFlowRate_UPER
int Encode_UPER_AuroraFlowRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraFlowRate *pSrc);
#endif

#ifdef __NEED_AuroraFlowRate_ACN
int Encode_ACN_AuroraFlowRate(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraFlowRate *pSrc);
#endif

#ifdef __NEED_AuroraFlowRate_NATIVE
int Encode_NATIVE_AuroraFlowRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraFlowRate *pSrc);
#endif

#ifdef __NEED_AuroraFlowRate_UPER
int Decode_UPER_AuroraFlowRate(asn1SccAuroraFlowRate *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraFlowRate_ACN
int Decode_ACN_AuroraFlowRate(asn1SccAuroraFlowRate *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraFlowRate_NATIVE
int Decode_NATIVE_AuroraFlowRate(asn1SccAuroraFlowRate *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraBatteryCapacity_UPER
int Encode_UPER_AuroraBatteryCapacity(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraBatteryCapacity *pSrc);
#endif

#ifdef __NEED_AuroraBatteryCapacity_ACN
int Encode_ACN_AuroraBatteryCapacity(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraBatteryCapacity *pSrc);
#endif

#ifdef __NEED_AuroraBatteryCapacity_NATIVE
int Encode_NATIVE_AuroraBatteryCapacity(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraBatteryCapacity *pSrc);
#endif

#ifdef __NEED_AuroraBatteryCapacity_UPER
int Decode_UPER_AuroraBatteryCapacity(asn1SccAuroraBatteryCapacity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraBatteryCapacity_ACN
int Decode_ACN_AuroraBatteryCapacity(asn1SccAuroraBatteryCapacity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraBatteryCapacity_NATIVE
int Decode_NATIVE_AuroraBatteryCapacity(asn1SccAuroraBatteryCapacity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraControllerStatus_UPER
int Encode_UPER_AuroraControllerStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraControllerStatus *pSrc);
#endif

#ifdef __NEED_AuroraControllerStatus_ACN
int Encode_ACN_AuroraControllerStatus(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraControllerStatus *pSrc);
#endif

#ifdef __NEED_AuroraControllerStatus_NATIVE
int Encode_NATIVE_AuroraControllerStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraControllerStatus *pSrc);
#endif

#ifdef __NEED_AuroraControllerStatus_UPER
int Decode_UPER_AuroraControllerStatus(asn1SccAuroraControllerStatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraControllerStatus_ACN
int Decode_ACN_AuroraControllerStatus(asn1SccAuroraControllerStatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AuroraControllerStatus_NATIVE
int Decode_NATIVE_AuroraControllerStatus(asn1SccAuroraControllerStatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_Range_UPER
int Encode_UPER_PID_Range(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID_Range *pSrc);
#endif

#ifdef __NEED_PID_Range_ACN
int Encode_ACN_PID_Range(void *pBuffer, size_t iMaxBufferSize, asn1SccPID_Range *pSrc);
#endif

#ifdef __NEED_PID_Range_NATIVE
int Encode_NATIVE_PID_Range(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID_Range *pSrc);
#endif

#ifdef __NEED_PID_Range_UPER
int Decode_UPER_PID_Range(asn1SccPID_Range *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_Range_ACN
int Decode_ACN_PID_Range(asn1SccPID_Range *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_Range_NATIVE
int Decode_NATIVE_PID_Range(asn1SccPID_Range *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_UPER
int Encode_UPER_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc);
#endif

#ifdef __NEED_PID_ACN
int Encode_ACN_PID(void *pBuffer, size_t iMaxBufferSize, asn1SccPID *pSrc);
#endif

#ifdef __NEED_PID_NATIVE
int Encode_NATIVE_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc);
#endif

#ifdef __NEED_PID_UPER
int Decode_UPER_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_ACN
int Decode_ACN_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_NATIVE
int Decode_NATIVE_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize);
#endif


#endif
