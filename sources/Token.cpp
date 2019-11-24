#include <Token.h>

Token::Token(const std::string_view& identifier,
             TokenType type,
             int token_value)
: identifier(identifier)
, type(type)
, token_value(token_value) {}