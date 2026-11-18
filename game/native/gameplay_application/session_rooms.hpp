#pragma once
#include "native_session.hpp"
#include "../gameplay_contact_world/contacts.hpp"
#include "../gameplay_scenario/room_object_commands.hpp"
#include <map>
#include <tuple>

namespace reo::native::gameplay_application {
// Actual5DCB90/5DCB60 selectors use the low five bits of selector+16.
// Unknown canonical state is not materialized by a read/modify/write command.
bool set_collision_disabled(gameplay_world::Session&,std::uint32_t selector)noexcept;
bool clear_collision_disabled(gameplay_world::Session&,std::uint32_t selector)noexcept;
enum class RoomResourcesStatus {
    completed,unavailable_session,unavailable_room,unavailable_geometry,
    unavailable_object_instances,unsupported_dynamic,object_binding_refused
};
struct RoomObjectStartupBytes {std::uint8_t byte_b2ba{},byte_b2b9{},byte_b2bc{};};
// Production RoomResources bound to one application's actual World, archive,
// Records and matrix-program graph. Import is lazy and occurs once per room
// identity. Geometry leases retain that entire graph across room retirement.
class SessionRooms final:public gameplay_contact_world::RoomResources {
public:
    explicit SessionRooms(std::shared_ptr<NativeSession>);
    std::shared_ptr<gameplay_contact_world::RoomInvocation> retain(std::uint16_t)override;
    RoomResourcesStatus status()const noexcept{return status_;}
    std::shared_ptr<gameplay_world::World> world()const noexcept;
    // Retains the same immutable floor asset without retaining a RoomLease or
    // NativeSession. Session-owned resource factories must not create a cycle.
    std::shared_ptr<const gameplay_collision::response::Grid> retain_floor(std::uint16_t);
    std::shared_ptr<gameplay_collision::room_objects::Owner> objects()const noexcept;
    std::optional<RoomObjectStartupBytes> object_startup_bytes()const noexcept;
    // Borrowed only for the synchronous VM call; a reset or retired room
    // replaces this facade together with its canonical object/lifetime owner.
    gameplay_scenario::RoomObjectCommands* script_commands()const noexcept;
private:
    bool initialize_roster_objects()noexcept;
    friend class SessionResources;
    std::weak_ptr<NativeSession> session_;
    std::unique_ptr<gameplay_scenario::RoomObjectCommands> commands_;
    gameplay_collision::room_objects::Owner* command_owner_{};
    gameplay_collision::room_objects::Scene* command_scene_{};
    gameplay_actors::EntityId command_room_;
    std::map<std::tuple<std::uint16_t,std::uint16_t,std::uint16_t>,
        std::weak_ptr<const gameplay_collision::response::Grid>> floors_;
    RoomResourcesStatus status_{RoomResourcesStatus::unavailable_room};
};
}
