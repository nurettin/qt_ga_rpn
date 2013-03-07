#include "wheel.h"
#include "util.h"

namespace qrg{

wheel::wheel(data_type::size_type n, double mutation)
  : data(n, 1./ n)
  , mutation(mutation)
{}

wheel::data_type::size_type wheel::select_for_mutate()
{
  select_index.clear();
  for(data_type::size_type ie= 0; ie< data.size(); ++ ie)
    if(data[ie]>= mutation)
      select_index.push_back(ie);
  int rand_index= rand_range(0, select_index.size()- 1);
  return select_index[rand_index];
}

void wheel::select_for_increase(double diff)
{
  select_index.clear();
  for(data_type::size_type ie= 0; ie< data.size(); ++ ie)
    if(1- data[ie]>= diff)
      select_index.push_back(ie);
}

void wheel::mutate_down()
{
  data_type::size_type mutate_index= select_for_mutate();
  data[mutate_index]-= mutation;
  double diff= mutation/ (data.size()- 1);
  select_for_increase(diff);
  for(select_index_type::size_type s= 0; s< select_index.size(); ++ s)
    if(select_index[s]!= mutate_index)
      data[select_index[s]]+= diff;
}

void wheel::mutate()
{
  mutate_down();
}

wheel::data_type::size_type wheel::spin() const
{
  data_type::size_type i= 0;
  double rand= std::rand()* 1./ RAND_MAX;
  for(double s= 0; s< rand;)
  {
    s+= data[i];
    ++ i;
  }
  return i- 1;
}

QDebug operator<< (QDebug dbg, wheel const &wheel)
{
  dbg.nospace()<< "qrg::Wheel "<< wheel.data;
  return dbg.space();
}

}
