#pragma once
#include "update.hpp"
#include "../gameplay_world/bodies.hpp"
#include "../gameplay_world/collision_phase.hpp"
#include "../gameplay_world/target_metrics.hpp"
#include <stdexcept>
namespace reo::native::gameplay_update {
struct AdditionalBody {
    world::actors::EntityId id;
    std::shared_ptr<world::Actor> actor;
    std::shared_ptr<const world::JointPose> pose;
};
struct BodyFrame {
    std::vector<AdditionalBody> additional;
    world::actors::EntityId selected;
    bool limit_repeated{},fast_tick{};
};
struct HeightFrame {
    std::vector<std::shared_ptr<world::Actor>> auxiliary;
    // Native entity leases keep each secondary Entry's referenced fields live.
    std::vector<std::shared_ptr<world::actors::Entity>> secondary_owners;
    std::vector<gameplay_collision::ground::Entry> secondary;
};
class CollisionParticipants {
public:
    virtual ~CollisionParticipants()=default;
    // The actual native scene owner acquires identities/leases at each phase,
    // after earlier script/actor mutations. Stale lookups must fail admission.
    virtual BodyFrame bodies(Owner&)=0;
    virtual HeightFrame heights(Owner&)=0;
    // Immutable geometry and dynamic-triangle spans remain owned by this scene
    // provider and must outlive the synchronous worker invocation.
    virtual world::CollisionRoom room(Owner&)=0;
};
enum class CollisionProgress {never_run,acquiring,completed,failed};
class CollisionWorkers final:public PhaseServices {
public:
    CollisionWorkers(world::World& world,PhaseServices& remaining,world::WorldBodies& bodies,
        world::BodyPoses& poses,CollisionParticipants& participants,world::SecondaryCollisionWalls& walls):
        world_(world),remaining_(remaining),bodies_(bodies),poses_(poses),participants_(participants),walls_(walls){
        if(&bodies.world()!=&world)throw std::invalid_argument("Collision queue belongs to another native World");
    }
    void run(Worker,Owner&)override;
    bool button(Button,Owner&)override;
    bool transition_request(Owner&)override;
    void effect(PhaseEffect,Owner&,std::uint32_t=0)override;
    const std::optional<world::TargetMetricReport>& last_targets()const noexcept{return target_result_;}
    const std::optional<world::BodyReport>& last_bodies()const noexcept{return body_result_;}
    const std::optional<world::HeightReport>& last_heights()const noexcept{return height_result_;}
    CollisionProgress body_progress()const noexcept{return body_progress_;}
    CollisionProgress height_progress()const noexcept{return height_progress_;}
    CollisionProgress target_progress()const noexcept{return target_progress_;}
private:
    void verify(Owner&)const;
    world::World& world_;PhaseServices& remaining_;world::WorldBodies& bodies_;
    world::BodyPoses& poses_;CollisionParticipants& participants_;world::SecondaryCollisionWalls& walls_;
    std::optional<world::BodyReport> body_result_;std::optional<world::HeightReport> height_result_;
    std::optional<world::TargetMetricReport> target_result_;
    CollisionProgress body_progress_{},height_progress_{},target_progress_{};
};
}
