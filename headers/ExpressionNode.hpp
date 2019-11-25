#pragma once
#include <cstdint>
#include <string>
#include <memory>

struct ExpressionNode {
  inline ExpressionNode(const ExpressionNode& other);
  inline ExpressionNode(int type_id,
                        int value,
                        std::unique_ptr<ExpressionNode>&& left,
                        std::unique_ptr<ExpressionNode>&& right);
  int type_id;
  int value;
  std::unique_ptr<ExpressionNode> left;
  std::unique_ptr<ExpressionNode> right;
};

ExpressionNode::ExpressionNode(const ExpressionNode& other)
: type_id(other.type_id)
, value(other.value) {
  if (other.left) {
    left  = std::make_unique<ExpressionNode>(*(other.left));
  }
  if (other.right) {
    right = std::make_unique<ExpressionNode>(*(other.right));
  }
}

ExpressionNode::ExpressionNode(int type_id,
                               int value,
                               std::unique_ptr<ExpressionNode>&& left,
                               std::unique_ptr<ExpressionNode>&& right)
: type_id(type_id)
, value(value)
, left(std::move(left))
, right(std::move(right)) {}
