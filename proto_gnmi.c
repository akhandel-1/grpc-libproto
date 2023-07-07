#include "proto_gnmi.h"

/**************************************************************************************
   Description :
        Adds prefix to given notification.

   Parameters:
        ::gnmi::Notification *notif => Pointer to notification in which prefix
                                             to be added.
        ::gnmi::Path& yPrefix => Prefix which is to be added.

   Returns: void
 **************************************************************************************/
inline static void addPrefix2Notif(::gnmi::Notification *notif, ::gnmi::Path& yPrefix)
{
   ::gnmi::Path*           prefix  = new ::gnmi::Path(yPrefix);

   assert(prefix != NULL);
   notif->clear_prefix();

   notif->set_allocated_prefix(prefix);

   return;
}

void serializeDataIntoGetResp(::gnmi::GetResponse    *protoResp,
                                                     ::gnmi::Path&  hierarchyBox)
{
	int notif_count = 250000, i;
	int update_count = 4, j;
    ::gnmi::Notification *notif = NULL;
    int64_t  epochTm = 662257324270000000;

	printf("!!!Data to be publised is bytes %ld\n", notif_count * 4 + update_count * 4);
	hierarchyBox.add_elem()->set_name("maintenance-domain");


	for (i = 0; i < notif_count; i++) {
        notif   = protoResp->add_notification();

		notif->set_timestamp(epochTm);

		notif->mutable_prefix()->CopyFrom(hierarchyBox);
//		addPrefix2Notif(notif, hierarchyBox);
		for (j = 0; j < update_count; j++) {

			::gnmi::Update* update = notif->add_update();
			update->mutable_path()->add_elem()->set_name("id");

			update->mutable_val()->set_string_val("service");
		}
	}
	return;
}
