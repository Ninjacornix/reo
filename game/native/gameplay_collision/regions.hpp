#pragma once
#include "collision.hpp"
namespace reo::native::gameplay_collision::regions {
struct Vertex {std::int32_t x{},y{},z{};};
struct Plane {Vec3 vertex,normal;bool valid{};};
struct Region {
    std::uint8_t priority{},flags{1};
    std::uint16_t selector{};
    std::array<Vertex,8> vertices;
    std::array<Plane,6> planes;
};
struct Auxiliary {std::uint8_t active{},mode{};std::uint16_t first{},second{};Vec3 position;};
struct Defaults {std::uint16_t selector{};std::uint8_t mode{},variant{},weight{};std::uint32_t flags{0x80000000u};};
Region prepare(std::uint8_t priority,std::uint16_t selector,std::array<Vertex,8>)noexcept;
bool contains(const Region&,Vec3)noexcept;
class World {
public:
    static World import(std::span<const std::byte> section);
    std::uint16_t select(std::optional<Vec3>)const noexcept;
    std::span<const Region> regions()const noexcept{return regions_;}
    std::span<const Auxiliary> auxiliary()const noexcept{return auxiliary_;}
    const Defaults& defaults()const noexcept{return defaults_;}
private:
    std::vector<Region> regions_;
    std::vector<Auxiliary> auxiliary_;
    Defaults defaults_;
};
}
