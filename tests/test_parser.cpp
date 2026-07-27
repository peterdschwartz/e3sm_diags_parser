#include "ast.hpp"
#include "catch2/catch_message.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "tokens.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

namespace edp {

TEST_CASE("Test Parse expressions") {
  std::string input = "x*y.derivative(dx=dy,['col'])";
  // std::string input = "[1, 'col', 2]";

  parser::Parser parser{Lexer{input}};

  auto expr = parser.parse();
  auto str_ = to_string(*expr);
  std::cout << "Parsed Expression: \n" << str_;
  INFO("Parsed Expression: \n" << str_);
  CHECK(str_ == "((x*y).derivative((dx=dy), ['col']))");
}

} // namespace edp
