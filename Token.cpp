#include "Token.h"

namespace esplang {
    Token::Token(TokenType type, std::wstring lexeme, TokenValue literal, int line)
        : m_type(type), m_lexeme(lexeme), m_literal(literal), m_line(line) {}

    void Token::print() {
        std::wstring s = L"NONE";
        if (m_literal.has_value()) {
            if (auto value = std::get_if<const std::wstring>(&(m_literal.value()))) {
                s = *value;
            }
            else {
                s = std::to_wstring(std::get<double>(m_literal.value()));
            }
        }
        std::wcout << m_type << " " << m_lexeme << " " << s << " " << std::to_wstring(m_line) << "\n";
    }
}
