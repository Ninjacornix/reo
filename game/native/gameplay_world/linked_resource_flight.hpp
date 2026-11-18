#pragma once
#include "resource_pose_work.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
// Reached operations require real owners. A known floor miss is type255;
// unavailable floor evidence is a disengaged optional, never a guessed miss.
class LinkedFlightEffects {
public:
    virtual ~LinkedFlightEffects()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)=0;
    virtual bool burst(const actors::EntityId& parent,transform_math::Vector)=0;
    virtual bool light(const actors::EntityId& parent,transform_math::Vector)=0;
    virtual bool sound(const actors::EntityId& work,std::uint8_t)=0;
    virtual bool packet(const actors::EntityId& work,std::uint8_t)=0;
};
// Complete583C50 directly updates the canonical actor/model records.
bool advance_linked_resource_flight(Actor&,ResourceModel*,std::uint8_t clock_mode,
    const actors::EntityId& work,LinkedFlightEffects&);
class LinkedResourceFlight final:public PoseWorkUpdates {
public:
    LinkedResourceFlight(World&,PoseWorkPool&,gameplay_scenario::SceneResources&,
        LinkedFlightEffects&,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseWorkPool& pool_;gameplay_scenario::SceneResources& resources_;
    LinkedFlightEffects& effects_;PoseWorkUpdates* remaining_;
};
}
