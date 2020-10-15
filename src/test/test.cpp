
# ifdef WIN32
#   include <windows.h>
# endif /* WIN32 */
#include "../inc/entity.h"

class Test {
public:
  unsigned char a;
  unsigned char b;
} test_class;

# ifdef WIN32
int WINAPI WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
) {
# else
int main (void) {
# endif /* WIN32 */
  
  return 0;
};
