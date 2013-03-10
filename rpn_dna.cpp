#include <limits>
#include <cmath>

#include <QTextStream>
#include <QDebug>

#include "rpn_dna.h"
#include "util.h"
#include "rpn.h"

namespace qrg {

rpn_dna::rpn_dna(){}

rpn_dna::rpn_dna(QVector<rpn_gene>::size_type size,
                 QVector<QString>* gene_samples,
                 double mutation)
  : gene(size, rpn_gene(gene_samples, mutation))
{}

void rpn_dna::mutate()
{
  int mutate_index= rand_range(0, gene.size()- 1);
  gene[mutate_index].mutate();
}

QString rpn_dna::sample() const
{
  static QString cat;
  cat.clear();
  for(QVector<rpn_gene>::size_type g= 0; g< gene.size()- 1; ++ g)
    cat.append(gene[g].sample()).append(' ');
  cat.append(gene[gene.size()- 1].sample());
  return cat;
}

double rpn_dna::fitness(double target, int tries) const
{
  double error_value= std::numeric_limits<double>::max()/ tries;
  double sum= 0;
  for(int n= tries; n--;)
  {
    bool ok= true;
    QString const &sample_equation= sample();
    double rpn= rpn_eval(sample_equation, ok);
    double how_fit= 0;
    if(!ok) how_fit= error_value;
    else
    {
      how_fit= std::fabs(rpn- target);
      if(how_fit<= 0.001)
        qDebug()<< "fitness: "<< how_fit<< " target: "<< target<< rpn_infix_valid(sample_equation)<< " = "<< rpn;
    }
    sum+= how_fit;
  }
  return sum/ tries;
}

rpn_dna operator* (rpn_dna const &d1, rpn_dna const &d2)
{
  rpn_dna child(d1.gene.size(), d1.gene.first().samples, d1.gene.first().mutation);
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
