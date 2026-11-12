#pragma once
#include "pose_arcs.hpp"
namespace reo::native::gameplay_world {
class SplittingArcEffects {
public:
    virtual ~SplittingArcEffects()=default;
    virtual std::optional<transform_math::Vector> primary_zero_position()=0;
    virtual std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)=0;
    virtual bool packet(const actors::EntityId&,std::uint8_t,std::uint8_t)=0;
    virtual bool trail(const actors::EntityId&,const actors::EntityId&,std::uint8_t)=0;
    virtual bool sound(const actors::EntityId&,std::uint8_t)=0;
    virtual bool preset(const actors::EntityId&,const transform_math::Matrix&,transform_math::Vector,const std::array<std::int16_t,4>&,std::uint8_t,std::uint8_t)=0;
    virtual bool retire(const actors::EntityId&)=0;
};
bool advance_splitting_pose_arc(Actor&,const actors::EntityId&,SplittingArcEffects&);
}
