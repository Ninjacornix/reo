#pragma once
#include "pose_work_pool.hpp"
#include "../gameplay_contact_world/contacts.hpp"
namespace reo::native::gameplay_world {
class PoseTrails {
public:
    virtual ~PoseTrails()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool emit(const actors::EntityId& parent,const actors::EntityId& work,std::uint8_t mode)=0;
};
class PoseArcEffects {
public:
    virtual ~PoseArcEffects()=default;
    virtual std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)=0;
    virtual bool trail(const actors::EntityId&,const actors::EntityId&,std::uint8_t)=0;
};
enum class PoseArcStep {completed,retire,unavailable,unhandled};
// Complete5833B0 value operation and583430/5835E0 callback policies.
void integrate_rotated_pose_velocity(Actor&);
PoseArcStep advance_quarter_turn_pose_arc(Actor&,std::uint8_t,const actors::EntityId&,PoseArcEffects&);
class RoomPoseArcs final:public PoseWorkUpdates,private PoseArcEffects {
public:
    RoomPoseArcs(World&,PoseWorkPool&,gameplay_contact_world::RoomResources&,PoseTrails* =nullptr,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseWorkPool& pool_;gameplay_contact_world::RoomResources& rooms_;PoseTrails* trails_;PoseWorkUpdates* remaining_;
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)override;
    bool trail(const actors::EntityId&,const actors::EntityId&,std::uint8_t)override;
};
}
