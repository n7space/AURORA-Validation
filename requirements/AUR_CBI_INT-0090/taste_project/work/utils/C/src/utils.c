/* Body file for function utils
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "utils.h"
//#include <stdio.h>


void utils_startup(void)
{
   // Write your initialisation code
   // You may call sporadic required interfaces and start timers
   // puts ("[utils] Startup");
}

void utils_PI_calc
      (const asn1SccMyInteger *IN_calcin1,
       const asn1SccMyReal *IN_calcin2,
       const asn1SccMyBool *IN_calcin3,
       const asn1SccMySeqOf *IN_calcin4,
       const asn1SccMySeq *IN_calcin5,
       asn1SccMyInteger *OUT_calcout1,
       asn1SccMyReal *OUT_calcout2,
       asn1SccMyBool *OUT_calcout3,
       asn1SccMySeqOf *OUT_calcout4,
       asn1SccMySeq *OUT_calcout5)
{
    *OUT_calcout1 = (*IN_calcin1) * 2;
    *OUT_calcout2 = (*IN_calcin2) * 2;
    *OUT_calcout3 = ! (*IN_calcin3);
    *OUT_calcout4 = (*IN_calcin4);
    *OUT_calcout5 = (*IN_calcin5);
}