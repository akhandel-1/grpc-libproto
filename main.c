#include <stdio.h>
#include <stdlib.h>
#include "proto_gnmi.h"

int main()
{

	::gnmi::GetResponse         getResp;
	::gnmi::Path              hierarchyBox;

	struct rusage usage_1;

	getResp.clear_notification();
    printf("Bytesize(before) - %d\n", getResp.ByteSizeLong());

	if (getrusage(RUSAGE_SELF, &usage_1) != 0) {
		perror("getrusage");
		exit(1);
	}

	printf("Heap utilization(before deserialize): %ld KB\n", usage_1.ru_maxrss);

	serializeDataIntoGetResp(&getResp, hierarchyBox);
	long data_size = 0;
	long data_size_after = 0;
	struct rusage usage;


	if (getrusage(RUSAGE_SELF, &usage) != 0) {
		perror("getrusage");
		exit(1);
	}
	data_size = usage.ru_maxrss;
	printf("Heap utilization(after): %ld KB\n", data_size);
	printf("Heap utilization(difference): %ld KB\n", data_size - usage_1.ru_maxrss);

    printf("Bytesize(after) - %d\n", getResp.ByteSizeLong());

	return 0;
}
