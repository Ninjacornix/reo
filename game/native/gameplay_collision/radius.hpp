#pragma once
#include "trace.hpp"
namespace reo::native::gameplay_collision::radius {
enum class Status {complete,uninitialized_point,invalid_radius,capacity,nonprogress};
struct Result {
    std::uint32_t contacts{};
    std::optional<trace::Hit> hit;
    Status status{Status::complete};
    // Last original local point write, including rejected plane intersections.
    std::optional<Vec3> scratch;
};
Result list(std::span<const response::Triangle>,std::span<const std::uint32_t>,Vec3 start,Vec3 end,float radius,
            const response::Filter&,std::optional<Vec3> initial_scratch={});
// Original wrapper stops at the first successful list, after repeated segment
// samples and exactly four endpoint-neighbor lists, then the dynamic list.
Result query(const response::Grid&,Vec3 start,Vec3 end,float radius,const response::Filter&,
             std::span<const response::Triangle> dynamic={});
}
