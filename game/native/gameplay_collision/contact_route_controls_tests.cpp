#include "contact_routes.hpp"
#include "../gameplay_scenario/scene_control_routes.hpp"
namespace sc = reo::native::gameplay_scenario;
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
struct Services final : d::RouteServices {
    std::uint16_t& room;
    std::array<std::uint16_t, 512> masks;
    std::array<Target, 16> targets;
    std::shared_ptr<sc::SceneControls> controls = std::make_shared<sc::SceneControls>();
    std::array<sc::SceneControlId, 16> ids;
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
                const auto i = std::size_t(&t - targets.data());
                auto record = controls->get(ids[i]);
                check(bool(record), "actual control retained during effect");
                if (auto* zero = std::get_if<sc::ControlTypeZero>(&record->body))
                    zero->destination = sc::ControlRouteDestination{t.room, t.edge};
                else
                    std::get<sc::ControlTypeTwo>(record->body).destination =
                        sc::ControlRouteDestination{t.room, t.edge};
                check(controls->replace(ids[i], *record) == sc::ControlStatus::completed,
                      "canonical destination updated during actual effect");
            }
        return accepted;
    }
    bool finish(std::uint32_t r, std::uint32_t e, std::uint8_t kind) override {
        trace.insert(trace.end(), {0x5706b0, r, e, kind});
        return accepted;
    }
    d::RouteLookup related(std::uint8_t edge) override {
        if (!ready)
            return {};
        return sc::lookup_scene_route(controls, edge);
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
            ref_write(m, route_oracle::target(i) + 0x28,
                      i == 15 ? 0u : route_oracle::target(i + 1));
            ref_write(m, route_oracle::target(i) + 0x40, route_oracle::present[i] ? i : 256u + i);
            sc::SceneControl record;
            record.authored_id = route_oracle::present[i] ? i : 256u + i;
            record.enabled = std::uint8_t(rng());
            m[route_oracle::target(i) + 0x3c] = record.enabled;
            if (t.type == 0) {
                sc::ControlTypeZero body;
                body.destination = sc::ControlRouteDestination{t.room, t.edge};
                record.body = body;
            } else {
                sc::ControlTypeTwo body;
                body.destination = sc::ControlRouteDestination{t.room, t.edge};
                record.body = body;
            }
            const auto id = services.controls->append(record);
            check(bool(id), "actual canonical control admitted");
            services.ids[i] = *id;
        }
        std::array<std::int16_t, 32> pending;
        for (unsigned i = 0; i < 32; ++i) {
            pending[i] = n % 5 == 0 ? std::int16_t(i + 1)
                                    : std::bit_cast<std::int16_t>(std::uint16_t(rng()));
            ref_write(m, 0x4a35f0 + 2 * i, pending[i]);
        }
        ref_write(m, 0x3b5150, std::int16_t(16));
        ref_write(m, 0x3b5160, route_oracle::target(0));
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
        auto owner = std::make_shared<sc::SceneControls>();
        sc::SceneControl record;
        record.authored_id = 7;
        sc::ControlTypeZero body;
        body.destination = sc::ControlRouteDestination{19, 23};
        record.body = body;
        const auto id = owner->append(record);
        check(bool(id), "real route owner allocation");
        auto selected = sc::lookup_scene_route(owner, 7);
        std::weak_ptr<sc::SceneControls> weak = owner;
        owner.reset();
        check(selected.admitted && selected.target && !weak.expired() &&
                  selected.target->destination()->room == 19,
              "selected control retains actual canonical owner");
        owner = weak.lock();
        record = *owner->get(*id);
        std::get<sc::ControlTypeZero>(record.body).destination =
            sc::ControlRouteDestination{33, 34};
        owner->replace(*id, record);
        check(selected.target->destination()->room == 33 &&
                  selected.target->destination()->edge == 34,
              "actual selected identity requery observes canonical replacement");
        owner->erase(*id);
        check(!selected.target->destination(),
              "retired actual control refuses rather than using copied destination");
        record.authored_id = 7;
        std::get<sc::ControlTypeZero>(record.body).destination.reset();
        owner->append(record);
        selected = sc::lookup_scene_route(owner, 7);
        check(selected.admitted && selected.target && !selected.target->destination(),
              "unprojected actual destination refuses");
        check(!sc::lookup_scene_route({}, 7).admitted,
              "absent actual control owner is not an admitted empty scene");
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
