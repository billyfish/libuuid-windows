#include <ctype.h>

#include "uuid.h"

#include "rpcdce.h"


const static size_t S_UUID_STRING_SIZE = 36;

void uuid_unparse (const uuid_t uu, char *out_s)
{
	RPC_CSTR *str_p = NULL;
	RPC_STATUS status = UuidToString (&uu, str_p);

	if (status == RPC_S_OK)
		{
			if (str_p)
				{
					strcpy_s (out_s, S_UUID_STRING_SIZE, (const char *) str_p);
					RpcStringFree (str_p);
				}
		}
}


void uuid_unparse_lower (const uuid_t uu, char *out_s)
{
	size_t i;
	char* char_p;

	uuid_unparse (uu, out_s);

	for (i = 0, char_p = out_s; i < S_UUID_STRING_SIZE; ++ i, ++ char_p)
		{
			*char_p = tolower (*char_p);
		}
}


void uuid_unparse_upper (const uuid_t uu, char *out_s)
{
	size_t i;
	char* char_p;

	uuid_unparse (uu, out_s);

	for (i = 0, char_p = out_s; i < S_UUID_STRING_SIZE; ++ i, ++ char_p)
		{
			*char_p = toupper (*char_p);
		}
}

