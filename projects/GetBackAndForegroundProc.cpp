#include <iostream>
#include <windows.h>
#include <filesystem>
#include <fstream>

typedef std::string string;
using std::cout;

int main() {
    HWND f = GetForegroundWindow();
    HWND xg = GetActiveWindow();

    wchar_t wT[256];
    wchar_t mT[256];

    if (f) {
        GetWindowText(f, wT, 256);
    }
    if (xg) { GetWindowText(xg, mT, 256); }
    return 0;
}
