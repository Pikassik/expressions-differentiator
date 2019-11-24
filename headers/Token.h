#pragma once
#include <string_view>

enum TokenType {
    OPERATION,
    VALUE,
    VARIABLE,
    FUNCTION,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    COMMA,
    UNARY_OPERATION
};

struct Token {
    std::string_view identifier;
    TokenType type;
    int token_value;

    // OPERATION: operation sign
    // VALUE: constant value
    // VARIABLE: is negative
    // FUNCTION: variables count
    // others: --

    Token() = default;

    Token(const std::string_view& identifier,
          TokenType type,
          int token_value = 0);
};