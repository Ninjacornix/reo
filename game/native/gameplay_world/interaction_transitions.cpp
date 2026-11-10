#include "interaction_transitions.hpp"
#include "motion.hpp"
#include "interaction_transition_profile.inc"
namespace reo::native::gameplay_world {
InteractionTransition consume_interaction_request(World& world,const actors::EntityId& id,std::uint32_t full_selector)noexcept{
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
    if(!selector&&actor->primary!=1&&actor->category==0)return{};
    if(selector>1||kind>=interaction_transition_states.size())return{};
    actor->primary=1;actor->secondary=std::uint8_t(interaction_transition_states[kind][selector]);actor->phase=0;actor->subphase=0;save_action_pose(*actor);
    if(!selector&&(kind==1||kind==2)){
        actor->primary=1;actor->secondary=request.parameter?0x17:0x18;actor->phase=0;actor->subphase=0;save_action_pose(*actor);
    }
    return{InteractionTransitionStatus::completed,true};
}
}
