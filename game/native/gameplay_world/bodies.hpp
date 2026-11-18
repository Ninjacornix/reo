#pragma once
#include "motion.hpp"
#include "../gameplay_collision/actor_views.hpp"
#include <utility>
namespace reo::native::gameplay_world {
struct JointPose {std::vector<gameplay_collision::actors::Basis> joints;};
class BodyPoses {
public:
    virtual ~BodyPoses()=default;
    virtual std::shared_ptr<const JointPose> retain(const actors::EntityId&,const Actor&)=0;
};
gameplay_collision::actors::View body_view(Actor&,actors::EntityId,
    std::span<const gameplay_collision::actors::Basis>)noexcept;
enum class BodyStatus {completed,busy,pose_unavailable,roster_changed,invalid_geometry};
struct BodyReport {
    BodyStatus status{BodyStatus::completed};
    gameplay_collision::actors::SolveReport solve;
    actors::EntityId blocked_actor{};
};
struct RegistrationCounts {std::uint64_t accepted{},full{},retired_or_foreign{},busy{};};
// Actual motion-registration consumer. Primary actor and native pose leases are
// retained through the synchronous solve. Auxiliary callers can supply typed
// views while retaining their own native leases; no Actor projection is copied.
class WorldBodies final:public MotionServices {
public:
    explicit WorldBodies(World& w):world_(w){}
    World& world()const noexcept{return world_;}
    void enqueue(World&,Actor&,std::uint16_t collision_class,std::uint16_t source_mask)override;
    bool add(gameplay_collision::actors::Registration);
    BodyReport solve(BodyPoses&,actors::EntityId selected,bool limit_repeated,bool fast_tick,
        std::span<const gameplay_collision::actors::View> additional={});
    gameplay_collision::actors::ViewBoundary& boundary()noexcept{return boundary_;}
    std::size_t pending()const noexcept{return registry_.size();}
    bool clear()noexcept;
    const RegistrationCounts& counts()const noexcept{return counts_;}
private:
    World& world_;
    gameplay_collision::actors::ViewRegistry registry_;
    gameplay_collision::actors::ViewBoundary boundary_;
    RegistrationCounts counts_;
    std::array<actors::EntityId,32> queued_;
    bool solving_{};
};
}
