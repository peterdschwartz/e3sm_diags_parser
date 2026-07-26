#include "ast.hpp"
#include <algorithm>

namespace edp::ast {

namespace {

struct ToStringVisitor {

  std::string operator()(const Identifier &expr) const;
  std::string operator()(const PrefixExpression &expr) const;
  std::string operator()(const InfixExpression &expr) const;
  std::string operator()(const FuncExpression &expr) const;
  std::string operator()(const StringLiteral &expr) const;
  std::string operator()(const FloatLiteral &expr) const;
  std::string operator()(const IntegerLiteral &expr) const;
};

} // namespace

std::string ToStringVisitor::operator()(const Identifier &expr) const {
  return expr.value;
};

std::string ToStringVisitor::operator()(const PrefixExpression &expr) const {
  return "(" + expr.token.literal + to_string(*expr.right) + ")";
};

std::string ToStringVisitor::operator()(const InfixExpression &expr) const {
  return "(" + to_string(*expr.left) + expr.token.literal +
         to_string(*expr.right) + ")";
};
std::string ToStringVisitor::operator()(const FuncExpression &expr) const {
  std::string arg_str;
  bool first = true;

  std::ranges::for_each(expr.args, [&arg_str, &first](const ExprPtr &arg) {
    if (!first) {
      arg_str += ", ";
    }
    first = false;
    arg_str += to_string(*arg);
  });
  return to_string(*expr.function) + "(" + arg_str + ")";
};

std::string ToStringVisitor::operator()(const StringLiteral &expr) const {
  return expr.value;
};
std::string ToStringVisitor::operator()(const IntegerLiteral &expr) const {
  return std::to_string(expr.value);
};
std::string ToStringVisitor::operator()(const FloatLiteral &expr) const {
  return std::to_string(expr.value);
};

std::string to_string(const Expression &expr) {}

} // namespace edp::ast
