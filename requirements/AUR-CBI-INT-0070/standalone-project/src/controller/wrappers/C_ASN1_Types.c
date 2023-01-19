#ifdef __unix__
#include <stdio.h>
#include <assert.h>
#endif

#include <string.h>

#include "C_ASN1_Types.h"

#ifdef __NEED_AuroraInt_UPER
int Encode_UPER_AuroraInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraInt *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraInt_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraInt (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraInt_ACN
int Encode_ACN_AuroraInt(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraInt *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraInt_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraInt (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraInt_NATIVE
int Encode_NATIVE_AuroraInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraInt *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraInt) );
    return sizeof(asn1SccAuroraInt);
}
#endif

#ifdef __NEED_AuroraInt_UPER
int Decode_UPER_AuroraInt(asn1SccAuroraInt *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraInt_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraInt (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraInt_ACN
int Decode_ACN_AuroraInt(asn1SccAuroraInt *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraInt_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraInt (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraInt_NATIVE
int Decode_NATIVE_AuroraInt(asn1SccAuroraInt *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraInt *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraUInt_UPER
int Encode_UPER_AuroraUInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraUInt *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraUInt_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraUInt (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraUInt_ACN
int Encode_ACN_AuroraUInt(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraUInt *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraUInt_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraUInt (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraUInt_NATIVE
int Encode_NATIVE_AuroraUInt(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraUInt *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraUInt) );
    return sizeof(asn1SccAuroraUInt);
}
#endif

#ifdef __NEED_AuroraUInt_UPER
int Decode_UPER_AuroraUInt(asn1SccAuroraUInt *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraUInt_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraUInt (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraUInt_ACN
int Decode_ACN_AuroraUInt(asn1SccAuroraUInt *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraUInt_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraUInt (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraUInt_NATIVE
int Decode_NATIVE_AuroraUInt(asn1SccAuroraUInt *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraUInt *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraReal_UPER
int Encode_UPER_AuroraReal(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraReal *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraReal_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraReal (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraReal_ACN
int Encode_ACN_AuroraReal(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraReal *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraReal_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraReal (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraReal_NATIVE
int Encode_NATIVE_AuroraReal(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraReal *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraReal) );
    return sizeof(asn1SccAuroraReal);
}
#endif

#ifdef __NEED_AuroraReal_UPER
int Decode_UPER_AuroraReal(asn1SccAuroraReal *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraReal_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraReal (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraReal_ACN
int Decode_ACN_AuroraReal(asn1SccAuroraReal *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraReal_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraReal (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraReal_NATIVE
int Decode_NATIVE_AuroraReal(asn1SccAuroraReal *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraReal *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraVoltage_UPER
int Encode_UPER_AuroraVoltage(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraVoltage *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraVoltage_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraVoltage (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraVoltage_ACN
int Encode_ACN_AuroraVoltage(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraVoltage *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraVoltage_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraVoltage (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraVoltage_NATIVE
int Encode_NATIVE_AuroraVoltage(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraVoltage *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraVoltage) );
    return sizeof(asn1SccAuroraVoltage);
}
#endif

#ifdef __NEED_AuroraVoltage_UPER
int Decode_UPER_AuroraVoltage(asn1SccAuroraVoltage *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraVoltage_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraVoltage (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraVoltage_ACN
int Decode_ACN_AuroraVoltage(asn1SccAuroraVoltage *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraVoltage_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraVoltage (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraVoltage_NATIVE
int Decode_NATIVE_AuroraVoltage(asn1SccAuroraVoltage *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraVoltage *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraCurrent_UPER
int Encode_UPER_AuroraCurrent(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraCurrent *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraCurrent_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraCurrent (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraCurrent_ACN
int Encode_ACN_AuroraCurrent(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraCurrent *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraCurrent_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraCurrent (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraCurrent_NATIVE
int Encode_NATIVE_AuroraCurrent(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraCurrent *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraCurrent) );
    return sizeof(asn1SccAuroraCurrent);
}
#endif

#ifdef __NEED_AuroraCurrent_UPER
int Decode_UPER_AuroraCurrent(asn1SccAuroraCurrent *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraCurrent_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraCurrent (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraCurrent_ACN
int Decode_ACN_AuroraCurrent(asn1SccAuroraCurrent *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraCurrent_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraCurrent (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraCurrent_NATIVE
int Decode_NATIVE_AuroraCurrent(asn1SccAuroraCurrent *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraCurrent *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraPWM_UPER
int Encode_UPER_AuroraPWM(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPWM *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraPWM_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraPWM (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraPWM_ACN
int Encode_ACN_AuroraPWM(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraPWM *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraPWM_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraPWM (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraPWM_NATIVE
int Encode_NATIVE_AuroraPWM(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPWM *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraPWM) );
    return sizeof(asn1SccAuroraPWM);
}
#endif

#ifdef __NEED_AuroraPWM_UPER
int Decode_UPER_AuroraPWM(asn1SccAuroraPWM *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraPWM_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraPWM (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraPWM_ACN
int Decode_ACN_AuroraPWM(asn1SccAuroraPWM *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraPWM_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraPWM (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraPWM_NATIVE
int Decode_NATIVE_AuroraPWM(asn1SccAuroraPWM *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraPWM *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraPIDValue_UPER
int Encode_UPER_AuroraPIDValue(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPIDValue *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraPIDValue_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraPIDValue (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraPIDValue_ACN
int Encode_ACN_AuroraPIDValue(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraPIDValue *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraPIDValue_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraPIDValue (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraPIDValue_NATIVE
int Encode_NATIVE_AuroraPIDValue(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraPIDValue *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraPIDValue) );
    return sizeof(asn1SccAuroraPIDValue);
}
#endif

#ifdef __NEED_AuroraPIDValue_UPER
int Decode_UPER_AuroraPIDValue(asn1SccAuroraPIDValue *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraPIDValue_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraPIDValue (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraPIDValue_ACN
int Decode_ACN_AuroraPIDValue(asn1SccAuroraPIDValue *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraPIDValue_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraPIDValue (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraPIDValue_NATIVE
int Decode_NATIVE_AuroraPIDValue(asn1SccAuroraPIDValue *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraPIDValue *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraTemperature_UPER
int Encode_UPER_AuroraTemperature(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraTemperature *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraTemperature_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraTemperature (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraTemperature_ACN
int Encode_ACN_AuroraTemperature(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraTemperature *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraTemperature_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraTemperature (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraTemperature_NATIVE
int Encode_NATIVE_AuroraTemperature(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraTemperature *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraTemperature) );
    return sizeof(asn1SccAuroraTemperature);
}
#endif

#ifdef __NEED_AuroraTemperature_UPER
int Decode_UPER_AuroraTemperature(asn1SccAuroraTemperature *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraTemperature_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraTemperature (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraTemperature_ACN
int Decode_ACN_AuroraTemperature(asn1SccAuroraTemperature *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraTemperature_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraTemperature (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraTemperature_NATIVE
int Decode_NATIVE_AuroraTemperature(asn1SccAuroraTemperature *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraTemperature *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraFlowRate_UPER
int Encode_UPER_AuroraFlowRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraFlowRate *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraFlowRate_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraFlowRate (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraFlowRate_ACN
int Encode_ACN_AuroraFlowRate(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraFlowRate *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraFlowRate_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraFlowRate (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraFlowRate_NATIVE
int Encode_NATIVE_AuroraFlowRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraFlowRate *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraFlowRate) );
    return sizeof(asn1SccAuroraFlowRate);
}
#endif

#ifdef __NEED_AuroraFlowRate_UPER
int Decode_UPER_AuroraFlowRate(asn1SccAuroraFlowRate *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraFlowRate_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraFlowRate (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraFlowRate_ACN
int Decode_ACN_AuroraFlowRate(asn1SccAuroraFlowRate *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraFlowRate_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraFlowRate (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraFlowRate_NATIVE
int Decode_NATIVE_AuroraFlowRate(asn1SccAuroraFlowRate *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraFlowRate *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraBatteryCapacity_UPER
int Encode_UPER_AuroraBatteryCapacity(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraBatteryCapacity *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraBatteryCapacity_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraBatteryCapacity (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraBatteryCapacity_ACN
int Encode_ACN_AuroraBatteryCapacity(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraBatteryCapacity *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraBatteryCapacity_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraBatteryCapacity (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraBatteryCapacity_NATIVE
int Encode_NATIVE_AuroraBatteryCapacity(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraBatteryCapacity *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraBatteryCapacity) );
    return sizeof(asn1SccAuroraBatteryCapacity);
}
#endif

#ifdef __NEED_AuroraBatteryCapacity_UPER
int Decode_UPER_AuroraBatteryCapacity(asn1SccAuroraBatteryCapacity *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraBatteryCapacity_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraBatteryCapacity (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraBatteryCapacity_ACN
int Decode_ACN_AuroraBatteryCapacity(asn1SccAuroraBatteryCapacity *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraBatteryCapacity_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraBatteryCapacity (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraBatteryCapacity_NATIVE
int Decode_NATIVE_AuroraBatteryCapacity(asn1SccAuroraBatteryCapacity *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraBatteryCapacity *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AuroraControllerStatus_UPER
int Encode_UPER_AuroraControllerStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraControllerStatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraControllerStatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraControllerStatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraControllerStatus_ACN
int Encode_ACN_AuroraControllerStatus(void *pBuffer, size_t iMaxBufferSize, asn1SccAuroraControllerStatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAuroraControllerStatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AuroraControllerStatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AuroraControllerStatus_NATIVE
int Encode_NATIVE_AuroraControllerStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAuroraControllerStatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAuroraControllerStatus) );
    return sizeof(asn1SccAuroraControllerStatus);
}
#endif

#ifdef __NEED_AuroraControllerStatus_UPER
int Decode_UPER_AuroraControllerStatus(asn1SccAuroraControllerStatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraControllerStatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraControllerStatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraControllerStatus_ACN
int Decode_ACN_AuroraControllerStatus(asn1SccAuroraControllerStatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAuroraControllerStatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AuroraControllerStatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AuroraControllerStatus_NATIVE
int Decode_NATIVE_AuroraControllerStatus(asn1SccAuroraControllerStatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAuroraControllerStatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int32) );
    return sizeof(asn1SccT_Int32);
}
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt32) );
    return sizeof(asn1SccT_UInt32);
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int8) );
    return sizeof(asn1SccT_Int8);
}
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt8) );
    return sizeof(asn1SccT_UInt8);
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Boolean) );
    return sizeof(asn1SccT_Boolean);
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Boolean *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Null_Record) );
    return sizeof(asn1SccT_Null_Record);
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Null_Record *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PID_Range_UPER
int Encode_UPER_PID_Range(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID_Range *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPID_Range_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PID-Range (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PID_Range_ACN
int Encode_ACN_PID_Range(void *pBuffer, size_t iMaxBufferSize, asn1SccPID_Range *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPID_Range_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PID-Range (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PID_Range_NATIVE
int Encode_NATIVE_PID_Range(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID_Range *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPID_Range) );
    return sizeof(asn1SccPID_Range);
}
#endif

#ifdef __NEED_PID_Range_UPER
int Decode_UPER_PID_Range(asn1SccPID_Range *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPID_Range_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PID-Range (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PID_Range_ACN
int Decode_ACN_PID_Range(asn1SccPID_Range *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPID_Range_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PID-Range (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PID_Range_NATIVE
int Decode_NATIVE_PID_Range(asn1SccPID_Range *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPID_Range *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PID_UPER
int Encode_UPER_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPID_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PID_ACN
int Encode_ACN_PID(void *pBuffer, size_t iMaxBufferSize, asn1SccPID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPID_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PID_NATIVE
int Encode_NATIVE_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPID) );
    return sizeof(asn1SccPID);
}
#endif

#ifdef __NEED_PID_UPER
int Decode_UPER_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPID_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PID_ACN
int Decode_ACN_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPID_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PID_NATIVE
int Decode_NATIVE_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPID *) pBuffer;
    {
        return 0;
    }
}
#endif

