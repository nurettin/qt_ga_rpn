#ifndef WHEEL_H
#define WHEEL_H

#include <QVector>
#include <QDebug>

namespace qrg {

struct wheel
{
  typedef QVector<double> data_type;
  data_type data;
  typedef QVector<data_type::size_type> select_index_type;
  select_index_type select_index;
  double mutation;

  wheel(data_type::size_type n, double mutation);
  data_type::size_type select_for_mutate();
  void select_for_increase(double diff);
  void mutate_down();
  void mutate();
  data_type::size_type spin() const;
};

QDebug operator<< (QDebug dbg, wheel const &wheel);

}
#endif // WHEEL_H
