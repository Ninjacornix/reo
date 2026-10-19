#pragma once
#include "data_cheats.h"

namespace reo::cheats {
enum Builtin : unsigned { FullHealth = 1, NoInfection = 2, InfiniteAmmo = 4 };
struct Program {
    std::vector<Write> writes;
    unsigned builtins = 0;
};
inline Program parseProgram(std::istream& input) {
    std::string header;
    std::getline(input, header);
    if (header != "REO-CHEATS-1" && header != "REO-CHEATS-2")
        throw std::runtime_error("Invalid cheat manifest version");
    Program result;
    std::ostringstream numeric;
    numeric << "REO-CHEATS-1\n";
    std::string line;
    size_t bytes = 0;
    while (std::getline(input, line)) {
        bytes += line.size();
        if (bytes > 1024 * 1024)
            throw std::runtime_error("Cheat manifest too large");
        if (header == "REO-CHEATS-2" && line.rfind("builtin ", 0) == 0) {
            const auto name = line.substr(8);
            if (name == "health")
                result.builtins |= FullHealth;
            else if (name == "infection")
                result.builtins |= NoInfection;
            else if (name == "ammo")
                result.builtins |= InfiniteAmmo;
            else
                throw std::runtime_error("Unknown built-in cheat");
        } else
            numeric << line << '\n';
    }
    std::istringstream rows(numeric.str());
    result.writes = parse(rows);
    return result;
}
inline uint16_t half(const uint8_t* r, uint32_t a) {
    uint16_t v;
    std::memcpy(&v, r + a, 2);
    return v;
}
inline uint32_t word(const uint8_t* r, uint32_t a) {
    uint32_t v;
    std::memcpy(&v, r + a, 4);
    return v;
}
inline void setHalf(uint8_t* r, uint32_t a, uint16_t v) {
    std::memcpy(r + a, &v, 2);
}
inline void setWord(uint8_t* r, uint32_t a, uint32_t v) {
    std::memcpy(r + a, &v, 4);
}
struct BuiltinResult {
    bool active = false;
    unsigned player = 0, health = 0, maximum = 0, ammunitionSlots = 0;
    uint32_t virus = 0;
};
inline BuiltinResult applyBuiltins(unsigned flags, uint8_t* r) {
    BuiltinResult result;
    if (!flags || !r || r[0x4badd0] != 2 || r[0x4baded] >= 4)
        return result;
    const unsigned player = r[0x4baded];
    const uint32_t actor = 0x4a5c30u + player * 0x10e0u;
    const int16_t hp = int16_t(half(r, actor + 0x544)), maximum = int16_t(half(r, actor + 0x546));
    if (!r[actor] || r[actor + 0xbd0] || r[actor + 8] == 4 || hp <= 0 || maximum <= 0)
        return result;
    result.active = true;
    result.player = player;
    // Original actor HP/max fields; only the selected, living player is touched.
    if ((flags & FullHealth) && hp < maximum)
        setHalf(r, actor + 0x544, uint16_t(maximum));
    // Original 667F90 computes gauge = actor.BAC / character limit * 100.
    if (flags & NoInfection)
        setWord(r, actor + 0xbac, 0);
    if (flags & InfiniteAmmo) {
        // Four inventory handles plus the character's personal weapon slot.
        for (unsigned slot = 0; slot < 5; ++slot) {
            const unsigned handle = r[actor + 0xc84 + slot];
            if (!handle)
                continue;
            const uint32_t item = 0x3c5630u + handle * 60u;
            const unsigned index = r[item + 0x2b];
            if (r[item] != 1 || r[item + 2] != handle || index == 255)
                continue;
            const uint32_t info = 0x74bb50u + index * 24u;
            const unsigned type = half(r, item + 6), capacity = half(r, info + 8);
            // Metadata identity and firearm category exclude consumables/keys/melee.
            if (type < 0x100 || type >= 0x200 || half(r, info + 18) != type ||
                !(word(r, info) & 0x100000u) || !capacity || capacity > 999)
                continue;
            const int16_t current = int16_t(half(r, item + 0x24));
            if (current < 0 || current > int(capacity))
                continue;
            setHalf(r, item + 0x24, uint16_t(capacity));
            ++result.ammunitionSlots;
        }
    }
    result.health = half(r, actor + 0x544);
    result.maximum = unsigned(maximum);
    result.virus = word(r, actor + 0xbac);
    return result;
}
} // namespace reo::cheats
