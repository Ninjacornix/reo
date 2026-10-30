#pragma once
inline void testFile2Cheats() {
    using namespace reo::cheats;
    std::vector<uint8_t> ram(32 * 1024 * 1024);
    unsigned checks = 0;
    auto check = [&](bool ok) {
        if (!ok) throw std::runtime_error("File #2 cheat check failed");
        ++checks;
    };
    for (unsigned player = 0; player < 4; ++player) {
        std::fill(ram.begin(), ram.end(), 0);
        auto* r = ram.data();
        const uint32_t actor = 0x4c5e10 + player * 0x1100;
        const uint32_t item = 0x3e1c20 + 81 * 60, info = 0x7aca00 + 18 * 24;
        r[0x4db3ad] = uint8_t(player);
        r[actor] = 1;
        setHalf(r, actor + 0x540, 1200);
        setHalf(r, actor + 0x542, 2300);
        setWord(r, actor + 0xbc4, 1234);
        // Four inventory handles and the personal firearm slot.
        r[actor + 0xc98] = 81;
        r[item] = 1; r[item + 2] = 81; r[item + 0x2b] = 18;
        setHalf(r, item + 6, 20);
        setHalf(r, item + 0x24, 0);
        setHalf(r, info + 18, 20);
        setHalf(r, info + 8, 7);
        setWord(r, info, 0x104001);
        setHalf(r, 0x7ada20, 150);
        auto apply2 = [&](unsigned flags) { return applyBuiltins(flags, r, Game::File2); };
        auto before = ram;
        check(!apply2(7).active && ram == before); // Menus must be untouched.
        r[0x4db390] = 2;
        before = ram;
        check(!apply2(0).active && ram == before);
        auto expected = ram;
        setHalf(expected.data(), actor + 0x540, 2300);
        setWord(expected.data(), actor + 0xbc4, 0);
        setHalf(expected.data(), item + 0x24, 7);
        auto result = apply2(7);
        check(result.active && result.player == player && result.health == 2300 &&
              result.virus == 0 && result.ammunitionSlots == 1);
        check(ram == expected); // Includes all File #1 addresses and other actors.
        apply2(7); check(ram == expected);
        setHalf(r, actor + 0x540, 1000);
        setWord(r, actor + 0xbc4, 4321);
        setHalf(r, item + 0x24, 1);
        apply2(NoInfection);
        check(half(r, actor + 0x540) == 1000 && half(r, item + 0x24) == 1 &&
              word(r, actor + 0xbc4) == 0);
        for (unsigned count : {0u, 18u, 257u}) {
            setHalf(r, 0x7ada20, uint16_t(count));
            check(apply2(InfiniteAmmo).ammunitionSlots == 0 && half(r, item + 0x24) == 1);
        }
        setHalf(r, 0x7ada20, 150);
        setWord(r, info, 0x100400); // Ammunition boxes are not firearms.
        check(apply2(InfiniteAmmo).ammunitionSlots == 0);
        setWord(r, info, 0x104001);
        for (unsigned slot = 0; slot < 5; ++slot) {
            std::fill(r + actor + 0xc94, r + actor + 0xc99, 0);
            r[actor + 0xc94 + slot] = 81;
            check(apply2(InfiniteAmmo).ammunitionSlots == 1);
        }
        r[actor + 0xbe8] = 1;
        before = ram;
        check(!apply2(7).active && ram == before);
        r[actor + 0xbe8] = 0;
        setHalf(r, actor + 0x540, 0);
        before = ram;
        check(!apply2(7).active && ram == before);
        r[0x4db3ad] = 4;
        check(!apply2(7).active);
        bool refused = false;
        try { apply2(UnlockEverything); } catch (const std::runtime_error&) { refused = true; }
        check(refused);
    }
    std::cout << "PASS " << checks << " File #2 cheat checks\n";
}

