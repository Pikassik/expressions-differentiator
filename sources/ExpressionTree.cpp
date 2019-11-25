#include <ExpressionTree.h>
#include <ReversePolishNotationGenerator.h>
#include <NodesIdentifierSingleton.h>
#include <DotFileFromTreeGenerator.h>
#include <cstring>
#include <cassert>

ExpressionTree::ExpressionTree(const std::string_view& expression) {
  Tokenizer tokenizer;
  std::vector<Token> expression_tokens = tokenizer.GetTokens(expression);
  ReversePolishNotationGenerator
    reverse_polish_notation_generator(expression_tokens);
  std::vector<Token> reverse_polish_notation =
    reverse_polish_notation_generator.GenerateExpression();
  BuildTreeFromReversePolishNotation(reverse_polish_notation);
}

template<class Func>
void ExpressionTree::DFS(const std::unique_ptr<ExpressionNode>& node, Func function) {
  function(node);
  if (node->left)
    DFS(node->left, function);
  if (node->right)
    DFS(node->right, function);
}

void ExpressionTree::BuildTreeFromReversePolishNotation
  (const std::vector<Token>& reverse_polish_notation) {
  std::vector<std::unique_ptr<ExpressionNode>> stack;
  stack.reserve(reverse_polish_notation.size());
  for (const auto& token: reverse_polish_notation) {
    switch (token.type) {
      case VALUE: {
        stack.emplace_back(
          std::make_unique<ExpressionNode>(
            NodesIdentifierSingleton::kNumberId,
            token.token_value,
            nullptr,
            nullptr));
        break;
      }
      case VARIABLE: {
        stack.emplace_back(
          std::make_unique<ExpressionNode>(
            NodesIdentifierSingleton::Instance().at(token.identifier),
            0,
            nullptr,
            nullptr));
        break;
      }
      case OPERATION: {
        std::unique_ptr right_arg(std::move(stack.back()));
        stack.pop_back();
        std::unique_ptr left_arg(std::move(stack.back()));
        stack.pop_back();
        stack.emplace_back(
          std::make_unique<ExpressionNode>(
            NodesIdentifierSingleton::Instance().at(token.identifier),
            0,
            std::move(left_arg),
            std::move(right_arg)));
        break;
      }
      case UNARY_OPERATION: {
        if (token.identifier == "-") {
          (*stack.back()).value *= -1;
        }
        break;
      }
      case FUNCTION: {
        std::unique_ptr arg(std::move(stack.back()));
        stack.pop_back();
        stack.emplace_back(
          std::make_unique<ExpressionNode>(
            NodesIdentifierSingleton::Instance().at(token.identifier),
            0,
            std::move(arg),
            nullptr));
        break;
      }
      default: assert(false);
    }
  }
  root = std::move(stack.back());
}

void ExpressionTree::Dump(const std::string_view& filename) {
  std::string dot_file_name = filename.data();
  dot_file_name += ".dot";
  FILE* dot_file = fopen(dot_file_name.c_str(), "w");
  std::fprintf(dot_file,
    "digraph akitree {\n"
    "graph [nodesep=0.5];\n"
    "node [fontname=\"Helvetica\", color=\"Lavender\", style=\"filled\"];\n");
  std::string_view first_node_label =
    NodesIdentifierSingleton::InstanceReversed().at(root->type_id);
  fprintf(dot_file, "node%zu [label=\"%.*s\"]\n",
          root.get(),
          first_node_label.size(), first_node_label.data());
  DFS(root, DotFileFromTreeGenerator(dot_file));
  std::fwrite("}\n", 2, 1, dot_file);
  fclose(dot_file);
  std::string format(
    filename.size() * 2 + std::strlen("dot  .dot -Tpng -o  .png"), '\0');
  std::snprintf(format.data(), format.size(), "dot %.*s.dot -Tpng -o  %.*s.png",
                filename.size(), filename.data(),
                filename.size(), filename.data());
  system(format.c_str());
}
