#pragma once
#include "pose_work_pool.hpp"
namespace reo::native::gameplay_world {
class ForwardProjectileEffects {
public:
    virtual ~ForwardProjectileEffects()=default;
    virtual bool visual(const actors::EntityId&)=0; // actual5DEF90
    virtual bool sound(const actors::EntityId&,std::uint8_t)=0; // actual1BA5E0
    virtual bool packet(const actors::EntityId&,std::uint8_t,std::uint8_t)=0;
    virtual bool light(transform_math::Vector)=0; // actual6B25B0
    virtual bool retire(const actors::EntityId&)=0;
};
bool advance_forward_pose_projectile(Actor&,const actors::EntityId&,ForwardProjectileEffects&);
}
