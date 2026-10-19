#pragma once
// Private Windows cache IO and bounded codec. Never stores GS/VU/VRAM state.
#include <algorithm>
#include <array>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <vector>
#include <windows.h>
namespace reo_parallel_backend::cache_store {
constexpr size_t MaxPayload = 256u * 1024u * 1024u, HeaderBytes = 80;
constexpr std::array<uint8_t, 16> Magic = {'R', 'E', 'O', 'P', 'G', 'S', 'C', 'A',
                                           'C', 'H', 'E', '0', '0', '0', '1', 0};
// Pin renderer and shader/API policy, not a particular game or process.
constexpr char Compatibility[] = "cc6184af7e0c03da603045ca371ffa5dae9b0655;binning-barrier-"
                                 "allcommands-v1;gif-remaining-v1;reo-cache-v1";
struct Identity {
    uint32_t format = 0, vendor = 0, device = 0, driver = 0, flags = 0;
    std::array<uint8_t, 16> uuid{};
};
inline uint64_t hash(const uint8_t* p, size_t bytes) {
    uint64_t h = 14695981039346656037ull;
    for (size_t i = 0; i < bytes; ++i)
        h = (h ^ p[i]) * 1099511628211ull;
    return h;
}
inline uint64_t compatibilityHash() {
    return hash(reinterpret_cast<const uint8_t*>(Compatibility), sizeof(Compatibility) - 1);
}
inline uint32_t u32(const uint8_t* p) {
    uint32_t v;
    std::memcpy(&v, p, 4);
    return v;
}
inline uint64_t u64(const uint8_t* p) {
    uint64_t v;
    std::memcpy(&v, p, 8);
    return v;
}
inline void put32(uint8_t* p, uint32_t v) {
    std::memcpy(p, &v, 4);
}
inline void put64(uint8_t* p, uint64_t v) {
    std::memcpy(p, &v, 8);
}
// Guard the upstream parser's counts before it can allocate partial mappings.
// Pinned VK_MAX_PIPELINE_BINARY_KEY_SIZE_KHR=32; keys occupy fixed-size slots.
inline bool binaryStructure(const uint8_t* data, size_t bytes) {
    constexpr size_t KeyBytes = 32, Prefix = 16 + 4 + KeyBytes + 4;
    constexpr char BinaryMagic[16] = "GraniteBinary1";
    if (bytes < Prefix + 8 || std::memcmp(data, BinaryMagic, 16) || !u32(data + 16) ||
        u32(data + 16) > KeyBytes)
        return false;
    size_t pos = Prefix;
    const uint32_t pipelines = u32(data + Prefix - 4);
    if (pipelines > 65536 || pipelines > (bytes - pos) / 16)
        return false;
    for (uint32_t i = 0; i < pipelines; ++i) {
        if (bytes - pos < 16)
            return false;
        const uint64_t count = u64(data + pos + 8);
        pos += 16;
        if (count > 4096 || count > (bytes - pos) / 8)
            return false;
        pos += size_t(count) * 8;
    }
    if (bytes - pos < 8)
        return false;
    const uint64_t binaries = u64(data + pos);
    pos += 8;
    if (binaries > 65536 || binaries > (bytes - pos) / (16 + KeyBytes))
        return false;
    for (uint64_t i = 0; i < binaries; ++i) {
        if (bytes - pos < 16 + KeyBytes)
            return false;
        const uint32_t length = u32(data + pos + 8), key = u32(data + pos + 12);
        pos += 16 + KeyBytes;
        if (!key || key > KeyBytes)
            return false;
        const uint64_t padded = (uint64_t(length) + 7) & ~7ull;
        if (padded > bytes - pos)
            return false;
        pos += size_t(padded);
    }
    return pos == bytes;
}
inline bool payloadStructure(const std::vector<uint8_t>& payload, const Identity& id) {
    if (payload.empty() || payload.size() > MaxPayload)
        return false;
    if (id.format == 1)
        return binaryStructure(payload.data(), payload.size());
    // Granite legacy wrapper is UUID16 + Util::Hash8 + Vulkan cache header.
    // Granite itself additionally verifies its hash before vkCreatePipelineCache.
    if (id.format || payload.size() < 24 + 32 || std::memcmp(payload.data(), id.uuid.data(), 16))
        return false;
    const uint8_t* vk = payload.data() + 24;
    const uint32_t size = u32(vk);
    return size >= 32 && size <= payload.size() - 24 && u32(vk + 4) == 1 &&
           u32(vk + 8) == id.vendor && u32(vk + 12) == id.device &&
           !std::memcmp(vk + 16, id.uuid.data(), 16);
}
inline std::vector<uint8_t> encode(const std::vector<uint8_t>& payload, const Identity& id) {
    if (!payloadStructure(payload, id))
        return {};
    std::vector<uint8_t> file(HeaderBytes + payload.size());
    std::memcpy(file.data(), Magic.data(), 16);
    put32(file.data() + 16, 1);
    put32(file.data() + 20, id.format);
    put32(file.data() + 24, id.vendor);
    put32(file.data() + 28, id.device);
    put32(file.data() + 32, id.driver);
    put32(file.data() + 36, id.flags);
    std::memcpy(file.data() + 40, id.uuid.data(), 16);
    put64(file.data() + 56, compatibilityHash());
    put64(file.data() + 64, payload.size());
    put64(file.data() + 72, hash(payload.data(), payload.size()));
    std::memcpy(file.data() + HeaderBytes, payload.data(), payload.size());
    return file;
}
inline std::vector<uint8_t> decode(const std::vector<uint8_t>& file, const Identity& id) {
    if (file.size() < HeaderBytes || file.size() > HeaderBytes + MaxPayload ||
        std::memcmp(file.data(), Magic.data(), 16) || u32(file.data() + 16) != 1 ||
        u32(file.data() + 20) != id.format || u32(file.data() + 24) != id.vendor ||
        u32(file.data() + 28) != id.device || u32(file.data() + 32) != id.driver ||
        u32(file.data() + 36) != id.flags || std::memcmp(file.data() + 40, id.uuid.data(), 16) ||
        u64(file.data() + 56) != compatibilityHash() ||
        u64(file.data() + 64) != file.size() - HeaderBytes)
        return {};
    const uint8_t* raw = file.data() + HeaderBytes;
    const size_t bytes = file.size() - HeaderBytes;
    if (u64(file.data() + 72) != hash(raw, bytes))
        return {};
    std::vector<uint8_t> payload(raw, raw + bytes);
    if (!payloadStructure(payload, id))
        return {};
    return payload;
}
inline std::filesystem::path defaultPath(const Identity& id) {
    std::wstring local(32768, L'\0');
    const DWORD length =
        GetEnvironmentVariableW(L"LOCALAPPDATA", local.data(), DWORD(local.size()));
    if (!length || length >= local.size())
        return {};
    local.resize(length);
    constexpr wchar_t hex[] = L"0123456789abcdef";
    std::wstring uuid;
    for (auto b : id.uuid) {
        uuid += hex[b >> 4];
        uuid += hex[b & 15];
    }
    return std::filesystem::path(local) / L"REO" / L"parallel-gs" /
           (std::to_wstring(id.vendor) + L"-" + std::to_wstring(id.device) + L"-" + uuid + L"-" +
            std::to_wstring(id.format) + L"-" + std::to_wstring(id.flags) + L".cache");
}
inline std::vector<uint8_t> load(const std::filesystem::path& path, const Identity& id) {
    if (path.empty())
        return {};
    const HANDLE handle = CreateFileW(path.c_str(), GENERIC_READ,
                                      FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                                      nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (handle == INVALID_HANDLE_VALUE)
        return {};
    struct Close {
        HANDLE value;
        ~Close() {
            CloseHandle(value);
        }
    } close{handle};
    LARGE_INTEGER size{};
    if (!GetFileSizeEx(handle, &size) || size.QuadPart < HeaderBytes ||
        size.QuadPart > HeaderBytes + MaxPayload)
        return {};
    std::vector<uint8_t> file(size_t(size.QuadPart));
    DWORD received = 0;
    const bool okay = ReadFile(handle, file.data(), DWORD(file.size()), &received, nullptr) &&
                      received == file.size();
    return okay ? decode(file, id) : std::vector<uint8_t>{};
}
inline bool save(const std::filesystem::path& path, const std::vector<uint8_t>& payload,
                 const Identity& id) {
    if (path.empty())
        return false;
    const auto file = encode(payload, id);
    if (file.empty())
        return false;
    std::error_code ec;
    const auto absolute = std::filesystem::absolute(path, ec);
    if (ec)
        return false;
    std::filesystem::create_directories(absolute.parent_path(), ec);
    if (ec)
        return false;
    static std::atomic<uint64_t> sequence{0};
    auto temp = absolute;
    temp += L".tmp." + std::to_wstring(GetCurrentProcessId()) + L"." +
            std::to_wstring(GetTickCount64()) + L"." +
            std::to_wstring(sequence.fetch_add(1, std::memory_order_relaxed));
    const HANDLE handle = CreateFileW(temp.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_NEW,
                                      FILE_ATTRIBUTE_NORMAL, nullptr);
    if (handle == INVALID_HANDLE_VALUE)
        return false;
    DWORD written = 0;
    bool okay = WriteFile(handle, file.data(), DWORD(file.size()), &written, nullptr) &&
                written == file.size();
    if (okay)
        okay = FlushFileBuffers(handle) != FALSE;
    if (!CloseHandle(handle))
        okay = false;
    // Same-directory rename: reader sees the previous complete file or the new
    // complete file. A write/rename failure leaves the previous file intact.
    if (okay)
        okay = MoveFileExW(temp.c_str(), absolute.c_str(),
                           MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != FALSE;
    if (!okay)
        DeleteFileW(temp.c_str()); // Exact unique file created by CREATE_NEW above.
    return okay;
}
} // namespace reo_parallel_backend::cache_store
