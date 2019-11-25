#pragma once
#include <ExpressionNode.hpp>

std::unique_ptr<ExpressionNode>
DifferentiateTree(std::unique_ptr<ExpressionNode> node);