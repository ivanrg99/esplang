#pragma once
#include <string>

namespace esplang {
    void error_msg(int line, const std::wstring& message);
    void report(int line, const std::wstring& where, const std::wstring& message);
}
