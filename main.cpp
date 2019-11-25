#include <iostream>
#include <ExpressionTree.h>
#include <DifferentiateTree.h>

/*
 * TODO: 1) fixed precision numbers
 * TODO: 2) optimizations
 * TODO: 3) LaTeX
 * TODO: 4) Funny samples
 */
int main() {
  std::string expression;
  expression = "sin(ln(1-pow(x, 3)))";
  ExpressionTree tree(expression);
  tree.root = DifferentiateTree(std::move(tree.root));
  tree.Dump("dump");
}