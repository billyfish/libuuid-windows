#include "uuid.h"

#include "Rpcdce.h"


void uuid_generate (uuid_t out)
{
	UuidCreate (&out);
}


void uuid_generate_random (uuid_t out)
{
	uuid_generate (out);
}


void uuid_generate_time (uuid_t out)
{
	UuidCreateSequential (&out);
}


int uuid_generate_time_safe (uuid_t out)
{
	UuidCreateSequential (&out);
	return 0;
}
