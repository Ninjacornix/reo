#include "actor_terminal_timer.hpp"
#include "motion.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
ActorTerminalTimer::ActorTerminalTimer(World& world,ActorResourceOperations& operations):world_(world),operations_(operations){
    if(world_.closed()||!operations_.bound_to(world_))throw std::invalid_argument("Native actor terminal owners closed or foreign");
}
void ActorTerminalTimer::tick(const actors::EntityId& id){
    const auto actor=world_.closed()?nullptr:world_.resolve(id);
    if(!actor)throw std::runtime_error("Native terminal actor retired, foreign or closed");
    if(!(actor->auxiliary_status&0x1000u)||actor->primary==4)return;
    actor->gauge_value=0;
    if(!(actor->status&0x18u))return;
    if(!actor->terminal_countdown){actor->terminal_countdown=world_.session().clock_mode?10800:21600;return;}
    if(--actor->terminal_countdown)return;
    actor->status|=0x40000000u;
    (void)operations_.transfer_inventory(id,0);
    actor->motion_class=0xa0;actor->primary=4;actor->secondary=actor->phase=actor->subphase=0;
    save_action_pose(*actor);
}
bool ActorTerminalTimer::apply_terminal_timer(World& source,Actor& actor){
    if(&source!=&world_)return false;
    const auto id=world_.identity_of(actor);if(!id)return false;
    tick(id);return true;
}
}
