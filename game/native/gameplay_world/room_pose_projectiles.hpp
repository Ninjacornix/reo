#pragma once
#include "pose_ground_flight.hpp"
#include "pose_forward_projectile.hpp"
#include "pose_surface_follower.hpp"
#include "pose_splitting_arc.hpp"
#include "pose_presets.hpp"
#include "pose_parent_flight.hpp"
#include "packed_actor_audio.hpp"
namespace reo::native::gameplay_world {
// These reached constructors must share the actual visual/light owners. A
// missing provider is unavailable; it never manufactures successful effects.
class PoseProjectileActions {
public:
    virtual ~PoseProjectileActions()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool ground_flare(const actors::EntityId&)=0; //57F990
    virtual bool ground_trail(const actors::EntityId&)=0; //57FAA0
    virtual bool forward_visual(const actors::EntityId&)=0; //5DEF90
    virtual bool projectile_light(transform_math::Vector)=0; //6B25B0
    virtual std::optional<actors::EntityId> follower_visual(const actors::EntityId&)=0; //58DA20
    virtual bool follower_position(const actors::EntityId&,transform_math::Vector)=0;
};
class RoomPoseProjectiles final:public PoseWorkUpdates {
public:
    RoomPoseProjectiles(World&,PoseWorkPool&,gameplay_contact_world::RoomResources&,
        gameplay_collision::delivery::Packets&,const gameplay_collision::delivery::Catalog&,
        PresetPoseWork* =nullptr,PoseTrails* =nullptr,ActorOffsetSound* =nullptr,
        PackedActorAudio* =nullptr,PoseProjectileActions* =nullptr,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    struct Ground;struct Forward;struct Follower;struct Split;
    World& world_;PoseWorkPool& pool_;gameplay_contact_world::RoomResources& rooms_;
    gameplay_collision::delivery::Packets& packets_;const gameplay_collision::delivery::Catalog& catalog_;
    PresetPoseWork* presets_;PoseTrails* trails_;ActorOffsetSound* sound_;PackedActorAudio* audio_;
    PoseProjectileActions* actions_;PoseWorkUpdates* remaining_;
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector);
    bool packet(const actors::EntityId&,std::uint8_t,std::uint8_t);
    bool retire(const actors::EntityId&);
    bool emitter_absent(const actors::EntityId&)const;
};
}
