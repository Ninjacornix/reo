#include "actor_forced_terminal.hpp"
#include "motion.hpp"
#include "../gameplay_update/update.hpp"
#include <stdexcept>

namespace reo::native::gameplay_world {
ActorForcedTerminal::ActorForcedTerminal(gameplay_update::Owner& update,ActorResourceOperations& operations,
                                         RecoveryUi& ui)
    :update_(update),operations_(operations),ui_(ui),world_(update.world()) {
    if(!update_.open()||!operations_.bound_to(world_)||!ui_.bound_to(world_))
        throw std::invalid_argument("Native forced terminal owners closed or foreign");
}

bool ActorForcedTerminal::apply(World& source,std::uint32_t mode) noexcept {
    if(&source!=&world_)return false;
    try { force(mode);return true; }
    catch(const std::exception&) { return false; }
}

bool ActorForcedTerminal::bound_to(const World& source)const noexcept {
    return &source==&world_&&update_.open()&&operations_.bound_to(world_)&&ui_.bound_to(world_);
}

bool ActorForcedTerminal::ready()const noexcept {
    if(!bound_to(world_)||running_)return false;
    const auto index=world_.mode==0?0:world_.selected_actor;
    return world_.primary(index)&&operations_.transfer_inventory_ready(world_.identity(index),0);
}

void ActorForcedTerminal::force(std::uint32_t mode) {
    if(!bound_to(world_)||running_)throw std::runtime_error("Native forced terminal owner unavailable or busy");
    struct Running {bool& value;explicit Running(bool& v):value(v){value=true;}~Running(){value=false;}} running(running_);
    const auto index=world_.mode==0?0:world_.selected_actor;
    const auto actor=world_.primary(index);
    if(!actor)throw std::runtime_error("Native forced terminal actor unavailable");
    const auto id=world_.identity(index);
    world_.session().cutscene_requests.limit_override=true;
    world_.session().inventory_owner=0;
    if(!ui_.close())throw std::runtime_error("Native forced terminal UI close unavailable");
    if(!bound_to(world_)||world_.resolve(id).get()!=actor.get())
        throw std::runtime_error("Native forced terminal actor retired during UI close");
    const auto event=update_.record_event(0x26,0,0);
    if(event.status==gameplay_events::Status::unavailable||event.status==gameplay_events::Status::closed)
        throw std::runtime_error("Native forced terminal event unavailable");

    struct Saved {
        std::int16_t health;
        std::uint32_t status;
        std::array<std::uint8_t,4> action;
        std::uint8_t motion_class;
    } saved{actor->current,actor->status,
            {actor->primary,actor->secondary,actor->phase,actor->subphase},actor->motion_class};

    actor->status|=0x40000120u;
    actor->current=0;
    actor->pending_notice=0;
    (void)operations_.transfer_inventory(id,0);
    actor->motion_class=0xa0;
    actor->primary=4;actor->secondary=7;actor->phase=actor->subphase=0;
    save_action_pose(*actor);
    actor->status|=0x1000u;
    if(update_.record_local_actor_message(id,gameplay_update::ActorMessageSelector::snapshot)!=gameplay_update::PublicationStatus::completed)
        throw std::runtime_error("Native forced terminal snapshot unavailable");
    if(!bound_to(world_)||world_.resolve(id).get()!=actor.get())
        throw std::runtime_error("Native forced terminal actor retired during snapshot");
    if(actor->pending_notice) {
        if(update_.record_local_actor_message(id,gameplay_update::ActorMessageSelector::action)!=gameplay_update::PublicationStatus::completed)
            throw std::runtime_error("Native forced terminal action message unavailable");
        if(!bound_to(world_)||world_.resolve(id).get()!=actor.get())
            throw std::runtime_error("Native forced terminal actor retired during action message");
        actor->pending_notice=0;
    }
    if(mode==1) {
        actor->current=saved.health;actor->status=saved.status;
        actor->primary=saved.action[0];actor->secondary=saved.action[1];
        actor->phase=saved.action[2];actor->subphase=saved.action[3];
        actor->motion_class=saved.motion_class;
    }
}
}
