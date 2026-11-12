#pragma once
#include "pose_arcs.hpp"
namespace reo::native::gameplay_world {
struct ParentFlightLaunch {std::uint8_t primary{},secondary{};transform_math::Matrix basis;};
class ParentFlightEffects {
public:
    virtual ~ParentFlightEffects()=default;
    virtual std::optional<ParentFlightLaunch> launch(const actors::EntityId&)=0;
    virtual std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)=0;
    virtual bool trail(const actors::EntityId&,const actors::EntityId&,std::uint8_t)=0;
    virtual bool sound(const actors::EntityId&,std::uint8_t)=0;
};
enum class ParentFlightStep {completed,retire,unavailable};
ParentFlightStep advance_parent_pose_flight(Actor&,const actors::EntityId&,std::uint8_t clock_mode,ParentFlightEffects&);
class ActorOffsetSound {
public:
    virtual ~ActorOffsetSound()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    // Complete1B9310; actual source33/554 producer is required where reached.
    virtual bool sound(const actors::EntityId&,std::uint8_t event)=0;
};
class RoomParentPoseFlight final:public PoseWorkUpdates,private ParentFlightEffects {
public:
    RoomParentPoseFlight(World&,PoseWorkPool&,gameplay_contact_world::RoomResources&,PoseTrails* =nullptr,ActorOffsetSound* =nullptr,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseWorkPool& pool_;gameplay_contact_world::RoomResources& rooms_;
    PoseTrails* trails_;ActorOffsetSound* sound_;PoseWorkUpdates* remaining_;
    std::optional<ParentFlightLaunch> launch(const actors::EntityId&)override;
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)override;
    bool trail(const actors::EntityId&,const actors::EntityId&,std::uint8_t)override;
    bool sound(const actors::EntityId&,std::uint8_t)override;
};
}
