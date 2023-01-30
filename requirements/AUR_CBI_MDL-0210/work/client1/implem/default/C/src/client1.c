/* Body file for function Environment
 * Generated by TASTE (kazoo/templates/skeletons/c-body/function.tmplt)
 * You can edit this file, it will not be overwritten

    !! IMPORTANT                                                        !!
    !! When you modify your design (interface view), you must update    !!
    !! the procedures corresponding to the provided interfaces in this  !!
    !! file. The up-to-date signatures can be found in the .ads file.   !!
*/
#include "client1.h"
#include "routing.h"

static asn1SccDataStoreCreateRequest create_request;
static asn1SccDataStoreUpdateRequest update_request;

static int counter;
static int subscribed;

void client1_startup(void)
{
    counter = 0;
    subscribed = 0;
}

void client1_PI_Trigger( void )
{
    if(subscribed == 0)
    {
        asn1SccT_UInt32 event_id = event_id_datastore_notify;
        asn1SccT_Boolean should_subscribe = 1;
        client1_RI_subscribe_to_event(&event_id, &should_subscribe);
        subscribed = 1;
    }
    create_request.behaviour = DataStoreCreateRequest_behaviour_reject_when_overflow;
    create_request.item_value.kind = DataStoreValueType_coefficient_PRESENT;
    create_request.item_value.u.coefficient = 2;
    client1_RI_Create(&create_request);
    ++counter;

    if (counter > 2)
    {
        update_request.item_key = counter - 1;
        update_request.item_value.u.coefficient = 1;
        client1_RI_Update(&update_request);
    }

}

void client1_PI_notify( const asn1SccT_EventMessage * ev)
{
    switch(ev->kind)
    {
    case T_EventMessage_item_created_PRESENT:
        printf("client1: item received\n");
        break;
    case T_EventMessage_item_updated_PRESENT:
        printf("client1: item updated %lu\n", ev->u.item_updated.item_key);
        break;
    default:
        break;
    }
}

void client1_PI_notifyRetrieve(const asn1SccT_EventRetrieveMessage* ev)
{
    switch(ev->kind)
    {
        case T_EventRetrieveMessage_item_retrieved_PRESENT:
            printf("client1: item retrieved %lu\n", ev->u.item_retrieved.item_key);
            break;

        case T_EventRetrieveMessage_item_by_timestamp_retrieved_PRESENT:
            printf("client1: item by timestamp retrieved\n");
            break;

        case T_EventRetrieveMessage_data_store_error_PRESENT:
            printf("client1: error\n");
            break;

        case T_EventRetrieveMessage_NONE:
            printf("client1: none\n");
            break;
    }
}
