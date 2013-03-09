#include <QCoreApplication>
#include <QDebug>

#include "rpn_dna.h"
#include "util.h"
#include "rpn.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  qrg::rand_seed();
  bool ok= true;
  qDebug()<< qrg::rpn_infix("5 7 + 6 2 - *", ok);
  qDebug()<< ok;
  return a.exec();
}
