#include "impact_policy.hpp"
#include "impact_support.hpp"
namespace transforms = reo::native::transform_math;
unsigned policy_cases{}, oriented_calls{}, surface_calls{}, refusals{};
float maximum_error{};
void vector_equal(c::Vec3 a, c::Vec3 b, const char* why) {
    for (const auto values : {std::pair{a.x, b.x}, std::pair{a.y, b.y}, std::pair{a.z, b.z}}) {
        const bool same = values.first == values.second ||
                          (std::isnan(values.first) && std::isnan(values.second));
        const auto error = std::abs(values.first - values.second);
        if (!same)
            maximum_error = std::max(maximum_error, error);
        check(same || error < 0.00001f, why);
    }
}
struct Visuals final : d::ImpactVisuals {
    Roster& roster;
    std::vector<impact_oracle::Call> calls;
    explicit Visuals(Roster& r) : roster(r) {}
    d::Status oriented(const transforms::Matrix& matrix, c::Vec3& point,
                       std::uint8_t key) override {
        calls.push_back({1, key, 0, matrix, point});
        point = {point.x + 2, point.y + 3, point.z + 5};
        return d::Status::completed;
    }
    d::Status surface(d::View owner, const std::optional<transforms::Matrix>& matrix,
                      c::Vec3& point, std::uint8_t key) override {
        check(!matrix, "surface81 helper passes a null matrix separately from actor identity");
        calls.push_back({2, key, address(roster.index(owner.id)), {}, point});
        point = {point.x + 2, point.y + 3, point.z + 5};
        return d::Status::completed;
    }
};
int main() {
    Roster roster;
    auto* m = storage().data();
    std::mt19937 rng(0x5dd580);
    const std::array<c::Vec3, 9> normals{{{0, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1},
                                          {1, 0, 0},
                                          {-1, 0, 0},
                                          {1, 2, 3},
                                          {0.00001f, 0.00002f, -0.00003f},
                                          {1e20f, 0, 1e20f},
                                          {-1, -2, -3}}};
    for (unsigned n = 0; n < 24000; ++n) {
        for (auto& subject : roster.subjects) {
            subject.actor = {};
            subject.contact = {};
        }
        auto& owner = roster.subjects[1];
        owner.actor.category = n % 3 == 0 ? 2 : 0;
        owner.actor.slot = std::uint8_t(rng());
        roster.write();
        d::Packet packet;
        packet.cached_related = n % 5 == 0 ? a::EntityId{} : owner.id;
        packet.key = std::uint8_t(n);
        packet.event = std::uint8_t(n % 4);
        c::Vec3 impact{11, 13, 17};
        const auto old_impact = impact;
        const auto normal = normals[n % normals.size()];
        const c::Vec3 point = n % 7 == 0 ? c::Vec3{1e10f, -1e10f, 1e10f}
                                         : c::Vec3{float(n % 1000), float(n % 73), -float(n % 211)};
        const c::trace::Hit wall{{101, 102, 103}, normal, 0, 0},
            floor{point, normal, (n / 4) % 256, 0};
        ref_write(m, 0x3102c, packet.cached_related ? address(1) : 0u);
        m[0x3101b] = packet.event;
        m[0x3100d] = packet.key;
        ref_write(m, 0x3101c, impact);
        ref_write(m, 0x32000, point);
        ref_write(m, 0x32100, normal);
        ref_write(m, 0x32200, normal);
        auto ctx = context(0x5dd580);
        SET_GPR_U32(&ctx, 4, 0x31000);
        SET_GPR_U32(&ctx, 5, 0x32000);
        SET_GPR_U32(&ctx, 6, 0x32100);
        SET_GPR_U32(&ctx, 7, 0x32200);
        SET_GPR_U32(&ctx, 8, (n / 4) % 256);
        PS2Runtime runtime;
        impact_oracle::calls.clear();
        o2_005DD580_0x5dd580(m, &ctx, &runtime);
        Visuals visuals(roster);
        const auto status = d::emit_contact_impact(packet, impact, roster, visuals, wall, floor);
        check(status == d::Status::completed && visuals.calls.size() == impact_oracle::calls.size(),
              "full original owner/event/type dispatch");
        vector_equal(impact, ref_read<c::Vec3>(m, 0x3101c),
                     "event1 publishes mutable packet impact; event2 does not");
        for (unsigned i = 0; i < visuals.calls.size(); ++i) {
            const auto& actual = visuals.calls[i];
            const auto& original = impact_oracle::calls[i];
            check(actual.kind == original.kind && actual.key == original.key &&
                      actual.actor == original.actor,
                  "selected child/key and actual owner identity");
            vector_equal(actual.point, original.point, "selected point or floorY+1");
            if (actual.kind == 1) {
                for (unsigned column = 0; column < 4; ++column) {
                    const auto& a = actual.matrix[column];
                    const auto& b = original.matrix[column];
                    vector_equal({a[0], a[1], a[2]}, {b[0], b[1], b[2]},
                                 "complete original basis/view orientation and cancellation");
                    check(a[3] == b[3], "caller clears basisW and preserves translationW1");
                }
                ++oriented_calls;
            } else
                ++surface_calls;
        }
        if (packet.event != 1)
            vector_equal(impact, old_impact,
                         "local floor point mutation never leaks to packet storage");
        ++policy_cases;
    }
    d::Packet packet;
    packet.event = 1;
    packet.cached_related = roster.subjects[1].id;
    roster.subjects[1].actor.category = 0;
    c::Vec3 impact{1, 2, 3};
    Visuals visuals(roster);
    check(d::emit_contact_impact(packet, impact, roster, visuals, {}, {}) ==
                  d::Status::uninitialized_output_point &&
              visuals.calls.empty(),
          "unknown required input refuses before emission");
    ++refusals;
    a::EntityStore foreign;
    packet.cached_related = foreign.create(std::make_unique<a::Entity>()).id;
    check(d::emit_contact_impact(packet, impact, roster, visuals, {}, {}) ==
              d::Status::missing_actor,
          "foreign/stale typed owner is not a usable original address");
    ++refusals;
    std::printf("{\"checks\":%u,\"policy_cases\":%u,\"oriented_calls\":%u,\"surface_calls\":%u,"
                "\"refusals\":%u,\"maximum_error\":%.9g,\"game_launched\":false}\n",
                checks, policy_cases, oriented_calls, surface_calls, refusals,
                double(maximum_error));
}
