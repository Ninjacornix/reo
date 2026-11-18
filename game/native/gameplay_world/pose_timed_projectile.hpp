#pragma once
#include "pose_arcs.hpp"
#include "pose_motion.hpp"
#include "../gameplay_collision/contact_packets.hpp"
namespace reo::native::gameplay_world {
class TimedProjectileEffects {
public:
    virtual ~TimedProjectileEffects()=default;
    virtual std::optional<std::uint8_t> parent_variant(const actors::EntityId&)=0; // actual CF2
    virtual std::optional<std::uint8_t> quantum()=0;
    virtual std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector,std::uint8_t)=0;
    virtual bool packet(const actors::EntityId&,std::uint8_t descriptor,std::uint8_t bank)=0;
    virtual bool trail(const actors::EntityId&,const actors::EntityId&,std::uint8_t)=0;
    virtual bool retire(const actors::EntityId&)=0;
};
bool advance_timed_pose_projectile(Actor&,const actors::EntityId&,TimedProjectileEffects&);
class ProjectileParentVariant {
public:
    virtual ~ProjectileParentVariant()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual std::optional<std::uint8_t> read(const actors::EntityId&)=0;
};
class RoomTimedPoseProjectiles final:public PoseWorkUpdates,private TimedProjectileEffects {
public:
    RoomTimedPoseProjectiles(World&,PoseWorkPool&,gameplay_contact_world::RoomResources&,
        gameplay_collision::delivery::Packets&,const gameplay_collision::delivery::Catalog&,
        PoseTrails* =nullptr,PoseTimingQuantum* =nullptr,ProjectileParentVariant* =nullptr,PoseWorkUpdates* remaining=nullptr);
    bool bound_to(const World&)const noexcept override;
    bool update(PoseWorkPool&,const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;PoseWorkPool& pool_;gameplay_contact_world::RoomResources& rooms_;
    gameplay_collision::delivery::Packets& packets_;const gameplay_collision::delivery::Catalog& catalog_;
    PoseTrails* trails_;PoseTimingQuantum* quantum_;ProjectileParentVariant* variants_;PoseWorkUpdates* remaining_;
    std::optional<std::uint8_t> parent_variant(const actors::EntityId&)override;
    std::optional<std::uint8_t> quantum()override;
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector,std::uint8_t)override;
    bool packet(const actors::EntityId&,std::uint8_t,std::uint8_t)override;
    bool trail(const actors::EntityId&,const actors::EntityId&,std::uint8_t)override;
    bool retire(const actors::EntityId&)override;
};
}
