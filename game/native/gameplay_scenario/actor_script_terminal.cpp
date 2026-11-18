#include "actor_script_terminal.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_world/actor_resource_operations.hpp"
#include "../gameplay_world/actor_state.hpp"
#include "../gameplay_world/motion.hpp"
#include "../gameplay_update/scenario_publication.hpp"
#include "../gameplay_events/statistics.hpp"

namespace reo::native::gameplay_scenario {
namespace w=gameplay_world;
namespace u=gameplay_update;
namespace {
bool excluded(const std::shared_ptr<w::Actor>& actor)noexcept{
    return !actor||!actor->active||(actor->status&0x5e0u)!=0; // Complete666080 mode0.
}
}
ActorScriptTerminal::ActorScriptTerminal(w::World& world,gameplay_events::Statistics& statistics,
    u::StatePublication& publication,std::uint8_t& pause_latched)noexcept:
    world_(world),statistics_(statistics),publication_(publication),pause_latched_(pause_latched){}
bool ActorScriptTerminal::bound_to(const w::World& world)const noexcept{return &world==&world_;}
bool ActorScriptTerminal::ready()const noexcept{return !closed_&&!world_.closed();}
bool ActorScriptTerminal::retire_offline_actor_ready(std::uint32_t selector)const noexcept{
    if(!ready()||selector>=w::World::primary_capacity)return false;
    const auto actor=world_.primary(selector);
    if(!actor||!actor->active||!actor->ai_control)return true;
    //5F6800 mode0 returns before touching resources for either source gate.
    if(actor->category!=0||actor->slot!=world_.selected_actor)return true;
    return operations_&&operations_->bound_to(world_)&&operations_->transfer_inventory_ready(world_.identity_of(*actor),0);
}
ActorScriptTerminalStatus ActorScriptTerminal::retire_offline_actor(std::uint32_t selector)noexcept{
    if(!ready())return ActorScriptTerminalStatus::closed;
    if(running_)return ActorScriptTerminalStatus::busy;
    if(!retire_offline_actor_ready(selector))return ActorScriptTerminalStatus::unavailable_owner;
    const auto actor=world_.primary(selector);
    if(!actor||!actor->active||!actor->ai_control)return ActorScriptTerminalStatus::completed;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    const auto id=world_.identity_of(*actor);
    actor->status|=0x5e0u;
    try{if(operations_)(void)operations_->transfer_inventory(id,0);}catch(...){return ActorScriptTerminalStatus::resource_failure;}
    if(world_.closed()||world_.resolve(id).get()!=actor.get())return ActorScriptTerminalStatus::unavailable_owner;
    actor->active=false;actor->visible=false;return ActorScriptTerminalStatus::completed;
}
bool ActorScriptTerminal::command_ready()const noexcept{
    if(!ready()||world_.selected_actor>=w::World::primary_capacity)return false;
    const auto actor=world_.primary(world_.selected_actor);
    if(excluded(actor)||!world_.locally_controlled(*actor))return true;
    const auto id=world_.identity_of(*actor);
    if(!operations_||!operations_->bound_to(world_)||!operations_->transfer_inventory_ready(id,0))return false;
    //1B0010's request lane is independent of the actor message phase.
    if((world_.mode==0&&actor->slot==0)||(world_.mode==1&&actor->slot<4)){
        const auto room_actor=world_.primary(actor->slot);if(!room_actor)return false;
        if(room_actor->room<128&&actor->slot==world_.selected_actor&&!publication_.message_sink())return false;
    }
    const auto phase=world_.session().message_phase;
    if((phase==1||phase==2)&&actor->category==0&&actor->slot==world_.selected_actor){
        if(!actor->interaction_resource||!actor->aim_pitch_adjustment||!actor->aim_target_pitch||
           !actor->aim_target_index||!w::selected_gauge_band(world_))return false;
        if((world_.mode==0||world_.mode==1)&&!publication_.message_sink())return false;
    }
    return true;
}
ActorScriptTerminalStatus ActorScriptTerminal::bind_resource_operations(w::ActorResourceOperations* operations,
    w::ActorResourceOperations* expected_current)noexcept{
    if(closed_)return operations?ActorScriptTerminalStatus::closed:ActorScriptTerminalStatus::completed;
    if(running_||world_.busy())return ActorScriptTerminalStatus::busy;
    return bind_roster_resources(operations,expected_current);
}
ActorScriptTerminalStatus ActorScriptTerminal::bind_roster_resources(w::ActorResourceOperations* operations,
    w::ActorResourceOperations* expected_current)noexcept{
    if(closed_)return operations?ActorScriptTerminalStatus::closed:ActorScriptTerminalStatus::completed;
    if(!ready())return ActorScriptTerminalStatus::closed;
    if(running_)return ActorScriptTerminalStatus::busy;
    if(operations&&!operations->bound_to(world_))return ActorScriptTerminalStatus::unavailable_owner;
    if(operations_==operations)return ActorScriptTerminalStatus::completed;
    if(operations_!=expected_current)return ActorScriptTerminalStatus::unavailable_owner;
    operations_=operations;return ActorScriptTerminalStatus::completed;
}
ActorScriptTerminalStatus ActorScriptTerminal::close()noexcept{
    if(closed_)return ActorScriptTerminalStatus::completed;
    if(running_||world_.busy())return ActorScriptTerminalStatus::busy;
    closed_=true;operations_=nullptr;return ActorScriptTerminalStatus::completed;
}
ActorScriptTerminalStatus ActorScriptTerminal::command()noexcept{
    if(!ready())return ActorScriptTerminalStatus::closed;
    if(running_)return ActorScriptTerminalStatus::busy;
    if(!command_ready())return ActorScriptTerminalStatus::unavailable_owner;
    const auto actor=world_.primary(world_.selected_actor);
    if(excluded(actor))return ActorScriptTerminalStatus::completed;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    pause_latched_=1;statistics_.mark_scripted_terminal(); //68EF50's committed prefix.
    if(!world_.locally_controlled(*actor))return ActorScriptTerminalStatus::completed;
    const auto id=world_.identity_of(*actor);
    const auto current=[&](){return !world_.closed()&&world_.resolve(id).get()==actor.get();};
    actor->status|=4u;actor->auxiliary_status|=0x20000000u;
    if(publication_.release_actor_room(actor->slot)!=u::PublicationStatus::completed)return ActorScriptTerminalStatus::publication_failure;
    if(!current())return ActorScriptTerminalStatus::unavailable_owner;
    // The source snapshots AFTER the synchronous room-release publication.
    const auto status=actor->status;const auto room=actor->room;
    const std::array<std::uint8_t,4> action{actor->primary,actor->secondary,actor->phase,actor->subphase};
    actor->room=0;actor->primary=1;actor->secondary=0x30;actor->phase=actor->subphase=0;
    w::save_action_pose(*actor);
    if(publication_.local_actor_message(id,u::ActorMessageSelector::snapshot)!=u::PublicationStatus::completed)return ActorScriptTerminalStatus::publication_failure;
    if(!current())return ActorScriptTerminalStatus::unavailable_owner;
    actor->pending_notice=0;
    try{(void)operations_->transfer_inventory(id,0);}catch(...){return ActorScriptTerminalStatus::resource_failure;}
    if(!current())return ActorScriptTerminalStatus::unavailable_owner;
    if(actor->pending_notice&&publication_.local_actor_message(id,u::ActorMessageSelector::action)!=u::PublicationStatus::completed)
        return ActorScriptTerminalStatus::publication_failure;
    if(!current())return ActorScriptTerminalStatus::unavailable_owner;
    actor->pending_notice=0;actor->status=status;actor->room=room;
    actor->primary=action[0];actor->secondary=action[1];actor->phase=action[2];actor->subphase=action[3];
    return ActorScriptTerminalStatus::completed;
}
}
