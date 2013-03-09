#ifndef RPN_H
#define RPN_H

#include <QString>

namespace qrg {

//4 5 7 2 + - *            -16
//3 4 + 2  * 7 /             2
//5 7 + 6 2 -  *            48
//4 2 3 5 1 - + * +         18
//4 2 + 3 5 1 -  * +        18
double rpn_eval(QString const &expr, bool &ok);
QString rpn_infix(QString const &expr, bool &ok);

}

#endif // RPN_H
