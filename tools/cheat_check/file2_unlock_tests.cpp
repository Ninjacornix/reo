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
    std::istringstream hiddenManifest("REO-CHEATS-2\nbuiltin file3\n");
    const auto hidden = parseProgram(hiddenManifest);
    check(hidden.builtins == UnlockFile3Characters && hidden.writes.empty(), "File #3 manifest is a dedicated built-in");
    for (unsigned pattern : {0u, 0x5au, 0xffu}) {
        std::vector<uint8_t> ram(32 * 1024 * 1024, uint8_t(pattern));
        ram[0x4db390] = 0; // Menus: unlocks do not require a live player.
        auto before = ram;
        check(!applyBuiltins(0, ram.data(), Game::File2).unlocks && ram == before, "Disabled unlock writes");
        auto result = applyBuiltins(UnlockEverything, ram.data(), Game::File2);
        check(result.unlocks && !result.active, "Menu progression service");
        check((word(ram.data(), 0x30022c) & 0xfff) == 0xfff, "Scenario availability");
        check((word(ram.data(), 0x2ff8c8) & 0xffe) == 0xffe, "Online room scenario availability");
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
        setWord(expected.data(), 0x2ff8c8, word(before.data(),0x2ff8c8) | 0xffe);
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
        auto hiddenRam = before;
        auto hiddenExpected = before;
        constexpr unsigned hiddenIds[] = {0, 2, 3, 4, 5, 8, 9, 20, 21, 26, 31, 32, 33,
                                           34, 44, 45, 50, 53, 66, 72, 73, 74, 75, 76, 77};
        for (unsigned id : hiddenIds)
            hiddenExpected[0x2feeb0 + id / 8] |= uint8_t(1u << (id % 8));
        applyBuiltins(hidden.builtins, hiddenRam.data(), Game::File1);
        check(hiddenRam == before, "File #3 option has no effect in File #1");
        applyBuiltins(hidden.builtins, hiddenRam.data(), Game::File2);
        check(hiddenRam == hiddenExpected, "Hidden-only unlock sets exactly the 25 NPC bits and preserves all other RAM");
        applyBuiltins(hidden.builtins, hiddenRam.data(), Game::File2);
        check(hiddenRam == hiddenExpected, "Hidden-only unlock is idempotent");
        applyBuiltins(hidden.builtins | UnlockEverything, hiddenRam.data(), Game::File2);
        for (unsigned id : hiddenIds)
            expected[0x2feeb0 + id / 8] |= uint8_t(1u << (id % 8));
        check(hiddenRam == expected, "Full solo unlock adds hidden NPCs to normal progression without exposing unnamed entries");
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
