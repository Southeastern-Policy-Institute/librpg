/* RANDOM.CPP - Pseudo-random number generator.
 * Southeastern Policy Institute, 2020
 */

# ifdef WIN32
#   include <windows.h>
#   define  COMPILING_LIBRPG
#   define  EXPORT __declspec(dllexport) __stdcall
# else
#   define EXPORT
# endif /* WIN32 */
# include <stdio.h>

static constexpr const unsigned char RNGTable[] {
  58, 72, 31, 175, 86, 36, 57, 194, 204, 143, 35, 208, 124, 173, 161,
  34, 147, 49, 211, 123, 2, 232, 4, 100, 189, 134, 30, 224, 37, 18,
  187, 81, 242, 39, 135, 70, 97, 176, 110, 92, 130, 41, 106, 87, 153,
  129, 137, 202, 177, 88, 118, 199, 200, 182, 251, 236, 240, 62, 238, 237,
  207, 168, 29, 45, 17, 98, 193, 60, 20, 142, 229, 205, 146, 125, 249,
  13, 215, 246, 253, 241, 252, 126, 159, 12, 74, 89, 254, 99, 28, 244,
  163, 138, 85, 11, 166, 10, 165, 145, 160, 149, 154, 136, 167, 216, 150,
  6, 226, 116, 171, 56, 109, 75, 234, 54, 38, 120, 127, 121, 15, 94,
  217, 184, 233, 190, 84, 243, 141, 170, 197, 50, 42, 174, 71, 156, 43,
  48, 16, 220, 172, 83, 9, 82, 73, 235, 79, 152, 69, 102, 157, 247,
  248, 221, 201, 180, 113, 53, 77, 59, 186, 14, 188, 228, 196, 5, 52,
  117, 210, 191, 250, 27, 223, 185, 108, 93, 24, 61, 112, 209, 122, 1,
  162, 181, 65, 151, 195, 76, 67, 230, 218, 3, 206, 213, 212, 178, 155,
  55, 111, 7, 183, 44, 115, 132, 68, 80, 21, 103, 90, 64, 101, 46,
  63, 26, 219, 51, 227, 231, 158, 222, 133, 144, 140, 40, 169, 128, 19,
  23, 32, 47, 95, 239, 107, 33, 66, 164, 8, 114, 203, 22, 105, 198,
  214, 179, 255, 96, 131, 245, 148, 119, 139, 78, 104, 225, 25, 192, 91, 0
};

static unsigned char RNGAccumulatorA = 0;
static unsigned char RNGAccumulatorB = 128;

constexpr unsigned char RNGGet (unsigned char a) { return RNGTable[a]; };

extern "C" {
  EXPORT unsigned int rpg_RNG (void) {
    union {
      struct {
        unsigned char a, b, c, d;
      };
      unsigned int abcd;
    } random_val {RNGGet (RNGAccumulatorA++), RNGGet (RNGAccumulatorB++),
                  RNGGet (RNGAccumulatorB++), RNGGet (RNGAccumulatorA++)};
    RNGAccumulatorB *= 3;
    return random_val.abcd;
  };
};

class Test {
public:
  unsigned char a;
  unsigned char b;
} test_class;

int main (void) {
  constexpr unsigned int SAMPLE_SIZE = 1000;
  unsigned int arr[SAMPLE_SIZE];
  //unsigned int start_time = GetTickCount ();

  unsigned int i2 = 0;
  unsigned int i3 = 0;
  unsigned int i5 = 0;

  // populate array
  for (unsigned int i = 0; i < SAMPLE_SIZE; i++)
    arr[i] = rpg_RNG () % 5;

  //unsigned int pop_time = GetTickCount ();

  // display array
  for (unsigned int i = 0; i < SAMPLE_SIZE; i+=2)
    printf ("[%04d] %08X  |  [%04d] %08X\n",
      i, arr[i], i+1, arr[i+1]
    );

  //unsigned int list_time = GetTickCount ();

  // check against members
  for (unsigned int i = 0; i < SAMPLE_SIZE; i++)
    switch (arr[i])
    {
    case 2:
      i2++;
      break;
    case 3:
      i3++;
      break;
    case 5:
      i5++;
      break;
    default:
      break;
    }

  //unsigned int sort_time = GetTickCount ();

  // printf ("TIME TO POPULATE: %dms\n", pop_time - start_time);
  // printf ("TIME TO DISPLAY:  %dms\n", list_time - pop_time);
  // printf ("TIME TO CHECK:    %dms\n", sort_time - list_time);
  // printf ("TOTAL TIME:       %dms\n", sort_time - start_time);
  printf ("INSTANCES OF 2:   %d\n", i2);
  printf ("INSTANCES OF 3:   %d\n", i3);
  printf ("INSTANCES OF 5:   %d\n", i5);

  return 0;
};
