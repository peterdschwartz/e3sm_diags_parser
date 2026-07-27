#pragma once // becoming lazy

#include "tokens.hpp"
namespace edp::parser {

enum class Precedence {
  Lowest,
  Equal,
  LessGreater,
  Sum,
  Product,
  Prefix,
  Bounds,
  Call,
};
Precedence token_precedence(TokenTypes type);
} // namespace edp::parser
