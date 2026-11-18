#include "../gameplay_world/world.hpp"
#include "actor_view_support.hpp"
namespace w = reo::native::gameplay_world;
unsigned world_cases{}, world_boundary_cases{}, ownership_cases{};
using Lease = std::shared_ptr<w::Actor>;
a::View canonical(a::EntityId id, w::Actor& actor, std::span<const a::Basis> joints) {
    auto& collision = actor.collision;
    return {id,
            actor.position,
            actor.previous_position,
            actor.candidate_direction,
            joints,
            collision.body_definition,
            actor.category,
            collision.body_priority,
            collision.separation_count,
            actor.room_marker,
            collision.body_peer,
            actor.room,
            collision.body_summary,
            actor.transient_marker};
}
void constants() {
    auto& m = storage();
    ref_write(m.data(), 0x742e80, 0.0010000000474974513f);
    ref_write(m.data(), 0x38ca98, 0.00009999999747378752f);
    ref_write(m.data(), 0x241c80, 182.04444885253906f);
    ref_write(m.data(), 0x241c88, 3.1415927410125732f);
}
void compare_world(w::World& owner, std::span<const a::Actor> inputs,
                   std::span<const a::Registration> registrations, bool limited, bool fast) {
    auto& memory = storage();
    constants();
    memory[64] = limited;
    memory[0x3243cc] = fast;
    memory[0x3b5370] = 0;
    std::fill(memory.begin() + 0x759f60, memory.begin() + 0x759f60 + 32 * 12, 0);
    std::vector<Lease> leases;
    std::vector<a::View> views;
    a::ViewRegistry registry;
    for (unsigned i = 0; i < inputs.size(); ++i) {
        const auto& input = inputs[i];
        auto lease = owner.resolve(input.id);
        check(bool(lease) && lease == owner.primary(i),
              "body view ID resolves actual canonical World-owned actor");
        auto& actor = *lease;
        actor.position = {input.position.x, input.position.y, input.position.z};
        actor.previous_position = {input.previous.x, input.previous.y, input.previous.z};
        actor.candidate_direction = {input.candidate_direction.x, input.candidate_direction.y,
                                     input.candidate_direction.z};
        actor.category = input.actor_class;
        actor.room = input.room;
        actor.room_marker = 0xa5;
        actor.transient_marker = 0x81;
        actor.collision.body_definition = input.definition;
        actor.collision.body_priority = input.priority;
        actor.collision.separation_count = input.separation_count;
        actor.collision.body_peer = {};
        actor.collision.body_summary = {};
        views.push_back(canonical(input.id, actor, input.joints));
        auto& view = views.back();
        check(&view.position.x == &actor.position.x &&
                  &view.previous.z == &actor.previous_position.z &&
                  &view.candidate_direction.y == &actor.candidate_direction.y &&
                  &view.definition == &actor.collision.body_definition &&
                  &view.summary == &actor.collision.body_summary,
              "canonical body refs alias actual existing fields");
        leases.push_back(std::move(lease));
        write_actor(memory.data(), input, i);
        memory[address(i) + 0xc53] = actor.room_marker;
    }
    ref_write(memory.data(), 0x3b53b0, std::uint16_t(registrations.size()));
    for (unsigned i = 0; i < registrations.size(); ++i) {
        const auto& entry = registrations[i];
        check(registry.add(entry), "canonical view registration");
        unsigned actor{};
        for (; actor < inputs.size() && inputs[actor].id != entry.actor; ++actor) {
        }
        check(actor < inputs.size(), "admitted identity roster");
        ref_write(memory.data(), 0x3b53c0 + 8 * i, entry.source_mask);
        ref_write(memory.data(), 0x3b53c2 + 8 * i, entry.collision_class);
        ref_write(memory.data(), 0x3b53c4 + 8 * i, address(actor));
    }
    (void)registry.solve(views, limited, fast);
    R5900Context ctx;
    ctx.pc = 0x6ef150;
    ctx.g[29].lo = 0x7f0000;
    ctx.g[31].lo = 0x1234;
    PS2Runtime runtime;
    o2_006EF150_0x6ef150(memory.data(), &ctx, &runtime);
    check(registry.size() == 0 && ref_read<std::uint16_t>(memory.data(), 0x3b53b0) == 0,
          "canonical body registration drains at original point");
    for (unsigned i = 0; i < inputs.size(); ++i) {
        const auto& actor = *leases[i];
        const auto at = address(i);
        vector_equal({actor.position.x, actor.position.y, actor.position.z},
                     ref_read<c::Vec3>(memory.data(), at + 0x38),
                     "actual World-owned position matches unchanged actor solver");
        check(actor.room_marker == memory[at + 0xc53],
              "existing canonical C53byte clears/sets/preserves exact sourcevalue");
        check(actor.collision.separation_count == memory[at + 0x1e1],
              "canonical repeated-contact count");
        const auto& s = actor.collision.body_summary;
        check(s.x == ref_read<float>(memory.data(), at + 0x19c) &&
                  s.z == ref_read<float>(memory.data(), at + 0x1a0) &&
                  s.half_length == ref_read<std::uint16_t>(memory.data(), at + 0x1a4) &&
                  s.heading == ref_read<std::uint16_t>(memory.data(), at + 0x1a6),
              "canonical body summary fields");
        const auto peer = ref_read<std::uint32_t>(memory.data(), at + 0xc54);
        if (peer) {
            check(peer >= address(0) && (peer - address(0)) % 0x2000 == 0,
                  "source selected peer belongs to admitted fixture");
            check(actor.collision.body_peer == inputs[(peer - address(0)) / 0x2000].id,
                  "canonical peer is native entity identity");
        } else
            check(!actor.collision.body_peer, "unchanged canonical peer stays empty");
    }
    ++world_cases;
}
int main() {
    w::Profile profile;
    profile.layouts.resize(1);
    auto session = std::make_shared<w::Session>();
    w::World owner(std::move(profile), session);
    std::array<a::EntityId, 4> ids;
    std::array<Lease, 4> owned;
    for (unsigned i = 0; i < 4; ++i) {
        auto actor = std::make_unique<w::Actor>();
        actor->active = true;
        actor->slot = std::uint8_t(i);
        const auto created = owner.spawn_primary(i, std::move(actor));
        check(created.status == reo::native::gameplay_actors::EntityStatus::completed,
              "actual primary owner creates actor");
        ids[i] = created.id;
        owned[i] = owner.primary(i);
    }
    std::array<a::Basis, 2> joints;
    std::mt19937 random(0x6ef150);
    const auto scalar = [&] { return float(int(random() % 2001) - 1000) / 100; };
    for (unsigned iteration = 0; iteration < 1000; ++iteration) {
        for (auto& basis : joints) {
            basis = {};
            basis.translation = {scalar(), scalar(), scalar()};
            basis.x.x = 0.5f + float(random() % 4) * 0.5f;
        }
        std::vector<a::Actor> inputs(4);
        std::vector<a::Registration> registrations;
        for (unsigned i = 0; i < 4; ++i) {
            auto& actor = inputs[i];
            actor.id = ids[i];
            actor.position = {scalar(), scalar(), scalar()};
            actor.previous = {actor.position.x + scalar() / 4, actor.position.y,
                              actor.position.z + scalar() / 4};
            actor.candidate_direction = {scalar(), scalar(), scalar()};
            actor.joints = joints;
            actor.actor_class = std::uint8_t(random() % 3);
            actor.priority = std::uint8_t(random() % 3);
            actor.separation_count = std::uint8_t(random() % 125);
            a::ShapeDefinition shape;
            shape.kind = random() % 2 ? a::ShapeKind::sphere : a::ShapeKind::capsule;
            shape.radius = float(random() % 7 + 1);
            for (auto* center : {&shape.first, &shape.second}) {
                const auto first = random() % 3, second = random() % 3;
                if (first < 2)
                    center->first_joint = std::uint16_t(first);
                if (second < 2)
                    center->second_joint = std::uint16_t(second);
                center->first_offset = {scalar(), scalar(), scalar()};
                center->second_offset = {scalar(), scalar(), scalar()};
            }
            actor.definition = shape;
            registrations.push_back(
                {ids[i], std::uint16_t(random() % 16), std::uint16_t(1u << (random() % 4))});
        }
        compare_world(owner, inputs, registrations, random() % 2, random() % 2);
    }
    for (unsigned iteration = 0; iteration < 200; ++iteration) {
        auto& memory = storage();
        memory[65] = iteration % 2;
        memory[0x4baded] = iteration % 4;
        ref_write(memory.data(), 0x4baea0, 4u);
        ref_write(memory.data(), 0x3243dc, std::uint16_t(1));
        std::vector<a::View> views;
        for (unsigned i = 0; i < 4; ++i) {
            auto& actor = *owned[i];
            actor.position = {0, -900 + float(random() % 61), float(random() % 1000)};
            actor.room = std::uint16_t(random() % 3);
            actor.transient_marker = 0x81;
            views.push_back(canonical(ids[i], actor, joints));
            const auto at = 0x4a5c30 + 0x10e0 * i;
            ref_write(memory.data(), at + 0x38, actor.position);
            ref_write(memory.data(), at + 0x1e2, actor.room);
            memory[at + 0x10a9] = actor.transient_marker;
        }
        const auto boundary_owner = iteration % 4;
        ref_write(memory.data(), 0x3b5374, std::uint32_t(0x4a5c30 + 0x10e0 * boundary_owner));
        a::ViewBoundary boundary;
        check(boundary.set(0, ids[boundary_owner]), "canonical boundary owner");
        boundary.apply(views, memory[65] == 1, 1, ids[iteration % 4]);
        R5900Context ctx;
        ctx.pc = 0x6f1750;
        ctx.g[29].lo = 0x7f0000;
        ctx.g[31].lo = 0x1234;
        ctx.g[4].lo = 0x3b5370;
        PS2Runtime runtime;
        o2_006F1750_0x6f1750(memory.data(), &ctx, &runtime);
        for (unsigned i = 0; i < 4; ++i) {
            const auto at = 0x4a5c30 + 0x10e0 * i;
            vector_equal({owned[i]->position.x, owned[i]->position.y, owned[i]->position.z},
                         ref_read<c::Vec3>(memory.data(), at + 0x38),
                         "canonical boundary preserves changing owner position/order");
            check(owned[i]->transient_marker == memory[at + 0x10a9],
                  "existing canonical10A9byte publishesone or preserves nonzero");
        }
        ++world_boundary_cases;
    }
    const auto retired = ids[0];
    auto retained = owned[0];
    check(owner.retire_primary(0) == reo::native::gameplay_actors::EntityStatus::completed &&
              !owner.resolve(retired),
          "retired native generation is not readmitted through owner");
    auto replacement = owner.spawn_primary(0, std::make_unique<w::Actor>());
    check(replacement.id && replacement.id != retired,
          "same primary slot has distinct native generation");
    std::vector<a::View> roster;
    for (unsigned i = 0; i < 4; ++i) {
        auto lease = owner.primary(i);
        roster.push_back(canonical(owner.identity(i), *lease, joints));
    }
    a::ViewRegistry stale;
    check(stale.add({retired, 1, 1}), "registration retains old token for validation");
    const auto before = owner.primary(0)->position;
    bool rejected{};
    try {
        (void)stale.solve(roster);
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    check(rejected && owner.primary(0)->position.x == before.x && retained != owner.primary(0),
          "stale token refused before replacement actor writes while oldlease stays alive");
    ++ownership_cases;
    std::printf("{\"checks\":%u,\"world_body_cases\":%u,\"world_boundary_cases\":%u,\"ownership_"
                "cases\":%u,\"maximum_error\":%.9g,\"game_launched\":false}\n",
                checks, world_cases, world_boundary_cases, ownership_cases, double(maximum_error));
}
