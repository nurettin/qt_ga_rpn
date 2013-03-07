#include "rpn_gene.h"

namespace qrg {

rpn_gene::rpn_gene()
  : wheel(13, 1./ 13/ 4)
{}

QString rpn_gene::sample() const
{
  static QString samples[]= {
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "/"
  };
  data_type::size_type index= spin();
  return samples[index];
}

rpn_gene operator* (rpn_gene const &g1, rpn_gene const &g2)
{
  rpn_gene ret;
  for(wheel::data_type::size_type g= 0; g< ret.data.size(); ++ g)
    ret.data[g]= (g1.data[g]+ g2.data[g])/ 2.;
  return ret;
}

}
