#pragma once
#include "../../runtime/cheats/outbreak_cheats.h"
#include <algorithm>
#include <cstdio>

inline void testResultsPointsCheats() {
    using namespace reo::cheats;
    unsigned checks = 0;
    const auto check = [&](bool ok, const char* message) {
        if (!ok) throw std::runtime_error(message);
        ++checks;
    };
    check(maximumResultsPoints == 999999999u, "Results points must use the owned games' nine-digit maximum");
    check(!applyBuiltins(MaxResultsPoints, nullptr, Game::File1).points &&
          !applyBuiltins(MaxResultsPoints, nullptr, Game::File2).points,
          "Missing guest RAM must remain a no-op");
    std::vector<uint8_t> ram(32 * 1024 * 1024, 0xa5);
    for (const auto game : {Game::File1, Game::File2}) {
        const bool file2 = game == Game::File2;
        const uint32_t wallet = file2 ? 0x2feea4 : 0x31fb60;
        const uint32_t lifetime = file2 ? 0x2feea0 : 0x323d14;
        const uint32_t state = file2 ? 0x4db390 : 0x4badd0;
        const uint32_t actor = file2 ? 0x4c5e10 : 0x4a5c30;
        const uint32_t health = file2 ? 0x540 : 0x544;
        const uint32_t dead = file2 ? 0xbe8 : 0xbd0;
        const uint32_t virus = file2 ? 0xbc4 : 0xbac;
        // No gameplay flag, current-player state, or living actor is needed by
        // the collection wallet. Exercise all these states against whole RAM.
        for (unsigned context = 0; context < 5; ++context) {
            std::fill(ram.begin(), ram.end(), 0xa5);
            ram[state] = context == 0 ? 0 : context == 4 ? 13 : 2;
            ram[state + 0x1d] = context == 3 ? 255 : 0;
            ram[actor] = 1;
            ram[actor + 8] = 0;
            ram[actor + dead] = context == 2 ? 1 : 0;
            setHalf(ram.data(), actor + health, context == 2 ? 0 : 1000);
            setHalf(ram.data(), actor + health + 2, 2000);
            setWord(ram.data(), actor + virus, 1234);
            setWord(ram.data(), lifetime, 123456789);
            for (const auto balance : {0u, 12345u, maximumResultsPoints, 0xffffffffu}) {
                setWord(ram.data(), wallet, balance);
                const auto before = ram;
                const auto disabled = applyBuiltins(0, ram.data(), game);
                check(!disabled.points && ram == before,
                      "Unselected results-points cheat must not change any guest state");
                auto expected = ram;
                setWord(expected.data(), wallet, maximumResultsPoints);
                const auto result = applyBuiltins(MaxResultsPoints, ram.data(), game);
                check(result.points && ram == expected,
                      "Results-points cheat must touch only this edition's four-byte spendable wallet");
                check(word(ram.data(), lifetime) == 123456789 &&
                      half(ram.data(), actor + health) == (context == 2 ? 0 : 1000) &&
                      word(ram.data(), actor + virus) == 1234,
                      "Max points must preserve lifetime totals, player health and infection");
            }
        }
        // A regular collection purchase may deduct from the balance. With the
        // cheat disabled it remains spent; the next enabled frame restores it.
        ram[state] = 0;
        setWord(ram.data(), wallet, maximumResultsPoints - 2500);
        auto spent = ram;
        check(!applyBuiltins(FullHealth | NoInfection | InfiniteAmmo, ram.data(), game).points && ram == spent,
              "Other menu-safe cheats must not implicitly grant points");
        check(!applyBuiltins(0, ram.data(), game).points && ram == spent,
              "Disabling max points preserves subsequent normal purchases");
        auto expected = ram;
        setWord(expected.data(), wallet, maximumResultsPoints);
        check(applyBuiltins(MaxResultsPoints, ram.data(), game).points && ram == expected,
              "Enabled max points refills after a collection purchase without touching its records");
        check(applyBuiltins(MaxResultsPoints, ram.data(), game).points && ram == expected,
              "Repeated max-points frames are idempotent at the native cap");
    }
    std::printf("PASS %u results-points checks\n", checks);
}
