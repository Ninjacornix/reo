#pragma once
#include "../cheats/outbreak_cheats.h"
#include <array>
#include <algorithm>
#include <charconv>
#include <string_view>
#include <stdexcept>

namespace reo::mods {
// Versioned, portable PRNG: seeds reproduce the permutation on every host.
inline uint32_t next(uint32_t& state) {
    state += 0x9e3779b9u;
    uint32_t z = state;
    z = (z ^ (z >> 16)) * 0x85ebca6bu;
    z = (z ^ (z >> 13)) * 0xc2b2ae35u;
    return z ^ (z >> 16);
}
struct Pickup { uint32_t address; uint16_t type, quantity; uint8_t metadata; };
struct ShuffleResult {
    std::array<Pickup, 255> before{}, after{};
    unsigned count = 0, changed = 0;
};
using ItemExclusions = std::array<bool, 400>;
inline ItemExclusions parseItemExclusions(std::string_view value) {
    ItemExclusions result{};
    if (value.empty()) throw std::runtime_error("Invalid item randomizer exclusion list");
    while (!value.empty()) {
        unsigned type = 400;
        const char* end = value.data() + value.size();
        const auto parsed = std::from_chars(value.data(), end, type);
        if (parsed.ec != std::errc{} || type >= result.size() || result[type] ||
            (parsed.ptr != end && *parsed.ptr != ','))
            throw std::runtime_error("Invalid item randomizer exclusion list");
        result[type] = true;
        if (parsed.ptr == end) break;
        value.remove_prefix(size_t(parsed.ptr - value.data()) + 1);
        if (value.empty()) throw std::runtime_error("Invalid item randomizer exclusion list");
    }
    return result;
}
inline ShuffleResult shufflePickups(uint8_t* ram, uint32_t seed, bool allOrdinaryItems,
                                   const ItemExclusions& excluded = {}) {
    using namespace reo::cheats;
    ShuffleResult result;
    if (!ram) return result;
    for (unsigned handle = 1; handle < 256; ++handle) {
        const uint32_t a = 0x3c5630u + handle * 60u;
        const unsigned type = half(ram, a + 6);
        // Ordinary item IDs are below 400; personal items start at 400 and
        // scenario-key IDs use the 10000+ lookup range. Legacy mode restricts
        // this pool further to firearms. Owned/scripted grants stay intact.
        // 592370 marks placed records with bit 0 after the table loader sets 0x800.
        if (ram[a] != 1 || ram[a + 2] != handle || (word(ram, a + 0x18) & ~1u) != 0x800 ||
            half(ram, a + 0x28) != 0 || type >= (allOrdinaryItems ? 400u : 100u)) continue;
        // Remove both the location and its contents from the permutation.
        if (excluded[type]) continue;
        const unsigned index = ram[0x74b6e0u + type];
        if (index >= 129) continue;
        const uint32_t info = 0x74bb50u + index * 24u;
        const unsigned capacity = half(ram, info + 8), quantity = half(ram, a + 0x24);
        if (half(ram, info + 18) != type || !word(ram, info) || quantity > 32767) continue;
        const bool firearm = type < 100 && (word(ram, info) & 0x100000u);
        if (!allOrdinaryItems && !firearm) continue;
        if (firearm && (capacity == 0 || capacity > 999 || quantity > capacity)) continue;
        result.before[result.count++] = {a, uint16_t(type), uint16_t(quantity), uint8_t(index)};
    }
    result.after = result.before;
    for (unsigned i = result.count; i > 1; --i)
        std::swap(result.after[i - 1], result.after[next(seed) % i]);
    for (unsigned i = 0; i < result.count; ++i) {
        const auto& old = result.before[i];
        auto& replacement = result.after[i];
        replacement.address = old.address;
        if (old.type != replacement.type || old.quantity != replacement.quantity) ++result.changed;
        setHalf(ram, old.address + 6, replacement.type);
        setHalf(ram, old.address + 0x24, replacement.quantity);
        ram[old.address + 0x2b] = replacement.metadata;
    }
    return result;
}
inline ShuffleResult shuffleWeapons(uint8_t* ram, uint32_t seed) {
    return shufflePickups(ram, seed, false);
}
} // namespace reo::mods
