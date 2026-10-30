#pragma once
#include "virtual_afs.h"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include <cstdlib>
#include <functional>
#include <string>

namespace reo::assets {
using Digest = reo_native_image_identity::Digest;
inline Digest digest(const Source& source, uint64_t offset, uint64_t size) {
    require(size <= 256ull * 1024 * 1024, "Asset hash input exceeds 256 MiB");
    std::vector<uint8_t> bytes(static_cast<size_t>(size));
    source.read(offset, bytes.size(), bytes.data());
    return reo_native_image_identity::sha256(bytes.data(), static_cast<uint32_t>(bytes.size()));
}
inline std::string pathKey(std::string name) {
    std::replace(name.begin(), name.end(), '\\', '/');
    const auto colon = name.find(':'); if (colon != std::string::npos) name.erase(0, colon + 1);
    while (!name.empty() && name.front() == '/') name.erase(name.begin());
    const auto semi = name.find(';'); if (semi != std::string::npos) name.resize(semi);
    for (auto& c : name) if (c >= 'a' && c <= 'z') c -= 'a' - 'A';
    return name;
}
class PlanReader {
    std::vector<uint8_t> bytes; size_t at = 0;
  public:
    explicit PlanReader(const std::filesystem::path& path) {
        Source source(path); require(source.size <= 16 * 1024 * 1024, "Asset plan exceeds limit");
        bytes.resize(static_cast<size_t>(source.size)); source.read(0, bytes.size(), bytes.data());
    }
    void read(void* out, size_t n) {
        require(n <= bytes.size() - at, "Truncated asset plan"); std::memcpy(out, bytes.data() + at, n); at += n;
    }
    uint32_t number() { uint8_t b[4]; read(b, 4); return u32(b); }
    uint64_t size() { const uint64_t lo = number(); return lo | uint64_t(number()) << 32; }
    Digest hash() { Digest value; read(value.data(), value.size()); return value; }
    std::string text(uint32_t max) {
        const auto n = number(); require(n && n <= max, "Asset plan string exceeds limit");
        std::string value(n, '\0'); read(value.data(), n);
        require(value.find('\0') == std::string::npos, "NUL in asset plan string"); return value;
    }
    bool done() const { return at == bytes.size(); }
};
struct MountedArchive { VirtualFile file; uint32_t lba; };
class Overlay {
    std::map<std::string, MountedArchive> archives;
  public:
    explicit Overlay(const std::filesystem::path& root, const std::filesystem::path& plan) {
        PlanReader reader(plan); char magic[8]; reader.read(magic, 8);
        require(std::memcmp(magic, "REOPAK1\0", 8) == 0, "Unsupported asset overlay plan");
        const auto game = reader.number(); require(game == 1 || game == 2, "Invalid asset game");
        const auto elfHash = reader.hash();
        const char* expected = game == 1 ? "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46"
            : "5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d";
        for (size_t i = 0; i < elfHash.size(); ++i) {
            const std::string pair(expected + i * 2, 2);
            require(elfHash[i] == std::stoul(pair, nullptr, 16), "Asset plan targets unsupported executable");
        }
        Source elf(root / (game == 1 ? "SLUS_207.65" : "SLUS_209.84"));
        require(digest(elf, 0, elf.size) == elfHash, "Asset plan executable identity mismatch");
        const uint32_t count = reader.number(); require(count <= 4096, "Too many asset replacements");
        std::map<std::string, Replacements> changes;
        std::map<std::string, std::shared_ptr<Source>> sources;
        std::map<std::string, bool> seen;
        for (uint32_t i = 0; i < count; ++i) {
            const auto target = reader.text(256), file = reader.text(32768);
            const auto length = reader.size(); const auto baseHash = reader.hash(), newHash = reader.hash();
            require(seen.emplace(target, true).second, "Duplicate asset replacement");
            const auto slash = target.find('/'); require(slash != std::string::npos, "Asset path has no indices");
            const auto name = target.substr(0, slash);
            require(name == "NETBIO00.DAT" || name == "NETBIO01.DAT" || (game == 1 && name == "NETBIO02.DAT"),
                    "Unsupported asset archive");
            auto& source = sources[name]; if (!source) source = std::make_shared<Source>(root / name);
            IndexPath path; uint64_t base = 0, extent = source->size; size_t start = slash + 1;
            while (start < target.size()) {
                const auto end = target.find('/', start); const auto token = target.substr(start, end - start);
                require(!token.empty() && token.size() <= 6 && token.find_first_not_of("0123456789") == std::string::npos,
                        "Asset paths must contain numeric entry indices");
                const auto index = static_cast<uint32_t>(std::stoul(token));
                require(token == std::to_string(index), "Asset index must use canonical decimal notation");
                require(path.size() < 4, "Asset path nesting exceeds limit");
                const auto t = table(*source, base, extent);
                require(index < t.entries.size(), "Asset index outside archive");
                const auto& entry = t.entries[index];
                if (end == std::string::npos) {
                    auto label = pathKey(entry.name);
                    require(!(label.size() >= 6 && label.substr(label.size() - 6) == "_H.BIN"), "Cannot replace room name tables");
                }
                base += entry.offset; extent = entry.size; path.push_back(index);
                if (end == std::string::npos) break;
                start = end + 1; require(start < target.size(), "Empty asset path component");
            }
            require(!path.empty(), "Asset replacement path is empty");
            uint8_t leafMagic[4]{}; if (extent >= 4) source->read(base, 4, leafMagic);
            require(std::memcmp(leafMagic, "AFS\0", 4) != 0, "Cannot replace whole nested archives");
            require(digest(*source, base, extent) == baseHash, "Original asset hash mismatch");
            const auto replacementPath = std::filesystem::u8path(file);
            require(replacementPath.is_absolute(), "Replacement file path must be absolute");
            auto replacement = std::make_shared<Source>(replacementPath);
            require(replacement->size == length && digest(*replacement, 0, length) == newHash, "Replacement asset hash mismatch");
            replacement->traceReplacement = true;
            // Thousands of installed assets must not consume thousands of open CRT
            // streams. Original archives stay open; replacements open on demand.
            replacement->transient = true;
            replacement->stream.close();
            if (length != extent || newHash != baseHash) changes[name].emplace(path, std::move(replacement));
        }
        require(reader.done(), "Unexpected trailing data in asset plan");
        // Reserved above any supported DVD image and below PS2Recomp's pseudo-file range.
        uint32_t nextLba = 0x20000000u;
        for (const auto& [name, replacement] : changes) {
            auto file = build(sources.at(name), 0, sources.at(name)->size, replacement);
            archives.emplace(name, MountedArchive{std::move(file), nextLba});
            nextLba += static_cast<uint32_t>((archives.at(name).file.size + 2047) / 2048 + 1);
        }
        std::fprintf(stderr, "[ASSET-PAKS-1] %u validated replacements, %zu virtual archives\n", count, archives.size());
    }
    const MountedArchive* find(const std::string& key) const {
        const auto found = archives.find(pathKey(key)); return found == archives.end() ? nullptr : &found->second;
    }
    bool containsLba(uint32_t lba) const {
        for (const auto& [name, archive] : archives)
            if (lba >= archive.lba && uint64_t(lba) < uint64_t(archive.lba) + (archive.file.size + 2047) / 2048) return true;
        return false;
    }
    bool sector(uint32_t lba, uint32_t count, void* out, size_t capacity = SIZE_MAX) const {
        if (!containsLba(lba)) return false;
        require(count && count <= 16384 && out, "Invalid virtual sector read");
        for (const auto& [name, archive] : archives) {
            const auto sectors = (archive.file.size + 2047) / 2048;
            if (lba < archive.lba || uint64_t(lba) >= uint64_t(archive.lba) + sectors) continue;
            const uint64_t off = uint64_t(lba - archive.lba) * 2048, n = uint64_t(count) * 2048;
            require(n <= capacity, "Virtual sector read exceeds destination capacity");
            require(n <= (sectors * 2048) - off, "Virtual sector read crosses archive boundary");
            std::memset(out, 0, static_cast<size_t>(n));
            archive.file.read(off, static_cast<size_t>(std::min(n, archive.file.size - off)), out); return true;
        }
        return false;
    }
};
inline std::unique_ptr<Overlay> active;
inline bool hostSize(const std::filesystem::path& path, uint64_t& size) {
    const auto* archive = active ? active->find(path.filename().string()) : nullptr;
    if (!archive) return false;
    size = archive->file.size; return true;
}
inline bool hostRead(const std::filesystem::path& path, uint64_t off, void* dst, size_t n) {
    const auto* archive = active ? active->find(path.filename().string()) : nullptr;
    if (!archive) return false;
    std::memset(dst, 0, n);
    if (off < archive->file.size) archive->file.read(off, static_cast<size_t>(std::min<uint64_t>(n, archive->file.size - off)), dst);
    return true;
}
} // namespace reo::assets
