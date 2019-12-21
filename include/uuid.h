/*
	This is a native windows uuid library that conforms to the standard libuuid API
*/

/* Original copyright */
/*
 * Public include file for the UUID library
 *
 * Copyright (C) 1996, 1997, 1998 Theodore Ts'o.
 *
 * %Begin-Header%
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, and the entire permission notice in its entirety,
 *    including the disclaimer of warranties.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ALL OF
 * WHICH ARE HEREBY DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * %End-Header%
 */


#ifndef _UUID_H
#define _UUID_H

#include "rpc.h"
#include "library.h"

/* UUID Variant definitions */
#define UUID_VARIANT_NCS	0
#define UUID_VARIANT_DCE	1
#define UUID_VARIANT_MICROSOFT	2
#define UUID_VARIANT_OTHER	3

/* UUID Type definitions */
#define UUID_TYPE_DCE_TIME   1
#define UUID_TYPE_DCE_RANDOM 4



/*
** Now we use the generic helper definitions above to define LIB_API and LIB_LOCAL.
** LIB_API is used for the public API symbols. It either DLL imports or DLL exports
** (or does nothing for static build)
** LIB_LOCAL is used for non-api symbols.
*/

#ifdef SHARED_LIBRARY /* defined if LIB is compiled as a DLL */
  #ifdef LIBUUID_EXPORTS /* defined if we are building the LIB DLL (instead of using it) */
    #define LIBUUID_API LIB_HELPER_SYMBOL_EXPORT
  #else
    #define LIBUUID_API LIB_HELPER_SYMBOL_IMPORT
  #endif /* #ifdef LIBUUID_MANAGER_LIBRARY_EXPORTS */
  #define LIBUUID_LOCAL LIB_HELPER_SYMBOL_LOCAL
#else /* SHARED_LIBRARY is not defined: this means LIB is a static lib. */
  #define LIBUUID_API
  #define LIBUUID_LOCAL
#endif /* #ifdef SHARED_LIBRARY */


/* clear.c */
LIBUUID_API void uuid_clear(uuid_t uu);

/* compare.c */
LIBUUID_API int uuid_compare(const uuid_t uu1, const uuid_t uu2);

/* copy.c */
LIBUUID_API void uuid_copy(uuid_t dst, const uuid_t src);

/* gen_uuid.c */
LIBUUID_API void uuid_generate(uuid_t out);
LIBUUID_API void uuid_generate_random(uuid_t out);
LIBUUID_API void uuid_generate_time(uuid_t out);
LIBUUID_API int uuid_generate_time_safe(uuid_t out);

/* isnull.c */
LIBUUID_API int uuid_is_null(const uuid_t uu);

/* parse.c */
LIBUUID_API int uuid_parse(const char* in, uuid_t uu);

/* unparse.c */
LIBUUID_API void uuid_unparse(const uuid_t uu, char* out);
LIBUUID_API void uuid_unparse_lower(const uuid_t uu, char* out);
LIBUUID_API void uuid_unparse_upper(const uuid_t uu, char* out);

/* uuid_time.c */
LIBUUID_API time_t uuid_time(const uuid_t uu, struct timeval* ret_tv);
LIBUUID_API int uuid_type(const uuid_t uu);
LIBUUID_API int uuid_variant(const uuid_t uu);

#ifdef __cplusplus
}
#endif

#endif
