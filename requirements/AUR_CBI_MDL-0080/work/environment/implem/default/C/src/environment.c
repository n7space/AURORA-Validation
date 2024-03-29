/* Body file for function Environment
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/

#include "environment.h"
#include "logs.h"

#include <time.h>
#include <unistd.h>

#define CUC_TIME_ARRAY_SIZE 7

void environment_startup(void)
{

}

#define SECONDS_IDX 3

asn1SccCfsTimestamp getCfsTimestamp()
{
   asn1SccCfsTimestamp timestamp;
   asn1SccULongInteger nseconds;
   timeservice_PI_ObetTime(&nseconds);
   timeservice_PI_CfsTimestamp(&nseconds, &timestamp);

   return timestamp;
}

void environment_PI_Trigger(void)
{
   asn1SccULongInteger nseconds;
   timeservice_PI_ObetTime(&nseconds);
   LOG_VARIABLE_ENDL("Nanoseconds from start: ", nseconds);

   asn1SccCfsTimestamp firstCfsTimestamp = getCfsTimestamp();
   LOG_VARIABLE_ENDL("First cFS timestamp seconds: ", firstCfsTimestamp.seconds);
   LOG_VARIABLE_ENDL("First cFS timestamp subseconds: ", firstCfsTimestamp.subseconds);

   asn1SccCfsTimestamp secondCfsTimestamp = getCfsTimestamp();
   LOG_VARIABLE_ENDL("Second cFS timestamp seconds: ", secondCfsTimestamp.seconds);
   LOG_VARIABLE_ENDL("Second cFS timestamp subseconds: ", secondCfsTimestamp.subseconds);

   asn1SccComparisonResult compareResultCfs = 0;
   environment_RI_CfsTimestampCmp(&secondCfsTimestamp, &firstCfsTimestamp, &compareResultCfs);
   LOG_VARIABLE_ENDL("cFS timestamps comparison result: ", compareResultCfs);
   LOG("\n");
}
