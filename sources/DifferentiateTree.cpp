#include <DifferentiateTree.h>
#include <NodesIdentifierSingleton.h>

std::unique_ptr<ExpressionNode>
DifferentiateTree(std::unique_ptr<ExpressionNode> node) {
  if (!node)
    return nullptr;
  if (node->type_id == NodesIdentifierSingleton::kNumberId)
    return std::make_unique<ExpressionNode>(NodesIdentifierSingleton::kNumberId,
                                            0, nullptr, nullptr);

  switch (node->type_id) {
    #include <generated/FunctionsDerivatives.h>
  }

  return node;
}
