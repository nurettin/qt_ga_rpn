#include <QString>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "rpn.h"

namespace qrg {

double rpn_eval(QString const &s_expr, bool &ok)
{
  std::string expr= s_expr.toStdString();
  static std::istringstream in;
  in.clear();
  in.str(expr);
  static std::vector<double> stack;
  stack.clear();
  static std::string token;
  while (in>> token)
  {
    if(!(token.size()== 1 && std::string("+-*/^").find(token)!= std::string::npos))
    {
      double n= QString::fromStdString(token).toDouble();
      stack.push_back(n);
      continue;
    }
    if(stack.size()< 2)
    {
      ok= false;
      return 0;
    }
    double rhs = stack.back();
    stack.pop_back();
    double lhs = stack.back();
    stack.pop_back();
    if (token == "*")
      stack.push_back(lhs * rhs);
    else if (token == "/")
      stack.push_back(lhs / rhs);
    else if (token == "-")
      stack.push_back(lhs - rhs);
    else if (token == "+")
      stack.push_back(lhs + rhs);
    else if (token == "^")
      stack.push_back(std::pow(lhs, rhs));
  }
  return stack.back();
}

}
