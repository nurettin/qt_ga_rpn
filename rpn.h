#ifndef RPN_H
#define RPN_H

#include <string>

#include <QString>

namespace qrg {

double rpn_eval(QString const &expr, bool &ok);
QString rpn_infix_valid(QString const &expr);
std::string remove_parens(std::string const &expr);

}

#endif // RPN_H
