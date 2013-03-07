#include "util.h"

#include <ctime>
#include <cstdlib>

namespace qrg {

int rand_range(int min, int max)
{
  return ((double)std::rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}

unsigned long rand_seed()
{
  unsigned long seed= static_cast<unsigned long>(std::time(0));
  std::srand(seed);
  return seed;
}

}
