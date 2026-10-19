#pragma once
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <functional>
#include <map>
#include <mutex>
#include <stdexcept>
#include <string>
#include <vector>

namespace reo::memory_card {
// Folder-backed PS2 MCSERV wire protocol; no host pointers cross the RPC boundary.
class Service {
  public:
    using Path = std::filesystem::path;
    using Read = std::function<bool(uint32_t, void*, size_t)>;
    using Write = std::function<bool(uint32_t, const void*, size_t)>;
    using Entry = std::array<uint8_t, 64>;
    explicit Service(std::array<Path, 2> roots) : roots_(std::move(roots)) {
        for (auto& root : roots_)
            if (!root.empty()) {
                std::filesystem::create_directories(root);
                root = std::filesystem::weakly_canonical(root);
            }
    }
    int call(uint32_t command, const std::vector<uint8_t>& request, const Read& read,
             const Write& write) {
        std::lock_guard lock(mutex_);
        try {
            return invoke(command, request, read, write);
        } catch (const std::exception&) {
            return -5;
        }
    }
    int rename(int port, const std::string& from, const std::string& to) {
        std::lock_guard lock(mutex_);
        try {
            if (int state = present(port, 0); state < 0)
                return state;
            Path source = path(port, from);
            if (to.empty() || to.find_first_of("/\\") != std::string::npos)
                return -5;
            Path target = path(
                port,
                "/" +
                    (source.parent_path().lexically_relative(roots_[port]) / to).generic_string());
            if (source == roots_[port] || !std::filesystem::exists(source))
                return -4;
            if (std::filesystem::exists(target))
                return -5;
            for (const auto& [fd, h] : handles_)
                if (h.path == source)
                    return -5;
            auto oldMeta = metadata(port, source), newMeta = metadata(port, target);
            std::filesystem::rename(source, target);
            if (std::filesystem::exists(oldMeta.parent_path())) {
                std::filesystem::create_directories(newMeta.parent_path().parent_path());
                std::filesystem::rename(oldMeta.parent_path(), newMeta.parent_path());
            }
            return 0;
        } catch (const std::exception&) {
            return -5;
        }
    }
    int entrySpace(int port, const std::string& value) {
        std::lock_guard lock(mutex_);
        try {
            if (int state = present(port, 0); state < 0)
                return state;
            Path directory = path(port, value);
            if (!std::filesystem::is_directory(directory))
                return -4;
            int entries = 0;
            for (const auto& item : std::filesystem::directory_iterator(directory))
                if (!hidden(item.path()))
                    ++entries;
            return static_cast<int>(std::min<uint64_t>(
                std::max(0, 512 - entries), (Capacity - std::min(Capacity, used(port))) / 1024));
        } catch (const std::exception&) {
            return -5;
        }
    }

