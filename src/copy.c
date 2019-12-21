#include "uuid.h"

void uuid_copy (uuid_t dst, const uuid_t src)
{
	dst.Data1 = src.Data1;
	dst.Data2 = src.Data2;
	dst.Data3 = src.Data3;
	
	memcpy (dst.Data4, src.Data4, 8 * sizeof (char));
}
