#pragma once
#include "weapon_resources.hpp"
#include "../gameplay_world/resource_factory.hpp"
namespace reo::native::gameplay_weapon_resources {
struct Attached {
    gameplay_world::ResourceModelCreated primary;
    std::optional<Refreshed> weapons;
};
// Concrete5B18D0 equipment construction, with actual model/secondary release and
// weapon resource refresh. Borrowed simulation owners outlive this facade.
class Equipment final {
public:
    Equipment(Owner&,gameplay_world::ResourceFactory&);
    Attached attach(std::uint8_t logical_resource)noexcept;
private:
    Owner& weapons_;
    gameplay_world::ResourceFactory& factory_;
};
}
