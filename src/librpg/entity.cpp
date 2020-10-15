/*
 *
 */

# ifdef WIN32
#   include <windows.h>
#   define  COMPILING_LIBRPG
#   define  EXPORT __declspec(dllexport) __stdcall
# else
#   define EXPORT
# endif /* WIN32 */
# include "../inc/entity.h"

// Internal Entity Structure
struct Entity {
public:
  unsigned int id;
  spi::string name;
  spi::string desc;
  unsigned int weight;
  unsigned int size;

  Entity (
    const spi::string& n,
    const spi::string& d,
    unsigned int w,
    unsigned int s,
    unsigned int id = 0)
  : id {id ?: rpg_RNG ()}, name {n}, desc {d}, weight {w}, size {s}
  {

  };
};

extern "C" {
  EXPORT rpg_entity_t rpg_CreateEntity (
    const tchar_t* n,
    const tchar_t* d,
    unsigned int w,
    unsigned int s)
  {
    static const tchar_t* NO_NAME {PREFIX_L ("No Name")};
    static const tchar_t* NO_DESC {PREFIX_L ("No Description")};

    // Provide placeholder names in case none are provided.
    const tchar_t* name = n ?: NO_NAME;
    const tchar_t* desc = d ?: NO_DESC;
    
    return new Entity {name, desc, w, s};
  };

  EXPORT int rpg_DestroyEntity (rpg_entity_t e)
  {
    if (!e)
      return -1;
    delete reinterpret_cast<Entity*> (e);
    return 0;
  };

  EXPORT const tchar_t* rpg_GetEntityName (rpg_entity_t e)
  {
    Entity* temp = reinterpret_cast<Entity*> (e);
    if (!temp)
      return nullptr;
    
    return temp->name;
  };

  EXPORT const tchar_t* rpg_GetEntityDesc (rpg_entity_t e)
  {
    Entity* temp = reinterpret_cast<Entity*> (e);
    if (!temp)
      return nullptr;
    
    return temp->desc;
  };
};
