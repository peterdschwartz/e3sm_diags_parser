#ifndef EDP_TOKENS_HPP
#define EDP_TOKENS_HPP
#include <string>
namespace edp {

enum class TokenTypes {
  EndofFile,
  Illegal,
  Newline,

  Identifer,
  Integer,
  Float,
  String,
  // Operators
  Assign,
  Plus,
  Minus,
  Asterisk,
  Bang,
  Slash,
  Exp,
  Equal,
  GreaterThan,
  GreaterEqual,
  LessThan,
  LessEq,
  NotEqual,
  Or,
  And,
  Concat,
  Dot,

  // DELIMITERS
  Comma,
  LeftParen,
  RightParen,
  Colon,
  Semicolon,
  Percent,
  DoubleColon,
  ArrayLeftBracket,
  ArrayRightBracket,
};

struct Token {
  TokenTypes token;
  std::string literal;
};

} // namespace edp
#endif
