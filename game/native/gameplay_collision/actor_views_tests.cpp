#include "actor_views.hpp"
#include "actors_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <random>
namespace c = reo::native::gameplay_collision;
namespace a = c::actors;
unsigned checks{}, byte_view_cases{};
float maximum_error{};
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "actor collision check %u failed: %s\n", checks, why);
        std::exit(1);
    }
}
std::vector<std::uint8_t>& storage() {
    static std::vector<std::uint8_t> value(0x800000);
    return value;
}
std::uint32_t address(unsigned index) {
    return 0x10000 + 0x2000 * index;
}
void write_actor(std::uint8_t* memory, const a::Actor& actor, unsigned index) {
    const auto at = address(index);
    std::fill(memory + at, memory + at + 0x2000, 0);
    std::memcpy(memory + at + 0x38, &actor.position, 12);
    std::memcpy(memory + at + 0x44, &actor.previous, 12);
    std::memcpy(memory + at + 0xa8, &actor.candidate_direction, 12);
    memory[at + 2] = actor.actor_class;
    memory[at + 0x199] = actor.priority;
    memory[at + 0x1e1] = actor.separation_count;
    memory[at + 0xc53] = actor.contact;
    if (actor.definition) {
        const auto& definition = *actor.definition;
        const auto descriptor = 0x50000 + index * 64;
        ref_write(memory, at + 0x1a8, descriptor);
        ref_write(memory, descriptor,
                  std::uint16_t(definition.kind == a::ShapeKind::sphere ? 0 : 1));
        ref_write(memory, descriptor + 2, std::int16_t(definition.radius));
        const auto joint = [](std::optional<std::uint16_t> j) {
            return j ? std::uint8_t(*j) : std::uint8_t(255);
        };
        memory[descriptor + 4] = joint(definition.first.first_joint);
        memory[descriptor + 5] = joint(definition.first.second_joint);
        memory[descriptor + 6] = joint(definition.second.first_joint);
        memory[descriptor + 7] = joint(definition.second.second_joint);
        ref_write(memory, descriptor + 8, definition.first.first_offset);
        ref_write(memory, descriptor + 20, definition.first.second_offset);
        ref_write(memory, descriptor + 32, definition.second.first_offset);
        ref_write(memory, descriptor + 44, definition.second.second_offset);
    }
    const auto model = 0x90000 + index * 0x1000;
    ref_write(memory, at + 0x34, model);
    for (unsigned j = 0; j < actor.joints.size(); ++j) {
        const auto matrix = 0xb0000 + index * 0x1000 + j * 64;
        ref_write(memory, model + 0x820 + 4 * j, matrix);
        const auto& basis = actor.joints[j];
        std::array<float, 16> raw{basis.x.x,           basis.x.y,           basis.x.z,           0,
                                  basis.y.x,           basis.y.y,           basis.y.z,           0,
                                  basis.z.x,           basis.z.y,           basis.z.z,           0,
                                  basis.translation.x, basis.translation.y, basis.translation.z, 1};
        std::memcpy(memory + matrix, raw.data(), 64);
    }
}
void vector_equal(c::Vec3 native, c::Vec3 original, const char* why) {
    const auto axis = [&](float x, float y) {
        const auto error = std::abs(x - y);
        maximum_error = std::max(maximum_error, error);
        if (!(error <= 0.0002f + std::abs(y) * 0.00001f))
            std::fprintf(stderr, "native=%g original=%g\n", double(x), double(y));
        check(error <= 0.0002f + std::abs(y) * 0.00001f, why);
    };
    axis(native.x, original.x);
    axis(native.y, original.y);
    axis(native.z, original.z);
}
void compare(std::vector<a::Actor> actors, std::span<const a::Registration> registrations,
             bool limited, bool fast) {
    auto& memory = storage();
    memory[64] = limited;
    memory[0x3243cc] = fast;
    memory[0x3b5370] = 0;
    ref_write(memory.data(), 0x742e80, 0.0010000000474974513f);
    ref_write(memory.data(), 0x38ca98, 0.00009999999747378752f);
    ref_write(memory.data(), 0x241c80, 182.04444885253906f);
    ref_write(memory.data(), 0x241c88, 3.1415927410125732f);
    for (unsigned i = 0; i < actors.size(); ++i)
        write_actor(memory.data(), actors[i], i);
    std::fill(memory.begin() + 0x759f60, memory.begin() + 0x759f60 + 32 * 12, 0);
    for (unsigned i = 0; i < actors.size(); ++i)
        if (actors[i].definition && actors[i].definition->radius > 0) {
            R5900Context built;
            built.pc = 0x6efde0;
            built.g[29].lo = 0x7f0000;
            built.g[31].lo = 0x1234;
            built.g[4].lo = address(i);
            built.g[5].lo = 0x8000;
            built.g[6].lo = i;
            PS2Runtime runtime;
            o2_006EFDE0_0x6efde0(memory.data(), &built, &runtime);
            const auto native = a::build(actors[i], *actors[i].definition);
            c::response::Capsule expected;
            if (const auto* sphere = std::get_if<c::Sphere>(&native))
                expected =
                    c::response::make_capsule(sphere->center, sphere->center, sphere->radius);
            else
                expected = std::get<c::response::Capsule>(native);
            vector_equal(expected.start, ref_read<c::Vec3>(memory.data(), 0x8000),
                         "original joint/root shape start");
            vector_equal(expected.end, ref_read<c::Vec3>(memory.data(), 0x800c),
                         "original joint/root shape end");
            vector_equal(expected.midpoint, ref_read<c::Vec3>(memory.data(), 0x8028),
                         "original joint/root shape midpoint");
            check(expected.bound_radius == ref_read<float>(memory.data(), 0x8034),
                  "original world shape bound");
        }
    ref_write(memory.data(), 0x3b53b0, std::uint16_t(registrations.size()));
    a::ViewRegistry registry;
    for (unsigned i = 0; i < registrations.size(); ++i) {
        const auto& entry = registrations[i];
        check(registry.add(entry), "native original-capacity registration accepted");
        unsigned actor{};
        for (; actor < actors.size() && actors[actor].id != entry.actor; ++actor) {
        }
        check(actor < actors.size(), "reference identity resolves to actor");
        ref_write(memory.data(), 0x3b53c0 + 8 * i, entry.source_mask);
        ref_write(memory.data(), 0x3b53c2 + 8 * i, entry.collision_class);
        ref_write(memory.data(), 0x3b53c4 + 8 * i, address(actor));
    }
    const auto before = actors;
    R5900Context ctx;
    ctx.pc = 0x6ef150;
    ctx.g[29].lo = 0x7f0000;
    ctx.g[31].lo = 0x1234;
    PS2Runtime runtime;
    o2_006EF150_0x6ef150(memory.data(), &ctx, &runtime);
    std::vector<a::View> views;
    for (auto& actor : actors)
        views.push_back(a::references(actor));
    (void)registry.solve(views, limited, fast);
    check(registry.size() == 0 && ref_read<std::uint16_t>(memory.data(), 0x3b53b0) == 0,
          "contact registration drains per update");
    for (unsigned i = 0; i < actors.size(); ++i) {
        const auto at = address(i);
        const auto reference = ref_read<c::Vec3>(memory.data(), at + 0x38);
        if (std::abs(actors[i].position.x - reference.x) > 0.0002f ||
            std::abs(actors[i].position.z - reference.z) > 0.0002f) {
            for (unsigned j = 0; j < actors.size(); ++j)
                std::fprintf(
                    stderr,
                    "actor%u class%u regclass%u mask%u priority%u shape%u radius%g "
                    "before(%g,%g,%g) native(%g,%g,%g) original(%g,%g,%g)\n",
                    j, unsigned(before[j].actor_class), unsigned(registrations[j].collision_class),
                    unsigned(registrations[j].source_mask), unsigned(before[j].priority),
                    unsigned(before[j].definition->kind), double(before[j].definition->radius),
                    double(before[j].position.x), double(before[j].position.y),
                    double(before[j].position.z), double(actors[j].position.x),
                    double(actors[j].position.y), double(actors[j].position.z),
                    double(ref_read<float>(memory.data(), address(j) + 0x38)),
                    double(ref_read<float>(memory.data(), address(j) + 0x3c)),
                    double(ref_read<float>(memory.data(), address(j) + 0x40)));
        }
        vector_equal(actors[i].position, reference, "original registry actor displacement order");
        check(actors[i].contact == bool(memory[at + 0xc53]), "original class-zero contact flag");
        check(actors[i].separation_count == memory[at + 0x1e1],
              "original pair priority/repeated-contact counter");
        check(actors[i].summary.x == ref_read<float>(memory.data(), at + 0x19c) &&
                  actors[i].summary.z == ref_read<float>(memory.data(), at + 0x1a0),
              "original collision midpoint summary");
        if (actors[i].summary.half_length != ref_read<std::uint16_t>(memory.data(), at + 0x1a4) ||
            actors[i].summary.heading != ref_read<std::uint16_t>(memory.data(), at + 0x1a6))
            std::fprintf(stderr, "summary actor%u half %u/%u heading %u/%u\n", i,
                         unsigned(actors[i].summary.half_length),
                         unsigned(ref_read<std::uint16_t>(memory.data(), at + 0x1a4)),
                         unsigned(actors[i].summary.heading),
                         unsigned(ref_read<std::uint16_t>(memory.data(), at + 0x1a6)));
        check(actors[i].summary.half_length == ref_read<std::uint16_t>(memory.data(), at + 0x1a4) &&
                  actors[i].summary.heading == ref_read<std::uint16_t>(memory.data(), at + 0x1a6),
              "original horizontal length/heading summary");
        if (actors[i].contact && actors[i].actor_class == 0) {
            const auto peer = ref_read<std::uint32_t>(memory.data(), at + 0xc54);
            check(peer >= address(0) && (peer - address(0)) % 0x2000 == 0,
                  "original contact peer is registered native actor");
            check(actors[i].peer == actors[(peer - address(0)) / 0x2000].id,
                  "original contact peer identity");
        }
    }
}
void byte_views(std::span<const a::EntityId> ids) {
    struct Position {
        float x{}, y{}, z{};
    };
    auto& memory = storage();
    for (const auto category : {std::uint8_t(0), std::uint8_t(2)}) {
        a::Actor backing;
        backing.id = ids[0];
        backing.position = {1, 2, 3};
        backing.previous = {1, 2, 3};
        backing.actor_class = category;
        backing.definition = a::ShapeDefinition{};
        backing.definition->radius = 5;
        Position position{1, 2, 3}, previous{1, 2, 3}, direction{0, 0, 1};
        std::uint8_t contact = 0xa5, boundary = 0x81;
        a::View view{backing.id,
                     position,
                     previous,
                     direction,
                     {},
                     backing.definition,
                     backing.actor_class,
                     backing.priority,
                     backing.separation_count,
                     contact,
                     backing.peer,
                     backing.room,
                     backing.summary,
                     boundary};
        check(&view.position.x == &position.x && &view.previous.z == &previous.z,
              "genericXYZrefs borrow exact scalar members without casts");
        write_actor(memory.data(), backing, 0);
        memory[address(0) + 0xc53] = contact;
        ref_write(memory.data(), 0x3b53b0, std::uint16_t(1));
        ref_write(memory.data(), 0x3b53c0, std::uint16_t(0));
        ref_write(memory.data(), 0x3b53c2, std::uint16_t(1));
        ref_write(memory.data(), 0x3b53c4, address(0));
        std::fill(memory.begin() + 0x759f60, memory.begin() + 0x759f60 + 32 * 12, 0);
        a::ViewRegistry registry;
        check(registry.add({ids[0], 0, 1}), "byteview registration");
        (void)registry.solve(std::span(&view, 1));
        R5900Context ctx;
        ctx.pc = 0x6ef150;
        ctx.g[29].lo = 0x7f0000;
        ctx.g[31].lo = 0x1234;
        PS2Runtime runtime;
        o2_006EF150_0x6ef150(memory.data(), &ctx, &runtime);
        check(contact == memory[address(0) + 0xc53] && contact == (category == 0 ? 0 : 0xa5),
              "actualC53byte clears only forclasszero and preserves otherbytes");
        ++byte_view_cases;
    }
    std::array<a::Actor, 4> backing;
    std::array<Position, 4> positions, previous, direction;
    std::array<std::uint8_t, 4> contacts, boundaries;
    std::vector<a::View> views;
    for (unsigned i = 0; i < 4; ++i) {
        backing[i].id = ids[i];
        backing[i].room = 1;
        positions[i] = {0, -900, float(i == 0 ? 1000 : i == 1 ? 1200 : 700)};
        previous[i] = positions[i];
        contacts[i] = 0xa5;
        boundaries[i] = 0x81;
        views.push_back({ids[i],
                         positions[i],
                         previous[i],
                         direction[i],
                         {},
                         backing[i].definition,
                         backing[i].actor_class,
                         backing[i].priority,
                         backing[i].separation_count,
                         contacts[i],
                         backing[i].peer,
                         backing[i].room,
                         backing[i].summary,
                         boundaries[i]});
        const auto at = 0x4a5c30 + 0x10e0 * i;
        ref_write(memory.data(), at + 0x38, positions[i]);
        ref_write(memory.data(), at + 0x1e2, std::uint16_t(1));
        memory[at + 0x10a9] = boundaries[i];
    }
    memory[65] = 0;
    memory[0x4baded] = 1;
    ref_write(memory.data(), 0x4baea0, 4u);
    ref_write(memory.data(), 0x3b5374, 0x4a5c30u);
    a::ViewBoundary boundary;
    check(boundary.set(0, ids[0]), "byte-boundary owner admitted");
    boundary.apply(views, false, 1, ids[1]);
    R5900Context ctx;
    ctx.pc = 0x6f1750;
    ctx.g[29].lo = 0x7f0000;
    ctx.g[31].lo = 0x1234;
    ctx.g[4].lo = 0x3b5370;
    PS2Runtime runtime;
    o2_006F1750_0x6f1750(memory.data(), &ctx, &runtime);
    for (unsigned i = 0; i < 4; ++i) {
        const auto at = 0x4a5c30 + 0x10e0 * i;
        vector_equal({positions[i].x, positions[i].y, positions[i].z},
                     ref_read<c::Vec3>(memory.data(), at + 0x38),
                     "genericXYZboundary writes remain direct");
        check(boundaries[i] == memory[at + 0x10a9] && boundaries[i] == (i == 1 ? 1 : 0x81),
              "actual10A9byte publishesone or preserves originalnonzero");
    }
    ++byte_view_cases;
}

