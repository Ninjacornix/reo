#include "actor_metadata.hpp"
#include "metadata_support.hpp"
int main() {
    std::mt19937 random(0x6f14f0);
    std::uniform_real_distribution<float> coordinate(-15000, 15000);
    std::array<a::Basis, 3> joints;
    auto& memory = storage();
    ref_write(memory.data(), 0x38ca98, 0.00009999999747378752f);
    ref_write(memory.data(), 0x241c80, 182.04444885253906f);
    ref_write(memory.data(), 0x241c88, 3.1415927410125732f);
    unsigned preserved{}, spheres{}, capsules{};
    for (unsigned i = 0; i < 8000; ++i) {
        for (auto& joint : joints)
            joint.translation = {coordinate(random), coordinate(random), coordinate(random)};
        a::Actor actor;
        actor.position = {coordinate(random), coordinate(random), coordinate(random)};
        actor.previous = {coordinate(random), coordinate(random), coordinate(random)};
        actor.joints = joints;
        actor.summary = {13, -47, 901, 487};
        if (i % 17) {
            a::ShapeDefinition definition;
            definition.kind = i % 2 ? a::ShapeKind::sphere : a::ShapeKind::capsule;
            definition.radius = float(int(i % 30) - 4);
            const auto center = [&](unsigned seed) {
                a::Center result;
                if (seed % 4)
                    result.first_joint = seed % 3;
                if (seed % 3)
                    result.second_joint = (seed + 1) % 3;
                result.first_offset = {float(seed % 21), float(seed % 7), -float(seed % 17)};
                result.second_offset = {-float(seed % 11), float(seed % 13), float(seed % 19)};
                return result;
            };
            definition.first = center(i);
            definition.second = center(i + 5);
            actor.definition = definition;
        }
        write_actor(memory.data(), actor, 0);
        ref_write(memory.data(), address(0) + 0x19c, actor.summary);
        // The standalone update must ignore any registry push left in scratch.
        ref_write(memory.data(), 0x759f60, c::Vec3{413, -871, 299});
        R5900Context ctx;
        ctx.pc = 0x6f14f0;
        ctx.g[29].lo = 0x7f0000;
        ctx.g[31].lo = 0x1234;
        ctx.g[4].lo = address(0);
        PS2Runtime runtime;
        o2_006F14F0_0x6f14f0(memory.data(), &ctx, &runtime);
        check(a::refresh_summary(a::references(actor)) == bool(actor.definition),
              "missing standalone definition preserves metadata");
        const auto original = ref_read<a::Summary>(memory.data(), address(0) + 0x19c);
        check(actor.summary.x == original.x && actor.summary.z == original.z,
              "standalone source summary uses pose without accumulated push");
        check(actor.summary.half_length == original.half_length &&
                  actor.summary.heading == original.heading,
              "standalone horizontal half-length and heading");
        if (!actor.definition)
            ++preserved;
        else if (actor.definition->kind == a::ShapeKind::sphere) {
            ++spheres;
            check(actor.summary.heading == 0 && actor.summary.half_length == 0,
                  "standalone sphere has exact zero heading");
        } else
            ++capsules;
    }
    R5900Context empty;
    empty.pc = 0x6f14f0;
    empty.g[29].lo = 0x7f0000;
    empty.g[31].lo = 0x1234;
    PS2Runtime runtime;
    o2_006F14F0_0x6f14f0(memory.data(), &empty, &runtime);
    check(empty.pc == 0x1234, "original null actor returns without mutation");
    std::printf("{\"checks\":%u,\"cases\":8000,\"spheres\":%u,\"capsules\":%u,"
                "\"missing_definition\":%u,\"maximum_error\":%g}\n",
                checks, spheres, capsules, preserved, double(maximum_error));
}
