#include "Lexer.h"
#include "utils.h"
#include <cwctype>

namespace esplang {
    Lexer::Lexer(std::wstring src) : m_src(std::move(src)), m_current(0), m_line(1), m_start(0) {
        m_tokens.reserve(50);
        initKeywords();
    }

    void Lexer::initKeywords() {
        m_keywords.emplace(L"y", TokenType::AND);
        m_keywords.emplace(L"objeto", TokenType::CLASS);
        m_keywords.emplace(L"sino", TokenType::ELSE);
        m_keywords.emplace(L"falso", TokenType::BOOL_FALSE);
        m_keywords.emplace(L"por", TokenType::FOR);
        m_keywords.emplace(L"funcion", TokenType::FUN);
        m_keywords.emplace(L"si", TokenType::IF);
        m_keywords.emplace(L"nada", TokenType::NIL);
        m_keywords.emplace(L"o", TokenType::OR);
        m_keywords.emplace(L"mostrar", TokenType::PRINT);
        m_keywords.emplace(L"devolver", TokenType::RETURN);
        m_keywords.emplace(L"super", TokenType::SUPER);
        m_keywords.emplace(L"este", TokenType::OBJ_THIS);
        m_keywords.emplace(L"verdadero", TokenType::BOOL_TRUE);
        m_keywords.emplace(L"variable", TokenType::VAR);
        m_keywords.emplace(L"mientras", TokenType::WHILE);
    }

    std::vector<Token>& Lexer::scanTokens() {
        while (!isAtEnd()) {
            m_start = m_current;
            scanToken();
        }
        m_tokens.emplace_back(Token(TokenType::END, L"", {}, m_line));
        return m_tokens;
    }

    bool Lexer::isAtEnd() {
        return m_current >= m_src.length();
    }

    void Lexer::addToken(TokenType type, TokenValue v) {
        m_tokens.emplace_back(Token(type, m_src.substr(m_start, m_current - m_start), v, m_line));
    }

    void Lexer::scanToken() {
        const wchar_t c = advance();
        switch (c) {
        case '(': addToken(TokenType::LEFT_PAREN, {}); break;
        case ')': addToken(TokenType::RIGHT_PAREN, {}); break;
        case '{': addToken(TokenType::LEFT_BRACE, {}); break;
        case '}': addToken(TokenType::RIGHT_BRACE, {}); break;
        case ',': addToken(TokenType::COMMA, {}); break;
        case '.': addToken(TokenType::DOT, {}); break;
        case '-': addToken(TokenType::MINUS, {}); break;
        case '+': addToken(TokenType::PLUS, {}); break;
        case ';': addToken(TokenType::SEMICOLON, {}); break;
        case '*': addToken(TokenType::STAR, {}); break;
        case '!':
            addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG, {});
            break;
        case '=':
            addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL, {});
            break;
        case '<':
            addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS, {});
            break;
        case '>':
            addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER, {});
            break;
        case '/':
            if (match('/')) {
                while (peek() != '\n' && !isAtEnd()) advance();
            }
            else {
                addToken(TokenType::SLASH, {});
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            m_line++;
            break;
        case '"': {
            handleString();
            break;
        }
        default:
            if (isDigit(c)) {
                handleNumber();
            }
            else if (isAlpha(c)) {
                handleIdentifier();
            }
            else {
                error_msg(m_line, L"Carácter no reconocido");
            }
            break;
        }
    }

    bool Lexer::isDigit(wchar_t c) {
        return c >= '0' && c <= '9';
    }

    void Lexer::handleIdentifier() {
        while (isAlphaNumeric(peek()))
            advance();

        std::wstring text = m_src.substr(m_start, m_current);

        if (m_keywords.find(text) == m_keywords.end()) {
            addToken(TokenType::IDENTIFIER, {});
        }
        else {
            addToken(m_keywords.at(text), {});
        }
    }

    bool Lexer::isAlphaNumeric(wchar_t c) {
        return isAlpha(c) || isDigit(c);
    }


    wchar_t Lexer::peekNext() {
        if (m_current + 1 >= m_src.length()) return '\0';
        return m_src.at(m_current + 1);
    }

    void Lexer::handleNumber() {
        while (isDigit(peek())) advance();

        // Look for a fractional part.
        if (peek() == '.' && isDigit(peekNext())) {
            // Consume the "."
            advance();

            while (isDigit(peek())) advance();
        }
        auto num = std::stod(m_src.substr(m_start, m_current - m_start));
        addToken(TokenType::NUMBER, num);
    }

    bool Lexer::isAlpha(wchar_t c) {
        return std::iswalpha(c) != 0;
    }

    void Lexer::handleString() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') m_line++;
            advance();
        }

        if (isAtEnd()) {
            error_msg(m_line, L"Hay una string sin acabar (falta una comilla)");
            return;
        }

        // The closing ".
        advance();

        // Get rid of the the 2 ", so we substract by 2
        addToken(TokenType::STRING, m_src.substr(m_start + 1, m_current - m_start - 2));
    }

    bool Lexer::match(wchar_t expected) {
        if (isAtEnd()) return false;
        if (m_src.at(m_current) != expected) return false;

        m_current++;
        return true;

    }

    wchar_t Lexer::peek() {
        if (isAtEnd()) return '\0';

        return m_src.at(m_current);
    }

    wchar_t Lexer::advance() {
        return m_src.at(m_current++);
    }


}