int main() {
    using namespace reo::native::gameplay_actors;
    EntityStore owner;
    std::array<EntityId, 4> ids;
    for (unsigned i = 0; i < ids.size(); ++i)
        ids[i] = owner.create(std::make_unique<Entity>()).id;
    std::array<a::Basis, 2> joints;
    std::mt19937 random(0x6ef150);
    const auto scalar = [&] { return float(int(random() % 2001) - 1000) / 100; };
    for (unsigned iteration = 0; iteration < 1000; ++iteration) {
        for (auto& basis : joints) {
            basis = {};
            basis.translation = {scalar(), scalar(), scalar()};
            basis.x.x = 0.5f + float(random() % 4) * 0.5f;
            basis.y.y = 1;
            basis.z.z = 1;
        }
        std::vector<a::Actor> actors(4);
        std::vector<a::Registration> registrations;
        for (unsigned i = 0; i < 4; ++i) {
            auto& actor = actors[i];
            actor.id = ids[i];
            actor.position = {scalar(), scalar(), scalar()};
            actor.previous = {actor.position.x + scalar() / 4, actor.position.y,
                              actor.position.z + scalar() / 4};
            actor.candidate_direction = {scalar(), scalar(), scalar()};
            actor.joints = joints;
            actor.actor_class = std::uint8_t(random() % 3);
            actor.priority = std::uint8_t(random() % 3);
            actor.separation_count = std::uint8_t(random() % 125);
            actor.contact = random() % 2;
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
        const bool limited = random() % 2, fast = random() % 2;
        compare(actors, registrations, limited, fast);
    }
    for (unsigned iteration = 0; iteration < 200; ++iteration) {
        std::vector<a::Actor> roster(4);
        auto& memory = storage();
        memory[65] = iteration % 2;
        ref_write(memory.data(), 0x4baea0, 4u);
        ref_write(memory.data(), 0x3243dc, std::uint16_t(1));
        memory[0x4baded] = iteration % 4;
        for (unsigned i = 0; i < 4; ++i) {
            roster[i].id = ids[i];
            roster[i].position = {0, -900 + float(random() % 61), float(random() % 1000)};
            roster[i].room = std::uint16_t(random() % 3);
            const auto at = 0x4a5c30 + 0x10e0 * i;
            ref_write(memory.data(), at + 0x38, roster[i].position);
            ref_write(memory.data(), at + 0x1e2, roster[i].room);
            memory[at + 0x10a9] = 0;
        }
        const auto owner = iteration % 4;
        ref_write(memory.data(), 0x3b5374, std::uint32_t(0x4a5c30 + 0x10e0 * owner));
        a::ViewBoundary boundary;
        check(boundary.set(0, ids[owner]), "native auxiliary boundary kind zero");
        std::vector<a::View> views;
        for (auto& actor : roster)
            views.push_back(a::references(actor));
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
            vector_equal(roster[i].position, ref_read<c::Vec3>(memory.data(), at + 0x38),
                         "original auxiliary boundary order/room/mode");
            check(roster[i].boundary_clamped == bool(memory[at + 0x10a9]),
                  "original auxiliary boundary flag");
        }
    }
    a::ViewRegistry registry;
    for (unsigned i = 0; i < 32; ++i)
        check(registry.add({ids[0], 1, 1}), "original registry32capacity");
    check(!registry.add({ids[0], 1, 1}), "33rdregistryrecord refused");
    registry.clear();
    a::Actor actor;
    actor.id = ids[0];
    a::ViewRegistry stale;
    check(stale.add({owner.create(std::make_unique<Entity>()).id, 1, 1}),
          "foreign-generation test admission");
    auto view = a::references(actor);
    bool rejected{};
    try {
        (void)stale.solve(std::span(&view, 1));
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    check(rejected && actor.position.x == 0,
          "stale actor generation refused before state publication");
    byte_views(ids);
    a::ShapeDefinition root;
    root.radius = 5;
    actor.definition = root;
    actor.position = {2, 3, 4};
    const auto root_shape = a::build(actor, root);
    check(std::get<c::Sphere>(root_shape).center.x == 2,
          "root fallback ignores unused local offsets");
    std::printf(
        "{\"checks\":%u,\"maximum_error\":%.9g,\"registry_cases\":1000,\"byte_view_cases\":%u,"
        "\"boundary_cases\":200,\"declared_identity_math_ports\":true,\"game_launched\":false}\n",
        checks, double(maximum_error), byte_view_cases);
}
