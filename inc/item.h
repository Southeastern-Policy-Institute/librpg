/*
 *
 */

# ifndef  _LIBRPG_ITEM_H_
#   define  _LIBRPG_ITEM_H_
#   include "entity.h"

// Public-facing Item Type
typedef void* rpg_item_t;

#   if defined(BUILDING_LIBRPG) && defined(__cplusplus)
// Internal Item Structure
struct Item : Entity {
  
};
#   endif /* BUILDING_LIBRPG */

/* ===== CONSTANTS ===== */
static const unsigned int rpg_ENTITY_WEIGHT_MAX = 5000;

/* ===== CREATION/DESTRUCTION ===== */
EXTERN_C rpg_item_t*      rpg_CreateItem          (const tchar_t* name,
                                                       const tchar_t* desc,
                                                       unsigned int weight,
                                                       rpg_entity_size_t size);
EXTERN_C rpg_item_t*      rpg_CopyItem            (const rpg_item_t*);
EXTERN_C void               rpg_DestroyItem         (rpg_item_t*);

/* ===== FIELD RETRIEVAL ===== */
EXTERN_C const tchar_t*     rpg_GetEntityName         (const rpg_item_t*);
EXTERN_C const tchar_t*     rpg_GetEntityDescription  (const rpg_item_t*);
EXTERN_C unsigned int       rpg_GetEntityWeight       (const rpg_item_t*);
EXTERN_C rpg_entity_size_t  rpg_GetEntitySize         (const rpg_item_t*);

/* ===== CONVERSIONS ===== */
EXTERN_C const tchar_t*     rpg_EntityWeightToString  (const rpg_item_t*);
EXTERN_C const tchar_t*     rpg_EntitySizeToString    (const rpg_item_t*);

# endif /* _LIBRPG_ITEM_H_ */
