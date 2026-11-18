#pragma once
#include "weapon_resources.hpp"
#include "../gameplay_world/resource_factory.hpp"
namespace reo::native::gameplay_weapon_resources {
struct Attached {
    gameplay_world::ResourceModelCreated primary;
    std::optional<Refreshed> weapons;
};
struct Selected {
    gameplay_scenario::SceneStatus status{gameplay_scenario::SceneStatus::completed};
    bool changed{};
    std::optional<Attached> attachment;
};
// Concrete5B18D0 equipment construction, with actual model/secondary release and
// weapon resource refresh. Borrowed simulation owners outlive this facade.
class Equipment final {
public:
    Equipment(Owner&,gameplay_world::ResourceFactory&);
    Attached attach(std::uint8_t logical_resource)noexcept;
    //666DE0 primary selection and the reached5F1F70/5B4D50 action-kind query.
    Selected select(const gameplay_actors::EntityId&,std::uint8_t logical_resource)noexcept;
    //67ED50 shared receiver tail: retain/rebuild the current item's binding,
    // then derive its action kind through the same actual equipment owners.
    Selected reconcile(const gameplay_actors::EntityId&)noexcept;
    bool bound_to(const gameplay_world::World&)const noexcept;
private:
    Owner& weapons_;
    gameplay_world::ResourceFactory& factory_;
};
}
