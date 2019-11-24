#pragma once
#include <Token.h>
#include <Tokenizer.h>
#include <ReversePolishNotationGenerator.h>
#include <ExpressionNode.hpp>

class ExpressionTree {
 public:
  ExpressionTree(const std::string_view& expression);
  void Dump(const std::string_view& filename);

  template <class Func>
  static void DFS(const std::unique_ptr<ExpressionNode>& node, Func function);

  std::unique_ptr<ExpressionNode> root;
 private:
  void BuildTreeFromReversePolishNotation
    (const std::vector<Token>& reverse_polish_notation);
};