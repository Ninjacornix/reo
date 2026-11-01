#pragma once
#include <cstdio>
#include <cstdint>
#include <filesystem>

namespace reo::host_file {
inline FILE* openRead(const std::filesystem::path& path) {
#ifdef _WIN32
    return _wfopen(path.c_str(), L"rb");
#else
    return fopen(path.c_str(), "rb");
#endif
}
inline int seek(FILE* file, int64_t offset, int origin) {
#ifdef _WIN32
    return _fseeki64(file, offset, origin);
#else
    static_assert(sizeof(off_t) >= sizeof(int64_t), "Disc IO requires 64-bit offsets");
    return fseeko(file, static_cast<off_t>(offset), origin);
#endif
}
inline int64_t tell(FILE* file) {
#ifdef _WIN32
    return _ftelli64(file);
#else
    return ftello(file);
#endif
}
} // namespace reo::host_file
