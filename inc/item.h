/* ITEM.H - Basic Item Type
 * Southeastern Policy Institute, 2020
 */

# ifndef _LIBRPG_ITEM_H_
#   define _LIBRPG_ITEM_H_
#   if _MSC_VER > 1000
#     pragma once
#   endif /* _MSC_VER */
#   ifdef __cplusplus
extern "C" {
#   endif /* __cplusplus */
#   if defined(COMPILING_LIBRPG) && defined(WIN32)
#     define LIBSPEC __declspec(dllexport)
#   elif !defined(COMPILING_LIBRPG) && defined(WIN32)
#     define LIBSPEC __declspec(dllimport)
#   else
#     define LIBSPEC
#   endif /* COMPILING_LIBRPG */
#   ifdef WIN32
#     define LINKAGE __stdcall
#   else
#     define LINKAGE
#   endif /* LINKAGE */

// Public-facing item type
typedef void* rpg_item_t;

// LIBSPEC LINKAGE return-type name (parameters);

#   undef LINKAGE
#   undef LIBSPEC
#   ifdef __cplusplus
};
#   endif /* __cplusplus */
# endif /* _LIBRPG_ITEM_H_ */
