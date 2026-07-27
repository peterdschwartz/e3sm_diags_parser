#pragma once // becoming lazy

#include "tokens.hpp"
#include <stdexcept>
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

Precedence token_precedence(TokenTypes type) {
  switch (type) {

  case TokenTypes::Plus:
  case TokenTypes::Minus:
  case TokenTypes::Dot:
    return Precedence::Sum;

  case TokenTypes::Slash:
  case TokenTypes::Asterisk:
  case TokenTypes::Exp:
    return Precedence::Product;

  case TokenTypes::LeftParen:
    return Precedence::Call;
  case TokenTypes::Colon:
    return Precedence::Bounds;

  case TokenTypes::GreaterThan:
  case TokenTypes::GreaterEqual:
  case TokenTypes::LessThan:
  case TokenTypes::LessEq:
    return Precedence::LessGreater;

  case TokenTypes::Equal:
  case TokenTypes::NotEqual:
  case TokenTypes::Assign:
  case TokenTypes::And:
  case TokenTypes::Or:
    return Precedence::Equal;

  case TokenTypes::Bang:
    return Precedence::Prefix;
  }
  throw std::runtime_error("No Precedence for Token " +
                           std::string(to_string(type)));
}

} // namespace edp::parser
