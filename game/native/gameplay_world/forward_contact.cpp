#include "forward_contact.hpp"
#include "../gameplay_collision/trace.hpp"
#include "../transform_math/transform_math.hpp"
#include <bit>

namespace reo::native::gameplay_world {
ForwardContactResult probe_forward_contact(
    Actor& actor, const gameplay_collision::response::Grid& walls,
    std::uint32_t include, std::uint32_t exclude, float signed_offset,
    std::span<const gameplay_collision::response::Triangle> dynamic) {
    // 65F4C4's delay slot preserves f12 even when a1 is nonzero. A zero
    // include mask is replaced by FFFF003E; a2 remains the exclude mask.
    if (!include) include=0xffff003eu;
    const auto start=gameplay_collision::Vec3{actor.position.x,actor.position.y,actor.position.z};
    // 65F4D8/65F4F0 pass LH(+92) through 3700C0/370100. Those helpers
    // ANDI the signed halfword with FFFF, CVT.S.W that unsigned turn, then
    // multiply by the o0 constant at38B290 (0x38C90FDB) before trig.
    constexpr float turn_radians=std::bit_cast<float>(0x38c90fdbu);
    const auto turn=std::bit_cast<std::uint16_t>(actor.orientation[1]);
    const auto wave=transform_math::sin_cos(turn_radians*float(turn));
    const auto end=gameplay_collision::Vec3{
        start.x+signed_offset*wave.sine, start.y+10.0f,
        start.z+signed_offset*wave.cosine};
    gameplay_collision::response::Filter filter;
    filter.include=include; filter.exclude=exclude;
    const auto query=gameplay_collision::trace::shorten(walls,start,end,filter,dynamic);
    //579730 returns the accumulated cell count when sampling exits the grid.
    //The trace wrapper still consumes those cells and the dynamic list.
    if (query.status==gameplay_collision::trace::SamplingStatus::capacity||
        query.status==gameplay_collision::trace::SamplingStatus::nonprogress) return {};

    if (!query.hit) {
        actor.forward_contact_status=0;
        return {ForwardContactStatus::completed,0};
    }
    actor.projectile_contact.point=query.hit->point;
    actor.projectile_contact.normal=query.hit->normal;
    actor.forward_contact_status=1;
    return {ForwardContactStatus::completed,
            static_cast<std::uint16_t>(query.hit->type)};
}
}
