#include "cdvd.h"
#include "runtime/assets/overlay.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif
#include <fstream>
#include <algorithm>

namespace reo {

namespace fs = std::filesystem;

CDVD::CDVD(const fs::path& game_data_root) : m_root(game_data_root) {
    build_file_map();
    assets::active.reset();
#ifdef _WIN32
    const wchar_t* plan = _wgetenv(L"REO_ASSET_OVERLAY");
#else
    const char* plan = std::getenv("REO_ASSET_OVERLAY");
#endif
    if (plan && *plan) {
        const char* host = std::getenv("REO_COOP_HOST");
        assets::require(!host || !*host, "Asset packs require offline play");
        assets::active = std::make_unique<assets::Overlay>(m_root, fs::path(plan));
    }
    open_image();
}

CDVD::~CDVD() {
    if (!m_image)
        return;
#ifdef _WIN32
    if (m_imageIsVolume) {
        CloseHandle(static_cast<HANDLE>(m_image));
        return;
    }
#endif
    fclose(static_cast<FILE*>(m_image));
}

void CDVD::open_image() {
    const char* gamePak = std::getenv("REO_GAME_PAK");
    if (gamePak && strcmp(gamePak, "1") == 0) {
        std::vector<std::pair<std::string, fs::path>> files(m_file_map.begin(), m_file_map.end());
        std::sort(files.begin(), files.end());
        uint64_t lba = 0x01000000;
        for (const auto& [name, path] : files) {
            const uint64_t bytes = fs::file_size(path);
            assets::require(bytes < 0x100000000ull && lba + (bytes + 2047) / 2048 + 0x4000 < 0x10000000,
                            "Game PAK file map exceeds bounds");
            m_pakFiles.push_back({static_cast<uint32_t>(lba), bytes, path});
            // libcdvd prefetches past EOF (0FLIST.DIR is read as two sectors).
            // Give each file a bounded zero-filled read-ahead area so that such
            // reads cannot accidentally consume bytes from another mapped file.
            lba += (bytes + 2047) / 2048 + 0x4000;
        }
        m_gamePak = true;
        printf("[GAME-PAK-1] %zu files; ISO-independent sector reads\n", m_pakFiles.size());
        return;
    }
    // Read directly from the user's image; no mounted drive is required.
#ifdef _WIN32
    const wchar_t* iso = _wgetenv(L"REO_ISO");
    FILE* f = iso && *iso ? _wfopen(iso, L"rb") : nullptr;
    std::string label;
    if (iso && *iso) {
        const auto utf8 = fs::path(iso).u8string();
        label.assign(reinterpret_cast<const char*>(utf8.data()), utf8.size());
    }
#else
    const char* iso = std::getenv("REO_ISO");
    FILE* f = iso && *iso ? fopen(iso, "rb") : nullptr;
    std::string label = iso ? iso : "";
#endif
    if (!label.empty()) {
        if (f) {
            _fseeki64(f, 0, SEEK_END);
            m_imageSize = static_cast<uint64_t>(_ftelli64(f));
            m_image = f;
            printf("[CDVD] Disc image: %s (%llu bytes)\n", label.c_str(),
                   (unsigned long long)m_imageSize);
            return;
        }
        fprintf(stderr, "[CDVD] REO_ISO not readable: %s\n", label.c_str());
    }
#ifdef _WIN32
    // Fallback: the data root is a mounted disc ("F:\\"): read its raw volume.
    const std::string r = m_root.string();
    if (r.size() >= 2 && r[1] == ':' && (r.size() == 2 || r.size() == 3)) {
        const std::string dev = std::string("\\\\.\\") + r.substr(0, 2);
        HANDLE hv = CreateFileA(dev.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
                                nullptr, OPEN_EXISTING, 0, nullptr);
        if (hv != INVALID_HANDLE_VALUE) {
            m_image = hv;
            m_imageIsVolume = true;
            m_imageSize = ~0ull;
            printf("[CDVD] Disc image: raw volume %s\n", dev.c_str());
            return;
        }
    }
#endif
    printf("[CDVD] No disc image (set REO_ISO): raw sector reads unavailable\n");
}

void CDVD::build_file_map() {
    if (!fs::exists(m_root)) {
        fprintf(stderr, "[CDVD] Game data root does not exist: %s\n", m_root.string().c_str());
        return;
    }

    int count = 0;
    for (auto& entry : fs::recursive_directory_iterator(m_root)) {
        if (entry.is_regular_file()) {
            // Build a PS2-style path relative to root
            auto rel = fs::relative(entry.path(), m_root);
            std::string ps2_path = rel.string();

            // Normalize: backslashes, uppercase
            std::replace(ps2_path.begin(), ps2_path.end(), '/', '\\');
            std::transform(ps2_path.begin(), ps2_path.end(), ps2_path.begin(), ::toupper);

            m_file_map[ps2_path] = entry.path();
            count++;
        }
    }

    printf("[CDVD] Mapped %d files from %s\n", count, m_root.string().c_str());
}

std::string CDVD::normalize_ps2_path(const std::string& path) const {
    std::string normalized = path;

    // Strip cdrom prefix
    const char* prefixes[] = {"cdrom0:\\", "cdrom0:", "cdrom:\\", "cdrom:", "host:"};
    for (auto prefix : prefixes) {
        size_t plen = strlen(prefix);
        if (normalized.size() >= plen && _strnicmp(normalized.c_str(), prefix, plen) == 0) {
            normalized = normalized.substr(plen);
            break;
        }
    }

    // Strip version suffix (;1)
    auto semi = normalized.find(';');
    if (semi != std::string::npos) {
        normalized = normalized.substr(0, semi);
    }

    // Normalize separators and case
    std::replace(normalized.begin(), normalized.end(), '/', '\\');
    std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::toupper);

