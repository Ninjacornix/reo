#pragma once
#include "collision.hpp"
namespace reo::native::gameplay_collision::response {
// Native shape value built from native joint/root positions. Derived fields
// retain original rounding/order; callers do not supply guest shape workspaces.
struct Capsule {
    Vec3 start, end;
    float radius{};
    Vec3 direction, midpoint;
    float bound_radius{};
};
Capsule make_capsule(Vec3 start, Vec3 end, float radius) noexcept;
std::optional<Contact> capsule_sphere(Capsule, Sphere) noexcept;
std::optional<Contact> capsules(Capsule, Capsule) noexcept;
struct Triangle { std::uint32_t flags{}; std::array<Vec3,3> vertices; Vec3 normal; float plane_d{}; };
struct Floor {
    float height{};
    Vec3 normal{0,1,0};
    std::uint8_t type{255}, material{255};
    std::uint16_t attributes{};
    std::optional<std::uint32_t> triangle;
};
Floor floor_at(Vec3, std::span<const Triangle>, std::uint8_t required_type=255) noexcept;
struct DynamicSlot { std::uint8_t kind{}, state{}; };
struct Filter {
    std::uint32_t include{0xffffffffu}, exclude{}, disabled{};
    bool dynamic_kind_gate{};
    std::array<DynamicSlot,16> slots{};
};
bool admits(std::uint32_t triangle_flags, const Filter&) noexcept;
class Grid {
public:
    struct Header { std::uint32_t step_x{}, step_z{}, columns{}, rows{}, origin_x{}, origin_z{}; };
    static Grid import(std::span<const std::byte>);
    const Header& header()const noexcept{return header_;}
    bool contains(Vec3)const noexcept;
    std::span<const std::uint32_t> cell(Vec3)const noexcept;
    std::span<const Triangle> triangles()const noexcept{return triangles_;}
    Floor floor(Vec3, std::uint8_t required_type=255)const noexcept;
private:
    Header header_;
    std::vector<Triangle> triangles_;
    std::vector<std::vector<std::uint32_t>> cells_;
};
}
