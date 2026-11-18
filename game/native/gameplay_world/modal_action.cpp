#include "modal_action.hpp"
#include "motion.hpp"
#include <bit>

namespace reo::native::gameplay_world {
namespace {
ModalActionResult unavailable() noexcept { return {}; }
ModalActionResult complete(bool value) noexcept { return {ModalActionStatus::completed,value}; }
}

ModalActionResult consume_modal_action(World& world,Actor& actor,ModalActionServices& services,
    ModalActionPublication& publication) {
    if(world.closed()) return unavailable();
    const auto id=world.identity_of(actor);
    const auto actor_lease=id?world.resolve(id):nullptr;
    if(!id || !actor_lease || actor_lease.get()!=&actor || !actor.interaction_request_count) return unavailable();

    // 64F128 captures BBD before either query. The query results are not tested,
    // but both consumers run in order and may have visible side effects.
    const auto initial_count=*actor.interaction_request_count;
    if(!services.query_actor(world,actor,3,7) || world.closed() || world.resolve(id).get()!=&actor)
        return unavailable();
    if(!services.query_actor(world,actor,3,1) || world.closed() || world.resolve(id).get()!=&actor)
        return unavailable();

    // 64F148..64F158: pending equipment consumes AB8 and returns one.
    if(actor.transient_equipment){actor.transient_action=0;return complete(true);}

    if(actor.transient_action && actor.category==0 && actor.ai_control==0){
        // 5F4FD0 clears the canonical session owner in its delay slot before
        // entering the phase-sensitive inventory close routine.
        world.session().inventory_owner=0;
        if(!services.close_inventory(world,actor))return unavailable();
    }
    if(actor.transient_action && actor.motion_class==0x16){
        actor.transient_action=0;
        if(!actor.interaction_subselector)return unavailable();
        if(!*actor.interaction_subselector)return complete(false);
        actor.primary=1;actor.secondary=0xdd;actor.phase=actor.subphase=0;
        save_action_pose(actor);
        return complete(true);
    }

    // 64F1E0 is reached both with and without AB8. A completed false result
    // continues to the BBD threshold; a refusal stops after the consumer's
    // own documented mutation prefix.
    const auto consumed=consume_interaction_request(world,id,0,nullptr);
    if(consumed.status==InteractionTransitionStatus::unavailable || world.closed() ||
       world.resolve(id).get()!=&actor)return unavailable();
    if(consumed.status==InteractionTransitionStatus::completed && consumed.original_result){
        if(!publication.publish_interaction_request(world,actor) || world.closed() ||
           world.resolve(id).get()!=&actor)return unavailable();
    }

    // 64F200..64F240 conditionally clears BBD, rejects status mask 0x90, then
    // waits until the mode-dependent request threshold is reached.
    if(*actor.interaction_request_count==initial_count)actor.interaction_request_count=0;
    if(actor.status&0x90u)return complete(false);
    const auto mode=world.session().mode;
    const auto threshold=std::uint8_t(mode?20:40);
    if(*actor.interaction_request_count<threshold)return complete(false);
    if(actor.motion_class!=3 && actor.motion_class!=1)return complete(false);

    // Delay-slot behavior at 64F254/25C leaves 900 in source modes and 1800
    // when mode is zero; the class-3 and class-1 paths converge here.
    // 64F278 stores the signed actor+C contact-style discriminator. The
    // source halfword is narrowed then interpreted signed by its consumers.
    if(!actor.contact_style_discriminator)return unavailable();
    *actor.contact_style_discriminator=std::bit_cast<std::int16_t>(std::uint16_t(mode?900:1800));
    actor.primary=1;actor.secondary=0xae;actor.phase=actor.subphase=0;
    save_action_pose(actor);
    if(!actor.interaction_control_selector)return unavailable();
    if(register_interaction(world,actor,*actor.interaction_control_selector,services)!=
       InteractionRegistrationStatus::completed)return unavailable();
    return complete(true);
}

} // namespace reo::native::gameplay_world
