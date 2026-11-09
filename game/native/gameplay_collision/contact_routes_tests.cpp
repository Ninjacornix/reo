#include "contact_routes.hpp"
#include "routes_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <random>
namespace d = reo::native::gameplay_collision::delivery;
unsigned checks{}, cases{}, full_batches{}, changed_targets{}, refusals{};
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "route check %u failed: %s\n", checks, why);
        std::exit(1);
    }
}
struct Target {
    std::uint8_t type{};
    std::uint32_t room{}, edge{};
};
struct TargetLease final : d::RouteTarget {
    Target& target;
    explicit TargetLease(Target& t) : target(t) {}
    std::uint8_t type() const noexcept override {
        return target.type;
    }
    std::optional<d::RouteDestination> destination() const override {
        return d::RouteDestination{target.room, target.edge};
    }
};
struct Services final : d::RouteServices {
    std::uint16_t& room;
    std::array<std::uint16_t, 512> masks;
    std::array<Target, 16> targets;
    std::vector<std::uint32_t> trace;
    bool ready{true}, admitted{true}, accepted{true};
    explicit Services(std::uint16_t& value) : room(value) {}
    std::optional<std::uint16_t> closed_edges(std::uint32_t value) override {
        return admitted && value < masks.size() ? std::optional<std::uint16_t>{masks[value]}
                                                : std::nullopt;
    }
    bool apply(std::uint8_t r, std::uint8_t e, std::int32_t amount) override {
        trace.insert(trace.end(), {0x570a30, r, e, std::uint32_t(amount)});
        if (route_oracle::mutation & 1)
            masks[room] |= std::uint16_t(1u << (e & 31));
        if (route_oracle::mutation & 2)
            room = std::uint16_t((room + 1) % 512);
        if (route_oracle::mutation & 4)
            for (auto& t : targets) {
                t.room = (t.room + 1) % 512;
                t.edge = (t.edge + 1) % 64;
            }
        return accepted;
    }
    bool finish(std::uint32_t r, std::uint32_t e, std::uint8_t kind) override {
        trace.insert(trace.end(), {0x5706b0, r, e, kind});
        return accepted;
    }
    d::RouteLookup related(std::uint8_t edge) override {
        trace.insert(trace.end(), {0x5819c0, edge});
        auto& t = targets[edge];
        if (!ready)
            return {};
        if (!route_oracle::present[edge])
            return {true, {}};
        return {true, std::make_shared<TargetLease>(t)};
    }
    std::int32_t send_authority() override {
        trace.push_back(0x1b0310);
        return route_oracle::authority;
    }
    bool send(std::span<const d::RouteEntry> entries) override {
        trace.insert(trace.end(), {0x1afdd0, 5, 0, 2, 4, 0x30, std::uint32_t(entries.size())});
        for (const auto& e : entries)
            trace.insert(trace.end(), {e.room, e.edge, std::uint16_t(e.amount)});
        return accepted;
    }
};
int main() {
    std::vector<std::uint8_t> memory(0x800000);
    auto* m = memory.data();
    std::mt19937 rng(0x680b40);
    for (unsigned n = 0; n < 12000; ++n) {
        std::uint16_t room = std::uint16_t(rng() % 512);
        Services services(room);
        ref_write(m, 0x3243dc, room);
        route_oracle::mutation = std::uint8_t(n % 8);
        route_oracle::authority = std::array<std::int32_t, 4>{-1, 0, 1, 2}[rng() % 4];
        route_oracle::trace.clear();
        for (unsigned i = 0; i < 512; ++i) {
            services.masks[i] = std::uint16_t(rng());
            if (n % 5 == 0)
                services.masks[i] = 0;
            ref_write(m, route_oracle::mask(i), services.masks[i]);
        }
        for (unsigned i = 0; i < 16; ++i) {
            auto& t = services.targets[i];
            t.type = std::uint8_t(rng() % 2 ? 0 : 2);
            t.room = rng() % 512;
            t.edge = rng() % 64;
            route_oracle::present[i] = rng() % 3 != 0;
            m[route_oracle::target(i) + 0x30] = t.type;
            ref_write(m, route_oracle::target(i) + 0x44, t.room);
            ref_write(m, route_oracle::target(i) + 0x48, t.edge);
        }
        std::array<std::int16_t, 32> pending;
        for (unsigned i = 0; i < 32; ++i) {
            pending[i] = n % 5 == 0 ? std::int16_t(i + 1)
                                    : std::bit_cast<std::int16_t>(std::uint16_t(rng()));
            ref_write(m, 0x4a35f0 + 2 * i, pending[i]);
        }
        PS2Runtime runtime;
        R5900Context ctx;
        ctx.pc = 0x680b40;
        ctx.g[29].lo = 0x7f0000;
        ctx.g[31].lo = 0x1234;
        o2_00680B40_0x680b40(m, &ctx, &runtime);
        const auto report = d::consume_routes(pending, room, services);
        if (services.trace != route_oracle::trace) {
            std::fprintf(stderr, "case %u mutation%u\nnative ", n, route_oracle::mutation);
            for (auto x : services.trace)
                std::fprintf(stderr, "%x ", x);
            std::fprintf(stderr, "\noriginal ");
            for (auto x : route_oracle::trace)
                std::fprintf(stderr, "%x ", x);
            std::fprintf(stderr, "\n");
        }
        check(report.status == d::RouteStatus::completed && services.trace == route_oracle::trace,
              "unchanged original route control and effect order");
        check(room == ref_read<std::uint16_t>(m, 0x3243dc),
              "canonical room re-read after synchronous callback");
        for (unsigned i = 0; i < 512; ++i)
            check(services.masks[i] == ref_read<std::uint16_t>(m, route_oracle::mask(i)),
                  "closure mask callback state");
        for (unsigned i = 0; i < 16; ++i) {
            const auto& t = services.targets[i];
            check(t.room == ref_read<std::uint32_t>(m, route_oracle::target(i) + 0x44) &&
                      t.edge == ref_read<std::uint32_t>(m, route_oracle::target(i) + 0x48),
                  "leased target room/edge re-read rather than snapshot");
        }
        for (unsigned i = 0; i < 32; ++i)
            check(pending[i] == ref_read<std::int16_t>(m, 0x4a35f0 + 2 * i),
                  "consumer does not reset pending route accumulators");
        check(report.visited <= 24 && report.batched <= 10, "exact source consumer limits");
        ++cases;
        if (report.batched == 10)
            ++full_batches;
        if (route_oracle::mutation & 4)
            ++changed_targets;
    }
    for (unsigned kind = 0; kind < 3; ++kind) {
        std::uint16_t room = 0;
        Services services(room);
        services.masks.fill(0);
        std::array<std::int16_t, 32> pending{};
        pending[0] = 5;
        route_oracle::mutation = 0;
        route_oracle::present.fill(false);
        if (kind == 0)
            services.admitted = false;
        if (kind == 1)
            services.ready = false;
        if (kind == 2)
            services.accepted = false;
        const auto result = d::consume_routes(pending, room, services);
        check(result.status != d::RouteStatus::completed && pending[0] == 5,
              "native unavailable profile/owner/effect preserves prior work and pending state");
        ++refusals;
    }
    {
        std::uint16_t room = 0;
        Services services(room);
        std::array<std::int16_t, 24> exact{};
        check(d::consume_routes(std::span<const std::int16_t>(exact).first(23), room, services)
                          .status == d::RouteStatus::unadmitted_pending &&
                  services.trace.empty(),
              "short pending owner refuses before effects");
        const auto complete = d::consume_routes(exact, room, services);
        check(complete.status == d::RouteStatus::completed && complete.visited == 24 &&
                  services.trace.empty(),
              "actual24-slot owner consumed directly without shadow copy");
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"full_batches\":%u,\"changed_targets\":%u,"
                "\"refusals\":%u,\"game_launched\":false}\n",
                checks, cases, full_batches, changed_targets, refusals);
}
