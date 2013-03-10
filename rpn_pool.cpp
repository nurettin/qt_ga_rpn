#include "rpn_pool.h"
#include "rpn_dna.h"
#include "rpn_dna_comparator.h"

namespace qrg {

rpn_pool::rpn_pool(QVector<rpn_dna>::size_type size,
                   QVector<rpn_gene>::size_type dna_size,
                   QVector<QString>* gene_samples,
                   double mutation,
                   double fitness_target,
                   int fitness_samples)
  : pool(size, rpn_dna(dna_size, gene_samples, mutation))
  , comparator(fitness_target, fitness_samples)
{}

rpn_dna_comparator rpn_pool::evolve()
{
  int half_pool_size= pool.size()/ 2;
  for(int n= 0; n< half_pool_size; ++ n)
  {
    rpn_dna new_dna(pool[n]* pool[n+ half_pool_size]);
    new_dna.mutate();
    pool.push_back(new_dna);
  }
  qSort(pool.begin(), pool.end(), comparator);
  pool.erase(pool.begin()+ half_pool_size* 2, pool.end());
  return comparator;
}

QDebug operator<< (QDebug dbg, rpn_pool const &pool)
{
  dbg.nospace()<< pool.pool;
  return dbg.space();
}

}
