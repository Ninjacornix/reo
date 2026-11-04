#include "runtime/memory_card/card_rpc.h"
#include <iostream>
using namespace reo::memory_card;
int main(int argc, char** argv) {
    if (argc != 2)
        return 2;
    auto root = std::filesystem::absolute(argv[1]);
    if (std::filesystem::exists(root))
        return 3;
    std::vector<uint8_t> ram(32 * 1024 * 1024), q(1044);
    int checks = 0;
    auto check = [&](bool ok, const char* label) {
        if (!ok)
            throw std::runtime_error(label);
        ++checks;
    };
    auto read = [&](uint32_t a, void* b, size_t n) {
        a &= 0x1fffffff;
        if (a >= ram.size() || n > ram.size() - a)
            return false;
        memcpy(b, ram.data() + a, n);
        return true;
    };
    auto write = [&](uint32_t a, const void* b, size_t n) {
        a &= 0x1fffffff;
        if (a >= ram.size() || n > ram.size() - a)
            return false;
        memcpy(ram.data() + a, b, n);
        return true;
    };
    auto word = [&](int off, uint32_t x) { memcpy(q.data() + off, &x, 4); };
    auto named = [&](const char* name, int flags = 0, int max = 0) {
        std::fill(q.begin(), q.end(), 0);
        word(8, flags);
        word(12, max);
        word(16, 0x1000);
        if (std::strlen(name) >= 1024)
            throw std::runtime_error("test card path exceeds protocol buffer");
        std::memcpy(q.data() + 20, name, std::strlen(name) + 1);
    };
    {
        Service card({root / "card0", {}});
        check(card.call(0x70, {}, read, write) == 0, "init");
        q.resize(48);
        word(4, 0);
        word(8, 0);
        word(28, 0x1000);
        check(card.call(0x78, q, read, write) == -1 && ram[0x1000] == 2, "inserted PS2 card");
        check(card.call(0x78, q, read, write) == 0, "stable card");
        word(4, 1);
        check(card.call(1, q, read, write) == -1 && ram[0x1000] == 0, "empty second slot");
        q.resize(1044);
        named("/BASLUS-20765", 0x40);
        check(card.call(0x71, q, read, write) == 0, "mkdir");
        named("/BASLUS-20765/data", 0x203);
        int fd = card.call(2, q, read, write);
        check(fd >= 0, "create");
        q.assign(48, 0);
        word(0, fd);
        word(12, 7);
        word(20, 3);
        word(24, 0x2000);
        memcpy(q.data() + 32, "abc", 3);
        memcpy(ram.data() + 0x2000, "defghij", 7);
        check(card.call(0x74, q, read, write) == 10, "unaligned prefix and tail");
        word(16, 0);
        word(20, 0);
        check(card.call(4, q, read, write) == 0, "seek");
        word(12, 10);
        word(24, 0x2001);
        word(28, 0x3000);
        ram[0x3000] = 99;
        check(card.call(5, q, read, write) == 10 &&
                  memcmp(ram.data() + 0x2001, "abcdefghij", 10) == 0 && ram[0x3000] == 0,
              "unaligned read and fixup clear");
        check(card.call(3, q, read, write) == 0, "close");
        q.resize(1044);
        named("/BASLUS-20765/*", 0, 1);
        check(card.call(13, q, read, write) == 1, "getdir begin");
        word(8, 1);
        check(card.call(13, q, read, write) == 1, "getdir continue");
        check(card.call(13, q, read, write) == 1 &&
                  strcmp(reinterpret_cast<char*>(ram.data() + 0x1020), "data") == 0,
              "file entry");
        named("/../escape", 0x203);
        check(card.call(2, q, read, write) == -5, "traversal rejected");
        named("/.reo-meta/entry", 0x203);
        check(card.call(2, q, read, write) == -5, "metadata hidden");
        named("/BASLUS-20765");
        check(card.call(15, q, read, write) == -6, "nonempty directory protected");
    }
    {
        Service card({root / "card0", root / "card1"});
        q.resize(1044);
        named("/BASLUS-20765/data", 1);
        int fd = card.call(2, q, read, write);
        check(fd >= 0, "persistent reopen");
        q.assign(48, 0);
        word(0, fd);
        word(12, 10);
        word(24, 0x4000);
        word(28, 0x5000);
        check(card.call(5, q, read, write) == 10 &&
                  memcmp(ram.data() + 0x4000, "abcdefghij", 10) == 0,
              "persistent bytes");
        check(card.call(3, q, read, write) == 0, "close reopened");
        check(card.rename(0, "/BASLUS-20765/data", "renamed") == 0, "rename persistent file");
        check(std::filesystem::exists(root / "card0" / "BASLUS-20765" / "renamed"),
              "rename persisted");
        check(card.rename(0, "/BASLUS-20765/renamed", "../escape") == -5, "rename cannot escape");
        check(card.entrySpace(0, "/BASLUS-20765") > 0, "directory free entries");
        q.resize(1044);
        named("/BASLUS-20765/renamed", 1);
        int ro = card.call(2, q, read, write);
        check(ro >= 0, "open read only");
        q.assign(48, 0);
        word(0, ro);
        word(12, 1);
        word(24, 0x2000);
        check(card.call(6, q, read, write) == -5, "read only handle cannot write");
        check(card.call(3, q, read, write) == 0, "close read only");
        q.resize(1044);
        named("/capacity", 0x203);
        int full = card.call(2, q, read, write);
        check(full >= 0, "capacity test file");
        q.assign(48, 0);
        word(0, full);
        word(12, 8 * 1024 * 1024);
        word(24, 0x100000);
        check(card.call(6, q, read, write) == -3, "card capacity enforced");
        check(card.call(3, q, read, write) == 0, "close capacity file");
        q.resize(1044);
        named("/BASLUS-20765/data", 1);
        word(0, 1);
        check(card.call(2, q, read, write) == -4, "card isolation");
        q.assign(48, 0);
        word(4, 0);
        check(card.call(0x77, q, read, write) == 0, "explicit format");
        check(!std::filesystem::exists(root / "card0" / "BASLUS-20765"), "formatted empty");
        bool preserved = false;
        for (auto& p : std::filesystem::directory_iterator(root))
            if (p.path().filename().string().find("before-format") != std::string::npos)
                preserved = std::filesystem::exists(p.path() / "BASLUS-20765" / "renamed");
        check(preserved, "format preserves backup");
    }
    std::cout << "PASS " << checks << " checks\n";
}
