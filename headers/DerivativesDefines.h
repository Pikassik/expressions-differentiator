#define LET auto
#define MOV(x) std::move(x)
#define RET break
#define COPY(x) x ? std::make_unique<ExpressionNode>(*x) : nullptr
#define LEFT node->left
#define RIGHT node->right
#define DIF(x) DifferentiateTree(std::move(x))
#define TYPE(x) NodesIdentifierSingleton::Instance().at(x)
#define NUMBER_TYPE NodesIdentifierSingleton::kNumberId
#define VALUE(value)\
std::make_unique<ExpressionNode>(NUMBER_TYPE, value, nullptr, nullptr)
#define OPERATION(operation, left_node, right_node)\
std::make_unique<ExpressionNode>(TYPE(operation), 0, MOV(left_node), MOV(right_node))
#define FUNC(func, left_node)\
std::make_unique<ExpressionNode>(TYPE(func), 0, MOV(left_node), nullptr)
#define CUR_TYPE node->type_id
#define CUR_VALUE node->value
#define NEW(label, value, left_node, right_node)\
std::make_unique<ExpressionNode>(TYPE(label), value, MOV(left_node), MOV(right_node))
