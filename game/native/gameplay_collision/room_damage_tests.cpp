#include "room_damage.hpp"
#include "contact_routes.hpp"
#include "../gameplay_scenario/flags.hpp"
#include "damage_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <random>
namespace d = reo::native::gameplay_collision::delivery;
namespace sc = reo::native::gameplay_scenario;
unsigned checks{}, cases{}, resets{}, finish_cases{}, refusals{};
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "room damage check%u failed: %s\n", checks, why);
        std::exit(1);
    }
}
struct Channels final : d::RouteChannels {
    std::array<d::RouteChannel, 16> values;
    std::optional<d::ChannelView> channel(std::uint8_t edge) override {
        if (edge >= 16)
            return {};
        return d::ChannelView{values[edge].gate, values[edge].active};
    }
};
struct Effects final : d::RouteDamageEffects {
    sc::FlagState& flags;
    std::uint16_t& room;
    std::vector<std::uint32_t> trace;
    explicit Effects(sc::FlagState& f, std::uint16_t& r) : flags(f), room(r) {}
    bool refresh_channel(std::uint8_t edge) override {
        trace.insert(trace.end(), {0x6b5c60, edge});
        for (auto slot : {0u, 3u})
            flags.strided(room, edge, std::uint8_t(slot), true, false);
        if (damage_oracle::change_room)
            room = std::uint16_t((room + 1) % 128);
        return true;
    }
    bool notify(std::uint32_t r, std::uint32_t edge, std::uint8_t value,
                std::uint8_t kind) override {
        trace.insert(trace.end(), {0x67dcb0, r, edge, value, kind});
        return true;
    }
};
R5900Context context(std::uint32_t at) {
    R5900Context c;
    c.pc = at;
    c.g[29].lo = 0x7f0000;
    c.g[31].lo = 0x1234;
    return c;
}
int main() {
    std::vector<std::uint8_t> memory(0x800000);
    auto* m = memory.data();
    PS2Runtime runtime;
    d::RoomContacts contacts;
    std::mt19937 rng(0x570a30);
    for (auto bits : {0u, 500u, 32768u, 65535u}) {
        m[0x4bae8a] = 0;
        ref_write(m, 0x717698, std::uint16_t(bits));
        auto ctx = context(0x5d7cf0);
        o2_005D7CF0_0x5d7cf0(m, &ctx, &runtime);
        contacts.counters.reset(std::bit_cast<std::int16_t>(std::uint16_t(bits)));
        for (unsigned r = 0; r < 128; ++r)
            for (unsigned e = 0; e < 24; ++e)
                check(contacts.counters.get(r, e) ==
                          ref_read<std::int16_t>(m, 0x4a1df0 + 48 * r + 2 * e),
                      "complete original128x24 signed-half reset");
        ++resets;
    }
    sc::FlagState flags;
    d::RouteFlagBinding binding(flags);
    Channels channels;
    for (unsigned n = 0; n < 77536; ++n) {
        const auto row = std::uint8_t(rng() % 128), edge = std::uint8_t(rng() % 24);
        std::uint16_t room = n % 3 == 0 ? row : std::uint16_t(rng() % 128);
        ref_write(m, 0x3243dc, room);
        sc::FlagStateSnapshot snapshot;
        for (unsigned r = 0; r < 128; ++r)
            for (unsigned slot = 0; slot < 6; ++slot) {
                snapshot.strided[r][slot] = n < 65536 ? 0 : std::uint16_t(rng());
                ref_write(m, 0x4b9e20 + 12 * r + 2 * slot, snapshot.strided[r][slot]);
            }
        flags.restore(snapshot);
        const auto before = std::bit_cast<std::int16_t>(std::uint16_t(n < 65536 ? n : rng()));
        contacts.counters.set(row, edge, before);
        ref_write(m, 0x4a1df0 + 48 * row + 2 * edge, before);
        for (unsigned i = 0; i < 16; ++i) {
            channels.values[i] = {std::uint8_t(rng()), std::uint8_t(rng())};
            m[0x4a3621 + 96 * i] = channels.values[i].gate;
            m[0x4a362b + 96 * i] = channels.values[i].active;
        }
        const auto amount = n < 65536
                                ? std::array<std::int32_t, 5>{0, 1, -1, INT32_MAX, INT32_MIN}[n % 5]
                                : std::bit_cast<std::int32_t>(std::uint32_t(rng()));
        damage_oracle::trace.clear();
        damage_oracle::change_room = n % 2;
        auto ctx = context(0x570a30);
        ctx.g[4].lo = row;
        ctx.g[5].lo = edge;
        ctx.g[6].lo = std::uint64_t(std::int64_t(amount));
        o2_00570A30_0x570a30(m, &ctx, &runtime);
        Effects effects(flags, room);
        const auto report = d::apply_route_damage(contacts.counters, binding, channels, effects,
                                                  room, row, edge, amount);
        check(report.status == d::DamageStatus::completed && effects.trace == damage_oracle::trace,
              "full original durability/flag/effect sequence");
        check(room == ref_read<std::uint16_t>(m, 0x3243dc), "canonical room mutation preserved");
        check(contacts.counters.get(row, edge) ==
                  ref_read<std::int16_t>(m, 0x4a1df0 + 48 * row + 2 * edge),
              "signed16 subtract/wrap/reset/clamp source result");
        for (unsigned i = 0; i < 16; ++i)
            check(channels.values[i].gate == m[0x4a3621 + 96 * i] &&
                      channels.values[i].active == m[0x4a362b + 96 * i],
                  "shared canonical channel bytes preserve source ordering");
        for (unsigned r : {unsigned(row), unsigned(room)})
            for (unsigned slot = 0; slot < 6; ++slot)
                check(flags.strided_half(r, slot) ==
                          ref_read<std::uint16_t>(m, 0x4b9e20 + 12 * r + 2 * slot),
                      "actual canonical FlagState slots match original helpers");
        ++cases;
    }
    for (unsigned n = 0; n < 8192; ++n) {
        const auto row = rng() % 256, edge = rng() % 64, kind = rng() % 6;
        auto snapshot = flags.snapshot();
        snapshot.strided[row][kind] = std::uint16_t(rng());
        flags.restore(snapshot);
        ref_write(m, 0x4b9e20 + 12 * row + 2 * kind, snapshot.strided[row][kind]);
        std::uint16_t room = 0;
        Effects effects(flags, room);
        damage_oracle::trace.clear();
        auto ctx = context(0x5706b0);
        ctx.g[4].lo = row;
        ctx.g[5].lo = edge;
        ctx.g[6].lo = kind;
        o2_005706B0_0x5706b0(m, &ctx, &runtime);
        check(d::finish_route(binding, effects, row, edge, std::uint8_t(kind)) ==
                      d::DamageStatus::completed &&
                  effects.trace == damage_oracle::trace &&
                  flags.strided_half(row, kind) ==
                      ref_read<std::uint16_t>(m, 0x4b9e20 + 12 * row + 2 * kind),
              "actual finish flag set before native notify");
        ++finish_cases;
    }
    for (unsigned edge = 24; edge < 32; ++edge) {
        std::uint16_t room = 0;
        Effects effects(flags, room);
        check(!contacts.pending_amount(edge) &&
                  d::apply_route_damage(contacts.counters, binding, channels, effects, room, 0,
                                        std::uint8_t(edge), 1)
                          .status == d::DamageStatus::unadmitted_counter,
              "unknown adjacent header aliases refused instead of duplicated");
        ++refusals;
    }
    std::uint16_t room = 128;
    Effects effects(flags, room);
    flags.strided(128, 0, 5, false, false);
    flags.strided(128, 0, 2, false, false);
    check(d::apply_route_damage(contacts.counters, binding, channels, effects, room, 128, 0, 1)
                      .status == d::DamageStatus::unadmitted_counter &&
              channels.values[0].active == 1,
          "unknown counter keeps earlier source active-byte write");
    ++refusals;
    flags.strided(128, 0, 5, true, false);
    check(d::apply_route_damage(contacts.counters, binding, channels, effects, room, 128, 0, 1)
                  .status == d::DamageStatus::completed,
          "protected flag path never reads unadmitted counter row");
    check(!contacts.counters.get(128, 0) && !contacts.counters.set(0, 24, 1) &&
              contacts.pending_amount(23),
          "native owner exposes exact128x24 bounds and pending24");
    std::printf("{\"checks\":%u,\"cases\":%u,\"resets\":%u,\"finish_cases\":%u,\"refusals\":%u,"
                "\"game_launched\":false}\n",
                checks, cases, resets, finish_cases, refusals);
}