    return normalized;
}

fs::path CDVD::resolve_path(const std::string& ps2_path) const {
    std::string key = normalize_ps2_path(ps2_path);
    while (!key.empty() && key.front() == '\\') key.erase(key.begin());
    auto it = m_file_map.find(key);
    if (it != m_file_map.end()) {
        return it->second;
    }
    return {};
}

bool CDVD::read_file(const std::string& ps2_path, std::vector<uint8_t>& out) {
    if (const auto* archive = assets::active ? assets::active->find(ps2_path) : nullptr) {
        out.resize(static_cast<size_t>(archive->file.size));
        archive->file.read(0, out.size(), out.data()); return true;
    }
    fs::path local = resolve_path(ps2_path);
    if (local.empty()) {
        fprintf(stderr, "[CDVD] File not found: %s\n", ps2_path.c_str());
        return false;
    }

    std::ifstream file(local, std::ios::binary | std::ios::ate);
    if (!file) {
        fprintf(stderr, "[CDVD] Failed to open: %s\n", local.string().c_str());
        return false;
    }

    auto size = file.tellg();
    file.seekg(0);
    out.resize((size_t)size);
    file.read((char*)out.data(), size);

    return true;
}

bool CDVD::read_sectors(uint32_t lba, uint32_t count, void* buffer) {
    if (assets::active && assets::active->sector(lba, count, buffer)) return true;
    if (m_gamePak) {
        if (!buffer || count == 0 || count > 0x4000) return false;
        for (const auto& file : m_pakFiles) {
            const uint64_t offset = uint64_t(lba - file.lba) * 2048;
            const uint64_t rounded = ((file.bytes + 2047) & ~uint64_t(2047)) + 0x4000ull * 2048;
            const uint64_t size = uint64_t(count) * 2048;
            if (lba < file.lba || offset >= rounded || size > rounded - offset) continue;
            std::ifstream input(file.path, std::ios::binary);
            if (!input) return false;
            memset(buffer, 0, static_cast<size_t>(size));
            if (offset >= file.bytes) return true;
            const auto bytes = static_cast<size_t>(std::min(size, file.bytes - offset));
            input.seekg(static_cast<std::streamoff>(offset));
            input.read(static_cast<char*>(buffer), bytes);
            return input.gcount() == static_cast<std::streamsize>(bytes);
        }
        return false;
    }
    if (!m_image || !buffer || count == 0)
        return false;
    const uint64_t off = static_cast<uint64_t>(lba) * 2048u;
    const uint64_t len = static_cast<uint64_t>(count) * 2048u;
    if (len > 0x2000000u || (m_imageSize != ~0ull && off + len > m_imageSize))
        return false;
#ifdef _WIN32
    if (m_imageIsVolume) {
        LARGE_INTEGER li;
        li.QuadPart = static_cast<LONGLONG>(off);
        if (!SetFilePointerEx(static_cast<HANDLE>(m_image), li, nullptr, FILE_BEGIN))
            return false;
        DWORD got = 0;
        return ReadFile(static_cast<HANDLE>(m_image), buffer, static_cast<DWORD>(len), &got,
                        nullptr) &&
               got == len;
    }
#endif
    FILE* f = static_cast<FILE*>(m_image);
    if (_fseeki64(f, static_cast<long long>(off), SEEK_SET) != 0)
        return false;
    return fread(buffer, 1, static_cast<size_t>(len), f) == len;
}

