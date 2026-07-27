#include "tokens.hpp"
#include "precedences.hpp"
#include <stdexcept>

namespace edp::parser {

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
  return Precedence::Lowest;
}

}

