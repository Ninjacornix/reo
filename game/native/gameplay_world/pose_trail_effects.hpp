#pragma once
#include "pose_trail_admission.hpp"
#include "../gameplay_effects/particle_work.hpp"
namespace reo::native::gameplay_world {
// Actual578620 modes0/2/3 through canonical visual work and room floors.
// Mode1 requires the distinct five-child5789C0 inherited-motion consumer.
class MappedPoseTrailEffects final:public PoseTrails {
public:
    MappedPoseTrailEffects(World&,gameplay_effects::WorkBackend&,gameplay_contact_world::RoomResources&,PoseTrails* inherited=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool emit(const actors::EntityId&,const actors::EntityId&,std::uint8_t)override;
    bool emit_at(const actors::EntityId&,const actors::EntityId&,std::uint8_t,
        std::optional<transform_math::Vector>,std::int32_t delay);
private:
    World& world_;gameplay_effects::WorkBackend& work_;gameplay_contact_world::RoomResources& rooms_;PoseTrails* inherited_;
    std::optional<gameplay_collision::response::Floor> water_floor(transform_math::Vector);
};
std::array<float,6> pose_trail_parameters(std::uint8_t policy);
}
