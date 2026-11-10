#include "actor_recovery.hpp"
#include "animation.hpp"
#include "motion.hpp"
#include "../gameplay_actors/health_class.hpp"
#include "../gameplay_update/update.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ActorRecovery::ActorRecovery(gameplay_update::Owner& update,ActorResourceOperations& operations,WorldAnimation* animation,RecoveryUi* ui):
    update_(update),operations_(operations),world_(update.world()),animation_(animation),ui_(ui){
    if(!bound_to(world_)||(animation_&&!animation_->bound_to(world_))||(ui_&&!ui_->bound_to(world_)))throw std::invalid_argument("Native actor recovery owners closed or foreign");
}
bool ActorRecovery::bound_to(const World& world)const noexcept{return &world==&world_&&update_.open()&&operations_.bound_to(world_);}
void ActorRecovery::apply(const actors::EntityId& id,std::uint32_t full_mode){
    if(!bound_to(world_))throw std::runtime_error("Native actor recovery owner closed");
    const auto actor=world_.resolve(id);if(!actor)throw std::runtime_error("Native recovery actor retired or foreign");
    actor->status=(actor->status&~0x38u)|0x80u;
    actor->recovery_timer=world_.session().clock_mode?3600:7200;
    if(update_.clear_actor_status(id,5)!=gameplay_update::PublicationStatus::completed)throw std::runtime_error("Native recovery first status publication unavailable");
    if(update_.clear_actor_status(id,8)!=gameplay_update::PublicationStatus::completed)throw std::runtime_error("Native recovery second status publication unavailable");
    if(world_.locally_controlled(*actor)){
        world_.session().inventory_owner=0;
        if(!ui_||!ui_->bound_to(world_)||!ui_->close())throw std::runtime_error("Native recovery UI close unavailable");
    }
    const auto transition=[&](std::uint8_t primary,std::uint8_t secondary,std::uint8_t phase){actor->primary=primary;actor->secondary=secondary;actor->phase=phase;actor->subphase=0;save_action_pose(*actor);};
    if(world_.mode==0){
        actor->status=(actor->status&~0x80u)|0x40000000u;
        (void)operations_.transfer_inventory(id,0);actor->motion_class=0xa0;transition(4,0,0);
        if(update_.record_actor_message(id,gameplay_update::ActorMessageSelector::snapshot)!=gameplay_update::PublicationStatus::completed)throw std::runtime_error("Native recovery offline snapshot unavailable");
        (void)operations_.transfer_inventory(id,0);return;
    }
    constexpr std::array<float,2> thresholds{50.f,25.f}; // owned71B030
    if(actors::derive_health_class(*actor,thresholds)==actors::ClassResult::invalid_maximum)throw std::runtime_error("Native recovery health-class denominator unavailable");
    actor->previous_motion_class=2;
    const auto mode=std::uint8_t(full_mode);
    if(mode==0)transition(3,0x11,0);
    else if(mode==1)transition(3,0x10,0);
    else{
        actor->motion_class=0;
        actor->action_flags&=~std::uint16_t(1);transition(1,0,1);
        if(!animation_||!animation_->bound_to(world_))throw std::runtime_error("Native recovery animation owner unavailable");
        animation_->select(id,0x2050,0.f,10.f);
        if(!actor->animation||actor->animation->model()!=actor->model)throw std::runtime_error("Native recovery playback replaced before activation");
        actor->animation->activate(actor->animation->channel_count);
    }
    if(update_.record_actor_message(id,gameplay_update::ActorMessageSelector::snapshot)!=gameplay_update::PublicationStatus::completed)throw std::runtime_error("Native recovery snapshot unavailable");
    actor->status|=0x400u;(void)operations_.transfer_inventory(id,0);
}
}
