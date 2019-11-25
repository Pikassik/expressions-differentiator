#include <iostream>
#include <ExpressionTree.h>
#include <DifferentiateTree.h>

/*
// TODO: 1) fixed precision numbers
// TODO: 2) derivatives
// TODO: 3) optimizations
// TODO: 4) LaTeX
// TODO: 5) Funny samples
 */
int main() {
  std::string expression;
  expression = "x / (x + 5)";
  ExpressionTree tree(expression);
  tree.root = DifferentiateTree(std::move(tree.root));
  tree.Dump("dump");
}