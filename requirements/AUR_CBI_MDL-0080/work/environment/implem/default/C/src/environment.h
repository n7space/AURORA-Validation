/* Header file for function Environment
 * Generated by TASTE (kazoo/templates/skeletons/c-header/function.tmplt)
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

void environment_startup(void);

/* Provided interfaces */
void environment_PI_Trigger( void );

/* Required interfaces */
extern void environment_RI_CfsTimestamp( const asn1SccULongInteger *, asn1SccCfsTimestamp * );


extern void environment_RI_CfsTimestampCmp( const asn1SccCfsTimestamp *, const asn1SccCfsTimestamp *, asn1SccComparisonResult * );


extern void environment_RI_ObetTime( asn1SccULongInteger * );


#ifdef __cplusplus
}
#endif
