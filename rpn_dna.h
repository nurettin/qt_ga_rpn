#ifndef RPN_DNA_H
#define RPN_DNA_H

#include "rpn_gene.h"

namespace qrg {

class rpn_dna
{
public:
  QVector<rpn_gene> gene;

  rpn_dna(QVector<rpn_gene>::size_type size, wheel::data_type::size_type gene_size, double mutation);
  void mutate();
  double fitness(int tries);
};

rpn_dna operator* (rpn_dna const &d1, rpn_dna const &d2);

QDebug operator<< (QDebug dbg, rpn_dna const &dna);

}
#endif // RPN_DNA_H

