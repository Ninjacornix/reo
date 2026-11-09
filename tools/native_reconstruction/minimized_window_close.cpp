// Regression against the game's actual raylib archive. Never activates a window.
#include "raylib.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <thread>
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void*, int);
extern "C" __declspec(dllimport) int __stdcall PostMessageW(void*, unsigned int, std::uintptr_t, std::intptr_t);
extern "C" __declspec(dllimport) void* __stdcall GetForegroundWindow();

int main(int argc, char** argv) {
    if (argc != 2 || (std::strcmp(argv[1], "baseline") && std::strcmp(argv[1], "fixed"))) return 2;
    const bool fixed = !std::strcmp(argv[1], "fixed");
    const auto foreground = GetForegroundWindow();
    SetTraceLogLevel(LOG_WARNING);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIDDEN);
    if (fixed) SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(128, 96, "Owned minimized close regression");
    if (!IsWindowReady()) return 3;
    auto* window = GetWindowHandle();
    // Same explicit background startup as the native-media game fixture.
    ShowWindow(window, 7); // SW_SHOWMINNOACTIVE
    std::thread sender([&] {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::fprintf(stderr, "close_posted=%d\n", PostMessageW(window, 0x10, 0, 0));
    });
    const auto end = std::chrono::steady_clock::now() + std::chrono::seconds(2);
    bool minimized = false;
    unsigned polls = 0;
    while (std::chrono::steady_clock::now() < end) {
        PollInputEvents();
        ++polls;
        minimized |= IsWindowState(FLAG_WINDOW_MINIMIZED);
        if (WindowShouldClose()) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    const bool closed = WindowShouldClose();
    const bool configured = IsWindowState(FLAG_WINDOW_ALWAYS_RUN);
    const bool unchanged = GetForegroundWindow() == foreground;
    sender.join();
    CloseWindow();
    std::printf("{\"always_run\":%s,\"minimized_observed\":%s,\"close_observed\":%s,"
                "\"foreground_unchanged\":%s,\"focus_requested\":false,\"polls\":%u}\n",
                configured ? "true" : "false", minimized ? "true" : "false",
                closed ? "true" : "false", unchanged ? "true" : "false", polls);
    return closed && minimized && configured == fixed ? 0 : 1;
}