  private:
    struct Handle {
        std::fstream file;
        Path path;
        int port;
        bool readable, writable, append;
        int64_t offset = 0;
    };
    std::array<Path, 2> roots_;
    std::array<std::string, 2> cwd_{"/", "/"};
    std::array<bool, 2> seen_{};
    std::array<std::vector<Entry>, 2> directory_;
    std::array<size_t, 2> cursor_{};
    std::map<int, Handle> handles_;
    std::mutex mutex_;
    static constexpr uint64_t Capacity = 8 * 1024 * 1024;
    static uint32_t word(const std::vector<uint8_t>& v, size_t offset) {
        if (offset + 4 > v.size())
            throw std::runtime_error("short packet");
        uint32_t x;
        std::memcpy(&x, v.data() + offset, 4);
        return x;
    }
    static int number(const std::vector<uint8_t>& v, size_t offset) {
        return static_cast<int32_t>(word(v, offset));
    }
    static void put(void* p, uint32_t x) {
        std::memcpy(p, &x, 4);
    }
    static bool hidden(const Path& p) {
        return p.filename().string().rfind(".reo-", 0) == 0;
    }
    static bool wildcard(const std::string& pattern, const std::string& value) {
        size_t p = 0, v = 0, star = std::string::npos, mark = 0;
        while (v < value.size()) {
            if (p < pattern.size() && (pattern[p] == '?' || pattern[p] == value[v])) {
                ++p;
                ++v;
            } else if (p < pattern.size() && pattern[p] == '*') {
                star = p++;
                mark = v;
            } else if (star != std::string::npos) {
                p = star + 1;
                v = ++mark;
            } else
                return false;
        }
        while (p < pattern.size() && pattern[p] == '*')
            ++p;
        return p == pattern.size();
    }
    static std::string name(const std::vector<uint8_t>& q) {
        if (q.size() <= 20)
            throw std::runtime_error("missing name");
        auto end = std::find(q.begin() + 20, q.end(), 0);
        if (end == q.end() || end - (q.begin() + 20) > 1023)
            throw std::runtime_error("unterminated name");
        return std::string(q.begin() + 20, end);
    }
    Path path(int port, std::string value) const {
        std::replace(value.begin(), value.end(), '\\', '/');
        if (value.find(':') != std::string::npos)
            throw std::runtime_error("device in path");
        Path relative = value.empty() || value[0] != '/' ? Path(cwd_[port].substr(1)) / value
                                                         : Path(value.substr(1));
        relative = relative.lexically_normal();
        for (const auto& component : relative) {
            auto text = component.string();
            if (text == ".." || hidden(component) ||
                text.find_first_of("<>\"|\x01\x02\x03") != std::string::npos ||
                (!text.empty() && (text.back() == ' ' || text.back() == '.') && text != "."))
                throw std::runtime_error("invalid path");
        }
        Path result = std::filesystem::weakly_canonical(roots_[port] / relative);
        auto a = roots_[port].begin(), b = result.begin();
        for (; a != roots_[port].end(); ++a, ++b)
            if (b == result.end() || *a != *b)
                throw std::runtime_error("card escape");
        return result;
    }
    uint64_t used(int port) const {
        uint64_t total = 2048;
        for (auto it = std::filesystem::recursive_directory_iterator(roots_[port]);
             it != std::filesystem::recursive_directory_iterator(); ++it) {
            if (hidden(it->path()) || it->is_symlink()) {
                if (it->is_directory())
                    it.disable_recursion_pending();
                continue;
            }
            total += it->is_regular_file()
                         ? std::max<uint64_t>(1024, ((it->file_size() + 1023) / 1024) * 1024)
                         : 1024;
            if (total > Capacity)
                return total;
        }
        return total;
    }
    int present(int port, int slot) const {
        if (port < 0 || port > 1 || slot != 0 || roots_[port].empty())
            return -1;
        return std::filesystem::exists(roots_[port] / ".reo-unformatted") ? -2 : 0;
    }
    Path metadata(int port, const Path& p) const {
        Path result = roots_[port] / ".reo-meta";
        for (auto& component : p.lexically_relative(roots_[port])) {
            std::string encoded;
            for (unsigned char c : component.string()) {
                static const char hex[] = "0123456789abcdef";
                encoded += hex[c >> 4];
                encoded += hex[c & 15];
            }
            result /= encoded;
        }
        // Internal metadata is never followed through a user-provided symlink.
        for (Path current = result; current != roots_[port] && !current.empty();
             current = current.parent_path())
            if (std::filesystem::is_symlink(current))
                throw std::runtime_error("metadata symlink");
        if (std::filesystem::is_symlink(result / "entry"))
            throw std::runtime_error("metadata symlink");
        return result / "entry";
    }
    Entry entry(int port, const Path& p, const std::string& label) const {
        Entry e{};
        bool dir = std::filesystem::is_directory(p);
        std::ifstream stored(metadata(port, p), std::ios::binary);
        if (stored)
            stored.read(reinterpret_cast<char*>(e.data()), e.size());
        if (!stored) {
            auto timestamp = std::chrono::clock_cast<std::chrono::system_clock>(
                std::filesystem::last_write_time(p));
            auto now = std::chrono::system_clock::to_time_t(timestamp);
            std::tm tm{};
#ifdef _WIN32
            localtime_s(&tm, &now);
#else
            localtime_r(&now, &tm);
#endif
            for (int base : {0, 8}) {
                e[base + 1] = tm.tm_sec;
                e[base + 2] = tm.tm_min;
                e[base + 3] = tm.tm_hour;
                e[base + 4] = tm.tm_mday;
                e[base + 5] = tm.tm_mon + 1;
                uint16_t year = tm.tm_year + 1900;
                std::memcpy(e.data() + base + 6, &year, 2);
            }
            uint16_t attrs = dir ? 0x8427 : 0x8497;
            std::memcpy(e.data() + 20, &attrs, 2);
        }
        put(e.data() + 16, dir ? 0 : static_cast<uint32_t>(std::filesystem::file_size(p)));
        std::fill(e.begin() + 32, e.end(), 0);
        std::memcpy(e.data() + 32, label.data(), std::min<size_t>(31, label.size()));
        return e;
    }
    int invoke(uint32_t cmd, const std::vector<uint8_t>& q, const Read& read, const Write& write) {
        static const std::map<uint32_t, uint32_t> old{
            {0x70, 0xfe}, {0x71, 2}, {0x72, 3},  {0x73, 5},  {0x74, 6},  {0x75, 4},  {0x76, 13},
            {0x77, 16},   {0x78, 1}, {0x79, 15}, {0x7a, 10}, {0x7b, 12}, {0x7c, 14}, {0x80, 17}};
        bool legacy = cmd >= 0x70 && cmd <= 0x80;
        if (auto i = old.find(cmd); i != old.end())
            cmd = i->second;
        if (cmd == 0xfe)
            return 0;
        if (cmd == 0x14)
            return 0;
        if (cmd == 3 || cmd == 4 || cmd == 5 || cmd == 6 || cmd == 10) {
            auto it = handles_.find(number(q, 0));
            if (it == handles_.end())
                return -5;
            Handle& h = it->second;
            if (cmd == 3) {
                h.file.flush();
                bool ok = !h.file.fail();
                handles_.erase(it);
                return ok ? 0 : -5;
            }
            if (cmd == 10) {
                h.file.flush();
                return h.file ? 0 : -5;
            }
            if (cmd == 4) {
                int origin = number(q, 20);
                if (origin < 0 || origin > 2)
                    return -5;
                int64_t next =
                    number(q, 16) +
                    (origin == 0   ? 0
                     : origin == 1 ? h.offset
                                   : static_cast<int64_t>(std::filesystem::file_size(h.path)));
                if (next < 0 || next > static_cast<int64_t>(Capacity))
                    return -5;
                h.offset = next;
                return static_cast<int>(next);
            }
            int n = number(q, 12);
            if (n < 0 || n > static_cast<int>(Capacity))
                return -5;
            uint32_t buffer = word(q, 24);
            std::vector<uint8_t> bytes(n);
            h.file.clear();
            if (cmd == 5) {
                if (!h.readable)
                    return -5;
                uint32_t extra = word(q, 28);
                std::array<uint8_t, 192> zeros{};
                if (extra && !write(extra, zeros.data(), legacy ? 64 : 192))
                    return -5;
                h.file.seekg(h.offset);
                h.file.read(reinterpret_cast<char*>(bytes.data()), n);
                int got = static_cast<int>(h.file.gcount());
                if (got && !write(buffer, bytes.data(), got))
                    return -5;
                h.offset += got;
                h.file.clear();
                return got;
            }
            if (!h.writable)
                return -5;
            int prefix = number(q, 20);
            if (prefix < 0 || prefix > 16 || q.size() < 32 + prefix)
                return -5;
            if (n && !read(buffer, bytes.data(), n))
                return -5;
            uint64_t length = std::filesystem::file_size(h.path);
            if (h.append)
                h.offset = length;
            uint64_t end = static_cast<uint64_t>(h.offset) + prefix + n;
            uint64_t oldBlocks = std::max<uint64_t>(1024, ((length + 1023) / 1024) * 1024);
            uint64_t newBlocks =
                std::max<uint64_t>(1024, ((std::max(end, length) + 1023) / 1024) * 1024);
            if (end > Capacity || used(h.port) + newBlocks - oldBlocks > Capacity)
                return -3;
            h.file.seekp(h.offset);
            h.file.write(reinterpret_cast<const char*>(q.data() + 32), prefix);
            h.file.write(reinterpret_cast<const char*>(bytes.data()), n);
            h.file.flush();
            if (!h.file)
                return -5;
            h.offset += prefix + n;
            return prefix + n;
        }
        bool named = cmd == 2 || cmd == 12 || cmd == 13 || cmd == 14 || cmd == 15 || cmd == 18;
        int port = number(q, named ? 0 : 4), slot = number(q, named ? 4 : 8);
        int state = present(port, slot);
        if (cmd == 1) {
            std::array<uint8_t, 192> info{};
            bool inserted = port >= 0 && port < 2 && slot == 0 && !roots_[port].empty();
            put(info.data(), inserted ? 2 : 0);
            put(info.data() + 4,
                state == 0
                    ? static_cast<uint32_t>((Capacity - std::min(Capacity, used(port))) / 1024)
                    : 0);
            put(info.data() + 144, state == 0 ? 1 : 0);
            if (!write(word(q, 28), info.data(), legacy ? 64 : 192))
                return -5;
            if (state < 0)
                return state;
            bool seen = seen_[port];
            seen_[port] = true;
            return seen ? 0 : -1;
        }
        if (state == -1)
            return -1;
        if (cmd == 16 || cmd == 17) {
            for (const auto& [fd, h] : handles_)
                if (h.port == port)
                    return -5;
            // Preserve the previous card on explicit in-game format/unformat.
            auto suffix =
                std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
            Path backup = roots_[port];
            backup += ".before-format-" + suffix;
            std::filesystem::rename(roots_[port], backup);
            std::filesystem::create_directories(roots_[port]);
            if (cmd == 17) {
                std::ofstream marker(roots_[port] / ".reo-unformatted");
                if (!marker)
                    return -5;
            }
            cwd_[port] = "/";
            seen_[port] = false;
            directory_[port].clear();
            return 0;
        }
        if (state < 0)
            return state;
        if (cmd == 0x33)
            return 0;
        if (!named)
            return -5;
        Path p = path(port, name(q));
        if (cmd == 2) {
            int flags = number(q, 8);
            if (flags & 0x40) {
                if (std::filesystem::exists(p))
                    return -4;
                if (used(port) + 1024 > Capacity)
                    return -3;
                return std::filesystem::create_directory(p) ? 0 : -5;
            }
            if (handles_.size() >= 32)
                return -7;
            bool readable = flags & 1, writable = flags & 2;
            if (!readable && !writable)
                return -5;
            if (!std::filesystem::exists(p)) {
                if (!(flags & 0x200))
                    return -4;
                if (used(port) + 1024 > Capacity)
                    return -3;
                std::ofstream create(p, std::ios::binary);
                if (!create)
                    return -5;
            }
            if (!std::filesystem::is_regular_file(p))
                return -5;
            if ((flags & 0x400) && writable) {
                std::ofstream truncate(p, std::ios::binary | std::ios::trunc);
                if (!truncate)
                    return -5;
            }
            for (int fd = 0; fd < 32; ++fd)
                if (!handles_.count(fd)) {
                    Handle h{
                        std::fstream(p, std::ios::binary | std::ios::in |
                                            (writable ? std::ios::out : std::ios::openmode(0))),
                        p,
                        port,
                        readable,
                        writable,
                        (flags & 0x1000) != 0};
                    if (!h.file)
                        return -5;
                    handles_.emplace(fd, std::move(h));
                    return fd;
                }
            return -7;
        }
        if (cmd == 12) {
            if (!std::filesystem::is_directory(p))
                return -4;
            std::string next = "/" + p.lexically_relative(roots_[port]).generic_string();
            if (next == "/.")
                next = "/";
            std::array<char, 1024> dir{};
            std::memcpy(dir.data(), next.data(), std::min<size_t>(next.size(), 1023));
            if (word(q, 16) && !write(word(q, 16), dir.data(), dir.size()))
                return -5;
            cwd_[port] = next;
            return 0;
        }
        if (cmd == 13) {
            int count = number(q, 12);
            if (count < 0 || count > 1024)
                return -5;
            if (number(q, 8) == 0) {
                directory_[port].clear();
                cursor_[port] = 0;
                std::string pattern = p.filename().string();
                Path parent = p.parent_path();
                if (pattern.find_first_of("*?") == std::string::npos) {
                    if (std::filesystem::exists(p))
                        directory_[port].push_back(entry(port, p, pattern));
                } else {
                    if (!std::filesystem::is_directory(parent))
                        return -4;
                    if (wildcard(pattern, "."))
                        directory_[port].push_back(entry(port, parent, "."));
                    if (wildcard(pattern, ".."))
                        directory_[port].push_back(entry(
                            port, parent == roots_[port] ? parent : parent.parent_path(), ".."));
                    std::vector<Path> entries;
                    for (const auto& item : std::filesystem::directory_iterator(parent))
                        if (!hidden(item.path()) && !item.is_symlink() &&
                            wildcard(pattern, item.path().filename().string()))
                            entries.push_back(item.path());
                    std::sort(entries.begin(), entries.end());
                    for (const auto& item : entries)
                        directory_[port].push_back(entry(port, item, item.filename().string()));
                }
            }
            int copied = 0;
            for (; copied < count && cursor_[port] < directory_[port].size();
                 ++copied, ++cursor_[port])
                if (!write(word(q, 16) + copied * 64, directory_[port][cursor_[port]].data(), 64))
                    return -5;
            return copied;
        }
        if (!std::filesystem::exists(p))
            return -4;
        if (cmd == 15) {
            if (p == roots_[port])
                return -5;
            for (const auto& [fd, h] : handles_)
                if (h.path == p)
                    return -5;
            if (std::filesystem::is_directory(p) && !std::filesystem::is_empty(p))
                return -6;
            if (!std::filesystem::remove(p))
                return -5;
            std::error_code ignored;
            std::filesystem::remove(metadata(port, p), ignored);
            return 0;
        }
        if (cmd == 14) {
            Entry e{};
            if (!read(word(q, 16), e.data(), e.size()))
                return -5;
            Entry result = entry(port, p, p.filename().string());
            int flags = number(q, 8);
            if (flags & ~7)
                return -5;
            if (flags & 1)
                std::copy_n(e.begin(), 8, result.begin());
            if (flags & 2)
                std::copy_n(e.begin() + 8, 8, result.begin() + 8);
            if (flags & 4)
                std::copy_n(e.begin() + 20, 2, result.begin() + 20);
            Path target = metadata(port, p);
            std::filesystem::create_directories(target.parent_path());
            std::ofstream output(target, std::ios::binary | std::ios::trunc);
            output.write(reinterpret_cast<const char*>(result.data()), result.size());
            return output ? 0 : -5;
        }
        if (cmd == 18)
            return static_cast<int>(
                std::min<uint64_t>(512, (Capacity - std::min(Capacity, used(port))) / 1024));
        return -5;
    }
};
} // namespace reo::memory_card
