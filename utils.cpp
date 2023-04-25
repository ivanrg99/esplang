#include "utils.h"
#include <iostream>

extern bool hadError;
namespace esplang {

    void error_msg(int line, const std::wstring& message) {
        report(line, L"", message);
    }

    void report(int line, const std::wstring& where, const std::wstring& message) {
        std::wcerr << L"[Linea " << line << L"] Error " << where << L": " << message << L"\n";
        hadError = true;
    }
}
