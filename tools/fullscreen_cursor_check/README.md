# Fullscreen cursor checks

Apply `third_party/patches/ps2recomp/0102-fullscreen-cursor.patch` to the matching pinned SDK before building. Link this check with that SDK's `ps2xRuntime/src/lib/Kernel/Host/Win32ModalRender.cpp` and Windows `user32`.

For LLVM/MinGW, compile with C++20, `_WIN32_WINNT=0x0a00` and `WINVER=0x0a00`. Run the resulting executable on an interactive Windows desktop. It creates short-lived windows, exercises the actual window procedure and restores the previous foreground window and cursor position.

Eight checks cover the normal windowed cursor, launcher-style borderless fullscreen, mouse movement, switching windows, returning to the game, both Ctrl+Enter transitions and closing fullscreen. No game data or GPU backend is required. The fix uses `WM_SETCURSOR` and window focus/geometry rather than changing Windows' cursor visibility counter or locking the pointer to the game.
