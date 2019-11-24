#include <ReversePolishNotationGenerator.h>
#include <cassert>

namespace {
bool operator<(const Token& lhvalue, const Token& rhvalue) {

  if (rhvalue.type == UNARY_OPERATION)
    return true; // order in this 2 strings is rly important
  if (lhvalue.type == UNARY_OPERATION)
    return false; // unary is max
  if (rhvalue.type == LEFT_BRACKET)
    return false; // left_bracket min
  if (lhvalue.type == LEFT_BRACKET)
    return true;
  if (rhvalue.type == COMMA)
    return false; // left bracket < comma < others
  if (lhvalue.type == COMMA)
    return true;
  if (lhvalue.type == OPERATION && rhvalue.type == FUNCTION)
    return true;

  if (lhvalue.type == OPERATION && rhvalue.type == OPERATION) {
    return (lhvalue.token_value == '+' || lhvalue.token_value == '-') &&
           (rhvalue.token_value == '*' || rhvalue.token_value == '/');
  }

  return false;
}

bool operator>(const Token& lhvalue, const Token& rhvalue) {
  return rhvalue < lhvalue;
}

bool operator==(const Token& lhvalue, const Token& rhvalue) {
  return !((lhvalue < rhvalue) || (rhvalue < lhvalue));
}

bool operator!=(const Token& lhvalue, const Token& rhvalue) {
  return lhvalue < rhvalue || rhvalue < lhvalue;
}

bool operator<=(const Token& lhvalue, const Token& rhvalue) {
  return !(rhvalue < lhvalue);
}

bool operator>=(const Token& lhvalue, const Token& rhvalue) {
  return !(lhvalue < rhvalue);
}

} // namespace

ReversePolishNotationGenerator::
ReversePolishNotationGenerator(const std::vector<Token>& expression)
: expression_(expression) {}

std::vector<Token>
ReversePolishNotationGenerator::GenerateExpression() {
  for (auto token: expression_) {
    switch (token.type) {
      case VALUE: {
        reverse_polish_notation_.push_back(token);
        break;
      }
      case VARIABLE: {
        reverse_polish_notation_.push_back(token);
        break;
      }
      case LEFT_BRACKET: {
        operations_stack_.push_back(token);
        break;
      }
      case UNARY_OPERATION: {
        operations_stack_.push_back(token);
        break;
      }
      case OPERATION: {
        if (!operations_stack_.empty() &&
            operations_stack_.back() >= token) {
          ProcessOperation(token);
        } else {
          operations_stack_.push_back(token);
        }
        break;
      }
      case COMMA: {
        ProcessOperation(token);
        ++commas_count_stack_.back();
        break;
      }
      case FUNCTION: {
        operations_stack_.push_back(token);
        commas_count_stack_.push_back(0);
        break;
      }
      case RIGHT_BRACKET: {
        ProcessRightBracket();
        break;
      }
      default: assert(false);
    }
  }

  while (!operations_stack_.empty()) {
    reverse_polish_notation_.push_back(operations_stack_.back());
    operations_stack_.pop_back();
  }

  return std::move(reverse_polish_notation_);
}

void ReversePolishNotationGenerator::ProcessOperation(const Token& token) {
  while ((!operations_stack_.empty() &&
          operations_stack_.back() >= token)) {
    reverse_polish_notation_.push_back(operations_stack_.back());
    operations_stack_.pop_back();
  }

  if (token.type != COMMA) {
    operations_stack_.push_back(token);
  }
}

void ReversePolishNotationGenerator::ProcessRightBracket() {
  while (operations_stack_.back().type != LEFT_BRACKET) {
    assert(!operations_stack_.empty());
    reverse_polish_notation_.push_back(operations_stack_.back());
    operations_stack_.pop_back();
  }

  if (operations_stack_.size() > 1 &&
      operations_stack_[operations_stack_.size() - 2].type == FUNCTION) {
    reverse_polish_notation_.push_back(
      operations_stack_[operations_stack_.size() - 2]);
    operations_stack_.pop_back();
    operations_stack_.pop_back();
    assert(!commas_count_stack_.empty());
    reverse_polish_notation_.back().token_value =
      commas_count_stack_.back() + 1;
    commas_count_stack_.pop_back();
  } else {
    operations_stack_.pop_back();
  }
}


