#include "rpn_dna_comparator.h"

namespace qrg {

rpn_dna_comparator::rpn_dna_comparator(double target, int samples)
  : target(target)
  , samples(samples)
{}

bool rpn_dna_comparator::operator()(const rpn_dna &dna1, const rpn_dna &dna2)
{
  double fitness1= dna1.fitness(target, samples);
  double fitness2= dna2.fitness(target, samples);
  return fitness1< fitness2;
}

}
