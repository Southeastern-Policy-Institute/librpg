/*
 *
 */

# include <windows.h>
# include <spi.h>

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID /*lpReserved*/)
{
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
  }
  return TRUE;
};

typedef void (__cdecl *exit_func)(void);

spi::list<exit_func>* atexit_list{ nullptr };

extern "C" exit_func _xc_a;

extern "C" exit_func _xc_z;

extern "C" void* malloc (__SIZE_TYPE__ len) {
  return HeapAlloc (GetProcessHeap (), HEAP_ZERO_MEMORY, len);
};

extern "C" void free (void* ptr) {
  if (ptr)
    HeapFree (GetProcessHeap (), NULL, ptr);
};

extern "C" int atexit (exit_func func) {
  if (!atexit_list)
    atexit_list = new spi::list<exit_func> ();
  atexit_list->add (func);
  return 0;
};

extern "C" int spi_crt_start ( HINSTANCE a,
                                HINSTANCE b,
                                LPSTR     c,
                                int       d)
{
  uintptr_t global_init_i = reinterpret_cast<uintptr_t> (&_xc_a);
  uintptr_t global_init_f = reinterpret_cast<uintptr_t> (&_xc_z);
  uintptr_t global_init_size = global_init_f - global_init_i;
  size_t global_init_count = global_init_size / sizeof (exit_func);

  for (size_t i = 0; i < global_init_count; i++)
    (&_xc_a)[i] ();

  int ret_code = DllMain (a, DLL_PROCESS_ATTACH, NULL);

  if (atexit_list)
    for (const auto& func : *atexit_list)
      func ();

  return ret_code;
};

