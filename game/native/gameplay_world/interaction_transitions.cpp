#include "interaction_transitions.hpp"
#include "motion.hpp"
#include "interaction_transition_profile.inc"
#include "../gameplay_update/room_publication.hpp"
namespace reo::native::gameplay_world {
bool begin_interaction_hold(World& world,const actors::EntityId& id)noexcept{
    if(world.closed())return false;
    const auto actor=world.resolve(id);if(!actor)return false;
    actor->response_lock=0;actor->status|=0x10000u;
    if(world.locally_controlled(*actor))world.session().exit_requested=1;
    return true;
}
bool resume_offline_interaction(World& world,const actors::EntityId& id)noexcept{
    if(world.closed())return false;
    const auto actor=world.resolve(id);if(!actor)return false;
    if(world.mode!=0||actor->category!=0||actor->slot==0)return true;
    if(!actor->interaction_request)return false;
    if(!actor->interaction_request->parameter)return true;
    actor->response_lock=0;
    // Complete819880 returns-1 without scene work for either status bit.
    // Other profiles still need the actual route/room reconstruction owner.
    if(!(actor->status&0x88u))return false;
    if(actor->room!=world.room){
        actor->visible=false;actor->auxiliary_status&=~0xc000u;actor->color_fade=ColorFade{0xffffffffu,0,0};
    }
    actor->status&=~0x10000u;actor->primary=1;actor->secondary=actor->phase=actor->subphase=0;save_action_pose(*actor);
    return true;
}
InteractionTransition consume_interaction_request(World& world,const actors::EntityId& id,std::uint32_t full_selector,gameplay_update::RoomClaimSink* messages)noexcept{
    if(world.closed())return{};
    const auto actor=world.resolve(id);if(!actor)return{};
    if(!actor->transient_action)return{InteractionTransitionStatus::idle,false};
    actor->transient_action=0;
    if(!actor->interaction_request)return{};
    const auto& request=*actor->interaction_request;const auto kind=request.kind;
    if(!kind)return{InteractionTransitionStatus::rejected,false};
    if(actor->status&0x80u){
        switch(kind){case 1:case 2:case 7:case 0x1a:case 0x1f:case 0x20:case 0x29:case 0x2f:case 0x30:break;
        default:return{InteractionTransitionStatus::rejected,false};}
    }
    const auto selector=std::uint8_t(full_selector);
    if(!selector&&actor->primary!=1&&actor->category==0){
        if(world.locally_controlled(*actor)){
            if(!begin_interaction_hold(world,id))return{};
        }else{
            if(world.mode==0){
                if(!resume_offline_interaction(world,id))return{};
                actor->response_lock=0;
            }
        }
        if(gameplay_update::publish_actor_room_release(world,actor->slot,messages)!=gameplay_update::PublicationStatus::completed)return{};
        return{InteractionTransitionStatus::completed,true};
    }
    if(selector>1||kind>=interaction_transition_states.size())return{};
    actor->primary=1;actor->secondary=std::uint8_t(interaction_transition_states[kind][selector]);actor->phase=0;actor->subphase=0;save_action_pose(*actor);
    if(!selector&&(kind==1||kind==2)){
        actor->primary=1;actor->secondary=request.parameter?0x17:0x18;actor->phase=0;actor->subphase=0;save_action_pose(*actor);
    }
    return{InteractionTransitionStatus::completed,true};
}
}
