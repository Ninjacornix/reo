#pragma once
#include "overlay.h"
#include <regex>
#include <set>

namespace reo::assets {
struct StringPatch { uint32_t address, capacity; std::vector<uint8_t> original, replacement; };
inline std::set<uint32_t> stringLiteralTargets(const Source& elf, uint32_t begin, uint32_t end) {
    std::vector<uint8_t> image(elf.size); elf.read(0, image.size(), image.data());
    require(image.size() >= 52, "Truncated string ELF");
    uint32_t table = u32(image.data() + 28), count = image[44] | uint32_t(image[45]) << 8;
    require(count && count <= 256 && uint64_t(table) + count * 32 <= image.size(), "Invalid string ELF program table");
    std::set<uint32_t> targets;
    for (uint32_t i = 0; i < count; ++i) {
        const auto* p = image.data() + table + i * 32;
        if (u32(p) != 1) continue;
        uint32_t offset = u32(p + 4), bytes = u32(p + 16);
        require(uint64_t(offset) + bytes <= image.size(), "Invalid string ELF load range");
        for (uint64_t at = (uint64_t(offset) + 3) & ~uint64_t(3); at + 4 <= uint64_t(offset) + bytes; at += 4) {
            uint32_t value = u32(image.data() + at);
            if (value >= 0x80000000u && value < 0xc0000000u) value &= 0x1fffffffu;
            if (value >= begin && value < end) targets.insert(value);
        }
    }
    return targets;
}
inline std::vector<std::string> stringTokens(const std::string& text, const char* expression) {
    const std::regex pattern(expression);
    std::vector<std::string> result;
    for (std::sregex_iterator it(text.begin(), text.end(), pattern), end; it != end; ++it) result.push_back(it->str());
    return result;
}
inline void applyExecutableStrings(const std::filesystem::path& elfPath, uint8_t* ram, size_t ramBytes, bool file2) {
#ifdef _WIN32
    const wchar_t* path = _wgetenv(L"REO_EXECUTABLE_STRINGS");
#else
    const char* path = std::getenv("REO_EXECUTABLE_STRINGS");
#endif
    if (!path || !*path) return;
    const char* host = std::getenv("REO_COOP_HOST"); require(!host || !*host, "Executable string mods require offline play");
    PlanReader reader{std::filesystem::path(path)}; char magic[8]; reader.read(magic, 8);
    const bool padded = std::memcmp(magic, "REOSTR2\0", 8) == 0;
    require(padded || std::memcmp(magic, "REOSTR1\0", 8) == 0, "Unsupported executable string plan");
    require(reader.number() == (file2 ? 2u : 1u), "Executable string plan targets another game");
    const auto identity = reader.hash(); Source elf(elfPath);
    require(elf.size < 16 * 1024 * 1024 && digest(elf, 0, elf.size) == identity, "Executable string ELF identity differs");
    const char* expected = file2 ? "5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d" :
                                 "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46";
    for (size_t i = 0; i < identity.size(); ++i) {
        char hex[3]{expected[i * 2], expected[i * 2 + 1], 0};
        require(identity[i] == std::strtoul(hex, nullptr, 16), "Unsupported executable string revision");
    }
    const uint32_t begin = file2 ? 0x2552d0 : 0x24fe60, end = file2 ? 0x269980 : 0x259d80;
    const auto targets = padded ? stringLiteralTargets(elf, begin, end) : std::set<uint32_t>{};
    const auto count = reader.number(); require(count && count <= 4096 && ram && ramBytes >= end, "Invalid executable string plan bounds");
    std::vector<StringPatch> patches; uint64_t total = 0;
    for (uint32_t i = 0; i < count; ++i) {
        const auto address = reader.number(), length = reader.number();
        const auto capacity = padded ? reader.number() : length, size = reader.number();
        require(length && length <= capacity && capacity <= 65535 && size <= capacity && address >= begin &&
            uint64_t(address) + capacity + 1 <= end, "Executable string outside its bounded data region");
        total += capacity + size; require(total <= 1024 * 1024, "Executable string plan exceeds limit");
        StringPatch patch{address, capacity, std::vector<uint8_t>(length + 1), std::vector<uint8_t>(size)};
        reader.read(patch.original.data(), patch.original.size()); reader.read(patch.replacement.data(), patch.replacement.size());
        require(patch.original.back() == 0 && std::find(patch.original.begin(), patch.original.end() - 1, 0) == patch.original.end() - 1 &&
            std::find(patch.replacement.begin(), patch.replacement.end(), 0) == patch.replacement.end(), "Embedded NUL or missing string terminator");
        std::vector<uint8_t> original(patch.original.size()); elf.read(address - 0x100000 + 0x200, original.size(), original.data());
        require(original == patch.original && std::memcmp(ram + address, original.data(), original.size()) == 0, "Original executable string bytes differ");
        if (capacity > length) {
            require(uint64_t(address) + capacity + 1 <= ((uint64_t(address) + length + 16) & ~uint64_t(15)),
                    "Executable string padding exceeds its alignment slot");
            const auto referenced = targets.lower_bound(address + length);
            require(referenced == targets.end() || *referenced > address + capacity, "Executable string padding has a literal address reference");
            std::vector<uint8_t> padding(capacity - length + 1);
            elf.read(address - 0x100000 + 0x200 + length, padding.size(), padding.data());
            require(std::all_of(padding.begin(), padding.end(), [](uint8_t b) { return b == 0; }) &&
                std::all_of(ram + address + length, ram + address + capacity + 1, [](uint8_t b) { return b == 0; }),
                "Executable string padding is not untouched zero bytes");
        }
        const std::string oldText(patch.original.begin(), patch.original.end() - 1), newText(patch.replacement.begin(), patch.replacement.end());
        for (const auto* expression : {R"(<[^>\r\n]+>)", R"(%(?:\d+\$)?[-+ #0]*(?:\d+|\*)?(?:\.(?:\d+|\*))?(?:hh|ll|[hlLjzt])?[diuoxXfFeEgGaAcspn%])"})
            require(stringTokens(oldText, expression) == stringTokens(newText, expression), "Executable string formatting tokens differ");
        patches.push_back(std::move(patch));
    }
    require(reader.done(), "Trailing executable string plan bytes");
    std::sort(patches.begin(), patches.end(), [](const auto& a, const auto& b) { return a.address < b.address; });
    for (size_t i = 1; i < patches.size(); ++i)
        require(uint64_t(patches[i - 1].address) + patches[i - 1].capacity + 1 <= patches[i].address, "Overlapping executable string patches");
    // Validate the complete plan before the first guest-memory write.
    for (const auto& patch : patches) {
        std::memset(ram + patch.address, 0, patch.capacity + 1);
        std::memcpy(ram + patch.address, patch.replacement.data(), patch.replacement.size());
        std::fprintf(stderr, "%s applied address=0x%08x bytes=%zu budget=%u\n", padded ? "[EXECUTABLE-STRINGS-2]" : "[EXECUTABLE-STRINGS-1]",
                     patch.address, patch.replacement.size(), patch.capacity);
    }
}
} // namespace reo::assets
