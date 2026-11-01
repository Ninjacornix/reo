// SPDX-License-Identifier: GPL-3.0-only
// Test host deliberately omits longPathAware. It exercises Python's ordinary
// Win32 path limit without changing the machine's long-path registry setting.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>

int wmain(int argc, wchar_t** argv) {
    if (argc < 3) return 2;
    auto python = LoadLibraryW(argv[1]);
    if (!python) {
        std::fprintf(stderr, "Unable to load test Python DLL: %lu\n", GetLastError());
        return 3;
    }
    auto main = reinterpret_cast<int(__cdecl*)(int, wchar_t**)>(GetProcAddress(python, "Py_Main"));
    return main ? main(argc - 1, argv + 1) : 4;
}
