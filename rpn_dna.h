#ifndef RPN_DNA_H
#define RPN_DNA_H

#include "rpn_gene.h"

namespace qrg {

class rpn_dna
{
public:
  QVector<rpn_gene> gene;

  rpn_dna();
  rpn_dna(QVector<rpn_gene>::size_type size,
          QVector<QString> *gene_samples,
          double mutation);
  void mutate();
  QString sample() const;
  double fitness(double target, int samples) const;
};

rpn_dna operator* (rpn_dna const &d1, rpn_dna const &d2);

QDebug operator<< (QDebug dbg, rpn_dna const &dna);

}
#endif // RPN_DNA_H

