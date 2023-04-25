#include <iostream>
#include <string>
#include <vector>

#include "Lexer.h"
#include "Token.h"
#include <span>
#include <locale>

bool hadError = false;

void run(const std::wstring& src) {
    esplang::Lexer lexer(src);
    std::vector<esplang::Token> tokens = lexer.scanTokens();

    for (auto& t : tokens) {
        t.print();
    }
}

void runFile(const std::wstring& file) {
    std::wcout << file << "\n";
}

void runPrompt() {
    std::wstring line;

    for (;;) {
        std::wcout << "EspLang> ";
        std::getline(std::wcin, line);
        run(line);
        if (hadError)
            std::exit(65);

        hadError = false;
    }

}

int main(int argc, const char* const argv[]) {
    std::setlocale(LC_ALL, "en_US.utf8");
    if (argv == nullptr) {
        return 0;
    }
    if (argc > 2) {
        std::cerr << "Para ejecutar un archivo: esplang  <archivo.esp>\n";
    }
    else if (argc == 2) {
        //runFile(argv[1]);
    }
    else {
        runPrompt();
    }
}
