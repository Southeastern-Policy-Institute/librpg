
#include <windows.h>
#include <stdio.h>
#include "../inc/entity.h"

int WINAPI WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
) {
  printf ("test\n");
  rpg_entity_t test_entity = rpg_CreateEntity (PREFIX_L("TEST1\0"), PREFIX_L("TEST2\0"), 10, 1);
  printf ("id: %p | name: %s\n",
    test_entity,
    spi::array<char>{spi::string{rpg_GetEntityName (test_entity)}}.operator const char*()
  );
  rpg_DestroyEntity (test_entity);
  return 0;
};
