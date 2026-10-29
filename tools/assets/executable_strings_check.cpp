#include "runtime/assets/executable_strings.h"
#include <iostream>

// Owned ELF + launcher-produced plan. Reads game bytes only; writes a named
// private test plan and host-side synthetic RAM, never the executable or game RAM.
int main(int argc, char** argv) {
    try {
        using namespace reo::assets;
        require(argc == 5, "Usage: executable_strings_check elf plan file1|file2 new-scratch-plan");
        const auto elf = std::filesystem::u8path(argv[1]), plan = std::filesystem::u8path(argv[2]), scratch = std::filesystem::u8path(argv[4]);
        require(!std::filesystem::exists(scratch), "Choose a new scratch file");
        Source source(elf), input(plan); std::vector<uint8_t> bytes(input.size), image(source.size);
        input.read(0, bytes.size(), bytes.data()); source.read(0, image.size(), image.data());
        require(bytes.size() >= 60 && image.size() > 512, "Truncated test inputs");
        std::vector<uint8_t> original(32 * 1024 * 1024);
        std::copy(image.begin() + 512, image.end(), original.begin() + 0x100000);
        auto setPlan = [&](const std::filesystem::path& path) {
#ifdef _WIN32
            _wputenv_s(L"REO_EXECUTABLE_STRINGS", path.c_str());
#else
            setenv("REO_EXECUTABLE_STRINGS", path.c_str(), 1);
#endif
        };
        bool file2 = std::string(argv[3]) == "file2"; unsigned checks = 0;
        setPlan(plan); auto memory = original; applyExecutableStrings(elf, memory.data(), memory.size(), file2);
        size_t at = 48;
        for (uint32_t n = 0; n < u32(bytes.data() + 44); ++n) {
            uint32_t address = u32(bytes.data() + at), capacity = u32(bytes.data() + at + 4), size = u32(bytes.data() + at + 8); at += 12;
            require(at + capacity + 1 + size <= bytes.size(), "Invalid test plan record"); at += capacity + 1;
            require(std::memcmp(memory.data() + address, bytes.data() + at, size) == 0, "Replacement bytes differ in guest slot");
            for (uint32_t i = size; i <= capacity; ++i) require(memory[address + i] == 0, "String terminator or padding differs");
            at += size; ++checks;
        }
        auto rejected = [&](std::vector<uint8_t> modified, bool guestMismatch = false) {
            { std::ofstream output(scratch, std::ios::binary); output.write(reinterpret_cast<const char*>(modified.data()), modified.size()); }
            setPlan(scratch); auto ram = original; if (guestMismatch) ram[u32(bytes.data() + 48)] ^= 1;
            auto before = ram; bool failed = false;
            try { applyExecutableStrings(elf, ram.data(), ram.size(), file2); } catch (const std::exception&) { failed = true; }
            require(failed && before == ram, "Invalid plan accepted or partially changed memory"); ++checks;
        };
        auto corrupt = bytes; corrupt.push_back(0); rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + 48, 0x100008); rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + 56, u32(corrupt.data() + 52) + 1); rejected(corrupt);
        corrupt = bytes; corrupt[12] ^= 1; rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + 44, 4097); rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + 8, file2 ? 1 : 2); rejected(corrupt);
        const auto capacity = u32(bytes.data() + 52), size = u32(bytes.data() + 56);
        const auto firstEnd = 60 + capacity + 1 + size;
        require(firstEnd <= bytes.size(), "First test patch is truncated");
        corrupt.assign(bytes.begin(), bytes.begin() + 60 + capacity + 1);
        put32(corrupt.data() + 44, 1); put32(corrupt.data() + 56, 2); corrupt.push_back('%'); corrupt.push_back('n'); rejected(corrupt);
        corrupt.assign(bytes.begin(), bytes.begin() + firstEnd); put32(corrupt.data() + 44, 2);
        corrupt.insert(corrupt.end(), bytes.begin() + 48, bytes.begin() + firstEnd); rejected(corrupt);
        rejected(bytes, true);
        std::filesystem::remove(scratch);
        std::cout << "PASS: " << checks << " native string writes, terminators, bounds, identity and atomic rejection checks\n";
        return 0;
    } catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
