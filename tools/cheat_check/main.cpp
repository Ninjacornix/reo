#include "../../runtime/cheats/outbreak_cheats.h"
#include <iostream>
#include <sstream>
#include "weapon_shuffle_tests.h"
#include "enemy_randomizer_tests.h"
int main() {
    testWeaponShuffle();
    testEnemyRandomizer();
    using namespace reo::cheats;
    unsigned checks = 0;
    auto check = [&](bool ok) {
        if (!ok)
            throw std::runtime_error("Check failed");
        ++checks;
    };
    std::istringstream input("REO-CHEATS-1\n0 0056FFF0 4 12345678\n1 0056FFF4 2 ABCD\n2 0056FFF8 1 "
                             "42\n3 0056FFFA 2 CDEF\n");
    auto writes = parse(input);
    std::vector<uint8_t> ram(32 * 1024 * 1024);
    apply(writes, ram.data(), true);
    check(ram[0x56fff0] == 0x78 && ram[0x56fff3] == 0x12);
    check(ram[0x56fff4] == 0 && ram[0x56fff8] == 0x42 && ram[0x56fffa] == 0xef);
    ram[0x56fff0] = 0;
    ram[0x56fff8] = 0;
    ram[0x56fffa] = 0;
    apply(writes, ram.data(), false);
    check(ram[0x56fff0] == 0 && ram[0x56fff4] == 0xcd && ram[0x56fff5] == 0xab);
    check(ram[0x56fff8] == 0x42 && ram[0x56fffa] == 0);
    for (const char* bad :
         {"bad\n", "REO-CHEATS-1\n1 00100000 4 0\n", "REO-CHEATS-1\n1 00570000 4 0\n",
          "REO-CHEATS-1\n1 01FCFFFF 8 0\n", "REO-CHEATS-1\n1 0056FFF0 1 100\n",
          "REO-CHEATS-1\n4 0056FFF0 1 0\n", "REO-CHEATS-1\n1 0056FFF0 3 0\n",
          "REO-CHEATS-1\n1 0056FFF0 1 0 trailing\n"}) {
        bool refused = false;
        try {
            std::istringstream b(bad);
            parse(b);
        } catch (const std::runtime_error&) {
            refused = true;
        }
        check(refused);
    }
    std::istringstream builtinInput(
        "REO-CHEATS-2\nbuiltin health\nbuiltin infection\nbuiltin ammo\n1 0056FFF0 4 1\n");
    auto program = parseProgram(builtinInput);
    check(program.builtins == 7 && program.writes.size() == 1);
    bool unknown = false;
    try {
        std::istringstream input("REO-CHEATS-2\nbuiltin unsafe\n");
        parseProgram(input);
    } catch (const std::runtime_error&) {
        unknown = true;
    }
    check(unknown);
    std::istringstream legacy("REO-CHEATS-1\n1 0056FFF0 1 42\n");
    check(parseProgram(legacy).writes.size() == 1);
    const uint32_t actor = 0x4a5c30 + 0x10e0, other = 0x4a5c30, item = 0x3c5630 + 81 * 60,
                   info = 0x74bb50 + 18 * 24;
    ram[0x4baded] = 1;
    ram[actor] = 1;
    ram[other] = 1;
    ram[actor + 0xc88] = 81;
    setHalf(ram.data(), actor + 0x544, 1200);
    setHalf(ram.data(), actor + 0x546, 2300);
    setWord(ram.data(), actor + 0xbac, 1234);
    setHalf(ram.data(), other + 0x544, 500);
    ram[item] = 1;
    ram[item + 2] = 81;
    ram[item + 0x2b] = 18;
    setHalf(ram.data(), item + 6, 0x190);
    setHalf(ram.data(), item + 0x24, 2);
    setHalf(ram.data(), info + 18, 0x190);
    setHalf(ram.data(), info + 8, 7);
    setWord(ram.data(), info, 0x00102041);
    check(!applyBuiltins(7, ram.data()).active && half(ram.data(), actor + 0x544) == 1200); // menu
    ram[0x4badd0] = 2;
    check(!applyBuiltins(0, ram.data()).active && word(ram.data(), actor + 0xbac) == 1234);
    auto effects = applyBuiltins(7, ram.data());
    check(effects.active && effects.player == 1 && effects.health == 2300 && effects.virus == 0 &&
          effects.ammunitionSlots == 1);
    check(half(ram.data(), item + 0x24) == 7 && half(ram.data(), other + 0x544) == 500);
    setHalf(ram.data(), actor + 0x544, 1100);
    setWord(ram.data(), actor + 0xbac, 4321);
    setHalf(ram.data(), item + 0x24, 1);
    applyBuiltins(NoInfection, ram.data());
    check(half(ram.data(), actor + 0x544) == 1100 && half(ram.data(), item + 0x24) == 1 &&
          word(ram.data(), actor + 0xbac) == 0);
    setHalf(ram.data(), info + 18, 0x191);
    check(applyBuiltins(InfiniteAmmo, ram.data()).ammunitionSlots == 0 &&
          half(ram.data(), item + 0x24) == 1);
    setHalf(ram.data(), info + 18, 0x190);
    setWord(ram.data(), info, 1);
    check(applyBuiltins(InfiniteAmmo, ram.data()).ammunitionSlots == 0);
    setWord(ram.data(), info, 0x00102041);
    ram[item + 2] = 82;
    check(applyBuiltins(InfiniteAmmo, ram.data()).ammunitionSlots == 0);
    ram[item + 2] = 81;
    setHalf(ram.data(), actor + 0x544, 0);
    check(!applyBuiltins(7, ram.data()).active && half(ram.data(), actor + 0x544) == 0);
    setHalf(ram.data(), actor + 0x544, 1000);
    ram[actor + 8] = 4;
    check(!applyBuiltins(7, ram.data()).active);
    ram[actor + 8] = 0;
    ram[0x4baded] = 255;
    check(!applyBuiltins(7, ram.data()).active);
    std::cout << "PASS " << checks << " cheat engine checks\n";
}
