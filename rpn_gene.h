#ifndef RPN_GENE_H
#define RPN_GENE_H

#include "wheel.h"

namespace qrg {

struct rpn_gene: wheel
{
  QVector<QString>* samples;

  rpn_gene();
  rpn_gene(QVector<QString>* samples, double mutation);
  QString sample() const;
};

rpn_gene operator* (rpn_gene const &g1, rpn_gene const &g2);

}

#endif // RPN_GENE_H
