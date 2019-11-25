#include <iostream>
#include <ExpressionTree.h>

int main() {
  std::string expression;
  expression = "sin(4 * x)";
  ExpressionTree tree(expression);
  tree.Dump("dump");
}