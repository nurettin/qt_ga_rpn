#include <QDebug>

#include "loud.h"

loud::loud()
{
  qDebug()<< "loud()";
}

loud::loud(const loud &)
{
  qDebug()<< "loud(loud const &)";
}

loud::~loud()
{
  qDebug()<< "~loud()";
}
