#pragma once
// Compiled helper shaders: locally built games ship them in reo-gpu-present beside the
// executable (copied from the build kit); source/development builds read the source tree.
#include <filesystem>
#include <system_error>
#if defined(__APPLE__)
#include <mach-o/dyld.h>
#include <vector>
#endif

namespace reo_shader_location {
#if defined(_WIN32)
// Defined in parallel_backend.cpp, which already includes the Windows API headers.
// (_wpgmptr cannot be used: it is only set for programs entered through wmain.)
std::filesystem::path executableDirectory();
#elif defined(__APPLE__)
inline std::filesystem::path executableDirectory() {
    uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size);
    std::vector<char> path(size);
    if (_NSGetExecutablePath(path.data(), &size) != 0)
        return {};
    std::error_code error;
    const auto executable = std::filesystem::canonical(path.data(), error);
    return error ? std::filesystem::path() : executable.parent_path();
}
#else
inline std::filesystem::path executableDirectory() {
    std::error_code error;
    const auto executable = std::filesystem::read_symlink("/proc/self/exe", error);
    return error ? std::filesystem::path() : executable.parent_path();
}
#endif

inline std::filesystem::path find(const std::filesystem::path& sourceDirectory, const char* name) {
    const auto directory = executableDirectory();
    if (!directory.empty()) {
        std::error_code error;
        const auto shipped = directory / "reo-gpu-present" / name;
        if (std::filesystem::is_regular_file(shipped, error))
            return shipped;
    }
    return sourceDirectory / name;
}
} // namespace reo_shader_location
