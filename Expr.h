#pragma once
#include "Token.h"

namespace esplang {
    // Pure virtual class
    class Expr {
    public:
        virtual ~Expr() = 0;
    };

    class Binary : public Expr {
    public:
    private:
        const std::unique_ptr<Expr> left;
        const Token op;
        const std::unique_ptr<Expr> right;
    };
}
