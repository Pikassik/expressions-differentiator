#include <DotFileFromTreeGenerator.h>
#include <NodesIdentifierSingleton.h>

DotFileFromTreeGenerator::DotFileFromTreeGenerator(FILE* file)
: file_(file) {}

void DotFileFromTreeGenerator::operator()(const std::unique_ptr<ExpressionNode>& node) {
  auto print_node = [&](const std::unique_ptr<ExpressionNode>& node) {
    fprintf(file_, "node%zu [label=\"", node.get());
    if (node->type_id == NodesIdentifierSingleton::kNumberId) {
      fprintf(file_, "%d", node->value);
    } else {
      std::string_view label = NodesIdentifierSingleton::InstanceReversed().
        at(node->type_id).data();
      fwrite(label.data(), label.size(), 1, file_);
    }
    fprintf(file_, "\"]\n");
  };

  void* parent_ptr = node.get();

  if (node->left) {
    print_node(node->left);
    std::fprintf(file_, "edge [color=\"Green\"];\n");
    fprintf(file_, "node%zu -> node%zu\n", parent_ptr, node->left.get());
  }

  if (node->right) {
    print_node(node->right);
    std::fprintf(file_, "edge [color=\"Red\"];\n");
    fprintf(file_, "node%zu -> node%zu\n", parent_ptr, node->right.get());
  }
}

