#pragma once
#include "common_actor_frame.hpp"
#include "secondary_pose_links.hpp"
namespace reo::native::gameplay_world {
enum class CinematicFrameStatus {completed,busy,closed,unavailable,no_memory};
struct CinematicFramesUpdated {
    CinematicFrameStatus status{CinematicFrameStatus::completed};
    std::size_t temporary_visits{},auxiliary_visits{},called{},links_restored{};
    actors::EntityId failed{};
};
// Actual5ECAE0: active temporary players, then the auxiliary NPC list. This is
// distinct from the linked-model pool and ordinary camera-filtered NPC update.
// The caller owns phase admission; there is no invented pause/visibility gate.
class CinematicActorFrames final {
public:
    CinematicActorFrames(World&,Services&,MotionTransformServices&);
    ~CinematicActorFrames();
    CinematicActorFrames(const CinematicActorFrames&)=delete;
    CinematicActorFrames& operator=(const CinematicActorFrames&)=delete;
    // Provider exceptions retain their prefix and release all traversal guards.
    // A callback retiring its current actor is rejected by CommonActorFrame.
    CinematicFramesUpdated run();
    CinematicFrameStatus close()noexcept;
private:
    World& world_;
    CommonActorFrame frame_;
    bool running_{},closed_{};
};
}
