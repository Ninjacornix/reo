#pragma once
// Refuse to start, with a readable message, when the graphics driver cannot open the
// game window. raylib 5.5 asks GLFW for an OpenGL 3.3 core context; without one
// (Microsoft Basic Display Adapter, missing vendor driver, some remote sessions)
// InitWindow only logs a warning and returns, and PS2Runtime::initialize then passes
// the null window to GetWindowHandle(). An RC1 player report (2026-11-03) crashed
// there: "WGL_ARB_create_context_profile unavailable", Vulkan unavailable, then
// "read 0x360" in the GLFW window lookup.
//
// The probe creates and destroys a hidden window with raylib's exact GL 3.3 hints
// before the runtime does, then releases GLFW so raylib initializes it normally.
// Vulkan is not required: the GS backend already falls back to software without it.
// GLFW is reached through raylib's bundled copy; only the calls used are declared.
#include <cstdio>

extern "C" {
struct GLFWwindow;
struct GLFWmonitor;
int glfwInit(void);
void glfwTerminate(void);
void glfwDefaultWindowHints(void);
void glfwWindowHint(int hint, int value);
GLFWwindow* glfwCreateWindow(int width, int height, const char* title,
                             GLFWmonitor* monitor, GLFWwindow* share);
void glfwDestroyWindow(GLFWwindow* window);
}

namespace reo_display_probe {

// Values from GLFW 3.4's glfw3.h, as bundled with raylib 5.5.
constexpr int kVisible = 0x00020004;
constexpr int kContextVersionMajor = 0x00022002;
constexpr int kContextVersionMinor = 0x00022003;
constexpr int kOpenGlForwardCompat = 0x00022006;
constexpr int kOpenGlProfile = 0x00022008;
constexpr int kOpenGlCoreProfile = 0x00032001;

inline constexpr const char* kMessage =
    "This PC's graphics driver does not provide OpenGL 3.3, which the game needs to "
    "open its window.\n\nInstall the latest graphics driver from your graphics card "
    "maker (NVIDIA, AMD or Intel), then start the game again. Microsoft's basic display "
    "driver and some remote-desktop sessions do not provide OpenGL 3.3.";

inline bool openGl33Available() {
    if (!glfwInit()) return false;
    glfwDefaultWindowHints();
    glfwWindowHint(kVisible, 0);
    glfwWindowHint(kContextVersionMajor, 3);
    glfwWindowHint(kContextVersionMinor, 3);
    glfwWindowHint(kOpenGlProfile, kOpenGlCoreProfile);
    glfwWindowHint(kOpenGlForwardCompat, 0);
    GLFWwindow* window = glfwCreateWindow(64, 64, "OpenGL 3.3 check", nullptr, nullptr);
    if (window) glfwDestroyWindow(window);
    glfwTerminate();
    return window != nullptr;
}

} // namespace reo_display_probe
