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
static asn1SccDataStoreDeleteRequest delete_request;
static asn1SccDataStoreRetrieveRequest retrieve_request;

static int counter;
static int subscribed;
static int key;

void client1_startup(void)
{
    counter = 0;
    subscribed = 0;
    key = -1;
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

    if(counter < 12 && counter % 4 == 0)
    {
        create_request.behaviour = DataStoreCreateRequest_behaviour_free_existing;
        create_request.item_value.kind = DataStoreValueType_coefficient_PRESENT;
        create_request.item_value.u.coefficient = 2;
        client1_RI_Create(&create_request);
        ++counter;
        ++key;
    }
    else if(counter < 12 && counter % 4 == 1)
    {
        retrieve_request.item_key = key;
        client1_RI_Retrieve(&retrieve_request);
        ++counter;
    }
    else if(counter < 12 && counter % 4 == 2)
    {
        delete_request.item_key = key;
        client1_RI_Delete(&delete_request);
        ++counter;
    }
    else if(counter < 12 && counter % 4 == 3)
    {
        retrieve_request.item_key = key;
        client1_RI_Retrieve(&retrieve_request);
        ++counter;
    }
    else
    {
        client1_RI_Clean();
        counter = 0;
    }
}

void client1_PI_notify( const asn1SccT_EventMessage * ev)
{
    switch(ev->kind)
    {
    case T_EventMessage_item_created_PRESENT:
        printf("client1: item created, key = %lu\n", ev->u.item_created.item_key);
        break;

    case T_EventMessage_item_updated_PRESENT:
        printf("client1: item updated key = %lu\n", ev->u.item_updated.item_key);
        break;

    case T_EventMessage_item_deleted_PRESENT:
        printf("client1: item deleted key = %lu\n", ev->u.item_deleted.item_key);
        break;

    case T_EventMessage_item_store_rejected_PRESENT:
        printf("client1: item store rejected\n");
        break;

    case T_EventMessage_item_removed_PRESENT:
        printf("client1: item removed key = %lu\n", ev->u.item_removed.item_key);
        break;

    case T_EventMessage_data_store_cleaned_PRESENT:
        printf("client1: cleaned\n");
        break;

    case T_EventMessage_data_store_error_PRESENT:
        printf("client1: error\n");
        break;

    case T_EventMessage_NONE:
        printf("client1: none\n");
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
            printf("client1: item retrieved key = %lu\n", ev->u.item_retrieved.item_key);
            break;

        case T_EventRetrieveMessage_item_by_timestamp_retrieved_PRESENT:
            printf("client1: item by timestamp retrieved\n");
            break;

        case T_EventRetrieveMessage_data_store_error_PRESENT:
            printf("client1: item not present\n");
            break;

        case T_EventRetrieveMessage_NONE:
            printf("client1: none\n");
            break;
    }
}
