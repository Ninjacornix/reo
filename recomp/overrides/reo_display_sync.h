#pragma once
#include "runtime/gs/display_sync.h"
#include <cstdio>

// raylib's desktop backend owns the current GLFW context. Avoid GLFW's OpenGL
// headers here: bootstrap already includes raylib's conflicting drawing types.
#if !defined(PLATFORM_VITA)
extern "C" void glfwSwapInterval(int interval);
extern "C" int glfwExtensionSupported(const char* extension);
#endif

namespace reo::display_sync {
inline void configureOpenGl() {
#if !defined(PLATFORM_VITA)
    const Mode mode = configured();
    const bool adaptive =
        mode == Mode::Adaptive && (glfwExtensionSupported("WGL_EXT_swap_control_tear") ||
                                   glfwExtensionSupported("GLX_EXT_swap_control_tear"));
    const int interval = swapInterval(mode, adaptive);
    glfwSwapInterval(interval);
    std::fprintf(stderr, "[DISPLAY-SYNC] OpenGL requested=%s interval=%d%s\n", name(mode), interval,
                 mode == Mode::Adaptive && !adaptive ? " (adaptive unavailable; using on)" : "");
#endif
}
} // namespace reo::display_sync
