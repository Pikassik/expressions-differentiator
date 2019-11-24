#pragma once
#include <ExpressionNode.hpp>

class DotFileFromTreeGenerator {
 public:
  explicit DotFileFromTreeGenerator(FILE* file);
  void operator()(const std::unique_ptr<ExpressionNode>& node);
 private:
  FILE* file_;
};