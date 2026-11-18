#pragma once
#include "world.hpp"
#include "../gameplay_collision/postmove_view.hpp"
namespace reo::native::gameplay_world {
namespace collision=gameplay_collision;
struct CollisionRoom {
    const collision::response::Grid& walls;
    const collision::response::Grid& floors;
    const collision::regions::World& regions;
    const collision::room_objects::Owner& objects;
    collision::response::Filter filter;
    std::span<const collision::response::Triangle> dynamic;
    bool objects_enabled{},height_layers{};
};
enum class CollisionStatus {completed,pose_unavailable,geometry_unavailable};
struct CollisionResult {CollisionStatus status{CollisionStatus::completed};collision::postmove::Result policy;};
collision::postmove::View collision_view(Actor&)noexcept;
CollisionResult update_collision(Actor&,collision::postmove::Context,const CollisionRoom&);
struct CollisionPass {
    CollisionStatus status{CollisionStatus::completed};
    std::size_t visited{},eligible{},source_face_recoveries{};
    actors::EntityId failed_actor;
    collision::postmove::Result last;
};
// Primary part of the ordered primary/auxiliary/secondary height pass. Native
// pose and immutable room owners must be admitted before gameplay installation.
// A failure retains earlier actor effects and does not rerun a legacy solver.
CollisionPass update_primary_collision(World&,const CollisionRoom&);
}
