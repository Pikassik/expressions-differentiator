#define LET auto
#define MOV(x) std::move(x)
#define RET break
#define COPY(x) x ? std::make_unique<ExpressionNode>(*x) : nullptr
#define LEFT node->left
#define RIGHT node->right
#define DIF(x) DifferentiateTree(std::move(x))
#define TYPE(x) NodesIdentifierSingleton::Instance().at(x)
#define NUMBER_TYPE NodesIdentifierSingleton::kNumberId
#define MUL(left_node, right_node)\
std::make_unique<ExpressionNode>(TYPE("*"), 0, MOV(left_node), MOV(right_node))
#define CUR_TYPE node->type_id
#define CUR_VALUE node->value
#define NEW(type_id, value, left_node, right_node)\
std::make_unique<ExpressionNode>(type_id, value, MOV(left_node), MOV(right_node))
