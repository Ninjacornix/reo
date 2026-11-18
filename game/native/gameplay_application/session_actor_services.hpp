#pragma once
#include "../gameplay_world/actor_resource_operations.hpp"
#include "../gameplay_update/update.hpp"
#include "session_rooms.hpp"

namespace reo::native::gameplay_application {
// Terminal actor-frame services for the same canonical Update/World. Missing
// source stages fail at their actual caller; they never pretend to execute.
class SessionActorServices final:public gameplay_world::Services {
public:
    SessionActorServices(gameplay_update::Owner&,gameplay_world::ActorResourceOperations&,
                         std::shared_ptr<SessionRooms> = {});
    void begin_offline_frame(gameplay_world::World&)override;
    void run(gameplay_world::Stage,gameplay_world::World&,gameplay_world::Actor&)override;
    bool remote_motion(gameplay_world::World&,gameplay_world::Actor&)override;
    bool find_grid(gameplay_world::World&,gameplay_world::Actor&,std::int8_t&)override;
    void switch_grid(gameplay_world::World&,std::int32_t,std::int32_t)override;
    float grid_response(gameplay_world::World&,std::uint8_t)override;
private:
    gameplay_world::actors::EntityId admit(gameplay_world::World&,gameplay_world::Actor&)const;
    std::shared_ptr<gameplay_collision::room_objects::Owner> objects(gameplay_world::World&)const;
    gameplay_update::Owner& update_;
    gameplay_world::ActorResourceOperations& resources_;
    std::shared_ptr<SessionRooms> rooms_;
    std::shared_ptr<gameplay_contact_world::RoomInvocation> room_;
};
}
