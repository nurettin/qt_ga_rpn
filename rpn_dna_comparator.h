#ifndef RPN_DNA_COMPARATOR_H
#define RPN_DNA_COMPARATOR_H

#include "rpn_dna.h"

namespace qrg {

class rpn_dna_comparator
{
public:
  double target;
  int samples;
  double max_fitness;

  rpn_dna_comparator(double target, int samples);
  bool operator()(rpn_dna const &dna1, rpn_dna const &dna2);
};

}

#endif // RPN_DNA_COMPARATOR_H
