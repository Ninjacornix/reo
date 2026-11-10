#include "actor_gauge_progression.hpp"
#include "actor_state.hpp"
#include "motion.hpp"
#include "../gameplay_update/update.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ActorGaugeProgression::ActorGaugeProgression(gameplay_update::Owner& update,ActorResourceOperations& operations,GaugeTransitionEffects* effects):update_(update),operations_(operations),world_(update.world()),effects_(effects){
    if(!update_.open()||!operations_.bound_to(world_)||(effects_&&!effects_->bound_to(world_)))throw std::invalid_argument("Native gauge progression owners closed or foreign");
}
GaugeTransitionEffects& ActorGaugeProgression::effects(){
    if(!effects_||!effects_->bound_to(world_))throw std::runtime_error("Native gauge transition consumer unavailable");
    return *effects_;
}
void ActorGaugeProgression::close_ui(){
    world_.session().inventory_owner=0;
    if(!effects().close())throw std::runtime_error("Native gauge UI close unavailable");
}
std::uint8_t ActorGaugeProgression::tick(const actors::EntityId& id){
    if(!update_.open())throw std::runtime_error("Native gauge update owner closed");
    const auto actor=world_.resolve(id);if(!actor)throw std::runtime_error("Native gauge actor retired or foreign");
    auto& session=world_.session();
    if(world_.paused||actor->category!=0||actor->slot!=world_.selected_actor||(actor->status&0x400000u))return 0;
    if(!actor->gauge_value||actor->character>=actor_gauge_rates.size())throw std::runtime_error("Native gauge value or rate profile unavailable");
    float gauge=gauge_unsigned_float(*actor->gauge_value);
    auto rate=actor_gauge_rates[actor->character];
    float acceleration=actor->status&0x10u?60.f:0.f;
    if(actor->character==2&&actor->motion_class==0x41&&actor->phase>=3)acceleration=10.f;
    if(actor->model_variant)acceleration*=actor_gauge_scales[actor->gauge_rate_variant&7u];
    unsigned step=60;
    if(acceleration!=0.f){
        if(world_.locally_controlled(*actor)&&!effects().notify_ui())throw std::runtime_error("Native gauge UI notification unavailable");
        // Owned rates/scales give finite positive values at most192 here. Preserve
        // the source multiply/divide/truncate order without guest FP machinery.
        const auto numerator=gauge_unsigned_float(rate)*acceleration;
        rate=std::uint32_t(numerator/(session.clock_mode?30.f:60.f));step=2;
    }else if(session.timer_subseconds()!=0)return 0;
    if(actor->status&0x1e0u){actor->gauge_modifier_one=actor->gauge_modifier_two=actor->linked_model_variant=0;return 0;}
    if(actor->status&0x400u)actor->gauge_modifier_one=actor->gauge_modifier_two=actor->linked_model_variant=0;
    if(actor->auxiliary_status&0x80000u){actor->auxiliary_status&=~0x80000u;return 0;}
    const auto modifier=[&](std::uint32_t flag,std::uint16_t initial,std::uint16_t& countdown){
        if(actor->auxiliary_status&flag){actor->auxiliary_status&=~flag;countdown=initial;}
        float percent=100.f;
        if(countdown){countdown=countdown>step?std::uint16_t(countdown-step):0;percent=0.f;}
        // Halfword countdowns and the two steps are exact finite float integers
        // in the original. Applying a modifier suppresses this invocation even
        // when its decrement reaches zero; subsequent modifiers still update.
        rate=std::uint32_t(gauge_unsigned_float(rate)*(percent/100.f));
    };
    modifier(8,5400,actor->gauge_modifier_one);
    modifier(0x10,10800,actor->gauge_modifier_two);
    modifier(0x20,1800,actor->linked_model_variant);
    gauge+=gauge_unsigned_float(rate);
    if(actor->character>=actor_gauge_limits.size())throw std::runtime_error("Native gauge cap profile unavailable");
    const auto cap=gauge_unsigned_float(actor_gauge_limits[actor->character]);
    if(!(100.f*(gauge/cap)<99.99500274658203f))gauge=cap;
    if(gauge<cap){
        // The preceding comparison bounds this conversion below345600. Its
        // finite nonnegative truncation matches the source unsigned sequence.
        const auto next=std::uint32_t(gauge);
        if(!actor->gauge_value)throw std::runtime_error("Native gauge value invalidated before crossing");
        if(update_.record_gauge_crossing(id,*actor->gauge_value,next)!=gameplay_update::GaugeStatus::completed)throw std::runtime_error("Native gauge threshold event unavailable");
        actor->gauge_value=next;return 0;
    }
    if(world_.locally_controlled(*actor)){
        const auto blocked=effects().close_blocked();if(!blocked)throw std::runtime_error("Native gauge UI close admission unavailable");
        if(!*blocked)close_ui();
    }
    // Complete65FC90 prefix and its actual inventory consumer. No successful
    // placeholder for transfer, model retirement or auxiliary-list retention.
    actor->status|=0x400u;(void)operations_.transfer_inventory(id,0);
    if(actor->character>=actor_gauge_limits.size())throw std::runtime_error("Native gauge cap invalidated after transfer");
    actor->gauge_value=actor_gauge_limits[actor->character];
    if(!(actor->auxiliary_status&0x100u))return 0;
    actor->current=0;
    if(world_.locally_controlled(*actor)&&!(actor->auxiliary_status&0x10000000u)){
        actor->auxiliary_status|=0x10000000u;
        const auto event=update_.record_event(0x24,0,0).status;
        if(event!=gameplay_events::Status::completed&&event!=gameplay_events::Status::priority_rejected&&event!=gameplay_events::Status::full)throw std::runtime_error("Native gauge cap event unavailable");
    }
    const auto transition=[&](std::uint8_t secondary){actor->motion_class=0xa0;actor->primary=4;actor->secondary=secondary;actor->phase=actor->subphase=0;save_action_pose(*actor);};
    if(actor->status&0x18u){
        actor->status&=~0x18u;
        if(actor->category==0){
            if(actor->ai_control&&actor->room!=world_.room){
                actor->status|=0x60u;(void)operations_.transfer_inventory(id,0);transition(1);
                if(!effects().notify_off_room(id))throw std::runtime_error("Native gauge off-room notification unavailable");
            }else{
                actor->status|=0x20u;if(world_.mode==0)actor->status|=0x40000000u;
                (void)operations_.transfer_inventory(id,0);transition(0);
            }
        }else if(actor->category==1){actor->status|=0x40u;(void)operations_.transfer_inventory(id,0);transition(1);}
    }else{
        if(!effects().recover(id,2))throw std::runtime_error("Native gauge recovery transition unavailable");
        if(actor->category==0&&actor->ai_control&&actor->room!=world_.room&&!effects().notify_off_room(id))throw std::runtime_error("Native gauge recovery notification unavailable");
    }
    return 1;
}
bool ActorGaugeProgression::apply_progression_timer(World& source,Actor& actor){
    if(&source!=&world_)return false;
    const auto id=world_.identity_of(actor);if(!id)return false;
    (void)tick(id);return true;
}
}
