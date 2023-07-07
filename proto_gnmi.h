#include "gNMI.pb.h"

#include <sys/resource.h>
#include <sys/stat.h>

#include "gNMI.pb.h"


#ifdef __cplusplus
extern "C"
{
#endif

void serializeDataIntoGetResp(::gnmi::GetResponse    *protoResp,
		                                                     ::gnmi::Path&  hierarchyBox);
#ifdef __cplusplus
}
#endif
