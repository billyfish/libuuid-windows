#include "uuid.h"

#include "rpcdce.h"


int uuid_parse (const char *in_s, uuid_t uu)
{
	RPC_STATUS status = UuidFromString ((char *) in_s, &uu);

	if (status == RPC_S_OK)
		{
			return 0;
		}
	else
		{
			return 1;
		}
}
