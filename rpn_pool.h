#ifndef RPN_POOL_H
#define RPN_POOL_H

#include <QVector>

#include "rpn_dna.h"

namespace qrg {

class rpn_pool
{
public:
  QVector<rpn_dna> pool;
  double fitness_target;
  int fitness_samples;

  rpn_pool(QVector<rpn_dna>::size_type size,
           QVector<rpn_gene>::size_type dna_size,
           QVector<QString>* gene_samples,
           double mutation,
           double fitness_target,
           int fitness_samples);
  double evolve();
};

QDebug operator<< (QDebug dbg, rpn_pool const &pool);

}

#endif // RPN_POOL_H
