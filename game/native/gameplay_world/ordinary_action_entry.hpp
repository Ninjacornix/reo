#pragma once
#include "secondary_pose_dynamics.hpp"
#include "../gameplay_update/room_publication.hpp"
namespace reo::native::gameplay_world {
//66B8E0 prefix through1AFF90. The caller then invokes the same66B960
//secondary dispatch used by an already active ordinary actor. Publication
//failure retains all preceding writes; it must not restart this prefix.
inline gameplay_update::PublicationStatus enter_ordinary_action(World& world,Actor& actor,
    gameplay_update::RoomClaimSink* messages){
    actor.primary=std::uint8_t(actor.primary+1u);actor.visible=true;
    reset_secondary_pose_history(actor);
    actor.auxiliary_status|=0x08000000u;
    if(actor.category==0)actor.response_lock=0;
    return gameplay_update::publish_actor_room_claim(world,actor.slot,messages);
}
}
