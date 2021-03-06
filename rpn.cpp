#include <QString>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <map>

#include <tr1/functional>

#include <QDebug>

#include "rpn.h"

namespace qrg {

typedef std::map<std::string, std::tr1::function<double(double, double)> > binary_ops_type;

binary_ops_type binary_ops()
{
  binary_ops_type ops;
  ops["+"]= std::plus<double>();
  ops["-"]= std::minus<double>();
  ops["*"]= std::multiplies<double>();
  ops["/"]= std::divides<double>();
  ops["^"]= static_cast<double(*)(double, double)>(std::pow);
  return ops;
}

double rpn_eval(QString const &s_expr, bool &ok)
{
  std::string expr= s_expr.toStdString();
  static std::istringstream in;
  in.clear();
  in.str(expr);
  static std::vector<double> stack;
  stack.clear();
  static std::string token;
  static binary_ops_type bin_ops= binary_ops();

  while (in>> token)
  {
    binary_ops_type::const_iterator op= bin_ops.find(token);
    if(op== bin_ops.end())
    {
      if(stack.size()== 2)
      {
        ok= false;
        return 0;
      }
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
    stack.push_back(op-> second(lhs, rhs));;
  }
  return stack.back();
}

QString rpn_infix_valid(QString const &s_expr)
{
  std::string expr= s_expr.toStdString();
  static std::istringstream in;
  in.clear();
  in.str(expr);
  static std::vector<std::string> stack;
  stack.clear();
  static std::string token;
  static binary_ops_type bin_ops= binary_ops();

  while (in>> token)
  {
    binary_ops_type::const_iterator op= bin_ops.find(token);
    if(op== bin_ops.end())
    {
      stack.push_back(token);
      continue;
    }

    std::string rhs = stack.back();
    stack.pop_back();
    std::string lhs = stack.back();
    stack.pop_back();
    if(op-> first== "*"|| op-> first== "/")
      stack.push_back('('+ lhs+ ' '+ op-> first+ ' '+ rhs+ ')');
    else
      stack.push_back('('+ remove_parens(lhs)+ ' '+ op-> first+ ' '+ remove_parens(rhs)+ ')');
  }

  return QString::fromStdString(remove_parens(stack.back()));
}

std::string remove_parens(std::string const &expr)
{
  std::string::size_type expr_size= expr.size();
  if(expr_size< 2) return expr;
  if(expr[0]!= '(' || expr[expr_size- 1]!= ')') return expr;
  std::string substr= expr.substr(1, expr_size- 2);
  return substr;
}

}
