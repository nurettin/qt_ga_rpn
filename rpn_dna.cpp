#include "rpn_dna.h"
#include "util.h"
#include "rpn.h"

namespace qrg {

rpn_dna::rpn_dna(QVector<rpn_gene>::size_type size, wheel::data_type::size_type gene_size, double mutation)
  : gene(size, rpn_gene(gene_size, mutation))
{}

void rpn_dna::mutate()
{
  int mutate_index= rand_range(0, gene.size());
  gene[mutate_index].mutate();
}

QString rpn_dna::sample() const
{
  return "";
}

double rpn_dna::fitness(int tries)
{
  return 0;
}

rpn_dna operator* (rpn_dna const &d1, rpn_dna const &d2)
{
  rpn_dna child(d1.gene.size(), d1.gene.first().data.size(), d1.gene.first().mutation);
  for(QVector<rpn_gene>::size_type e= 0; e< d1.gene.size(); ++ e)
    child.gene[e]= d1.gene[e]* d2.gene[e];
  return child;
}

QDebug operator<< (QDebug dbg, rpn_dna const &dna)
{
  dbg.nospace()<< dna.gene;
  return dbg.space();
}

}
