/* Body file for function Controller
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "controller.h"

#include <CbiPartitionApi.h>

// Implemented in manager.c
extern void print_rtems(const char *str);

static void startup_on_processor_reset()
{
   print_rtems("Controller starting up on processor reset\n");
}

static void startup_on_power_reset()
{
   print_rtems("Controller starting up on power reset\n");
}

void controller_startup(void)
{
   Reset_Reason reason = Cbi_Partition_Api_getResetReason();
   switch (reason)
   {
   case Reset_Reason_Power:
      startup_on_power_reset();
      return;
   case Reset_Reason_Reset:
      startup_on_processor_reset();
      return;
   case Reset_Reason_Unknown:
      break;
   }
}

void controller_PI_d1(void)
{
   // NOP - dummy interface
}

void controller_PI_d2(void)
{
   // NOP - dummy interface
}