#pragma once
#include "response.hpp"
namespace reo::native::gameplay_collision::trace {
struct SegmentResult {bool hit{};std::optional<Vec3> written_point;std::optional<std::uint8_t> side;};
bool angle_contains(const response::Triangle&,Vec3)noexcept;
SegmentResult triangle(const response::Triangle&,Vec3 start,Vec3 end,std::uint8_t side=0)noexcept;
enum class SamplingStatus {complete,left_grid,nonprogress,capacity};
struct Cell {std::uint32_t column{},row{};};
struct Samples {std::vector<Cell> cells;SamplingStatus status{SamplingStatus::complete};};
Samples sample(const response::Grid&,Vec3,Vec3,bool floor_bank=false,std::size_t capacity=256);
struct Hit {Vec3 point,normal;std::uint32_t type{};std::uint32_t triangle{};};
struct ListResult {std::uint32_t count{};std::optional<Hit> nearest;};
ListResult list(std::span<const response::Triangle>,std::span<const std::uint32_t>,Vec3,Vec3,
                const response::Filter&,bool two_sided=false);
struct Result {std::optional<Hit> hit;SamplingStatus status{SamplingStatus::complete};};
// Wall calls retain source list order, repeated cells and dynamic-last order.
// Shorten refines the endpoint after each list. Any stops at its first hit.
Result shorten(const response::Grid&,Vec3,Vec3,const response::Filter&,
               std::span<const response::Triangle> dynamic={});
Result any(const response::Grid&,Vec3,Vec3,const response::Filter&,
           std::span<const response::Triangle> dynamic={});
// Floor nearest is list-local: the first successful sampled list wins.
Result floor(const response::Grid&,Vec3,Vec3);
bool floor_any(const response::Grid&,Vec3,Vec3,std::uint8_t required=255,std::uint8_t excluded=255);
}
