#pragma once
#include <string>
#include <variant>
#include <optional>

#include "TokenType.h"

namespace esplang {
    typedef std::optional<std::variant<double, const std::wstring>> TokenValue;

    class Token {

    public:
        Token(TokenType type, std::wstring lexeme, TokenValue literal, int line);
        void print();

    private:
        const TokenType m_type;
        const std::wstring m_lexeme;
        const int m_line;
        const TokenValue m_literal;
    };
}
