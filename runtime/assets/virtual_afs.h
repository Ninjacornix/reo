#pragma once
#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <vector>

namespace reo::assets {
inline std::filesystem::path readablePath(const std::filesystem::path& path) {
#ifdef _WIN32
    auto value = std::filesystem::absolute(path).wstring();
    std::replace(value.begin(), value.end(), L'/', L'\\');
    if (value.rfind(L"\\\\?\\", 0) == 0) return value;
    if (value.rfind(L"\\\\", 0) == 0) return L"\\\\?\\UNC\\" + value.substr(2);
    return L"\\\\?\\" + value;
#else
    return path;
#endif
}
inline void require(bool ok, const char* message) {
    if (!ok) throw std::runtime_error(message);
}
struct Source {
    std::filesystem::path path;
    uint64_t size;
    mutable std::ifstream stream;
    mutable std::mutex lock;
    bool traceReplacement = false;
    bool transient = false;
    mutable std::atomic<bool> traced{false};
    explicit Source(const std::filesystem::path& p)
        : path(readablePath(p)), size(std::filesystem::file_size(path)), stream(path, std::ios::binary) {
        require(stream.is_open(), "Asset source cannot be opened");
    }
    void read(uint64_t off, size_t n, void* out) const {
        require(off <= size && n <= size - off, "Asset read outside source");
        std::lock_guard guard(lock);
        stream.clear();
        if (!stream.is_open()) stream.open(path, std::ios::binary);
        stream.seekg(static_cast<std::streamoff>(off));
        if (n) stream.read(static_cast<char*>(out), static_cast<std::streamsize>(n));
        require(bool(stream), "Asset source read failed");
        if (transient) stream.close();
        if (traceReplacement && !traced.exchange(true))
            std::fprintf(stderr, "[ASSET-PAKS-1] replacement payload read: offset=%llu bytes=%zu\n", static_cast<unsigned long long>(off), n);
    }
};
struct Segment {
    uint64_t offset = 0, size = 0, sourceOffset = 0;
    std::shared_ptr<Source> source;
    std::shared_ptr<std::vector<uint8_t>> bytes;
};
struct VirtualFile {
    uint64_t size = 0;
    std::vector<Segment> segments;
    void read(uint64_t off, size_t n, void* out) const {
        require(off <= size && n <= size - off, "Virtual asset read outside file");
        if (!n) return;
        auto* dst = static_cast<uint8_t*>(out);
        std::memset(dst, 0, n);
        auto it = std::lower_bound(segments.begin(), segments.end(), off,
            [](const Segment& s, uint64_t value) { return s.offset + s.size <= value; });
        for (; it != segments.end() && it->offset < off + n; ++it) {
            const uint64_t start = std::max(off, it->offset);
            const auto length = static_cast<size_t>(std::min(off + n, it->offset + it->size) - start);
            if (it->source) it->source->read(it->sourceOffset + start - it->offset, length, dst + start - off);
            else std::memcpy(dst + start - off, it->bytes->data() + start - it->offset, length);
        }
    }
};
inline uint32_t u32(const uint8_t* p) {
    return uint32_t(p[0]) | uint32_t(p[1]) << 8 | uint32_t(p[2]) << 16 | uint32_t(p[3]) << 24;
}
inline void put32(uint8_t* p, uint64_t n) {
    require(n < 0x100000000ull, "Virtual AFS exceeds 32-bit limits");
    for (int i = 0; i < 4; ++i) p[i] = uint8_t(n >> (8 * i));
}
struct Entry { uint32_t offset, size; std::string name; };
struct Table { std::vector<Entry> entries; uint32_t namesOffset, namesSize, headerSize; };
inline Table table(const Source& src, uint64_t base, uint64_t size) {
    require(size >= 16 && base <= src.size && size <= src.size - base, "Invalid AFS extent");
    uint8_t head[8]; src.read(base, 8, head);
    require(std::memcmp(head, "AFS\0", 4) == 0, "Replacement path is not an AFS archive");
    const uint32_t count = u32(head + 4);
    require(count && count <= 100000 && 16ull + 8ull * count <= size, "Invalid AFS count");
    std::vector<uint8_t> raw(8ull * count + 8); src.read(base + 8, raw.size(), raw.data());
    Table t{}; t.namesOffset = u32(raw.data() + count * 8); t.namesSize = u32(raw.data() + count * 8 + 4);
    require(uint64_t(t.namesOffset) + t.namesSize <= size && t.namesSize <= 48ull * count + 2048,
            "Invalid AFS names extent");
    std::vector<uint8_t> names(t.namesSize); if (!names.empty()) src.read(base + t.namesOffset, names.size(), names.data());
    t.headerSize = UINT32_MAX;
    for (uint32_t i = 0; i < count; ++i) {
        Entry e{u32(raw.data() + i * 8), u32(raw.data() + i * 8 + 4), {}};
        require(e.offset >= 16ull + 8ull * count && uint64_t(e.offset) + e.size <= size && e.offset % 2048 == 0,
                "Invalid AFS entry extent or alignment");
        if (uint64_t(i + 1) * 48 <= names.size()) {
            const auto* p = reinterpret_cast<const char*>(names.data() + i * 48);
            e.name.assign(p, std::find(p, p + 32, '\0'));
        }
        t.headerSize = std::min(t.headerSize, e.offset); t.entries.push_back(std::move(e));
    }
    require(t.headerSize <= 16 * 1024 * 1024, "AFS header exceeds limit");
    return t;
}
using IndexPath = std::vector<uint32_t>;
using Replacements = std::map<IndexPath, std::shared_ptr<Source>>;
inline VirtualFile original(const std::shared_ptr<Source>& s, uint64_t base, uint64_t size) {
    return {size, {{0, size, base, s, {}}}};
}
inline VirtualFile build(const std::shared_ptr<Source>& src, uint64_t base, uint64_t size,
                         const Replacements& changes, unsigned depth = 0) {
    if (changes.empty()) return original(src, base, size);
    require(depth < 4, "AFS nesting exceeds limit");
    const auto t = table(*src, base, size);
    for (const auto& [path, replacement] : changes)
        require(!path.empty() && path.front() < t.entries.size(), "Replacement index is outside archive");
    auto header = std::make_shared<std::vector<uint8_t>>(t.headerSize);
    src->read(base, header->size(), header->data());
    auto names = std::make_shared<std::vector<uint8_t>>(t.namesSize);
    if (!names->empty()) src->read(base + t.namesOffset, names->size(), names->data());
    VirtualFile output{t.headerSize, {{0, t.headerSize, 0, {}, header}}};
    for (uint32_t i = 0; i < t.entries.size(); ++i) {
        const auto& entry = t.entries[i];
        Replacements nested; std::shared_ptr<Source> replacement;
        for (const auto& [path, value] : changes) if (path.front() == i) {
            if (path.size() == 1) replacement = value;
            else nested.emplace(IndexPath(path.begin() + 1, path.end()), value);
        }
        require(!replacement || nested.empty(), "Conflicting archive replacement");
        VirtualFile child;
        if (replacement) {
            uint8_t magic[4]{};
            if (entry.size >= 4) src->read(base + entry.offset, 4, magic);
            require(std::memcmp(magic, "AFS\0", 4) != 0, "Whole AFS replacement is unsupported");
            auto name = entry.name;
            for (auto& c : name) if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
            require(!(name.size() >= 6 && name.substr(name.size() - 6) == "_h.bin"), "Room name-table replacement is unsupported");
            require(replacement->size <= 256ull * 1024 * 1024, "Replacement exceeds 256 MiB");
            child = original(replacement, 0, replacement->size);
        } else if (!nested.empty()) child = build(src, base + entry.offset, entry.size, nested, depth + 1);
        else child = original(src, base + entry.offset, entry.size);
        const uint64_t start = (output.size + 2047) & ~2047ull;
        put32(header->data() + 8 + i * 8, start); put32(header->data() + 12 + i * 8, child.size);
        if (uint64_t(i + 1) * 48 <= names->size() && u32(names->data() + i * 48 + 44) == entry.size)
            put32(names->data() + i * 48 + 44, child.size);
        for (auto segment : child.segments) { segment.offset += start; output.segments.push_back(std::move(segment)); }
        output.size = start + child.size;
        require(output.size < 0x100000000ull, "Virtual AFS exceeds 4 GiB");
    }
    if (!names->empty()) {
        const uint64_t start = (output.size + 2047) & ~2047ull;
        put32(header->data() + 8 + t.entries.size() * 8, start);
        output.segments.push_back({start, names->size(), 0, {}, names}); output.size = start + names->size();
    }
    require(output.size < 0x100000000ull, "Virtual AFS exceeds 4 GiB");
    return output;
}
} // namespace reo::assets
