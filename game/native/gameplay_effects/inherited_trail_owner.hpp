#pragma once
#include "inherited_trail.hpp"
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_contact_world {class RoomResources;}
namespace reo::native::gameplay_effects {
class InheritedTrailActions {
public:
    virtual ~InheritedTrailActions()=default;
    virtual bool bound_to(const gameplay_world::World&)const noexcept=0;
    virtual bool cue(const gameplay_actors::EntityId&,transform_math::Vector)=0;
    virtual bool burst(const gameplay_actors::EntityId&,transform_math::Vector)=0;
};
// Borrowed room/action providers must outlive the visual owner and its joined
// update calls. The strong World lease prevents destruction of canonical state.
struct InheritedTrailRequest {
    std::shared_ptr<gameplay_world::World> world;
    gameplay_contact_world::RoomResources* rooms{};
    InheritedTrailActions* actions{};
    gameplay_actors::EntityId parent,motion;
    std::optional<transform_math::Vector> point;
    std::int32_t delay{};
};
struct InheritedTrailBatch {
    WorkStatus status{WorkStatus::unavailable};
    std::size_t attempted{},created{};
    std::array<gameplay_actors::EntityId,5> identities;
};
}
