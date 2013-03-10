#include <QCoreApplication>
#include <QDebug>
#include <QTime>

#include "rpn_pool.h"
#include "util.h"
#include "rpn.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qrg::rand_seed();
  QString arr_gene_samples[]= {
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "/"
  };
  QVector<QString> gene_samples(13);
  qCopy(arr_gene_samples, arr_gene_samples+ 13, gene_samples.begin());

  qrg::rpn_pool pool(100, 7, &gene_samples, 1./ 7/ 4, 3.14, 100);
  QTime timer;
  timer.start();
  for(int generation= 1; generation< 1001; ++ generation)
  {
    qDebug()<< "evolving generation: "<< generation;
    qDebug()<< "max fitness: "<< pool.evolve().max_fitness;
    qDebug()<< "time: "<< timer.elapsed()<< "ms";
    timer.restart();
  }

  return a.exec();
}
