#pragma once
#include "native_session.hpp"
#include "../gameplay_contact_world/contacts.hpp"

namespace reo::native::gameplay_application {
// Actual5DCB90/5DCB60 selectors use the low five bits of selector+16.
// Unknown canonical state is not materialized by a read/modify/write command.
bool set_collision_disabled(gameplay_world::Session&,std::uint32_t selector)noexcept;
bool clear_collision_disabled(gameplay_world::Session&,std::uint32_t selector)noexcept;
enum class RoomResourcesStatus {
    completed,unavailable_session,unavailable_room,unavailable_geometry,
    unavailable_object_instances,unsupported_dynamic
};
// Production RoomResources bound to one application's actual World, archive,
// Records and matrix-program graph. Import is lazy and occurs once per room
// identity. Geometry leases retain that entire graph across room retirement.
class SessionRooms final:public gameplay_contact_world::RoomResources {
public:
    explicit SessionRooms(std::shared_ptr<NativeSession>);
    std::shared_ptr<gameplay_contact_world::RoomInvocation> retain(std::uint16_t)override;
    RoomResourcesStatus status()const noexcept{return status_;}
    std::shared_ptr<gameplay_world::World> world()const noexcept;
private:
    std::weak_ptr<NativeSession> session_;
    RoomResourcesStatus status_{RoomResourcesStatus::unavailable_room};
};
}
