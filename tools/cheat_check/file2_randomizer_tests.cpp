#include "../../runtime/mods/global_items.h"
#include "../../runtime/mods/enemy_randomizer.h"
#include "../../runtime/mods/enemy_spawn_randomizer.h"
#include <iostream>
#include <tuple>

#ifndef REO_GAME_FILE2
#error These fixtures must be compiled for File #2.
#endif
using namespace reo::mods;
using namespace reo::cheats;
namespace {
unsigned checks;
void require(bool ok, const char* message) {
    if (!ok) throw std::runtime_error(message);
    ++checks;
}
// Independent SLUS-20984 v1.05 constants: do not derive fixtures from the
// implementation's layout. Wrong-game addresses must fail these checks.
constexpr uint32_t pool = 0x3e1c20, lookup = 0x7ac590, metadata = 0x7aca00;
constexpr uint32_t metadataCount = 0x7ada20, recipes = 0x7ad660;
constexpr uint32_t spawns = 0x7aff80, spawnCount = 0x4db44e;
constexpr uint32_t scenario = 0x30095a, roomAddress = 0x30095c;
constexpr uint32_t enemyBase = 0x44de90, enemyStride = 0xdb0;
constexpr uint32_t enemySpawn = 0xbb0, enemyBehavior = 0xc48;
constexpr uint32_t enemyModel = 0xbd2, enemyHealth = 0x540, enemyMaximum = 0x542;
constexpr uint32_t sharedTypes = 0x765f40;
using Ram = std::vector<uint8_t>;
uint32_t item(unsigned handle) { return pool + handle * 60; }
void definition(Ram& r, unsigned index, unsigned type, uint32_t flags, unsigned capacity) {
    const auto a = metadata + index * 24;
    setWord(r.data(), a, flags); setHalf(r.data(), a + 4, 65535);
    setHalf(r.data(), a + 8, uint16_t(capacity)); setHalf(r.data(), a + 18, uint16_t(type));
    if (type < 600) r[lookup + type] = uint8_t(index);
}
void pickup(Ram& r, unsigned handle, unsigned type, unsigned index, unsigned quantity = 1) {
    const auto a = item(handle);
    r[a] = 1; r[a + 2] = uint8_t(handle);
    setWord(r.data(), a + 0x18, 0x800); setHalf(r.data(), a + 6, uint16_t(type));
    setHalf(r.data(), a + 0x24, uint16_t(quantity)); r[a + 0x2b] = uint8_t(index);
}
void itemRules() {
    Ram r(32 * 1024 * 1024);
    std::fill_n(r.begin() + lookup, 600, 255);
    definition(r, 0, 0, 0x102001, 15); definition(r, 1, 20, 0x104001, 1);
    definition(r, 2, 200, 0x100400, 60); definition(r, 3, 250, 0x100002, 255);
    definition(r, 4, 300, 0x40004, 1); definition(r, 5, 309, 0x140005, 1);
    definition(r, 6, 400, 0x102041, 7); definition(r, 7, 312, 0x40004, 1);
    definition(r, 8, 450, 8, 1); definition(r, 9, 10100, 0x8040200, 1);
    definition(r, 10, 310, 0x8040004, 1); setHalf(r.data(), metadataCount, 11);
    for (unsigned i = 0; i < 11; ++i)
        pickup(r, i + 1, half(r.data(), metadata + i * 24 + 18), i);
    pickup(r, 12, 0, 0); setHalf(r.data(), item(12) + 0x28, 1); // Owned/starting item.
    pickup(r, 13, 20, 1); setWord(r.data(), item(13) + 0x18, 1); // Scripted grant.
    const auto initial = r;
    bool varied = false;
    Ram first;
    for (uint32_t seed : {0u, 1u, 43u, 2031u, 0xffffffffu}) {
        r = initial; auto repeat = initial;
        const auto result = randomizeGlobalPickups(r.data(), seed);
        randomizeGlobalPickups(repeat.data(), seed);
        require(result.count == 6 && repeat == r, "File2 global eligible set/determinism");
        if (first.empty()) first = r; else varied |= first != r;
        for (unsigned i = 0; i < result.count; ++i) {
            const auto& before = result.before[i]; const auto& after = result.after[i];
            require(itemCategory(before.type, word(initial.data(), metadata + before.metadata * 24)) ==
                    itemCategory(after.type, word(r.data(), metadata + after.metadata * 24)), "Category crossover");
            require(after.quantity > 0 && half(r.data(), metadata + after.metadata * 24 + 18) == after.type,
                    "Invalid quantity or metadata identity");
            for (unsigned offset : {6u, 7u, 0x24u, 0x25u, 0x2bu}) r[before.address + offset] = initial[before.address + offset];
        }
        require(r == initial, "Global randomizer changed protected records or unrelated RAM");
        ItemExclusions exclusions{}; exclusions[0] = exclusions[309] = true;
        r = initial; const auto excluded = randomizeGlobalPickups(r.data(), seed, exclusions);
        // Removing spray leaves no alternative common item for the herb;
        // unchanged locations are intentionally absent from this result.
        require(excluded.count == 3, "Exclusion candidate accounting differs");
        for (unsigned h : {1u, 6u})
            require(std::equal(r.begin() + item(h), r.begin() + item(h) + 60, initial.begin() + item(h)), "Excluded pickup changed");
        for (unsigned i = 0; i < excluded.count; ++i)
            require(!exclusions[excluded.after[i].type], "Excluded contents re-entered candidate pool");
    }
    require(varied, "Different seeds never vary");
    // Legacy weapon mode must conserve each weapon's loaded quantity.
    r = initial; auto shuffled = shuffleWeapons(r.data(), 43);
    require(shuffled.count == 2, "Weapon shuffle included personal/owned/scripted items");
    std::vector<std::pair<unsigned, unsigned>> before, after;
    for (unsigned i = 0; i < shuffled.count; ++i) {
        before.emplace_back(shuffled.before[i].type, shuffled.before[i].quantity);
        after.emplace_back(shuffled.after[i].type, shuffled.after[i].quantity);
        for (unsigned o : {6u, 7u, 0x24u, 0x25u, 0x2bu}) r[shuffled.before[i].address + o] = initial[shuffled.before[i].address + o];
    }
    std::sort(before.begin(), before.end()); std::sort(after.begin(), after.end());
    require(before == after && r == initial, "Weapon quantities or unrelated RAM changed");
    // Appending a missing global definition preserves progression metadata and
    // the exact recipe range already referenced by a key item.
    setHalf(r.data(), metadata + 9 * 24 + 4, 381); r[metadata + 9 * 24 + 6] = 1;
    for (unsigned j = 0; j < 3; ++j) setHalf(r.data(), recipes + (381 + j) * 2, uint16_t(123 + j));
    const auto original = r;
    CatalogueItem added; added.type = 11;
    setWord(added.metadata.data(), 0, 0x104001); setHalf(added.metadata.data(), 8, 7);
    setHalf(added.metadata.data(), 18, 11); added.combinations.push_back({200, 11, 1});
    require(installItemCatalogue(r.data(), {added}) == 12, "File2 catalogue append failed");
    require(std::equal(r.begin() + metadata + 9 * 24, r.begin() + metadata + 10 * 24, original.begin() + metadata + 9 * 24), "Key metadata changed");
    require(std::equal(r.begin() + recipes + 381 * 2, r.begin() + recipes + 384 * 2, original.begin() + recipes + 381 * 2), "Key recipe changed");
    require(std::equal(r.begin() + pool, r.begin() + pool + 256 * 60, original.begin() + pool), "Catalogue installation altered pickups");
}
void cataloguePreservation() {
    Ram r(32 * 1024 * 1024);
    std::fill_n(r.begin() + lookup, 600, 255);
    definition(r, 0, 0, 0x102001, 15); definition(r, 1, 20, 0x104001, 1);
    definition(r, 2, 200, 0x100400, 60); definition(r, 3, 300, 0x40004, 1);
    definition(r, 4, 400, 0x102041, 7); definition(r, 5, 10100, 0x8040200, 1);
    setHalf(r.data(), metadataCount, 6);
    // Occupy every native recipe halfword. Both ordinary and protected recipes
    // extend above the old File #1 limit, including the final triple 477..479.
    for (unsigned i = 0; i < 480; ++i) setHalf(r.data(), recipes + i * 2, uint16_t(1000 + i));
    for (auto [index, start, triples] : std::array<std::array<unsigned, 3>, 5>{{
            {0, 0, 128}, {1, 0, 128}, {2, 384, 30}, {4, 474, 1}, {5, 477, 1}}}) {
        setHalf(r.data(), metadata + index * 24 + 4, uint16_t(start));
        r[metadata + index * 24 + 6] = uint8_t(triples);
    }
    for (unsigned i = 0; i < 6; ++i) {
        setWord(r.data(), 0x7ac7f0 + i * 4, 0x3f000001 + i);
        for (unsigned j = 0; j < 8; ++j) r[0x7ac180 + i * 8 + j] = uint8_t(i * 8 + j + 1);
    }
    const auto original = r;
    require(installItemCatalogue(r.data(), {}) == 6 && r == original, "Zero-entry catalogue changed RAM");
    CatalogueItem existingOrdinary, existingPersonal, added;
    auto populate = [](CatalogueItem& c, unsigned type, uint32_t flags, unsigned capacity) {
        c.type = uint16_t(type); setWord(c.metadata.data(), 0, flags);
        setHalf(c.metadata.data(), 8, uint16_t(capacity)); setHalf(c.metadata.data(), 18, uint16_t(type));
    };
    populate(existingOrdinary, 0, 0x102001, 15); existingOrdinary.combinations.push_back({9, 9, 9});
    populate(existingPersonal, 400, 0x102041, 7); existingPersonal.combinations.push_back({8, 8, 8});
    populate(added, 11, 0x104001, 7); added.combinations.push_back({1477, 1478, 1479});
    require(installItemCatalogue(r.data(), {existingOrdinary, existingPersonal, added}) == 7,
            "Missing-only catalogue did not preserve existing indices");
    require(std::equal(r.begin() + metadata, r.begin() + metadata + 6 * 24, original.begin() + metadata),
            "Existing ordinary/key/personal metadata was rewritten");
    require(std::equal(r.begin() + recipes, r.begin() + recipes + 480 * 2, original.begin() + recipes),
            "Existing ordinary/key/personal recipe words were overwritten");
    require(half(r.data(), metadata + 6 * 24 + 4) == 477 && r[metadata + 6 * 24 + 6] == 1,
            "Identical recipe did not reuse the original upper-buffer triple");
    for (unsigned index = 0; index < 6; ++index) {
        require(word(r.data(), 0x7ac7f0 + index * 4) == word(original.data(), 0x7ac7f0 + index * 4), "Existing scale changed");
        require(std::equal(r.begin() + 0x7ac180 + index * 8, r.begin() + 0x7ac180 + (index + 1) * 8,
                           original.begin() + 0x7ac180 + index * 8), "Existing priority changed");
    }
    auto restored = r;
    for (unsigned j = 0; j < 24; ++j) restored[metadata + 6 * 24 + j] = original[metadata + 6 * 24 + j];
    for (unsigned j = 0; j < 4; ++j) restored[0x7ac7f0 + 6 * 4 + j] = original[0x7ac7f0 + 6 * 4 + j];
    for (unsigned j = 0; j < 8; ++j) restored[0x7ac180 + 6 * 8 + j] = original[0x7ac180 + 6 * 8 + j];
    restored[lookup + 11] = original[lookup + 11]; setHalf(restored.data(), metadataCount, 6);
    require(restored == original, "Catalogue append wrote outside the new definition/index fields");
    // Parse the actual zero-entry on-disk format, rather than passing only an
    // empty C++ vector. Then use the unchanged native definitions to randomize.
    const auto path = std::filesystem::path("build-ninja/cheat-check/file2-empty-catalogue.bin");
    {
        std::ofstream output(path, std::ios::binary);
        const char bytes[12] = {'R','G','I','C','1',0,0,0,0,0,0,0};
        output.write(bytes, sizeof(bytes));
    }
    const auto loaded = readItemCatalogue(path.string().c_str()); std::filesystem::remove(path);
    require(loaded.empty(), "File2 rejected valid zero-entry catalogue");
    r = original; require(installItemCatalogue(r.data(), loaded) == 6 && r == original,
                          "Parsed zero-entry catalogue changed native definitions");
    pickup(r, 1, 0, 0); pickup(r, 2, 200, 2); pickup(r, 3, 300, 3);
    // Add native alternatives without requiring any appended catalogue rows.
    definition(r, 6, 250, 0x100002, 255); definition(r, 7, 309, 0x140005, 1);
    setHalf(r.data(), metadataCount, 8);
    const auto shuffled = randomizeGlobalPickups(r.data(), 43);
    require(shuffled.count == 3, "Zero-entry catalogue disabled existing native category pools");
    require(itemCategory(shuffled.after[0].type, word(r.data(), metadata + shuffled.after[0].metadata * 24)) == ItemCategory::Weapon &&
            itemCategory(shuffled.after[1].type, word(r.data(), metadata + shuffled.after[1].metadata * 24)) == ItemCategory::Ammunition &&
            itemCategory(shuffled.after[2].type, word(r.data(), metadata + shuffled.after[2].metadata * 24)) == ItemCategory::Common,
            "Zero-entry catalogue changed category boundaries");
}
void floorModelRules() {
    Ram r(32 * 1024 * 1024);
    std::fill_n(r.begin() + lookup, 600, 255);
    definition(r, 0, 0, 0x102001, 15); definition(r, 1, 20, 0x104001, 1);
    definition(r, 2, 28, 0x108001, 5);
    definition(r, 3, 200, 0x100400, 60); definition(r, 4, 250, 0x100002, 255);
    definition(r, 5, 251, 0x100002, 255); definition(r, 6, 203, 0x100400, 60);
    definition(r, 7, 300, 0x40004, 1); definition(r, 8, 309, 0x140005, 1);
    definition(r, 9, 315, 0x40004, 1); definition(r, 10, 317, 0x40004, 1);
    setHalf(r.data(), metadataCount, 11);
    pickup(r, 1, 0, 0); pickup(r, 2, 200, 3); pickup(r, 3, 300, 7);
    pickup(r, 4, 315, 9); pickup(r, 5, 317, 10); pickup(r, 6, 28, 2);
    const auto original = r;
    ItemAvailability ready{};
    for (unsigned type : {0u, 20u, 200u, 250u, 251u, 300u, 309u}) ready[type] = 1;
    bool ammunitionAliasSeen = false, newlyAvailableAliasSeen = false;
    for (uint32_t seed = 0; seed < 32; ++seed) {
        r = original;
        const auto result = randomizeGlobalPickups(r.data(), seed, {}, &ready);
        require(result.count == 3, "Unavailable floor source was randomized");
        for (unsigned handle : {4u, 5u, 6u})
            require(std::equal(r.begin() + item(handle), r.begin() + item(handle) + 60, original.begin() + item(handle)),
                    "Unavailable floor source record changed");
        for (unsigned i = 0; i < result.count; ++i) {
            require(ready[result.before[i].type] && ready[result.after[i].type], "Unavailable floor candidate was chosen");
            ammunitionAliasSeen |= result.after[i].type == 251;
            for (unsigned offset : {6u, 7u, 0x24u, 0x25u, 0x2bu})
                r[result.before[i].address + offset] = original[result.before[i].address + offset];
        }
        require(r == original, "Floor availability filtering changed unrelated RAM");
        // Availability is generated from the actual model/alias lookup. If a
        // donor bank later supplies a canonical alias for 315, the same numeric
        // type becomes eligible without adding a hardcoded type exception.
        auto withAlias = ready; withAlias[315] = 1;
        r = original;
        const auto aliased = randomizeGlobalPickups(r.data(), seed, {}, &withAlias);
        require(aliased.count == 4, "Available canonical alias did not enable its source");
        for (unsigned i = 0; i < aliased.count; ++i) {
            require(withAlias[aliased.after[i].type], "Alias-enabled pool admitted an unavailable candidate");
            newlyAvailableAliasSeen |= aliased.after[i].type == 315;
            for (unsigned offset : {6u, 7u, 0x24u, 0x25u, 0x2bu})
                r[aliased.before[i].address + offset] = original[aliased.before[i].address + offset];
        }
        require(r == original, "Alias-enabled floor filtering changed protected records");
    }
    require(ammunitionAliasSeen && newlyAvailableAliasSeen, "Available alias candidates never reached a seeded pool");
    r = original;
    require(randomizeGlobalPickups(r.data(), 43).count == 6, "Null availability unexpectedly filtered native definitions");
}
void enemyRules() {
    Ram r(32 * 1024 * 1024);
    auto make = [&](unsigned id, unsigned room, unsigned model, unsigned hp, unsigned mode = 0) {
        const auto a = spawns + id * 96;
        r[a] = uint8_t(id); r[a + 2] = 1; r[a + 3] = uint8_t(model);
        r[a + 0x22] = uint8_t(room); r[a + 0x26] = uint8_t(mode);
        setHalf(r.data(), a + 0x1c, uint16_t(hp)); setHalf(r.data(), a + 0x1e, uint16_t(hp));
    };
    r[spawnCount] = 10;
    make(0, 1, 9, 700); make(1, 1, 11, 850); make(2, 2, 12, 600); make(3, 2, 13, 800);
    make(4, 1, 14, 500, 1); make(5, 1, 15, 900, 1);
    make(6, 1, 85, 750); make(7, 1, 9, 700, 2); make(8, 1, 9, 0); make(9, 1, 9, 700);
    setHalf(r.data(), spawns + 9 * 96 + 0x1c, 600);
    const auto initial = r;
    bool varied = false;
    for (unsigned seed : {0u, 1u, 2031u, 0xffffffffu}) {
        r = initial; auto again = initial;
        const auto result = shuffleZombieProfiles(r.data(), seed); shuffleZombieProfiles(again.data(), seed);
        require(result.count == 6 && r == again, "File2 zombie eligible set/determinism"); varied |= result.changed > 0;
        using Profile = std::tuple<unsigned, unsigned, unsigned, unsigned, unsigned>;
        std::vector<Profile> before, after;
        for (unsigned i = 0; i < result.count; ++i) {
            const auto& a = result.before[i]; const auto& b = result.after[i];
            before.emplace_back(a.room, a.mode, a.variant, a.health, a.maximum);
            after.emplace_back(b.room, b.mode, b.variant, b.health, b.maximum);
            for (unsigned offset : {3u, 0x1cu, 0x1du, 0x1eu, 0x1fu}) r[a.address + offset] = initial[a.address + offset];
        }
        std::sort(before.begin(), before.end()); std::sort(after.begin(), after.end());
        require(before == after && r == initial, "Zombie room/lifecycle supply or protected state changed");
    }
    require(varied, "Zombie seed never changes profiles");
    const auto planPool = parseSpawnPool("1:9:700:0:0:1;2:1:300:0:0:3;0:0:700:0:0:3;22:0:1200:0:0:3;5:0:50:0:0:3;7:0:600:0:0:3;6:0:150:0:0:3;26:0:1500:0:0:3", "0,9");
    std::fill(r.begin(), r.end(), 0); r[spawnCount] = 32; setHalf(r.data(), scenario, 6);
    setWord(r.data(), sharedTypes, 2);
    for (unsigned i = 0; i < 32; ++i) make(i, i / 16 + 1, 9, 700);
    r[spawns + 29 * 96 + 0x2a] = 9; r[spawns + 30 * 96 + 0x26] = 2;
    setHalf(r.data(), spawns + 31 * 96 + 0x1c, 0);
    const auto source = r;
    std::array<bool, MaxSpawnProfiles> supported{}; supported.fill(true);
    std::array<int, 256> previous{}; bool seedVariation = false;
    for (uint32_t seed : {0u, 1u, 43u, 2031u, 0xffffffffu}) {
        r = source; SpawnDecisions host, client;
        host.prepare(r.data(), seed, planPool, supported); client.prepare(r.data(), seed, planPool, supported);
        require(host.profiles == client.profiles && r == source, "Planning mutates RAM or differs across peers");
        seedVariation |= seed != 0 && host.profiles != previous; previous = host.profiles;
        require(host.profiles[30] == -1 && host.profiles[31] == -1, "Dead/special-lifecycle source randomized");
        require(host.scripted[29] && host.profiles[29] >= 0 && planPool.profiles[host.profiles[29]].type == 1,
                "Scripted source changed native species");
        for (unsigned room = 1; room <= 2; ++room) {
            std::set<unsigned> families{1};
            for (unsigned id = (room - 1) * 16; id < room * 16; ++id)
                if (host.profiles[id] >= 0) families.insert(planPool.profiles[host.profiles[id]].type);
            require(families.size() <= 6, "Room exceeded six animation families");
        }
        std::array<int, 32> forward{}, reverse{}; auto unavailable = supported; unavailable.fill(false);
        for (unsigned id = 0; id < 32; ++id) {
            const auto actor = enemyBase + (id % 40) * enemyStride;
            r[actor + enemySpawn] = uint8_t(id); r[actor + enemyBehavior] = 0;
            forward[id] = host.pick(r.data(), actor, seed, planPool, supported);
        }
        setHalf(r.data(), roomAddress, 99);
        for (int id = 31; id >= 0; --id) {
            const auto actor = enemyBase + (unsigned(id + 7) % 40) * enemyStride;
            r[actor + enemySpawn] = uint8_t(id);
            reverse[id] = client.pick(r.data(), actor, seed, planPool, unavailable);
        }
        require(forward == reverse && host.scripted[29], "Late actor reconstruction/order rerolled seeded identity");
    }
    require(seedVariation, "Enemy plans never vary across seeds");
    setWord(r.data(), sharedTypes, 0xffffffff); setWord(r.data(), sharedTypes + 4, 0xffffffff);
    for (unsigned bonus : {21u, 22u, 23u}) {
        setHalf(r.data(), scenario, uint16_t(bonus));
        require(sharedEnemyTypes(r.data()) == ((uint64_t(1) << 41) | (uint64_t(1) << 43)),
                "Bonus scenario did not use its original shared-family override");
    }
    setHalf(r.data(), scenario, 6);
    require(sharedEnemyTypes(r.data()) == 0xffffffffffffffffull, "Ordinary scenario ignored loaded shared-family bits");
    std::fill(r.begin(), r.end(), 0);
    r[enemyBase] = 1; r[enemyBase + 2] = 2; r[enemyBase + 3] = 1;
    r[enemyBase + enemySpawn] = 3;
    setHalf(r.data(), enemyBase + enemyModel, 9);
    setHalf(r.data(), enemyBase + enemyHealth, 350);
    setHalf(r.data(), enemyBase + enemyMaximum, 700);
    const auto actorSource = r;
    const SpawnProfile dog{2, 1, 0, 0, 300, 1};
    applySpawnProfile(r.data(), enemyBase, dog, 0x60ff00);
    require(half(r.data(), enemyBase + enemyHealth) == 150 && half(r.data(), enemyBase + enemyMaximum) == 300,
            "Enemy replacement lost proportional damage");
    require(r[enemyBase + 3] == 2 && half(r.data(), enemyBase + enemyModel) == 1, "Enemy profile not applied");
    for (unsigned offset : {3u, 0xbd2u, 0xbd3u, 0x540u, 0x541u, 0x542u, 0x543u,
                            0xc48u, 0xbb4u, 0x14u, 0x15u, 0x16u, 0x17u})
        r[enemyBase + offset] = actorSource[enemyBase + offset];
    require(r == actorSource, "Enemy replacement changed another actor, position, trigger or lifecycle");
    require(enemyActorAddress(enemyBase) && enemyActorAddress(enemyBase + 49 * enemyStride) &&
            !enemyActorAddress(enemyBase + 50 * enemyStride) && !enemyActorAddress(enemyBase + 1),
            "File2 actor pool bounds are incorrect");
    setWord(r.data(), 0x3a2360 + 2 * 8, 0x100000);
    setWord(r.data(), 0x3a2364 + 2 * 8, 2);
    setHalf(r.data(), 0x766ee0 + 2 * 2, 3);
    setWord(r.data(), 0x766fb0 + 3 * 4, 0x60ff00);
    require(enemyProfileCallback(r.data(), dog) == 0x60ff00, "File2 callback lookup uses wrong table");
    setWord(r.data(), 0x3a2364 + 2 * 8, 1);
    require(enemyProfileCallback(r.data(), dog) == 0, "Invalid model was accepted");
    r[0x4db470 + 2] = 0xff;
    for (unsigned i = 0; i < 6; ++i) r[0x4df200 + i * 0xc84 + 1] = 1;
    require(!enemyAnimationAvailable(r.data(), 2), "Full File2 animation bank reported capacity");
    r[0x4df200 + 5 * 0xc84 + 1] = 0;
    require(enemyAnimationAvailable(r.data(), 2), "File2 animation bank free slot ignored");
}
}
int main() try {
    require(gameLayout.itemPool == pool && gameLayout.spawnTable == spawns, "Wrong-game layout selected");
    require(gameLayout.enemySpawn && gameLayout.sharedTypes, "File2 enemy layout is incomplete");
    require(gameLayout.enemyBase == enemyBase && gameLayout.enemyStride == enemyStride &&
            gameLayout.enemySpawn == enemySpawn && gameLayout.enemyModel == enemyModel &&
            gameLayout.enemyBehavior == enemyBehavior && gameLayout.sharedTypes == sharedTypes,
            "File2 native field evidence disagrees with selected layout");
    itemRules(); cataloguePreservation(); floorModelRules(); enemyRules();
    std::cout << "PASS " << checks << " File #2 randomizer checks: category pools, seeded variation, exclusions, progression recipes, full-RAM boundaries, room/lifecycle supply, scripted species and six-family plans\n";
} catch (const std::exception& e) {
    std::cerr << "FAIL after " << checks << " checks: " << e.what() << '\n';
    return 1;
}
