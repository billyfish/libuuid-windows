#include <string.h>

#include "uuid.h"


time_t uuid_time (const uuid_t uu, struct timeval *ret_tv_p)
{
	if (ret_tv_p)
		{
			memset (ret_tv_p, sizeof (struct timeval), 0);
		}

	return 0;
}


int uuid_type (const uuid_t uu)
{
	return UUID_TYPE_DCE_RANDOM;
}


int uuid_variant (const uuid_t uu)
{
	return UUID_VARIANT_MICROSOFT;
}
