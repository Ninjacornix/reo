#pragma once
#include "room_objects.hpp"
#include "trace.hpp"
namespace reo::native::gameplay_collision::room_geometry {
struct Quads {Quad expanded,first,second,exact;};
std::optional<Quads> quads(const room_objects::Owner&,const room_objects::Object&)noexcept;
struct ProxyDescriptions {std::array<std::optional<ownership::Record>,4> records;bool missing_owner{};};
struct Instance {gameplay_actors::EntityId id;Vec3 position;std::uint8_t object_ordinal{};};
ProxyDescriptions proxies(const room_objects::Owner&,const room_objects::Object&,Instance);
struct Occupant {Vec3 position;bool active{},visible{};};
room_objects::Grid::Mask combined_occupancy(const room_objects::Owner&,std::span<const Occupant>);
struct Prism {
    std::array<Vec3,8> vertices;
    std::array<response::Triangle,8> triangles;
    std::array<bool,4> inflated{};
    trace::SamplingStatus status{trace::SamplingStatus::complete};
};
Prism prism(const room_objects::Owner&,const room_objects::Object&,const response::Grid& walls,
            response::Filter,std::span<const response::Triangle> existing={});
struct Dynamic {
    std::array<response::Triangle,31> storage;
    std::uint8_t count{};
    std::uint32_t attempted{},dropped{};
    trace::SamplingStatus status{trace::SamplingStatus::complete};
    std::span<const response::Triangle> triangles()const noexcept{return std::span(storage).first(count);}
};
Dynamic build_dynamic(const room_objects::Owner&,std::uint16_t room,const response::Grid& walls,response::Filter);
}
