#include "runtime/assets/executable_strings.h"
#include <iostream>

// Owned ELF + launcher-produced plan. Reads game bytes only; writes a named
// private test plan and host-side synthetic RAM, never the executable or game RAM.
int main(int argc, char** argv) {
    try {
        using namespace reo::assets;
        require(argc == 5 || argc == 6, "Usage: executable_strings_check elf plan file1|file2 new-scratch-plan [referenced-padding-negative-plan]");
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
        const bool padded = std::memcmp(bytes.data(), "REOSTR2\0", 8) == 0;
        const size_t fields = padded ? 16 : 12, sizeField = padded ? 60 : 56;
        size_t at = 48; auto expectedMemory = original;
        for (uint32_t n = 0; n < u32(bytes.data() + 44); ++n) {
            uint32_t address = u32(bytes.data() + at), length = u32(bytes.data() + at + 4), capacity = padded ? u32(bytes.data() + at + 8) : length, size = u32(bytes.data() + at + fields - 4); at += fields;
            require(at + length + 1 + size <= bytes.size(), "Invalid test plan record"); at += length + 1;
            require(std::memcmp(memory.data() + address, bytes.data() + at, size) == 0, "Replacement bytes differ in guest slot");
            for (uint32_t i = size; i <= capacity; ++i) require(memory[address + i] == 0, "String terminator or padding differs");
            std::fill(expectedMemory.begin() + address, expectedMemory.begin() + address + capacity + 1, 0);
            std::copy(bytes.begin() + at, bytes.begin() + at + size, expectedMemory.begin() + address);
            at += size; ++checks;
        }
        require(memory == expectedMemory, "String plan changed bytes outside its exact patch ranges"); ++checks;
        auto rejected = [&](std::vector<uint8_t> modified, uint32_t guestMismatch = 0, const char* expected = nullptr) {
            { std::ofstream output(scratch, std::ios::binary); output.write(reinterpret_cast<const char*>(modified.data()), modified.size()); }
            setPlan(scratch); auto ram = original; if (guestMismatch) ram[guestMismatch] ^= 1;
            auto before = ram; bool failed = false; std::string reason;
            try { applyExecutableStrings(elf, ram.data(), ram.size(), file2); } catch (const std::exception& error) { failed = true; reason = error.what(); }
            require(failed && before == ram, "Invalid plan accepted or partially changed memory"); ++checks;
            require(!expected || reason.find(expected) != std::string::npos, "Plan was rejected for an unexpected reason");
        };
        auto corrupt = bytes; corrupt.push_back(0); rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + 48, 0x100008); rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + sizeField, u32(corrupt.data() + (padded ? 56 : 52)) + 1); rejected(corrupt);
        corrupt = bytes; corrupt[12] ^= 1; rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + 44, 4097); rejected(corrupt);
        corrupt = bytes; put32(corrupt.data() + 8, file2 ? 1 : 2); rejected(corrupt);
        const auto length = u32(bytes.data() + 52), capacity = padded ? u32(bytes.data() + 56) : length, size = u32(bytes.data() + sizeField);
        const auto firstEnd = 48 + fields + length + 1 + size;
        require(firstEnd <= bytes.size(), "First test patch is truncated");
        corrupt.assign(bytes.begin(), bytes.begin() + 48 + fields + length + 1);
        put32(corrupt.data() + 44, 1); put32(corrupt.data() + sizeField, 2); corrupt.push_back('%'); corrupt.push_back('n'); rejected(corrupt);
        corrupt.assign(bytes.begin(), bytes.begin() + firstEnd); put32(corrupt.data() + 44, 2);
        corrupt.insert(corrupt.end(), bytes.begin() + 48, bytes.begin() + firstEnd); rejected(corrupt);
        rejected(bytes, u32(bytes.data() + 48));
        if (padded && capacity > length) {
            rejected(bytes, u32(bytes.data() + 48) + length + 1);
            corrupt = bytes; put32(corrupt.data() + 56, 65535); rejected(corrupt);
        }
        if (argc == 6) {
            Source negative(std::filesystem::u8path(argv[5])); std::vector<uint8_t> invalid(negative.size);
            negative.read(0, invalid.size(), invalid.data());
            auto targets = stringLiteralTargets(source, file2 ? 0x2552d0u : 0x24fe60u, file2 ? 0x269980u : 0x259d80u);
            uint32_t address = u32(invalid.data() + 48), length = u32(invalid.data() + 52), capacity = u32(invalid.data() + 56);
            auto target = targets.lower_bound(address + length);
            require(target != targets.end() && *target <= address + capacity, "Negative padding fixture has no literal reference");
            // This fixture may also cross an alignment boundary. Both constraints
            // must reject it without touching RAM; verify the pointer scan too.
            rejected(invalid);
        }
        std::filesystem::remove(scratch);
        std::cout << "PASS: " << checks << " native string writes, terminators, bounds, identity and atomic rejection checks\n";
        return 0;
    } catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