bool CDVD::search_file(const std::string& ps2_path, uint32_t& lba, uint32_t& size) {
    if (const auto* archive = assets::active ? assets::active->find(ps2_path) : nullptr) {
        lba = archive->lba; size = static_cast<uint32_t>(archive->file.size); return true;
    }
    if (m_gamePak) {
        const auto path = resolve_path(ps2_path);
        for (const auto& file : m_pakFiles) if (file.path == path) {
            lba = file.lba; size = static_cast<uint32_t>(file.bytes); return true;
        }
        return false;
    }
    // Path components, upper-case, without "cdrom0:" and ";version".
    std::string p = ps2_path;
    const size_t colon = p.find(':');
    if (colon != std::string::npos)
        p = p.substr(colon + 1);
    std::vector<std::string> parts;
    std::string cur;
    for (char ch : p) {
        if (ch == '\\' || ch == '/') {
            if (!cur.empty())
                parts.push_back(cur);
            cur.clear();
        } else
            cur.push_back(static_cast<char>(toupper(static_cast<unsigned char>(ch))));
    }
    if (!cur.empty())
        parts.push_back(cur);
    if (parts.empty())
        return false;
    const size_t semi = parts.back().find(';');
    if (semi != std::string::npos)
        parts.back().resize(semi);

    std::vector<uint8_t> sec(2048);
    if (!read_sectors(16, 1, sec.data()) || sec[0] != 1 || memcmp(&sec[1], "CD001", 5) != 0)
        return false;
    uint32_t dirLba = 0, dirSize = 0;
    memcpy(&dirLba, &sec[156 + 2], 4);
    memcpy(&dirSize, &sec[156 + 10], 4);

    for (size_t i = 0; i < parts.size(); ++i) {
        const bool last = (i + 1 == parts.size());
        bool found = false;
        const uint32_t nsec = (dirSize + 2047u) / 2048u;
        std::vector<uint8_t> dir(static_cast<size_t>(nsec) * 2048u);
        if (nsec == 0 || nsec > 4096 || !read_sectors(dirLba, nsec, dir.data()))
            return false;
        for (uint32_t s0 = 0; s0 < nsec && !found; ++s0) {
            uint32_t o = s0 * 2048u;
            const uint32_t end = o + 2048u;
            while (o + 33 < end) {
                const uint8_t rl = dir[o];
                if (rl == 0)
                    break; // rest of this sector unused
                const uint8_t nl = dir[o + 32];
                if (o + 33u + nl > end)
                    break;
                std::string name(reinterpret_cast<const char*>(&dir[o + 33]), nl);
                const size_t sv = name.find(';');
                if (sv != std::string::npos)
                    name.resize(sv);
                for (auto& ch : name)
                    ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
                const bool isDir = (dir[o + 25] & 2u) != 0;
                if (name == parts[i] && isDir != last) {
                    memcpy(&dirLba, &dir[o + 2], 4);
                    memcpy(&dirSize, &dir[o + 10], 4);
                    found = true;
                    break;
                }
                o += rl;
            }
        }
        if (!found)
            return false;
    }
    lba = dirLba;
    size = dirSize;
    return true;
}

bool CDVD::file_exists(const std::string& ps2_path) const {
    return !resolve_path(ps2_path).empty();
}

uint32_t CDVD::file_size(const std::string& ps2_path) const {
    if (const auto* archive = assets::active ? assets::active->find(ps2_path) : nullptr)
        return static_cast<uint32_t>(archive->file.size);
    fs::path local = resolve_path(ps2_path);
    if (local.empty())
        return 0;
    return (uint32_t)fs::file_size(local);
}

} // namespace reo
