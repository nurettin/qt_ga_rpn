#ifndef RPN_H
#define RPN_H

#include <QString>

namespace qrg {

double rpn_eval(QString const &expr, bool &ok);
QString rpn_infix(QString const &expr, bool &ok);

}

#endif // RPN_H
