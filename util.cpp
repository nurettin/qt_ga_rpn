#include <ctime>
#include <cstdlib>

#include "util.h"

namespace qrg {
/* !
    \function rand_seed
    \brief rand_seed uses present time to seed random number generator.

    \ingroup utilities

    \reentrant

    rand_seed, in conjunction with rand_range, is used in creation of normalized
    random number generation.
*/
unsigned long rand_seed()
{
  unsigned long seed= static_cast<unsigned long>(std::time(0));
  std::srand(seed);
  return seed;
}

int rand_range(int min, int max)
{
  return ((double)std::rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}

}
