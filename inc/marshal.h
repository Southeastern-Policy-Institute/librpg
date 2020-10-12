/*
 *
 */

# ifndef  _LIBRPG_MARSHAL_H_
#   define  _LIBRPG_MARSHAL_H_
#   include <spi.h>
#   if defined(BUILDING_LIBRPG) && defined(__cplusplus)
enum class SERIAL_REG : unsigned int {
  ID, NAME_INDEX, DESC_INDEX, WEIGHT, SIZE
};
#   endif /* BUILDING_LIBRPG */

// Public-facing Serial Type
typedef unsigned int* rpg_serial_t;

const tchar_t* rpg_SerialGetName (rpg_serial_t serial) {
  return reinterpret_cast<tchar_t*> (
    (__UINTPTR_TYPE__)serial+serial[(unsigned int)SERIAL_REG::NAME_INDEX]);
};
const tchar_t* rpg_SerialGetDescription (rpg_serial_t serial) {
  return reinterpret_cast<tchar_t*> (
    (__UINTPTR_TYPE__)serial+serial[(unsigned int)SERIAL_REG::DESC_INDEX]);
};

# endif /* _LIBRPG_MARSHAL_H_ */
