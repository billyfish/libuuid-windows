#include <string.h>

#include "uuid.h"



void uuid_clear (uuid_t uu)
{
	uu.Data1 = 0;
	uu.Data2 = 0;
	uu.Data3 = 0;

	memset (uu.Data4, 8 * sizeof (char), 0);
}