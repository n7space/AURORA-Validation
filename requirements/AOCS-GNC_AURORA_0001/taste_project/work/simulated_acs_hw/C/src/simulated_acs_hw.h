/* Header file for function Simulated_ACS_HW
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

void simulated_acs_hw_startup(void);

/* Provided interfaces */
void simulated_acs_hw_PI_Read_MGM( asn1SccT_B_b_T * );


void simulated_acs_hw_PI_control_MGT( const asn1SccT_Control * );


void simulated_acs_hw_PI_get_step( asn1SccT_UInteger32 * );


void simulated_acs_hw_PI_set_step( const asn1SccT_UInteger32 * );

/* Required interfaces */



#ifdef __cplusplus
}
#endif