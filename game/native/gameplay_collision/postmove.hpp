#pragma once
#include "footprint.hpp"
#include "regions.hpp"
namespace reo::native::gameplay_collision::postmove {
struct State {
    ownership::WallState wall;
    Vec3 wall_displacement;
    std::optional<Vec3> joint_two_position;
    float height{},surface_target{};
    std::uint32_t movement_flags{},height_flags{};
    std::uint16_t controls{},room{},route_ticks{},region{};
    std::uint8_t kind{},surface{},material{255};
    bool active{},pose_dirty{};
};
struct Context {
    std::uint16_t room{};
    bool ignore_room{},room_objects_enabled{},height_layers{};
};
struct Result {
    bool eligible{},missing_joint{};
    sweep::Status wall_status{sweep::Status::ok};
    footprint::Status footprint_status{footprint::Status::complete};
};
// Source6636D0 composed entirely from typed native collision providers. Wall
// displacement is published before height/footprint correction, as in source.
Result update(State&,Context,const actors::Basis&,const response::Grid& walls,
              const response::Grid& floors,const regions::World&,
              const room_objects::Owner&,response::Filter,
              std::span<const response::Triangle> dynamic={});
}
