#include "uuid.h"

#include "Rpcdce.h"

int uuid_compare (const uuid_t uu1, const uuid_t uu2)
{
	RPC_STATUS status;

	int res = UuidCompare ((UUID *) &uu1, (UUID*)  &uu2,  &status);
	return res;
}
