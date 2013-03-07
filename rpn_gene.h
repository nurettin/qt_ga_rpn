#ifndef RPN_GENE_H
#define RPN_GENE_H

#include "wheel.h"

namespace qrg {

struct rpn_gene: wheel
{
  rpn_gene();
  rpn_gene(data_type::size_type n, double mutation);
  QString sample() const;
};

rpn_gene operator* (rpn_gene const &g1, rpn_gene const &g2);

}

#endif // RPN_GENE_H
