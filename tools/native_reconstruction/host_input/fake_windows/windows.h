#pragma once
#include <cstdint>
using WORD=std::uint16_t;
using SHORT=std::int16_t;
using DWORD=std::uint32_t;
using HWND=void*;
inline constexpr DWORD ERROR_SUCCESS=0;
inline constexpr int VK_SPACE=0x20,VK_RETURN=0x0d,VK_CONTROL=0x11,VK_LCONTROL=0xa2,
    VK_RCONTROL=0xa3,VK_BACK=0x08,VK_LEFT=0x25,VK_UP=0x26,VK_RIGHT=0x27,VK_DOWN=0x28;
SHORT GetAsyncKeyState(int);
bool IsWindow(HWND);
DWORD GetWindowThreadProcessId(HWND,DWORD*);
DWORD GetCurrentProcessId();
HWND GetForegroundWindow();
bool IsIconic(HWND);
