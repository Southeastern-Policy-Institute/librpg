/* ENTITY.H - Basic entity type.
 * Southeastern Policy Institute, 2020
 */

# ifndef _LIBRPG_ENTITY_H_
#   define _LIBRPG_ENTITY_H_
#   if _MSC_VER > 1000
#     pragma once
#   endif /* _MSC_VER */
#   include "common.h"
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

// Public-facing entity type
typedef void* rpg_entity_t;

#   ifdef __cplusplus
extern "C" {
#   endif /* __cplusplus */

  /*
Public Declare Function CreateEntity _
  Lib "librpg.dll" Alias "rpg_CreateEntity" as UInteger
  */

  LIBSPEC LINKAGE rpg_entity_t rpg_CreateEntity ( const tchar_t* name,
                                                  const tchar_t* desc,
                                                  unsigned int weight,
                                                  unsigned int size);
  LIBSPEC LINKAGE int rpg_DestroyEntity (rpg_entity_t);
  LIBSPEC LINKAGE const tchar_t* rpg_GetEntityName (rpg_entity_t);


#   undef LINKAGE
#   undef LIBSPEC
#   ifdef __cplusplus
};
#   endif /* __cplusplus */
# endif /* _LIBRPG_ENTITY_H_ */
