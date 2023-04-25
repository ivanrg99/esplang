#pragma once

#include <iostream>

namespace esplang {
    enum class TokenType {
        // Single-wchar_tacter tokens.
        LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
        COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

        // One or two wchar_tacter tokens.
        BANG, BANG_EQUAL,
        EQUAL, EQUAL_EQUAL,
        GREATER, GREATER_EQUAL,
        LESS, LESS_EQUAL,

        // Literals.
        IDENTIFIER, STRING, NUMBER,

        // Keywords.
        AND, CLASS, ELSE, BOOL_FALSE, FUN, FOR, IF, NIL, OR,
        PRINT, RETURN, SUPER, OBJ_THIS, BOOL_TRUE, VAR, WHILE,

        END
    };

    static std::wostream& operator<<(std::wostream& os, const TokenType& t) {
        switch (t) {
        case TokenType::LEFT_PAREN:
            os << "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            os << "RIGHT_PAREN";
            break;
        case TokenType::LEFT_BRACE:
            os << "LEFT_BRACE";
            break;
        case TokenType::RIGHT_BRACE:
            os << "RIGHT_BRACE";
            break;
        case TokenType::COMMA:
            os << "COMMA";
            break;
        case TokenType::DOT:
            os << "DOT";
            break;
        case TokenType::MINUS:
            os << "MINUS";
            break;
        case TokenType::PLUS:
            os << "PLUS";
            break;
        case TokenType::STAR:
            os << "STAR";
            break;
        case TokenType::SLASH:
            os << "SLASH";
            break;
        case TokenType::SEMICOLON:
            os << "SEMICOLON";
            break;
        case TokenType::IDENTIFIER:
            os << "IDENTIFIER";
            break;
        case TokenType::STRING:
            os << "STRING";
            break;
        case TokenType::NUMBER:
            os << "NUMBER";
            break;
        case TokenType::ELSE:
            os << "ELSE";
            break;
        case TokenType::END:
            os << "END";
            break;
        case TokenType::EQUAL:
            os << "EQUAL";
            break;
        case TokenType::BANG_EQUAL:
            os << "BANG_EQUAL";
            break;
        case TokenType::EQUAL_EQUAL:
            os << "EQUAL_EQUAL";
            break;
        case TokenType::GREATER:
            os << "GREATER";
            break;
        case TokenType::GREATER_EQUAL:
            os << "GREATER_EQUAL";
            break;
        case TokenType::LESS:
            os << "LESS";
            break;
        case TokenType::LESS_EQUAL:
            os << "LESS_EQUAL";
            break;
        case TokenType::AND:
            os << "AND";
            break;
        case TokenType::CLASS:
            os << "CLASS";
            break;
        case TokenType::BOOL_FALSE:
            os << "BOOL_FALSE";
            break;
        case TokenType::BOOL_TRUE:
            os << "BOOL_TRUE";
            break;
        case TokenType::WHILE:
            os << "WHILE";
            break;
        case TokenType::BANG:
            os << "BANG";
            break;
        case TokenType::FUN:
            os << "FUN";
            break;
        case TokenType::FOR:
            os << "FOR";
            break;
        case TokenType::IF:
            os << "IF";
            break;
        case TokenType::NIL:
            os << "NIL";
            break;
        case TokenType::OR:
            os << "OR";
            break;
        case TokenType::PRINT:
            os << "PRINT";
            break;
        case TokenType::RETURN:
            os << "RETURN";
            break;
        case TokenType::OBJ_THIS:
            os << "OBJ_THIS";
            break;
        case TokenType::SUPER:
            os << "SUPER";
            break;
        case TokenType::VAR:
            os << "VAR";
            break;
        default:
            os << "FORGOT TO IMPLEMENT PRINT";
            break;
        }
            return os;
    }
}
