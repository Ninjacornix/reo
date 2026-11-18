#pragma once
#include "collision.hpp"
#include "../gameplay_collision/secondary_ground.hpp"
namespace reo::native::gameplay_world {
enum class HeightStatus {completed,primary_failure,auxiliary_failure,unknown_secondary_probe,invalid_roster};
struct HeightReport {
    HeightStatus status{HeightStatus::completed};
    CollisionPass primary;
    std::size_t auxiliary_visited{},failed_auxiliary{};
    CollisionResult last_auxiliary;
    gameplay_collision::ground::Report secondary;
};
class SecondaryCollisionWalls {
public:
    virtual ~SecondaryCollisionWalls()=default;
    virtual void correct(const actors::EntityId&,gameplay_collision::ground::View,
                         const CollisionRoom&)=0;
};
// Complete 5DA680 ordering: primary physical slots, the supplied native
// auxiliary list order, then the secondary ground owner. All auxiliary/secondary
// leases must remain live for this synchronous pass. The secondary wall owner
// supplies its distinct state; primary floor policy is never applied to it.
HeightReport update_collision_heights(World&,const CollisionRoom&,
    std::span<const std::shared_ptr<Actor>> auxiliary,
    std::span<gameplay_collision::ground::Entry> secondary,
    SecondaryCollisionWalls&);
}
