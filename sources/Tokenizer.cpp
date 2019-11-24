#include <Tokenizer.h>
#include <cctype>
#include <cstdlib>

std::vector<Token>
Tokenizer::GetTokens(const std::string_view& expression) {
  for (size_t i = 0; i < expression.size(); ) {

    while (i < expression.size() && IsSpace(expression[i]))
      ++i;

    if (i == expression.size())
      break;

    if (IsOperation(expression[i])) {
      if (
          (expression[i] == '+' ||
           expression[i] == '-') &&
          (i == 0 ||
           tokens_.back().type == LEFT_BRACKET ||
           tokens_.back().type == COMMA ||
           tokens_.back().type == OPERATION)
          ) {
        if (expression[i] == '-')
          tokens_.emplace_back(expression.substr(i, 1),
                               UNARY_OPERATION,
                               expression[i]);
      } else {
        tokens_.emplace_back(
            expression.substr(i, 1), OPERATION, expression[i]);
      }

      ++i;

    } else if (std::isdigit(expression[i])) {

      size_t begin = i;
      while (i < expression.size() &&
             std::isdigit(expression[i]))
        ++i;
      // TODO fixed precision numbers
      tokens_.emplace_back(expression.substr(begin, i - begin),
                           VALUE,
                           strtol(expression.data() + begin, nullptr, 10));

    } else if (IsLeftBracket(expression[i])) {

      tokens_.emplace_back(expression.substr(i, 1), LEFT_BRACKET);
      ++i;

    } else if (IsRightBracket(expression[i])) {

      tokens_.emplace_back(expression.substr(i, 1), RIGHT_BRACKET);
      ++i;

    } else if (IsComma(expression[i])) {

      tokens_.emplace_back(expression.substr(i, 1), COMMA);
      ++i;

    } else /*variable or function (unique identifier)*/ {

      size_t begin = i;
      while ( i < expression.size() &&
             (std::isalpha(expression[i]) ||
              std::isdigit(expression[i]))) {
        ++i;
      }

      size_t end = i;

      while (i < expression.size() &&
             IsSpace(expression[i]))
        ++i;

      if (i == expression.size() ||
          !IsLeftBracket(expression[i])) {
        tokens_.emplace_back(expression.substr(begin, end - begin), VARIABLE);
        continue;
      }

      tokens_.emplace_back(expression.substr(begin, end - begin), FUNCTION);
    }
  }

  return std::move(tokens_);
}

bool Tokenizer::IsOperation(char letter) {
    return letter == '+' || letter == '-' || letter == '*' || letter == '/';
}

bool Tokenizer::IsSpace(char letter) {
    return letter == ' ';
}

bool Tokenizer::IsLeftBracket(char letter) {
    return letter == '(';
}

bool Tokenizer::IsRightBracket(char letter) {
    return letter == ')';
}

bool Tokenizer::IsComma(char letter) {
    return letter == ',';
}

