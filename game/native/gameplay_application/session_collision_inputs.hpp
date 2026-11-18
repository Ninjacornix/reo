#pragma once
#include "session_collision_frame.hpp"
#include "../gameplay_world/collision_phase.hpp"

namespace reo::native::gameplay_application {
// Actual per-frame populations and 5DA420 wall correction for one session.
// The session owns its actor pools; each returned frame retains actor and pose
// leases until the synchronous collision worker finishes.
class SessionCollisionPopulation final : public SessionCollisionInputs,
                                         public gameplay_world::SecondaryCollisionWalls {
public:
    explicit SessionCollisionPopulation(std::shared_ptr<NativeSession>);
    gameplay_update::BodyFrame bodies(gameplay_update::Owner&) override;
    gameplay_update::HeightFrame secondary_heights(gameplay_update::Owner&) override;
    void correct(const gameplay_actors::EntityId&,gameplay_collision::ground::View,
                 const gameplay_world::CollisionRoom&) override;
private:
    gameplay_world::World& world(gameplay_update::Owner&) const;
    std::shared_ptr<NativeSession> session_;
};
}
