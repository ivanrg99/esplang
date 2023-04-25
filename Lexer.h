#pragma once
#include "Token.h"
#include <string>
#include <vector>
#include <unordered_map>

#include "Expr.h"

namespace esplang {
    class Lexer {
    public:
        Lexer(std::wstring src);
        std::vector<Token>& scanTokens();
    private:
        bool isAtEnd();
        void scanToken();
        wchar_t advance();
        void addToken(TokenType type, TokenValue v);
        bool match(wchar_t expected);
        wchar_t peek();
        void handleString();
        bool isDigit(wchar_t c);
        void handleNumber();
        bool isAlpha(wchar_t c);
        bool isAlphaNumeric(wchar_t c);
        wchar_t peekNext();
        void handleIdentifier();
        void initKeywords();

        const std::wstring m_src;
        std::vector<Token> m_tokens;
        int m_start, m_current, m_line;
        std::unordered_map<std::wstring, TokenType> m_keywords;

    };
}
