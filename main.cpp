#include <iostream>
#include <ExpressionTree.h>

int main() {
  std::string expression;
  expression = "1 + 2 + 3";
  ExpressionTree tree(expression);
  tree.Dump("dump");
}