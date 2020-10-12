/* COMMON.H - Common declarations and types.
 * Southeastern Policy Institute, 2020
 */

# ifndef _LIBRPG_COMMON_H_
#   define _LIBRPG_COMMON_H_
#   if _MSC_VER > 1000
#     pragma once
#   endif /* _MSC_VER */
#   include <spi.h>
#   if defined(_COMPILING_COMMON_) && defined(WIN32)
#     define LIBSPEC __declspec(dllexport)
#   elif !defined(_COMPILING_COMMON_) && defined(WIN32)
#     define LIBSPEC __declspec(dllimport)
#   else
#     define LIBSPEC
#   endif /* _COMPILING_COMMON_H_ */
#   ifdef WIN32
#     define LINKAGE __stdcall
#   else
#     define LINKAGE
#   endif /* LINKAGE */
#   ifdef __cplusplus
extern "C" {
#   endif /* __cplusplus */

LIBSPEC LINKAGE unsigned int rpg_RNG (void);

#   undef LINKAGE
#   undef LIBSPEC
#   ifdef __cplusplus
};
#   endif /* __cplusplus */
# endif /* _LIBRPG_COMMON_H_ */
