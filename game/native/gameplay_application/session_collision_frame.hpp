#pragma once
#include "session_rooms.hpp"
#include "../gameplay_update/collision_workers.hpp"
#include "../gameplay_world/model_poses.hpp"

namespace reo::native::gameplay_application {
// The remaining collision populations and source timing flags have distinct
// producers. They are mandatory: an absent secondary population is not proof
// that the source's population is empty.
class SessionCollisionInputs {
public:
    virtual ~SessionCollisionInputs()=default;
    virtual gameplay_update::BodyFrame bodies(gameplay_update::Owner&)=0;
    virtual gameplay_update::HeightFrame secondary_heights(gameplay_update::Owner&)=0;
};

// Retains the canonical session, geometry and collision queues. The caller
// supplies the still-unimplemented phase, actor and secondary-ground owners.
// Exceptions retain the same partial frame effects as NativeSession::advance.
class SessionCollisionFrame final:private gameplay_update::CollisionParticipants {
public:
    SessionCollisionFrame(std::shared_ptr<NativeSession>,std::shared_ptr<SessionRooms>,
        gameplay_update::PhaseServices&,gameplay_world::Services&,
        SessionCollisionInputs&,gameplay_world::SecondaryCollisionWalls&);
    FrameStep advance(std::size_t script_budget=4096,std::size_t task_budget=1024);
    // Uses the application's concrete behavior owner. Missing native action
    // consumers refuse; this path never substitutes fixture callbacks.
    FrameStep advance_native_behavior(std::span<const std::int16_t> hit_timer_amounts,
        std::size_t script_budget=4096,std::size_t task_budget=1024);
    // Run the canonical behavior policy with this room's retained floors and
    // Update's own activity/gauge publication. The supplied service still
    // owns the real control, action, status and attachment effects.
    FrameStep advance_behavior(gameplay_world::BehaviorServices&,
        std::span<const std::int16_t> hit_timer_amounts,
        gameplay_world::TerminalTiming* = nullptr,gameplay_world::ProgressionTiming* = nullptr,
        gameplay_world::ZeroHealthApplication* = nullptr,
        std::size_t script_budget=4096,std::size_t task_budget=1024);
    gameplay_world::WorldBodies& bodies()noexcept{return bodies_;}
    const gameplay_update::CollisionWorkers& workers()const noexcept{return workers_;}
private:
    void verify(gameplay_update::Owner&)const;
    gameplay_update::BodyFrame bodies(gameplay_update::Owner&)override;
    gameplay_update::HeightFrame heights(gameplay_update::Owner&)override;
    gameplay_world::CollisionRoom room(gameplay_update::Owner&)override;
    FrameStep advance_impl(gameplay_world::BehaviorServices*,std::span<const std::int16_t>,
        gameplay_world::TerminalTiming*,gameplay_world::ProgressionTiming*,gameplay_world::ZeroHealthApplication*,
        std::size_t,std::size_t);
    std::shared_ptr<NativeSession> session_;
    std::shared_ptr<SessionRooms> rooms_;
    gameplay_world::Services& actors_;
    SessionCollisionInputs& inputs_;
    std::shared_ptr<gameplay_contact_world::RoomInvocation> room_lease_;
    gameplay_world::WorldBodies bodies_;
    gameplay_world::WorldModelPoses poses_;
    gameplay_update::CollisionWorkers workers_;
    bool running_{};
};
}
