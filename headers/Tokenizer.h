#pragma once
#include <Token.h>
#include <vector>

class Tokenizer {
 public:
  Tokenizer() = default;
  std::vector<Token> GetTokens(const std::string_view& expression);
 private:
  std::vector<Token> tokens_;
  static bool IsOperation(char letter);
  static bool IsSpace(char letter);
  static bool IsLeftBracket(char letter);
  static bool IsRightBracket(char letter);
  static bool IsComma(char letter);
};