/* Body file for function error_manager
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "error_manager.h"


#include "Broker.h"

static void error_manager_broker_error_detected(const Broker_ErrorType err, uint8_t* const data, const size_t length)
{
    error_manager_RI_error();
}

void error_manager_startup(void)
{
    Broker_register_error_callback(&error_manager_broker_error_detected);
}

void error_manager_PI_reset(void)
{

}



