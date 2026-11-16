#include "control_request_flow.hpp"
#include "interaction_transitions.hpp"

namespace reo::native::gameplay_world {
namespace {
ControlRequestFlowResult done(bool result) noexcept {
    return {ControlRequestFlowStatus::completed,result};
}
ControlRequestFlowResult missing() noexcept { return {}; }
bool still_live(World& world,const actors::EntityId& id,const Actor& actor) noexcept {
    return !world.closed()&&world.resolve(id).get()==&actor;
}
}

ControlRequestFlowResult process_control_request(World& world,Actor& actor,
    ControlRequestFlowServices& services,gameplay_update::RoomClaimSink* room_messages) {
    if(world.closed())return missing();
    const auto id=world.identity_of(actor);
    const auto actor_lease=id?world.resolve(id):nullptr;
    if(!id||!actor_lease||actor_lease.get()!=&actor)return missing();

    //64F2E0..300. The mask gate precedes current health at+544. A nonzero
    // halfword branches to64F308; zero takes the immediate return at64F300.
    if(actor.status&0x3e8u)return done(false);
    if(!actor.current)return done(false);

    // 64F2F4 selects query selector0 only for motion class1A, otherwise1.
    if(!services.query_actor(world,actor,actor.motion_class==0x1a?0:1)||
       !still_live(world,id,actor))return missing();
    if(actor.status&0x4000u){
        if(!services.query_actor(world,actor,2)||!still_live(world,id,actor))return missing();
    }

    // 64F348..364: queued equipment preempts all later requests. C74 is the
    // delay-slot clear, and C78 is cleared before returning one.
    if(actor.transient_equipment){
        if(!actor.interaction_control_request)return missing();
        actor.transient_action=0;
        actor.interaction_kind=0;
        actor.interaction_control_request->pending=0;
        return done(true);
    }

    // 64F368..3B0. The category/local predicate and the two resource calls
    // retain the source's call order; resource return zero falls through.
    if(actor.category==0&&world.locally_controlled(actor)){
        const auto resource=services.prepare_equipment(world,actor);
        if(!resource||!still_live(world,id,actor))return missing();
        if(*resource){
            if(!services.consume_equipment(world,actor,*resource)||!still_live(world,id,actor))
                return missing();
            if(!actor.interaction_control_request)return missing();
            actor.transient_action=0;
            actor.interaction_kind=0;
            actor.interaction_control_request->pending=0;
            return done(true);
        }
    }

    // 64F3B4..3E0. 64EF10 itself owns the pending-byte prefix and source
    // transition writes; a false result continues into C74/C75 handling.
    const auto consumed=consume_interaction_request(world,id,0,room_messages);
    if(consumed.status==InteractionTransitionStatus::unavailable||!still_live(world,id,actor))
        return missing();
    if(consumed.status==InteractionTransitionStatus::completed&&consumed.original_result){
        if(!actor.interaction_control_request)return missing();
        actor.interaction_kind=0;
        actor.interaction_control_request->pending=0;
        if(!services.notify(world,actor,3)||!still_live(world,id,actor))return missing();
        return done(true);
    }

    // Category-nonzero actors skip the three primary-only gates below. The
    // shared C78/C74 state machine remains reachable for every category.
    if(actor.category==0&&((actor.status&0x80u)||actor.ai_control))
        actor.interaction_kind=0;
    else if(actor.category==0&&actor.interaction_kind==3){
        if(!actor.interaction_control_request)return missing();
        actor.interaction_kind=0;
        actor.interaction_control_request->pending=0; //64F488 delay slot
        if(!services.request_resource(world,actor,13)||!still_live(world,id,actor))return missing();
        return done(true);
    } else if(actor.category==0&&actor.interaction_kind==1){
        if(!actor.interaction_control_request)return missing();
        actor.interaction_kind=0;actor.interaction_control_request->pending=0;
        if(actor.secondary==0x1a)actor.phase=30;
        else{
            actor.primary=1;actor.secondary=0x16;actor.phase=0;
            if(!services.activate_action(world,actor)||!still_live(world,id,actor))return missing();
        }
        if(!services.notify(world,actor,4)||!still_live(world,id,actor))return missing();
        return done(true);
    }

    // 64F494..4B0 clears C78 first. A C74 value other than one returns zero;
    // status mask88 is tested only after the C74 clear.
    actor.interaction_kind=0;
    if(!actor.interaction_control_request)return missing();
    auto& request=*actor.interaction_control_request;
    if(request.pending!=1)return done(false);
    request.pending=0;
    if(actor.status&0x88u)return done(false);

    const auto selector=request.variant;
    if(selector!=1&&selector!=2)return done(true);
    if(selector==1){
        const auto phase=world.session().message_phase;
        if(phase!=1&&phase!=2){
            if(!actor.interaction_control_selector)return missing();
            const auto admitted=services.admit_control(world,actor,*actor.interaction_control_selector);
            if(!admitted||!still_live(world,id,actor))return missing();
            if(!*admitted)return done(false);
        }
        actor.primary=1;actor.secondary=0x36;actor.phase=0;
        if(!services.activate_action(world,actor)||!still_live(world,id,actor))return missing();
        if(!actor.interaction_control_request)return missing();
        const auto parameter=actor.interaction_control_request->parameter;
        actor.subphase=parameter;
        if(!actor.interaction_control_selector)return missing();
        if(!services.publish_control(world,actor,5,*actor.interaction_control_selector)||
           !still_live(world,id,actor))return missing();
    }else{
        const auto phase=world.session().message_phase;
        if(phase!=1&&phase!=2){
            const auto admitted=services.admit_actor(world,actor);
            if(!admitted||!still_live(world,id,actor))return missing();
            if(!*admitted)return done(false);
        }
        actor.primary=1;actor.secondary=0x37;actor.phase=0;
        if(!services.activate_action(world,actor)||!still_live(world,id,actor))return missing();
        if(!actor.interaction_control_request)return missing();
        const auto parameter=actor.interaction_control_request->parameter;
        actor.subphase=parameter;
        if(!actor.interaction_control_selector)return missing();
        if(!services.publish_control(world,actor,6,*actor.interaction_control_selector)||
           !still_live(world,id,actor))return missing();
    }
    if(!services.notify(world,actor,1)||!still_live(world,id,actor))return missing();
    return done(true);
}
} // namespace reo::native::gameplay_world
