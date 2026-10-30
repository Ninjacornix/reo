#pragma once
#include "data_cheats.h"

namespace reo::cheats {
enum Builtin : unsigned { FullHealth = 1, NoInfection = 2, InfiniteAmmo = 4, UnlockEverything = 8 };
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
            else if (name == "unlock")
                result.builtins |= UnlockEverything;
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
    bool unlocks = false;
    unsigned player = 0, health = 0, maximum = 0, ammunitionSlots = 0;
    uint32_t virus = 0;
};
enum class Game { File1, File2 };
inline void unlockFile2(uint8_t* r) {
    // SLUS-20984 v1.05: original 13C190/13C110 full-unlock routines,
    // with tables at 217878/217880/217890/2178B0. Keep other records,
    // reward points and selected options intact. Do not directly write the
    // secondary scenario-availability bank at 2FF8C8.
    constexpr uint8_t costumes[8] = {3, 3, 3, 3, 3, 15, 15, 15};
    constexpr uint32_t npcs[4] = {
        0x72400c40u | 0x098ff082u, 0xff03c200u | 0x00d80df8u,
        0x03ffc0fbu | 0x1c000000u, 0u
    };
    constexpr unsigned collectionCounts[5] = {145, 59, 146, 14, 11};
    for (unsigned i = 0; i < 8; ++i) r[0x2feea8 + i] |= costumes[i];
    for (unsigned i = 0; i < 4; ++i)
        setWord(r, 0x2feeb0 + 4 * i, word(r, 0x2feeb0 + 4 * i) | npcs[i]);
    r[0x2feec5] |= 0x0f; // All four difficulties; preserve other bits.
    r[0x2feec3] |= 0x0d; // Purchased bonus-mode availability, not active mode.
    setWord(r, 0x30022c, word(r, 0x30022c) | 0x0fffu);
    // Five banks of 160 bits; only the real entries are available/purchased.
    for (unsigned bank = 0; bank < 5; ++bank)
        for (unsigned bit = 0; bit < collectionCounts[bank]; ++bit) {
            const unsigned offset = bank * 20 + bit / 8;
            const uint8_t mask = uint8_t(1u << (bit % 8));
            r[0x300248 + offset] |= mask;
            r[0x3002ac + offset] |= mask;
        }
}
inline BuiltinResult applyBuiltins(unsigned flags, uint8_t* r, Game game = Game::File1) {
    BuiltinResult result;
    if (!flags || !r)
        return result;
    const bool file2 = game == Game::File2;
    if (file2 && (flags & UnlockEverything)) {
        unlockFile2(r);
        result.unlocks = true;
    }
    if (!file2 && (flags & UnlockEverything)) {
        // Verified NTSC-U v2.00 save/progression fields. The scenario menu
        // 581820 tests +4078 in the save structure rooted at 31FB60; the
        // difficulty menu 587640 tests bits 2/3 at +23.
        setWord(r, 0x323bd8, word(r, 0x323bd8) | 0x1fu);
        // Costume and NPC bitsets, without touching reward points or options.
        for (uint32_t a = 0x31fb64; a < 0x31fb6c; ++a) r[a] = 0xff;
        for (uint32_t a = 0x31fb6d; a < 0x31fb79; ++a) r[a] = 0xff;
        r[0x31fb83] |= 0x0c;
        r[0x31fb7f] |= 0x05; // Purchased bonus-mode availability, not current mode.
        // 57C4C0/57C530: available/purchased collection bits, three banks
        // at a 32-byte stride. Leave each bank's padding and other records alone.
        for (uint32_t bank = 0; bank < 3; ++bank)
            for (uint32_t offset = 0; offset < 24; ++offset) {
                r[0x323bf4 + bank * 32 + offset] = 0xff;
                r[0x323c54 + bank * 32 + offset] = 0xff;
            }
        result.unlocks = true;
    }
    const uint32_t state = file2 ? 0x4db390u : 0x4badd0u;
    if (r[state] != 2 || r[state + 0x1d] >= 4)
        return result;
    const unsigned player = r[state + 0x1d];
    // SLUS-20984 v1.05: 609F38..609F50 actor table/stride,
    // 6102C0 dead flag, 684F2C virus, 5A1318 inventory handles.
    const uint32_t actor = file2 ? 0x4c5e10u + player * 0x1100u
                                : 0x4a5c30u + player * 0x10e0u;
    const uint32_t dead = file2 ? 0xbe8u : 0xbd0u;
    const uint32_t virus = file2 ? 0xbc4u : 0xbacu;
    const uint32_t inventory = file2 ? 0xc94u : 0xc84u;
    const uint32_t health = file2 ? 0x540u : 0x544u;
    const int16_t hp = int16_t(half(r, actor + health)), maximum = int16_t(half(r, actor + health + 2));
    if (!r[actor] || r[actor + dead] || r[actor + 8] == 4 || hp <= 0 || maximum <= 0)
        return result;
    result.active = true;
    result.player = player;
    // Original actor HP/max fields; only the selected, living player is touched.
    if ((flags & FullHealth) && hp < maximum)
        setHalf(r, actor + health, uint16_t(maximum));
    // Original 667F90 computes gauge = actor.BAC / character limit * 100.
    if (flags & NoInfection)
        setWord(r, actor + virus, 0);
    if (flags & InfiniteAmmo) {
        // Four inventory handles plus the character's personal weapon slot.
        for (unsigned slot = 0; slot < 5; ++slot) {
            const unsigned handle = r[actor + inventory + slot];
            if (!handle)
                continue;
            const uint32_t item = (file2 ? 0x3e1c20u : 0x3c5630u) + handle * 60u;
            const unsigned index = r[item + 0x2b];
            // File #2 loads its catalogue count at 5B0640; never index
            // beyond the byte-addressable table, even with malformed data.
            const unsigned count = file2 ? half(r, 0x7ada20) : 129;
            if (r[item] != 1 || r[item + 2] != handle || count > 256 || index >= count)
                continue;
            const uint32_t info = (file2 ? 0x7aca00u : 0x74bb50u) + index * 24u;
            const unsigned type = half(r, item + 6), capacity = half(r, info + 8);
            // Metadata identity and firearm category exclude consumables/keys/melee.
            // Ordinary guns use decimal IDs below 100; personal guns include
            // 400/401. Weapon + loaded-ammunition metadata, excluding common
            // items, distinguishes both from ammo boxes, healing and melee.
            if (type >= 600 || half(r, info + 18) != type ||
                (word(r, info) & 0x100005u) != 0x100001u || !capacity || capacity > 999)
                continue;
            const int16_t current = int16_t(half(r, item + 0x24));
            if (current < 0 || current > int(capacity))
                continue;
            setHalf(r, item + 0x24, uint16_t(capacity));
            ++result.ammunitionSlots;
        }
    }
    result.health = half(r, actor + health);
    result.maximum = unsigned(maximum);
    result.virus = word(r, actor + virus);
    return result;
}
} // namespace reo::cheats
