#include "../../runtime/cheats/outbreak_cheats.h"
#include <fstream>
#include <iostream>
#include <numeric>

int main(int argc, char** argv) try {
    using namespace reo::cheats;
    unsigned checks = 0;
    auto check = [&](bool ok, const char* message) {
        if (!ok) throw std::runtime_error(message);
        ++checks;
    };
    check(!applyBuiltins(UnlockEverything, nullptr, Game::File2).unlocks, "Null RAM");
    for (unsigned pattern : {0u, 0x5au, 0xffu}) {
        std::vector<uint8_t> ram(32 * 1024 * 1024, uint8_t(pattern));
        ram[0x4db390] = 0; // Menus: unlocks do not require a live player.
        auto before = ram;
        check(!applyBuiltins(0, ram.data(), Game::File2).unlocks && ram == before, "Disabled unlock writes");
        auto result = applyBuiltins(UnlockEverything, ram.data(), Game::File2);
        check(result.unlocks && !result.active, "Menu progression service");
        check((word(ram.data(), 0x30022c) & 0xfff) == 0xfff, "Scenario availability");
        check((ram[0x2feec5] & 15) == 15, "Difficulty availability");
        auto expected = before;
        const uint8_t costumeMask[] = {3,3,3,3,3,15,15,15};
        const uint32_t npcMask[] = {0x7bcffcc2,0xffdbcff8,0x1fffc0fb,0};
        for (unsigned i = 0; i < 8; ++i) expected[0x2feea8+i] |= costumeMask[i];
        for (unsigned i = 0; i < 4; ++i)
            setWord(expected.data(), 0x2feeb0+4*i, word(before.data(),0x2feeb0+4*i) | npcMask[i]);
        expected[0x2feec5] |= 15;
        expected[0x2feec3] |= 13;
        setWord(expected.data(), 0x30022c, word(before.data(),0x30022c) | 0xfff);
        const unsigned counts[] = {145,59,146,14,11};
        for (unsigned bank = 0; bank < 5; ++bank)
            for (unsigned bit = 0; bit < 160; ++bit) {
                const unsigned byte = bank*20+bit/8, mask = 1u << (bit%8);
                if (bit < counts[bank]) {
                    expected[0x300248+byte] |= mask;
                    expected[0x3002ac+byte] |= mask;
                }
            }
        check(ram == expected, "Full RAM comparison: points, records, padding, settings and File #1 fields preserved");
        before = ram;
        applyBuiltins(UnlockEverything, ram.data(), Game::File2);
        check(ram == before, "Repeated frames are idempotent");
        applyBuiltins(UnlockEverything | FullHealth | NoInfection | InfiniteAmmo, ram.data(), Game::File2);
        check(ram == before, "Other menu cheats leave progression and actor data intact");
        if (argc == 2 && pattern == 0) {
            std::ofstream output(argv[1], std::ios::binary);
            output.write(reinterpret_cast<const char*>(ram.data()), ram.size());
            check(bool(output), "Private oracle comparison output");
        }
    }
    std::cout << "PASS " << checks << " File #2 progression checks\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
