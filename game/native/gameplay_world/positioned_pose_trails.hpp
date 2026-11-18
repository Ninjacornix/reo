#pragma once
#include "pose_arcs.hpp"
namespace reo::native::gameplay_world {
class PositionedPoseTrails:public PoseTrails {
public:
    virtual bool emit_at(const actors::EntityId&,const actors::EntityId&,std::uint8_t,
        std::optional<transform_math::Vector>,std::int32_t)=0;
};
}
