#include "rpn_dna_comparator.h"

namespace qrg {

rpn_dna_comparator::rpn_dna_comparator(int target, int samples)
  : target(target)
  , samples(samples)
{}

bool rpn_dna_comparator::operator()(const rpn_dna &dna1, const rpn_dna &dna2)
{
  return dna1.fitness(target, samples)< dna2.fitness(target, samples);
}

}
