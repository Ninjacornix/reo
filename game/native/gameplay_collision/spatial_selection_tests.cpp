#include "nearest.hpp"
#include "selection_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <optional>
#include <vector>
unsigned checks{}, cases{}, nan_first{}, ties{}, empty{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "selection check %u failed: %s\n", checks, why);
        std::exit(1);
    }
}
struct Hit {
    unsigned actor{}, region{};
    float distance{};
};
void compare(bool per_actor, bool margin) {
    auto* m = memory.data();
    std::fill(memory.begin() + 0x10000, memory.begin() + 0x26000, 0);
    m[0x10002] = 3;
    m[0x10006] = 9;
    ref_write(m, 0x80008, 0x10000u);
    ref_write(m, 0x80014, 0x81000u);
    m[0x80019] = 1;
    m[0x8100d] = per_actor;
    m[0x81006] = 1;
    m[0x81016] = 1;
    m[0x4bae96] = 0;
    ref_write(m, 0x3c25f8, std::uint16_t(2));
    const std::array<float, 3> start{}, end{100, 0, 0};
    ref_write(m, 256, start);
    ref_write(m, 272, end);
    const std::array<float, 3> marker{701, 702, 703};
    ref_write(m, 304, marker);
    for (unsigned actor = 0; actor < 2; ++actor) {
        const auto at = 0x20000 + actor * 0x2000;
        ref_write(m, 0x3c2600 + 4 * actor, at);
        m[at + 2] = 0;
        m[at + 6] = std::uint8_t(actor);
        ref_write(m, at + 0x1d8, 0x90000 + actor * 0x1000);
        ref_write(m, at + 0x1dc, 0xa0000 + actor * 0x1000);
        m[at + 0x1e0] = 2;
        for (unsigned region = 0; region < 2; ++region) {
            ref_write(m, 0x9000c + actor * 0x1000 + 20 * region, 1.0f);
            ref_write(m, 0xa0000 + actor * 0x1000 + 12 * region,
                      std::array<float, 3>{float(actor), float(region), 0});
        }
    }
    R5900Context ctx;
    ctx.pc = margin ? 0x57ac60 : 0x579fc0;
    ctx.g[29].lo = 0x7f0000;
    ctx.g[31].lo = 0x1234;
    ctx.g[4].lo = 0x80000;
    ctx.g[5].lo = 256;
    ctx.g[6].lo = 272;
    ctx.g[7].lo = 304;
    ctx.f[12] = margin ? 5 : 0;
    PS2Runtime runtime;
    selection_oracle::calls = 0;
    if (margin)
        o2_0057AC60_0x57ac60(m, &ctx, &runtime);
    else
        o2_00579FC0_0x579fc0(m, &ctx, &runtime);
    std::array<std::optional<Hit>, 2> selected_by_actor;
    std::optional<Hit> selected;
    unsigned hits{}, calls{};
    for (unsigned actor = 0; actor < 2; ++actor) {
        for (unsigned region = 0; region < 2; ++region) {
            ++calls;
            if (!selection_oracle::enabled[actor][region])
                continue;
            ++hits;
            const auto& point = selection_oracle::points[actor][region];
            const auto distance =
                std::sqrt((point[0] * point[0] + point[1] * point[1]) + point[2] * point[2]);
            Hit candidate{actor, region, distance};
            auto& prior = per_actor ? selected_by_actor[actor] : selected;
            if (reo::native::gameplay_collision::spatial::detail::replaces(
                    bool(prior), distance, prior ? prior->distance : 0))
                prior = candidate;
            else if (prior->distance == distance)
                ++ties;
            if (per_actor && margin)
                break;
        }
    }
    check(hits == ctx.g[2].lo && calls == selection_oracle::calls,
          "unchanged original scanner admitted count and per-actor break");
    for (unsigned actor = 0; actor < 2; ++actor) {
        const auto& hit = per_actor ? selected_by_actor[actor] : selected;
        const bool selected_here = hit && hit->actor == actor;
        const auto at = 0x20000 + actor * 0x2000;
        check(m[at + 0x13f] == unsigned(selected_here),
              "production nearest policy selects original actor");
        if (selected_here) {
            check(m[at + 0x13e] == hit->region,
                  "production nearest policy selects original first/nearest region");
            const auto expected = selection_oracle::points[actor][hit->region],
                       actual = ref_read<std::array<float, 3>>(m, at + 0x120);
            for (unsigned lane = 0; lane < 3; ++lane)
                check(actual[lane] == expected[lane] ||
                          (std::isnan(actual[lane]) && std::isnan(expected[lane])),
                      "original selected controlled point");
            if (std::isnan(hit->distance))
                ++nan_first;
        }
    }
    if (!hits)
        ++empty;
    ++cases;
}
int main() {
    const std::array<float, 8> values{0,
                                      1,
                                      -1,
                                      2,
                                      std::numeric_limits<float>::infinity(),
                                      std::numeric_limits<float>::quiet_NaN(),
                                      std::numeric_limits<float>::max(),
                                      3};
    for (unsigned pattern = 0; pattern < 4096; ++pattern) {
        auto encoded = pattern;
        for (unsigned actor = 0; actor < 2; ++actor)
            for (unsigned region = 0; region < 2; ++region) {
                const auto index = encoded & 7;
                encoded >>= 3;
                selection_oracle::points[actor][region] = {values[index], 0, 0};
                selection_oracle::enabled[actor][region] = index != 7;
            }
        for (bool per_actor : {false, true})
            for (bool margin : {false, true})
                compare(per_actor, margin);
    }
    check(nan_first > 100 && ties > 100 && empty == 4,
          "unordered first hits, equal distances and empty queries exercised");
    std::printf("{\"checks\":%u,\"controlled_policy_cases\":%u,\"nan_first_deliveries\":%u,\"equal_"
                "distance_keeps\":%u,\"empty_cases\":%u,\"geometry_outputs_controlled\":true,"
                "\"game_launched\":false}\n",
                checks, cases, nan_first, ties, empty);
}
