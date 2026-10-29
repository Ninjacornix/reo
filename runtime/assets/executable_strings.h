#pragma once
#include "overlay.h"
#include <regex>

namespace reo::assets {
struct StringPatch { uint32_t address; std::vector<uint8_t> original, replacement; };
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
    require(std::memcmp(magic, "REOSTR1\0", 8) == 0, "Unsupported executable string plan");
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
    const auto count = reader.number(); require(count && count <= 4096 && ram && ramBytes >= end, "Invalid executable string plan bounds");
    std::vector<StringPatch> patches; uint64_t total = 0;
    for (uint32_t i = 0; i < count; ++i) {
        const auto address = reader.number(), capacity = reader.number(), size = reader.number();
        require(capacity && capacity <= 65535 && size <= capacity && address >= begin &&
            uint64_t(address) + capacity + 1 <= end, "Executable string outside its bounded data region");
        total += capacity + size; require(total <= 1024 * 1024, "Executable string plan exceeds limit");
        StringPatch patch{address, std::vector<uint8_t>(capacity + 1), std::vector<uint8_t>(size)};
        reader.read(patch.original.data(), patch.original.size()); reader.read(patch.replacement.data(), patch.replacement.size());
        require(patch.original.back() == 0 && std::find(patch.original.begin(), patch.original.end() - 1, 0) == patch.original.end() - 1 &&
            std::find(patch.replacement.begin(), patch.replacement.end(), 0) == patch.replacement.end(), "Embedded NUL or missing string terminator");
        std::vector<uint8_t> original(patch.original.size()); elf.read(address - 0x100000 + 0x200, original.size(), original.data());
        require(original == patch.original && std::memcmp(ram + address, original.data(), original.size()) == 0, "Original executable string bytes differ");
        const std::string oldText(patch.original.begin(), patch.original.end() - 1), newText(patch.replacement.begin(), patch.replacement.end());
        for (const auto* expression : {R"(<[^>\r\n]+>)", R"(%(?:\d+\$)?[-+ #0]*(?:\d+|\*)?(?:\.(?:\d+|\*))?(?:hh|ll|[hlLjzt])?[diuoxXfFeEgGaAcspn%])"})
            require(stringTokens(oldText, expression) == stringTokens(newText, expression), "Executable string formatting tokens differ");
        patches.push_back(std::move(patch));
    }
    require(reader.done(), "Trailing executable string plan bytes");
    std::sort(patches.begin(), patches.end(), [](const auto& a, const auto& b) { return a.address < b.address; });
    for (size_t i = 1; i < patches.size(); ++i)
        require(uint64_t(patches[i - 1].address) + patches[i - 1].original.size() <= patches[i].address, "Overlapping executable string patches");
    // Validate the complete plan before the first guest-memory write.
    for (const auto& patch : patches) {
        std::memset(ram + patch.address, 0, patch.original.size());
        std::memcpy(ram + patch.address, patch.replacement.data(), patch.replacement.size());
        std::fprintf(stderr, "[EXECUTABLE-STRINGS-1] applied address=0x%08x bytes=%zu budget=%zu\n", patch.address, patch.replacement.size(), patch.original.size() - 1);
    }
}
} // namespace reo::assets
