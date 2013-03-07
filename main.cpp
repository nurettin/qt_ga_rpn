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
  qDebug()<< qrg::rpn_eval("- 1 2 + 4 * + 3 -", ok);
  qDebug()<< ok;
  return a.exec();
}
