#include "cooperation.hpp"

namespace reo::native::gameplay_world {
namespace {
std::optional<actors::ActorReference> actor_reference(const Actor& actor) noexcept {
    // 666B70: primary/category 0 is its slot; category 1 is model_variant
    // with the auxiliary marker. Every other category returns encoded key0,
    // which is the canonical primary-slot-zero reference.
    if (actor.category == 0) return actors::ActorReference{actors::ActorReference::Kind::primary,actor.slot};
    if (actor.category == 1) return actors::ActorReference{actors::ActorReference::Kind::auxiliary,
        std::uint16_t(actor.model_variant & 0x7fffu)};
    return actors::ActorReference{actors::ActorReference::Kind::primary,0};
}
}

CooperationStatus update_cooperation_request(World& world, Actor& actor,
    Actor& related_actor, CooperationPublication& publication) noexcept {
    if (world.closed()) return CooperationStatus::unavailable;
    const auto id = world.identity_of(actor);
    const auto actor_lease = id ? world.resolve(id) : nullptr;
    if (!id || !actor_lease || actor_lease.get() != &actor) return CooperationStatus::unavailable;
    const auto related_id=world.identity_of(related_actor);
    const auto related_lease = related_id ? world.resolve(related_id) : nullptr;
    if(!related_id||!related_lease||related_lease.get()!=&related_actor)return CooperationStatus::unavailable;
    const auto related_ref=actor_reference(related_actor);
    if (!related_ref || !world.referenced_actor(*related_ref) ||
        ((related_actor.category==0 || related_actor.category==1) &&
         world.referenced_actor(*related_ref).get()!=&related_actor))
        return CooperationStatus::unavailable;
    if(!actor.peer_request)return CooperationStatus::unavailable;
    // 1B0310 is the 3243FB message-phase predicate (exactly values 1 or 2),
    // not the distinct 1B0340 locally-controlled-actor predicate.
    const auto phase=world.session().message_phase;
    if ((phase==1 || phase==2) && actor.category==0) {
        // 64F76C/774 write both C64 and C65 before publication. Refusal
        // retains this source-visible mutation prefix.
        actor.transient_contact=2;
        if(!actor.peer_request)return CooperationStatus::unavailable;
        actor.peer_request->state_high=2;
        actor.peer_request->peer=*related_ref;
        if(!publication.publish_peer(world,actor))
            return CooperationStatus::unavailable;
    }
    // 64F788 and 64F794/798 always clear C64/C65, then write 666B70's
    // canonical related identity to C66. C68/C6A are untouched.
    const auto live_actor=world.resolve(id);
    if(world.closed()||!live_actor||live_actor.get()!=&actor)return CooperationStatus::unavailable;
    const auto live_related=world.resolve(related_id);
    if(!live_related||live_related.get()!=&related_actor||!actor.peer_request)
        return CooperationStatus::unavailable;
    actor.transient_contact=0;
    actor.peer_request->state_high = 0;
    const auto final_ref=actor_reference(*live_related);
    if (!final_ref || !world.referenced_actor(*final_ref))
        return CooperationStatus::unavailable;
    actor.peer_request->peer = *final_ref;
    return CooperationStatus::completed;
}

} // namespace reo::native::gameplay_world
