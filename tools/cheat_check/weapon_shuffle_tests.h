#include "../../runtime/mods/weapon_shuffle.h"
inline void testWeaponShuffle() {
    using namespace reo::cheats;
    std::vector<uint8_t> ram(32 * 1024 * 1024);
    auto make = [&](unsigned h, unsigned type, unsigned index, unsigned qty) {
        auto a = 0x3c5630u + h * 60;
        ram[a] = 1; ram[a + 2] = uint8_t(h);
        setHalf(ram.data(), a + 6, uint16_t(type));
        setHalf(ram.data(), a + 0x24, uint16_t(qty));
        setWord(ram.data(), a + 0x18, 0x800);
        ram[0x74b6e0 + type] = uint8_t(index);
        auto info = 0x74bb50 + index * 24;
        setHalf(ram.data(), info + 18, uint16_t(type));
        setHalf(ram.data(), info + 8, 30);
        setWord(ram.data(), info, 0x100000);
    };
    make(1, 0, 1, 15); make(2, 4, 2, 7); make(3, 11, 3, 5);
    setWord(ram.data(), 0x3c5630 + 3 * 60 + 0x18, 0x801); // Original placement flag.
    make(4, 0x190, 4, 7); // Personal weapon.
    make(5, 0x135, 5, 1); // Non-weapon, even if its metadata has the firearm bit.
    make(6, 27, 6, 12); setHalf(ram.data(), 0x3c5630 + 6 * 60 + 0x28, 1);
    make(7, 28, 7, 12); setWord(ram.data(), 0x3c5630 + 7 * 60 + 0x18, 1);
    make(8, 29, 8, 31); // Invalid quantity.
    make(9, 100, 9, 30); make(10, 300, 10, 1); // Ammo and healing.
    make(11, 10000, 11, 1); // Scenario key, never part of the ordinary pool.
    auto initial = ram;
    auto result = reo::mods::shuffleWeapons(ram.data(), 2026);
    auto require = [](bool ok) { if (!ok) throw std::runtime_error("Weapon shuffle check failed"); };
    require(result.count == 3);
    auto repeat = initial;
    reo::mods::shuffleWeapons(repeat.data(), 2026);
    require(repeat == ram);
    bool distinct = false;
    for (unsigned seed = 0; seed < 20; ++seed) {
        auto other = initial;
        reo::mods::shuffleWeapons(other.data(), seed);
        distinct |= other != ram;
    }
    require(distinct);
    std::vector<std::pair<unsigned, unsigned>> before, after;
    for (unsigned i = 0; i < result.count; ++i) {
        before.emplace_back(result.before[i].type, result.before[i].quantity);
        after.emplace_back(result.after[i].type, result.after[i].quantity);
        auto a = result.before[i].address;
        require(half(ram.data(), 0x74bb50 + ram[a + 0x2b] * 24 + 18) == half(ram.data(), a + 6));
        // Restore exactly the permitted fields, then check all RAM for unintended writes.
        for (unsigned offset : {6u, 7u, 0x24u, 0x25u, 0x2bu}) ram[a + offset] = initial[a + offset];
    }
    std::sort(before.begin(), before.end()); std::sort(after.begin(), after.end());
    require(before == after && ram == initial);
    require(reo::mods::shuffleWeapons(nullptr, 0).count == 0);
    bool crossedCategories = false;
    for (unsigned seed = 0; seed < 20; ++seed) {
        auto full = initial;
        auto mixed = reo::mods::shufflePickups(full.data(), seed, true);
        require(mixed.count == 6);
        auto duplicate = initial;
        reo::mods::shufflePickups(duplicate.data(), seed, true);
        require(full == duplicate);
        before.clear(); after.clear();
        for (unsigned i = 0; i < mixed.count; ++i) {
            auto a = mixed.before[i].address;
            before.emplace_back(mixed.before[i].type, mixed.before[i].quantity);
            after.emplace_back(mixed.after[i].type, mixed.after[i].quantity);
            crossedCategories |= mixed.before[i].type < 100 && mixed.after[i].type >= 100;
            require(half(full.data(), 0x74bb50 + full[a + 0x2b] * 24 + 18) == half(full.data(), a + 6));
            for (unsigned offset : {6u, 7u, 0x24u, 0x25u, 0x2bu}) full[a + offset] = initial[a + offset];
        }
        std::sort(before.begin(), before.end()); std::sort(after.begin(), after.end());
        require(before == after && full == initial);
    }
    require(crossedCategories);
    const auto parsed = reo::mods::parseItemExclusions("0,309,399");
    require(parsed[0] && parsed[309] && parsed[399] && std::count(parsed.begin(), parsed.end(), true) == 3);
    for (const char* invalid : {"", "-1", "400", "0,0", "0,", ",0", "1.5", "0x10", " 1", "4294967296"}) {
        bool rejected = false;
        try { (void)reo::mods::parseItemExclusions(invalid); }
        catch (const std::runtime_error&) { rejected = true; }
        require(rejected);
    }
    reo::mods::ItemExclusions excluded{};
    excluded[0] = excluded[300] = true;
    for (unsigned seed = 0; seed < 20; ++seed) {
        auto protectedRam = initial;
        const auto protectedResult = reo::mods::shufflePickups(protectedRam.data(), seed, true, excluded);
        require(protectedResult.count == 4);
        for (unsigned h : {1u, 10u}) {
            const auto a = 0x3c5630u + h * 60;
            require(std::equal(initial.begin() + a, initial.begin() + a + 60, protectedRam.begin() + a));
        }
        for (unsigned i = 0; i < protectedResult.count; ++i)
            require(!excluded[protectedResult.before[i].type] && !excluded[protectedResult.after[i].type]);
    }
    excluded.fill(true);
    auto untouched = initial;
    require(reo::mods::shufflePickups(untouched.data(), 2027, true, excluded).count == 0);
    require(untouched == initial);
    std::cout << "PASS item exclusions preserve full records and remove contents from the pool\n";
    std::cout << "PASS item randomizer cross-category swaps, conservation, metadata, determinism and excluded keys/personal items\n";
    std::cout << "PASS weapon shuffle determinism, seed variation, supply conservation, metadata and excluded-item checks\n";
}
