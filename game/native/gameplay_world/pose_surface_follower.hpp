#pragma once
#include "pose_work_pool.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
class SurfaceFollowerEffects {
public:
    virtual ~SurfaceFollowerEffects()=default;
    // nullopt is unknown; an engaged empty ID is actual known allocation full.
    virtual std::optional<actors::EntityId> visual(const actors::EntityId&)=0;
    virtual std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)=0;
    virtual bool position(const actors::EntityId&,transform_math::Vector)=0;
    virtual bool retire(const actors::EntityId&)=0;
};
bool advance_pose_surface_follower(Actor&,const actors::EntityId&,SurfaceFollowerEffects&);
}
