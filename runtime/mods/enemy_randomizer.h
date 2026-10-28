#pragma once
#include "weapon_shuffle.h"

namespace reo::mods {
struct ZombieProfile { uint32_t address; uint8_t room, variant, mode; uint16_t health, maximum; };
struct EnemyShuffleResult {
    std::array<ZombieProfile, 255> before{}, after{};
    unsigned count = 0, changed = 0;
};
inline bool supportedZombieVariant(unsigned variant) {
    // Variants observed in the supported File #1 scenario table. In particular,
    // 85 is a special scripted variant and must not enter the ordinary pool.
    switch (variant) {
        case 0: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
        case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
        case 48: case 49: case 50: case 51: case 52: case 57: case 58: return true;
        default: return false;
    }
}
struct ZombieShuffleFilter {
    std::array<bool,256> behaviors{}, variants{};
};
inline EnemyShuffleResult shuffleZombieProfiles(uint8_t* ram, uint32_t seed,
                                                const ZombieShuffleFilter* filter=nullptr) {
    using namespace reo::cheats;
    EnemyShuffleResult result;
    if (!ram) return result;
    const unsigned count = ram[gameLayout.spawnCount];
    for (unsigned i = 0; i < count; ++i) {
        const uint32_t a = gameLayout.spawnTable + i * 96;
        const auto health = half(ram, a + 0x1c), maximum = half(ram, a + 0x1e);
        if(filter && (!filter->behaviors[ram[a+0x2a]] || !filter->variants[ram[a+3]])) continue;
        // 6BAA40 builds the scenario records; 6BB040 creates actors from them.
        // Both room-local (0) and tracked (1) entries use 6BBDA0 to copy the
        // variant/health. Keep those two lifecycle groups separate. Leave other
        // modes, special variants, dead records and other enemy families intact.
        if (ram[a] != i || ram[a + 2] != 1 || ram[a + 0x26] > 1 ||
            !supportedZombieVariant(ram[a + 3]) || !ram[a + 0x22] ||
            !health || health != maximum || maximum >= 32767) continue;
        result.before[result.count++] = {a, ram[a + 0x22], ram[a + 3], ram[a + 0x26], health, maximum};
    }
    result.after = result.before;
    // Keep each room's existing model set and total health supply. Separate PRNG
    // streams mean changes in one room do not perturb another room's shuffle.
    for (unsigned group = 2; group < 512; ++group) {
        std::array<unsigned, 255> indices{};
        unsigned n = 0;
        for (unsigned i = 0; i < result.count; ++i)
            if (unsigned(result.before[i].room) * 2 + result.before[i].mode == group) indices[n++] = i;
        uint32_t state = seed ^ (group * 0x9e3779b9u);
        for (unsigned i = n; i > 1; --i)
            std::swap(result.after[indices[i - 1]], result.after[indices[next(state) % i]]);
    }
    for (unsigned i = 0; i < result.count; ++i) {
        const auto& old = result.before[i];
        auto& replacement = result.after[i];
        replacement.address = old.address;
        if (old.variant != replacement.variant || old.health != replacement.health) ++result.changed;
        ram[old.address + 3] = replacement.variant;
        setHalf(ram, old.address + 0x1c, replacement.health);
        setHalf(ram, old.address + 0x1e, replacement.maximum);
    }
    return result;
}
}
