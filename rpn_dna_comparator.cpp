#include <limits>

#include "rpn_dna_comparator.h"

namespace qrg {

rpn_dna_comparator::rpn_dna_comparator(double target, int samples)
  : target(target)
  , samples(samples)
  , max_fitness(std::numeric_limits<double>::max())
{}

bool rpn_dna_comparator::operator()(rpn_dna const &dna1, rpn_dna const &dna2)
{
  double fitness1= dna1.fitness(target, samples);
  double fitness2= dna2.fitness(target, samples);
  if(fitness1< max_fitness) max_fitness= fitness1;
  if(fitness2< max_fitness) max_fitness= fitness2;

  return fitness1< fitness2;
}

}
