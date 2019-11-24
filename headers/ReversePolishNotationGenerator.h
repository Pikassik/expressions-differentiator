#pragma once
#include <Token.h>
#include <Tokenizer.h>
#include <unordered_map>


class ReversePolishNotationGenerator {
 public:
  explicit ReversePolishNotationGenerator(const std::vector<Token>& expression);
  std::vector<Token> GenerateExpression();
 private:
  const std::vector<Token>& expression_;
  std::vector<Token> reverse_polish_notation_;
  std::vector<size_t> commas_count_stack_;
  std::vector<Token> operations_stack_;
  void ProcessOperation(const Token& token);
  void ProcessRightBracket();
};