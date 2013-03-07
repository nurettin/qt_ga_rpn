#include <QCoreApplication>
#include <QDebug>

#include "rpn_gene.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  qrg::rpn_gene gene;
  for(int n= 1000; n--;)
    gene.mutate();
  qDebug()<< gene;
  for(int n= 10; n--;)
    qDebug()<< gene.sample();
  return a.exec();
}
