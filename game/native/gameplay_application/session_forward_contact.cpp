#include "session_forward_contact.hpp"
#include "native_session.hpp"

namespace reo::native::gameplay_application {
SessionForwardContact::SessionForwardContact(NativeSession& session,SessionRooms& rooms)noexcept:
    session_(session),rooms_(rooms){}

gameplay_world::ForwardContactResult SessionForwardContact::probe(
    gameplay_world::World& world,gameplay_world::Actor& actor,
    std::uint32_t include,std::uint32_t exclude,float signed_offset)noexcept{
    namespace w=gameplay_world;
    if(!session_.open()||&world!=&session_.world()||rooms_.world().get()!=&world||world.closed())return{};
    const auto actor_id=world.identity_of(actor);
    const auto retained_actor=world.resolve(actor_id);
    if(!actor_id||retained_actor.get()!=&actor)return{};
    std::shared_ptr<gameplay_contact_world::RoomInvocation> lease;
    try{lease=rooms_.retain(world.room);}catch(...){return{};}
    if(!lease||lease->room_number()!=world.room||!lease->current(lease->identity()))return{};
    w::ForwardContactResult result;
    try{
        const auto& collision=lease->geometry();
        result=w::probe_forward_contact(actor,collision.walls,include,exclude,
            signed_offset,collision.dynamic);
    }catch(...){return{};}
    // Query output mutates the canonical actor. Validate the borrowed room and
    // actor identities again before reporting a successful source operation.
    if(!session_.open()||world.closed()||!lease->current(lease->identity())||
       world.resolve(actor_id).get()!=&actor)return{};
    return result;
}
}
