#include "uuid.h"

#include "Rpcdce.h"

/* isnull.c */
int uuid_is_null (const uuid_t uu)
{
	RPC_STATUS status;
	int res = UuidIsNil ((UUID *) &uu, &status);

	return ((res == TRUE) ? 0 : 1);
}
