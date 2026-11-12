#pragma once
#include "positioned_pose_trails.hpp"
#include "../gameplay_effects/periodic_visuals.hpp"
namespace reo::native::gameplay_world {
class InheritedPoseTrailEffects final:public PositionedPoseTrails {
public:
    InheritedPoseTrailEffects(std::shared_ptr<World>,gameplay_effects::PeriodicVisuals&,
        gameplay_contact_world::RoomResources&,gameplay_effects::InheritedTrailActions* =nullptr);
    bool bound_to(const World&)const noexcept override;
    bool emit(const actors::EntityId&,const actors::EntityId&,std::uint8_t)override;
    bool emit_at(const actors::EntityId&,const actors::EntityId&,std::uint8_t,
        std::optional<transform_math::Vector>,std::int32_t)override;
private:
    std::shared_ptr<World> world_;gameplay_effects::PeriodicVisuals& visuals_;
    gameplay_contact_world::RoomResources& rooms_;gameplay_effects::InheritedTrailActions* actions_;
};
}
