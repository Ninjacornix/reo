#pragma once
#include "pose_work_pool.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
class GroundPoseEffects {
public:
    virtual ~GroundPoseEffects()=default;
    virtual std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)=0;
    virtual bool packet(const actors::EntityId&,std::uint8_t descriptor,std::uint8_t bank)=0;
    virtual bool flare(const actors::EntityId&)=0; // actual57F990
    virtual bool trail(const actors::EntityId&)=0; // actual57FAA0
    virtual bool retire(const actors::EntityId&)=0;
    virtual bool sound(const actors::EntityId&,std::uint8_t)=0; // actual1B9310
};
// Complete583030 including initial-only floor caching and retire-before-sound.
bool advance_ground_pose_flight(Actor&,const actors::EntityId&,GroundPoseEffects&);
}
